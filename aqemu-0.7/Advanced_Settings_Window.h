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

#ifndef ADVANCED_SETTINGS_WINDOW_H
#define ADVANCED_SETTINGS_WINDOW_H

#include <QSettings>
#include "VM_Devices.h"
#include "ui_Advanced_Settings_Window.h"

class Advanced_Settings_Window: public QDialog
{
	Q_OBJECT
	
	public:
		Advanced_Settings_Window( QWidget *parent = 0 );
	
	public slots:
		void on_Button_OK_clicked();
		
	private slots:
		void on_TB_Browse_Before_clicked();
		void on_TB_Browse_After_clicked();
		void on_TB_Log_File_clicked();
		void on_TB_QEMU_IMG_Browse_clicked();
		
		void on_CH_Check_Version_on_Start_toggled( bool on );
		void on_RB_QEMU_Version_Manual_toggled( bool on );
	
	private:
		Ui::Advanced_Settings_Window ui;
		QSettings Settings;
};

#endif
