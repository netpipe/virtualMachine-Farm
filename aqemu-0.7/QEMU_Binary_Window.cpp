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

#include <QtGui>
#include <QFileDialog>
#include "QEMU_Binary_Window.h"

QEMU_Binary_Window::QEMU_Binary_Window( QWidget *parent )
	: QDialog( parent )
{
	ui.setupUi( this );
	
	on_Button_Reset_Settings_clicked();
	
	QSettings settings;
	
	for( int ix = 0; ix < ui.Table_QEMU_Systems->rowCount(); ++ix )
	{
		QString tmp_str = settings.value( "QEMU_Systems/" + ui.Table_QEMU_Systems->item(ix,0)->text(), "" ).toString();
		
		if( ! tmp_str.isEmpty() )
		{
			ui.Table_QEMU_Systems->item(ix,1)->setText( tmp_str );
		}
	}
	
	ui.Table_QEMU_Systems->resizeColumnsToContents();
	ui.Table_QEMU_Systems->resizeRowsToContents();
	
	QHeaderView * hv = new QHeaderView( Qt::Vertical, ui.Table_QEMU_Systems );
    //hv->setResizeMode( QHeaderView::Fixed );
	ui.Table_QEMU_Systems->setVerticalHeader( hv );
	
	hv = new QHeaderView( Qt::Horizontal, ui.Table_QEMU_Systems );
//	hv->setResizeMode( QHeaderView::Stretch );
	ui.Table_QEMU_Systems->setHorizontalHeader( hv );
}

void QEMU_Binary_Window::on_Edit_Binary_Path_textChanged()
{
	if( ui.Table_QEMU_Systems->currentRow() < 0 ) return;
	
	ui.Table_QEMU_Systems->item( ui.Table_QEMU_Systems->currentRow(), 1 )->setText( ui.Edit_Binary_Path->text() );
}

void QEMU_Binary_Window::on_Table_QEMU_Systems_cellClicked( int row, int column )
{
	ui.Edit_Binary_Path->setText( ui.Table_QEMU_Systems->item( row, 1 )->text() );
}

void QEMU_Binary_Window::on_Button_Reset_Settings_clicked()
{
	ui.Table_QEMU_Systems->clearContents();
	
	while( ui.Table_QEMU_Systems->rowCount() > 0 )
	{
		ui.Table_QEMU_Systems->removeRow( 0 );
	}
	
	QTableWidgetItem *newItem = new QTableWidgetItem( "qemu-system-x86" );
	ui.Table_QEMU_Systems->insertRow( ui.Table_QEMU_Systems->rowCount() );
	ui.Table_QEMU_Systems->setItem( ui.Table_QEMU_Systems->rowCount()-1, 0, newItem );
	newItem = new QTableWidgetItem( "qemu" );
	ui.Table_QEMU_Systems->setItem( ui.Table_QEMU_Systems->rowCount()-1, 1, newItem );
	
	newItem = new QTableWidgetItem( "qemu-system-x86_64" );
	ui.Table_QEMU_Systems->insertRow( ui.Table_QEMU_Systems->rowCount() );
	ui.Table_QEMU_Systems->setItem( ui.Table_QEMU_Systems->rowCount()-1, 0, newItem );
	newItem = new QTableWidgetItem( "qemu-system-x86_64" );
	ui.Table_QEMU_Systems->setItem( ui.Table_QEMU_Systems->rowCount()-1, 1, newItem );
	
	newItem = new QTableWidgetItem( "qemu-kvm" );
	ui.Table_QEMU_Systems->insertRow( ui.Table_QEMU_Systems->rowCount() );
	ui.Table_QEMU_Systems->setItem( ui.Table_QEMU_Systems->rowCount()-1, 0, newItem );
	newItem = new QTableWidgetItem( "qemu-kvm" );
	ui.Table_QEMU_Systems->setItem( ui.Table_QEMU_Systems->rowCount()-1, 1, newItem );
	
	newItem = new QTableWidgetItem( "qemu-system-arm" );
	ui.Table_QEMU_Systems->insertRow( ui.Table_QEMU_Systems->rowCount() );
	ui.Table_QEMU_Systems->setItem( ui.Table_QEMU_Systems->rowCount()-1, 0, newItem );
	newItem = new QTableWidgetItem( "qemu-system-arm" );
	ui.Table_QEMU_Systems->setItem( ui.Table_QEMU_Systems->rowCount()-1, 1, newItem );
	
	newItem = new QTableWidgetItem( "qemu-system-cris" );
	ui.Table_QEMU_Systems->insertRow( ui.Table_QEMU_Systems->rowCount() );
	ui.Table_QEMU_Systems->setItem( ui.Table_QEMU_Systems->rowCount()-1, 0, newItem );
	newItem = new QTableWidgetItem( "qemu-system-cris" );
	ui.Table_QEMU_Systems->setItem( ui.Table_QEMU_Systems->rowCount()-1, 1, newItem );
	
	newItem = new QTableWidgetItem( "qemu-system-m68k" );
	ui.Table_QEMU_Systems->insertRow( ui.Table_QEMU_Systems->rowCount() );
	ui.Table_QEMU_Systems->setItem( ui.Table_QEMU_Systems->rowCount()-1, 0, newItem );
	newItem = new QTableWidgetItem( "qemu-system-m68k" );
	ui.Table_QEMU_Systems->setItem( ui.Table_QEMU_Systems->rowCount()-1, 1, newItem );
	
	newItem = new QTableWidgetItem( "qemu-system-mips" );
	ui.Table_QEMU_Systems->insertRow( ui.Table_QEMU_Systems->rowCount() );
	ui.Table_QEMU_Systems->setItem( ui.Table_QEMU_Systems->rowCount()-1, 0, newItem );
	newItem = new QTableWidgetItem( "qemu-system-mips" );
	ui.Table_QEMU_Systems->setItem( ui.Table_QEMU_Systems->rowCount()-1, 1, newItem );
	
	newItem = new QTableWidgetItem( "qemu-system-mipsel" );
	ui.Table_QEMU_Systems->insertRow( ui.Table_QEMU_Systems->rowCount() );
	ui.Table_QEMU_Systems->setItem( ui.Table_QEMU_Systems->rowCount()-1, 0, newItem );
	newItem = new QTableWidgetItem( "qemu-system-mipsel" );
	ui.Table_QEMU_Systems->setItem( ui.Table_QEMU_Systems->rowCount()-1, 1, newItem );
	
	newItem = new QTableWidgetItem( "qemu-system-mips64" );
	ui.Table_QEMU_Systems->insertRow( ui.Table_QEMU_Systems->rowCount() );
	ui.Table_QEMU_Systems->setItem( ui.Table_QEMU_Systems->rowCount()-1, 0, newItem );
	newItem = new QTableWidgetItem( "qemu-system-mips64" );
	ui.Table_QEMU_Systems->setItem( ui.Table_QEMU_Systems->rowCount()-1, 1, newItem );
	
	newItem = new QTableWidgetItem( "qemu-system-mips64el" );
	ui.Table_QEMU_Systems->insertRow( ui.Table_QEMU_Systems->rowCount() );
	ui.Table_QEMU_Systems->setItem( ui.Table_QEMU_Systems->rowCount()-1, 0, newItem );
	newItem = new QTableWidgetItem( "qemu-system-mips64el" );
	ui.Table_QEMU_Systems->setItem( ui.Table_QEMU_Systems->rowCount()-1, 1, newItem );
	
	newItem = new QTableWidgetItem( "qemu-system-ppc" );
	ui.Table_QEMU_Systems->insertRow( ui.Table_QEMU_Systems->rowCount() );
	ui.Table_QEMU_Systems->setItem( ui.Table_QEMU_Systems->rowCount()-1, 0, newItem );
	newItem = new QTableWidgetItem( "qemu-system-ppc" );
	ui.Table_QEMU_Systems->setItem( ui.Table_QEMU_Systems->rowCount()-1, 1, newItem );
	
	newItem = new QTableWidgetItem( "qemu-system-ppc64" );
	ui.Table_QEMU_Systems->insertRow( ui.Table_QEMU_Systems->rowCount() );
	ui.Table_QEMU_Systems->setItem( ui.Table_QEMU_Systems->rowCount()-1, 0, newItem );
	newItem = new QTableWidgetItem( "qemu-system-ppc64" );
	ui.Table_QEMU_Systems->setItem( ui.Table_QEMU_Systems->rowCount()-1, 1, newItem );
	
	newItem = new QTableWidgetItem( "qemu-system-ppcemb" );
	ui.Table_QEMU_Systems->insertRow( ui.Table_QEMU_Systems->rowCount() );
	ui.Table_QEMU_Systems->setItem( ui.Table_QEMU_Systems->rowCount()-1, 0, newItem );
	newItem = new QTableWidgetItem( "qemu-system-ppcemb" );
	ui.Table_QEMU_Systems->setItem( ui.Table_QEMU_Systems->rowCount()-1, 1, newItem );
	
	newItem = new QTableWidgetItem( "qemu-system-sh4" );
	ui.Table_QEMU_Systems->insertRow( ui.Table_QEMU_Systems->rowCount() );
	ui.Table_QEMU_Systems->setItem( ui.Table_QEMU_Systems->rowCount()-1, 0, newItem );
	newItem = new QTableWidgetItem( "qemu-system-sh4" );
	ui.Table_QEMU_Systems->setItem( ui.Table_QEMU_Systems->rowCount()-1, 1, newItem );
	
	newItem = new QTableWidgetItem( "qemu-system-sh4eb" );
	ui.Table_QEMU_Systems->insertRow( ui.Table_QEMU_Systems->rowCount() );
	ui.Table_QEMU_Systems->setItem( ui.Table_QEMU_Systems->rowCount()-1, 0, newItem );
	newItem = new QTableWidgetItem( "qemu-system-sh4eb" );
	ui.Table_QEMU_Systems->setItem( ui.Table_QEMU_Systems->rowCount()-1, 1, newItem );
	
	newItem = new QTableWidgetItem( "qemu-system-sparc" );
	ui.Table_QEMU_Systems->insertRow( ui.Table_QEMU_Systems->rowCount() );
	ui.Table_QEMU_Systems->setItem( ui.Table_QEMU_Systems->rowCount()-1, 0, newItem );
	newItem = new QTableWidgetItem( "qemu-system-sparc" );
	ui.Table_QEMU_Systems->setItem( ui.Table_QEMU_Systems->rowCount()-1, 1, newItem );
	
	ui.Table_QEMU_Systems->resizeColumnsToContents();
}

void QEMU_Binary_Window::on_TB_Binary_Browse_clicked()
{
	QString binName = QFileDialog::getOpenFileName( this, tr("Select QEMU Binary File"),
			"/usr/", tr("All Files (*)") );
	
	if( ! (binName.isNull() || binName.isEmpty()) )
	{
		ui.Edit_Binary_Path->setText( binName );
	}
}

void QEMU_Binary_Window::on_Button_OK_clicked()
{
	QSettings settings;
	
	for( int ix = 0; ix < ui.Table_QEMU_Systems->rowCount(); ++ix )
	{
		settings.setValue( "QEMU_Systems/" + ui.Table_QEMU_Systems->item(ix, 0)->text(),
						   ui.Table_QEMU_Systems->item(ix, 1)->text() );
	}
	
	accept();
}
