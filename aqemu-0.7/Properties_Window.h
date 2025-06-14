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

#ifndef PROPERTIES_WINDOW_H
#define PROPERTIES_WINDOW_H

#include "VM_Devices.h"
#include "ui_Properties_Window.h"

class Properties_Window: public QDialog
{
	Q_OBJECT

	public:
		Properties_Window( QWidget *parent = 0 );
		
		const VM_Floppy &Get_Floppy();
		const VM_CDROM &Get_CD_ROM();
		const VM_HDD &Get_HDD();
		
		void Set_Floppy( const VM_Floppy &fd, const QString &name );
		void Set_CD_ROM( const VM_CDROM &cd, const QString &name );
		void Set_HDD( const VM_HDD &hd, const QString &name );
		
	private slots:
		void on_Button_OK_clicked();
		void on_Button_Cancel_clicked();
		
		void on_Button_Update_Info_clicked();
		
		void on_TB_FD_Image_Browse_clicked();
		void on_TB_CDROM_Image_Browse_clicked();
		void on_TB_HDD_Image_Browse_clicked();
		void on_Button_HDD_New_clicked();
		void on_Button_HDD_Format_clicked();
		
		void on_RB_FD_Host_toggled( bool on );
		void on_RB_CDROM_Host_toggled( bool on );
		
	private:
		Ui::Properties_Window ui;
		VM_Floppy PW_Floppy;
		VM_CDROM PW_CDROM;
		VM_HDD PW_HDD;
};

#endif
