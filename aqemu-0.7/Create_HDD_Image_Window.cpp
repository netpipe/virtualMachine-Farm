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

#include <QFileDialog>
#include <QMessageBox>

#include "Utils.h"
#include "VM_Devices.h"
#include "Create_HDD_Image_Window.h"

Create_HDD_Image_Window::Create_HDD_Image_Window( QWidget *parent )
	: QDialog( parent )
{
	ui.setupUi( this );
}

const QString &Create_HDD_Image_Window::Get_Image_File_Name()
{
	Image_File_Name = ui.Edit_File_Name->text();
	return Image_File_Name;
}

void Create_HDD_Image_Window::Set_Image_File_Name( const QString &path )
{
	Image_File_Name = path;
	ui.Edit_File_Name->setText( path );
}

void Create_HDD_Image_Window::Set_Image_Size( double gb )
{
	ui.SB_Size->setValue( gb );
}

void Create_HDD_Image_Window::on_Button_Browse_Base_Image_clicked()
{
	QString fileName = QFileDialog::getOpenFileName(
			this, tr("Select Base HDD Image File"), QDir::homePath(), tr("All Files (*)") );
	
	if( ! (fileName.isNull() || fileName.isEmpty()) )
	{
		ui.Edit_Base_Image_File_Name->setText( fileName );
	}
}

void Create_HDD_Image_Window::on_Button_Browse_New_Image_clicked()
{
	QString fileName = QFileDialog::getSaveFileName(
			this, tr("Create HDD Image File"), QDir::homePath(), tr("All Files (*)") );
	
	if( ! (fileName.isNull() || fileName.isEmpty()) )
	{
		ui.Edit_File_Name->setText( fileName );
	}
}

void Create_HDD_Image_Window::on_CB_Format_currentIndexChanged( const QString &text )
{
	if( text == "qcow2" || text == "qcow" )
	{
		ui.CH_Encrypted->setEnabled( true );
	}
	else
	{
		ui.CH_Encrypted->setEnabled( false );
	}
}

void Create_HDD_Image_Window::on_Button_Create_clicked()
{
	if( ui.Edit_File_Name->text().isEmpty() )
	{
		AQGraphic_Warning( tr("Error!"),
						   tr("Image File Name is Empty!") );
		return;
	}
	
	if( ui.SB_Size->value() < 1 || ui.SB_Size->value() > 1024 )
	{
		AQGraphic_Warning( tr("Error!"),
						   tr("Image Size Invalid!") );
		return;
	}
	
	bool Create_OK = false;
	
	VM::Device_Size hd_size;
	hd_size.Size = ui.SB_Size->value();
	
	switch( ui.CB_Suffix->currentIndex() )
	{
		case 1: // MB
			hd_size.Suffix = VM::Size_Suf_Mb;
			break;
			
		case 2: // GB
			hd_size.Suffix = VM::Size_Suf_Gb;
			break;
			
		default: // KG
			hd_size.Suffix= VM::Size_Suf_Kb;
			break;
	}
	
	if( ui.GB_Base_Image->isChecked() )
	{
		if( ! QFile::exists(ui.Edit_Base_Image_File_Name->text()) )
		{
			AQGraphic_Warning( tr("Error!"),
							   tr("Base Image File Not Exists!") );
			return;
		}
		else
		{
			Create_OK = Create_New_HDD_Image( ui.CH_Encrypted->isChecked(),
					ui.Edit_Base_Image_File_Name->text(), ui.Edit_File_Name->text(),
					ui.CB_Format->currentText(), hd_size, true );
		}
	}
	else
	{
		Create_OK = Create_New_HDD_Image( ui.CH_Encrypted->isChecked(), "",
				ui.Edit_File_Name->text(), ui.CB_Format->currentText(), hd_size, true );
	}
	
	if( Create_OK )
	{
		accept();
	}
	else
	{
		AQGraphic_Warning( tr("Error!"),
						   tr("Image Not Created!") );
		return;
	}
}

void Create_HDD_Image_Window::on_Button_Format_Help_clicked()
{
	QMessageBox::information( this, tr("QEMU-IMG Supported formats"),
		tr( "raw\nRaw disk image format. This format has the advantage of being simple and easily "
			"exportable to all other emulators. If your file system supports holes (for example in "
			"ext2 or ext3 on Linux or NTFS on Windows), then only the written sectors will reserve "
			"space. Use qemu-img info to know the real size used by the image or ls -ls on Unix/Linux."
			"\n\nqcow2\nQEMU image format, the most versatile format. Use it to have smaller images "
			"(useful if your filesystem does not supports holes, for example on Windows), optional "
			"AES encryption, zlib based compression and support of multiple VM snapshots."
			"\n\nqcow\nOld QEMU image format. Left for compatibility."
			"\n\ncow\nUser Mode Linux Copy On Write image format. Used to be the only growable image "
			"format in QEMU. It is supported only for compatibility with previous versions. "
			"It does not work on win32."
			"\n\nvmdk\nVMware 3 and 4 compatible image format."
			"\n\ncloop\nLinux Compressed Loop image, useful only to reuse directly compressed CD-ROM "
			"images present for example in the Knoppix CD-ROMs." ) );
}
