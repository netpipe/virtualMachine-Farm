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

#ifndef PORTS_TAB_WINGET_H
#define PORTS_TAB_WINGET_H

#include "VM_Devices.h"
#include "ui_Ports_Tab_Widget.h"

class Ports_Tab_Widget: public QWidget
{
	Q_OBJECT
	
	public:
		Ports_Tab_Widget( QWidget *parent = 0 );
		
		void Apply_USB_State();
		
		const VM_Port &Get_Serial_Port();
		void Set_Serial_Port( const VM_Port &sp );
		
		const VM_Port &Get_Parallel_Port();
		void Set_Parallel_Port( const VM_Port &pp );
		
		QList<VM_USB> &Get_USB_List();
		void Set_USB_List( const QList<VM_USB> &list );
		
		bool Get_USB_Hub_State() const;
		void Set_USB_Hub_State( bool s );
		
	private slots:
		void on_TB_Serial_Other_clicked();
		void on_TB_Parallel_Other_clicked();
		
		void on_Button_Add_USB_Device_clicked();
		void on_Button_Delete_USB_Device_clicked();
		void on_Button_Update_Host_USB_clicked();
		void on_Button_Clear_VM_USB_List_clicked();
		
	private:
		Ui::Ports_Tab_Widget ui;
		
		void No_USB_Ui( bool on );
		
		VM_Port Serial_Port;
		VM_Port Parallel_Port;
		
		QList<VM_USB> USB_Host_List;
		QList<VM_USB> USB_List;
};

#endif
