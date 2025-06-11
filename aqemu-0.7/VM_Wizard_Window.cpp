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
#include <QRegExp>
#include <QFileDialog>

#include "Utils.h"
#include "Settings_Window.h"
#include "VM_Wizard_Window.h"
#include "System_Info.h"

VM_Wizard_Window::VM_Wizard_Window( QWidget *parent )
	: QDialog(parent)
{
	ui.setupUi( this );
	ui.Label_Page->setBackgroundRole( QPalette::Base );
	
	New_VM = new Virtual_Machine();
	
	// All QEMU Systems
	for( int sx = 0; sx < System_Info::VM_Computers.count(); ++sx )
	{
		ui.CB_Computer_Type->addItem( System_Info::VM_Computers[sx].System.Caption );
	}
	
	// Loadind All Templates
	if( Load_OS_Templates() )
	{
		// Find default template
		for( int ix = 0; ix < ui.CB_OS_Type->count(); ++ix )
		{
			if( ui.CB_OS_Type->itemText(ix) ==
						 Settings.value("Default_VM_Template", "Linux_2_6").toString() )
			{
				ui.CB_OS_Type->setCurrentIndex( ix );
			}
		}
	}
	else
	{
		AQWarning( "void VM_Wizard_Window::on_Button_Next_clicked()",
				   "No VM Templates Found!" );
	}
}

void VM_Wizard_Window::Set_VM_List( QList<Virtual_Machine> *list )
{
	VM_List = list;
}

void VM_Wizard_Window::on_Button_Back_clicked()
{
	ui.Button_Next->setEnabled( true );
	
	if( ui.Welcome_Page == ui.Wizard_Pages->currentWidget() )
	{
	}
	else if( ui.Wizard_Mode_Page == ui.Wizard_Pages->currentWidget() )
	{
		ui.Wizard_Pages->setCurrentWidget( ui.Welcome_Page );
		ui.Label_Page->setText( tr("New Virtual Machine Wizard") );
		ui.Button_Back->setEnabled( false );
	}
	else if( ui.Template_Page == ui.Wizard_Pages->currentWidget() )
	{
		ui.Wizard_Pages->setCurrentWidget( ui.Wizard_Mode_Page );
		ui.Label_Page->setText( tr("Wizard Mode") );
	}
	else if( ui.General_Settings_Page == ui.Wizard_Pages->currentWidget() )
	{
		ui.Wizard_Pages->setCurrentWidget( ui.Template_Page );
		ui.Label_Page->setText( tr("VM Hardware Template") );
	}
	else if( ui.Memory_Page == ui.Wizard_Pages->currentWidget() )
	{
		ui.Wizard_Pages->setCurrentWidget( ui.General_Settings_Page );
		ui.Label_Page->setText( tr("VM Name and CPU Type") );
		ui.GB_CPU_Type->setVisible( true );
	}
	else if( ui.Typical_HDD_Page == ui.Wizard_Pages->currentWidget() )
	{
		ui.Wizard_Pages->setCurrentWidget( ui.General_Settings_Page );
		ui.Label_Page->setText( tr("Virtual Machine Name") );
		ui.GB_CPU_Type->setVisible( false );
	}
	else if( ui.Custom_HDD_Page == ui.Wizard_Pages->currentWidget() )
	{
		ui.Wizard_Pages->setCurrentWidget( ui.Memory_Page );
		ui.Label_Page->setText( tr("Memory") );
	}
	else if( ui.Network_Page == ui.Wizard_Pages->currentWidget() )
	{
		if( ui.RB_Typical->isChecked() ) // typcal or custom mode
		{
			ui.Wizard_Pages->setCurrentWidget( ui.Typical_HDD_Page );
			ui.Label_Page->setText( tr("Hard Disk Size") );
		}
		else
		{
			ui.Wizard_Pages->setCurrentWidget( ui.Custom_HDD_Page );
			ui.Label_Page->setText( tr("Virtual Hard Disk") );
		}
	}
	else if( ui.Finish_Page == ui.Wizard_Pages->currentWidget() )
	{
		ui.Wizard_Pages->setCurrentWidget( ui.Network_Page );
		ui.Label_Page->setText( tr("Network") );
		ui.Button_Next->setText( tr("&Next") );
	}
	else
	{
		// Default
		AQError( "void VM_Wizard_Window::on_Button_Back_clicked()",
				 "Default Section!" );
	}
}

void VM_Wizard_Window::on_Button_Next_clicked()
{
	if( ui.Welcome_Page == ui.Wizard_Pages->currentWidget() )
	{
		ui.Wizard_Pages->setCurrentWidget( ui.Wizard_Mode_Page );
		ui.Button_Back->setEnabled( true );
		ui.Label_Page->setText( tr("Wizard Mode") );
	}
	else if( ui.Wizard_Mode_Page == ui.Wizard_Pages->currentWidget() )
	{
		ui.Wizard_Pages->setCurrentWidget( ui.Template_Page );
		on_RB_VM_Template_toggled( ui.RB_VM_Template->isChecked() );
		ui.Label_Page->setText( tr("Template For VM") );
	}
	else if( ui.Template_Page == ui.Wizard_Pages->currentWidget() )
	{
		// Use Selected Template
		if( ui.RB_VM_Template->isChecked() )
		{
			if( New_VM->Load_VM(OS_Templates_List[ui.CB_OS_Type->currentIndex()-1].filePath()) )
			{
				// Name
				ui.Edit_VM_Name->setText( New_VM->Get_Machine_Name() );
				
				// Find CPU List For This Template
				int sys_index = -1;
				
				for( int sx = 0; sx < System_Info::VM_Computers.count(); ++sx )
				{
					if( System_Info::VM_Computers[sx].System.QEMU_Name == New_VM->Get_Computer_Type() )
					{
						sys_index = sx;
						break;
					}
				}
				
				if( sys_index == -1 )
				{
					AQGraphic_Error( "void VM_Wizard_Window::on_Button_Next_clicked()", tr("Error!"),
									 tr("Cannot Find QEMU System ID!") );
				}
				else
				{
					ui.CB_CPU_Type->clear();
					
					for( int cx = 0; cx < System_Info::VM_Computers[sys_index].CPU_List.count(); ++cx )
					{
						ui.CB_CPU_Type->addItem( System_Info::VM_Computers[sys_index].CPU_List[cx].Caption );
					}
				}
				
				// Memory
				ui.Mem_Size_Spin->setValue( New_VM->Get_Memory_Size() );
				
				// HDA
				double hda_size = New_VM->Get_HDA().Get_Virtual_Size_in_GB();
				
				if( hda_size != 0.0 )
				{
					ui.SB_HDD_Size->setValue( hda_size );
				}
				else
				{
					ui.SB_HDD_Size->setValue( 10.0 );
				}
				
				// Network
				ui.RB_User_Mode_Network->setChecked( New_VM->Get_Use_Network() );
			}
			else
			{
				AQGraphic_Error( "void VM_Wizard_Window::Create_New_VM()", tr("Error!"),
								 tr("Cannot Create New VM from Template!") );
				return;
			}
		}
		else // Create New VM in Date Mode
		{
			// Find CPU List
			if( ui.CB_Computer_Type->currentIndex() < 1 ) // 0 is "No Selected" item
			{
				AQError( "void VM_Wizard_Window::Create_New_VM()",
						 "ui.CB_Computer_Type->currentIndex() < 2" );
			}
			else
			{
				ui.CB_CPU_Type->clear();
				
				for( int cx = 0; cx < System_Info::VM_Computers[ui.CB_Computer_Type->currentIndex()-1].CPU_List.count(); ++cx )
				{
					ui.CB_CPU_Type->addItem(
							System_Info::VM_Computers[ui.CB_Computer_Type->currentIndex()-1].CPU_List[cx].Caption );
				}
			}
			
			// Select Memory Size, and HDD Size
			switch( ui.CB_Relese_Date->currentIndex() )
			{
				case 0:
					AQError( "void VM_Wizard_Window::Create_New_VM()",
							 "Relese Date Not Selected!" );
					ui.Memory_Size->setValue( 128 );
					break;
					
				case 1: // 1985-1990
					ui.Memory_Size->setValue( 8 );
					ui.SB_HDD_Size->setValue( 1.0 );
					break;
					
				case 2: // 1990-1995
					ui.Memory_Size->setValue( 32 );
					ui.SB_HDD_Size->setValue( 2.0 );
					break;
						
				case 3: // 1995-2000
					ui.Memory_Size->setValue( 128 );
					ui.SB_HDD_Size->setValue( 10.0 );
					break;
					
				case 4: // 2000-2005
					ui.Memory_Size->setValue( 256 );
					ui.SB_HDD_Size->setValue( 20.0 );
					break;
					
				case 5: // 2005-2008
					ui.Memory_Size->setValue( 512 );
					ui.SB_HDD_Size->setValue( 40.0 );
					break;
					
				default:
					AQError( "void VM_Wizard_Window::Create_New_VM()",
							 "Relese Date Default Section!" );
					ui.Memory_Size->setValue( 128 );
					break;
			}
		}
		
		ui.Wizard_Pages->setCurrentWidget( ui.General_Settings_Page );
		
		if( ui.RB_Typical->isChecked() ) // typical or custom mode
		{
			ui.Label_Page->setText( tr("Virtual Machine Name") );
			on_Edit_VM_Name_textEdited( ui.Edit_VM_Name->text() );
			ui.GB_CPU_Type->setVisible( false );
		}
		else
		{
			ui.Label_Page->setText( tr("VM Name and CPU Type") );
			on_Edit_VM_Name_textEdited( ui.Edit_VM_Name->text() );
			ui.GB_CPU_Type->setVisible( true );
		}
	}
	else if( ui.General_Settings_Page == ui.Wizard_Pages->currentWidget() )
	{
		for( int vx = 0; vx < VM_List->count(); ++vx )
		{
			if( VM_List->at(vx).Get_Machine_Name() == ui.Edit_VM_Name->text() )
			{
				AQGraphic_Warning( tr("Warning"), tr("This VM Name is Already Exists!") );
				return;
			}
		}
		
		if( ui.RB_Typical->isChecked() )
		{
			ui.Wizard_Pages->setCurrentWidget( ui.Typical_HDD_Page );
			ui.Label_Page->setText( tr("Hard Disk Size") );
		}
		else
		{
			ui.Wizard_Pages->setCurrentWidget( ui.Memory_Page );
			ui.Label_Page->setText( tr("Memory") );
		}
	}
	else if( ui.Memory_Page == ui.Wizard_Pages->currentWidget() )
	{
		ui.Wizard_Pages->setCurrentWidget( ui.Custom_HDD_Page );
		ui.Label_Page->setText( tr("Virtual Hard Disk") );
	}
	else if( ui.Typical_HDD_Page == ui.Wizard_Pages->currentWidget() )
	{
		ui.Wizard_Pages->setCurrentWidget( ui.Network_Page );
		ui.Label_Page->setText( tr("Network") );
	}
	else if( ui.Custom_HDD_Page == ui.Wizard_Pages->currentWidget() )
	{
		ui.Wizard_Pages->setCurrentWidget( ui.Network_Page );
		ui.Label_Page->setText( tr("Network") );
	}
	else if( ui.Network_Page == ui.Wizard_Pages->currentWidget() )
	{
		ui.Wizard_Pages->setCurrentWidget( ui.Finish_Page );
		ui.Button_Next->setText( tr("&Finish") );
		ui.Label_Page->setText( tr("Finish!") );
	}
	else if( ui.Finish_Page == ui.Wizard_Pages->currentWidget() )
	{
		if( Create_New_VM() )
		{
			accept();
		}
	}
	else
	{
		AQError( "void VM_Wizard_Window::on_Button_Next_clicked()",
				 "Default Section!" );
	}
}

bool VM_Wizard_Window::Load_OS_Templates()
{
	QList<QString> tmp_list = Get_Templates_List();
	
	for( int ax = 0; ax < tmp_list.count(); ++ax )
	{
		OS_Templates_List.append( QFileInfo(tmp_list[ax]) );
	}

	for( int ix = 0; ix < OS_Templates_List.count(); ++ix )
	{
		ui.CB_OS_Type->addItem( OS_Templates_List[ix].completeBaseName() );
	}
	
	if( ui.CB_OS_Type->count() < 2 ) // no items found
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool VM_Wizard_Window::Create_New_VM()
{
	// Icon
	QString icon_path = Find_OS_Icon( ui.Edit_VM_Name->text() );
	if( icon_path.isEmpty() )
	{
		AQWarning( "void VM_Wizard_Window::Create_New_VM()", "Icon for new VM not Found!" );
		New_VM->Set_Icon_Path( "other.png" );
	}
	else
	{
		New_VM->Set_Icon_Path( icon_path );
	}
	
	// Name
	New_VM->Set_Machine_Name( ui.Edit_VM_Name->text() );
	
	// Create path valid string
	QString VM_File_Name = Get_FS_Compatible_VM_Name( ui.Edit_VM_Name->text() );
	
	// Set Computer Type?
	if( ui.RB_Generate_VM->isChecked() )
	{
		New_VM->Set_Computer_Type( System_Info::VM_Computers[ui.CB_Computer_Type->currentIndex()-1].System.QEMU_Name );
	}
	
	// RAM
	New_VM->Set_Memory_Size( ui.Memory_Size->value() );
	
	// Wizard Mode
	if( ui.RB_Typical->isChecked() )
	{
		// Hard Disk
		VM::Device_Size hd_size;
		hd_size.Size = ui.SB_HDD_Size->value();
		hd_size.Suffix = VM::Size_Suf_Gb;
		
		QString hd_path = Settings.value( "VM_Directory", "~" ).toString()
				+ VM_File_Name;
		
		Create_New_HDD_Image( hd_path + "_HDA.img", hd_size );
		
		New_VM->Set_HDA( VM_HDD(true, hd_path + "_HDA.img") );
		
		// Other HDD's
		if( New_VM->Get_HDB().Get_Enabled() )
		{
			Create_New_HDD_Image( hd_path + "_HDB.img", New_VM->Get_HDB().Get_Virtual_Size() );
			New_VM->Set_HDB( VM_HDD(true, hd_path + "_HDB.img") );
		}
		
		if( New_VM->Get_HDC().Get_Enabled() )
		{
			Create_New_HDD_Image( hd_path + "_HDC.img", New_VM->Get_HDC().Get_Virtual_Size() );
			New_VM->Set_HDC( VM_HDD(true, hd_path + "_HDC.img") );
		}
		
		if( New_VM->Get_HDD().Get_Enabled() )
		{
			Create_New_HDD_Image( hd_path + "_HDD.img", New_VM->Get_HDD().Get_Virtual_Size() );
			New_VM->Set_HDD( VM_HDD(true, hd_path + "_HDD.img") );
		}
	}
	else
	{
		// CPU Type
		int sys_index = -1;
		
		if( ui.RB_VM_Template->isChecked() )
		{
			// Find QEMU System Name in VM
			for( int sx = 0; sx < System_Info::VM_Computers.count(); ++sx )
			{
				if( System_Info::VM_Computers[sx].System.QEMU_Name == New_VM->Get_Computer_Type() )
				{
					sys_index = sx;
					break;
				}
			}
		}
		else
		{
			// Find QEMU System Name in CB_Computer_Type
			for( int sx = 0; sx < System_Info::VM_Computers.count(); ++sx )
			{
				if( ui.CB_Computer_Type->currentText() == System_Info::VM_Computers[sx].System.Caption )
				{
					sys_index = sx;
					break;
				}
			}
		}
		
		if( sys_index == -1 )
		{
			AQGraphic_Error( "bool VM_Wizard_Window::Create_New_VM()", tr("Error!"),
							 tr("Cannot Find QEMU System ID!") );
			return false;
		}
		
		New_VM->Set_CPU_Type( System_Info::VM_Computers[sys_index].CPU_List[ui.CB_CPU_Type->currentIndex()].QEMU_Name );
		
		// Hard Disk
		if( ! ui.Edit_HDA_File_Name->text().isEmpty() )
		{
			New_VM->Set_HDA( VM_HDD(true, ui.Edit_HDA_File_Name->text()) );
		}
		else
		{
			New_VM->Set_HDA( VM_HDD(false, "") );
		}
	}
	
	// Network
	if( ui.RB_User_Mode_Network->isChecked() )
	{
		if( New_VM->Get_Network_Cards_Count() == 0 )
		{
			New_VM->Set_Use_Network( true );
			VM_Net_Card net_card;
			net_card.Set_Net_Mode( VM::Net_Mode_Usermode );
			
			New_VM->Add_Network_Card( net_card );
		}
	}
	else if( ui.RB_No_Network->isChecked() )
	{
		New_VM->Set_Use_Network( false );
		
		for( int rx = 0; rx < New_VM->Get_Network_Cards_Count(); ++rx )
		{
			New_VM->Delete_Network_Card( 0 );
		}
	}
	
	// Create New VM XML File
	New_VM->Create_VM_File( Settings.value("VM_Directory", "~").toString() + VM_File_Name + ".aqemu", false );
	
	return true;
}

QString VM_Wizard_Window::Find_OS_Icon( const QString os_name )
{
	if( os_name.isEmpty() )
	{
		AQError( "QString VM_Wizard_Window::Find_OS_Icon( const QString os_name )",
				 "os_name is Empty!" );
		return "";
	}
	else
	{
		// Find all os icons
		QDir icons_dir( Settings.value("AQEMU_Data_Folder","").toString() + "/os_icons/" );
		QFileInfoList all_os_icons = icons_dir.entryInfoList( QStringList("*.png"),
				QDir::Files, QDir::Unsorted );
		
		QRegExp rex;
		rex.setPatternSyntax( QRegExp::Wildcard );
		rex.setCaseSensitivity( Qt::CaseInsensitive );
		
		for( int i = 0; i < all_os_icons.count(); i++ )
		{
			rex.setPattern( "*" + all_os_icons[i].baseName() + "*" );
			
			if( rex.exactMatch(os_name) )
			{
				return all_os_icons[ i ].absoluteFilePath();
			}
		}
		
		// select os family...
		
		// Linux
		rex.setPattern( "*linux*" );
		if( rex.exactMatch(os_name) )
		{
			return ":/images/default_linux.png";
		}
		
		// Windows
		rex.setPattern( "*windows*" );
		if( rex.exactMatch(os_name) )
		{
			return ":/images/default_windows.png";
		}
		
		return ":/images/other.png";
	}
}

void VM_Wizard_Window::on_RB_VM_Template_toggled( bool on )
{
	if( on )
	{
		if( ui.CB_OS_Type->currentIndex() == 0 )
		{
			ui.Button_Next->setEnabled( false );
		}
		else
		{
			ui.Button_Next->setEnabled( true );
		}
	}
}

void VM_Wizard_Window::on_RB_Generate_VM_toggled( bool on )
{
	if( on )
	{
		if( ui.CB_Computer_Type->currentIndex() == 0 ||
		  	ui.CB_Relese_Date->currentIndex() == 0 )
		{
			ui.Button_Next->setEnabled( false );
		}
		else
		{
			ui.Button_Next->setEnabled( true );
		}
	}
}

void VM_Wizard_Window::on_CB_OS_Type_currentIndexChanged( int index )
{
	if( index == 0 )
	{
		ui.Button_Next->setEnabled( false );
	}
	else
	{
		ui.Button_Next->setEnabled( true );
	}
}

void VM_Wizard_Window::on_CB_Computer_Type_currentIndexChanged( int index )
{
	if( index == 0 )
	{
		ui.Button_Next->setEnabled( false );
	}
	else
	{
		if( ui.CB_Relese_Date->currentIndex() != 0 )
		{
			ui.Button_Next->setEnabled( true );
		}
	}
}

void VM_Wizard_Window::on_CB_Relese_Date_currentIndexChanged( int index )
{
	if( index == 0 )
	{
		ui.Button_Next->setEnabled( false );
	}
	else
	{
		if( ui.CB_Computer_Type->currentIndex() != 0 )
		{
			ui.Button_Next->setEnabled( true );
		}
	}
}

void VM_Wizard_Window::on_Edit_VM_Name_textEdited( const QString &text )
{
	if( ui.Edit_VM_Name->text().isEmpty() )
		ui.Button_Next->setEnabled( false );
	else
		ui.Button_Next->setEnabled( true );
}

void VM_Wizard_Window::on_Check_Host_Mem_stateChanged( int state )
{
	int mes_size = System_Info::Get_Free_Memory_Size();
	
	switch( state )
	{
		case Qt::Checked:
			ui.Memory_Size->setMaximum( mes_size );
			ui.label_max_mem->setText( QString::number(mes_size, 10) + tr(" MB") );
			ui.Mem_Size_Spin->setMaximum( mes_size );
			break;
			
		case Qt::Unchecked:
			ui.Memory_Size->setMaximum( 2048 );
			ui.label_max_mem->setText( tr("2048 MB") );
			ui.Mem_Size_Spin->setMaximum( 2048 );
			break;
			
		default:
			ui.Memory_Size->setMaximum( 2048 );
			ui.label_max_mem->setText( tr("2048 MB") );
			ui.Mem_Size_Spin->setMaximum( 2048 );
			break;
	}
}

void VM_Wizard_Window::on_Button_New_HDD_clicked()
{
	Create_HDD_Image_Window *Create_HDD_Win = new Create_HDD_Image_Window( this );
	
	Create_HDD_Win->Set_Image_Size( ui.SB_HDD_Size->value() ); // Set Initial HDA Size
	
	if( Create_HDD_Win->exec() == QDialog::Accepted )
	{
		ui.Edit_HDA_File_Name->setText( Create_HDD_Win->Get_Image_File_Name() );
	}
	
	delete Create_HDD_Win;
}

void VM_Wizard_Window::on_Button_Existing_clicked()
{
	QString hdd_path = QFileDialog::getOpenFileName( this,
			tr("Select HDD Image"), "/", tr("All Files (*)") );
	ui.Edit_HDA_File_Name->setText( hdd_path );
}
