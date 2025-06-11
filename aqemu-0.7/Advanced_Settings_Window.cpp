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

#include <QDir>
#include <QFileDialog>

#include "Advanced_Settings_Window.h"
#include "System_Info.h"
#include "Utils.h"

Advanced_Settings_Window::Advanced_Settings_Window( QWidget *parent )
	: QDialog( parent )
{
	ui.setupUi( this );
	
	// Minimum Size
	resize( minimumSizeHint().width(), minimumSizeHint().height() );
	
	// Check Version on Start AQEMU
	ui.CH_Check_Version_on_Start->setChecked(
			Settings.value("Check_Version_on_Start", "yes").toString() == "yes" );
	
	// Check Availability KVM Always Start AQEMU
	ui.CH_Check_KVM->setChecked(
			Settings.value("Check_KVM", "yes").toString() == "yes" );
	
	//  Set QEMU Version Manual
	ui.RB_QEMU_Version_Manual->setChecked(
			Settings.value("QEMU_Version_Manual", "no").toString() == "yes" );
	
	// Force QEMU Version
	if( ui.RB_QEMU_Version_Manual->isChecked() )
	{
		ui.CB_QEMU_Version->setCurrentIndex(
				Settings.value("Force_QEMU_Version", "0").toInt() );
	}
	
	// Execute Before Start QEMU
	ui.Edit_Before_Start_Command->setText(
			Settings.value("Run_Before_QEMU", "").toString() );
	
	// Execute After Stop QEMU
	ui.Edit_After_Stop_Command->setText(
			Settings.value("Run_After_QEMU", "").toString() );
	
	// Network Cards Settings Interface Mode
	ui.RB_Net_Card_Settings_Old->setChecked( Settings.value("Network_Settings_Mode",
											 "Default").toString() == "Old" );
	
	// QEMU-IMG Binary Path
	ui.Edit_QEMU_IMG_Path->setText(
			Settings.value("QEMU_IMG_Path", "qemu-img").toString() );
	
	// Save to QEMU Log
	ui.CH_QEMU_Log_out_asm->setChecked( Settings.value("QLOG/out_asm",
										"no").toString() == "yes" );
	
	ui.CH_QEMU_Log_in_asm->setChecked( Settings.value("QLOG/in_asm",
									   "no").toString() == "yes" );
	
	ui.CH_QEMU_Log_cpu->setChecked( Settings.value("QLOG/cpu",
									"no").toString() == "yes" );
	
	ui.CH_QEMU_Log_pcall->setChecked( Settings.value("QLOG/pcall",
									  "no").toString() == "yes" );
	
	ui.CH_QEMU_Log_op_opt->setChecked( Settings.value("QLOG/op_opt",
									   "no").toString() == "yes" );
	
	ui.CH_QEMU_Log_int->setChecked( Settings.value("QLOG/int",
									"no").toString() == "yes" );
	
	ui.CH_QEMU_Log_op->setChecked( Settings.value("QLOG/op",
								   "no").toString() == "yes" );
	
	ui.CH_QEMU_Log_exec->setChecked( Settings.value("QLOG/exec",
									 "no").toString() == "yes" );
	
	// Information in Info Tab
	ui.CH_Show_Tab_Info->setChecked( Settings.value("Info/Show_Tab_Info",
									 "yes").toString() == "yes" );
	
	ui.CH_Show_QEMU_Args->setChecked( Settings.value("Info/Show_QEMU_Args",
									  "no").toString() == "yes" );
	
	ui.CH_Show_Screenshot_in_Save_Mode->setChecked( Settings.value("Info/Show_Screenshot_in_Save_Mode",
													"no").toString() == "yes" );
	
	ui.CH_Machine_Details->setChecked( Settings.value("Info/Machine_Details",
									   "yes").toString() == "yes" );
	
	ui.CH_Machine_Name->setChecked( Settings.value("Info/Machine_Name",
									"yes").toString() == "yes" );
	
	ui.CH_Computer_Type->setChecked( Settings.value("Info/Computer_Type",
									 "yes").toString() == "yes" );
	
	ui.CH_Machine_Type->setChecked( Settings.value("Info/Machine_Type",
									"yes").toString() == "yes" );
	
	ui.CH_CPU_Type->setChecked( Settings.value("Info/CPU_Type",
								"yes").toString() == "yes" );
	
	ui.CH_Number_of_CPU->setChecked( Settings.value("Info/Number_of_CPU",
									 "no").toString() == "yes" );
	
	ui.CH_Acceleration->setChecked( Settings.value("Info/Acceleration",
									"no").toString() == "yes" );
	
	ui.CH_Boot_Priority->setChecked( Settings.value("Info/Boot_Priority",
									 "yes").toString() == "yes" );
	
	ui.CH_Video_Card->setChecked( Settings.value("Info/Video_Card",
								  "no").toString() == "yes" );
	
	ui.CH_Keyboard_Layout->setChecked( Settings.value("Info/Keyboard_Layout",
									   "no").toString() == "yes" );
	
	ui.CH_Memory_Size->setChecked( Settings.value("Info/Memory_Size",
								   "yes").toString() == "yes" );
	
	ui.CH_Use_Sound->setChecked( Settings.value("Info/Use_Sound",
								 "yes").toString() == "yes" );
	
	ui.CH_Fullscreen->setChecked( Settings.value("Info/Fullscreen",
								  "yes").toString() == "yes" );
	
	ui.CH_Win2K_Hack->setChecked( Settings.value("Info/Win2K_Hack",
								  "no").toString() == "yes" );
	
	ui.CH_ACPI->setChecked( Settings.value("Info/ACPI",
							"yes").toString() == "yes" );
	
	ui.CH_Localtime->setChecked( Settings.value("Info/Localtime",
								 "yes").toString() == "yes" );
	
	ui.CH_Check_Boot_on_FDD->setChecked( Settings.value("Info/Check_Boot_on_FDD",
										 "no").toString() == "yes" );
	
	ui.CH_Start_CPU->setChecked( Settings.value("Info/Start_CPU",
								 "no").toString() == "yes" );
	
	ui.CH_Snapshot->setChecked( Settings.value("Info/Snapshot",
								"yes").toString() == "yes" );
	
	ui.CH_QEMU_Log->setChecked( Settings.value("Info/QEMU_Log",
								"no").toString() == "yes" );
	
	ui.CH_No_Reboot->setChecked( Settings.value("Info/No_Reboot",
								 "no").toString() == "yes" );
	
	ui.CH_Network_Cards->setChecked( Settings.value("Info/Network_Cards",
									 "yes").toString() == "yes" );
	
	ui.CH_Redirections->setChecked( Settings.value("Info/Redirections",
									"no").toString() == "yes" );
	
	ui.CH_TFTP_Server_Prefix->setChecked( Settings.value("Info/TFTP_Server_Prefix",
										  "no").toString() == "yes" );
	
	ui.CH_SMB_Dir->setChecked( Settings.value("Info/SMB_Dir",
							   "no").toString() == "yes" );
	
	ui.CH_Serial_Port->setChecked( Settings.value("Info/Serial_Port",
								   "no").toString() == "yes" );
	
	ui.CH_Parallel_Port->setChecked( Settings.value("Info/Parallel_Port",
									 "no").toString() == "yes" );
	
	ui.CH_USB_Port->setChecked( Settings.value("Info/USB_Port",
								"no").toString() == "yes" );
	
	ui.CH_ROM_File->setChecked( Settings.value("Info/ROM_File",
								"no").toString() == "yes" );
	
	ui.CH_MTDBlock->setChecked( Settings.value("Info/MTDBlock",
								"no").toString() == "yes" );
	
	ui.CH_SD_Image->setChecked( Settings.value("Info/SD_Image",
								"no").toString() == "yes" );
	
	ui.CH_PFlash->setChecked( Settings.value("Info/PFlash",
							  "no").toString() == "yes" );
	
	ui.CH_No_Frame->setChecked( Settings.value("Info/No_Frame",
								"no").toString() == "yes" );
	
	ui.CH_Alt_Grab->setChecked( Settings.value("Info/Alt_Grab",
								"no").toString() == "yes" );
	
	ui.CH_No_Quit->setChecked( Settings.value("Info/No_Quit",
							   "no").toString() == "yes" );
	
	ui.CH_Portrait->setChecked( Settings.value("Info/Portrait",
								"no").toString() == "yes" );
	
	ui.CH_GDB_Port->setChecked( Settings.value("Info/GDB_Port",
								"no").toString() == "yes" );
	
	ui.CH_Linux_Boot->setChecked( Settings.value("Info/Linux_Boot",
								  "no").toString() == "yes" );
	
	ui.CH_Show_FDD->setChecked( Settings.value("Info/Show_FDD",
								"yes").toString() == "yes" );
	
	ui.CH_Show_CD->setChecked( Settings.value("Info/Show_CD",
							   "yes").toString() == "yes" );
	
	ui.CH_Show_HDD->setChecked( Settings.value("Info/Show_HDD",
								"yes").toString() == "yes" );
	
	// MAC Address Generation Mode
	ui.RB_MAC_Random->setChecked( Settings.value("MAC_Generation_Mode",
								  "Model").toString() == "Random" );
	
	ui.RB_MAC_QEMU->setChecked( Settings.value("MAC_Generation_Mode",
								"Model").toString() == "QEMU_Segment" );
	
	ui.RB_MAC_Valid->setChecked( Settings.value("MAC_Generation_Mode",
								 "Model").toString() == "Model" );
	
	// Save to Log File
	ui.CH_Log_Save_in_File->setChecked(
			Settings.value("Log/Save_In_File", "yes").toString() == "yes" );
	
	// Print In StdOut
	ui.CH_Log_Print_in_STDIO->setChecked(
			Settings.value("Log/Print_In_STDOUT", "yes").toString() == "yes" );
	
	// Log File Path
	ui.Edit_Log_Path->setText(
			Settings.value("Log/Log_Path", Settings.value("VM_Directory", "").toString() +
			"aqemu.log").toString() );
	
	// Save to AQEMU Log
	ui.CH_Log_Debug->setChecked( Settings.value("Log/Save_Debug",
								 "yes").toString() == "yes" );
	
	ui.CH_Log_Warning->setChecked( Settings.value("Log/Save_Warning",
								   "yes").toString() == "yes" );
	
	ui.CH_Log_Error->setChecked( Settings.value("Log/Save_Error",
								 "yes").toString() == "yes" );
	
	// QEMU_AUDIO
	ui.GB_Audio_Default->setChecked( ! (Settings.value("QEMU_AUDIO/Use_Default_Driver",
									 "no").toString()  == "yes") );
	
	// Recent Count
	ui.SB_Recent_Count->setValue( Settings.value("CD_ROM_Exits_Images/Max", "4").toString().toInt() );
	
	// First VNC Port for Embedded Display
	ui.SB_First_VNC_Port->setValue( Settings.value("First_VNC_Port", "6000").toString().toInt() );
	
	// QEMU_AUDIO_DRV
	for( int ix = 0; ix < ui.CB_Host_Sound_System->count(); ++ix )
	{
		if( ui.CB_Host_Sound_System->itemText(ix) ==
			Settings.value("QEMU_AUDIO/QEMU_AUDIO_DRV", "alsa").toString() )
		{
			ui.CB_Host_Sound_System->setCurrentIndex( ix );
		}
	}
}

void Advanced_Settings_Window::on_Button_OK_clicked()
{
	// Check Version on Start AQEMU
	if( ui.CH_Check_Version_on_Start->isChecked() )
	{
		Settings.setValue( "Check_Version_on_Start", "yes" );
	}
	else
	{
		Settings.setValue( "Check_Version_on_Start", "no" );
	}
	
	// Check Availability KVM Always Start AQEMU
	if( ui.CH_Check_KVM->isChecked() )
	{
		Settings.setValue( "Check_KVM", "yes" );
	}
	else
	{
		Settings.setValue( "Check_KVM", "no" );
	}
	
	//  Set QEMU Version Manual
	if( ui.RB_QEMU_Version_Manual->isChecked() )
	{
		Settings.setValue( "QEMU_Version_Manual", "yes" );
		
		switch( ui.CB_QEMU_Version->currentIndex() )
		{
			case 0:
				Settings.setValue( "QEMU_Version", "0.9.0" );
				break;
			
			case 1:
				Settings.setValue( "QEMU_Version", "0.9.1" );
				break;
			
			default:
				Settings.setValue( "QEMU_Version", "0.9.0" );
				break;
		}
	}
	else
	{
		if( Settings.value("QEMU_Version_Manual", "no") == "yes" )
		{
			System_Info::Check_QEMU_Version();
		}
		
		Settings.setValue( "QEMU_Version_Manual", "no" );
	}
	
	// Force QEMU Version
	Settings.setValue("Force_QEMU_Version", ui.CB_QEMU_Version->currentIndex() );
	
	// Execute Before Start QEMU
	Settings.setValue( "Run_Before_QEMU",
						ui.Edit_Before_Start_Command->text() );
	
	// Execute After Stop QEMU
	Settings.setValue( "Run_After_QEMU",
						ui.Edit_After_Stop_Command->text() );
	
	// Network Cards Settings Interface Mode
	if( ui.RB_Net_Card_Settings_Old->isChecked() )
	{
		Settings.setValue( "Network_Settings_Mode", "Old" );
	}
	else
	{
		Settings.setValue( "Network_Settings_Mode", "Default" );
	}
	
	// QEMU-IMG Binary Path
	Settings.setValue( "QEMU_IMG_Path", ui.Edit_QEMU_IMG_Path->text() );
	
	// Save to QEMU Log
	if( ui.CH_QEMU_Log_out_asm->isChecked() )
	{
		Settings.setValue( "QLOG/out_asm", "yes" );
	}
	else
	{
		Settings.setValue( "QLOG/out_asm", "no" );
	}
	
	if( ui.CH_QEMU_Log_in_asm->isChecked() )
	{
		Settings.setValue( "QLOG/in_asm", "yes" );
	}
	else
	{
		Settings.setValue( "QLOG/in_asm", "no" );
	}
	
	if( ui.CH_QEMU_Log_cpu->isChecked() )
	{
		Settings.setValue( "QLOG/cpu", "yes" );
	}
	else
	{
		Settings.setValue( "QLOG/cpu", "no" );
	}
	
	if( ui.CH_QEMU_Log_pcall->isChecked() )
	{
		Settings.setValue( "QLOG/pcall", "yes" );
	}
	else
	{
		Settings.setValue( "QLOG/pcall", "no" );
	}
	
	if( ui.CH_QEMU_Log_op_opt->isChecked() )
	{
		Settings.setValue( "QLOG/op_opt", "yes" );
	}
	else
	{
		Settings.setValue( "QLOG/op_opt", "no" );
	}
	
	if( ui.CH_QEMU_Log_int->isChecked() )
	{
		Settings.setValue( "QLOG/int", "yes" );
	}
	else
	{
		Settings.setValue( "QLOG/int", "no" );
	}
	
	if( ui.CH_QEMU_Log_op->isChecked() )
	{
		Settings.setValue( "QLOG/op", "yes" );
	}
	else
	{
		Settings.setValue( "QLOG/op", "no" );
	}
	
	if( ui.CH_QEMU_Log_exec->isChecked() )
	{
		Settings.setValue( "QLOG/exec", "yes" );
	}
	else
	{
		Settings.setValue( "QLOG/exec", "no" );
	}
	
	// Information in Info Tab
	if( ui.CH_Show_Tab_Info->isChecked() )
	{
		Settings.setValue( "Info/Show_Tab_Info", "yes" );
	}
	else
	{
		Settings.setValue( "Info/Show_Tab_Info", "no" );
	}
	
	if( ui.CH_Show_QEMU_Args->isChecked() )
	{
		Settings.setValue( "Info/Show_QEMU_Args", "yes" );
	}
	else
	{
		Settings.setValue( "Info/Show_QEMU_Args", "no" );
	}
	
	if( ui.CH_Show_Screenshot_in_Save_Mode->isChecked() )
	{
		Settings.setValue( "Info/Show_Screenshot_in_Save_Mode", "yes" );
	}
	else
	{
		Settings.setValue( "Info/Show_Screenshot_in_Save_Mode", "no" );
	}
	
	if( ui.CH_Machine_Details->isChecked() )
	{
		Settings.setValue( "Info/Machine_Details", "yes" );
	}
	else
	{
		Settings.setValue( "Info/Machine_Details", "no" );
	}
	
	if( ui.CH_Machine_Name->isChecked() )
	{
		Settings.setValue( "Info/Machine_Name", "yes" );
	}
	else
	{
		Settings.setValue( "Info/Machine_Name", "no" );
	}
	
	if( ui.CH_Computer_Type->isChecked() )
	{
		Settings.setValue( "Info/Computer_Type", "yes" );
	}
	else
	{
		Settings.setValue( "Info/Computer_Type", "no" );
	}
	
	if( ui.CH_Machine_Type->isChecked() )
	{
		Settings.setValue( "Info/Machine_Type", "yes" );
	}
	else
	{
		Settings.setValue( "Info/Machine_Type", "no" );
	}
	
	if( ui.CH_CPU_Type->isChecked() )
	{
		Settings.setValue( "Info/CPU_Type", "yes" );
	}
	else
	{
		Settings.setValue( "Info/CPU_Type", "no" );
	}
	
	if( ui.CH_Number_of_CPU->isChecked() )
	{
		Settings.setValue( "Info/Number_of_CPU", "yes" );
	}
	else
	{
		Settings.setValue( "Info/Number_of_CPU", "no" );
	}
	
	if( ui.CH_Acceleration->isChecked() )
	{
		Settings.setValue( "Info/Acceleration", "yes" );
	}
	else
	{
		Settings.setValue( "Info/Acceleration", "no" );
	}
	
	if( ui.CH_Boot_Priority->isChecked() )
	{
		Settings.setValue( "Info/Boot_Priority", "yes" );
	}
	else
	{
		Settings.setValue( "Info/Boot_Priority", "no" );
	}
	
	if( ui.CH_Video_Card->isChecked() )
	{
		Settings.setValue( "Info/Video_Card", "yes" );
	}
	else
	{
		Settings.setValue( "Info/Video_Card", "no" );
	}
	
	if( ui.CH_Keyboard_Layout->isChecked() )
	{
		Settings.setValue( "Info/Keyboard_Layout", "yes" );
	}
	else
	{
		Settings.setValue( "Info/Keyboard_Layout", "no" );
	}
	
	if( ui.CH_Memory_Size->isChecked() )
	{
		Settings.setValue( "Info/Memory_Size", "yes" );
	}
	else
	{
		Settings.setValue( "Info/Memory_Size", "no" );
	}
	
	if( ui.CH_Use_Sound->isChecked() )
	{
		Settings.setValue( "Info/Use_Sound", "yes" );
	}
	else
	{
		Settings.setValue( "Info/Use_Sound", "no" );
	}
	
	if( ui.CH_Fullscreen->isChecked() )
	{
		Settings.setValue( "Info/Fullscreen", "yes" );
	}
	else
	{
		Settings.setValue( "Info/Fullscreen", "no" );
	}
	
	if( ui.CH_Win2K_Hack->isChecked() )
	{
		Settings.setValue( "Info/Win2K_Hack", "yes" );
	}
	else
	{
		Settings.setValue( "Info/Win2K_Hack", "no" );
	}
	
	if( ui.CH_ACPI->isChecked() )
	{
		Settings.setValue( "Info/ACPI", "yes" );
	}
	else
	{
		Settings.setValue( "Info/ACPI", "no" );
	}
	
	if( ui.CH_Localtime->isChecked() )
	{
		Settings.setValue( "Info/Localtime", "yes" );
	}
	else
	{
		Settings.setValue( "Info/Localtime", "no" );
	}
	
	if( ui.CH_Check_Boot_on_FDD->isChecked() )
	{
		Settings.setValue( "Info/Check_Boot_on_FDD", "yes" );
	}
	else
	{
		Settings.setValue( "Info/Check_Boot_on_FDD", "no" );
	}
	
	if( ui.CH_Start_CPU->isChecked() )
	{
		Settings.setValue( "Info/Start_CPU", "yes" );
	}
	else
	{
		Settings.setValue( "Info/Start_CPU", "no" );
	}
	
	if( ui.CH_Snapshot->isChecked() )
	{
		Settings.setValue( "Info/Snapshot", "yes" );
	}
	else
	{
		Settings.setValue( "Info/Snapshot", "no" );
	}
	
	if( ui.CH_QEMU_Log->isChecked() )
	{
		Settings.setValue( "Info/QEMU_Log", "yes" );
	}
	else
	{
		Settings.setValue( "Info/QEMU_Log", "no" );
	}
	
	if( ui.CH_No_Reboot->isChecked() )
	{
		Settings.setValue( "Info/No_Reboot", "yes" );
	}
	else
	{
		Settings.setValue( "Info/No_Reboot", "no" );
	}
	
	if( ui.CH_Network_Cards->isChecked() )
	{
		Settings.setValue( "Info/Network_Cards", "yes" );
	}
	else
	{
		Settings.setValue( "Info/Network_Cards", "no" );
	}
	
	if( ui.CH_Redirections->isChecked() )
	{
		Settings.setValue( "Info/Redirections", "yes" );
	}
	else
	{
		Settings.setValue( "Info/Redirections", "no" );
	}
	
	if( ui.CH_TFTP_Server_Prefix->isChecked() )
	{
		Settings.setValue( "Info/TFTP_Server_Prefix", "yes" );
	}
	else
	{
		Settings.setValue( "Info/TFTP_Server_Prefix", "no" );
	}
	
	if( ui.CH_SMB_Dir->isChecked() )
	{
		Settings.setValue( "Info/SMB_Dir", "yes" );
	}
	else
	{
		Settings.setValue( "Info/SMB_Dir", "no" );
	}
	
	if( ui.CH_Serial_Port->isChecked() )
	{
		Settings.setValue( "Info/Serial_Port", "yes" );
	}
	else
	{
		Settings.setValue( "Info/Serial_Port", "no" );
	}
	
	if( ui.CH_Parallel_Port->isChecked() )
	{
		Settings.setValue( "Info/Parallel_Port", "yes" );
	}
	else
	{
		Settings.setValue( "Info/Parallel_Port", "no" );
	}
	
	if( ui.CH_USB_Port->isChecked() )
	{
		Settings.setValue( "Info/USB_Port", "yes" );
	}
	else
	{
		Settings.setValue( "Info/USB_Port", "no" );
	}
	
	if( ui.CH_ROM_File->isChecked() )
	{
		Settings.setValue( "Info/ROM_File", "yes" );
	}
	else
	{
		Settings.setValue( "Info/ROM_File", "no" );
	}
	
	if( ui.CH_MTDBlock->isChecked() )
	{
		Settings.setValue( "Info/MTDBlock", "yes" );
	}
	else
	{
		Settings.setValue( "Info/MTDBlock", "no" );
	}
	
	if( ui.CH_SD_Image->isChecked() )
	{
		Settings.setValue( "Info/SD_Image", "yes" );
	}
	else
	{
		Settings.setValue( "Info/SD_Image", "no" );
	}
	
	if( ui.CH_PFlash->isChecked() )
	{
		Settings.setValue( "Info/PFlash", "yes" );
	}
	else
	{
		Settings.setValue( "Info/PFlash", "no" );
	}
	
	if( ui.CH_GDB_Port->isChecked() )
	{
		Settings.setValue( "Info/GDB_Port", "yes" );
	}
	else
	{
		Settings.setValue( "Info/GDB_Port", "no" );
	}
	
	if( ui.CH_No_Frame->isChecked() )
	{
		Settings.setValue( "Info/No_Frame", "yes" );
	}
	else
	{
		Settings.setValue( "Info/No_Frame", "no" );
	}
	
	if( ui.CH_Alt_Grab->isChecked() )
	{
		Settings.setValue( "Info/Alt_Grab", "yes" );
	}
	else
	{
		Settings.setValue( "Info/Alt_Grab", "no" );
	}
	
	if( ui.CH_No_Quit->isChecked() )
	{
		Settings.setValue( "Info/No_Quit", "yes" );
	}
	else
	{
		Settings.setValue( "Info/No_Quit", "no" );
	}
	
	if( ui.CH_Portrait->isChecked() )
	{
		Settings.setValue( "Info/Portrait", "yes" );
	}
	else
	{
		Settings.setValue( "Info/Portrait", "no" );
	}
	
	if( ui.CH_Linux_Boot->isChecked() )
	{
		Settings.setValue( "Info/Linux_Boot", "yes" );
	}
	else
	{
		Settings.setValue( "Info/Linux_Boot", "no" );
	}
	
	if( ui.CH_Show_FDD->isChecked() )
	{
		Settings.setValue( "Info/Show_FDD", "yes" );
	}
	else
	{
		Settings.setValue( "Info/Show_FDD", "no" );
	}
	
	if( ui.CH_Show_CD->isChecked() )
	{
		Settings.setValue( "Info/Show_CD", "yes" );
	}
	else
	{
		Settings.setValue( "Info/Show_CD", "no" );
	}
	
	if( ui.CH_Show_HDD->isChecked() )
	{
		Settings.setValue( "Info/Show_HDD", "yes" );
	}
	else
	{
		Settings.setValue( "Info/Show_HDD", "no" );
	}
	
	// MAC Address Generation Mode
	if( ui.RB_MAC_Random->isChecked() )
	{
		Settings.setValue( "MAC_Generation_Mode", "Random" );
	}
	else if( ui.RB_MAC_QEMU->isChecked() )
	{
		Settings.setValue( "MAC_Generation_Mode", "QEMU_Segment" );
	}
	else if( ui.RB_MAC_Valid->isChecked() )
	{
		 Settings.setValue( "MAC_Generation_Mode", "Model" );
	}
	
	// Save to Log File
	if( ui.CH_Log_Save_in_File->isChecked() )
	{
		Settings.setValue( "Log/Save_In_File", "yes" );
	}
	else
	{
		Settings.setValue( "Log/Save_In_File", "no" );
	}
	
	// Print In StdOut
	if( ui.CH_Log_Print_in_STDIO->isChecked() )
	{
		Settings.setValue( "Log/Print_In_STDOUT", "yes" );
	}
	else
	{
		Settings.setValue( "Log/Print_In_STDOUT", "no" );
	}
	
	// Log File Path
	Settings.setValue( "Log/Log_Path", ui.Edit_Log_Path->text() );
	
	// Save to AQEMU Log
	if( ui.CH_Log_Debug->isChecked() )
	{
		Settings.setValue( "Log/Save_Debug", "yes" );
	}
	else
	{
		Settings.setValue( "Log/Save_Debug", "no" );
	}
	
	if( ui.CH_Log_Warning->isChecked() )
	{
		Settings.setValue( "Log/Save_Warning", "yes" );
	}
	else
	{
		Settings.setValue( "Log/Save_Warning", "no" );
	}
	
	if( ui.CH_Log_Error->isChecked() )
	{
		Settings.setValue( "Log/Save_Error", "yes" );
	}
	else
	{
		Settings.setValue( "Log/Save_Error", "yes" );
	}
	
	// QEMU_AUDIO
	if( ui.GB_Audio_Default->isChecked() )
	{
		Settings.setValue( "QEMU_AUDIO/Use_Default_Driver", "no" );
	}
	else
	{
		Settings.setValue( "QEMU_AUDIO/Use_Default_Driver", "yes" );
	}
	
	// Recent Count
	Settings.setValue( "CD_ROM_Exits_Images/Max", QString::number(ui.SB_Recent_Count->value()) );
	
	// First VNC Port for Embedded Display
	Settings.setValue( "First_VNC_Port", QString::number(ui.SB_First_VNC_Port->value()) );
	
	// QEMU_AUDIO_DRV
	Settings.setValue( "QEMU_AUDIO/QEMU_AUDIO_DRV", ui.CB_Host_Sound_System->currentText() );
	
	// All OK?
	if( Settings.status() != QSettings::NoError )
	{
		AQError( "void Advanced_Settings_Window::on_Button_OK_clicked()",
				 "QSettings Error!" );
	}
	
	accept();
}

void Advanced_Settings_Window::on_TB_Browse_Before_clicked()
{
	QString fileName = QFileDialog::getOpenFileName( this, tr("Select executable"),
			ui.Edit_Before_Start_Command->text(), tr("All Files (*)") );
	
	if( ! (fileName.isNull() || fileName.isEmpty()) )
	{
		ui.Edit_Before_Start_Command->setText( fileName );
	}
}

void Advanced_Settings_Window::on_TB_Browse_After_clicked()
{
	QString fileName = QFileDialog::getOpenFileName( this, tr("Select executable"),
			ui.Edit_After_Stop_Command->text(), tr("All Files (*)") );
	
	if( ! (fileName.isNull() || fileName.isEmpty()) )
	{
		ui.Edit_After_Stop_Command->setText( fileName );
	}
}

void Advanced_Settings_Window::on_TB_Log_File_clicked()
{
	QString fileName = QFileDialog::getSaveFileName( this, tr("Select or Create Log File"),
			ui.Edit_Log_Path->text(), tr("All Files (*)") );
	
	if( ! (fileName.isNull() || fileName.isEmpty()) )
	{
		ui.Edit_Log_Path->setText( fileName );
	}
}

void Advanced_Settings_Window::on_TB_QEMU_IMG_Browse_clicked()
{
	QString fileName = QFileDialog::getSaveFileName( this, tr("Select qemu-img Binary File"),
			ui.Edit_QEMU_IMG_Path->text(), tr("All Files (*)") );
	
	if( ! (fileName.isNull() || fileName.isEmpty()) )
	{
		ui.Edit_QEMU_IMG_Path->setText( fileName );
	}
}

void Advanced_Settings_Window::on_CH_Check_Version_on_Start_toggled( bool on )
{
	if( on ) ui.RB_QEMU_Version_Auto->setChecked( true );
}

void Advanced_Settings_Window::on_RB_QEMU_Version_Manual_toggled( bool on )
{
	if( on ) ui.CH_Check_Version_on_Start->setChecked( false );
}
