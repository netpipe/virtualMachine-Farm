/****************************************************************************
**
** Copyright (C) 2009 Andrey Rijov <ANDron142@yandex.ru>
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
#include <QDir>

#include "Utils.h"
#include "Screenshot_Options_Window.h"

Screenshot_Options_Window::Screenshot_Options_Window( QWidget *parent )
	: QDialog( parent )
{
	ui.setupUi( this );
	
	// Use Shared Folder For All Screenshots
	ui.CH_Screenshot_Folder->setChecked( Settings.value("Use_Screenshots_Folder", "no").toString() == "yes" );
	
	// Screenshots Shared Folder Path
	ui.Edit_Screenshot_Folder->setText( Settings.value("Screenshot_Folder_Path", "").toString() );
	
	// Screenshot save format
	QString fmt = Settings.value( "Screenshot_Save_Format", "PNG" ).toString();
	
	if( fmt == "PNG" )
	{
		ui.RB_Format_PNG->setChecked( true );
	}
	else if( fmt == "JPEG" )
	{
		ui.RB_Format_Jpeg->setChecked( true );
	}
	else
	{
		ui.RB_Format_PPM->setChecked( true );
	}
	
	// Jpeg Quality
	ui.HS_Jpeg_Quality->setValue( Settings.value("Jpeg_Quality", "75").toString().toInt() );
}

void Screenshot_Options_Window::on_TB_Screenshot_Folder_clicked()
{
	QString folder = QFileDialog::getExistingDirectory(
			this, tr("Select Folder for Screenshots"),
					 Settings.value("Screenshot_Folder_Path", "~").toString() );
	
	if( ! (folder.isNull() || folder.isEmpty()) )
	{
		ui.Edit_Screenshot_Folder->setText( folder );
	}
}

void Screenshot_Options_Window::on_Button_OK_clicked()
{
	// Use Shared Folder For All Screenshots
	if( ui.CH_Screenshot_Folder->isChecked() )
	{
		Settings.setValue( "Use_Screenshots_Folder", "yes" );
		
		QDir dir; // For Check on valid
		
		// Screenshots Shared Folder Path
		if( dir.exists(ui.Edit_Screenshot_Folder->text()) )
		{
			Settings.setValue( "Screenshot_Folder_Path",
								ui.Edit_Screenshot_Folder->text() );
		}
		else
		{
			AQGraphic_Warning( tr("Invalid Value!"),
							   tr("Shared Folder for Screenshots is Not Exists!") );
			return;
		}
	}
	else
	{
		Settings.setValue( "Use_Screenshots_Folder", "no" );
		
		// Screenshots Shared Folder Path
		Settings.setValue( "Screenshot_Folder_Path",
							ui.Edit_Screenshot_Folder->text() );
	}
	
	// Screenshot save format
	if( ui.RB_Format_PNG->isChecked() )
	{
		Settings.setValue( "Screenshot_Save_Format", "PNG" );
	}
	else if( ui.RB_Format_Jpeg->isChecked() )
	{
		Settings.setValue( "Screenshot_Save_Format", "JPEG" );
	}
	else
	{
		Settings.setValue( "Screenshot_Save_Format", "PPM" );
	}
	
	// Jpeg Quality
	Settings.setValue( "Jpeg_Quality", QString::number(ui.HS_Jpeg_Quality->value()) );
	
	accept();
}
