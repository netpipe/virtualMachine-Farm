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

#include <QTextStream>
#include <QFileDialog>
#include <QSettings>
#include <QFile>
#include <QProcess>
#include <QFileDialog>

#include "Utils.h"
#include "System_Info.h"
#include "Ports_Tab_Widget.h"

Ports_Tab_Widget::Ports_Tab_Widget( QWidget *parent )
	: QWidget( parent )
{
	ui.setupUi( this );
	
	Serial_Port = VM_Port();
	Parallel_Port = VM_Port();
	
	on_Button_Update_Host_USB_clicked();
}

void Ports_Tab_Widget::Apply_USB_State()
{
	on_Button_Update_Host_USB_clicked();
}

const VM_Port &Ports_Tab_Widget::Get_Serial_Port()
{
	if( ui.RB_Serial_Default->isChecked() )
	{
		Serial_Port.Set_Port_Redirection( VM::PR_Default );
	}
	else if( ui.RB_Serial_vc->isChecked() )
	{
		Serial_Port.Set_Port_Redirection( VM::PR_vc );
	}
	else if( ui.RB_Serial_pty->isChecked() )
	{
		Serial_Port.Set_Port_Redirection( VM::PR_pty );
	}
	else if( ui.RB_Serial_none->isChecked() )
	{
		Serial_Port.Set_Port_Redirection( VM::PR_none );
	}
	else if( ui.RB_Serial_null->isChecked() )
	{
		Serial_Port.Set_Port_Redirection( VM::PR_null );
	}
	else if( ui.RB_Serial_stdio->isChecked() )
	{
		Serial_Port.Set_Port_Redirection( VM::PR_stdio );
	}
	else if( ui.RB_Serial_Dev->isChecked() )
	{
		Serial_Port.Set_Port_Redirection( VM::PR_dev );
	}
	else if( ui.RB_Serial_Host_Port->isChecked() )
	{
		Serial_Port.Set_Port_Redirection( VM::PR_host_port );
	}
	else if( ui.RB_Serial_File->isChecked() )
	{
		Serial_Port.Set_Port_Redirection( VM::PR_file );
	}
	else if( ui.RB_Serial_Pipe->isChecked() )
	{
		Serial_Port.Set_Port_Redirection( VM::PR_pipe );
	}
	else if( ui.RB_Serial_UDP->isChecked() )
	{
		Serial_Port.Set_Port_Redirection( VM::PR_udp );
	}
	else if( ui.RB_Serial_TCP->isChecked() )
	{
		Serial_Port.Set_Port_Redirection( VM::PR_tcp );
	}
	else if( ui.RB_Serial_Telnet->isChecked() )
	{
		Serial_Port.Set_Port_Redirection( VM::PR_telnet );
	}
	else if( ui.RB_Serial_Unix->isChecked() )
	{
		Serial_Port.Set_Port_Redirection( VM::PR_unix );
	}
	else
	{
		AQError( "const VM_Port &Ports_Tab_Widget::Get_Serial_Port()",
				 "Invalid Port Redirection!" );
	}
	
	// Set Parametrs
	Serial_Port.Set_Parametrs_Line( ui.Edit_Serial_Other->text() );
	
	return Serial_Port;
}

const VM_Port &Ports_Tab_Widget::Get_Parallel_Port()
{
	if( ui.RB_Parallel_Default->isChecked() )
	{
		Parallel_Port.Set_Port_Redirection( VM::PR_Default );
	}
	else if( ui.RB_Parallel_vc->isChecked() )
	{
		Parallel_Port.Set_Port_Redirection( VM::PR_vc );
	}
	else if( ui.RB_Parallel_pty->isChecked() )
	{
		Parallel_Port.Set_Port_Redirection( VM::PR_pty );
	}
	else if( ui.RB_Parallel_none->isChecked() )
	{
		Parallel_Port.Set_Port_Redirection( VM::PR_none );
	}
	else if( ui.RB_Parallel_null->isChecked() )
	{
		Parallel_Port.Set_Port_Redirection( VM::PR_null );
	}
	else if( ui.RB_Parallel_stdio->isChecked() )
	{
		Parallel_Port.Set_Port_Redirection( VM::PR_stdio );
	}
	else if( ui.RB_Parallel_Dev->isChecked() )
	{
		Parallel_Port.Set_Port_Redirection( VM::PR_dev );
	}
	else if( ui.RB_Parallel_Host_Port->isChecked() )
	{
		Parallel_Port.Set_Port_Redirection( VM::PR_host_port );
	}
	else if( ui.RB_Parallel_File->isChecked() )
	{
		Parallel_Port.Set_Port_Redirection( VM::PR_file );
	}
	else if( ui.RB_Parallel_Pipe->isChecked() )
	{
		Parallel_Port.Set_Port_Redirection( VM::PR_pipe );
	}
	else if( ui.RB_Parallel_UDP->isChecked() )
	{
		Parallel_Port.Set_Port_Redirection( VM::PR_udp );
	}
	else if( ui.RB_Parallel_TCP->isChecked() )
	{
		Parallel_Port.Set_Port_Redirection( VM::PR_tcp );
	}
	else if( ui.RB_Parallel_Telnet->isChecked() )
	{
		Parallel_Port.Set_Port_Redirection( VM::PR_telnet );
	}
	else if( ui.RB_Parallel_Unix->isChecked() )
	{
		Parallel_Port.Set_Port_Redirection( VM::PR_unix );
	}
	else
	{
		AQError( "const VM_Port &Ports_Tab_Widget::Get_Parallel_Port()",
				 "Invalid Port Redirection!" );
	}
	
	// Set Parametrs
	Parallel_Port.Set_Parametrs_Line( ui.Edit_Parallel_Other->text() );
	
	return Parallel_Port;
}

void Ports_Tab_Widget::Set_Serial_Port( const VM_Port &sp )
{
	switch( sp.Get_Port_Redirection() )
	{
		case VM::PR_vc:
			ui.RB_Serial_vc->setChecked( true );
			break;
			
		case VM::PR_pty:
			ui.RB_Serial_pty->setChecked( true );
			break;
			
		case VM::PR_none:
			ui.RB_Serial_none->setChecked( true );
			break;
			
		case VM::PR_null:
			ui.RB_Serial_null->setChecked( true );
			break;
			
		case VM::PR_dev:
			ui.RB_Serial_Dev->setChecked( true );
			break;
			
		case VM::PR_host_port:
			ui.RB_Serial_Host_Port->setChecked( true );
			break;
			
		case VM::PR_file:
			ui.RB_Serial_File->setChecked( true );
			break;
			
		case VM::PR_stdio:
			ui.RB_Serial_stdio->setChecked( true );
			break;
			
		case VM::PR_pipe:
			ui.RB_Serial_Pipe->setChecked( true );
			break;
			
		case VM::PR_udp:
			ui.RB_Serial_UDP->setChecked( true );
			break;
			
		case VM::PR_tcp:
			ui.RB_Serial_TCP->setChecked( true );
			break;
			
		case VM::PR_telnet:
			ui.RB_Serial_Telnet->setChecked( true );
			break;
			
		case VM::PR_unix:
			ui.RB_Serial_Unix->setChecked( true );
			break;
			
		default:
			ui.RB_Serial_Default->setChecked( true );
			break;
	}
	
	ui.Edit_Serial_Other->setText( sp.Get_Parametrs_Line() );
}

void Ports_Tab_Widget::Set_Parallel_Port( const VM_Port &pp )
{
	switch( pp.Get_Port_Redirection() )
	{
		case VM::PR_vc:
			ui.RB_Parallel_vc->setChecked( true );
			break;
			
		case VM::PR_pty:
			ui.RB_Parallel_pty->setChecked( true );
			break;
			
		case VM::PR_none:
			ui.RB_Parallel_none->setChecked( true );
			break;
			
		case VM::PR_null:
			ui.RB_Parallel_null->setChecked( true );
			break;
			
		case VM::PR_dev:
			ui.RB_Parallel_Dev->setChecked( true );
			break;
			
		case VM::PR_host_port:
			ui.RB_Parallel_Host_Port->setChecked( true );
			break;
			
		case VM::PR_file:
			ui.RB_Parallel_File->setChecked( true );
			break;
			
		case VM::PR_stdio:
			ui.RB_Parallel_stdio->setChecked( true );
			break;
			
		case VM::PR_pipe:
			ui.RB_Parallel_Pipe->setChecked( true );
			break;
			
		case VM::PR_udp:
			ui.RB_Parallel_UDP->setChecked( true );
			break;
			
		case VM::PR_tcp:
			ui.RB_Parallel_TCP->setChecked( true );
			break;
			
		case VM::PR_telnet:
			ui.RB_Parallel_Telnet->setChecked( true );
			break;
			
		case VM::PR_unix:
			ui.RB_Parallel_Unix->setChecked( true );
			break;
			
		default:
			ui.RB_Parallel_Default->setChecked( true );
			break;
	}
	
	ui.Edit_Parallel_Other->setText( pp.Get_Parametrs_Line() );
}

QList<VM_USB> &Ports_Tab_Widget::Get_USB_List()
{
	return USB_List;
}

void Ports_Tab_Widget::Set_USB_List( const QList<VM_USB> &list )
{
	USB_List.clear();
	on_Button_Clear_VM_USB_List_clicked();
	
	for( int ix = 0; ix < list.count(); ++ix )
	{
		USB_List.append( VM_USB(list[ix]) );
		
		// Show List
		ui.Table_VM_USB->insertRow( ui.Table_VM_USB->rowCount() );
		
		QTableWidgetItem *newItem = new QTableWidgetItem( list[ix].Get_Manufacturer_Name() );
		ui.Table_VM_USB->setItem( ui.Table_VM_USB->rowCount()-1, 0, newItem );
		
		newItem = new QTableWidgetItem( list[ix].Get_Product_Name() );
		ui.Table_VM_USB->setItem( ui.Table_VM_USB->rowCount()-1, 1, newItem );
	}
	
	ui.Table_VM_USB->resizeColumnsToContents();
}

bool Ports_Tab_Widget::Get_USB_Hub_State() const
{
	return ui.CH_USB_Hub->isChecked();
}

void Ports_Tab_Widget::Set_USB_Hub_State( bool s )
{
	ui.CH_USB_Hub->setChecked( s );
}

void Ports_Tab_Widget::on_TB_Serial_Other_clicked()
{
	QString dir = "";
	
	switch( Serial_Port.Get_Port_Redirection() )
	{
		case VM::PR_dev:
			dir = "/dev/";
			break;
			
		case VM::PR_host_port:
			dir = "/dev/";
			break;
			
		case VM::PR_file:
			dir = "/home/";
			break;
			
		case VM::PR_pipe:
			dir = "/";
			break;
			
		default:
			dir = "/";
			break;
	}
	
	QString so = QFileDialog::getOpenFileName( this, tr("Open File"), dir, tr("All Files (*)") );
	
	if( ! (so.isEmpty() || so.isNull()) )
	{
		ui.Edit_Serial_Other->setText( so );
	}
}

void Ports_Tab_Widget::on_TB_Parallel_Other_clicked()
{
	QString dir = "";
	
	switch( Parallel_Port.Get_Port_Redirection() )
	{
		case VM::PR_dev:
			dir = "/dev/";
			break;
			
		case VM::PR_host_port:
			dir = "/dev/";
			break;
			
		case VM::PR_file:
			dir = "/home/";
			break;
			
		case VM::PR_pipe:
			dir = "/";
			break;
			
		default:
			dir = "/";
			break;
	}
	
	QString po = QFileDialog::getOpenFileName( this, tr("Open File"), dir, tr("All Files (*)") );
	
	if( ! (po.isEmpty() || po.isNull()) )
	{
		ui.Edit_Parallel_Other->setText( po );
	}
}

void Ports_Tab_Widget::on_Button_Add_USB_Device_clicked()
{
	if( ui.Table_Host_USB->rowCount() < 1 ||
		ui.Table_Host_USB->currentRow() < 0 ) return;
	
	// Check for unique value
	for( int ax = 0; ax < ui.Table_VM_USB->rowCount(); ++ax )
	{
		if( ui.Table_Host_USB->item(ui.Table_Host_USB->currentRow(), 0)->text() ==
			ui.Table_VM_USB->item( ax, 0)->text() &&
			ui.Table_Host_USB->item(ui.Table_Host_USB->currentRow(), 1)->text() ==
			ui.Table_VM_USB->item( ax, 1)->text() )
		{
			AQWarning( "void Ports_Tab_Widget::on_Button_Add_USB_Device_clicked()",
					   "This is not unique value!" );
			return;
		}
	}
	
	USB_List << USB_Host_List[ ui.Table_Host_USB->currentRow() ];
	
	ui.Table_VM_USB->insertRow( ui.Table_VM_USB->rowCount() );
		
	QTableWidgetItem *newItem = new QTableWidgetItem(
			ui.Table_Host_USB->item(ui.Table_Host_USB->currentRow(), 0)->text() );
	ui.Table_VM_USB->setItem( ui.Table_VM_USB->rowCount()-1, 0, newItem );
		
	newItem = new QTableWidgetItem(
			ui.Table_Host_USB->item(ui.Table_Host_USB->currentRow(), 1)->text() );
	ui.Table_VM_USB->setItem( ui.Table_VM_USB->rowCount()-1, 1, newItem );
	
	//ui.Table_Host_USB->removeRow( ui.Table_Host_USB->currentRow() );
	
	ui.Table_VM_USB->resizeColumnsToContents();
}

void Ports_Tab_Widget::on_Button_Delete_USB_Device_clicked()
{
	if( ui.Table_VM_USB->currentRow() >= 0 &&
		ui.Table_VM_USB->currentRow() < ui.Table_VM_USB->rowCount() )
	{
		USB_List.removeAt( ui.Table_VM_USB->currentRow() );
		ui.Table_VM_USB->removeRow( ui.Table_VM_USB->currentRow() );
	}
}

void Ports_Tab_Widget::on_Button_Update_Host_USB_clicked()
{
	// Update User Interface
	ui.Table_Host_USB->clearContents();
	
	QSettings settings;
	if( settings.value("Use_USB", "no").toString() == "no" )
	{
		ui.Tab_USB_Ports->setEnabled( false );
		return;
	}
	else
	{
		ui.Tab_USB_Ports->setEnabled( true );
	}
	
	if( System_Info::Get_All_Host_USB(USB_Host_List) == false )
	{
		AQGraphic_Warning( tr("Error!"),
						   tr("Could Not Get USB Information From System!\nUSB Support is Disabled.\nAdd Support proc FS TO YOUR Kernel.") );
		settings.setValue( "Use_USB", "no" );
		No_USB_Ui( true );
		return;
	}
	
	for( int rx = 0; rx < ui.Table_Host_USB->rowCount(); )
	{
		ui.Table_Host_USB->removeRow( rx );
	}
	
	if( USB_Host_List.count() < 1 )
	{
		No_USB_Ui( true );
	}
	else
	{
		No_USB_Ui( false );
	}
	
	for( int ux = 0; ux < USB_Host_List.count(); ++ux )
	{
		ui.Table_Host_USB->insertRow( ui.Table_Host_USB->rowCount() );
		QTableWidgetItem *newItem;
		
		if( USB_Host_List[ux].Get_Manufacturer_Name().isEmpty() )
		{
			newItem = new QTableWidgetItem( USB_Host_List[ux].Get_Vendor_ID() );
		}
		else
		{
			newItem = new QTableWidgetItem( USB_Host_List[ux].Get_Manufacturer_Name() );
		}
		
		ui.Table_Host_USB->setItem( ui.Table_Host_USB->rowCount()-1, 0, newItem );
		
		if( USB_Host_List[ux].Get_Product_Name().isEmpty() )
		{
			newItem = new QTableWidgetItem( USB_Host_List[ux].Get_Product_ID() );
		}
		else
		{
			newItem = new QTableWidgetItem( USB_Host_List[ux].Get_Product_Name() );
		}
		
		ui.Table_Host_USB->setItem( ui.Table_Host_USB->rowCount()-1, 1, newItem );
	}
	
	ui.Table_Host_USB->resizeColumnsToContents();
}

void Ports_Tab_Widget::on_Button_Clear_VM_USB_List_clicked()
{
	USB_List.clear();
	ui.Table_VM_USB->clearContents();
	
	for( int rx = 0; rx < ui.Table_VM_USB->rowCount(); )
	{
		ui.Table_VM_USB->removeRow( rx );
	}
}

void Ports_Tab_Widget::No_USB_Ui( bool on )
{
	if( on )
	{
		QTableWidgetItem *newItem = new QTableWidgetItem( tr("No USB Devices Detected") );
		ui.Table_Host_USB->setItem( ui.Table_Host_USB->rowCount()-1, 1, newItem );
		
		ui.Button_Add_USB_Device->setEnabled( false );
		ui.Button_Delete_USB_Device->setEnabled( false );
	}
	else
	{
		ui.Button_Add_USB_Device->setEnabled( true );
		ui.Button_Delete_USB_Device->setEnabled( true );
	}
}
