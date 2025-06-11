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

#include "Error_Log_Window.h"

Error_Log_Window::Error_Log_Window( QWidget *parent )
	: QDialog( parent )
{
	ui.setupUi( this );
	Errors_Count = 0;
	ui.Edit_Log->setText(
			"--------------------------------------------------------------------------------------------------" );
}

void Error_Log_Window::Add_to_Log( const QString& err_str )
{
	Errors_Count++;
	ui.Edit_Log->append( tr("Error #") + QString::number(Errors_Count)
			+ "\n" + err_str
			+ "--------------------------------------------------------------------------------------------------" );
}
