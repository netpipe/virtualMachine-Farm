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
#include <QFileInfoList>
#include <QDir>

#include "Utils.h"
#include "Select_Icon_Window.h"

Select_Icon_Window::Select_Icon_Window( QWidget *parent )
	: QDialog( parent )
{
	ui.setupUi( this );
	
	GB_Locked = false;
	
	ui.GB_Default_Icons->setChecked( false );
	ui.GB_All_Icons->setChecked( false );
	ui.GB_Other_Icons->setChecked( false );
	
	// load all icons
	QDir *icons_dir = new QDir( Settings.value("AQEMU_Data_Folder", "").toString() + "/os_icons/" );
	QFileInfoList icon_files = icons_dir->entryInfoList( QDir::Files, QDir::Name | QDir::IgnoreCase );
	
	for( int ix = 0; ix < icon_files.count(); ++ix )
	{
		QListWidgetItem *ic = new QListWidgetItem( QIcon(icon_files[ix].absoluteFilePath()),
				icon_files[ix].baseName(), ui.All_Icons_List );
		ic->setData( 128, icon_files[ix].absoluteFilePath() );
	}
}

void Select_Icon_Window::Set_Previous_Icon_Path( const QString& path )
{
	// Analise path...
	if( path[0] == ':' ) // AQEMU Default Icons
	{
		ui.GB_Default_Icons->setChecked( true );
		
		if( path.indexOf("linux") > 0 ) ui.RB_Icon_Linux->setChecked( true );
		else if( path.indexOf("windows") > 0 ) ui.RB_Icon_Windows->setChecked( true );
		else ui.RB_Icon_Other->setChecked( true );
	}
	else if( path.indexOf(Settings.value("AQEMU_Data_Folder", "").toString() + "/os_icons/") == 0 ) // AQEMU Icons Folder
	{
		ui.GB_All_Icons->setChecked( true );
		
		QFileInfo fl = QFileInfo( path );
		
		for( int ix = 0; ix < ui.All_Icons_List->count(); ++ix )
		{
			if( ui.All_Icons_List->item(ix)->text() == fl.baseName() )
			{
				ui.All_Icons_List->setCurrentRow( ix );
				ui.All_Icons_List->scrollToItem( ui.All_Icons_List->item(ix),
						QAbstractItemView::PositionAtCenter );
			}
		}
	}
	else
	{
		// Other Path
		ui.GB_Other_Icons->setChecked( true );
		ui.Edit_Other_Icon_Path->setText( path );
	}
}

QString Select_Icon_Window::Get_New_Icon_Path() const
{
	return New_Icon_Path;
}

void Select_Icon_Window::on_Button_OK_clicked()
{
	// Check values
	if( ui.GB_Default_Icons->isChecked() )
	{
		if( ui.RB_Icon_Other->isChecked() )
		{
			New_Icon_Path = ":/images/other.png";
			accept();
		}
		else if( ui.RB_Icon_Windows->isChecked() )
		{
			New_Icon_Path = ":/images/default_windows.png";
			accept();
		}
		else if( ui.RB_Icon_Linux->isChecked() )
		{
			New_Icon_Path = ":/images/default_linux.png";
			accept();
		}
	}
	else if( ui.GB_All_Icons->isChecked() )
	{
		if( ui.All_Icons_List->currentItem() != NULL )
		{
			New_Icon_Path = ui.All_Icons_List->currentItem()->data( 128 ).toString();
			accept();
		}
	}
	else if( ui.GB_Other_Icons->isChecked() )
	{
		if( QFile::exists(ui.Edit_Other_Icon_Path->text()) )
		{
			New_Icon_Path = ui.Edit_Other_Icon_Path->text();
			accept();
		}
		else
		{
			AQGraphic_Warning( tr("Error!"), tr("Icon File Not Exists!") );
		}
	}
}

void Select_Icon_Window::on_Button_Browse_clicked()
{
	QString icon_path = QFileDialog::getOpenFileName( this,
			tr("Select Icon File:"), QDir::homePath(), tr("PNG Images (*.png)") );
	
	if( icon_path.isEmpty() ) return;
	
	if( ! QFile::exists(icon_path) )
	{
		AQError( "void Select_Icon_Window::on_Button_Browse_clicked()",
				 "File No Exists!" );
	}
	else
	{
		ui.Edit_Other_Icon_Path->setText( icon_path );
	}
}

void Select_Icon_Window::on_GB_Default_Icons_toggled( bool on )
{
	if( ! on ) return;
	
	if( GB_Locked == false )
	{
		GB_Locked = true;
		
		ui.GB_All_Icons->setChecked( ! on );
		ui.GB_Other_Icons->setChecked( ! on );
		
		GB_Locked = false;
	}
}

void Select_Icon_Window::on_GB_All_Icons_toggled( bool on )
{
	if( ! on ) return;
	
	if( GB_Locked == false )
	{
		GB_Locked = true;
		
		ui.GB_Default_Icons->setChecked( ! on );
		ui.GB_Other_Icons->setChecked( ! on );
		
		GB_Locked = false;
	}
}

void Select_Icon_Window::on_GB_Other_Icons_toggled( bool on )
{
	if( ! on ) return;
	
	if( GB_Locked == false )
	{
		GB_Locked = true;
		
		ui.GB_Default_Icons->setChecked( ! on );
		ui.GB_All_Icons->setChecked( ! on );
		
		GB_Locked = false;
	}
}

void Select_Icon_Window::on_All_Icons_List_itemDoubleClicked( QListWidgetItem *item )
{
	on_Button_OK_clicked();
}
