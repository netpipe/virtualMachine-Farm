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

#ifndef SYSTEM_INFO_H
#define SYSTEM_INFO_H

#include "Utils.h"
#include "VM_Devices.h"

class System_Info
{
	public:
		System_Info();
		
		static bool Update_VM_Computers_List();
		static bool Check_QEMU_Version();
		static bool Check_Availability_KVM();
		static bool Get_All_Host_USB( QList<VM_USB> &usb_list );
		static int Get_Free_Memory_Size();
		static QStringList Get_Host_FDD_List();
		static QStringList Get_Host_CDROM_List();
		
		static QList<Averable_Devices> VM_Computers;
};

#endif
