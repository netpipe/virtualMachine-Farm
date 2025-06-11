/****************************************************************************
**
** Copyright (C) 2008-2009 Andrey Rijov <ANDron142@yandex.ru>
**
** This file is part of AQEMU.
**
** This program is free software; you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation; either version 2 of the License.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with this program; if not, write to the Free Software
** Foundation, Inc., 51 Franklin Street, Fifth Floor,
** Boston, MA  02110-1301, USA.
**
****************************************************************************/

#include <QApplication>
#include <QMessageBox>
#include <QTranslator>
#include <QFileDialog>
#include <QDir>
#include <QFile>

// For Check User UID
#ifdef Q_OS_LINUX
#include <unistd.h>
#include <sys/types.h>
#endif

#include "Utils.h"
#include "Main_Window.h"
#include "Settings_Window.h"

int main( int argc, char *argv[] )
{
	QCoreApplication::setOrganizationName( "ANDronSoft" );
	QCoreApplication::setApplicationName( "AQEMU" );
	QSettings settings;
	
	QApplication app( argc, argv );
	
	// Check For First Start in root Mode
	#ifdef Q_OS_LINUX
	if( settings.value("First_Start", "yes").toString() == "yes" ) // This is a first start AQEMU on this computer?
	{
		uid_t user_uid = getuid();
		
		if( user_uid == 0 )
		{
			int ret = QMessageBox::question( NULL, QObject::tr("Warning!"),
											 QObject::tr("This is a First Start AQEMU and Program Running in root Mode.\n"
														 "In Some Linux Distributions That Can Lead to Inability to Save Configuration!"),
											 QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes );
			
			if( ret == QMessageBox::Yes )
			{
				return 0;
			}
		}
	}
	#endif
	
	// This is Upgrade AQEMU? Find Previous Confing
	if( QFile::exists(QDir::homePath() + "/.config/ANDronSoft/AQEMU.conf") )
	{
		if( settings.value( "AQEMU_Config_Version", "0.4" ).toString() == "0.5" )
		{
			// OK. Config Version 0.5 Averable
			AQDebug( "int main( int argc, char *argv[] )",
					 "AQEMU Config Version: 0.5" );
		}
		else
		{
			// Remove Old Config!
			if( QFile::copy(QDir::homePath() + "/.config/ANDronSoft/AQEMU.conf",
				QDir::homePath() + "/.config/ANDronSoft/AQEMU.conf.bak") )
			{
				AQWarning( "int main( int argc, char *argv[] )",
						   "AQEMU Configuration File No Version 0.5. File Saved: AQEMU.conf.bak" );
				
				settings.clear();
				settings.sync();
			}
			else
			{
				AQError( "int main( int argc, char *argv[] )",
						 "Cannot Save Old Version AQEMU Configuration File!" );
			}
		}
	}
	
	settings.setValue( "AQEMU_Config_Version", "0.5" );
	
	// Use Log
	if( settings.value( "Log/Save_In_File", "yes" ).toString() == "yes" )
	{
		// Log Size... FIXME Delete Half Log Size
		if( QFile::exists(settings.value("Log/Log_Path", "").toString()) )
		{
			QFileInfo log_info( settings.value("Log/Log_Path", "").toString() );
			
			// Log > 1MB
			if( log_info.size() > 1 * 1024 * 1024 )
			{
				QFile::remove( settings.value("Log/Log_Path", "").toString() );
			}
		}
		
		AQUse_Log( true );
	}
	else
	{
		AQUse_Log( false );
	}
	
	// Log File Name
	AQLog_Path( settings.value("Log/Log_Path", "").toString() );
	
	// Log Filter
	AQUse_Debug_Output( settings.value("Log/Print_In_STDOUT", "yes").toString() == "yes",
						settings.value("Log/Save_Debug","yes").toString() == "yes",
						settings.value("Log/Save_Warning","yes").toString() == "yes",
						settings.value("Log/Save_Error","yes").toString() == "yes" );
	
	bool kvm_support = false;
	
	#ifdef Q_OS_LINUX
	// Find KVM Binary
	if( settings.value("Check_KVM", "yes").toString() == "yes" )
	{
		if( ! System_Info::Check_Availability_KVM() )
		{
			AQWarning( "int main( int argc, char *argv[] )",
					   "Cannot Find KVM on This System!" );
		}
		else
		{
			AQDebug( "int main( int argc, char *argv[] )",
					 "KVM Finded on This System." );
			kvm_support = true;
		}
	}
	#endif
	
	// Check_Version_on_Start
	if( settings.value("Check_Version_on_Start", "yes").toString() == "yes" )
	{
		if( ! System_Info::Check_QEMU_Version() )
		{
			if( ! kvm_support )
			{
				AQError( "int main( int argc, char *argv[] )",
						 "Cannot Check QEMU Version! Using Default: QEMU 0.9.0" );
				settings.setValue( "QEMU_Version", "0.9.0" );
			}
			else
			{
				AQDebug( "int main( int argc, char *argv[] )",
						 "Cannot Check QEMU Version. Use Compatibility Mode for KVM" );
				settings.setValue( "QEMU_Version", "0.9.1" );
			}
		}
	}
	
	if( settings.value("QEMU_Version", "0.9.0").toString() == "Old" )
	{
		AQGraphic_Error( "int main( int argc, char *argv[] )", QObject::tr("Error!"),
						 QObject::tr("Installed on This System Version QEMU Cannot be Used!\n"
								 	 "AQEMU Working on QEMU 0.9.0 and Higher!"), true );
	}
	
	// Find Data Folder
	if( settings.value("AQEMU_Data_Folder", "").toString().isEmpty() )
	{
		#ifdef Q_OS_WIN32
		if( QDir(QDir::currentPath() + "\\os_icons").exists() &&
			QDir(QDir::currentPath() + "\\os_templates").exists() )
		{
			settings.setValue( "AQEMU_Data_Folder", QDir::currentPath() );
			AQDebug( "int main( int argc, char *argv[] )", "Use Data Folder: " + QDir::currentPath() );
		}
		else
		{
			AQGraphic_Error( "int main( int argc, char *argv[] )", QObject::tr("Error!"),
							 QObject::tr("Cannot Find AQEMU Data!"), false );
		}
		#else
		
		QDir data_dir;
		
		if( data_dir.exists("/usr/share/aqemu/") )
		{
			settings.setValue( "AQEMU_Data_Folder", "/usr/share/aqemu/" );
			AQDebug( "int main( int argc, char *argv[] )", "Use Data Folder: /usr/share/aqemu/" );
		}
		else if( data_dir.exists("/usr/share/apps/aqemu/") )
		{
			settings.setValue( "AQEMU_Data_Folder", "/usr/share/apps/aqemu/" );
			AQDebug( "int main( int argc, char *argv[] )", "Use Data Folder: /usr/share/apps/aqemu/" );
		}
		else if( data_dir.exists("/usr/local/share/aqemu/") )
		{
			settings.setValue( "AQEMU_Data_Folder", "/usr/local/share/aqemu/" );
			AQDebug( "int main( int argc, char *argv[] )", "Use Data Folder: /usr/local/share/aqemu/" );
		}
		else
		{
			QMessageBox::information( NULL, QObject::tr("Error!"),
				QObject::tr("Cannot Locate AQEMU Data Folder!\nYou Should Select This Folder in Next Window!"),
				QMessageBox::Ok );
			
			QString aqemu_data_dir = QFileDialog::getExistingDirectory( NULL,
				QObject::tr("Please Select AQEMU Data Folder:"), "/",
				QFileDialog::ShowDirsOnly );
			
			if( aqemu_data_dir.isEmpty() )
			{
				QMessageBox::critical( NULL,
					QObject::tr("Error!"), QObject::tr("AQEMU Doesn't Work If Data Folder Not Selected!") );
				return -1;
			}
			else
			{
				settings.setValue( "AQEMU_Data_Folder", aqemu_data_dir );
			}
		}
		
		#endif
	}
	
	// This is a first start AQEMU on this computer?
	settings.setValue( "Show_Language_Warning", "no" );
	
	if( settings.value("First_Start", "yes").toString() == "yes" )
	{
		QMessageBox::information( NULL, QObject::tr("AQEMU Configuration"),
			QObject::tr("This is a First Start AQEMU You Must Adjust the Program for Work") );
		
		Settings_Window *Settings_Win = new Settings_Window( NULL );
	
		for( int uf = 0; uf < 2 ; ++uf ) // user click OK button
		{
			Settings_Win->Advanced_Win_Show = true;
			
			if( Settings_Win->exec() == QDialog::Accepted )
			{
				settings.setValue( "First_Start", "no" );
				break;
			}
		}
		
		delete Settings_Win;
	}
	else
	{
		Check_AQEMU_Permissions();
	}
	
	settings.setValue( "Show_Language_Warning", "yes" );
	
	// Load Language
	QTranslator appTranslator;
	
	if( settings.value( "Language", "" ).toString() != "en" )
	{
		appTranslator.load( settings.value("AQEMU_Data_Folder", "").toString() +
							settings.value( "Language", "" ).toString() + ".qm",
							app.applicationDirPath() );
		
		app.installTranslator( &appTranslator );
	}
	
	// VM Directory Exists?
	QDir vm_dir;
	if( ! vm_dir.exists(settings.value("VM_Directory", "").toString()) )
	{
		int ret = QMessageBox::question( NULL, QObject::tr("Warning!"),
										 QObject::tr("AQEMU VM Folder Not Exists! Create It?"),
										 QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes );
		
		if( ret == QMessageBox::Yes )
		{
			vm_dir.mkdir( QDir::homePath() + "/.aqemu" );
		}
	}
	
	Main_Window Window;
	Window.show();
	
	return app.exec();
}
