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

#ifndef SCREENSHOT_OPTIONS_WINDOW_H
#define SCREENSHOT_OPTIONS_WINDOW_H

#include <QSettings>

#include "ui_Screenshot_Options_Window.h"

class Screenshot_Options_Window: public QDialog
{
	Q_OBJECT
	
	public:
		Screenshot_Options_Window( QWidget *parent = 0 );
	
	private slots:
		void on_TB_Screenshot_Folder_clicked();
		void on_Button_OK_clicked();
	
	private:
		Ui::Screenshot_Options_Window ui;
		QSettings Settings;
};

#endif
