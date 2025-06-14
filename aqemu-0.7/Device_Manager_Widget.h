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

#ifndef DEVICE_MANAGER_WIDGET_H
#define DEVICE_MANAGER_WIDGET_H

#include "VM.h"
#include "Add_New_Device_Window.h"
#include "Properties_Window.h"
#include "ui_Device_Manager_Widget.h"

class Device_Manager_Widget: public QWidget
{
	Q_OBJECT
	
	public:
		Device_Manager_Widget( QWidget *parent = 0 );
		~Device_Manager_Widget();
		void Set_VM( const Virtual_Machine &vm );
		void Update_Enabled_Actions();
		
		void Update_List_Mode();
		
		VM_Floppy Floppy1; // FD0
		VM_Floppy Floppy2; // FD1
		VM_CDROM CD_ROM; // cdrom device ide2
		VM_HDD HDA; // ide0
		VM_HDD HDB; // ide1
		VM_HDD HDC; // ide2 if cdrom is enabled, hdc be disibled
		VM_HDD HDD; // ide3
		QList<VM_Storage_Device> Storage_Devices;
		
	signals:
		void Device_Changet();
	
	private slots:
		// For Context Menu
		void on_Devices_List_customContextMenuRequested( const QPoint &pos );
		void on_Devices_List_currentItemChanged( QListWidgetItem *current, QListWidgetItem *previous );
		void on_Devices_List_itemDoubleClicked( QListWidgetItem *item );
		
		void on_actionAdd_Floppy_triggered();
		void on_actionAdd_CD_ROM_triggered();
		void on_actionAdd_HDD_triggered();
		void on_actionAdd_Device_triggered();
		void on_actionProperties_triggered();
		void on_actionDelete_triggered();
		void on_actionFormat_HDD_triggered();
		void on_actionQuick_Format_triggered();
		void on_actionIcon_Mode_triggered();
		void on_actionList_Mode_triggered();
		
		void Update_Icons();
		
	private:
		Add_New_Device_Window *Device_Window;
		Properties_Window *pw;
		Ui::Device_Manager_Widget ui;
		QMenu *Context_Menu;
};

#endif
