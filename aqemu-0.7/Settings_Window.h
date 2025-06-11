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

#ifndef SETTINGS_WINDOW_H
#define SETTINGS_WINDOW_H

#include <QSettings>
#include <QList>

#include "ui_Settings_Window.h"

class Settings_Window: public QDialog
{
	Q_OBJECT
	
	public:
		Settings_Window( QWidget *parent = 0 );
		~Settings_Window();
		
		bool Advanced_Win_Show;
		
	private slots:
		void on_Button_Create_Template_from_VM_clicked();
		void on_TB_VM_Folder_clicked();
		void on_Button_Box_clicked( QAbstractButton* button );
		void on_CB_Language_currentIndexChanged( int index );
		void on_Button_Screenshots_Settings_clicked();
		void on_Button_QEMU_Binary_clicked();
		void on_Button_Advanced_Settings_clicked();
		
		#ifdef VNC_DISPLAY
		void on_CH_Show_Emulator_Control_Window_toggled( bool checked );
		#endif
		
	private:
		void Load_Templates();
		QSettings *Settings;
		Ui::Settings_Window ui;
		bool First_Show;
};

#endif
