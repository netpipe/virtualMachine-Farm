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

#include <QList>
#include <QObject>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QDomDocument>
#include <QMessageBox>
#include <QSettings>
#include <QUuid>
#include <QTest>
#include <QPainter>
#include <QTest>

#include <QRect>
#include <QLabel>
#include <QHBoxLayout>
#include <QDesktopWidget>

#include "VM.h"
#include "Utils.h"
#include "Emulator_Control_Window.h"
#include "System_Info.h"

// VM Class -----------------------------------------------------------------

Virtual_Machine::Virtual_Machine()
{
	// Default Machine
	AQDebug( "Virtual_Machine::Virtual_Machine()", "Begin" );
	
	Shared_Constructor();
	
	AQDebug( "Virtual_Machine::Virtual_Machine()", "End" );
}

Virtual_Machine::Virtual_Machine( const QString &name )
{
	AQDebug( "Virtual_Machine::Virtual_Machine( const QString &name )",
			 "Begin" );
	
	Shared_Constructor();
	Machine_Name = name;
	
	AQDebug( "Virtual_Machine::Virtual_Machine( const QString &name )",
			 "End" );
}

Virtual_Machine::Virtual_Machine( const Virtual_Machine &vm )
{
	AQDebug( "Virtual_Machine::Virtual_Machine( const Virtual_Machine &vm )",
			 "Begin" );
	
	this->QEMU_Process = new QProcess();
	this->State = vm.Get_State();
	this->Emu_Ctl = new Emulator_Control_Window();
	this->VM_Dom_Document = QDomDocument();
	this->VM_XML_File_Path = vm.Get_VM_XML_File_Path();
	
	QObject::connect( Emu_Ctl,
		SIGNAL(Ready_Read_Command(QString)),this,
		SLOT(Execute_Emu_Ctl_Command(QString)) );
	
	QObject::connect( QEMU_Process, SIGNAL(readyReadStandardError()),
					  this, SLOT(Parse_StdErr()) );
	
	QObject::connect( QEMU_Process, SIGNAL(readyReadStandardOutput()),
					  this, SLOT(Parse_StdOut()) );
	
	QObject::connect( QEMU_Process, SIGNAL(started()),
					  this, SLOT(QEMU_Started()) );
	
	QObject::connect( QEMU_Process, SIGNAL(finished(int,QProcess::ExitStatus)),
					  this, SLOT(QEMU_Finished(int,QProcess::ExitStatus)) );
	
	this->Icon_Path = vm.Get_Icon_Path();
	this->Screenshot_Path = vm.Get_Screenshot_Path();
	
	// General Tab
	this->Machine_Name = vm.Get_Machine_Name();
	this->Computer_Type = vm.Get_Computer_Type();
	this->Machine_Type = vm.Get_Machine_Type();
	this->CPU_Type = vm.Get_CPU_Type();
	this->SMP_CPU_Count = vm.Get_SMP_CPU_Count();
	this->Keyboard_Layout = vm.Get_Keyboard_Layout();
	this->Boot_Device = vm.Get_Boot_Device();
	this->Video_Card = vm.Get_Video_Card();
	this->KQEMU_Mode = vm.Get_KQEMU_Mode();
	
	this->Audio_Card = vm.Get_Audio_Cards();
	
	this->Memory_Size = vm.Get_Memory_Size();
	this->Check_Free_RAM = vm.Get_Check_Free_RAM();
	
	this->Fullscreen = vm.Use_Fullscreen_Mode();
	this->Win2K_Hack = vm.Use_Win2K_Hack();
	this->Local_Time = vm.Use_Local_Time();
	this->Check_FDD_Boot_Sector = vm.Use_Check_FDD_Boot_Sector();
	this->ACPI = vm.Use_ACPI();
	this->Snapshot_Mode = vm.Use_Snapshot_Mode();
	this->Start_CPU = vm.Use_Start_CPU();
	this->QEMU_Log = vm.Use_QEMU_Log();
	this->No_Reboot = vm.Use_No_Reboot();
	
	// FDD/CD/DVD Tab
	this->FD0 = VM_Floppy( vm.Get_FD0() );
	this->FD1 = VM_Floppy( vm.Get_FD1() );
	this->CD_ROM = VM_CDROM( vm.Get_CD_ROM() );
	
	// HDD Tab
	this->HDA = VM_HDD( vm.Get_HDA() );
	this->HDB = VM_HDD( vm.Get_HDB() );
	this->HDC = VM_HDD( vm.Get_HDC() );
	this->HDD = VM_HDD( vm.Get_HDD() );
	
	// Snapshots
	this->Set_Snapshots( vm.Get_Snapshots() );
	
	// Storage Devices
	this->Set_Storage_Devices_List( vm.Get_Storage_Devices_List() );
	
	// Network Tab
	this->Use_Network = vm.Get_Use_Network();
	this->Use_Redirections = vm.Get_Use_Redirections();
	
	this->Network_Cards.clear();
	for( int nx = 0; nx < vm.Get_Network_Cards_Count(); nx++ )
	{
		VM_Net_Card n_card = vm.Get_Network_Card( nx );
		
		this->Network_Cards.append( VM_Net_Card(n_card) );
	}
	
	this->Network_Redirections.clear();
	for( int rx = 0; rx < vm.Get_Network_Redirections_Count(); rx++ )
	{
		VM_Redirection n_redir = vm.Get_Network_Redirection( rx );
		
		this->Network_Redirections.append( VM_Redirection(n_redir) );
	}
	
	this->SMB_Directory = vm.Get_SMB_Directory();
	this->TFTP_Prefix = vm.Get_TFTP_Prefix();
	
	// Ports Tab
	this->Serial_Port = VM_Port( vm.Get_Serial_Port() );
	this->Parallel_Port = VM_Port( vm.Get_Parallel_Port() );
	
	// USB
	this->USB_Hub = vm.Use_USB_Hub();
	this->USB_Ports.clear();
	for( int ux = 0; ux < vm.Get_USB_Ports_Count(); ++ux )
	{
		this->USB_Ports.append( VM_USB(vm.Get_USB_Port(ux)) );
	}
	
	// Other Tab
	this->Linux_Boot = vm.Get_Use_Linux_Boot();
	this->bzImage_Path = vm.Get_bzImage_Path();
	this->Initrd_Path = vm.Get_Initrd_Path();
	this->Kernel_ComLine = vm.Get_Kernel_ComLine();
	
	this->Additional_Args = vm.Get_Additional_Args();
	this->Use_ROM_File = vm.Get_Use_ROM_File();
	this->ROM_File = vm.Get_ROM_File();
	this->GDB = vm.Use_GDB();
	this->GDB_Port = vm.Get_GDB_Port();
	
	this->MTDBlock = vm.Use_MTDBlock_File();
	this->MTDBlock_File = vm.Get_MTDBlock_File();
	
	this->SecureDigital = vm.Use_SecureDigital_File();
	this->SecureDigital_File = vm.Get_SecureDigital_File();
	
	this->PFlash = vm.Use_PFlash_File();
	this->PFlash_File = vm.Get_PFlash_File();
	
	this->KVM_IRQChip = vm.Use_KVM_IRQChip();
	this->No_KVM_Pit = vm.Use_No_KVM_Pit();
	this->KVM_Shadow_Memory = vm.Use_KVM_Shadow_Memory();
	this->KVM_Shadow_Memory_Size = vm.Get_KVM_Shadow_Memory_Size();
	
	this->Init_Graphic_Mode = vm.Get_Init_Graphic_Mode();
	
	this->No_Frame = vm.Use_No_Frame();
	this->Alt_Grab = vm.Use_Alt_Grab();
	this->No_Quit = vm.Use_No_Quit();
	this->Portrait = vm.Use_Portrait();
	
	this->Start_Date = vm.Use_Start_Date();
	this->Start_DateTime = vm.Get_Start_Date();
	
	this->VNC = vm.Use_VNC();
	this->VNC_Socket_Mode = vm.Get_VNC_Socket_Mode();
	this->VNC_Unix_Socket_Path = vm.Get_VNC_Unix_Socket_Path();
	this->VNC_Display_Number = vm.Get_VNC_Display_Number();
	this->VNC_Password = vm.Use_VNC_Password();
	this->VNC_TLS = vm.Use_VNC_TLS();
	this->VNC_x509 = vm.Use_VNC_x509();
	this->VNC_x509_Folder_Path = vm.Get_VNC_x509_Folder_Path();
	this->VNC_x509verify = vm.Use_VNC_x509verify();
	this->VNC_x509verify_Folder_Path = vm.Get_VNC_x509verify_Folder_Path();
	
	this->Load_VM_Window = new QWidget();
	this->Save_VM_Window = new QWidget();
	this->QEMU_Error_Win = new Error_Log_Window();
	this->Load_Mode = false;
	
	AQDebug( "Virtual_Machine::Virtual_Machine( const Virtual_Machine &vm )", "End" );
}

Virtual_Machine::~Virtual_Machine()
{
	if( QEMU_Process != NULL ) delete QEMU_Process;
	if( Emu_Ctl != NULL ) delete Emu_Ctl;
	
	Snapshots.clear();
	Storage_Devices.clear();
	Network_Cards.clear();
	Network_Redirections.clear();
	USB_Ports.clear();
	
	if( Load_VM_Window != NULL ) delete Load_VM_Window;
	if( Save_VM_Window != NULL ) delete Save_VM_Window;
	if( QEMU_Error_Win != NULL ) delete QEMU_Error_Win;
}

void Virtual_Machine::Shared_Constructor()
{
	QEMU_Process = new QProcess();
	this->State = VM::VMS_Power_Off;
	Emu_Ctl = new Emulator_Control_Window();
	VM_Dom_Document = QDomDocument();
	VM_XML_File_Path = "";
	
	QObject::connect( Emu_Ctl, SIGNAL(Ready_Read_Command(QString)),
					  this, SLOT(Execute_Emu_Ctl_Command(QString)) );
	
	QObject::connect( QEMU_Process, SIGNAL(readyReadStandardError()),
					  this, SLOT(Parse_StdErr()) );
	
	QObject::connect( QEMU_Process, SIGNAL(readyReadStandardOutput()),
					  this, SLOT(Parse_StdOut()) );
	
	QObject::connect( QEMU_Process, SIGNAL(started()),
					  this, SLOT(QEMU_Started()) );
	
	QObject::connect( QEMU_Process, SIGNAL(finished(int, QProcess::ExitStatus)),
					  this, SLOT(QEMU_Finished(int, QProcess::ExitStatus)) );
	
	Icon_Path = ":/images/other.png";
	Screenshot_Path = "";
	
	Machine_Name = "NO_NAME";
	Computer_Type = "";
	Machine_Type = "";
	CPU_Type = "";
	SMP_CPU_Count = 1;
	Keyboard_Layout = "Default";
	Boot_Device = VM::Boot_From_FDD;
	Video_Card = "";
	KQEMU_Mode = VM::KQEMU_Default;
	Audio_Card = VM::Sound_Cards();
	Check_Free_RAM = false;
	Memory_Size = 128;
	
	Fullscreen = false;
	Win2K_Hack = false;
	Local_Time = true;
	Check_FDD_Boot_Sector = true;
	ACPI = true;
	Snapshot_Mode = false;
	Start_CPU = true;
	QEMU_Log = false;
	No_Reboot = false;
	
	FD0 = VM_Floppy();
	FD1 = VM_Floppy();
	CD_ROM = VM_CDROM();
	HDA = VM_HDD();
	HDB = VM_HDD();
	HDC = VM_HDD();
	HDD = VM_HDD();
	
	Use_Network = true;
	Use_Redirections = false;
	TFTP_Prefix = "";
	SMB_Directory = "";
	
	Serial_Port = VM_Port();
	Parallel_Port = VM_Port();
	USB_Hub = true;
	
	Linux_Boot = false;
	bzImage_Path = "";
	Initrd_Path = "";
	Kernel_ComLine = "";
	
	Additional_Args = "";
	Use_ROM_File = false;
	ROM_File = "";
	GDB = false;
	GDB_Port = 1024;
	
	MTDBlock = false;
	MTDBlock_File = "";
	
	SecureDigital = false;
	SecureDigital_File = "";
	
	PFlash = false;
	PFlash_File = "";
	
	KVM_IRQChip = false;
	No_KVM_Pit = false;
	KVM_Shadow_Memory = false;
	KVM_Shadow_Memory_Size = 0;
	
	Init_Graphic_Mode = VM_Init_Graphic_Mode();
	
	No_Frame = false;
	Alt_Grab = false;
	No_Quit = false;
	Portrait = false;
	
	Start_Date = false;
	Start_DateTime = QDateTime::fromString( "31.12.2008 23:59:00", "dd.MM.yyyy HH:mm:ss" );
	
	VNC = false;
	VNC_Socket_Mode = false;
	VNC_Unix_Socket_Path = "";
	VNC_Display_Number = 1;
	VNC_Password = false;
	VNC_TLS = false;
	VNC_x509 = "";
	VNC_x509_Folder_Path = "";
	VNC_x509verify = false;
	VNC_x509verify_Folder_Path = "";
	
	Embedded_Display_Port = -1;
	
	Template_Opts = Create_Template_Window::Template_Save_Default;
	
	Load_VM_Window = new QWidget();
	Save_VM_Window = new QWidget();
	QEMU_Error_Win = new Error_Log_Window();
	Load_Mode = false;
}

bool Virtual_Machine::operator==( const Virtual_Machine &vm ) const
{
	AQDebug( "bool Virtual_Machine::operator==( const Virtual_Machine &vm ) const", "Begin" );
	
	if( this->Icon_Path == vm.Get_Icon_Path() &&
		this->Computer_Type == vm.Get_Computer_Type() &&
		this->Machine_Name == vm.Get_Machine_Name() &&
		this->Machine_Type == vm.Get_Machine_Type() &&
		this->CPU_Type == vm.Get_CPU_Type() &&
		this->SMP_CPU_Count == vm.Get_SMP_CPU_Count() &&
		this->Keyboard_Layout == vm.Get_Keyboard_Layout() &&
		this->Boot_Device == vm.Get_Boot_Device() &&
		this->Video_Card == vm.Get_Video_Card() &&
		this->KQEMU_Mode == vm.Get_KQEMU_Mode() &&
		this->Audio_Card == vm.Get_Audio_Cards() &&
		this->Memory_Size == vm.Get_Memory_Size() &&
		this->Check_Free_RAM == vm.Get_Check_Free_RAM() &&
		this->Fullscreen == vm.Use_Fullscreen_Mode() &&
		this->Win2K_Hack == vm.Use_Win2K_Hack() &&
		this->Local_Time == vm.Use_Local_Time() &&
		this->Check_FDD_Boot_Sector == vm.Use_Check_FDD_Boot_Sector() &&
		this->ACPI == vm.Use_ACPI() &&
		this->Snapshot_Mode == vm.Use_Snapshot_Mode() &&
		this->Start_CPU == vm.Use_Start_CPU() &&
		this->QEMU_Log == vm.Use_QEMU_Log() &&
		this->No_Reboot == vm.Use_No_Reboot() &&
		this->FD0 == vm.Get_FD0() &&
		this->FD1 == vm.Get_FD1() &&
		this->CD_ROM == vm.Get_CD_ROM() &&
		this->HDA == vm.Get_HDA() &&
		this->HDB == vm.Get_HDB() &&
		this->HDC == vm.Get_HDC() &&
		this->HDD == vm.Get_HDD() &&
		this->Use_Network == vm.Get_Use_Network() &&
		this->Use_Redirections == vm.Get_Use_Redirections() &&
		this->Get_Network_Cards_Count() == vm.Get_Network_Cards_Count() &&
		this->Get_Network_Redirections_Count() == vm.Get_Network_Redirections_Count() &&
		this->TFTP_Prefix == vm.Get_TFTP_Prefix() &&
		this->SMB_Directory == vm.Get_SMB_Directory() &&
		this->Serial_Port == vm.Get_Serial_Port() &&
		this->Parallel_Port == vm.Get_Parallel_Port() &&
		this->USB_Hub == vm.Use_USB_Hub() &&
		this->Linux_Boot == vm.Get_Use_Linux_Boot() &&
		this->bzImage_Path == vm.Get_bzImage_Path() &&
		this->Initrd_Path == vm.Get_Initrd_Path() &&
		this->Kernel_ComLine == vm.Get_Kernel_ComLine() &&
		this->Additional_Args == vm.Get_Additional_Args() &&
		this->Use_ROM_File == vm.Get_Use_ROM_File() &&
		this->ROM_File == vm.Get_ROM_File() &&
		this->GDB == vm.Use_GDB() &&
		this->GDB_Port == vm.Get_GDB_Port() &&
		this->MTDBlock == vm.Use_MTDBlock_File() &&
		this->MTDBlock_File == vm.Get_MTDBlock_File() &&
		this->SecureDigital == vm.Use_SecureDigital_File() &&
		this->SecureDigital_File == vm.Get_SecureDigital_File() &&
		this->PFlash == vm.Use_PFlash_File() &&
		this->PFlash_File == vm.Get_PFlash_File() &&
		this->KVM_IRQChip == vm.Use_KVM_IRQChip() &&
		this->No_KVM_Pit == vm.Use_No_KVM_Pit() &&
		this->KVM_Shadow_Memory == vm.Use_KVM_Shadow_Memory() &&
		this->KVM_Shadow_Memory_Size == vm.Get_KVM_Shadow_Memory_Size() &&
		this->Init_Graphic_Mode == vm.Get_Init_Graphic_Mode() &&
		this->No_Frame == vm.Use_No_Frame() &&
		this->Alt_Grab == vm.Use_Alt_Grab() &&
		this->No_Quit == vm.Use_No_Quit() &&
		this->Portrait  == vm.Use_Portrait() &&
		this->Start_Date == vm.Use_Start_Date() &&
		this->Start_DateTime == vm.Get_Start_Date() &&
		this->VNC == vm.Use_VNC() &&
		this->VNC_Socket_Mode == vm.Get_VNC_Socket_Mode() &&
		this->VNC_Unix_Socket_Path == vm.Get_VNC_Unix_Socket_Path() &&
		this->VNC_Display_Number == vm.Get_VNC_Display_Number() &&
		this->VNC_Password == vm.Use_VNC_Password() &&
		this->VNC_TLS == vm.Use_VNC_TLS() &&
		this->VNC_x509 == vm.Use_VNC_x509() &&
		this->VNC_x509_Folder_Path == vm.Get_VNC_x509_Folder_Path() &&
		this->VNC_x509verify == vm.Use_VNC_x509verify() &&
		this->VNC_x509verify_Folder_Path == vm.Get_VNC_x509verify_Folder_Path() )
	{
		// Snapsgots
		/*if( Snapshots.count() == vm.Get_Snapshots().count() )
		{
			for( int sx = 0; sx < Snapshots.count(); ++sx )
			{
				if( Snapshots[sx] != vm.Get_Snapshots()[sx] )
				{
					return false;
				}
			}
		}
		else return false;*/
		
		// Storage Devices
		if( Storage_Devices.count() == vm.Get_Storage_Devices_List().count() )
		{
			for( int sx = 0; sx < Storage_Devices.count(); ++sx )
			{
				if( Storage_Devices[sx] != vm.Get_Storage_Devices_List()[sx] )
				{
					return false;
				}
			}
		}
		else return false;
		
		// Network Cards
		if( Get_Network_Cards_Count() == vm.Get_Network_Cards_Count() )
		{
			for( int nx = 0; nx < Get_Network_Cards_Count(); ++nx )
			{
				if( Network_Cards[nx] != vm.Get_Network_Card(nx) )
				{
					return false;
				}
			}
		}
		else return false;
		
		// Network Redirections
		if( Get_Network_Redirections_Count() == vm.Get_Network_Redirections_Count() )
		{
			for( int rx = 0; rx < Get_Network_Redirections_Count(); ++rx )
			{
				if( Network_Redirections[rx] != vm.Get_Network_Redirection(rx) )
				{
					return false;
				}
			}
		}
		else return false;
		
		// USB
		if( USB_Ports.count() == vm.Get_USB_Ports_Count() )
		{
			for( int ux = 0; ux < USB_Ports.count(); ++ux )
			{
				if( USB_Ports[ux] != vm.Get_USB_Port(ux) )
				{
					return false;
				}
			}
		}
		else return false;
		
		AQDebug( "bool Virtual_Machine::operator==( const Virtual_Machine &vm ) const", "End" );
		return true;
	}
	else
	{
		AQDebug( "bool Virtual_Machine::operator==( const Virtual_Machine &vm ) const", "End" );
		return false;
	}
}

bool Virtual_Machine::operator!=( const Virtual_Machine &v1 ) const
{
	return ! ( operator==(v1) );
}

Virtual_Machine &Virtual_Machine::operator=( const Virtual_Machine &vm )
{
	AQDebug( "Virtual_Machine &Virtual_Machine::operator=( const Virtual_Machine &vm )", "Begin" );
	
	this->QEMU_Process = new QProcess();
	this->Emu_Ctl = new Emulator_Control_Window();
	this->VM_Dom_Document = QDomDocument();
	this->VM_XML_File_Path = vm.Get_VM_XML_File_Path();
	this->State = vm.Get_State();
	
	QObject::connect( Emu_Ctl, SIGNAL(Ready_Read_Command(QString)),
					  this, SLOT(Execute_Emu_Ctl_Command(QString)) );
	
	QObject::connect( QEMU_Process, SIGNAL(readyReadStandardError()),
					  this, SLOT(Parse_StdErr()) );
	
	QObject::connect( QEMU_Process, SIGNAL(readyReadStandardOutput()),
					  this, SLOT(Parse_StdOut()) );
	
	QObject::connect( QEMU_Process, SIGNAL(started()),
					  this, SLOT(QEMU_Started()) );
	
	QObject::connect( QEMU_Process, SIGNAL(finished(int,QProcess::ExitStatus)),
					  this, SLOT(QEMU_Finished(int,QProcess::ExitStatus)) );
	
	this->Icon_Path = vm.Get_Icon_Path();
	this->Screenshot_Path = vm.Get_Screenshot_Path();
	
	// General Tab
	this->Machine_Name = vm.Get_Machine_Name();
	this->Computer_Type = vm.Get_Computer_Type();
	this->Machine_Type = vm.Get_Machine_Type();
	this->CPU_Type = vm.Get_CPU_Type();
	this->SMP_CPU_Count = vm.Get_SMP_CPU_Count();
	this->Keyboard_Layout = vm.Get_Keyboard_Layout();
	this->Boot_Device = vm.Get_Boot_Device();
	this->Video_Card = vm.Get_Video_Card();
	this->KQEMU_Mode = vm.Get_KQEMU_Mode();
	this->Audio_Card = vm.Get_Audio_Cards();
	this->Memory_Size = vm.Get_Memory_Size();
	this->Check_Free_RAM = vm.Get_Check_Free_RAM();
	this->Fullscreen = vm.Use_Fullscreen_Mode();
	this->Win2K_Hack = vm.Use_Win2K_Hack();
	this->Local_Time = vm.Use_Local_Time();
	this->Check_FDD_Boot_Sector = vm.Use_Check_FDD_Boot_Sector();
	this->ACPI = vm.Use_ACPI();
	this->Snapshot_Mode = vm.Use_Snapshot_Mode();
	this->Start_CPU = vm.Use_Start_CPU();
	this->QEMU_Log = vm.Use_QEMU_Log();
	this->No_Reboot = vm.Use_No_Reboot();
	
	// FDD/CD/DVD Tab
	this->FD0 = VM_Floppy( vm.Get_FD0() );
	this->FD1 = VM_Floppy( vm.Get_FD1() );
	this->CD_ROM = VM_CDROM( vm.Get_CD_ROM() );
	
	// HDD Tab
	this->HDA = VM_HDD( vm.Get_HDA() );
	this->HDB = VM_HDD( vm.Get_HDB() );
	this->HDC = VM_HDD( vm.Get_HDC() );
	this->HDD = VM_HDD( vm.Get_HDD() );
	
	// Snapshots
	this->Set_Snapshots( vm.Get_Snapshots() );
	
	// Storage Devices
	this->Set_Storage_Devices_List( vm.Get_Storage_Devices_List() );
	
	// Network Tab
	this->Use_Network = vm.Get_Use_Network();
	this->Use_Redirections = vm.Get_Use_Redirections();
	
	this->Network_Cards.clear();
	for( int nx = 0; nx < vm.Get_Network_Cards_Count(); nx++ )
	{
		VM_Net_Card n_card = vm.Get_Network_Card( nx );
		
		this->Network_Cards.append( VM_Net_Card(n_card) );
	}
	
	this->Network_Redirections.clear();
	for( int rx = 0; rx < vm.Get_Network_Redirections_Count(); rx++ )
	{
		VM_Redirection n_redir = vm.Get_Network_Redirection( rx );
		
		this->Network_Redirections.append( VM_Redirection(n_redir) );
	}
	
	this->SMB_Directory = vm.Get_SMB_Directory();
	this->TFTP_Prefix = vm.Get_TFTP_Prefix();
	
	// Port tab
	this->Serial_Port = VM_Port( vm.Get_Serial_Port() );
	this->Parallel_Port = VM_Port( vm.Get_Parallel_Port() );
	
	this->USB_Hub = vm.Use_USB_Hub();
	this->USB_Ports.clear();
	for( int ux = 0; ux < vm.Get_USB_Ports_Count(); ++ux )
	{
		this->USB_Ports.append( VM_USB(vm.Get_USB_Port(ux)) );
	}
	
	// Other Tab
	this->Linux_Boot = vm.Get_Use_Linux_Boot();
	this->bzImage_Path = vm.Get_bzImage_Path();
	this->Initrd_Path = vm.Get_Initrd_Path();
	this->Kernel_ComLine = vm.Get_Kernel_ComLine();
	
	this->Additional_Args = vm.Get_Additional_Args();
	this->Use_ROM_File = vm.Get_Use_ROM_File();
	this->ROM_File = vm.Get_ROM_File();
	this->GDB = vm.Use_GDB();
	this->GDB_Port = vm.Get_GDB_Port();
	
	this->MTDBlock = vm.Use_MTDBlock_File();
	this->MTDBlock_File = vm.Get_MTDBlock_File();
	
	this->SecureDigital = vm.Use_SecureDigital_File();
	this->SecureDigital_File = vm.Get_SecureDigital_File();
	
	this->PFlash = vm.Use_PFlash_File();
	this->PFlash_File = vm.Get_PFlash_File();
	
	this->KVM_IRQChip = vm.Use_KVM_IRQChip();
	this->No_KVM_Pit = vm.Use_No_KVM_Pit();
	this->KVM_Shadow_Memory = vm.Use_KVM_Shadow_Memory();
	this->KVM_Shadow_Memory_Size = vm.Get_KVM_Shadow_Memory_Size();
	
	this->Init_Graphic_Mode = vm.Get_Init_Graphic_Mode();
	
	this->No_Frame = vm.Use_No_Frame();
	this->Alt_Grab = vm.Use_Alt_Grab();
	this->No_Quit = vm.Use_No_Quit();
	this->Portrait = vm.Use_Portrait();
	
	this->Start_Date = vm.Use_Start_Date();
	this->Start_DateTime = vm.Get_Start_Date();
	
	this->VNC = vm.Use_VNC();
	this->VNC_Socket_Mode = vm.Get_VNC_Socket_Mode();
	this->VNC_Unix_Socket_Path = vm.Get_VNC_Unix_Socket_Path();
	this->VNC_Display_Number = vm.Get_VNC_Display_Number();
	this->VNC_Password = vm.Use_VNC_Password();
	this->VNC_TLS = vm.Use_VNC_TLS();
	this->VNC_x509 = vm.Use_VNC_x509();
	this->VNC_x509_Folder_Path = vm.Get_VNC_x509_Folder_Path();
	this->VNC_x509verify = vm.Use_VNC_x509verify();
	this->VNC_x509verify_Folder_Path = vm.Get_VNC_x509verify_Folder_Path();
	
	this->Load_VM_Window = new QWidget();
	this->Save_VM_Window = new QWidget();
	this->Load_Mode = false;
	
	AQDebug( "Virtual_Machine &Virtual_Machine::operator=( const Virtual_Machine &vm )",
			 "End" );
	
	return *this;
}

const QString &Virtual_Machine::Get_VM_XML_File_Path() const
{
	return VM_XML_File_Path;
}

void Virtual_Machine::Set_VM_XML_File_Path( const QString &path )
{
	VM_XML_File_Path = path;
}

bool Virtual_Machine::Create_VM_File( const QString &file_name, bool template_mode )
{
	VM_XML_File_Path = file_name;
	
	if( file_name.isEmpty() )
	{
		AQError( "bool Virtual_Machine::Create_VM_File( const QString &file_name, bool template_mode )",
				 "File Name is Empty!" );
		return false;
	}
	
	QDomDocument New_Dom_Document( "AQEMU" );
	
	QDomProcessingInstruction Pro_Instr =
			New_Dom_Document.createProcessingInstruction( "xml", "version=\"1.0\" encoding=\"UTF-8\"" );
	
	New_Dom_Document.appendChild( Pro_Instr );
	
	QDomElement Root_Element;
	
	if( template_mode )
	{
		Root_Element = New_Dom_Document.createElement( "AQEMU_Template" );
	}
	else
	{
		Root_Element = New_Dom_Document.createElement( "AQEMU" );
	}
	
	Root_Element.setAttribute( "version", "0.5" ); // This is AQEMU Version
	New_Dom_Document.appendChild( Root_Element );
	
	QDomElement VM_Element = New_Dom_Document.createElement( "Virtual_Machine" );
	Root_Element.appendChild( VM_Element );
	
	// Save New VM Data
	QDomElement Dom_Element;
	QDomText Dom_Text;
	
	if( template_mode )
	{
		// Temlate Options
		Dom_Element = New_Dom_Document.createElement( "Template_Options" );
		VM_Element.appendChild( Dom_Element );
		Dom_Text = New_Dom_Document.createTextNode( QString::number((int)Template_Opts) );
		Dom_Element.appendChild( Dom_Text );
	}
	
	// VM State
	Dom_Element = New_Dom_Document.createElement( "VM_State" );
	VM_Element.appendChild( Dom_Element );
	
	if( template_mode )
	{
		Dom_Text = New_Dom_Document.createTextNode( "Power_Off" );
	}
	else
	{
		switch( State )
		{
			case VM::VMS_Power_Off:
				Dom_Text = New_Dom_Document.createTextNode( "Power_Off" );
				break;
		
			case VM::VMS_Saved:
				Dom_Text = New_Dom_Document.createTextNode( "Saved" );
				break;
			
			default:
				Dom_Text = New_Dom_Document.createTextNode( "Power_Off" );
				break;
		}
	}
	
	Dom_Element.appendChild( Dom_Text );
	
	// Icon Path
	Dom_Element = New_Dom_Document.createElement( "Icon_Path" );
	VM_Element.appendChild( Dom_Element );
	Dom_Text = New_Dom_Document.createTextNode( Icon_Path );
	Dom_Element.appendChild( Dom_Text );
	
	// Screenshot Path
	Dom_Element = New_Dom_Document.createElement( "Screenshot_Path" );
	VM_Element.appendChild( Dom_Element );
	Dom_Text = New_Dom_Document.createTextNode( Screenshot_Path );
	Dom_Element.appendChild( Dom_Text );
	
	// Machine Name
	Dom_Element = New_Dom_Document.createElement( "Machine_Name" );
	VM_Element.appendChild( Dom_Element );
	
	if( template_mode )
	{
		Dom_Text = New_Dom_Document.createTextNode( Template_Name );
	}
	else
	{
		Dom_Text = New_Dom_Document.createTextNode( Machine_Name );
	}
	
	Dom_Element.appendChild( Dom_Text );
	
	// Computer Type
	Dom_Element = New_Dom_Document.createElement( "Computer_Type" );
	VM_Element.appendChild( Dom_Element );
	Dom_Text = New_Dom_Document.createTextNode( Computer_Type );
	Dom_Element.appendChild( Dom_Text );
	
	// Machine Type
	Dom_Element = New_Dom_Document.createElement( "Machine_Type" );
	VM_Element.appendChild( Dom_Element );
	Dom_Text = New_Dom_Document.createTextNode( Machine_Type );
	Dom_Element.appendChild( Dom_Text );
	
	// CPU Type
	Dom_Element = New_Dom_Document.createElement( "CPU_Type" );
	VM_Element.appendChild( Dom_Element );
	Dom_Text = New_Dom_Document.createTextNode( CPU_Type );
	Dom_Element.appendChild( Dom_Text );
	
	// CPU Count
	Dom_Element = New_Dom_Document.createElement( "SMP_CPU_Count" );
	VM_Element.appendChild( Dom_Element );
	Dom_Text = New_Dom_Document.createTextNode( QString::number(SMP_CPU_Count) );
	Dom_Element.appendChild( Dom_Text );
	
	// Keyboard Layout
	Dom_Element = New_Dom_Document.createElement( "Keyboard_Layout" );
	VM_Element.appendChild( Dom_Element );
	Dom_Text = New_Dom_Document.createTextNode( Keyboard_Layout );
	Dom_Element.appendChild( Dom_Text );
	
	// Boot Device
	Dom_Element = New_Dom_Document.createElement( "Boot_Device" );
	VM_Element.appendChild( Dom_Element );
	
	switch( Boot_Device )
	{
		case VM::Boot_From_FDD:
			Dom_Text = New_Dom_Document.createTextNode( "FDD" );
			break;
			
		case VM::Boot_From_CDROM:
			Dom_Text = New_Dom_Document.createTextNode( "CDROM" );
			break;
			
		case VM::Boot_From_HDD:
			Dom_Text = New_Dom_Document.createTextNode( "HDD" );
			break;
			
		case VM::Boot_From_Network:
			Dom_Text = New_Dom_Document.createTextNode( "Network" );
			break;
			
		case VM::Boot_None:
			Dom_Text = New_Dom_Document.createTextNode( "None" );
			break;
			
		default:
			AQWarning( "bool Virtual_Machine::Create_VM_File( const QString &file_name, bool template_mode )",
					   "Use Default Boot Device: CD-ROM" );
			Dom_Text = New_Dom_Document.createTextNode( "CDROM" );
			break;
	}
	
	Dom_Element.appendChild( Dom_Text );
	
	// Video_Card
	Dom_Element = New_Dom_Document.createElement( "Video_Card" );
	VM_Element.appendChild( Dom_Element );
	Dom_Text = New_Dom_Document.createTextNode( Video_Card );
	Dom_Element.appendChild( Dom_Text );
	
	// KQEMU Mode ( Acceleration )
	Dom_Element = New_Dom_Document.createElement( "KQEMU_Mode" );
	VM_Element.appendChild( Dom_Element );
	
	switch( KQEMU_Mode )
	{
		case VM::KQEMU_Disabled:
			Dom_Text = New_Dom_Document.createTextNode( "Disabled" );
			break;
			
		case VM::KQEMU_Enabled:
			Dom_Text = New_Dom_Document.createTextNode( "Enabled" );
			break;
			
		case VM::KQEMU_Full:
			Dom_Text = New_Dom_Document.createTextNode( "Full" );
			break;
			
		case VM::KQEMU_Default:
			Dom_Text = New_Dom_Document.createTextNode( "Default" );
			break;
			
		default:
			AQWarning( "bool Virtual_Machine::Create_VM_File( const QString &file_name, bool template_mode )",
					   "Use Default KQEMU Mode: Enabled" );
			Dom_Text = New_Dom_Document.createTextNode( "Enabled" );
			break;
	}
	
	Dom_Element.appendChild( Dom_Text );
	
	// Create new element
	QDomElement Sec_Element;
	
	// Audio Cards
	Dom_Element = New_Dom_Document.createElement( "Audio_Cards" );
	
	// Audio_sb16
	Sec_Element = New_Dom_Document.createElement( "Audio_sb16" );
	Dom_Element.appendChild( Sec_Element );
	
	if( Audio_Card.Audio_sb16 ) Dom_Text = New_Dom_Document.createTextNode( "true" );
	else Dom_Text = New_Dom_Document.createTextNode( "false" );
	
	Sec_Element.appendChild( Dom_Text );
	
	// Audio_es1370
	Sec_Element = New_Dom_Document.createElement( "Audio_es1370" );
	Dom_Element.appendChild( Sec_Element );
	
	if( Audio_Card.Audio_es1370 ) Dom_Text = New_Dom_Document.createTextNode( "true" );
	else Dom_Text = New_Dom_Document.createTextNode( "false" );
	
	Sec_Element.appendChild( Dom_Text );
	
	// Audio_Adlib
	Sec_Element = New_Dom_Document.createElement( "Audio_Adlib" );
	Dom_Element.appendChild( Sec_Element );
	
	if( Audio_Card.Audio_Adlib ) Dom_Text = New_Dom_Document.createTextNode( "true" );
	else Dom_Text = New_Dom_Document.createTextNode( "false" );
	
	Sec_Element.appendChild( Dom_Text );
	
	// Audio_PC_Speaker
	Sec_Element = New_Dom_Document.createElement( "Audio_PC_Speaker" );
	Dom_Element.appendChild( Sec_Element );
	
	if( Audio_Card.Audio_PC_Speaker ) Dom_Text = New_Dom_Document.createTextNode( "true" );
	else Dom_Text = New_Dom_Document.createTextNode( "false" );
	
	Sec_Element.appendChild( Dom_Text );
	
	// Audio_GUS
	Sec_Element = New_Dom_Document.createElement( "Audio_GUS" );
	Dom_Element.appendChild( Sec_Element );
	
	if( Audio_Card.Audio_GUS ) Dom_Text = New_Dom_Document.createTextNode( "true" );
	else Dom_Text = New_Dom_Document.createTextNode( "false" );
	
	Sec_Element.appendChild( Dom_Text );
	
	// Audio_AC97
	Sec_Element = New_Dom_Document.createElement( "Audio_AC97" );
	Dom_Element.appendChild( Sec_Element );
	
	if( Audio_Card.Audio_AC97 ) Dom_Text = New_Dom_Document.createTextNode( "true" );
	else Dom_Text = New_Dom_Document.createTextNode( "false" );
	
	Sec_Element.appendChild( Dom_Text );
	
	VM_Element.appendChild( Dom_Element );
	
	// Check Free RAM
	Dom_Element = New_Dom_Document.createElement( "Check_Free_RAM" );
	VM_Element.appendChild( Dom_Element );
	
	if( Check_Free_RAM )
	{
		Dom_Text = New_Dom_Document.createTextNode( "true" );
	}
	else
	{
		Dom_Text = New_Dom_Document.createTextNode( "false" );
	}
	
	Dom_Element.appendChild( Dom_Text );
	
	// Memory Size ( RAM )
	Dom_Element = New_Dom_Document.createElement( "Memory_Size" );
	VM_Element.appendChild( Dom_Element );
	Dom_Text = New_Dom_Document.createTextNode( QString::number(Memory_Size) );
	Dom_Element.appendChild( Dom_Text );
	
	// Fullscreen
	Dom_Element = New_Dom_Document.createElement( "Fullscreen" );
	VM_Element.appendChild( Dom_Element );
	
	if( Fullscreen )
	{
		Dom_Text = New_Dom_Document.createTextNode( "true" );
	}
	else
	{
		Dom_Text = New_Dom_Document.createTextNode( "false" );
	}
	
	Dom_Element.appendChild( Dom_Text );
	
	// Win2K_Hack
	Dom_Element = New_Dom_Document.createElement( "Win2K_Hack" );
	VM_Element.appendChild( Dom_Element );
	
	if( Win2K_Hack )
	{
		Dom_Text = New_Dom_Document.createTextNode( "true" );
	}
	else
	{
		Dom_Text = New_Dom_Document.createTextNode( "false" );
	}
	
	Dom_Element.appendChild( Dom_Text );
	
	// Localtime
	Dom_Element = New_Dom_Document.createElement( "Local_Time" );
	VM_Element.appendChild( Dom_Element );
	
	if( Local_Time )
	{
		Dom_Text = New_Dom_Document.createTextNode( "true" );
	}
	else
	{
		Dom_Text = New_Dom_Document.createTextNode( "false" );
	}
	
	Dom_Element.appendChild( Dom_Text );
	
	// Check FDD Boot Sector
	Dom_Element = New_Dom_Document.createElement( "Check_FDD_Boot_Sector" );
	VM_Element.appendChild( Dom_Element );
	
	if( Check_FDD_Boot_Sector )
	{
		Dom_Text = New_Dom_Document.createTextNode( "true" );
	}
	else
	{
		Dom_Text = New_Dom_Document.createTextNode( "false" );
	}
	
	Dom_Element.appendChild( Dom_Text );
	
	// ACPI
	Dom_Element = New_Dom_Document.createElement( "ACPI" );
	VM_Element.appendChild( Dom_Element );
	
	if( ACPI )
	{
		Dom_Text = New_Dom_Document.createTextNode( "true" );
	}
	else
	{
		Dom_Text = New_Dom_Document.createTextNode( "false" );
	}
	
	Dom_Element.appendChild( Dom_Text );
	
	// Snapshot_Mode
	Dom_Element = New_Dom_Document.createElement( "Snapshot_Mode" );
	VM_Element.appendChild( Dom_Element );
	
	if( Snapshot_Mode )
	{
		Dom_Text = New_Dom_Document.createTextNode( "true" );
	}
	else
	{
		Dom_Text = New_Dom_Document.createTextNode( "false" );
	}
	
	Dom_Element.appendChild( Dom_Text );
	
	// Start_CPU
	Dom_Element = New_Dom_Document.createElement( "Start_CPU" );
	VM_Element.appendChild( Dom_Element );
	
	if( Start_CPU )
	{
		Dom_Text = New_Dom_Document.createTextNode( "true" );
	}
	else
	{
		Dom_Text = New_Dom_Document.createTextNode( "false" );
	}
	
	Dom_Element.appendChild( Dom_Text );
	
	// QEMU_Log
	Dom_Element = New_Dom_Document.createElement( "QEMU_Log" );
	VM_Element.appendChild( Dom_Element );
	
	if( QEMU_Log )
	{
		Dom_Text = New_Dom_Document.createTextNode( "true" );
	}
	else
	{
		Dom_Text = New_Dom_Document.createTextNode( "false" );
	}
	
	Dom_Element.appendChild( Dom_Text );
	
	// No_Reboot
	Dom_Element = New_Dom_Document.createElement( "No_Reboot" );
	VM_Element.appendChild( Dom_Element );
	
	if( No_Reboot )
	{
		Dom_Text = New_Dom_Document.createTextNode( "true" );
	}
	else
	{
		Dom_Text = New_Dom_Document.createTextNode( "false" );
	}
	
	Dom_Element.appendChild( Dom_Text );
	
	// Floppy's and CD-ROM
	if( template_mode &&
		! (Template_Opts & Create_Template_Window::Template_Save_FDD_CD) )
	{
		// Floppy 0
		Dom_Element = New_Dom_Document.createElement( "FD0" );
		
		// Enabled
		Sec_Element = New_Dom_Document.createElement( "Enabled" );
		Dom_Element.appendChild( Sec_Element );
		Dom_Text = New_Dom_Document.createTextNode( "false" );
		Sec_Element.appendChild( Dom_Text );
		
		// Host File Name
		Sec_Element = New_Dom_Document.createElement( "Host_File_Name" );
		Dom_Element.appendChild( Sec_Element );
		Dom_Text = New_Dom_Document.createTextNode( "" );
		Sec_Element.appendChild( Dom_Text );
		
		// Image File Name
		Sec_Element = New_Dom_Document.createElement( "Image_File_Name" );
		Dom_Element.appendChild( Sec_Element );
		Dom_Text = New_Dom_Document.createTextNode( "" );
		Sec_Element.appendChild( Dom_Text );
		
		// Host Device
		Sec_Element = New_Dom_Document.createElement( "Host_Device" );
		Dom_Element.appendChild( Sec_Element );
		Dom_Text = New_Dom_Document.createTextNode( "true" );
		Sec_Element.appendChild( Dom_Text );
		
		VM_Element.appendChild( Dom_Element );
		
		// Floppy 1
		Dom_Element = New_Dom_Document.createElement( "FD1" );
		
		// Enabled
		Sec_Element = New_Dom_Document.createElement( "Enabled" );
		Dom_Element.appendChild( Sec_Element );
		Dom_Text = New_Dom_Document.createTextNode( "false" );
		Sec_Element.appendChild( Dom_Text );
		
		// Host File Name
		Sec_Element = New_Dom_Document.createElement( "Host_File_Name" );
		Dom_Element.appendChild( Sec_Element );
		Dom_Text = New_Dom_Document.createTextNode( "" );
		Sec_Element.appendChild( Dom_Text );
		
		// Image File Name
		Sec_Element = New_Dom_Document.createElement( "Image_File_Name" );
		Dom_Element.appendChild( Sec_Element );
		Dom_Text = New_Dom_Document.createTextNode( "" );
		Sec_Element.appendChild( Dom_Text );
		
		// Host Device
		Sec_Element = New_Dom_Document.createElement( "Host_Device" );
		Dom_Element.appendChild( Sec_Element );
		Dom_Text = New_Dom_Document.createTextNode( "true" );
		Sec_Element.appendChild( Dom_Text );
		
		VM_Element.appendChild( Dom_Element );
		
		// CD-ROM
		Dom_Element = New_Dom_Document.createElement( "CD_ROM" );
		
		// Enabled
		Sec_Element = New_Dom_Document.createElement( "Enabled" );
		Dom_Element.appendChild( Sec_Element );
		Dom_Text = New_Dom_Document.createTextNode( "false" );
		Sec_Element.appendChild( Dom_Text );
		
		// Host File Name
		Sec_Element = New_Dom_Document.createElement( "Host_File_Name" );
		Dom_Element.appendChild( Sec_Element );
		Dom_Text = New_Dom_Document.createTextNode( "" );
		Sec_Element.appendChild( Dom_Text );
		
		// Image File Name
		Sec_Element = New_Dom_Document.createElement( "Image_File_Name" );
		Dom_Element.appendChild( Sec_Element );
		Dom_Text = New_Dom_Document.createTextNode( "" );
		Sec_Element.appendChild( Dom_Text );
		
		// Host Device
		Sec_Element = New_Dom_Document.createElement( "Host_Device" );
		Dom_Element.appendChild( Sec_Element );
		Dom_Text = New_Dom_Document.createTextNode( "true" );
		Sec_Element.appendChild( Dom_Text );
		
		VM_Element.appendChild( Dom_Element );
	}
	else
	{
		// Floppy 0
		Dom_Element = New_Dom_Document.createElement( "FD0" );
		
		// Enabled
		Sec_Element = New_Dom_Document.createElement( "Enabled" );
		Dom_Element.appendChild( Sec_Element );
		
		if( FD0.Get_Enabled() )
		{
			Dom_Text = New_Dom_Document.createTextNode( "true" );
		}
		else
		{
			Dom_Text = New_Dom_Document.createTextNode( "false" );
		}
		
		Sec_Element.appendChild( Dom_Text );
		
		// Host File Name
		Sec_Element = New_Dom_Document.createElement( "Host_File_Name" );
		Dom_Element.appendChild( Sec_Element );
		Dom_Text = New_Dom_Document.createTextNode( FD0.Get_Host_File_Name() );
		Sec_Element.appendChild( Dom_Text );
		
		// Image File Name
		Sec_Element = New_Dom_Document.createElement( "Image_File_Name" );
		Dom_Element.appendChild( Sec_Element );
		Dom_Text = New_Dom_Document.createTextNode( FD0.Get_Image_File_Name() );
		Sec_Element.appendChild( Dom_Text );
		
		// Host Device
		Sec_Element = New_Dom_Document.createElement( "Host_Device" );
		Dom_Element.appendChild( Sec_Element );
		
		if( FD0.Get_Host_Device() )
		{
			Dom_Text = New_Dom_Document.createTextNode( "true" );
		}
		else
		{
			Dom_Text = New_Dom_Document.createTextNode( "false" );
		}
		
		Sec_Element.appendChild( Dom_Text );
		
		VM_Element.appendChild( Dom_Element );
		
		// Floppy 1
		Dom_Element = New_Dom_Document.createElement( "FD1" );
		
		// Enabled
		Sec_Element = New_Dom_Document.createElement( "Enabled" );
		Dom_Element.appendChild( Sec_Element );
		
		if( FD1.Get_Enabled() )
		{
			Dom_Text = New_Dom_Document.createTextNode( "true" );
		}
		else
		{
			Dom_Text = New_Dom_Document.createTextNode( "false" );
		}
		
		Sec_Element.appendChild( Dom_Text );
		
		// Host File Name
		Sec_Element = New_Dom_Document.createElement( "Host_File_Name" );
		Dom_Element.appendChild( Sec_Element );
		Dom_Text = New_Dom_Document.createTextNode( FD1.Get_Host_File_Name() );
		Sec_Element.appendChild( Dom_Text );
		
		// Image File Name
		Sec_Element = New_Dom_Document.createElement( "Image_File_Name" );
		Dom_Element.appendChild( Sec_Element );
		Dom_Text = New_Dom_Document.createTextNode( FD1.Get_Image_File_Name() );
		Sec_Element.appendChild( Dom_Text );
		
		// Host Device
		Sec_Element = New_Dom_Document.createElement( "Host_Device" );
		Dom_Element.appendChild( Sec_Element );
		
		if( FD1.Get_Host_Device() )
		{
			Dom_Text = New_Dom_Document.createTextNode( "true" );
		}
		else
		{
			Dom_Text = New_Dom_Document.createTextNode( "false" );
		}
		
		Sec_Element.appendChild( Dom_Text );
		
		VM_Element.appendChild( Dom_Element );
		
		// CD-ROM
		Dom_Element = New_Dom_Document.createElement( "CD_ROM" );
		
		// Enabled
		Sec_Element = New_Dom_Document.createElement( "Enabled" );
		Dom_Element.appendChild( Sec_Element );
		
		if( CD_ROM.Get_Enabled() )
		{
			Dom_Text = New_Dom_Document.createTextNode( "true" );
		}
		else
		{
			Dom_Text = New_Dom_Document.createTextNode( "false" );
		}
		
		Sec_Element.appendChild( Dom_Text );
		
		// Host File Name
		Sec_Element = New_Dom_Document.createElement( "Host_File_Name" );
		Dom_Element.appendChild( Sec_Element );
		Dom_Text = New_Dom_Document.createTextNode( CD_ROM.Get_Host_File_Name() );
		Sec_Element.appendChild( Dom_Text );
		
		// Image File Name
		Sec_Element = New_Dom_Document.createElement( "Image_File_Name" );
		Dom_Element.appendChild( Sec_Element );
		Dom_Text = New_Dom_Document.createTextNode( CD_ROM.Get_Image_File_Name() );
		Sec_Element.appendChild( Dom_Text );
		
		// Host Device
		Sec_Element = New_Dom_Document.createElement( "Host_Device" );
		Dom_Element.appendChild( Sec_Element );
		
		if( CD_ROM.Get_Host_Device() )
		{
			Dom_Text = New_Dom_Document.createTextNode( "true" );
		}
		else
		{
			Dom_Text = New_Dom_Document.createTextNode( "false" );
		}
		
		Sec_Element.appendChild( Dom_Text );
		
		VM_Element.appendChild( Dom_Element );
	}
	
	if( template_mode )
	{
		if( Template_Opts & Create_Template_Window::Template_Save_HDD )
		{
			// HDA
			Dom_Element = New_Dom_Document.createElement( "HDA" );
			
			// Enabled
			Sec_Element = New_Dom_Document.createElement( "Enabled" );
			Dom_Element.appendChild( Sec_Element );
		
			if( HDA.Get_Enabled() )
			{
				Dom_Text = New_Dom_Document.createTextNode( "true" );
			}
			else
			{
				Dom_Text = New_Dom_Document.createTextNode( "false" );
			}
			
			Sec_Element.appendChild( Dom_Text );
			
			if( HDA.Get_Enabled() )
			{
				// Size
				Sec_Element = New_Dom_Document.createElement( "Size" );
				Dom_Element.appendChild( Sec_Element );
				Dom_Text = New_Dom_Document.createTextNode( HDA.Get_Complete_Virtual_Size() );
				Sec_Element.appendChild( Dom_Text );
				
				// Size
				Sec_Element = New_Dom_Document.createElement( "Format" );
				Dom_Element.appendChild( Sec_Element );
				Dom_Text = New_Dom_Document.createTextNode( HDA.Get_Image_Format() );
				Sec_Element.appendChild( Dom_Text );
			}
			
			Sec_Element.appendChild( Dom_Text );
			
			VM_Element.appendChild( Dom_Element );
			
			// HDB
			Dom_Element = New_Dom_Document.createElement( "HDB" );
			
			// Enabled
			Sec_Element = New_Dom_Document.createElement( "Enabled" );
			Dom_Element.appendChild( Sec_Element );
		
			if( HDB.Get_Enabled() )
			{
				Dom_Text = New_Dom_Document.createTextNode( "true" );
			}
			else
			{
				Dom_Text = New_Dom_Document.createTextNode( "false" );
			}
			
			Sec_Element.appendChild( Dom_Text );
			
			if( HDB.Get_Enabled() )
			{
				// Size
				Sec_Element = New_Dom_Document.createElement( "Size" );
				Dom_Element.appendChild( Sec_Element );
				Dom_Text = New_Dom_Document.createTextNode( HDB.Get_Complete_Virtual_Size() );
				Sec_Element.appendChild( Dom_Text );
			
				// Size
				Sec_Element = New_Dom_Document.createElement( "Format" );
				Dom_Element.appendChild( Sec_Element );
				Dom_Text = New_Dom_Document.createTextNode( HDB.Get_Image_Format() );
				Sec_Element.appendChild( Dom_Text );
			}
			
			Sec_Element.appendChild( Dom_Text );
			
			VM_Element.appendChild( Dom_Element );
			
			// HDC
			Dom_Element = New_Dom_Document.createElement( "HDC" );
			
			// Enabled
			Sec_Element = New_Dom_Document.createElement( "Enabled" );
			Dom_Element.appendChild( Sec_Element );
		
			if( HDC.Get_Enabled() )
			{
				Dom_Text = New_Dom_Document.createTextNode( "true" );
			}
			else
			{
				Dom_Text = New_Dom_Document.createTextNode( "false" );
			}
			
			Sec_Element.appendChild( Dom_Text );
			
			if( HDC.Get_Enabled() )
			{
				// Size
				Sec_Element = New_Dom_Document.createElement( "Size" );
				Dom_Element.appendChild( Sec_Element );
				Dom_Text = New_Dom_Document.createTextNode( HDC.Get_Complete_Virtual_Size() );
				Sec_Element.appendChild( Dom_Text );
			
				// Size
				Sec_Element = New_Dom_Document.createElement( "Format" );
				Dom_Element.appendChild( Sec_Element );
				Dom_Text = New_Dom_Document.createTextNode( HDC.Get_Image_Format() );
				Sec_Element.appendChild( Dom_Text );
			}
			
			Sec_Element.appendChild( Dom_Text );
			
			VM_Element.appendChild( Dom_Element );
			
			// HDD
			Dom_Element = New_Dom_Document.createElement( "HDD" );
			
			// Enabled
			Sec_Element = New_Dom_Document.createElement( "Enabled" );
			Dom_Element.appendChild( Sec_Element );
		
			if( HDD.Get_Enabled() )
			{
				Dom_Text = New_Dom_Document.createTextNode( "true" );
			}
			else
			{
				Dom_Text = New_Dom_Document.createTextNode( "false" );
			}
			
			Sec_Element.appendChild( Dom_Text );
			
			if( HDD.Get_Enabled() )
			{
				// Size
				Sec_Element = New_Dom_Document.createElement( "Size" );
				Dom_Element.appendChild( Sec_Element );
				Dom_Text = New_Dom_Document.createTextNode( HDD.Get_Complete_Virtual_Size() );
				Sec_Element.appendChild( Dom_Text );
				
				// Size
				Sec_Element = New_Dom_Document.createElement( "Format" );
				Dom_Element.appendChild( Sec_Element );
				Dom_Text = New_Dom_Document.createTextNode( HDD.Get_Image_Format() );
				Sec_Element.appendChild( Dom_Text );
			}
			
			Sec_Element.appendChild( Dom_Text );
			
			VM_Element.appendChild( Dom_Element );
		}
		else
		{
			// HDA
			Dom_Element = New_Dom_Document.createElement( "HDA" );
			
			// Enabled
			Sec_Element = New_Dom_Document.createElement( "Enabled" );
			Dom_Element.appendChild( Sec_Element );
			Dom_Text = New_Dom_Document.createTextNode( "false" );
			Sec_Element.appendChild( Dom_Text );
			
			// Image File Name
			Sec_Element = New_Dom_Document.createElement( "Image_File_Name" );
			Dom_Element.appendChild( Sec_Element );
			Dom_Text = New_Dom_Document.createTextNode( "" );
			Sec_Element.appendChild( Dom_Text );
			
			VM_Element.appendChild( Dom_Element );
			
			// HDB
			Dom_Element = New_Dom_Document.createElement( "HDB" );
			
			// Enabled
			Sec_Element = New_Dom_Document.createElement( "Enabled" );
			Dom_Element.appendChild( Sec_Element );
			Dom_Text = New_Dom_Document.createTextNode( "false" );
			Sec_Element.appendChild( Dom_Text );
			
			// Image File Name
			Sec_Element = New_Dom_Document.createElement( "Image_File_Name" );
			Dom_Element.appendChild( Sec_Element );
			Dom_Text = New_Dom_Document.createTextNode( "" );
			Sec_Element.appendChild( Dom_Text );
			
			VM_Element.appendChild( Dom_Element );
			
			// HDC
			Dom_Element = New_Dom_Document.createElement( "HDC" );
			
			// Enabled
			Sec_Element = New_Dom_Document.createElement( "Enabled" );
			Dom_Element.appendChild( Sec_Element );
			Dom_Text = New_Dom_Document.createTextNode( "false" );
			Sec_Element.appendChild( Dom_Text );
			
			// Image File Name
			Sec_Element = New_Dom_Document.createElement( "Image_File_Name" );
			Dom_Element.appendChild( Sec_Element );
			Dom_Text = New_Dom_Document.createTextNode( "" );
			Sec_Element.appendChild( Dom_Text );
			
			VM_Element.appendChild( Dom_Element );
			
			// HDD
			Dom_Element = New_Dom_Document.createElement( "HDD" );
			
			// Enabled
			Sec_Element = New_Dom_Document.createElement( "Enabled" );
			Dom_Element.appendChild( Sec_Element );
			Dom_Text = New_Dom_Document.createTextNode( "false" );
			Sec_Element.appendChild( Dom_Text );
			
			// Image File Name
			Sec_Element = New_Dom_Document.createElement( "Image_File_Name" );
			Dom_Element.appendChild( Sec_Element );
			Dom_Text = New_Dom_Document.createTextNode( "" );
			Sec_Element.appendChild( Dom_Text );
			
			VM_Element.appendChild( Dom_Element );
		}
	}
	else
	{
		// HDA
		Dom_Element = New_Dom_Document.createElement( "HDA" );
		
		// Enabled
		Sec_Element = New_Dom_Document.createElement( "Enabled" );
		Dom_Element.appendChild( Sec_Element );
		
		if( HDA.Get_Enabled() )
		{
			Dom_Text = New_Dom_Document.createTextNode( "true" );
		}
		else
		{
			Dom_Text = New_Dom_Document.createTextNode( "false" );
		}
		
		Sec_Element.appendChild( Dom_Text );
		
		// Image File Name
		Sec_Element = New_Dom_Document.createElement( "Image_File_Name" );
		Dom_Element.appendChild( Sec_Element );
		Dom_Text = New_Dom_Document.createTextNode( HDA.Get_Image_File_Name() );
		Sec_Element.appendChild( Dom_Text );
		
		VM_Element.appendChild( Dom_Element );
		
		// HDB
		Dom_Element = New_Dom_Document.createElement( "HDB" );
		
		// Enabled
		Sec_Element = New_Dom_Document.createElement( "Enabled" );
		Dom_Element.appendChild( Sec_Element );
		
		if( HDB.Get_Enabled() )
		{
			Dom_Text = New_Dom_Document.createTextNode( "true" );
		}
		else
		{
			Dom_Text = New_Dom_Document.createTextNode( "false" );
		}
		
		Sec_Element.appendChild( Dom_Text );
		
		// Image File Name
		Sec_Element = New_Dom_Document.createElement( "Image_File_Name" );
		Dom_Element.appendChild( Sec_Element );
		Dom_Text = New_Dom_Document.createTextNode( HDB.Get_Image_File_Name() );
		Sec_Element.appendChild( Dom_Text );
		
		VM_Element.appendChild( Dom_Element );
		
		// HDC
		Dom_Element = New_Dom_Document.createElement( "HDC" );
		
		// Enabled
		Sec_Element = New_Dom_Document.createElement( "Enabled" );
		Dom_Element.appendChild( Sec_Element );
		
		if( HDC.Get_Enabled() )
		{
			Dom_Text = New_Dom_Document.createTextNode( "true" );
		}
		else
		{
			Dom_Text = New_Dom_Document.createTextNode( "false" );
		}
		
		Sec_Element.appendChild( Dom_Text );
		
		// Image File Name
		Sec_Element = New_Dom_Document.createElement( "Image_File_Name" );
		Dom_Element.appendChild( Sec_Element );
		Dom_Text = New_Dom_Document.createTextNode( HDC.Get_Image_File_Name() );
		Sec_Element.appendChild( Dom_Text );
		
		VM_Element.appendChild( Dom_Element );
		
		// HDD
		Dom_Element = New_Dom_Document.createElement( "HDD" );
		
		// Enabled
		Sec_Element = New_Dom_Document.createElement( "Enabled" );
		Dom_Element.appendChild( Sec_Element );
		
		if( HDD.Get_Enabled() )
		{
			Dom_Text = New_Dom_Document.createTextNode( "true" );
		}
		else
		{
			Dom_Text = New_Dom_Document.createTextNode( "false" );
		}
		
		Sec_Element.appendChild( Dom_Text );
		
		// Image File Name
		Sec_Element = New_Dom_Document.createElement( "Image_File_Name" );
		Dom_Element.appendChild( Sec_Element );
		Dom_Text = New_Dom_Document.createTextNode( HDD.Get_Image_File_Name() );
		Sec_Element.appendChild( Dom_Text );
		
		VM_Element.appendChild( Dom_Element );
	}
	
	// Snapshots
	if( ! template_mode )
	{
		// Storage Device Count
		Dom_Element = New_Dom_Document.createElement( "Snapshots_Count" );
		VM_Element.appendChild( Dom_Element );
		Dom_Text = New_Dom_Document.createTextNode( QString::number(Snapshots.count()) );
		Dom_Element.appendChild( Dom_Text );
		
		for( int sx = 0; sx < Snapshots.count(); ++sx )
		{
			Dom_Element = New_Dom_Document.createElement( "Snapshot_" + QString::number(sx) );
			
			// Tag
			Sec_Element = New_Dom_Document.createElement( "Tag" );
			Dom_Element.appendChild( Sec_Element );
			Dom_Text = New_Dom_Document.createTextNode( Snapshots[sx].Get_Tag() );
			Sec_Element.appendChild( Dom_Text );
			
			// Name
			Sec_Element = New_Dom_Document.createElement( "Name" );
			Dom_Element.appendChild( Sec_Element );
			Dom_Text = New_Dom_Document.createTextNode( Snapshots[sx].Get_Name() );
			Sec_Element.appendChild( Dom_Text );
			
			// Description
			Sec_Element = New_Dom_Document.createElement( "Description" );
			Dom_Element.appendChild( Sec_Element );
			Dom_Text = New_Dom_Document.createTextNode( Snapshots[sx].Get_Description() );
			Sec_Element.appendChild( Dom_Text );
			
			// END
			VM_Element.appendChild( Dom_Element );
		}
	}
	else
	{
		// Storage Device Count
		Dom_Element = New_Dom_Document.createElement( "Snapshots_Count" );
		VM_Element.appendChild( Dom_Element );
		Dom_Text = New_Dom_Document.createTextNode( "0" );
		Dom_Element.appendChild( Dom_Text );
	}
	
	// Storage Devices
	QString qemu_version = Settings.value( "QEMU_Version", "Old" ).toString();
	
	if( (qemu_version == "0.9.1" || qemu_version == "New") &&
	    (template_mode == false || (template_mode == true  && Template_Opts & Create_Template_Window::Template_Save_HDD)) )
	{
		// Storage Device Count
		Dom_Element = New_Dom_Document.createElement( "Storage_Device_Count" );
		VM_Element.appendChild( Dom_Element );
		Dom_Text = New_Dom_Document.createTextNode( QString::number(Storage_Devices.count()) );
		Dom_Element.appendChild( Dom_Text );
		
		for( int sx = 0; sx < Storage_Devices.count(); ++sx )
		{
			Dom_Element = New_Dom_Document.createElement( "Storage_Device_" + QString::number(sx) );
			
			// Use File Path
			Sec_Element = New_Dom_Document.createElement( "Use_File_Path" );
			Dom_Element.appendChild( Sec_Element );
			
			if( Storage_Devices[sx].Use_File_Path() )
			{
				Dom_Text = New_Dom_Document.createTextNode( "true" );
			}
			else
			{
				Dom_Text = New_Dom_Document.createTextNode( "false" );
			}
			
			Sec_Element.appendChild( Dom_Text );
			
			// File Path
			Sec_Element = New_Dom_Document.createElement( "File_Path" );
			Dom_Element.appendChild( Sec_Element );
			Dom_Text = New_Dom_Document.createTextNode( Storage_Devices[sx].Get_File_Path() );
			Sec_Element.appendChild( Dom_Text );
			
			// Use Interface
			Sec_Element = New_Dom_Document.createElement( "Use_Interface" );
			Dom_Element.appendChild( Sec_Element );
			
			if( Storage_Devices[sx].Use_Interface() )
			{
				Dom_Text = New_Dom_Document.createTextNode( "true" );
			}
			else
			{
				Dom_Text = New_Dom_Document.createTextNode( "false" );
			}
			
			Sec_Element.appendChild( Dom_Text );
			
			// Interface
			switch( Storage_Devices[sx].Get_Interface() )
			{
				case VM::DI_IDE:
					Sec_Element = New_Dom_Document.createElement( "Interface" );
					Dom_Element.appendChild( Sec_Element );
					Dom_Text = New_Dom_Document.createTextNode( "IDE" );
					Sec_Element.appendChild( Dom_Text );
					break;
					
				case VM::DI_SCSI:
					Sec_Element = New_Dom_Document.createElement( "Interface" );
					Dom_Element.appendChild( Sec_Element );
					Dom_Text = New_Dom_Document.createTextNode( "SCSI" );
					Sec_Element.appendChild( Dom_Text );
					break;
					
				case VM::DI_SD:
					Sec_Element = New_Dom_Document.createElement( "Interface" );
					Dom_Element.appendChild( Sec_Element );
					Dom_Text = New_Dom_Document.createTextNode( "SD" );
					Sec_Element.appendChild( Dom_Text );
					break;
					
				case VM::DI_MTD:
					Sec_Element = New_Dom_Document.createElement( "Interface" );
					Dom_Element.appendChild( Sec_Element );
					Dom_Text = New_Dom_Document.createTextNode( "MTD" );
					Sec_Element.appendChild( Dom_Text );
					break;
					
				case VM::DI_Floppy:
					Sec_Element = New_Dom_Document.createElement( "Interface" );
					Dom_Element.appendChild( Sec_Element );
					Dom_Text = New_Dom_Document.createTextNode( "Floppy" );
					Sec_Element.appendChild( Dom_Text );
					break;
					
				case VM::DI_PFlash:
					Sec_Element = New_Dom_Document.createElement( "Interface" );
					Dom_Element.appendChild( Sec_Element );
					Dom_Text = New_Dom_Document.createTextNode( "PFlash" );
					Sec_Element.appendChild( Dom_Text );
					break;
					
				default:
					AQError( "bool Virtual_Machine::Create_VM_File( const QString &file_name, bool template_mode )",
							 "Storage Device Interface Default Section!" );
					break;
			}
			
			// Use Bus Unit
			Sec_Element = New_Dom_Document.createElement( "Use_Bus_Unit" );
			Dom_Element.appendChild( Sec_Element );
			
			if( Storage_Devices[sx].Use_Bus_Unit() )
			{
				Dom_Text = New_Dom_Document.createTextNode( "true" );
			}
			else
			{
				Dom_Text = New_Dom_Document.createTextNode( "false" );
			}
			
			Sec_Element.appendChild( Dom_Text );
			
			// Bus
			Sec_Element = New_Dom_Document.createElement( "Bus" );
			Dom_Element.appendChild( Sec_Element );
			Dom_Text = New_Dom_Document.createTextNode( QString::number(Storage_Devices[sx].Get_Bus()) );
			Sec_Element.appendChild( Dom_Text );
			
			// Unit
			Sec_Element = New_Dom_Document.createElement( "Unit" );
			Dom_Element.appendChild( Sec_Element );
			Dom_Text = New_Dom_Document.createTextNode( QString::number(Storage_Devices[sx].Get_Unit()) );
			Sec_Element.appendChild( Dom_Text );
			
			// Use Index
			Sec_Element = New_Dom_Document.createElement( "Use_Index" );
			Dom_Element.appendChild( Sec_Element );
			
			if( Storage_Devices[sx].Use_Index() )
			{
				Dom_Text = New_Dom_Document.createTextNode( "true" );
			}
			else
			{
				Dom_Text = New_Dom_Document.createTextNode( "false" );
			}
			
			Sec_Element.appendChild( Dom_Text );
			
			// Index
			Sec_Element = New_Dom_Document.createElement( "Index" );
			Dom_Element.appendChild( Sec_Element );
			Dom_Text = New_Dom_Document.createTextNode( QString::number(Storage_Devices[sx].Get_Index()) );
			Sec_Element.appendChild( Dom_Text );
			
			// Use Media
			Sec_Element = New_Dom_Document.createElement( "Use_Media" );
			Dom_Element.appendChild( Sec_Element );
			
			if( Storage_Devices[sx].Use_Media() )
			{
				Dom_Text = New_Dom_Document.createTextNode( "true" );
			}
			else
			{
				Dom_Text = New_Dom_Document.createTextNode( "false" );
			}
			
			Sec_Element.appendChild( Dom_Text );
			
			// Media
			switch( Storage_Devices[sx].Get_Media() )
			{
				case VM::DM_Disk:
					Sec_Element = New_Dom_Document.createElement( "Media" );
					Dom_Element.appendChild( Sec_Element );
					Dom_Text = New_Dom_Document.createTextNode( "Disk" );
					Sec_Element.appendChild( Dom_Text );
					break;
					
				case VM::DM_CD_ROM:
					Sec_Element = New_Dom_Document.createElement( "Media" );
					Dom_Element.appendChild( Sec_Element );
					Dom_Text = New_Dom_Document.createTextNode( "CD_ROM" );
					Sec_Element.appendChild( Dom_Text );
					break;
					
				default:
					AQError( "bool Virtual_Machine::Create_VM_File( const QString &file_name, bool template_mode )",
							 "Storage Device Media Default Section!" );
					break;
			}
			
			// Use hdachs
			Sec_Element = New_Dom_Document.createElement( "Use_hdachs" );
			Dom_Element.appendChild( Sec_Element );
			
			if( Storage_Devices[sx].Use_hdachs() )
			{
				Dom_Text = New_Dom_Document.createTextNode( "true" );
			}
			else
			{
				Dom_Text = New_Dom_Document.createTextNode( "false" );
			}
			
			Sec_Element.appendChild( Dom_Text );
			
			// Cyls
			Sec_Element = New_Dom_Document.createElement( "Cyls" );
			Dom_Element.appendChild( Sec_Element );
			Dom_Text = New_Dom_Document.createTextNode( QString::number(Storage_Devices[sx].Get_Cyls()) );
			Sec_Element.appendChild( Dom_Text );
			
			// Heads
			Sec_Element = New_Dom_Document.createElement( "Heads" );
			Dom_Element.appendChild( Sec_Element );
			Dom_Text = New_Dom_Document.createTextNode( QString::number(Storage_Devices[sx].Get_Heads()) );
			Sec_Element.appendChild( Dom_Text );
			
			// Secs
			Sec_Element = New_Dom_Document.createElement( "Secs" );
			Dom_Element.appendChild( Sec_Element );
			Dom_Text = New_Dom_Document.createTextNode( QString::number(Storage_Devices[sx].Get_Secs()) );
			Sec_Element.appendChild( Dom_Text );
			
			// Trans
			Sec_Element = New_Dom_Document.createElement( "Trans" );
			Dom_Element.appendChild( Sec_Element );
			Dom_Text = New_Dom_Document.createTextNode( QString::number(Storage_Devices[sx].Get_Trans()) );
			Sec_Element.appendChild( Dom_Text );
			
			// Snapshot
			Sec_Element = New_Dom_Document.createElement( "Snapshot" );
			Dom_Element.appendChild( Sec_Element );
			
			if( Storage_Devices[sx].Get_Snapshot() )
			{
				Dom_Text = New_Dom_Document.createTextNode( "true" );
			}
			else
			{
				Dom_Text = New_Dom_Document.createTextNode( "false" );
			}
			
			Sec_Element.appendChild( Dom_Text );
			
			// Cache
			Sec_Element = New_Dom_Document.createElement( "Cache" );
			Dom_Element.appendChild( Sec_Element );
			
			if( Storage_Devices[sx].Get_Cache() )
			{
				Dom_Text = New_Dom_Document.createTextNode( "true" );
			}
			else
			{
				Dom_Text = New_Dom_Document.createTextNode( "false" );
			}
			
			Sec_Element.appendChild( Dom_Text );
			
			// END
			VM_Element.appendChild( Dom_Element );
		}
	}
	else
	{
		// Not Devices
		Dom_Element = New_Dom_Document.createElement( "Storage_Device_Count" );
		VM_Element.appendChild( Dom_Element );
		Dom_Text = New_Dom_Document.createTextNode( QString::number(0) );
		Dom_Element.appendChild( Dom_Text );
	}
	
	// Network
	if( template_mode &&
		! (Template_Opts & Create_Template_Window::Template_Save_Network) )
	{
		// Use Network
		Dom_Element = New_Dom_Document.createElement( "Use_Network" );
		VM_Element.appendChild( Dom_Element );
		Dom_Text = New_Dom_Document.createTextNode( "false" );
		Dom_Element.appendChild( Dom_Text );
		
		// Use Redirections
		Dom_Element = New_Dom_Document.createElement( "Use_Redirections" );
		VM_Element.appendChild( Dom_Element );
		Dom_Text = New_Dom_Document.createTextNode( "false" );
		Dom_Element.appendChild( Dom_Text );
		
		// Network Cards Count
		Dom_Element = New_Dom_Document.createElement( "Network_Cards_Count" );
		VM_Element.appendChild( Dom_Element );
		Dom_Text = New_Dom_Document.createTextNode( QString::number(0) );
		Dom_Element.appendChild( Dom_Text );
		
		// Redirections count
		Dom_Element = New_Dom_Document.createElement( "Redirections_Count" );
		VM_Element.appendChild( Dom_Element );
		Dom_Text = New_Dom_Document.createTextNode( QString::number(0) );
		Dom_Element.appendChild( Dom_Text );
		
		// TFTP Prefix
		Dom_Element = New_Dom_Document.createElement( "TFTP_Prefix" );
		VM_Element.appendChild( Dom_Element );
		Dom_Text = New_Dom_Document.createTextNode( "" );
		Dom_Element.appendChild( Dom_Text );
		
		// SMB Directory
		Dom_Element = New_Dom_Document.createElement( "SMB_Directory" );
		VM_Element.appendChild( Dom_Element );
		Dom_Text = New_Dom_Document.createTextNode( "" );
		Dom_Element.appendChild( Dom_Text );
	}
	else
	{
		// Use Network
		Dom_Element = New_Dom_Document.createElement( "Use_Network" );
		VM_Element.appendChild( Dom_Element );
		
		if( Use_Network )
		{
			Dom_Text = New_Dom_Document.createTextNode( "true" );
		}
		else
		{
			Dom_Text = New_Dom_Document.createTextNode( "false" );
		}
		
		Dom_Element.appendChild( Dom_Text );
		
		// Use Redirections
		Dom_Element = New_Dom_Document.createElement( "Use_Redirections" );
		VM_Element.appendChild( Dom_Element );
		
		if( Use_Redirections )
		{
			Dom_Text = New_Dom_Document.createTextNode( "true" );
		}
		else
		{
			Dom_Text = New_Dom_Document.createTextNode( "false" );
		}
		
		Dom_Element.appendChild( Dom_Text );
		
		// Network Cards Count
		Dom_Element = New_Dom_Document.createElement( "Network_Cards_Count" );
		VM_Element.appendChild( Dom_Element );
		Dom_Text = New_Dom_Document.createTextNode( QString::number(Network_Cards.count()) );
		Dom_Element.appendChild( Dom_Text );
		
		for( int nx = 0; nx < Network_Cards.count(); nx++ )
		{
			Dom_Element = New_Dom_Document.createElement( "Network_Card_" + QString::number(nx) );
			
			// Card Model
			Sec_Element = New_Dom_Document.createElement( "Card_Model" );
			Dom_Element.appendChild( Sec_Element );
			Dom_Text = New_Dom_Document.createTextNode( Network_Cards[nx].Get_Card_Model() );
			Sec_Element.appendChild( Dom_Text );
			
			// Network Mode
			Sec_Element = New_Dom_Document.createElement( "Network_Mode" );
			Dom_Element.appendChild( Sec_Element );
			
			switch( Network_Cards[nx].Get_Net_Mode() )
			{
				case VM::Net_Mode_None:
					Dom_Text = New_Dom_Document.createTextNode( "None" );
					break;
				
				case VM::Net_Mode_Usermode:
					Dom_Text = New_Dom_Document.createTextNode( "Usermode" );
					break;
				
				case VM::Net_Mode_Tuntap:
					Dom_Text = New_Dom_Document.createTextNode( "Tuntap" );
					break;
				
				case VM::Net_Mode_Tuntapfd:
					Dom_Text = New_Dom_Document.createTextNode( "Tuntapfd" );
					break;
				
				case VM::Net_Mode_Tcplisten:
					Dom_Text = New_Dom_Document.createTextNode( "Tcplisten" );
					break;
				
				case VM::Net_Mode_Tcpfd:
					Dom_Text = New_Dom_Document.createTextNode( "Tcpfd" );
					break;
				
				case VM::Net_Mode_Tcpconnect:
					Dom_Text = New_Dom_Document.createTextNode( "Tcpconnect" );
					break;
				
				case VM::Net_Mode_Multicast:
					Dom_Text = New_Dom_Document.createTextNode( "Multicast" );
					break;
				
				case VM::Net_Mode_Multicastfd:
					Dom_Text = New_Dom_Document.createTextNode( "Multicastfd" );
					break;
				
				default:
					Dom_Text = New_Dom_Document.createTextNode( "Dummy" );
					break;
			}
			
			Sec_Element.appendChild( Dom_Text );
			
			// Hostname
			Sec_Element = New_Dom_Document.createElement( "Hostname" );
			Dom_Element.appendChild( Sec_Element );
			Dom_Text = New_Dom_Document.createTextNode( Network_Cards[nx].Get_Hostname() );
			Sec_Element.appendChild( Dom_Text );
			
			// IP Address
			Sec_Element = New_Dom_Document.createElement( "IP_Address" );
			Dom_Element.appendChild( Sec_Element );
			Dom_Text = New_Dom_Document.createTextNode( Network_Cards[nx].Get_IP_Address() );
			Sec_Element.appendChild( Dom_Text );
			
			// MAC Address
			Sec_Element = New_Dom_Document.createElement( "MAC_Address" );
			Dom_Element.appendChild( Sec_Element );
			Dom_Text = New_Dom_Document.createTextNode( Network_Cards[nx].Get_MAC_Address() );
			Sec_Element.appendChild( Dom_Text );
			
			// Port
			Sec_Element = New_Dom_Document.createElement( "Port" );
			Dom_Element.appendChild( Sec_Element );
			Dom_Text = New_Dom_Document.createTextNode( QString::number(Network_Cards[nx].Get_Port()) );
			Sec_Element.appendChild( Dom_Text );
			
			// VLAN
			Sec_Element = New_Dom_Document.createElement( "VLAN" );
			Dom_Element.appendChild( Sec_Element );
			Dom_Text = New_Dom_Document.createTextNode( QString::number(Network_Cards[nx].Get_VLAN()) );
			Sec_Element.appendChild( Dom_Text );
			
			// Use TUN TAP Script
			Sec_Element = New_Dom_Document.createElement( "Use_TUN_TAP_Script" );
			Dom_Element.appendChild( Sec_Element );
			
			if( Network_Cards[nx].Get_Use_TUN_TAP_Script() )
			{
				Dom_Text = New_Dom_Document.createTextNode( "true" );
			}
			else
			{
				Dom_Text = New_Dom_Document.createTextNode( "false" );
			}
			
			Sec_Element.appendChild( Dom_Text );
			
			// TUN TAP Script
			Sec_Element = New_Dom_Document.createElement( "TUN_TAP_Script" );
			Dom_Element.appendChild( Sec_Element );
			Dom_Text = New_Dom_Document.createTextNode( Network_Cards[nx].Get_TUN_TAP_Script() );
			Sec_Element.appendChild( Dom_Text );
			
			// Interface Name
			Sec_Element = New_Dom_Document.createElement( "Interface_Name" );
			Dom_Element.appendChild( Sec_Element );
			Dom_Text = New_Dom_Document.createTextNode( Network_Cards[nx].Get_Interface_Name() );
			Sec_Element.appendChild( Dom_Text );
			
			// File Descriptor
			Sec_Element = New_Dom_Document.createElement( "File_Descriptor" );
			Dom_Element.appendChild( Sec_Element );
			Dom_Text = New_Dom_Document.createTextNode( QString::number(Network_Cards[nx].Get_File_Descriptor()) );
			Sec_Element.appendChild( Dom_Text );
			
			VM_Element.appendChild( Dom_Element );
		}
		
		// Redirections count
		Dom_Element = New_Dom_Document.createElement( "Redirections_Count" );
		VM_Element.appendChild( Dom_Element );
		Dom_Text = New_Dom_Document.createTextNode( QString::number(Network_Redirections.count()) );
		Dom_Element.appendChild( Dom_Text );
		
		// Network Redirections
		for( int rx = 0; rx < Network_Redirections.count(); rx++ )
		{
			Dom_Element = New_Dom_Document.createElement( "Network_Redirections_" + QString::number(rx) );
			
			// Protocol
			Sec_Element = New_Dom_Document.createElement( "Protocol" );
			Dom_Element.appendChild( Sec_Element );
			Dom_Text = New_Dom_Document.createTextNode( Network_Redirections[rx].Get_Protocol() );
			Sec_Element.appendChild( Dom_Text );
			
			// Host Port
			Sec_Element = New_Dom_Document.createElement( "Host_Port" );
			Dom_Element.appendChild( Sec_Element );
			Dom_Text = New_Dom_Document.createTextNode( QString::number(Network_Redirections[rx].Get_Host_Port()) );
			Sec_Element.appendChild( Dom_Text );
			
			// Guest IP
			Sec_Element = New_Dom_Document.createElement( "Guest_IP" );
			Dom_Element.appendChild( Sec_Element );
			Dom_Text = New_Dom_Document.createTextNode( Network_Redirections[rx].Get_Guest_IP() );
			Sec_Element.appendChild( Dom_Text );
			
			// Guest Port
			Sec_Element = New_Dom_Document.createElement( "Guest_Port" );
			Dom_Element.appendChild( Sec_Element );
			Dom_Text = New_Dom_Document.createTextNode( QString::number(Network_Redirections[rx].Get_Guest_Port()) );
			Sec_Element.appendChild( Dom_Text );
			
			VM_Element.appendChild( Dom_Element );
		}
		
		// TFTP Prefix
		Dom_Element = New_Dom_Document.createElement( "TFTP_Prefix" );
		VM_Element.appendChild( Dom_Element );
		Dom_Text = New_Dom_Document.createTextNode( TFTP_Prefix );
		Dom_Element.appendChild( Dom_Text );
		
		// SMB Directory
		Dom_Element = New_Dom_Document.createElement( "SMB_Directory" );
		VM_Element.appendChild( Dom_Element );
		Dom_Text = New_Dom_Document.createTextNode( SMB_Directory );
		Dom_Element.appendChild( Dom_Text );
	}
	
	if( template_mode &&
		! (Template_Opts & Create_Template_Window::Template_Save_Ports) )
	{
		// Serial Port
		Dom_Element = New_Dom_Document.createElement( "Serial_Port" );
		
		// Get_Port_Redirection()
		Sec_Element = New_Dom_Document.createElement( "Port_Redirection" );
		Dom_Element.appendChild( Sec_Element );
		Dom_Text = New_Dom_Document.createTextNode( "Default" );
		Sec_Element.appendChild( Dom_Text );
		
		// Parametrs Line
		Sec_Element = New_Dom_Document.createElement( "Parametrs" );
		Dom_Element.appendChild( Sec_Element );
		Dom_Text = New_Dom_Document.createTextNode( "" );
		Sec_Element.appendChild( Dom_Text );
		
		VM_Element.appendChild( Dom_Element );
		
		// Parallel Port
		Dom_Element = New_Dom_Document.createElement( "Parallel_Port" );
		
		// Get_Port_Redirection()
		Sec_Element = New_Dom_Document.createElement( "Port_Redirection" );
		Dom_Element.appendChild( Sec_Element );
		Dom_Text = New_Dom_Document.createTextNode( "Default" );
		Sec_Element.appendChild( Dom_Text );
		
		// Parametrs Line
		Sec_Element = New_Dom_Document.createElement( "Parametrs" );
		Dom_Element.appendChild( Sec_Element );
		Dom_Text = New_Dom_Document.createTextNode( "" );
		Sec_Element.appendChild( Dom_Text );
		
		VM_Element.appendChild( Dom_Element );
		
		// USB Ports
		Dom_Element = New_Dom_Document.createElement( "USB_Ports_Count" );
		VM_Element.appendChild( Dom_Element );
		Dom_Text = New_Dom_Document.createTextNode( QString::number(0) );
		Dom_Element.appendChild( Dom_Text );
	}
	else
	{
		// Serial Port
		Dom_Element = New_Dom_Document.createElement( "Serial_Port" );
		
		// Get_Port_Redirection()
		Sec_Element = New_Dom_Document.createElement( "Port_Redirection" );
		Dom_Element.appendChild( Sec_Element );
		
		switch( Serial_Port.Get_Port_Redirection() )
		{
			case VM::PR_vc:
				Dom_Text = New_Dom_Document.createTextNode( "vc" );
				break;
			
			case VM::PR_pty:
				Dom_Text = New_Dom_Document.createTextNode( "pty" );
				break;
			
			case VM::PR_none:
				Dom_Text = New_Dom_Document.createTextNode( "none" );
				break;
			
			case VM::PR_null:
				Dom_Text = New_Dom_Document.createTextNode( "null" );
				break;
			
			case VM::PR_dev:
				Dom_Text = New_Dom_Document.createTextNode( "dev" );
				break;
			
			case VM::PR_host_port:
				Dom_Text = New_Dom_Document.createTextNode( "host_port" );
				break;
			
			case VM::PR_file:
				Dom_Text = New_Dom_Document.createTextNode( "file" );
				break;
			
			case VM::PR_stdio:
				Dom_Text = New_Dom_Document.createTextNode( "stdio" );
				break;
			
			case VM::PR_pipe:
				Dom_Text = New_Dom_Document.createTextNode( "pipe" );
				break;
			
			case VM::PR_udp:
				Dom_Text = New_Dom_Document.createTextNode( "udp" );
				break;
			
			case VM::PR_tcp:
				Dom_Text = New_Dom_Document.createTextNode( "tcp" );
				break;
			
			case VM::PR_telnet:
				Dom_Text = New_Dom_Document.createTextNode( "telnet" );
				break;
			
			case VM::PR_unix:
				Dom_Text = New_Dom_Document.createTextNode( "unix" );
				break;
			
			default:
				Dom_Text = New_Dom_Document.createTextNode( "Default" );
				break;
		}
		
		Sec_Element.appendChild( Dom_Text );
		
		// Parametrs Line
		Sec_Element = New_Dom_Document.createElement( "Parametrs" );
		Dom_Element.appendChild( Sec_Element );
		Dom_Text = New_Dom_Document.createTextNode( Serial_Port.Get_Parametrs_Line() );
		Sec_Element.appendChild( Dom_Text );
		
		VM_Element.appendChild( Dom_Element );
		
		// Parallel Port
		Dom_Element = New_Dom_Document.createElement( "Parallel_Port" );
		
		// Get_Port_Redirection()
		Sec_Element = New_Dom_Document.createElement( "Port_Redirection" );
		Dom_Element.appendChild( Sec_Element );
		
		switch( Parallel_Port.Get_Port_Redirection() )
		{
			case VM::PR_vc:
				Dom_Text = New_Dom_Document.createTextNode( "vc" );
				break;
			
			case VM::PR_pty:
				Dom_Text = New_Dom_Document.createTextNode( "pty" );
				break;
			
			case VM::PR_none:
				Dom_Text = New_Dom_Document.createTextNode( "none" );
				break;
			
			case VM::PR_null:
				Dom_Text = New_Dom_Document.createTextNode( "null" );
				break;
			
			case VM::PR_dev:
				Dom_Text = New_Dom_Document.createTextNode( "dev" );
				break;
			
			case VM::PR_host_port:
				Dom_Text = New_Dom_Document.createTextNode( "host_port" );
				break;
			
			case VM::PR_file:
				Dom_Text = New_Dom_Document.createTextNode( "file" );
				break;
			
			case VM::PR_stdio:
				Dom_Text = New_Dom_Document.createTextNode( "stdio" );
				break;
			
			case VM::PR_pipe:
				Dom_Text = New_Dom_Document.createTextNode( "pipe" );
				break;
			
			case VM::PR_udp:
				Dom_Text = New_Dom_Document.createTextNode( "udp" );
				break;
			
			case VM::PR_tcp:
				Dom_Text = New_Dom_Document.createTextNode( "tcp" );
				break;
			
			case VM::PR_telnet:
				Dom_Text = New_Dom_Document.createTextNode( "telnet" );
				break;
			
			case VM::PR_unix:
				Dom_Text = New_Dom_Document.createTextNode( "unix" );
				break;
			
			default:
				Dom_Text = New_Dom_Document.createTextNode( "Default" );
				break;
		}
		
		Sec_Element.appendChild( Dom_Text );
		
		// Parametrs Line
		Sec_Element = New_Dom_Document.createElement( "Parametrs" );
		Dom_Element.appendChild( Sec_Element );
		Dom_Text = New_Dom_Document.createTextNode( Parallel_Port.Get_Parametrs_Line() );
		Sec_Element.appendChild( Dom_Text );
		
		VM_Element.appendChild( Dom_Element );
		
		// Enable USB Hub
		Dom_Element = New_Dom_Document.createElement( "USB_Hub" );
		VM_Element.appendChild( Dom_Element );
	
		if( USB_Hub )
		{
			Dom_Text = New_Dom_Document.createTextNode( "true" );
		}
		else
		{
			Dom_Text = New_Dom_Document.createTextNode( "false" );
		}
	
		Dom_Element.appendChild( Dom_Text );
		
		// USB Ports
		Dom_Element = New_Dom_Document.createElement( "USB_Ports_Count" );
		VM_Element.appendChild( Dom_Element );
		Dom_Text = New_Dom_Document.createTextNode( QString::number(USB_Ports.count()) );
		Dom_Element.appendChild( Dom_Text );
		
		// USB Devices
		for( int ux = 0; ux < USB_Ports.count(); ++ux )
		{
			Dom_Element = New_Dom_Document.createElement( "USB_Port_" + QString::number(ux) );
			
			// Manufacturer Name
			Sec_Element = New_Dom_Document.createElement( "Manufacturer_Name" );
			Dom_Element.appendChild( Sec_Element );
			Dom_Text = New_Dom_Document.createTextNode( USB_Ports[ux].Get_Manufacturer_Name() );
			Sec_Element.appendChild( Dom_Text );
			
			// Product Name
			Sec_Element = New_Dom_Document.createElement( "Product_Name" );
			Dom_Element.appendChild( Sec_Element );
			Dom_Text = New_Dom_Document.createTextNode( USB_Ports[ux].Get_Product_Name() );
			Sec_Element.appendChild( Dom_Text );
			
			// Vendor_ID
			Sec_Element = New_Dom_Document.createElement( "Vendor_ID" );
			Dom_Element.appendChild( Sec_Element );
			Dom_Text = New_Dom_Document.createTextNode( USB_Ports[ux].Get_Vendor_ID() );
			Sec_Element.appendChild( Dom_Text );
			
			// Product_ID
			Sec_Element = New_Dom_Document.createElement( "Product_ID" );
			Dom_Element.appendChild( Sec_Element );
			Dom_Text = New_Dom_Document.createTextNode( USB_Ports[ux].Get_Product_ID() );
			Sec_Element.appendChild( Dom_Text );
			
			VM_Element.appendChild( Dom_Element );
		}
	}
	
	// Linux Boot
	Dom_Element = New_Dom_Document.createElement( "Linux_Boot" );
	VM_Element.appendChild( Dom_Element );
	
	if( Linux_Boot )
	{
		Dom_Text = New_Dom_Document.createTextNode( "true" );
	}
	else
	{
		Dom_Text = New_Dom_Document.createTextNode( "false" );
	}
	
	Dom_Element.appendChild( Dom_Text );
	
	// bzImage Path
	Dom_Element = New_Dom_Document.createElement( "bzImage_Path" );
	VM_Element.appendChild( Dom_Element );
	Dom_Text = New_Dom_Document.createTextNode( bzImage_Path );
	Dom_Element.appendChild( Dom_Text );
	
	// Initrd Path
	Dom_Element = New_Dom_Document.createElement( "Initrd_Path" );
	VM_Element.appendChild( Dom_Element );
	Dom_Text = New_Dom_Document.createTextNode( Initrd_Path );
	Dom_Element.appendChild( Dom_Text );
	
	// Kernel Command Line Arguments
	Dom_Element = New_Dom_Document.createElement( "Kernel_ComLine" );
	VM_Element.appendChild( Dom_Element );
	Dom_Text = New_Dom_Document.createTextNode( Kernel_ComLine );
	Dom_Element.appendChild( Dom_Text );
	
	// Use ROM File
	Dom_Element = New_Dom_Document.createElement( "Use_ROM_File" );
	VM_Element.appendChild( Dom_Element );
	
	if( Use_ROM_File )
	{
		Dom_Text = New_Dom_Document.createTextNode( "true" );
	}
	else
	{
		Dom_Text = New_Dom_Document.createTextNode( "false" );
	}
	
	Dom_Element.appendChild( Dom_Text );
	
	// ROM File Path
	Dom_Element = New_Dom_Document.createElement( "ROM_File" );
	VM_Element.appendChild( Dom_Element );
	Dom_Text = New_Dom_Document.createTextNode( ROM_File );
	Dom_Element.appendChild( Dom_Text );
	
	// Use MTDBlock File
	Dom_Element = New_Dom_Document.createElement( "Use_MTDBlock_File" );
	VM_Element.appendChild( Dom_Element );
	
	if( MTDBlock )
	{
		Dom_Text = New_Dom_Document.createTextNode( "true" );
	}
	else
	{
		Dom_Text = New_Dom_Document.createTextNode( "false" );
	}
	
	Dom_Element.appendChild( Dom_Text );
	
	// MTDBlock File
	Dom_Element = New_Dom_Document.createElement( "MTDBlock_File" );
	VM_Element.appendChild( Dom_Element );
	Dom_Text = New_Dom_Document.createTextNode( MTDBlock_File );
	Dom_Element.appendChild( Dom_Text );
	
	// Use SecureDigital File
	Dom_Element = New_Dom_Document.createElement( "Use_SecureDigital_File" );
	VM_Element.appendChild( Dom_Element );
	
	if( SecureDigital )
	{
		Dom_Text = New_Dom_Document.createTextNode( "true" );
	}
	else
	{
		Dom_Text = New_Dom_Document.createTextNode( "false" );
	}
	
	Dom_Element.appendChild( Dom_Text );
	
	// SecureDigital File
	Dom_Element = New_Dom_Document.createElement( "SecureDigital_File" );
	VM_Element.appendChild( Dom_Element );
	Dom_Text = New_Dom_Document.createTextNode( SecureDigital_File );
	Dom_Element.appendChild( Dom_Text );
	
	// Use PFlash File
	Dom_Element = New_Dom_Document.createElement( "Use_PFlash_File" );
	VM_Element.appendChild( Dom_Element );
	
	if( PFlash )
	{
		Dom_Text = New_Dom_Document.createTextNode( "true" );
	}
	else
	{
		Dom_Text = New_Dom_Document.createTextNode( "false" );
	}
	
	Dom_Element.appendChild( Dom_Text );
	
	// PFlash File
	Dom_Element = New_Dom_Document.createElement( "PFlash_File" );
	VM_Element.appendChild( Dom_Element );
	Dom_Text = New_Dom_Document.createTextNode( PFlash_File );
	Dom_Element.appendChild( Dom_Text );
	
	// GDB
	Dom_Element = New_Dom_Document.createElement( "GDB" );
	VM_Element.appendChild( Dom_Element );
	
	if( GDB )
	{
		Dom_Text = New_Dom_Document.createTextNode( "true" );
	}
	else
	{
		Dom_Text = New_Dom_Document.createTextNode( "false" );
	}
	
	Dom_Element.appendChild( Dom_Text );
	
	// GDB_Port
	Dom_Element = New_Dom_Document.createElement( "GDB_Port" );
	VM_Element.appendChild( Dom_Element );
	Dom_Text = New_Dom_Document.createTextNode( QString::number(GDB_Port) );
	Dom_Element.appendChild( Dom_Text );
	
	// Additional Arguments
	Dom_Element = New_Dom_Document.createElement( "Additional_Args" );
	VM_Element.appendChild( Dom_Element );
	Dom_Text = New_Dom_Document.createTextNode( Additional_Args );
	Dom_Element.appendChild( Dom_Text );
	
	// Use KVM IRQChip
	Dom_Element = New_Dom_Document.createElement( "Use_KVM_IRQChip" );
	VM_Element.appendChild( Dom_Element );
	
	if( KVM_IRQChip )
	{
		Dom_Text = New_Dom_Document.createTextNode( "true" );
	}
	else
	{
		Dom_Text = New_Dom_Document.createTextNode( "false" );
	}
	
	Dom_Element.appendChild( Dom_Text );
	
	// Use No KVM Pit
	Dom_Element = New_Dom_Document.createElement( "Use_No_KVM_Pit" );
	VM_Element.appendChild( Dom_Element );
	
	if( No_KVM_Pit )
	{
		Dom_Text = New_Dom_Document.createTextNode( "true" );
	}
	else
	{
		Dom_Text = New_Dom_Document.createTextNode( "false" );
	}
	
	Dom_Element.appendChild( Dom_Text );
	
	// Use_KVM_Shadow_Memory
	Dom_Element = New_Dom_Document.createElement( "Use_KVM_Shadow_Memory" );
	VM_Element.appendChild( Dom_Element );
	
	if( KVM_Shadow_Memory )
	{
		Dom_Text = New_Dom_Document.createTextNode( "true" );
	}
	else
	{
		Dom_Text = New_Dom_Document.createTextNode( "false" );
	}
	
	Dom_Element.appendChild( Dom_Text );
	
	// KVM_Shadow_Memory_Size
	Dom_Element = New_Dom_Document.createElement( "KVM_Shadow_Memory_Size" );
	VM_Element.appendChild( Dom_Element );
	Dom_Text = New_Dom_Document.createTextNode( QString::number(KVM_Shadow_Memory_Size) );
	Dom_Element.appendChild( Dom_Text );
	
	// Init_Graphic_Mode
	Dom_Element = New_Dom_Document.createElement( "Init_Graphic_Mode" );
	
	// Enabled
	Sec_Element = New_Dom_Document.createElement( "Enabled" );
	Dom_Element.appendChild( Sec_Element );
	
	if( Init_Graphic_Mode.Get_Enabled() )
	{
		Dom_Text = New_Dom_Document.createTextNode( "true" );
	}
	else
	{
		Dom_Text = New_Dom_Document.createTextNode( "false" );
	}
	
	Sec_Element.appendChild( Dom_Text );
	
	// Width
	Sec_Element = New_Dom_Document.createElement( "Width" );
	Dom_Element.appendChild( Sec_Element );
	Dom_Text = New_Dom_Document.createTextNode( QString::number(Init_Graphic_Mode.Get_Width()) );
	Sec_Element.appendChild( Dom_Text );
	
	// Height
	Sec_Element = New_Dom_Document.createElement( "Height" );
	Dom_Element.appendChild( Sec_Element );
	Dom_Text = New_Dom_Document.createTextNode( QString::number(Init_Graphic_Mode.Get_Height()) );
	Sec_Element.appendChild( Dom_Text );
	
	// Depth
	Sec_Element = New_Dom_Document.createElement( "Depth" );
	Dom_Element.appendChild( Sec_Element );
	Dom_Text = New_Dom_Document.createTextNode( QString::number(Init_Graphic_Mode.Get_Depth()) );
	Sec_Element.appendChild( Dom_Text );
	
	VM_Element.appendChild( Dom_Element );
	
	// Use No Frame
	Dom_Element = New_Dom_Document.createElement( "Use_No_Frame" );
	VM_Element.appendChild( Dom_Element );
	
	if( No_Frame )
	{
		Dom_Text = New_Dom_Document.createTextNode( "true" );
	}
	else
	{
		Dom_Text = New_Dom_Document.createTextNode( "false" );
	}
	
	Dom_Element.appendChild( Dom_Text );
	
	// Use Alt Grab
	Dom_Element = New_Dom_Document.createElement( "Use_Alt_Grab" );
	VM_Element.appendChild( Dom_Element );
	
	if( Alt_Grab )
	{
		Dom_Text = New_Dom_Document.createTextNode( "true" );
	}
	else
	{
		Dom_Text = New_Dom_Document.createTextNode( "false" );
	}
	
	Dom_Element.appendChild( Dom_Text );
	
	// Use No Quit
	Dom_Element = New_Dom_Document.createElement( "Use_No_Quit" );
	VM_Element.appendChild( Dom_Element );
	
	if( No_Quit )
	{
		Dom_Text = New_Dom_Document.createTextNode( "true" );
	}
	else
	{
		Dom_Text = New_Dom_Document.createTextNode( "false" );
	}
	
	Dom_Element.appendChild( Dom_Text );
	
	// Use Portrait
	Dom_Element = New_Dom_Document.createElement( "Use_Portrait" );
	VM_Element.appendChild( Dom_Element );
	
	if( Portrait )
	{
		Dom_Text = New_Dom_Document.createTextNode( "true" );
	}
	else
	{
		Dom_Text = New_Dom_Document.createTextNode( "false" );
	}
	
	Dom_Element.appendChild( Dom_Text );
	
	// Start Date
	Dom_Element = New_Dom_Document.createElement( "Use_Start_Date" );
	VM_Element.appendChild( Dom_Element );
	
	if( Start_Date )
	{
		Dom_Text = New_Dom_Document.createTextNode( "true" );
	}
	else
	{
		Dom_Text = New_Dom_Document.createTextNode( "false" );
	}
	
	Dom_Element.appendChild( Dom_Text );
	
	// Start_DateTime
	Dom_Element = New_Dom_Document.createElement( "Start_Date" );
	VM_Element.appendChild( Dom_Element );
	Dom_Text = New_Dom_Document.createTextNode( Start_DateTime.toString("dd.MM.yyyy HH:mm:ss") );
	Dom_Element.appendChild( Dom_Text );
	
	// Use VNC
	Dom_Element = New_Dom_Document.createElement( "Use_VNC" );
	VM_Element.appendChild( Dom_Element );
	
	if( VNC )
	{
		Dom_Text = New_Dom_Document.createTextNode( "true" );
	}
	else
	{
		Dom_Text = New_Dom_Document.createTextNode( "false" );
	}
	
	Dom_Element.appendChild( Dom_Text );
	
	// VNC Socket Mode
	Dom_Element = New_Dom_Document.createElement( "VNC_Socket_Mode" );
	VM_Element.appendChild( Dom_Element );
	
	if( VNC_Socket_Mode )
	{
		Dom_Text = New_Dom_Document.createTextNode( "true" );
	}
	else
	{
		Dom_Text = New_Dom_Document.createTextNode( "false" );
	}
	
	Dom_Element.appendChild( Dom_Text );
	
	// VNC Unix Socket Path
	Dom_Element = New_Dom_Document.createElement( "VNC_Unix_Socket_Path" );
	VM_Element.appendChild( Dom_Element );
	Dom_Text = New_Dom_Document.createTextNode( VNC_Unix_Socket_Path );
	Dom_Element.appendChild( Dom_Text );
	
	// VNC Display Number
	Dom_Element = New_Dom_Document.createElement( "VNC_Display_Number" );
	VM_Element.appendChild( Dom_Element );
	Dom_Text = New_Dom_Document.createTextNode( QString::number(VNC_Display_Number) );
	Dom_Element.appendChild( Dom_Text );
	
	// Use VNC Password
	Dom_Element = New_Dom_Document.createElement( "Use_VNC_Password" );
	VM_Element.appendChild( Dom_Element );
	
	if( VNC_Password )
	{
		Dom_Text = New_Dom_Document.createTextNode( "true" );
	}
	else
	{
		Dom_Text = New_Dom_Document.createTextNode( "false" );
	}
	
	Dom_Element.appendChild( Dom_Text );
	
	// Use VNC TLS
	Dom_Element = New_Dom_Document.createElement( "Use_VNC_TLS" );
	VM_Element.appendChild( Dom_Element );
	
	if( VNC_TLS )
	{
		Dom_Text = New_Dom_Document.createTextNode( "true" );
	}
	else
	{
		Dom_Text = New_Dom_Document.createTextNode( "false" );
	}
	
	Dom_Element.appendChild( Dom_Text );
	
	// Use VNC x509
	Dom_Element = New_Dom_Document.createElement( "Use_VNC_x509" );
	VM_Element.appendChild( Dom_Element );
	
	if( VNC_x509 )
	{
		Dom_Text = New_Dom_Document.createTextNode( "true" );
	}
	else
	{
		Dom_Text = New_Dom_Document.createTextNode( "false" );
	}
	
	Dom_Element.appendChild( Dom_Text );
	
	// VNC x509 Folder Path
	Dom_Element = New_Dom_Document.createElement( "VNC_x509_Folder_Path" );
	VM_Element.appendChild( Dom_Element );
	Dom_Text = New_Dom_Document.createTextNode( VNC_x509_Folder_Path );
	Dom_Element.appendChild( Dom_Text );
	
	// Use VNC x509verify
	Dom_Element = New_Dom_Document.createElement( "Use_VNC_x509verify" );
	VM_Element.appendChild( Dom_Element );
	
	if( VNC_x509verify )
	{
		Dom_Text = New_Dom_Document.createTextNode( "true" );
	}
	else
	{
		Dom_Text = New_Dom_Document.createTextNode( "false" );
	}
	
	Dom_Element.appendChild( Dom_Text );
	
	// VNC x509verify Folder Path
	Dom_Element = New_Dom_Document.createElement( "VNC_x509verify_Folder_Path" );
	VM_Element.appendChild( Dom_Element );
	Dom_Text = New_Dom_Document.createTextNode( VNC_x509verify_Folder_Path );
	Dom_Element.appendChild( Dom_Text );
	
	// Create File and Save Data
	QFile VM_XML_File( file_name );
	
	if( ! VM_XML_File.open(QFile::WriteOnly | QFile::Truncate) )
	{
		AQError( "bool Virtual_Machine::Create_VM_File( const QString &file_name, bool template_mode )",
				 QString("Cannot Create New VM File \"%1\"").arg(file_name) );
		return false;
	}
	
	QTextStream Out_Stream( &VM_XML_File );
	New_Dom_Document.save( Out_Stream, 4 );
	
	return true;
}

bool Virtual_Machine::Create_Template( const QString &vm_path, const QString &template_name,
									   Create_Template_Window::Template_Options opts )
{
	Template_Name = template_name;
	Template_Opts = opts;
	return Create_VM_File( vm_path, true );
}

bool Virtual_Machine::Load_VM( const QString &file_name )
{
	VM_XML_File_Path = file_name;
	
	QFile VM_File( file_name );
	
	if( ! VM_File.open(QFile::ReadOnly | QFile::Text) )
	{
		AQError( "bool Virtual_Machine::Load_VM( const QString &file_name )",
				 QString("Cannot Read VM File \"%1\"! Error String: %2")
						 .arg(file_name).arg(VM_File.errorString()) );
		
		return false;
	}
	else
	{
		QString Error_String;
		int Error_Line, Error_Column;
		
		if( ! VM_Dom_Document.setContent(&VM_File, true,
			  &Error_String, &Error_Line, &Error_Column) )
		{
			AQError( "bool Virtual_Machine::Load_VM( const QString &file_name )",
					 QString("Parse Error!\nLine: %1\nColumn: %2\nString: %3" )
							 .arg(Error_Line).arg(Error_Column).arg(Error_String) );
			
			return false;
		}
		else
		{
			QDomElement Root_Element = VM_Dom_Document.documentElement();
			
			bool template_mode = false;
			
			if( Root_Element.tagName() != "AQEMU" )
			{
				if( Root_Element.tagName() != "AQEMU_Template" )
				{
					AQError( "bool Virtual_Machine::Load_VM( const QString &file_name )",
							 "This is not a AQEMU VM File!" );
					return false;
				}
				else
				{
					template_mode = true;
				}
			}
			
			if( Root_Element.hasAttribute("version") &&
						 Root_Element.attribute("version") != "0.5" )
			{
				AQError( "bool Virtual_Machine::Load_VM( const QString &file_name )",
						 "This is not a AQEMU VM File Version 0.5!" );
				
				// Check Version
				if( Root_Element.attribute("version") == "0.1" )
				{
				}
				else
				{
					int ret_but = QMessageBox::question( NULL, tr("Version Invalid!"),
							tr("This Version on AQEMU VM File no 0.5\nLoad This File?"),
							QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes );
				
					if( ret_but != QMessageBox::Yes )
					{
						return false;
					}
				}
			}
			
			// Read All Data in File
			QDomElement Child_Element =
					Root_Element.firstChildElement( "Virtual_Machine" );
			
			if( template_mode )
			{
				// Template Options
				Template_Opts = (Create_Template_Window::Template_Options)Child_Element.firstChildElement(
						"Template_Options" ).text().toInt();
			}
			
			// VM State
			if( Child_Element.firstChildElement("VM_State").text() == "Saved" )
			{
				Set_State( VM::VMS_Saved );
			}
			else
			{
				Set_State( VM::VMS_Power_Off );
			}
			
			// Icon Path
			Icon_Path = Child_Element.firstChildElement(
					"Icon_Path" ).text();
			
			// Screenshot Path
			Screenshot_Path = Child_Element.firstChildElement(
					"Screenshot_Path" ).text();
			
			// Machine Name
			Machine_Name = Child_Element.firstChildElement(
					"Machine_Name" ).text();
			
			// Computer Type
			Computer_Type = Child_Element.firstChildElement(
					"Computer_Type" ).text();
			
			// Machine Type
			Machine_Type = Child_Element.firstChildElement(
					"Machine_Type" ).text();
			
			// CPU Type
			CPU_Type = Child_Element.firstChildElement(
					"CPU_Type" ).text();
			
			// CPU Count
			SMP_CPU_Count = Child_Element.firstChildElement(
					"SMP_CPU_Count" ).text().toInt();
			
			// Keyboard Layout
			Keyboard_Layout = Child_Element.firstChildElement(
					"Keyboard_Layout" ).text();
			
			// Boot Device
			QString tmp_str = Child_Element.firstChildElement(
					"Boot_Device" ).text();
			
			if( tmp_str == "FDD" )
			{
				Boot_Device = VM::Boot_From_FDD;
			}
			else if( tmp_str == "CDROM" )
			{
				Boot_Device = VM::Boot_From_CDROM;
			}
			else if( tmp_str == "HDD" )
			{
				Boot_Device = VM::Boot_From_HDD;
			}
			else if( tmp_str == "Network" )
			{
				Boot_Device = VM::Boot_From_Network;
			}
			else if( tmp_str == "None" )
			{
				Boot_Device = VM::Boot_None;
			}
			else
			{
				Boot_Device = VM::Boot_From_CDROM;
				AQWarning( "bool Virtual_Machine::Load_VM( const QString &file_name )",
						   "Use Default Boot Device: CD-ROM" );
			}
			
			// Video Card
			Video_Card = Child_Element.firstChildElement(
					"Video_Card" ).text();
			
			// KQEMU Mode ( Acseleration )
			tmp_str = Child_Element.firstChildElement(
					"KQEMU_Mode" ).text();
			
			if( tmp_str == "Enabled" )
			{
				KQEMU_Mode = VM::KQEMU_Enabled;
			}
			else if( tmp_str == "Disabled" )
			{
				KQEMU_Mode = VM::KQEMU_Disabled;
			}
			else if( tmp_str == "Full" )
			{
				KQEMU_Mode = VM::KQEMU_Full;
			}
			else if( tmp_str == "Default" )
			{
				KQEMU_Mode = VM::KQEMU_Default;
			}
			else
			{
				KQEMU_Mode = VM::KQEMU_Enabled;
				AQWarning( "bool Virtual_Machine::Load_VM( const QString &file_name )",
						   "KQEMU_Mode Invalid! Use Default!" );
			}
			
			QDomElement Second_Element;
			
			// Audio Cards
			Second_Element = Child_Element.firstChildElement( "Audio_Cards" );
			
			VM::Sound_Cards snd_card;
			
			// Audio_sb16
			snd_card.Audio_sb16 = Second_Element.firstChildElement(
					"Audio_sb16" ).text() == "true";
			
			// Audio_es1370
			snd_card.Audio_es1370 = Second_Element.firstChildElement(
					"Audio_es1370" ).text() == "true" ;
			
			// Audio_Adlib
			snd_card.Audio_Adlib = Second_Element.firstChildElement(
					"Audio_Adlib" ).text() == "true";
			
			// Audio_PC_Speaker
			snd_card.Audio_PC_Speaker = Second_Element.firstChildElement(
					"Audio_PC_Speaker" ).text() == "true";
			
			// Audio_GUS
			snd_card.Audio_GUS = Second_Element.firstChildElement(
					"Audio_GUS" ).text() == "true";
			
			// Audio_AC97
			snd_card.Audio_AC97 = Second_Element.firstChildElement(
					"Audio_AC97" ).text() == "true";
			
			Set_Audio_Cards( snd_card );
			
			// Check Free RAM
			Check_Free_RAM = (Child_Element.firstChildElement(
					"Check_Free_RAM" ).text() == "true");
			
			// Memory Size ( RAM )
			Memory_Size = Child_Element.firstChildElement(
					"Memory_Size" ).text().toInt();
			
			// Fullscreen
			Fullscreen = (Child_Element.firstChildElement(
					"Fullscreen" ).text() == "true");
			
			// Win2K_Hack
			Win2K_Hack = (Child_Element.firstChildElement(
					"Win2K_Hack" ).text() == "true");
			
			// Localtime
			Local_Time = (Child_Element.firstChildElement(
					"Local_Time" ).text() == "true");
			
			// Check FDD Boot Sector
			Check_FDD_Boot_Sector = (Child_Element.firstChildElement(
					"Check_FDD_Boot_Sector" ).text() == "true");
			
			// ACPI
			ACPI = (Child_Element.firstChildElement(
					"ACPI" ).text() == "true");
			
			// Snapshot_Mode
			Snapshot_Mode = (Child_Element.firstChildElement(
					"Snapshot_Mode" ).text() == "true");
			
			// Start_CPU
			Start_CPU = (Child_Element.firstChildElement(
					"Start_CPU" ).text() == "true");
			
			// QEMU_Log
			QEMU_Log = (Child_Element.firstChildElement(
					"QEMU_Log" ).text() == "true");
			
			// No_Reboot
			No_Reboot = (Child_Element.firstChildElement(
					"No_Reboot" ).text() == "true");
			
			// Floppy and CD-ROM
			if( template_mode &&
				Template_Opts ^ Create_Template_Window::Template_Save_FDD_CD )
			{
				// Floppy 0
				FD0.Set_Enabled( false );
				FD0.Set_Host_File_Name( "" );
				FD0.Set_Image_File_Name( "" );
				FD0.Set_Host_Device( true );
				
				// Floppy 1
				FD1.Set_Enabled( false );
				FD1.Set_Host_File_Name( "" );
				FD1.Set_Image_File_Name( "" );
				FD1.Set_Host_Device( true );
				
				// CD-ROM
				CD_ROM.Set_Enabled( false );
				CD_ROM.Set_Host_File_Name( "" );
				CD_ROM.Set_Image_File_Name( "" );
				CD_ROM.Set_Host_Device( true );
			}
			else
			{
				// Floppy 0
				Second_Element = Child_Element.firstChildElement( "FD0" );
				
				FD0.Set_Enabled( (Second_Element.firstChildElement(
						"Enabled" ).text() == "true") );
				
				FD0.Set_Host_File_Name( Second_Element.firstChildElement(
						"Host_File_Name" ).text() );
				
				FD0.Set_Image_File_Name( Second_Element.firstChildElement(
						"Image_File_Name" ).text() );
				
				FD0.Set_Host_Device( (Second_Element.firstChildElement(
						"Host_Device" ).text() == "true") );
				
				// Floppy 1
				Second_Element = Child_Element.firstChildElement( "FD1" );
				
				FD1.Set_Enabled( (Second_Element.firstChildElement(
						"Enabled" ).text() == "true") );
				
				FD1.Set_Host_File_Name( Second_Element.firstChildElement(
						"Host_File_Name" ).text() );
				
				FD1.Set_Image_File_Name( Second_Element.firstChildElement(
						"Image_File_Name" ).text() );
				
				FD1.Set_Host_Device( (Second_Element.firstChildElement(
						"Host_Device" ).text() == "true") );
				
				// CD-ROM
				Second_Element = Child_Element.firstChildElement( "CD_ROM" );
				
				CD_ROM.Set_Enabled( (Second_Element.firstChildElement(
						"Enabled" ).text() == "true") );
				
				CD_ROM.Set_Host_File_Name( Second_Element.firstChildElement(
						"Host_File_Name" ).text() );
				
				CD_ROM.Set_Image_File_Name( Second_Element.firstChildElement(
						"Image_File_Name" ).text() );
				
				CD_ROM.Set_Host_Device( (Second_Element.firstChildElement(
						"Host_Device" ).text() == "true") );
			}
			
			// Hard Disk's
			if( template_mode )
			{
				if( Template_Opts | Create_Template_Window::Template_Save_HDD )
				{
					// HDA
					Second_Element = Child_Element.firstChildElement( "HDA" );
					
					HDA.Set_Enabled( (Second_Element.firstChildElement(
							"Enabled" ).text() == "true") );
					
					HDA.Set_Virtual_Size( HDA.String_to_Device_Size(Second_Element.firstChildElement(
							"Size" ).text()) );
					
					HDA.Set_Image_Format( Second_Element.firstChildElement(
							"Format" ).text() );
					
					// HDB
					Second_Element = Child_Element.firstChildElement( "HDB" );
					
					HDB.Set_Enabled( (Second_Element.firstChildElement(
							"Enabled" ).text() == "true") );
					
					HDB.Set_Virtual_Size( HDB.String_to_Device_Size(Second_Element.firstChildElement(
							"Size" ).text()) );
					
					HDB.Set_Image_Format( Second_Element.firstChildElement(
							"Format" ).text() );
					
					// HDC
					Second_Element = Child_Element.firstChildElement( "HDC" );
					
					HDC.Set_Enabled( (Second_Element.firstChildElement(
							"Enabled" ).text() == "true") );
					
					HDC.Set_Virtual_Size( HDC.String_to_Device_Size(Second_Element.firstChildElement(
							"Size" ).text()) );
					
					HDC.Set_Image_Format( Second_Element.firstChildElement(
							"Format" ).text() );
					
					// HDD
					Second_Element = Child_Element.firstChildElement( "HDD" );
					
					HDD.Set_Enabled( (Second_Element.firstChildElement(
							"Enabled" ).text() == "true") );
					
					HDD.Set_Virtual_Size( HDD.String_to_Device_Size(Second_Element.firstChildElement(
							"Size" ).text()) );
					
					HDD.Set_Image_Format( Second_Element.firstChildElement(
							"Format" ).text() );
				}
				else
				{
					// HDA
					Second_Element = Child_Element.firstChildElement( "HDA" );
					HDA.Set_Enabled( false );
					HDA.Set_Image_File_Name( "" );
					
					// HDB
					Second_Element = Child_Element.firstChildElement( "HDB" );
					HDB.Set_Enabled( false );
					HDB.Set_Image_File_Name( "" );
				
					// HDC
					Second_Element = Child_Element.firstChildElement( "HDC" );
					HDC.Set_Enabled( false );
					HDC.Set_Image_File_Name( "" );
				
					// HDD
					Second_Element = Child_Element.firstChildElement( "HDD" );
					HDD.Set_Enabled( false );
					HDD.Set_Image_File_Name( "" );
				}
			}
			else
			{
				// HDA
				Second_Element = Child_Element.firstChildElement( "HDA" );
				
				HDA.Set_Enabled( (Second_Element.firstChildElement(
						"Enabled" ).text() == "true") );
				
				HDA.Set_Image_File_Name( Second_Element.firstChildElement(
						"Image_File_Name" ).text() );
				
				// HDB
				Second_Element = Child_Element.firstChildElement( "HDB" );
				
				HDB.Set_Enabled( (Second_Element.firstChildElement(
						"Enabled" ).text() == "true") );
				
				HDB.Set_Image_File_Name( Second_Element.firstChildElement(
						"Image_File_Name" ).text() );
				
				// HDC
				Second_Element = Child_Element.firstChildElement( "HDC" );
				
				HDC.Set_Enabled( (Second_Element.firstChildElement(
						"Enabled" ).text() == "true") );
				
				HDC.Set_Image_File_Name( Second_Element.firstChildElement(
						"Image_File_Name" ).text() );
				
				// HDD
				Second_Element = Child_Element.firstChildElement( "HDD" );
				
				HDD.Set_Enabled( (Second_Element.firstChildElement(
						"Enabled" ).text() == "true") );
				
				HDD.Set_Image_File_Name( Second_Element.firstChildElement(
						"Image_File_Name" ).text() );
			}
			
			// Snapshots
			int Snapshots_Count = Child_Element.firstChildElement(
					"Snapshots_Count" ).text().toInt();
			
			for( int sx = 0; sx < Snapshots_Count; ++sx )
			{
				Second_Element = Child_Element.firstChildElement(
						"Snapshot_" + QString::number(sx) );
				
				VM_Snapshot tmp_snapshot;
				
				// Tag
				tmp_snapshot.Set_Tag( Second_Element.firstChildElement("Tag").text() );
				
				// Name
				tmp_snapshot.Set_Name( Second_Element.firstChildElement("Name").text() );
				
				// Description
				tmp_snapshot.Set_Description( Second_Element.firstChildElement("Description").text() );
				
				// add snapshot
				Snapshots << tmp_snapshot;
			}
			
			// Storage Devices
			int Storage_Device_Count = Child_Element.firstChildElement(
					"Storage_Device_Count" ).text().toInt();
			
			for( int sx = 0; sx < Storage_Device_Count; ++sx )
			{
				Second_Element = Child_Element.firstChildElement(
						"Storage_Device_" + QString::number(sx) );
				
				VM_Storage_Device tmp_device;
				
				// Use File Path
				tmp_device.Use_File_Path( Second_Element.firstChildElement(
										  "Use_File_Path").text() == "true" );
				
				// File Path
				tmp_device.Set_File_Path( Second_Element.firstChildElement("File_Path").text() );
				
				// Use Interface
				tmp_device.Use_Interface( Second_Element.firstChildElement(
										  "Use_Interface").text() == "true" );
				
				// Interface
				QString interface_str = Second_Element.firstChildElement( "Interface" ).text();
				
				if( interface_str == "IDE" )
				{
					tmp_device.Set_Interface( VM::DI_IDE );
				}
				else if( interface_str == "SCSI" )
				{
					tmp_device.Set_Interface( VM::DI_SCSI );
				}
				else if( interface_str == "SD" )
				{
					tmp_device.Set_Interface( VM::DI_SD );
				}
				else if( interface_str == "MTD" )
				{
					tmp_device.Set_Interface( VM::DI_MTD );
				}
				else if( interface_str == "Floppy" )
				{
					tmp_device.Set_Interface( VM::DI_Floppy );
				}
				else if( interface_str == "PFlash" )
				{
					tmp_device.Set_Interface( VM::DI_PFlash );
				}
				else
				{
					AQError( "bool Virtual_Machine::Load_VM( const QString &file_name )",
							 "Storage Device Interface Default Section!" );
				}
				
				// Use Bus Unit
				tmp_device.Use_Bus_Unit( Second_Element.firstChildElement(
										 "Use_Bus_Unit").text() == "true" );
				
				// Bus
				tmp_device.Set_Bus( Second_Element.firstChildElement("Bus").text().toInt() );
				
				// Unit
				tmp_device.Set_Bus( Second_Element.firstChildElement("Unit").text().toInt() );
				
				// Use Index
				tmp_device.Use_Index( Second_Element.firstChildElement(
									  "Use_Index").text() == "true" );
				
				// Index
				tmp_device.Set_Index( Second_Element.firstChildElement("Index").text().toInt() );
				
				// Use Media
				tmp_device.Use_Media( Second_Element.firstChildElement(
									  "Use_Media").text() == "true" );
				
				// Media
				QString media_str = Second_Element.firstChildElement( "Media" ).text();
				
				if( media_str == "Disk" )
				{
					tmp_device.Set_Index( VM::DM_Disk );
				}
				else if( media_str == "CD_ROM" )
				{
					tmp_device.Set_Index( VM::DM_CD_ROM );
				}
				else
				{
					AQError( "bool Virtual_Machine::Load_VM( const QString &file_name )",
							 "Storage Device Media Default Section!" );
				}
				
				// Use hdachs
				tmp_device.Use_hdachs( Second_Element.firstChildElement(
									   "Use_hdachs").text() == "true" );
				
				// Cyls
				tmp_device.Set_Cyls( Second_Element.firstChildElement("Cyls").text().toULongLong() );
				
				// Heads
				tmp_device.Set_Heads( Second_Element.firstChildElement("Heads").text().toULongLong() );
				
				// Secs
				tmp_device.Set_Secs( Second_Element.firstChildElement("Secs").text().toULongLong() );
				
				// Trans
				tmp_device.Set_Cyls( Second_Element.firstChildElement("Trans").text().toULongLong() );
				
				// Snapshot
				tmp_device.Set_Snapshot( Second_Element.firstChildElement(
										 "Snapshot").text() == "true" );
				
				// Cache
				tmp_device.Set_Cache( Second_Element.firstChildElement(
									  "Cache").text() == "true" );
				
				// Add Device
				Storage_Devices << tmp_device;
			}
			
			// Use Network
			Use_Network = (Child_Element.firstChildElement(
					"Use_Network" ).text() == "true");
			
			// Use Redirections
			Use_Redirections = (Child_Element.firstChildElement(
					"Use_Redirections" ).text() == "true");
			
			// Network Cards Count
			int NetCardsCount = Child_Element.firstChildElement(
					"Network_Cards_Count" ).text().toInt();
			
			// Network Cards...
			for( int nx = 0; nx < NetCardsCount; nx++ )
			{
				Second_Element = Child_Element.firstChildElement(
						"Network_Card_" + QString::number(nx) );
				
				VM_Net_Card tmp_card;
				
				// Card Model
				tmp_card.Set_Card_Model(
						Second_Element.firstChildElement( "Card_Model" ).text() );
				
				tmp_str = Second_Element.firstChildElement( "Network_Mode" ).text();
				
				// Network Mode
				if( tmp_str == "None" )
				{
					tmp_card.Set_Net_Mode( VM::Net_Mode_None );
				}
				else if( tmp_str == "Usermode" )
				{
					tmp_card.Set_Net_Mode( VM::Net_Mode_Usermode );
				}
				else if( tmp_str == "Tuntap" )
				{
					tmp_card.Set_Net_Mode( VM::Net_Mode_Tuntap );
				}
				else if( tmp_str == "Tuntapfd" )
				{
					tmp_card.Set_Net_Mode( VM::Net_Mode_Tuntapfd );
				}
				else if( tmp_str == "Tcplisten" )
				{
					tmp_card.Set_Net_Mode( VM::Net_Mode_Tcplisten );
				}
				else if( tmp_str == "Tcpfd" )
				{
					tmp_card.Set_Net_Mode( VM::Net_Mode_Tcpfd );
				}
				else if( tmp_str == "Tcpconnect" )
				{
					tmp_card.Set_Net_Mode( VM::Net_Mode_Tcpconnect );
				}
				else if( tmp_str == "Multicast" )
				{
					tmp_card.Set_Net_Mode( VM::Net_Mode_Multicast );
				}
				else if( tmp_str == "Multicastfd" )
				{
					tmp_card.Set_Net_Mode( VM::Net_Mode_Multicastfd );
				}
				else
				{
					tmp_card.Set_Net_Mode( VM::Net_Mode_Dummy );
					AQWarning( "bool Virtual_Machine::Load_VM( const QString &file_name )",
							   "Net Card Network Mode Invalid! Use Default!" );
				}
				
				// Hostname
				tmp_card.Set_Hostname(
						Second_Element.firstChildElement( "Hostname" ).text() );
				
				// IP Address
				tmp_card.Set_IP_Address(
						Second_Element.firstChildElement( "IP_Address" ).text() );
				
				// MAC Address
				tmp_card.Set_MAC_Address(
						Second_Element.firstChildElement( "MAC_Address" ).text() );
				
				// Port
				tmp_card.Set_Port(
						Second_Element.firstChildElement( "Port" ).text().toInt() );
				
				// VLAN
				tmp_card.Set_VLAN(
						Second_Element.firstChildElement( "VLAN" ).text().toInt() );
				
				// Use TUN TAP Script
				tmp_card.Set_Use_TUN_TAP_Script( !
						(Second_Element.firstChildElement( "Use_TUN_TAP_Script" ).text() == "false") );
				
				// TUN TAP Script
				tmp_card.Set_TUN_TAP_Script(
						Second_Element.firstChildElement( "TUN_TAP_Script" ).text() );
				
				// Interface Name
				tmp_card.Set_Interface_Name(
						Second_Element.firstChildElement( "Interface_Name" ).text() );
				
				// File Descriptor
				tmp_card.Set_File_Descriptor(
						Second_Element.firstChildElement( "File_Descriptor" ).text().toInt() );
				
				Add_Network_Card( tmp_card );
			}
			
			// Redirections count
			int RedirsCount = Child_Element.firstChildElement(
					"Redirections_Count" ).text().toInt();
			
			// Network Redirections...
			for( int rx = 0; rx < RedirsCount; rx++ )
			{
				Second_Element = Child_Element.firstChildElement(
						"Network_Redirections_" + QString::number(rx) );
				
				VM_Redirection tmp_redir;
				
				tmp_redir.Set_Protocol(
						Second_Element.firstChildElement( "Protocol" ).text() );
				
				tmp_redir.Set_Host_Port(
						(Second_Element.firstChildElement( "Host_Port" ).text().toInt()) );
				
				tmp_redir.Set_Guest_IP(
						Second_Element.firstChildElement( "Guest_IP" ).text() );
				
				tmp_redir.Set_Guest_Port(
						Second_Element.firstChildElement( "Guest_Port" ).text().toInt() );
				
				Add_Network_Redirection( tmp_redir );
			}
			
			// TFTP Prefix
			TFTP_Prefix = Child_Element.firstChildElement( "TFTP_Prefix" ).text();
			
			// SMB Directory
			SMB_Directory = Child_Element.firstChildElement( "SMB_Directory" ).text();
			
			// Serial Port
			Second_Element = Child_Element.firstChildElement( "Serial_Port" );
			
			tmp_str = Second_Element.firstChildElement( "Port_Redirection" ).text();
			
			if( tmp_str == "vc" )
			{
				Serial_Port.Set_Port_Redirection( VM::PR_vc );
			}
			else if( tmp_str == "pty" )
			{
				Serial_Port.Set_Port_Redirection( VM::PR_pty );
			}
			else if( tmp_str == "none" )
			{
				Serial_Port.Set_Port_Redirection( VM::PR_none );
			}
			else if( tmp_str == "null" )
			{
				Serial_Port.Set_Port_Redirection( VM::PR_null );
			}
			else if( tmp_str == "dev" )
			{
				Serial_Port.Set_Port_Redirection( VM::PR_dev );
			}
			else if( tmp_str == "host_port" )
			{
				Serial_Port.Set_Port_Redirection( VM::PR_host_port );
			}
			else if( tmp_str == "file" )
			{
				Serial_Port.Set_Port_Redirection( VM::PR_file );
			}
			else if( tmp_str == "stdio" )
			{
				Serial_Port.Set_Port_Redirection( VM::PR_stdio );
			}
			else if( tmp_str == "pipe" )
			{
				Serial_Port.Set_Port_Redirection( VM::PR_pipe );
			}
			else if( tmp_str == "udp" )
			{
				Serial_Port.Set_Port_Redirection( VM::PR_udp );
			}
			else if( tmp_str == "tcp" )
			{
				Serial_Port.Set_Port_Redirection( VM::PR_tcp );
			}
			else if( tmp_str == "telnet" )
			{
				Serial_Port.Set_Port_Redirection( VM::PR_telnet );
			}
			else if( tmp_str == "unix" )
			{
				Serial_Port.Set_Port_Redirection( VM::PR_unix );
			}
			else
			{
				Serial_Port.Set_Port_Redirection( VM::PR_Default );
			}
			
			// Parametrs Line
			Serial_Port.Set_Parametrs_Line(
					Second_Element.firstChildElement( "Parametrs" ).text() );
			
			// Parallel Port
			Second_Element = Child_Element.firstChildElement( "Parallel_Port" );
			
			tmp_str = Second_Element.firstChildElement( "Port_Redirection" ).text();
			
			if( tmp_str == "vc" )
			{
				Parallel_Port.Set_Port_Redirection( VM::PR_vc );
			}
			else if( tmp_str == "pty" )
			{
				Parallel_Port.Set_Port_Redirection( VM::PR_pty );
			}
			else if( tmp_str == "none" )
			{
				Parallel_Port.Set_Port_Redirection( VM::PR_none );
			}
			else if( tmp_str == "null" )
			{
				Parallel_Port.Set_Port_Redirection( VM::PR_null );
			}
			else if( tmp_str == "dev" )
			{
				Parallel_Port.Set_Port_Redirection( VM::PR_dev );
			}
			else if( tmp_str == "host_port" )
			{
				Parallel_Port.Set_Port_Redirection( VM::PR_host_port );
			}
			else if( tmp_str == "file" )
			{
				Parallel_Port.Set_Port_Redirection( VM::PR_file );
			}
			else if( tmp_str == "stdio" )
			{
				Parallel_Port.Set_Port_Redirection( VM::PR_stdio );
			}
			else if( tmp_str == "pipe" )
			{
				Parallel_Port.Set_Port_Redirection( VM::PR_pipe );
			}
			else if( tmp_str == "udp" )
			{
				Parallel_Port.Set_Port_Redirection( VM::PR_udp );
			}
			else if( tmp_str == "tcp" )
			{
				Parallel_Port.Set_Port_Redirection( VM::PR_tcp );
			}
			else if( tmp_str == "telnet" )
			{
				Parallel_Port.Set_Port_Redirection( VM::PR_telnet );
			}
			else if( tmp_str == "unix" )
			{
				Parallel_Port.Set_Port_Redirection( VM::PR_unix );
			}
			else
			{
				Parallel_Port.Set_Port_Redirection( VM::PR_Default );
			}
			
			// Parametrs Line
			Parallel_Port.Set_Parametrs_Line(
					Second_Element.firstChildElement("Parametrs").text() );
			
			// Enable USB Hub
			USB_Hub = (Child_Element.firstChildElement(
					"USB_Hub" ).text() == "true");
			
			// USB Count
			int usb_count = Child_Element.firstChildElement(
					"USB_Ports_Count" ).text().toInt();
			
			// USB Devices
			for( int ux = 0; ux < usb_count; ++ux )
			{
				Second_Element = Child_Element.firstChildElement(
						"USB_Port_" + QString::number(ux) );
				
				VM_USB tmp_usb;
				
				tmp_usb.Set_Manufacturer_Name(
						Second_Element.firstChildElement( "Manufacturer_Name" ).text() );
				
				tmp_usb.Set_Product_Name(
						Second_Element.firstChildElement( "Product_Name" ).text() );
				
				tmp_usb.Set_Vendor_ID(
						Second_Element.firstChildElement( "Vendor_ID" ).text() );
				
				tmp_usb.Set_Product_ID(
						Second_Element.firstChildElement( "Product_ID" ).text() );
				
				USB_Ports << tmp_usb;
			}
			
			// Linux Boot
			Linux_Boot = (Child_Element.firstChildElement(
					"Linux_Boot" ).text() == "true" );
			
			// bzImage Path
			bzImage_Path = Child_Element.firstChildElement(
					"bzImage_Path" ).text();
			
			// Initrd Path
			Initrd_Path = Child_Element.firstChildElement(
					"Initrd_Path" ).text();
			
			// Kernel Command Line Arguments
			Kernel_ComLine = Child_Element.firstChildElement(
					"Kernel_ComLine" ).text();
			
			// Use ROM File
			Use_ROM_File = ( Child_Element.firstChildElement(
					"Use_ROM_File").text() == "true" );
			
			// ROM File Path
			ROM_File =  Child_Element.firstChildElement(
					"ROM_File" ).text();
			
			// Use MTDBlock File
			MTDBlock = (Child_Element.firstChildElement(
					"Use_MTDBlock_File" ).text() == "true" );
			
			// MTDBlock File
			MTDBlock_File = Child_Element.firstChildElement(
					"MTDBlock_File" ).text();
			
			// Use SecureDigital File
			SecureDigital = (Child_Element.firstChildElement(
					"Use_SecureDigital_File" ).text() == "true" );
			
			// SecureDigital File
			SecureDigital_File = Child_Element.firstChildElement(
					"SecureDigital_File" ).text();
			
			// Use PFlash File
			PFlash = (Child_Element.firstChildElement(
					"Use_PFlash_File" ).text() == "true" );
			
			// PFlash File
			PFlash_File = Child_Element.firstChildElement(
					"PFlash_File" ).text();
			
			// Use KVM IRQChip
			KVM_IRQChip = (Child_Element.firstChildElement(
					"Use_KVM_IRQChip" ).text() == "true" );
			
			// Use No KVM Pit
			No_KVM_Pit = (Child_Element.firstChildElement(
					"Use_No_KVM_Pit" ).text() == "true" );
			
			// Use KVM Shadow Memory
			KVM_Shadow_Memory = (Child_Element.firstChildElement(
					"Use_KVM_Shadow_Memory" ).text() == "true" );
			
			// KVM_Shadow_Memory_Size
			KVM_Shadow_Memory_Size = (uint)Child_Element.firstChildElement(
					"KVM_Shadow_Memory_Size" ).text().toInt();
			
			// Init Graphic Mode
			Second_Element = Child_Element.firstChildElement( "Init_Graphic_Mode" );
			
			// Enabled
			Init_Graphic_Mode.Set_Enabled(
					Second_Element.firstChildElement("Enabled").text() == "true" );
			
			// Width
			Init_Graphic_Mode.Set_Width(
					Second_Element.firstChildElement( "Width" ).text().toInt() );
			
			// Height
			Init_Graphic_Mode.Set_Height(
					Second_Element.firstChildElement( "Height" ).text().toInt() );
			
			// Depth
			Init_Graphic_Mode.Set_Depth(
					Second_Element.firstChildElement( "Depth" ).text().toInt() );
			
			// Use No Frame
			No_Frame = (Child_Element.firstChildElement(
					"Use_No_Frame" ).text() == "true" );
			
			// Use Alt Grab
			Alt_Grab = (Child_Element.firstChildElement(
					"Use_Alt_Grab" ).text() == "true" );
			
			// Use No Quit
			No_Quit = (Child_Element.firstChildElement(
					"Use_No_Quit" ).text() == "true");
			
			// Use Portrait
			Portrait = (Child_Element.firstChildElement(
					"Use_Portrait" ).text() == "true");
			
			// Start Date
			Start_Date = (Child_Element.firstChildElement(
					"Use_Start_Date" ).text() == "true");
			
			// Start DateTime
			Start_DateTime = QDateTime::fromString(
					Child_Element.firstChildElement("Start_Date").text(),
					"dd.MM.yyyy HH:mm:ss" );
			
			// Use VNC
			VNC = (Child_Element.firstChildElement(
					"Use_VNC" ).text() == "true");
			
			// VNC Socket Mode
			VNC_Socket_Mode = (Child_Element.firstChildElement(
					"VNC_Socket_Mode" ).text() == "true");
			
			// VNC Unix Socket Path
			VNC_Unix_Socket_Path = Child_Element.firstChildElement(
					"VNC_Unix_Socket_Path" ).text();
			
			// VNC Display Number
			VNC_Display_Number = (uint)Child_Element.firstChildElement(
					"VNC_Display_Number" ).text().toInt();
			
			// Use VNC Password
			VNC_Password = (Child_Element.firstChildElement(
					"Use_VNC_Password" ).text() == "true");
			
			// Use VNC TLS
			VNC_TLS = (Child_Element.firstChildElement(
					"Use_VNC_TLS" ).text() == "true");
			
			// Use VNC x509
			VNC_x509 = (Child_Element.firstChildElement(
					"Use_VNC_x509" ).text() == "true");
			
			// VNC x509 Folder Path
			VNC_x509_Folder_Path = Child_Element.firstChildElement(
					"VNC_x509_Folder_Path" ).text();
			
			// Use VNC x509verify
			VNC_x509verify = (Child_Element.firstChildElement(
					"Use_VNC_x509verify" ).text() == "true");
			
			// VNC x509verify Folder Path
			VNC_x509verify_Folder_Path = Child_Element.firstChildElement(
					"VNC_x509verify_Folder_Path" ).text();
			
			// GDB
			GDB = (Child_Element.firstChildElement(
					"GDB" ).text() == "true" );
			
			GDB_Port = (uint)Child_Element.firstChildElement(
					"GDB_Port" ).text().toInt();
			
			// Additional Arguments
			Additional_Args = Child_Element.firstChildElement(
					"Additional_Args" ).text();
			
			return true;
		}
	}
}

bool Virtual_Machine::Save_VM()
{
	return Create_VM_File( VM_XML_File_Path, false );
}

bool Virtual_Machine::Save_VM( const QString &file_name )
{
	return Create_VM_File( file_name, false );
}

QStringList Virtual_Machine::Build_QEMU_Args()
{
	QStringList Args;
	
	QString qemu_version = Settings.value("QEMU_Version", "Old").toString();
	
	Args << "-monitor" << "stdio";
	
	// Saved?
	if( ! Start_Snapshot_Tag.isEmpty() )
	{
		Args << "-loadvm" << Start_Snapshot_Tag;
		Load_Mode = true;
	}
	else if( State == VM::VMS_Saved )
	{
		Args << "-loadvm" << "aqemu_save";
		//Load_Mode = true;
		Load_Mode = false;
	}
	else
	{
		Load_Mode = false;
	}
	
	int sys_index = -1;
	
	// Computer Type
	for( int cx = 0; cx < System_Info::VM_Computers.count(); ++cx )
	{
		if( Computer_Type == System_Info::VM_Computers[cx].System.QEMU_Name )
		{
			sys_index = cx;
		}
	}
	
	if( sys_index == -1 )
	{
		AQError( "QStringList Virtual_Machine::Build_QEMU_Args()",
				 "System Index Invalid!" );
		return QStringList();
	}
	
	// SMP Mode
	if( System_Info::VM_Computers[sys_index].PSO_SMP )
	{
		if( SMP_CPU_Count > 1 )
		{
			Args << "-smp" << QString::number( SMP_CPU_Count, 10 );
		}
	}
	
	// CPU Model
	if( qemu_version == "0.9.1" ||
		qemu_version == "New"  )
	{
		if( ! CPU_Type.isEmpty() )
		{
			Args << "-cpu" << CPU_Type;
		}
	}
	
	// Audio
	if( System_Info::VM_Computers[sys_index].Audio_Card_List.Audio_sb16 ||
		System_Info::VM_Computers[sys_index].Audio_Card_List.Audio_es1370 ||
		System_Info::VM_Computers[sys_index].Audio_Card_List.Audio_Adlib ||
		System_Info::VM_Computers[sys_index].Audio_Card_List.Audio_PC_Speaker ||
		System_Info::VM_Computers[sys_index].Audio_Card_List.Audio_GUS ||
		System_Info::VM_Computers[sys_index].Audio_Card_List.Audio_AC97 )
	{
		if( Audio_Card.Audio_sb16 || Audio_Card.Audio_es1370 ||
			Audio_Card.Audio_Adlib || Audio_Card.Audio_PC_Speaker ||
			Audio_Card.Audio_GUS || Audio_Card.Audio_AC97 ) // enable sound?
		{
			Args << "-soundhw";
			
			QStringList audio_list;
			
			if( Audio_Card.Audio_sb16 &&
				System_Info::VM_Computers[sys_index].Audio_Card_List.Audio_sb16 )
			{
				audio_list << "sb16";
			}
			
			if( Audio_Card.Audio_es1370 &&
				System_Info::VM_Computers[sys_index].Audio_Card_List.Audio_es1370 )
			{
				audio_list << "es1370";
			}
			
			if( Audio_Card.Audio_Adlib &&
				System_Info::VM_Computers[sys_index].Audio_Card_List.Audio_Adlib )
			{
				audio_list << "adlib";
			}
			
			if( Audio_Card.Audio_PC_Speaker &&
				System_Info::VM_Computers[sys_index].Audio_Card_List.Audio_PC_Speaker )
			{
				audio_list << "pcspk";
			}
			
			if( Audio_Card.Audio_GUS &&
				System_Info::VM_Computers[sys_index].Audio_Card_List.Audio_GUS )
			{
				audio_list << "gus";
			}
			
			if( Audio_Card.Audio_AC97 &&
				System_Info::VM_Computers[sys_index].Audio_Card_List.Audio_AC97 )
			{
				audio_list << "ac97";
			}
			
			if( audio_list.count() == 1 )
			{
				Args << audio_list[ 0 ];
			}
			else
			{
				for( int ax = 0; ax < audio_list.count(); ++ax )
				{
					if( ax != audio_list.count()-1 ) // end card?
					{
						Args << audio_list[ ax ] + ",";
					}
					else
					{
						Args << audio_list[ ax ];
					}
				}
			}
		}
	}
	
	// Machine Type
	if( ! Machine_Type.isEmpty() )
	{
		Args << "-M" << Machine_Type;
	}
	
	// Keyboard Layout (language)
	if( Keyboard_Layout != "Default" )
		Args << "-k" << Get_Keyboard_Layout();
	
	// Video
	if( ! Video_Card.isEmpty() )
	{
		Args << Video_Card;
	}
	
	// Boot Device
	switch( Boot_Device )
	{
		case VM::Boot_From_FDD:
			Args << "-boot" << "a";
			break;
			
		case VM::Boot_From_CDROM:
			Args << "-boot" << "d";
			break;
			
		case VM::Boot_From_HDD:
			Args << "-boot" << "c";
			break;
			
		case VM::Boot_From_Network:
			Args << "-boot" << "n";
			break;
			
		default:
			break;
	}
	
	// Acseleration Mode
	if( System_Info::VM_Computers[sys_index].PSO_KVM == false &&
		System_Info::VM_Computers[sys_index].PSO_Kernel_KQEMU == true )
	{
		switch( KQEMU_Mode )
		{
			case VM::KQEMU_Disabled:
				Args << "-no-kqemu";
				break;
			
			case VM::KQEMU_Full:
				Args << "-kernel-kqemu";
				break;
			
			default:
				break;
		}
	}
	
	// KVM Options
	if( System_Info::VM_Computers[sys_index].PSO_KVM == true )
	{
		if( KVM_IRQChip )
		{
			Args << "-no-kvm-irqchip";
		}
		
		if( No_KVM_Pit )
		{
			Args << "-no-kvm-pit";
		}
		
		if( KVM_Shadow_Memory )
		{
			Args << "-kvm-shadow-memory" << QString::number( KVM_Shadow_Memory_Size );
		}
	}
	
	// Memory
	Args << "-m" << QString::number( Memory_Size, 10 );
	
	// full screen
	if( Fullscreen )
	{
		Args << "-full-screen";
	}
	
	// Win2000 Hack
	if( System_Info::VM_Computers[sys_index].PSO_Win2K_Hack )
	{
		if( Win2K_Hack ) Args << "-win2k-hack";
	}
	
	// No Check FDD boot sector
	if( System_Info::VM_Computers[sys_index].PSO_No_FB_Boot_Check )
	{
		if( ! Check_FDD_Boot_Sector ) Args << "-no-fd-bootchk";
	}
	
	// No ACPI
	if( System_Info::VM_Computers[sys_index].PSO_No_ACPI )
	{
		if( ! ACPI ) Args << "-no-acpi";
	}
	
	// Localtime
	if( Local_Time )
	{
		Args << "-localtime";
	}
	
	// Snapshot
	if( Snapshot_Mode )
	{
		Args << "-snapshot";
	}
	
	// Do not start CPU at startup
	if( ! Start_CPU )
	{
		Args << "-S";
	}
	
	// Enable QEMU Log
	if( QEMU_Log )
	{
		Args << "-d";
		
		if( Settings.value("QLOG/out_asm", "no").toString() == "yes" ) Args << "out_asm";
		if( Settings.value("QLOG/in_asm", "no").toString() == "yes" ) Args << "in_asm";
		if( Settings.value("QLOG/cpu", "no").toString() == "yes" ) Args << "cpu";
		if( Settings.value("QLOG/pcall", "no").toString() == "yes" ) Args << "pcall";
		if( Settings.value("QLOG/op_opt", "no").toString() == "yes" ) Args << "op_opt";
		if( Settings.value("QLOG/int", "no").toString() == "yes" ) Args << "int";
		if( Settings.value("QLOG/op", "no").toString() == "yes" ) Args << "op";
		if( Settings.value("QLOG/exec", "no").toString() == "yes" ) Args << "exec";
	}
	
	// Exit instead of rebooting
	if( No_Reboot )
	{
		Args << "-no-reboot";
	}
	
	// FD0
	if( FD0.Get_Enabled() )
	{
		if( FD0.Get_Host_Device() )
		{
			Args << "-fda" << FD0.Get_Host_File_Name();
		}
		else
		{
			if( QFile::exists(FD0.Get_Image_File_Name()) )
			{
				Args << "-fda" << FD0.Get_Image_File_Name();
			}
			else
			{
				AQGraphic_Error( "QStringList Virtual_Machine::Build_QEMU_Args()",
								 tr("Error!"), tr("FD0 Image File Not Exist! QEMU Cannot Run!"), false );
				return QStringList();
			}
		}
	}
	
	// FD1
	if( FD1.Get_Enabled() )
	{
		if( FD1.Get_Host_Device() )
		{
			Args << "-fdb" << FD1.Get_Host_File_Name();
		}
		else
		{
			if( QFile::exists(FD1.Get_Image_File_Name()) )
			{
				Args << "-fdb" << FD1.Get_Image_File_Name();
			}
			else
			{
				AQGraphic_Error( "QStringList Virtual_Machine::Build_QEMU_Args()",
								 tr("Error!"), tr("FD1 Image File Not Exist! QEMU Cannot Run!"), false );
				return QStringList();
			}
		}
	}
	
	// CD-ROM
	if( CD_ROM.Get_Enabled() )
	{
		if( CD_ROM.Get_Host_Device() )
		{
			Args << "-cdrom" << CD_ROM.Get_Host_File_Name();
		}
		else
		{
			if( QFile::exists(CD_ROM.Get_Image_File_Name()) )
			{
				Args << "-cdrom" << CD_ROM.Get_Image_File_Name();
			}
			else
			{
				AQGraphic_Error( "QStringList Virtual_Machine::Build_QEMU_Args()",
								 tr("Error!"), tr("CD-ROM Image File Not Exist! QEMU Cannot Run!"), false );
				return QStringList();
			}
		}
	}
	
	// HDA
	if( HDA.Get_Enabled() )
	{
		if( QFile::exists(HDA.Get_Image_File_Name()) )
		{
			Args << "-hda" << HDA.Get_Image_File_Name();
		}
		else
		{
			AQGraphic_Error( "QStringList Virtual_Machine::Build_QEMU_Args()",
							 tr("Error!"), tr("HDA Image File Not Exist! QEMU Cannot Run!"), false );
			return QStringList();
		}
	}
	
	// HDB
	if( HDB.Get_Enabled() )
	{
		if( QFile::exists(HDB.Get_Image_File_Name()) )
		{
			Args << "-hdb" << HDB.Get_Image_File_Name();
		}
		else
		{
			AQGraphic_Error( "QStringList Virtual_Machine::Build_QEMU_Args()",
							 tr("Error!"), tr("HDB Image File Not Exist! QEMU Cannot Run!"), false );
			return QStringList();
		}
	}
	
	// HDC
	if( HDC.Get_Enabled() )
	{
		if( QFile::exists(HDC.Get_Image_File_Name()) )
		{
			Args << "-hdc" << HDC.Get_Image_File_Name();
		}
		else
		{
			AQGraphic_Error( "QStringList Virtual_Machine::Build_QEMU_Args()",
							 tr("Error!"), tr("HDC Image File Not Exist! QEMU Cannot Run!"), false );
			return QStringList();
		}
	}
	
	// HDD
	if( HDD.Get_Enabled() )
	{
		if( QFile::exists(HDD.Get_Image_File_Name()) )
		{
			Args << "-hdd" << HDD.Get_Image_File_Name();
		}
		else
		{
			AQGraphic_Error( "QStringList Virtual_Machine::Build_QEMU_Args()",
							 tr("Error!"), tr("HDD Image File Not Exist! QEMU Cannot Run!"), false );
			return QStringList();
		}
	}
	
	// Storage Devices
	if( qemu_version == "0.9.1" || qemu_version == "New" )
	{
		if( Storage_Devices.count() > 0 )
		{
			for( int ix = 0; ix < Storage_Devices.count(); ++ix )
			{
				QStringList opt;
				
				// File
				if( Storage_Devices[ix].Use_File_Path() )
				{
					opt << "file=\"" + Storage_Devices[ix].Get_File_Path() + "\"";
				}
				
				// Interface
				if( Storage_Devices[ix].Use_Interface() )
				{
					switch( Storage_Devices[ix].Get_Interface() )
					{
						case VM::DI_IDE:
							opt << "if=ide";
							break;
						
						case VM::DI_SCSI:
							opt << "if=scsi";
							break;
							
						case VM::DI_SD:
							opt << "if=sd";
							break;
							
						case VM::DI_MTD:
							opt << "if=mtd";
							break;
							
						case VM::DI_Floppy:
							opt << "if=floppy";
							break;
							
						case VM::DI_PFlash:
							opt << "if=pflash";
							break;
							
						default:
							AQError( "QStringList Virtual_Machine::Build_QEMU_Args()",
									 "Storage Device Interface Default Section!" );
							break;
					}
				}
				
				// Bus, Unit
				if( Storage_Devices[ix].Use_Bus_Unit() )
				{
					opt << "bus=" + QString::number( Storage_Devices[ix].Get_Bus() );
					opt << "unit=" + QString::number( Storage_Devices[ix].Get_Unit() );
				}
				
				// Index
				if( Storage_Devices[ix].Use_Index() )
				{
					opt << "index=" + QString::number( Storage_Devices[ix].Get_Index() );
				}
				
				// Media
				if( Storage_Devices[ix].Use_Media() )
				{
					switch( Storage_Devices[ix].Get_Media() )
					{
						case VM::DM_Disk:
							opt << "media=disk";
							break;
							
						case VM::DM_CD_ROM:
							opt << "media=cdrom";
							break;
							
						default:
							AQError( "QStringList Virtual_Machine::Build_QEMU_Args()",
									 "Storage Device Media Default Section!" );
							break;
					}
				}
				
				// hdachs
				if( Storage_Devices[ix].Use_hdachs() )
				{
					opt << "cyls=" + QString::number( Storage_Devices[ix].Get_Cyls() );
					opt << "heads=" + QString::number( Storage_Devices[ix].Get_Heads() );
					opt << "secs=" + QString::number( Storage_Devices[ix].Get_Secs() );
					opt << "trans=" + QString::number( Storage_Devices[ix].Get_Trans() );
				}
				
				// Snapshot
				if( Storage_Devices[ix].Get_Snapshot() )
				{
					opt << "snapshot=on";
				}
				else
				{
					opt << "snapshot=off";
				}
				
				// Cache
				if( Storage_Devices[ix].Get_Cache() )
				{
					opt << "cache=on";
				}
				else
				{
					opt << "cache=off";
				}
				
				// Create Complete Drive String
				QString drive_str = "";
				
				for( int ox = 0; ox < opt.count(); ++ox )
				{
					drive_str += opt[ox];
					
					if( ox < opt.count() -1 ) drive_str += ",";
				}
				
				// Add to Args
				Args << "-drive" << drive_str;
			}
		}
		else
		{
			AQDebug( "QStringList Virtual_Machine::Build_QEMU_Args()",
					 "No Storage Devices." );
		}
	}
	
	// Network Tab. Redirections
	if( Use_Redirections )
	{
		Args << "-redir";
			
		QString redir_str = "";
			
		for( int rx = 0; rx < Get_Network_Redirections_Count(); rx++ )
		{
			redir_str = "";
				
			if( Get_Network_Redirection(rx).Get_Protocol() == "TCP" )
			{
				redir_str += "tcp:";
			}
			else if( Get_Network_Redirection(rx).Get_Protocol() == "UDP" )
			{
				redir_str += "udp:";
			}
			else
			{
				// Error!
				AQError( "QStringList Virtual_Machine::Build_QEMU_Args()",
						 "Redirection Protocol Invalid!" );
			}
				
			redir_str += QString::number( Get_Network_Redirection(rx).Get_Host_Port() ) + ":";
			redir_str += Get_Network_Redirection(rx).Get_Guest_IP() + ":";
			redir_str += QString::number( Get_Network_Redirection(rx).Get_Guest_Port() );
				
			Args << redir_str;
		}
	}
	
	// Network Cards
	if( Network_Cards.count() < 1 || Use_Network == false )
	{
		Args << "-net" << "none";
	}
	else
	{
		for( int nc = 0; nc < Network_Cards.count(); nc++ )
		{
			Args << "-net";
			QString nic_str = "nic,vlan=" + QString::number( Network_Cards[nc].Get_VLAN() );
			
			if( ! Network_Cards[nc].Get_MAC_Address().isEmpty() ) // Use MAC?
			{
				nic_str += ",macaddr=" + Network_Cards[nc].Get_MAC_Address();
			}
			
			if( ! Network_Cards[nc].Get_Card_Model().isEmpty() )
			{
				nic_str += ",model=" + Network_Cards[nc].Get_Card_Model();
			}
			
			Args << nic_str;
			
			// Net Modes
			QString tap_tmp;
			
			switch( Network_Cards[nc].Get_Net_Mode() )
			{
				case VM::Net_Mode_None:
					break;
					
				case VM::Net_Mode_Usermode:
					if( Network_Cards[nc].Get_Hostname().isEmpty() )
					{
						Args << "-net" << QString( "user,vlan=" + QString::number(Network_Cards[nc].Get_VLAN()) );
					}
					else
					{
						Args << "-net" << QString( "user,vlan=" + QString::number(Network_Cards[nc].Get_VLAN()) +
												   ",hostname=" + Network_Cards[nc].Get_Hostname() );
					}
					break;
					
				case VM::Net_Mode_Tuntap:
					Args << "-net" ;
					
					tap_tmp = QString( "tap,vlan=" + QString::number(Network_Cards[nc].Get_VLAN()) );
					
					if( ! Network_Cards[nc].Get_Interface_Name().isEmpty() )
					{
						tap_tmp += QString( ",ifname=" + Network_Cards[nc].Get_Interface_Name() );
					}
					
					if( ! Network_Cards[nc].Get_Use_TUN_TAP_Script() )
					{
						tap_tmp += QString( ",script=no" );
					}
					else
					{
						if( ! Network_Cards[nc].Get_TUN_TAP_Script().isEmpty() )
						{
							tap_tmp += QString( ",script=" + Network_Cards[nc].Get_TUN_TAP_Script() );
						}
					}
					
					Args << tap_tmp;
					break;
					
				case VM::Net_Mode_Tuntapfd:
					Args << "-net" << QString( "tap,vlan=" + QString::number(Network_Cards[nc].Get_VLAN()) +
									 ",fd=" + QString::number(Network_Cards[nc].Get_File_Descriptor()) );
					break;
					
				case VM::Net_Mode_Tcplisten:
					if( Network_Cards[nc].Get_IP_Address().isEmpty() )
					{
						Args << "-net" << QString( "socket,vlan=" + QString::number(Network_Cards[nc].Get_VLAN()) +
										 ",listen=:" + QString::number(Network_Cards[nc].Get_Port()) );
					}
					else
					{
						Args << "-net" << QString( "socket,vlan=" + QString::number(Network_Cards[nc].Get_VLAN()) +
										 ",listen=" + Network_Cards[nc].Get_IP_Address() +
										 QString::number(Network_Cards[nc].Get_Port()) );
					}
					break;
					
				case VM::Net_Mode_Tcpfd:
					Args << "-net" << QString( "socket,vlan=" + QString::number(Network_Cards[nc].Get_VLAN()) +
									 ",fd=" + QString::number(Network_Cards[nc].Get_File_Descriptor()) );
					break;
					
				case VM::Net_Mode_Tcpconnect:
					if( Network_Cards[nc].Get_IP_Address().isEmpty() )
					{
						Args << "-net" << QString( "socket,vlan=" + QString::number(Network_Cards[nc].Get_VLAN()) +
										 ",connect=:" + QString::number(Network_Cards[nc].Get_Port()) );
					}
					else
					{
						Args << "-net" << QString( "socket,vlan=" + QString::number(Network_Cards[nc].Get_VLAN()) +
										 ",connect=" + Network_Cards[nc].Get_IP_Address() +
										 ":" + QString::number(Network_Cards[nc].Get_Port()) );
					}
					break;
					
				case VM::Net_Mode_Multicast:
					if( Network_Cards[nc].Get_IP_Address().isEmpty() )
					{
						Args << "-net" << QString( "socket,vlan=" + QString::number(Network_Cards[nc].Get_VLAN()) +
										 ",mcast=:" + QString::number(Network_Cards[nc].Get_Port()) );
					}
					else
					{
						Args << "-net" << QString( "socket,vlan=" + QString::number(Network_Cards[nc].Get_VLAN()) +
										 ",mcast=" + Network_Cards[nc].Get_IP_Address() +
										 ":" + QString::number(Network_Cards[nc].Get_Port()) );
					}
					break;
					
				case VM::Net_Mode_Multicastfd:
					Args << "-net" << QString( "socket,vlan=" + QString::number(Network_Cards[nc].Get_VLAN()) +
							",fd=" + QString::number(Network_Cards[nc].Get_File_Descriptor()) );
					break;
					
				default:
					Args << "-net" << "none";
					break;
			}
		}
	}
	
	// TFTP Prefix
	if( ! TFTP_Prefix.isEmpty() )
	{
		Args << "-tftp" << TFTP_Prefix;
	}
	
	// SMB Dir
	if( ! SMB_Directory.isEmpty() )
	{
		Args << "-smb" << SMB_Directory;
	}
	
	// Ports Tabs
	switch( Serial_Port.Get_Port_Redirection() )
	{
		case VM::PR_vc:
			Args << "-serial" << "vc";
			break;
			
		case VM::PR_pty:
			Args << "-serial" << "pty";
			break;
			
		case VM::PR_none:
			Args << "-serial" << "none";
			break;
			
		case VM::PR_null:
			Args << "-serial" << "null";
			break;
			
		case VM::PR_dev:
			Args << "-serial" << Serial_Port.Get_Parametrs_Line();
			break;
			
		case VM::PR_host_port:
			Args << "-serial" << Serial_Port.Get_Parametrs_Line();
			break;
			
		case VM::PR_file:
			Args << "-serial" << Serial_Port.Get_Parametrs_Line();
			break;
			
		case VM::PR_stdio:
			Args << "-serial" << "stdio";
			break;
			
		case VM::PR_pipe:
			Args << "-serial" << Serial_Port.Get_Parametrs_Line();
			break;
			
		case VM::PR_udp:
			Args << "-serial" << Serial_Port.Get_Parametrs_Line();
			break;
			
		case VM::PR_tcp:
			Args << "-serial" << Serial_Port.Get_Parametrs_Line();
			break;
			
		case VM::PR_telnet:
			Args << "-serial" << Serial_Port.Get_Parametrs_Line();
			break;
			
		case VM::PR_unix:
			Args << "-serial" << Serial_Port.Get_Parametrs_Line();
			break;
			
		default:
			break;
	}
	
	// parallel port
	switch( Parallel_Port.Get_Port_Redirection() )
	{
		case VM::PR_vc:
			Args << "-parallel" << "vc";
			break;
			
		case VM::PR_pty:
			Args << "-parallel" << "pty";
			break;
			
		case VM::PR_none:
			Args << "-parallel" << "none";
			break;
			
		case VM::PR_null:
			Args << "-parallel" << "null";
			break;
			
		case VM::PR_dev:
			Args << "-parallel" << Parallel_Port.Get_Parametrs_Line();
			break;
			
		case VM::PR_host_port:
			Args << "-parallel" << Parallel_Port.Get_Parametrs_Line();
			break;
			
		case VM::PR_file:
			Args << "-parallel" << Parallel_Port.Get_Parametrs_Line();
			break;
			
		case VM::PR_stdio:
			Args << "-parallel" << "stdio";
			break;
			
		case VM::PR_pipe:
			Args << "-parallel" << Parallel_Port.Get_Parametrs_Line();
			break;
			
		case VM::PR_udp:
			Args << "-parallel" << Parallel_Port.Get_Parametrs_Line();
			break;
			
		case VM::PR_tcp:
			Args << "-parallel" << Parallel_Port.Get_Parametrs_Line();
			break;
			
		case VM::PR_telnet:
			Args << "-parallel" << Parallel_Port.Get_Parametrs_Line();
			break;
			
		case VM::PR_unix:
			Args << "-parallel" << Parallel_Port.Get_Parametrs_Line();
			break;
			
		default:
			break;
	}
	
	// USB
	if( Settings.value("Use_USB", "no").toString() == "no" )
	{
		AQDebug( "QStringList Virtual_Machine::Build_QEMU_Args()",
				 "USB Suttport Not Activated" );
	}
	else
	{
		if( USB_Hub )
		{
			Args << "-usb";
			
			if( USB_Ports.count() > 0 )
			{
				for( int ux = 0; ux < USB_Ports.count(); ++ux )
				{
					Args << "-usbdevice"
						 << "host:" + USB_Ports[ux].Get_Vendor_ID() + ":" + USB_Ports[ux].Get_Product_ID();
				}
			}
		}
	}
	
	// Other Tab
	if( Linux_Boot )
	{
		Args << "-kernel" << bzImage_Path;
		
		if( ! Initrd_Path.isEmpty() )
		{
			Args << "-initrd" << Initrd_Path;
		}
		
		if( ! Kernel_ComLine.isEmpty() )
		{
			Args << "-append" << Kernel_ComLine;
		}
	}
	
	// Use ROM File
	if( Use_ROM_File )
	{
		if( ! QFile::exists(ROM_File) )
		{
			AQGraphic_Warning( tr("Error!"),
							   tr("ROM File Not Exists! QEMU Cannot Run!") );
		}
		else
		{
			Args << "-option-rom" << ROM_File;
		}
	}
	
	// Wait gdb connection to port 1234
	if( GDB )
	{
		Args << "-s";
		Args << "-p" << QString::number( GDB_Port );
	}
	
	// Additional Args...
	if( Additional_Args != "" )
	{
		QStringList ad_args = Additional_Args.split( " ", QString::SkipEmptyParts );
		
		for( int ix = 0; ix < ad_args.count(); ix++ )
		{
			Args << ad_args[ ix ];
		}
	}
	
	// Start Date
	if( Start_Date )
	{
		Args << "-startdate" << Start_DateTime.toString( "yyyy-MM-ddTHH:mm:ss" ); // QEMU Format
	}
	
	// QEMU 0.9.1 Options
	if( qemu_version == "0.9.1" || qemu_version == "New"  )
	{
		// VM Name
		Args << "-name" << "\"" + Machine_Name + "\"";
		
		// on-board Flash memory image
		if( MTDBlock )
		{
			Args << "-mtdblock" << MTDBlock_File;
		}
		
		// SecureDigital card image
		if( SecureDigital )
		{
			Args << "-sd" << SecureDigital_File;
		}
		
		// parallel flash image
		if( PFlash )
		{
			Args << "-pflash" << PFlash_File;
		}
		
		// Set the initial graphical resolution and depth
		if( System_Info::VM_Computers[sys_index].PSO_Initial_Graphic_Mode &&
			Init_Graphic_Mode.Get_Enabled() )
		{
			Args << "-g" << QString::number( Init_Graphic_Mode.Get_Width() ) + "x" +
							QString::number( Init_Graphic_Mode.Get_Height() ) + "x" +
							QString::number( Init_Graphic_Mode.Get_Depth() );
		}
		
		// open SDL window without a frame and window decorations
		if( No_Frame )
		{
			Args << "-no-frame";
		}
		
		// use Ctrl-Alt-Shift to grab mouse (instead of Ctrl-Alt)
		if( Alt_Grab )
		{
			Args << "-alt-grab";
		}
		
		// disable SDL window close capability
		if( No_Quit )
		{
			Args << "-no-quit";
		}
		
		// rotate graphical output 90 deg left (only PXA LCD)
		if( Portrait )
		{
			Args << "-portrait";
		}
		
		// VNC
		if( VNC )
		{
			if( qemu_version == "0.9.0" || qemu_version == "Old" )
			{
				Args << "-vnc" << ":" + QString::number( VNC_Display_Number );
			}
			else
			{
				Args << "-vnc";
				
				QString vnc_args = "";
				
				if( VNC_Socket_Mode )
				{
					vnc_args += "unix:" + VNC_Unix_Socket_Path;
				}
				else
				{
					vnc_args += ":" + QString::number( VNC_Display_Number );
				}
				
				if( VNC_Password )
				{
					vnc_args += ",password";
				}
				
				if( VNC_TLS )
				{
					vnc_args += ",tls";
					
					if( VNC_x509 )
					{
						vnc_args += ",x509=" + VNC_x509_Folder_Path;
					}
					
					if( VNC_x509verify )
					{
						vnc_args += ",x509verify=" + VNC_x509verify_Folder_Path;
					}
				}
				
				Args << vnc_args;
			}
		}
		else
		{
			#ifdef VNC_DISPLAY
			if( Settings.value("Use_VNC_Display", "yes").toString() == "yes" )
			{
				if( Embedded_Display_Port >= 0 )
				{
					int port = (Settings.value( "First_VNC_Port", "6000" ).toString().toInt() - 5900) + Embedded_Display_Port;
					
					if( port >= 1 && port < 59636 )
					{
						Args << "-vnc" << ":" + QString::number( port );
					}
					else
					{
						AQError( "QStringList Virtual_Machine::Build_QEMU_Args()",
								 "Port for Embedded Display > 1 or < 59636" );
					}
				}
				else
				{
					AQError( "QStringList Virtual_Machine::Build_QEMU_Args()",
							 "Embedded_Display_Port < 0" );
				}
			}
			#endif
		}
	}
	
	return Args;
}

bool Virtual_Machine::Start()
{
	bool kvm = false;
	bool kqemu = false;
	
	for( int sx = 0; sx < System_Info::VM_Computers.count(); ++sx )
	{
		if( System_Info::VM_Computers[sx].System.QEMU_Name == Computer_Type )
		{
			kvm = System_Info::VM_Computers[sx].PSO_KVM;
			kqemu = System_Info::VM_Computers[sx].PSO_Kernel_KQEMU;
		}
	}
	
	// Check KVM
	if( kvm )
	{
		QProcess lsmod;
		
		lsmod.start( "lsmod" );
		
		if( ! lsmod.waitForFinished(1000) )
		{
			AQError( "bool Virtual_Machine::Start()",
					 "lsmod not finished!" );
		}
		else
		{
			QString all_mod = lsmod.readAll();
			
			if( all_mod.isEmpty() )
			{
				AQError( "bool Virtual_Machine::Start()",
						 "all_mod is empty!" );
			}
			else
			{
				QRegExp kqmod_rex = QRegExp( "*kvm*" );
				kqmod_rex.setPatternSyntax( QRegExp::Wildcard );
					
				if( ! kqmod_rex.exactMatch(all_mod) )
				{
					AQGraphic_Warning( tr("Error!"),
									   tr("KVM Kernel Module Not Loaded!\n"
										  "This Module Provide Acceleration for QEMU.\n"
										  "For Loading KVM Module Type: \"modprobe kvm\" In Root Mode.") );
					return false;
				}
			}
		}
	}
	else if( kqemu ) // Check KQEMU
	{
		// KQEMU Module
		if( KQEMU_Mode != VM::KQEMU_Disabled &&
			KQEMU_Mode != VM::KQEMU_Default )
		{
			// Check kqemu module loaded
			QProcess lsmod;
			
			lsmod.start( "lsmod" );
			
			if( ! lsmod.waitForFinished(1000) )
			{
				AQError( "bool Virtual_Machine::Start()",
						 "lsmod not finished!" );
			}
			else
			{
				QString all_mod = lsmod.readAll();
				
				if( all_mod.isEmpty() )
				{
					AQError( "bool Virtual_Machine::Start()",
							 "all_mod is empty!" );
				}
				else
				{
					QRegExp kqmod_rex = QRegExp( "*kqemu*" );
					kqmod_rex.setPatternSyntax( QRegExp::Wildcard );
					
					if( ! kqmod_rex.exactMatch(all_mod) )
					{
						AQGraphic_Warning( tr("Error!"),
										   tr("KQEMU Kernel Module Not Loaded!\n"
											  "This Module Provide Acceleration for QEMU.\n"
											  "For Loading KQEMU Module Type In Root Mode:\n"
											  "\"modprobe kqemu\"\n"
											  "Or Disable Acceleration in Tab \"General\".") );
						return false;
					}
				}
			}
		}
	}
	
	// QEMU Audio Environment
	if( Settings.value("QEMU_AUDIO/Use_Default_Driver", "yes").toString() != "yes" )
	{
		QStringList tmp_env = QProcess::systemEnvironment();
		tmp_env << "QEMU_AUDIO_DRV=" + Settings.value("QEMU_AUDIO/QEMU_AUDIO_DRV", "alsa").toString();
		QEMU_Process->setEnvironment( tmp_env );
	}
	
	if( (Start_Snapshot_Tag.isEmpty() == false) || (State == VM::VMS_Saved) )
	{
		Show_VM_Load_Window();
	}
	
	QEMU_Process->start( Settings.value( "QEMU_Systems/" + Computer_Type, "qemu" ).toString(),
						 this->Build_QEMU_Args() );
	
	// Do NOT Start CPU
	if( ! Start_CPU )
	{
		Set_State( VM::VMS_Pause );
	}
	
	// VNC Password
	if( VNC && VNC_Password )
	{
		QString ver = Settings.value("QEMU_Version", "0.9.0").toString();
		
		if( ver == "0.9.1" || ver == "New" )
		{
			Execute_Emu_Ctl_Command( "change vnc password" );
		}
	}
	
	if( Load_Mode )
	{
		connect( this, SIGNAL(Ready_StdOut(const QString&)),
				 this, SLOT(Started_Booting(const QString&)) );
		
		QEMU_Process->write( "info vnc\n" );
	}
	
	if( Settings.value( "Show_Emulator_Control_Window", "yes" ).toString() == "yes" )
	{
		Show_Emu_Ctl_Win();
	}
	
	return true;
}

void Virtual_Machine::Pause()
{
	switch( State )
	{
		case VM::VMS_Pause:
			QEMU_Process->write( "c\n" );
			Set_State( VM::VMS_Running );
			break;
			
		case VM::VMS_Running:
			QEMU_Process->write( "stop\n" );
			Set_State( VM::VMS_Pause );
			break;
			
		default:
			AQDebug( "void Virtual_Machine::Pause()",
					 "Default Section!" );
			break;
	}
}

void Virtual_Machine::Stop()
{
	if( State == VM::VMS_Saved )
	{
		Set_State( VM::VMS_Power_Off, true );
	}
	else
	{
		QEMU_Process->write( "quit\n" );
		Set_State( VM::VMS_Power_Off );
	}
}

void Virtual_Machine::Reset()
{
	if( State == VM::VMS_Saved )
	{
		Start_Snapshot_Tag = "";
		Set_State( VM::VMS_Power_Off, true );
		Start();
	}
	else
	{
		//Set_State( VM::VMS_Power_Off );
		QEMU_Process->write( "system_reset\n" );
		//Set_State( VM::VMS_Running );
	}
}

void Virtual_Machine::Save_VM_State()
{
	Save_VM_State( "aqemu_save", true );
}

void Virtual_Machine::Save_VM_State( const QString &tag, bool quit )
{
	Show_VM_Save_Window();
	
	if( quit ) QEMU_Process->write( "stop\n" );
	
	if( Settings.value("Use_Screenshot_for_OS_Logo", "yes").toString() == "yes" )
	{
		/*QString scrn_file = Settings.value( "VM_Directory", "~" ).toString() +
		Get_FS_Compatible_VM_Name( Machine_Name ) + "." +
		Settings.value( "Screenshot_Save_Format", "PNG" ).toString().toLower();*/
		
		QString scrn_file = Settings.value( "VM_Directory", "~" ).toString() +
				Get_FS_Compatible_VM_Name( Machine_Name );
		
		if( Take_Screenshot(scrn_file, 64, 64) )
		{
			Screenshot_Path = scrn_file;
		}
	}
	
	QEMU_Process->write( qPrintable("savevm " + tag + "\n") );
	
	connect( this, SIGNAL(Ready_StdOut(const QString&)),
			 this, SLOT(Suspend_Finished(const QString&)) );
	
	if( quit )
	{
		QEMU_Process->write( "quit\n" );
		Hide_Emu_Ctl_Win();
		Set_State( VM::VMS_Saved );
	}
	
	if( ! Save_VM() )
	{
		AQError( "void Virtual_Machine::Save_VM_State( const QString &tag )",
				 "Saving Not Complete!" );
	}
}

void Virtual_Machine::Load_VM_State( const QString &tag )
{
	Show_VM_Load_Window();
	
	QEMU_Process->write( qPrintable("loadvm " + tag + "\n") );
	
	connect( this, SIGNAL(Ready_StdOut(const QString&)),
			 this, SLOT(Resume_Finished(const QString&)) );
}

bool Virtual_Machine::Start_Snapshot( const QString &tag )
{
	Start_Snapshot_Tag = tag;
	
	return Start();
}

void Virtual_Machine::Delete_Snapshot( const QString &tag )
{
	QEMU_Process->write( qPrintable("delvm " + tag + "\n") );
}

void Virtual_Machine::Show_Emu_Ctl_Win()
{
	if( Emu_Ctl->First_Start == false )
	{
		delete Emu_Ctl;
		
		Emu_Ctl = new Emulator_Control_Window();
		
		QObject::connect( Emu_Ctl, SIGNAL(Ready_Read_Command(QString)),
						  this, SLOT(Execute_Emu_Ctl_Command(QString)) );
	}
	
	Emu_Ctl->Set_Current_VM( this );
	Emu_Ctl->show();
	Emu_Ctl->raise();
	Emu_Ctl->Init();
	
	Emu_Ctl->activateWindow();
}

void Virtual_Machine::Hide_Emu_Ctl_Win()
{
	Emu_Ctl->Set_Show_Close_Warning( false );
	Emu_Ctl->close();
}

void Virtual_Machine::Show_QEMU_Error( const QString &err_str )
{
	QEMU_Error_Win->setWindowTitle( tr("QEMU Error Log")
			+ " (" + Machine_Name + ")" );
	
	QEMU_Error_Win->show();
	QEMU_Error_Win->Add_to_Log( err_str );
}

void Virtual_Machine::Hide_QEMU_Error_Log()
{
	QEMU_Error_Win->close();
}

void Virtual_Machine::Show_VM_Load_Window()
{
	QDesktopWidget *des_widget = new QDesktopWidget();
	QRect re = des_widget->screenGeometry( des_widget->primaryScreen() );
	
	Load_VM_Window = new QWidget();
	
	QLabel *load_label;
	
	Load_VM_Window->setWindowTitle( tr("Loading...") );
	load_label = new QLabel( tr("Loading Virtual Machine. Please wait...") );
	
	QHBoxLayout *h_layout = new QHBoxLayout();
	h_layout->addWidget( load_label );
	Load_VM_Window->setLayout( h_layout );
	
	Load_VM_Window->move( re.height() / 2, re.width() / 2 );
	Load_VM_Window->show();
}

void Virtual_Machine::Hide_VM_Load_Window()
{
	if( ! Dont_Reinit )
	{
		AQDebug( "void Virtual_Machine::Hide_VM_Load_Window()",
				 "emit Loading_Complete()" );
		//emit Loading_Complete();
	}
	
	Load_VM_Window->close();
}

void Virtual_Machine::Show_VM_Save_Window()
{
	QDesktopWidget *des_widget = new QDesktopWidget();
	QRect re = des_widget->screenGeometry( des_widget->primaryScreen() );
	
	Load_VM_Window = new QWidget();
	Save_VM_Window = new QWidget();
	
	QLabel *save_label;
	
	Save_VM_Window->setWindowTitle( tr("Saving...") );
	save_label = new QLabel( tr("Saving Virtual Machine. Please wait...") );
	
	QHBoxLayout *h_layout = new QHBoxLayout();
	h_layout->addWidget( save_label );
	Save_VM_Window->setLayout( h_layout );
	
	Save_VM_Window->move( re.height() / 2, re.width() / 2 );
	Save_VM_Window->show();
}

void Virtual_Machine::Hide_VM_Save_Window()
{
	Save_VM_Window->close();
}

bool Virtual_Machine::Take_Screenshot( const QString &file_name, int width, int height )
{
	if( ! (State == VM::VMS_Running || State == VM::VMS_Pause) )
	{
		AQError( "bool Virtual_Machine::Take_Screenshot( const QString &file_name, int width, int height )",
				 "VM Not Running, Cannot Create Screenshot!" );
		return false;
	}
	
	Execute_Emu_Ctl_Command( "screendump \"" + file_name + "\"" );
	
	QTest::qWait( 100 );
	
	QImage im = QImage();
	
	bool load_ok = false;
	
	// Time for creating screenshot
	for( int wx = 0; wx < 10; ++wx )
	{
		if( im.load(file_name) )
		{
			load_ok = true;
			break;
		}
		
		QTest::qWait( 100 );
	}
	
	// Loading Complete?
	if( load_ok == false)
	{
		AQError( "bool Virtual_Machine::Take_Screenshot( const QString &file_name, int width, int height )",
				 "Cannot Load Screenshot File!" );
		return false;
	}
	
	// delete tmp file
	if( ! QFile::remove(file_name) )
	{
		AQError( "bool Virtual_Machine::Take_Screenshot( const QString &file_name, int width, int height )",
				 "Cannot Remove Temp Screenshot File!" );
		return false;
	}
	
	// Default save format
	QString fmt = Settings.value( "Screenshot_Save_Format",
								  "PNG" ).toString();
	
	// OS Icon Mode?
	if( width > 0 && height > 0 )
	{
		im = im.scaled( width, height, Qt::KeepAspectRatio, Qt::SmoothTransformation );
		fmt = "PNG";
		
		// 64x64 Mode
		if( Settings.value( "64x64_Icons", "yes" ).toString() == "yes" )
		{
			QImage im2 = QImage( width, height, QImage::Format_ARGB32 );
			im2.fill( Qt::transparent );
			
			QSize ms = im2.size() - im.size();
			ms /= 2;
			
			QPainter myp;
			
			myp.begin( &im2 );
			myp.drawImage( QPoint(ms.width(),ms.height()), im );
			
			myp.end();
			
			im = im2;
		}
	}
	
	bool save_ok = false;
	
	if( fmt == "JPEG" )
	{
        save_ok = im.save( file_name, fmt.toLatin1(), Settings.value("Jpeg_Quality", 75).toInt() );
	}
	else
	{
        save_ok = im.save( file_name, fmt.toLatin1() );
	}
	
	if( save_ok )
	{
		return true;
	}
	else
	{
		AQError( "bool Virtual_Machine::Take_Screenshot( const QString &file_name, int width, int height )",
				 "Cannot Save Image!" );
		return false;
	}
}

void Virtual_Machine::Set_State( VM::VM_State s, bool real_poewer_off )
{
	if( State == VM::VMS_Saved && s == VM::VMS_Power_Off )
	{
		if( ! real_poewer_off ) return;
	}
	
	Old_State = State;
	
	State = s;
	emit State_Changet( this, State );
}

VM::VM_State Virtual_Machine::Get_State() const
{
	return State;
}

const QString &Virtual_Machine::Get_Machine_Name() const
{
	return Machine_Name;
}

void Virtual_Machine::Set_Machine_Name( const QString &name )
{
	if( name.isNull() || name.isEmpty() )
	{
		AQError( "void Virtual_Machine::Set_Machine_Name( const QString &name )",
				 "Machine name \"" + name + "\" is not valid!" );
	}
	else Machine_Name = name;
}

const QString &Virtual_Machine::Get_Icon_Path() const
{
	return Icon_Path;
}

void Virtual_Machine::Set_Icon_Path( const QString &file_name )
{
	if( file_name.isNull() || file_name.isEmpty() )
	{
		AQError( "void Virtual_Machine::Set_Icon_Path( const QString &file_name )",
				 "File \"" + file_name + "\" does not exist!" );
	}
	else
	{
		Icon_Path = file_name;
	}
}

const QString &Virtual_Machine::Get_Screenshot_Path() const
{
	return Screenshot_Path;
}

void Virtual_Machine::Set_Screenshot_Path( const QString &file_name )
{
	Screenshot_Path = file_name;
}

bool Virtual_Machine::Get_Check_Free_RAM() const
{
	return Check_Free_RAM;
}

void Virtual_Machine::Set_Check_Free_RAM( bool ch )
{
	Check_Free_RAM = ch;
}

int Virtual_Machine::Get_Memory_Size() const
{
	return Memory_Size;
}

void Virtual_Machine::Set_Memory_Size( int megs )
{
	if( megs > 0 && megs <= 2048 ) Memory_Size = megs;
	else
	{
		AQError( "void Virtual_Machine::Set_Memory_Size( int megs )",
				 "Memory size " + QString::number(megs) + " invalid!" );
	}
}

const QString &Virtual_Machine::Get_Computer_Type() const
{
	return Computer_Type;
}

void Virtual_Machine::Set_Computer_Type( const QString &type )
{
	Computer_Type = type;
}

const QString &Virtual_Machine::Get_Machine_Type() const
{
	return Machine_Type;
}

void Virtual_Machine::Set_Machine_Type( const QString &type )
{
	Machine_Type = type;
}

const QString &Virtual_Machine::Get_CPU_Type() const
{
	return CPU_Type;
}

void Virtual_Machine::Set_CPU_Type( const QString &type )
{
	CPU_Type = type;
}

int Virtual_Machine::Get_SMP_CPU_Count() const
{
	return SMP_CPU_Count;
}

void Virtual_Machine::Set_SMP_CPU_Count( int count )
{
	SMP_CPU_Count = count;
}

const QString &Virtual_Machine::Get_Keyboard_Layout() const
{
	return Keyboard_Layout;
}

void Virtual_Machine::Set_Keyboard_Layout( const QString &kl )
{
	Keyboard_Layout = kl;
}

VM::Sound_Cards Virtual_Machine::Get_Audio_Cards() const
{
	return Audio_Card;
}

void Virtual_Machine::Set_Audio_Cards( VM::Sound_Cards card )
{
	Audio_Card = card;
}

const QString &Virtual_Machine::Get_Video_Card() const
{
	return Video_Card;
}

void Virtual_Machine::Set_Video_Card( const QString &card )
{
	Video_Card = card;
}

VM::Acseleration_Mode Virtual_Machine::Get_KQEMU_Mode() const
{
	return KQEMU_Mode;
}

void Virtual_Machine::Set_KQEMU_Mode( VM::Acseleration_Mode mode )
{
	KQEMU_Mode = mode;
}

const QString &Virtual_Machine::Get_Additional_Args() const
{
	return Additional_Args;
}

void Virtual_Machine::Set_Additional_Args( const QString &aa )
{
	Additional_Args = aa;
}

VM::Boot_Device Virtual_Machine::Get_Boot_Device() const
{
	return Boot_Device;
}

void Virtual_Machine::Set_Boot_Device( VM::Boot_Device device )
{
	Boot_Device = device;
}

bool Virtual_Machine::Use_Fullscreen_Mode() const
{
	return Fullscreen;
}

void Virtual_Machine::Use_Fullscreen_Mode( bool use )
{
	Fullscreen = use;
}

bool Virtual_Machine::Use_ACPI() const
{
	return ACPI;
}

void Virtual_Machine::Use_ACPI( bool use )
{
	ACPI = use;
}

bool Virtual_Machine::Use_Local_Time() const
{
	return Local_Time;
}

void Virtual_Machine::Use_Local_Time( bool use )
{
	Local_Time = use;
}

bool Virtual_Machine::Use_Snapshot_Mode() const
{
	return Snapshot_Mode;
}

void Virtual_Machine::Use_Snapshot_Mode( bool use )
{
	Snapshot_Mode = use;
}

bool Virtual_Machine::Use_Win2K_Hack() const
{
	return Win2K_Hack;
}

void Virtual_Machine::Use_Win2K_Hack( bool use )
{
	Win2K_Hack = use;
}

bool Virtual_Machine::Use_Start_CPU() const
{
	return Start_CPU;
}

void Virtual_Machine::Use_Start_CPU( bool start )
{
	Start_CPU = start;
}

bool Virtual_Machine::Use_QEMU_Log() const
{
	return QEMU_Log;
}

void Virtual_Machine::Use_QEMU_Log( bool use )
{
	QEMU_Log = use;
}

bool Virtual_Machine::Use_No_Reboot() const
{
	return No_Reboot;
}

void Virtual_Machine::Use_No_Reboot( bool use )
{
	No_Reboot = use;
}

bool Virtual_Machine::Use_Check_FDD_Boot_Sector() const
{
	return Check_FDD_Boot_Sector;
}

void Virtual_Machine::Use_Check_FDD_Boot_Sector( bool use )
{
	Check_FDD_Boot_Sector = use;
}

const VM_Floppy &Virtual_Machine::Get_FD0() const
{
	return FD0;
}

void Virtual_Machine::Set_FD0( const VM_Floppy &floppy )
{
	FD0 = VM_Floppy( floppy );
}

const VM_Floppy &Virtual_Machine::Get_FD1() const
{
	return FD1;
}

void Virtual_Machine::Set_FD1( const VM_Floppy &floppy )
{
	FD1 = VM_Floppy( floppy );
}

const VM_CDROM &Virtual_Machine::Get_CD_ROM() const
{
	return CD_ROM;
}

void Virtual_Machine::Set_CD_ROM( const VM_CDROM &cdrom )
{
	CD_ROM = VM_CDROM( cdrom );
}

const VM_HDD &Virtual_Machine::Get_HDA() const
{
	return HDA;
}

void Virtual_Machine::Set_HDA( const VM_HDD &hdd )
{
	HDA = VM_HDD( hdd );
}

const VM_HDD &Virtual_Machine::Get_HDB() const
{
	return HDB;
}

void Virtual_Machine::Set_HDB( const VM_HDD &hdd )
{
	HDB = VM_HDD( hdd );
}

const VM_HDD &Virtual_Machine::Get_HDC() const
{
	return HDC;
}

void Virtual_Machine::Set_HDC( const VM_HDD &hdd )
{
	HDC = VM_HDD( hdd );
}

const VM_HDD &Virtual_Machine::Get_HDD() const
{
	return HDD;
}

void Virtual_Machine::Set_HDD( const VM_HDD &hdd )
{
	HDD = VM_HDD( hdd );
}

const QList<VM_Snapshot> &Virtual_Machine::Get_Snapshots() const
{
	return Snapshots;
}

void Virtual_Machine::Set_Snapshots( const QList<VM_Snapshot> &list )
{
	Snapshots.clear();
	
	for( int sx = 0; sx < list.count(); ++sx )
	{
		Snapshots.append( VM_Snapshot(list[sx]) );
	}
}

void Virtual_Machine::Add_Snapshot( const QString &tag, const QString &name, const QString &desc )
{
	VM_Snapshot tmp;
	
	tmp.Set_Tag( tag );
	tmp.Set_Name( name );
	tmp.Set_Description( desc );
	
	Snapshots.append( tmp );
}

void Virtual_Machine::Add_Snapshot( const VM_Snapshot &snapshot )
{
	Snapshots.append( VM_Snapshot(snapshot) );
}

void Virtual_Machine::Set_Snapshot( int index, const VM_Snapshot &s )
{
	if( index >= 0 && index < Snapshots.count() )
	{
		Snapshots[ index ] = VM_Snapshot( s );
	}
	else
	{
		AQError( "void Virtual_Machine::Set_Snapshot( int index, const VM_Snapshot &s )",
				 "Index == " + QString::number(index) );
	}
}

const QList<VM_Storage_Device> &Virtual_Machine::Get_Storage_Devices_List() const
{
	return Storage_Devices;
}

void Virtual_Machine::Set_Storage_Devices_List( const QList<VM_Storage_Device> &list )
{
	Storage_Devices.clear();
	
	for( int ix = 0; ix < list.count(); ++ix )
	{
		Storage_Devices.append( VM_Storage_Device(list[ix]) );
	}
}

const QString &Virtual_Machine::Get_SMB_Directory() const
{
	return SMB_Directory;
}

void Virtual_Machine::Set_SMB_Directory( const QString &dir )
{
	SMB_Directory = dir;
}

const QString &Virtual_Machine::Get_TFTP_Prefix() const
{
	return TFTP_Prefix;
}

void Virtual_Machine::Set_TFTP_Prefix( const QString &p )
{
	TFTP_Prefix = p;
}

const VM_Net_Card &Virtual_Machine::Get_Network_Card( int index ) const
{
	if( index >= 0 && index < Network_Cards.count() )
	{
		return Network_Cards[ index ];
	}
	else
	{
		AQError( "VM_Net_Card *Virtual_Machine::Get_Network_Card( int index ) const",
				 "Invalid Index!" );
		return *(new VM_Net_Card());
	}
}

void Virtual_Machine::Set_VM_Network_Card( int index, const VM_Net_Card &nc )
{
	if( index >= 0 && index <= 8 && index < Network_Cards.count() )
	{
		Network_Cards[ index ] = nc;
	}
	else
	{
		AQError( "void Virtual_Machine::Set_VM_Network_Card( int index, VM_Net_Card *nc )",
				 "Invalid Index!" );
	}
}

bool Virtual_Machine::Add_Network_Card( const VM_Net_Card &nc )
{
	if( Network_Cards.count() < 9 )
	{
		Network_Cards.append( VM_Net_Card(nc) );
		return true;
	}
	else
	{
		return false;
	}
}

bool Virtual_Machine::Delete_Network_Card( int ix )
{
	if( ix >= 0 && ix <= 8 )
	{
		Network_Cards.removeAt( ix );
		return true;
	}
	else
	{
		return false;
	}
}

void Virtual_Machine::Clear_Network_Cards_List()
{
	Network_Cards.clear();
}

int Virtual_Machine::Get_Network_Cards_Count() const
{
	return Network_Cards.count();
}

const VM_Redirection &Virtual_Machine::Get_Network_Redirection( int index ) const
{
	if( index >= 0 && index < Network_Redirections.count() )
	{
		return Network_Redirections[ index ];
	}
	else
	{
		AQError( "VM_Redirection *Virtual_Machine::Get_Network_Redirection( int index ) const",
				 "Invalid Index!" );
		return *(new VM_Redirection());
	}
}

void Virtual_Machine::Set_Network_Redirection( int index, const VM_Redirection &r )
{
	if( index >= 0 && index < Network_Redirections.count() )
	{
		Network_Redirections[ index ] = r;
	}
	else
	{
		AQError( "void Virtual_Machine::Set_Network_Redirection( int index, VM_Redirection *r )",
				 "Invalid Index!" );
	}
}

void Virtual_Machine::Add_Network_Redirection( const VM_Redirection &r )
{
	Network_Redirections.append( VM_Redirection(r) );
}

bool Virtual_Machine::Delete_Network_Redirection( int ix )
{
	if( ix >= 0 && ix < Network_Redirections.count() )
	{
		Network_Redirections.removeAt( ix );
		return true;
	}
	else
	{
		return false;
	}
}

int Virtual_Machine::Get_Network_Redirections_Count() const
{
	return Network_Redirections.count();
}

bool Virtual_Machine::Get_Use_Network() const
{
	return Use_Network;
}

void Virtual_Machine::Set_Use_Network( bool use )
{
	Use_Network = use;
}

bool Virtual_Machine::Get_Use_Redirections() const
{
	return Use_Redirections;
}

void Virtual_Machine::Set_Use_Redirections( bool r )
{
	Use_Redirections = r;
}

const VM_Port &Virtual_Machine::Get_Serial_Port() const
{
	return Serial_Port;
}

void Virtual_Machine::Set_Serial_Port( const VM_Port &sp )
{
	Serial_Port = VM_Port( sp );
}

const VM_Port &Virtual_Machine::Get_Parallel_Port() const
{
	return Parallel_Port;
}

void Virtual_Machine::Set_Parallel_Port( const VM_Port &pp )
{
	Parallel_Port = VM_Port( pp );
}

// FIXME WARNING! THIS FUNCTION INCOMPLETE
QString Virtual_Machine::Get_USB_Bus_Address( const QString &id )
{
	// Find Device Name by vendor_id:device_id
	QEMU_Process->write( "info usbhost\n" );
	QTest::qSleep(200);
	
	QString info_usbhost_res = QEMU_Process->readAll();
	
	if( info_usbhost_res.isEmpty() )
	{
		AQError( "QString Virtual_Machine::Get_USB_Bus_Address( const QString &id )",
				 "info_usbhost_res.isEmpty()" );
		return "";
	}
	
	QStringList usbhost_dev_list = info_usbhost_res.split( "\n", QString::SkipEmptyParts );
	
	AQWarning( "IW", "Data: " + info_usbhost_res );
	AQWarning( "IW", "End" );
	
	if( usbhost_dev_list.count() <= 0 )
	{
		AQError( "QString Virtual_Machine::Get_USB_Bus_Address( const QString &id )",
				 "usbhost_dev_list.count() <= 0" );
		return "";
	}
	
	// Valid String is: "Class 00: USB device ab12:34cd, USB UPS"
	QRegExp usbhost_dev_reg = QRegExp( ".+([\\da-fA-F]{,4}:[\\da-fA-F]{,4}),\\s+(.+)" );
	
	QString dev_name = "";
	
	for( int ix = 0; ix < usbhost_dev_list.count(); ++ix )
	{
		if( ! usbhost_dev_reg.exactMatch(usbhost_dev_list[ix]) )
		{
			AQDebug( "CM1", usbhost_dev_list[ix] );
			continue;
		}
		
		QStringList info_lines = usbhost_dev_reg.capturedTexts();
		
		if( info_lines.count() <= 1 )
		{
			AQError( "QString Virtual_Machine::Get_USB_Bus_Address( const QString &id )",
					 "info_lines.count() <= 1" );
			return "";
		}
		
		// info_lines[1] == ab12:34cd
		// info_lines[2] == USB UPS
		if( info_lines[1] == id )
		{
			dev_name = info_lines[2];
			break;
		}
	}
	
	if( dev_name.isEmpty() )
	{
		AQError( "QString Virtual_Machine::Get_USB_Bus_Address( const QString &id )",
				 "dev_name.isEmpty()" );
		return "";
	}
	
	AQWarning( "id == " + id, "name == " + dev_name );
	
	// Find Bus.Address by Device Name
	QEMU_Process->write( "info usb\n" );
	QTest::qSleep(200);
	QString info_usb_res = QEMU_Process->readAll();
	
	if( info_usb_res.isEmpty() )
	{
		AQError( "QString Virtual_Machine::Get_USB_Bus_Address( const QString &id )",
				 "info_usb_res is Empty" );
		return "";
	}
	
	QStringList usb_dev_list = info_usb_res.split( "\n", QString::SkipEmptyParts );
	
	if( usb_dev_list.count() <= 0 )
	{
		AQError( "QString Virtual_Machine::Get_USB_Bus_Address( const QString &id )",
				 "usb_dev_list.count() <= 0" );
		return "";
	}
	
	// Valid String is: "Device 0.0, Speed 1.5 Mb/s, Product USB UPS"
	QRegExp usb_dev_reg = QRegExp( "\\s*Device\\s+([\\d]+[.][\\d]+),\\s+Speed\\s+[\\d]+[.][\\d]+\\sMb/s,\\sProduct\\s+(.+)" );
	
	for( int ix = 0; ix < usb_dev_list.count(); ++ix )
	{
		if( ! usb_dev_reg.exactMatch(usb_dev_list[ix]) )
		{
			AQDebug( "CM2", usb_dev_list[ix] );
			continue;
		}
		
		QStringList info_lines = usb_dev_reg.capturedTexts();
		
		if( info_lines.count() <= 1 )
		{
			AQError( "QString Virtual_Machine::Get_USB_Bus_Address( const QString &id )",
					 "info_lines.count() <= 1" );
			return "";
		}
		
		// info_lines[1] == 0.0
		// info_lines[2] == USB UPS
		if( info_lines[2] == dev_name )
		{
			AQDebug( "Finded: ", info_lines[ 1 ] );
			return info_lines[ 1 ]; // OK. This is Bus.Adr
		}
	}
	
	AQError( "QString Virtual_Machine::Get_USB_Bus_Address( const QString &id )",
			 "Not Finded!" );
	
	return "";
}

bool Virtual_Machine::Use_USB_Hub() const
{
	return USB_Hub;
}

void Virtual_Machine::Use_USB_Hub( bool use )
{
	USB_Hub = use;
}

int Virtual_Machine::Get_USB_Ports_Count() const
{
	return USB_Ports.count();
}

const VM_USB &Virtual_Machine::Get_USB_Port( int index ) const
{
	if( index >= 0 && index < USB_Ports.count() )
	{
		return USB_Ports[ index ];
	}
	else
	{
		AQError( "VM_USB *Virtual_Machine::Get_USB_Port( int index ) const",
				 "Index Invalid!" );
		
		return *(new VM_USB());
	}
}

void Virtual_Machine::Set_USB_Port( int index, const VM_USB &u )
{
	if( index >= 0 && index < USB_Ports.count() )
	{
		USB_Ports[ index ] = VM_USB( u );
	}
}

void Virtual_Machine::Add_USB_Port( const VM_USB &u )
{
	USB_Ports.append( VM_USB(u) );
}

bool Virtual_Machine::Delete_USB_Port( int index )
{
	if( index >= 0 && index < USB_Ports.count() )
	{
		USB_Ports.removeAt( index );
		return true;
	}
	else
	{
		return false;
	}
}

const QList<VM_USB> &Virtual_Machine::Get_USB_List() const
{
	return USB_Ports;
}

void Virtual_Machine::Set_USB_List( const QList<VM_USB> &list )
{
	USB_Ports.clear();
	
	for( int ix = 0; ix < list.count(); ++ix )
	{
		USB_Ports.append( VM_USB(list[ix]) );
	}
}

bool Virtual_Machine::Get_Use_Linux_Boot() const
{
	return Linux_Boot;
}

void Virtual_Machine::Set_Use_Linux_Boot( bool use )
{
	Linux_Boot = use;
}

const QString &Virtual_Machine::Get_bzImage_Path() const
{
	return bzImage_Path;
}

void Virtual_Machine::Set_bzImage_Path( const QString &path )
{
	bzImage_Path = path;
}

const QString &Virtual_Machine::Get_Initrd_Path() const
{
	return Initrd_Path;
}

void Virtual_Machine::Set_Initrd_Path( const QString &path )
{
	Initrd_Path = path;
}

const QString &Virtual_Machine::Get_Kernel_ComLine() const
{
	return Kernel_ComLine;
}

void Virtual_Machine::Set_Kernel_ComLine( const QString &cl )
{
	Kernel_ComLine = cl;
}

bool Virtual_Machine::Get_Use_ROM_File() const
{
	return Use_ROM_File;
}

void Virtual_Machine::Set_Use_ROM_File( bool use )
{
	Use_ROM_File = use;
}

const QString &Virtual_Machine::Get_ROM_File() const
{
	return ROM_File;
}

void Virtual_Machine::Set_ROM_File( const QString &path )
{
	ROM_File = path;
}

bool Virtual_Machine::Use_GDB() const
{
	return GDB;
}

void Virtual_Machine::Use_GDB( bool use )
{
	GDB = use;
}

uint Virtual_Machine::Get_GDB_Port() const
{
	return GDB_Port;
}

void Virtual_Machine::Set_GDB_Port( uint port )
{
	if( port > 0 && port < 65531 )
	{
		GDB_Port = port;
	}
	else
	{
		AQError( "void Virtual_Machine::Set_GDB_Port( uint port )",
				 "GDB Port Incorrect!" );
	}
}

bool Virtual_Machine::Use_MTDBlock_File() const
{
	return MTDBlock;
}

void Virtual_Machine::Use_MTDBlock_File( bool use )
{
	MTDBlock = use;
}

const QString &Virtual_Machine::Get_MTDBlock_File() const
{
	return MTDBlock_File;
}

void Virtual_Machine::Set_MTDBlock_File( const QString &file )
{
	MTDBlock_File = file;
}

bool Virtual_Machine::Use_SecureDigital_File() const
{
	return SecureDigital;
}

void Virtual_Machine::Use_SecureDigital_File( bool use )
{
	SecureDigital = use;
}

const QString &Virtual_Machine::Get_SecureDigital_File() const
{
	return SecureDigital_File;
}

void Virtual_Machine::Set_SecureDigital_File( const QString &file )
{
	SecureDigital_File = file;
}

bool Virtual_Machine::Use_PFlash_File() const
{
	return PFlash;
}

void Virtual_Machine::Use_PFlash_File( bool use )
{
	PFlash = use;
}

const QString &Virtual_Machine::Get_PFlash_File() const
{
	return PFlash_File;
}

void Virtual_Machine::Set_PFlash_File( const QString &file )
{
	PFlash_File = file;
}

bool Virtual_Machine::Use_KVM_IRQChip() const
{
	return KVM_IRQChip;
}

void Virtual_Machine::Use_KVM_IRQChip( bool use )
{
	KVM_IRQChip = use;
}

bool Virtual_Machine::Use_No_KVM_Pit() const
{
	return No_KVM_Pit;
}

void Virtual_Machine::Use_No_KVM_Pit( bool use )
{
	No_KVM_Pit = use;
}

bool Virtual_Machine::Use_KVM_Shadow_Memory() const
{
	return KVM_Shadow_Memory;
}

void Virtual_Machine::Use_KVM_Shadow_Memory( bool use )
{
	KVM_Shadow_Memory = use;
}

int Virtual_Machine::Get_KVM_Shadow_Memory_Size() const
{
	return KVM_Shadow_Memory_Size;
}

void Virtual_Machine::Set_KVM_Shadow_Memory_Size( int size )
{
	KVM_Shadow_Memory_Size = size;
}

const VM_Init_Graphic_Mode &Virtual_Machine::Get_Init_Graphic_Mode() const
{
	return Init_Graphic_Mode;
}

void Virtual_Machine::Set_Init_Graphic_Mode( const VM_Init_Graphic_Mode &mode )
{
	Init_Graphic_Mode = mode;
}

bool Virtual_Machine::Use_No_Frame() const
{
	return No_Frame;
}

void Virtual_Machine::Use_No_Frame( bool use )
{
	No_Frame = use;
}

bool Virtual_Machine::Use_Alt_Grab() const
{
	return Alt_Grab;
}

void Virtual_Machine::Use_Alt_Grab( bool use )
{
	Alt_Grab = use;
}

bool Virtual_Machine::Use_No_Quit() const
{
	return No_Quit;
}

void Virtual_Machine::Use_No_Quit( bool use )
{
	No_Quit = use;
}

bool Virtual_Machine::Use_Portrait() const
{
	return Portrait;
}

void Virtual_Machine::Use_Portrait( bool use )
{
	Portrait = use;
}

bool Virtual_Machine::Use_Start_Date() const
{
	return Start_Date;
}

void Virtual_Machine::Use_Start_Date( bool use )
{
	Start_Date = use;
}

const QDateTime &Virtual_Machine::Get_Start_Date() const
{
	return Start_DateTime;
}

void Virtual_Machine::Set_Start_Date( const QDateTime &dt )
{
	Start_DateTime = dt;
}

bool Virtual_Machine::Use_VNC() const
{
	return VNC;
}

void Virtual_Machine::Use_VNC( bool use )
{
	VNC = use;
}

bool Virtual_Machine::Get_VNC_Socket_Mode() const
{
	return VNC_Socket_Mode;
}

void Virtual_Machine::Set_VNC_Socket_Mode( bool use )
{
	VNC_Socket_Mode = use;
}

const QString &Virtual_Machine::Get_VNC_Unix_Socket_Path() const
{
	return VNC_Unix_Socket_Path;
}

void Virtual_Machine::Set_VNC_Unix_Socket_Path( const QString &path )
{
	VNC_Unix_Socket_Path = path;
}

int Virtual_Machine::Get_VNC_Display_Number() const
{
	return VNC_Display_Number;
}

void Virtual_Machine::Set_VNC_Display_Number( int num )
{
	VNC_Display_Number = num;
}

bool Virtual_Machine::Use_VNC_Password() const
{
	return VNC_Password;
}

void Virtual_Machine::Use_VNC_Password( bool use )
{
	VNC_Password = use;
}

void Virtual_Machine::Set_VNC_Password( const QString &pas )
{
	Execute_Emu_Ctl_Command( pas );
}

bool Virtual_Machine::Use_VNC_TLS() const
{
	return VNC_TLS;
}

void Virtual_Machine::Use_VNC_TLS( bool use )
{
	VNC_TLS = use;
}

bool Virtual_Machine::Use_VNC_x509() const
{
	return VNC_x509;
}

void Virtual_Machine::Use_VNC_x509( bool use )
{
	VNC_x509 = use;
}

const QString &Virtual_Machine::Get_VNC_x509_Folder_Path() const
{
	return VNC_x509_Folder_Path;
}

void Virtual_Machine::Set_VNC_x509_Folder_Path( const QString &path )
{
	VNC_x509_Folder_Path = path;
}

bool Virtual_Machine::Use_VNC_x509verify() const
{
	return VNC_x509verify;
}

void Virtual_Machine::Use_VNC_x509verify( bool use )
{
	VNC_x509verify = use;
}

const QString &Virtual_Machine::Get_VNC_x509verify_Folder_Path() const
{
	return VNC_x509verify_Folder_Path;
}

void Virtual_Machine::Set_VNC_x509verify_Folder_Path( const QString &path )
{
	VNC_x509verify_Folder_Path = path;
}

int Virtual_Machine::Get_Embedded_Display_Port() const
{
	return Embedded_Display_Port;
}

void Virtual_Machine::Set_Embedded_Display_Port( int port )
{
	Embedded_Display_Port = port;
}

void Virtual_Machine::Parse_StdOut()
{
	QString convOutput = QEMU_Process->readAllStandardOutput();
	
	QStringList splitOutput = convOutput.split( "[K" );
	
	if( splitOutput.last() == splitOutput.first() )
	{
		emit Clean_Console( convOutput.trimmed() );
		emit Ready_StdOut( convOutput.simplified() );
		Last_Output.append( convOutput.simplified() );
	}
	else
	{
		if( ! splitOutput.last().isEmpty() )
		{
			QString cleanOutput = splitOutput.last().remove( QRegExp("\[[KD].") );
			emit Clean_Console( cleanOutput.trimmed() );
			emit Ready_StdOut( cleanOutput.simplified() );
			Last_Output.append( convOutput.simplified() );
		}
	}
	
	Output_Parts = Last_Output.split( "(qemu)" );
}

void Virtual_Machine::Parse_StdErr()
{
	QString convOutput = QEMU_Process->readAllStandardError();
	
	QStringList splitOutput = convOutput.split( "[K" );
	
	if( splitOutput.last() == splitOutput.first() )
	{
		emit Clean_Console( convOutput.trimmed() );
		emit Ready_StdErr( convOutput.simplified() );
		Last_Output.append( convOutput.simplified() );
	}
	else
	{
		if( ! splitOutput.last().isEmpty() )
		{
			QString cleanOutput = splitOutput.last().remove( QRegExp("\[[KD].") );
			emit Clean_Console( cleanOutput.trimmed() );
			emit Ready_StdErr( cleanOutput.simplified() );
			Last_Output.append( convOutput.simplified() );
		}
	}
	
	Output_Parts = Last_Output.split( "(qemu)" );
}

void Virtual_Machine::QEMU_Started()
{
	AQDebug( "void Virtual_Machine::QEMU_Started()",
			 "QEMU Start" );
	
	if( Start_CPU )
	{
		Set_State( VM::VMS_Running );
	}
	
	if( ! Load_Mode )
	{
		AQDebug( "void Virtual_Machine::QEMU_Started()",
				 "emit Loading_Complete()" );
		emit Loading_Complete();
		Hide_VM_Load_Window();
	}
	
	if( ! Settings.value("Run_Before_QEMU", "").toString().isEmpty() )
	{
		QProcess *before_proc = new QProcess();
		before_proc->start( Settings.value("Run_Before_QEMU", "").toString() );
	}
	
	emit QEMU_Start();
}

void Virtual_Machine::QEMU_Finished( int exitCode, QProcess::ExitStatus exitStatus )
{
	AQDebug( "void Virtual_Machine::QEMU_Finished( int exitCode, QProcess::ExitStatus exitStatus )" ,
			 "QEMU Finished" );
	
	emit QEMU_End();
	
	Set_State( VM::VMS_Power_Off );
	
	if( exitCode != 0 || exitStatus == QProcess::CrashExit )
	{
		AQError( "QEMU Crashed!", QEMU_Process->readAll() );
	}
	else
	{
		AQDebug( "void Virtual_Machine::QEMU_Finished( int exitCode, QProcess::ExitStatus exitStatus )",
				 "QEMU Closed" );
	}
	
	Hide_VM_Save_Window();
	
	if( ! Settings.value("Run_After_QEMU", "").toString().isEmpty() )
	{
		QProcess *after_proc = new QProcess();
		after_proc->start( Settings.value("Run_After_QEMU", "").toString() );
	}
}

void Virtual_Machine::Resume_Finished( const QString &returned_text )
{
	if( returned_text.contains("(qemu)") )
	{
		disconnect( this, SIGNAL(Ready_StdOut(const QString&)),
					this, SLOT(Resume_Finished(const QString&)) );
		
		Dont_Reinit = true;
		
		Hide_VM_Load_Window();
	}
	
    //might need to reconnect the usb tablet here...
}

void Virtual_Machine::Suspend_Finished( const QString &returned_text )
{
	if( returned_text == "(qemu)" )
	{
		QEMU_Process->write( "cont\n" );
		
		disconnect( this, SIGNAL(Ready_StdOut(const QString&)),
					this,SLOT(Suspend_Finished(const QString&)) );
		
		Hide_VM_Save_Window();
	}
}

void Virtual_Machine::Started_Booting( const QString &text )
{
	if( text.contains("VNC") )
	{
		disconnect( this, SIGNAL(Ready_StdOut(const QString&) ),
				    this, SLOT(Started_Booting(const QString&)) );
		
		AQDebug( "void Virtual_Machine::Started_Booting( const QString &text )",
				 "emit Loading_Complete()" );
		emit Loading_Complete();
		Hide_VM_Load_Window();
	}
}

void Virtual_Machine::Execute_Emu_Ctl_Command( const QString &com )
{
	QEMU_Process->write( qPrintable(com + "\n") );
	
	AQDebug( "void Virtual_Machine::Execute_Emu_Ctl_Command( const QString &com )",
			 "Run: " + com );
}

//===========================================================================
