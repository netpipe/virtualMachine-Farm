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
#include <QFile>
#include <QFileInfo>
#include <QFileInfoList>
#include <QDebug>
#include <QDateTime>
#include <QMessageBox>
#include <QApplication>
#include <QSettings>
#include <QRegExp>
#include <QProcess>
#include <QStringList>

#include "Utils.h"

static uint Messages_Index = 0;

static bool Save_Messages_To_Log = true;
static QString Log_Path = "";

static bool Use_Stdout;
static bool Stdout_Debug;
static bool Stdout_Warning;
static bool Stdout_Error;

static QStringList Recent_CD_Images;

void AQDebug( const QString &sender, const QString &mes )
{
	if( Use_Stdout && Stdout_Debug )
	{
		qDebug( qPrintable(QString(
			"\n\33[32mAQEMU Debug\33[0m [%1] >>>\n\33[32mSender:\33[0m %2\n\33[32mMessage:\33[0m %3")
			.arg(Messages_Index).arg(sender).arg(mes)) );
	}
	
	if( Save_Messages_To_Log )
	{
		AQSave_To_Log( "Debug", sender, mes );
	}
	
	Messages_Index++;
}

void AQWarning( const QString &sender, const QString &mes )
{
	if( Use_Stdout && Stdout_Warning )
	{
		qDebug( qPrintable(QString(
			"\n\33[34mAQEMU Warning\33[0m [%1] >>>\n\33[34mSender:\33[0m %2\n\33[34mMessage:\33[0m %3")
			.arg(Messages_Index).arg(sender).arg(mes)) );
	}
	
	if( Save_Messages_To_Log )
	{
		AQSave_To_Log( "Warning", sender, mes );
	}
	
	Messages_Index++;
}

void AQError( const QString &sender, const QString &mes )
{
	if( Use_Stdout && Stdout_Error )
	{
		qDebug( qPrintable(QString(
			"\n\33[31mAQEMU Error\33[0m [%1] >>>\n\33[31mSender:\33[0m %2\n\33[31mMessage:\33[0m %3")
			.arg(Messages_Index).arg(sender).arg(mes)) );
	}
	
	if( Save_Messages_To_Log )
	{
		AQSave_To_Log( "Error", sender, mes );
	}
	
	Messages_Index++;
}

void AQGraphic_Warning( const QString &caption, const QString &mes )
{
	QMessageBox::warning( NULL, caption, mes, QMessageBox::Ok );
}

void AQGraphic_Warning( const QString &sender, const QString &caption, const QString &mes, bool fatal )
{
	if( fatal )
	{
		QMessageBox::warning( NULL, caption,
					QString("Sender: %1\nMessage: %2\n").arg(sender).arg(mes) +
					QObject::tr("This Fatal Error. Recomend Close AQEMU."),
					QMessageBox::Ok );
	}
	else
	{
		QMessageBox::warning( NULL, caption,
					QString("Sender: %1\nMessage: %2").arg(sender).arg(mes),
					QMessageBox::Ok );
	}
	
	if( Save_Messages_To_Log )
	{
		AQSave_To_Log( "Warning", sender, mes );
	}
}

void AQGraphic_Error( const QString &sender, const QString &caption, const QString &mes, bool fatal )
{
	if( fatal )
	{
		QMessageBox::critical( NULL, caption,
					QString("Sender: %1\nMessage: %2\n").arg(sender).arg(mes) +
					QObject::tr("This Fatal Error. Recomend Close AQEMU."),
					QMessageBox::Ok );
	}
	else
	{
		QMessageBox::critical( NULL, caption,
					QString("Sender: %1\nMessage: %2").arg(sender).arg(mes),
					QMessageBox::Ok );
	}
	
	if( Save_Messages_To_Log )
	{
		AQSave_To_Log( "Error", sender, mes );
	}
}

void AQUse_Log( bool use )
{
	Save_Messages_To_Log = use;
}

void AQUse_Debug_Output( bool use, bool d, bool w, bool e )
{
	Use_Stdout = use;
	Stdout_Debug = d;
	Stdout_Warning = w;
	Stdout_Error = e;
}

void AQLog_Path( const QString& path )
{
	Log_Path = path;
}

void AQSave_To_Log( const QString &mes_type, const QString &sender, const QString &mes )
{
	if( Log_Path.isEmpty() ) return;
	
	QFile log_file( Log_Path );
	
	if( ! log_file.open(QIODevice::Append | QIODevice::Text) )
	{
		AQUse_Log( false ); // off loging
		AQError( "void AQSave_To_Log( const QString& mes_type, const QString& sender, const QString& mes )",
				 "Cannot Open Log file to Write! Log Path: \"" + Log_Path + "\"" );
	}
	else
	{
		QTextStream out( &log_file );
		out << "Type: " << mes_type << " Num: " << Messages_Index << "\nDate: "
			<< QDateTime::currentDateTime().toString("yyyy.MM.dd hh:mm:ss zzz")
			<< "\nSender: " << sender << "\nMessage: " << mes << "\n\n";
	}
}

bool Create_New_HDD_Image( bool encrypted, const QString &base_image,
						   const QString &file_name, const QString &format, VM::Device_Size size, bool verbose )
{
	QStringList args;
	args << "create";
	
	if( encrypted ) args << "-e"; // encrypted
	
	if( ! base_image.isEmpty() )
	{
		args << "-b" << base_image;
	}
	
	args << "-f" << format; // format
	
	args << file_name; // file name
	 
	switch( size.Suffix )
	{
		case VM::Size_Suf_Mb: // MB
			args << QString::number( (long)(size.Size * 1024) );
			break;
			
		case VM::Size_Suf_Gb: // GB
			args << QString::number( (long)(size.Size * 1024) ) + "M";
			break;
			
		default: // KG
			args << QString::number( (long)size.Size );
			break;
	}
	
	QProcess qemu_img;
	QSettings settings;
	qemu_img.start( settings.value("QEMU_IMG_Path", "qemu-img").toString(), args );
	
	if( ! qemu_img.waitForStarted(200) )
	{
		AQGraphic_Error( "bool Create_New_HDD_Image( bool encrypted, const QString &base_image,"
						 "const QString &file_name, const QString &format, VM::Device_Size size, bool verbose )",
						 QObject::tr("Error!"), QObject::tr("Cannot Start qemu-img! Image not Created!") );
		return false;
	}
	
	if( ! qemu_img.waitForFinished(10000) )
	{
		AQGraphic_Error( "bool Create_New_HDD_Image( bool encrypted, const QString &base_image,"
						 "const QString &file_name, const QString &format, VM::Device_Size size, bool verbose )",
						 QObject::tr("Error!"), QObject::tr("qemu-img Cannot Finish! Image not Created!") );
		return false;
	}
	else
	{
		QByteArray err = qemu_img.readAllStandardError();
		QByteArray out = qemu_img.readAllStandardOutput();
		
		if( err.count() > 0 )
		{
			AQGraphic_Error( "bool Create_New_HDD_Image( bool encrypted, const QString &base_image,"
							 "const QString &file_name, const QString &format, VM::Device_Size size, bool verbose )",
							 QObject::tr("Error!"), QObject::tr("Cannot Create Image!\nInformation: ") + err );
		}
		
		QRegExp rx( "Format*ing*fmt*size*" );
		rx.setPatternSyntax( QRegExp::Wildcard );
		
		if( verbose )
		{
			if( rx.exactMatch( out ) )
			{
				QMessageBox::information( NULL, QObject::tr("Complete!"),
						QObject::tr("QEMU-IMG is Create HDD Image.\nAdditional Information:\n") + out );
			}
			else
			{
				QMessageBox::information( NULL, QObject::tr("Warning!"),
						 QObject::tr("QEMU-IMG is Return non Standard Message!.\nAdditional Information:\n") + out );
			}
		}
		
		return true;
	}
}

bool Create_New_HDD_Image( const QString &file_name, VM::Device_Size size )
{
	QSettings settings;
	
	QString format = settings.value( "Default_HDD_Image_Format", "qcow2" ).toString();
	
	return Create_New_HDD_Image( false, "", file_name, format, size, false );
}

bool Format_HDD_Image( const QString &file_name )
{
	if( file_name.isEmpty() )
	{
		AQError( "bool Format_HDD_Image( const QString &file_name )",
				 "File Name is Empty!" );
		
		return false;
	}
	
	VM_HDD tmp_hd = VM_HDD( true, file_name );
	
	QString hd_format = tmp_hd.Get_Image_Format();
	
	if( hd_format.isEmpty() )
	{
		AQError( "bool Format_HDD_Image( const QString &file_name )",
				 "Format is Empty!" );
		
		return false;
	}
	
	return Create_New_HDD_Image( false, "", file_name, hd_format, tmp_hd.Get_Virtual_Size(), false );
}

QList<QString> Get_Templates_List()
{
	QList<QString> all_templates;
	QSettings settings;
	
	// VM Templates
	QDir sys_templates_dir( settings.value("AQEMU_Data_Folder", "").toString() + "os_templates/" );
	
	QFileInfoList sys_templates_list = sys_templates_dir.entryInfoList(
			QStringList("*.aqvmt"), QDir::Files, QDir::Unsorted );
	
	QDir user_templates_dir( settings.value("VM_Directory", "").toString() + "os_templates/" );
	
	QFileInfoList user_templates_list = user_templates_dir.entryInfoList(
			QStringList("*.aqvmt"), QDir::Files, QDir::Unsorted );
	
	for( int tx = 0; tx < sys_templates_list.count(); ++tx )
	{
		for( int ux = 0; ux < user_templates_list.count(); ++ux )
		{
			if( sys_templates_list[tx].completeBaseName() ==
						 user_templates_list[ux].completeBaseName() )
			{
				sys_templates_list.takeAt( tx ); // delete system template
				tx -= 1;
				ux = user_templates_list.count();
			}
		}
	}
	
	// OK. In Template Lists Only Unique Values
	for( int ix = 0; ix < sys_templates_list.count(); ++ix )
	{
		all_templates.append( sys_templates_list[ix].absoluteFilePath() );
	}
	
	for( int ix = 0; ix < user_templates_list.count(); ++ix )
	{
		all_templates.append( user_templates_list[ix].absoluteFilePath() );
	}
	
	// sort
	qSort( all_templates );
	
	return all_templates;
}


QString Get_FS_Compatible_VM_Name( const QString &name )
{
	//QRegExp vm_name_val = QRegExp( "[^a-zA-Z0-9_]" ); // old style
	QRegExp vm_name_val = QRegExp( "[^\\w]" );
	
	QString tmp = name;
	tmp = tmp.replace( vm_name_val, "_" );
	
	return tmp.replace( "__", "_" );
}

QString Get_Complete_VM_File_Path( const QString &vm_name )
{
	//QRegExp vm_name_val = QRegExp( "[^a-zA-Z0-9_]" ); // old style
	QRegExp vm_name_val = QRegExp( "[^\\w]" );
	
	QString tmp = vm_name;
	tmp = tmp.replace( vm_name_val, "_" );
	
	QString new_name = tmp.replace( "__", "_" );
	QString tmp_str = new_name;
	
	QSettings settings;
	
	QString ret_str = settings.value("VM_Directory", "").toString() + tmp_str;
	
	if( ! ret_str.endsWith(".aqemu") )
	{
		ret_str += ".aqemu";
	}
	
	for( int ix = 0; QFile::exists(ret_str); ++ix )
	{
		tmp_str = new_name + QString::number( ix );
	}
	
	return ret_str;
}

QString Get_TR_Size_Suffix( VM::Device_Size suf )
{
	switch( suf.Suffix )
	{
		case VM::Size_Suf_Kb:
			return QObject::tr("Kb");
				
		case VM::Size_Suf_Mb:
			return QObject::tr("Mb");
				
		case VM::Size_Suf_Gb:
			return QObject::tr("Gb");
				
		default:
			AQError( "QString Get_TR_Size_Suffix( VM::Device_Size suf )",
					 "Virtual Size Suffix Default Section!" );
			return "";
	}
}


void Check_AQEMU_Permissions()
{
	QSettings settings;
	
#ifndef Q_OS_WIN32
	// This Section For Unix Like OS. In Windows AQEMU Settings Save in Registy.
	QFileInfo test_perm( settings.fileName() );
	
	if( test_perm.exists() )
	{
		if( ! test_perm.isWritable() )
		{
			AQGraphic_Error( "void Check_AQEMU_Permissions()", QObject::tr("Error!"),
							 QObject::tr("AQEMU Config File is Read Only!\nCheck Permissions For File: ") +
							 settings.fileName(), true );
		}
	}
	else
	{
		
	}
#endif
	
	// Check VM Dir Permissions
	test_perm = QFileInfo( settings.value("VM_Directory", "~").toString() );
	
	if( test_perm.exists() )
	{
		if( ! test_perm.isWritable() )
		{
			AQGraphic_Error( "void Check_AQEMU_Permissions()", QObject::tr("Error!"),
							 QObject::tr("AQEMU VM Directory is Read Only!\nCheck Permissions For: ") +
							 settings.value("VM_Directory", "~").toString(), true );
		}
	}
	
	// Check VM Templates Dir Permissions
	test_perm = QFileInfo( settings.value("VM_Directory", "~").toString() + "os_templates" );
	
	if( test_perm.exists() )
	{
		if( ! test_perm.isWritable() )
		{
			AQGraphic_Error( "void Check_AQEMU_Permissions()", QObject::tr("Error!"),
							 QObject::tr("AQEMU VM Template Directory is Read Only!\nCheck Permissions For: ") +
							 settings.value("VM_Directory", "~").toString() + "os_templates", true );
		}
	}
	
	// Check AQEMU Log File Permissions
	if( ! settings.value("Log_Path", "").toString().isEmpty() )
	{
		test_perm = QFileInfo( settings.value("Log_Path", "").toString() );
		
		if( test_perm.exists() )
		{
			if( ! test_perm.isWritable() )
			{
				AQGraphic_Error( "void Check_AQEMU_Permissions()", QObject::tr("Error!"),
								 QObject::tr("AQEMU Log File is Read Only!\nCheck Permissions For File: ") +
								 settings.value("Log_Path", "").toString(), false );
			}
		}
	}
}

int Get_Random( int min, int max )
{
	if( min < 0 || max > RAND_MAX || min > max )
	{
		return -1;
	}
	
	qsrand( QTime::currentTime().msec() );
	
	return int( qrand() / (RAND_MAX + 1.0) * (max + 1 - min) + min );
}

void Load_Recent_Images_List()
{
	QSettings settings;
	int max = settings.value( "CD_ROM_Exits_Images/Max", "5" ).toString().toInt();
	
	Recent_CD_Images.clear();
	
	for( int ix = 0; ix < max; ++ix )
	{
		Recent_CD_Images << settings.value( "CD_ROM_Exits_Images/item" + QString::number(ix), "" ).toString();
	}
}

const QStringList &Get_CD_Recent_Images_List()
{
	return Recent_CD_Images;
}

void Add_To_Recent_Files( const QString &path )
{
	QSettings settings;
	int max = settings.value( "CD_ROM_Exits_Images/Max", "5" ).toString().toInt();
	
	// This Unique Path?
	for( int fx = 0; fx < Recent_CD_Images.count() && fx < max; ++fx )
	{
		if( Recent_CD_Images[fx] == path )
		{
			AQDebug( "void Add_To_Recent_Files( const QString &path )",
					 "CD-ROM Path Not Unique." );
			return;
		}
	}
	
	// Add to List
	if( Recent_CD_Images.count() < max )
	{
		Recent_CD_Images << path;
	}
	else
	{
		for( int ix = 0; ix < Recent_CD_Images.count() -1 && ix < max -1; ++ix )
		{
			Recent_CD_Images[ ix ] = Recent_CD_Images[ ix +1 ];
		}
		
		Recent_CD_Images[ max -1 ] = path;
	}
	
	settings.setValue( "CD_ROM_Exits_Images/item" + QString::number(Recent_CD_Images.count()-1), path );
}
