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

#include <QDir>
#include <QDialog>
#include <QMessageBox>
#include <QFileDialog>
#include <QInputDialog>

#include "Utils.h"
#include "Settings_Window.h"
#include "Create_Template_Window.h"
#include "Advanced_Settings_Window.h"
#include "QEMU_Binary_Window.h"
#include "Screenshot_Options_Window.h"

Settings_Window::Settings_Window( QWidget *parent )
	: QDialog( parent )
{
	ui.setupUi( this );
	
	First_Show = false;
	
	// Minimum Size
	resize( minimumSizeHint().width(), minimumSizeHint().height() );
	
	// Load Settings
	Settings = new QSettings();
	
	// Virtual Machines Folder
	ui.Edit_VM_Folder->setText(
			Settings->value("VM_Directory", QDir::homePath() + "/.aqemu/").toString() );
	
	// Show Emulator Control Window
	ui.CH_Show_Emulator_Control_Window->setChecked(
			Settings->value("Show_Emulator_Control_Window", "yes").toString() == "yes" );
	
	// Use Device Manager
	ui.CH_Use_Device_Manager->setChecked(
			Settings->value("Use_Device_Manager", "no").toString() == "yes" );
	
	// Find All Language Files (*.qm)
	QDir data_dir( Settings->value("AQEMU_Data_Folder", "/usr/share/aqemu/").toString() );
	QFileInfoList lang_files = data_dir.entryInfoList( QStringList("*.qm"), QDir::Files, QDir::Name );
	
	if( lang_files.count() > 0 )
	{
		// Add Languages to List
		for( int dd = 0; dd < lang_files.count(); ++dd )
		{
			ui.CB_Language->addItem( lang_files[dd].completeBaseName() );
			
			if( lang_files[dd].completeBaseName() == Settings->value( "Language", "en" ).toString() )
			{
				ui.CB_Language->setCurrentIndex( dd + 1 ); // First Item 'English'
			}
		}
	}
	
	// 64x64 Icons
	ui.CH_64_Icons->setChecked( Settings->value("64x64_Icons", "yes").toString() == "yes" );
	
	// Screenshot for OS Logo
	ui.CH_Screenshot_for_OS_Logo->setChecked( Settings->value("Use_Screenshot_for_OS_Logo",
											  "yes").toString() == "yes" );
	
	// Use USB
	#ifdef Q_OS_LINUX
	ui.CH_Use_USB->setEnabled( true );
	ui.CH_Use_USB->setChecked( Settings->value("Use_USB", "yes").toString() == "yes" );
	#else
	ui.CH_Use_USB->setEnabled( false );
	ui.CH_Use_USB->setChecked( false );
	#endif
	
	// Use VNC Embedded Display
	#ifdef VNC_DISPLAY
	ui.CH_Use_VNC_Display->setEnabled( true );
	ui.CH_Use_VNC_Display->setChecked( Settings->value("Use_VNC_Display", "yes").toString() == "yes" );
	#else
	ui.CH_Use_VNC_Display->setEnabled( false );
	ui.CH_Use_VNC_Display->setChecked( false );
	#endif
	
	Load_Templates();
	
	First_Show = true;
}

Settings_Window::~Settings_Window()
{
	if( Settings != NULL ) delete Settings;
}

void Settings_Window::Load_Templates()
{
	QList<QString> all_templates = Get_Templates_List();
	
	ui.CB_Default_VM_Template->clear();
	
	for( int ix = 0; ix < all_templates.count(); ++ix )
	{
		QFileInfo tmp_info = QFileInfo( all_templates[ix] );
		ui.CB_Default_VM_Template->addItem( tmp_info.completeBaseName() );
	}
	
	// no items found
	if( ui.CB_Default_VM_Template->count() < 1 )
	{
		AQGraphic_Warning( tr("Warning"),
						   tr("AQEMU VM Templates Not Found!") );
	}
	else
	{
		// Find default template
		for( int ix = 0; ix < ui.CB_Default_VM_Template->count(); ++ix )
		{
			if( ui.CB_Default_VM_Template->itemText(ix) ==
				Settings->value("Default_VM_Template", "Linux_2_6").toString() )
			{
				ui.CB_Default_VM_Template->setCurrentIndex( ix );
			}
		}
	}
}

void Settings_Window::on_Button_Create_Template_from_VM_clicked()
{
	Create_Template_Window *templ_win = new Create_Template_Window();
	
	if( templ_win->exec() == QDialog::Accepted )
	{
		Load_Templates();
		QMessageBox::information( this, tr("Information"),
								  tr("New Template Created!") );
	}
	
	delete templ_win;
}

void Settings_Window::on_TB_VM_Folder_clicked()
{
	QString folder = QFileDialog::getExistingDirectory(
			this, tr("Set Folder for you VM's"),
			Settings->value("VM_Directory", "~").toString() );
	
	if( ! (folder.isNull() || folder.isEmpty()) )
	{
		if( folder.at(folder.count()-1) != '/' ) folder.push_back( '/' );
		
		ui.Edit_VM_Folder->setText( folder );
	}
}

void Settings_Window::on_Button_Box_clicked( QAbstractButton* button )
{
	// Save settings?
	if( ui.Button_Box->buttonRole(button) == QDialogButtonBox::AcceptRole )
	{
		QDir dir; // For Check on valid
		
		Settings->setValue( "Default_VM_Template",
				ui.CB_Default_VM_Template->currentText() );
		
		// VM Folder
		if( ! ui.Edit_VM_Folder->text().endsWith("/") )
		{
			ui.Edit_VM_Folder->setText( ui.Edit_VM_Folder->text() + "/" );
		}
		
		if( dir.exists(ui.Edit_VM_Folder->text()) )
		{
			if( ! dir.exists(ui.Edit_VM_Folder->text() + "os_templates/") )
			{
				dir.mkdir( ui.Edit_VM_Folder->text() + "os_templates/" );
			}
			
			Settings->setValue( "VM_Directory", ui.Edit_VM_Folder->text() );
		}
		else
		{
			int mes_res = QMessageBox::question( this, tr("Invalid Value!"),
					tr("Folder for AQEMU VM is Not Exists! Create It?"),
					QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes );
			
			if( mes_res == QMessageBox::Yes )
			{
				if( ! (dir.mkdir(ui.Edit_VM_Folder->text()) &&
					   dir.mkdir(ui.Edit_VM_Folder->text() + "os_templates/")) )
				{
					AQGraphic_Warning( tr("Error!"), tr("Cannot Create New Folder!") );
					return;
				}
				else
				{
					Settings->setValue( "VM_Directory", ui.Edit_VM_Folder->text() );
				}
			}
			else
			{
				return;
			}
		}
		
		// Check Log
		if( Settings->value("Use_Log", "yes").toString() == "yes" )
		{
			if( Settings->value("Log_Path", "aqemu.log").toString() == "aqemu.log" )
			{
				Settings->setValue( "Log_Path",
									Settings->value("VM_Directory", "").toString() + "aqemu.log" );
			}
		}
		
		// Show Emulator Control Window
		if( ui.CH_Show_Emulator_Control_Window->isChecked() )
		{
			Settings->setValue( "Show_Emulator_Control_Window", "yes" );
		}
		else
		{
			Settings->setValue( "Show_Emulator_Control_Window", "no" );
		}
		
		// Use Device Manager
		if( ui.CH_Use_Device_Manager->isChecked() )
		{
			Settings->setValue( "Use_Device_Manager", "yes" );
		}
		else
		{
			Settings->setValue( "Use_Device_Manager", "no" );
		}
		
		// Interface Language
		if( ui.CB_Language->currentIndex() == 0 )
		{
			Settings->setValue( "Language", "en" );
		}
		else
		{
			Settings->setValue( "Language", ui.CB_Language->itemText(ui.CB_Language->currentIndex()) );
		}
		
		// USB Support
		if( ui.CH_Use_USB->isChecked() )
		{
			Settings->setValue( "Use_USB", "yes" );
		}
		else
		{
			Settings->setValue( "Use_USB", "no" );
		}
		
		// Use VNC Embedded Display
		if( ui.CH_Use_VNC_Display->isChecked() )
		{
			Settings->setValue( "Use_VNC_Display", "yes" );
		}
		else
		{
			Settings->setValue( "Use_VNC_Display", "no" );
		}
		
		// Screenshot for OS Logo
		if( ui.CH_Screenshot_for_OS_Logo->isChecked() )
		{
			Settings->setValue( "Use_Screenshot_for_OS_Logo", "yes" );
		}
		else
		{
			Settings->setValue( "Use_Screenshot_for_OS_Logo", "no" );
		}
		
		// 64x64 Icons
		if( ui.CH_64_Icons->isChecked() )
		{
			Settings->setValue( "64x64_Icons", "yes" );
		}
		else
		{
			Settings->setValue( "64x64_Icons", "no" );
		}
		
		Settings->sync();
		
		if( Settings->status() != QSettings::NoError )
		{
			AQError(
				"void Settings_Window::on_Button_Box_clicked( QAbstractButton* button )",
				"QSettings Error!" );
		}
		
		if( Advanced_Win_Show )
		{
			Advanced_Settings_Window *ad_set = new Advanced_Settings_Window();
			ad_set->on_Button_OK_clicked();
			delete ad_set;
		}
		
		QEMU_Binary_Window *bin_win = new QEMU_Binary_Window();
		bin_win->on_Button_OK_clicked();
		delete bin_win;
		
		accept();
	}
	else if( ui.Button_Box->buttonRole(button) == QDialogButtonBox::RejectRole )
	{
		reject();
	}
	else
	{
		AQError(
			"void Settings_Window::on_Button_Box_clicked( QAbstractButton* button )",
			"Invalid Button Role!" );
	}
}

void Settings_Window::on_CB_Language_currentIndexChanged( int index )
{
	if( First_Show && Settings->value("Show_Language_Warning", "yes").toString() == "yes" )
	{
		if( QMessageBox::information(this, tr("Information"),
			tr("Language be set after restart AQEMU\nShow this message in future?"),
			QMessageBox::Yes | QMessageBox::No) == QMessageBox::No )
		{
			Settings->setValue( "Show_Language_Warning", "no" );
		}
		
		First_Show = false;
	}
}

void Settings_Window::on_Button_Screenshots_Settings_clicked()
{
	Screenshot_Options_Window *screen_win = new Screenshot_Options_Window();
	
	screen_win->exec();
	
	delete screen_win;
}

void Settings_Window::on_Button_QEMU_Binary_clicked()
{
	QEMU_Binary_Window *bin_win = new QEMU_Binary_Window();
	
	bin_win->exec();
	
	delete bin_win;
}

void Settings_Window::on_Button_Advanced_Settings_clicked()
{
	Advanced_Settings_Window *ad_set = new Advanced_Settings_Window();
	
	ad_set->exec();
	
	// Use Log
	if( Settings->value( "Log/Save_In_File", "yes" ).toString() == "yes" )
	{
		AQUse_Log( true );
	}
	else
	{
		AQUse_Log( false );
	}
	
	// Log File Name
	AQLog_Path( Settings->value("Log/Log_Path", "").toString() );
	
	// Log Filter
	AQUse_Debug_Output( Settings->value("Log/Print_In_STDOUT", "yes").toString() == "yes",
						Settings->value("Log/Save_Debug","yes").toString() == "yes",
						Settings->value("Log/Save_Warning","yes").toString() == "yes",
						Settings->value("Log/Save_Error","yes").toString() == "yes" );
	
	delete ad_set;
}

#ifdef VNC_DISPLAY

void Settings_Window::on_CH_Show_Emulator_Control_Window_toggled( bool checked )
{
	ui.CH_Use_VNC_Display->setEnabled( checked );
	
	if( ! checked ) ui.CH_Use_VNC_Display->setChecked( false );
}

#endif
