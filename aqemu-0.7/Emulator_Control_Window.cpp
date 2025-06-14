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

#include <QUuid>
#include <QDir>
#include <QCloseEvent>
#include <QLineEdit>
#include <QFileDialog>
#include <QInputDialog>
#include <QMessageBox>
#include <QDesktopWidget>
#include <QTest>

#include "Utils.h"
#include "Ports_Tab_Widget.h"
#include "Emulator_Control_Window.h"
#include "System_Info.h"
#include "Snapshots_Window.h"

Emulator_Control_Window::Emulator_Control_Window( QWidget *parent )
	: QMainWindow( parent )
{
	ui.setupUi( this );
	
	First_Start = true;
	
	Show_Close_Warning = true;
	Mon_Win = new Monitor_Window();
	
	AQDebug( "Emulator_Control_Window::Emulator_Control_Window( QWidget *parent )",
			 "Created" );
}

void Emulator_Control_Window::Apply_Full_Size( int w, int h )
{
	if( ! ui.actionDisplay_Scaling->isChecked() )
	{
		setMaximumSize( w, h + menuWidget()->height() );
		
		QDesktopWidget desktop;
		
		if( desktop.screenGeometry(desktop.primaryScreen()).width() > w )
		{
			resize( w, h + menuWidget()->height() );
		}
	}
	else
	{
		setMaximumSize( 4096, 2048 );
	}
}

void Emulator_Control_Window::QEMU_Quit()
{
	#ifdef VNC_DISPLAY
	if( Machine_View &&
		Settings.value("Use_VNC_Display", "yes").toString() == "yes" &&
		Cur_VM->Use_VNC() == false )
	{
		Machine_View->disconnectVNC();
	}
	#endif
}

void Emulator_Control_Window::closeEvent( QCloseEvent *event )
{
	#ifdef VNC_DISPLAY
	if( this->isVisible() == false || Show_Close_Warning == false )
	{
		if( Settings.value("Use_VNC_Display", "yes").toString() == "yes" &&
			ui.actionFullscreen_Mode->isChecked() )
		{
			Machine_View->Set_Scaling( ui.actionDisplay_Scaling->isChecked() );
			Machine_View->Set_Fullscreen( false );
		}
		
		Mon_Win->hide();
		event->accept();
		return;
	}
	
	if( Settings.value("Use_VNC_Display", "yes").toString() == "yes" && Cur_VM->Use_VNC() == false )
	{
		int ret = QMessageBox::question( this, tr("Power Off This VM?"),
										 tr("This VM is Running, Off Power?"),
										 QMessageBox::Yes | QMessageBox::Save | QMessageBox::Close | QMessageBox::Cancel,
										 QMessageBox::Cancel );
		
		if( ret == QMessageBox::Yes )
		{
			on_actionPower_Off_triggered();
			
			Mon_Win->hide();
			event->accept();
			return;
		}
		else if( ret == QMessageBox::Save )
		{
			on_actionSave_VM_triggered();
			
			Mon_Win->hide();
			event->accept();
			return;
		}
		else if( ret == QMessageBox::Cancel )
		{
			event->ignore();
			return;
		}
		
		// For Section QMessageBox::Close Next Code
	}
	#endif
	
	Mon_Win->hide();
	event->accept();
}

void Emulator_Control_Window::Set_Current_VM( Virtual_Machine *vm )
{
	if( vm == NULL ) return;
	
	Cur_VM = vm;
	
	connect( Cur_VM, SIGNAL(QEMU_End()),
			 this, SLOT(QEMU_Quit()) );
	
	#ifdef VNC_DISPLAY
	if( Settings.value("Use_VNC_Display", "yes").toString() == "yes" && Cur_VM->Use_VNC() == false )
	{
		this->setWindowTitle( Cur_VM->Get_Machine_Name() );
		
		connect( Cur_VM, SIGNAL(Loading_Complete()),
				 this, SLOT(Connect_VNC()) );
	}
	#else
	this->setWindowTitle( Cur_VM->Get_Machine_Name() + tr(" (Emulator Control)") );
	#endif
	
	// USB
	for( int ix = 0; ix < Cur_VM->Get_USB_Ports_Count(); ++ix )
	{
		QAction *new_act = new QAction( Cur_VM->Get_USB_Port(ix).Get_Product_Name(), ui.menuDisconnect );
		new_act->setData( Cur_VM->Get_USB_Port(ix).Get_ID_Line() );
		
		connect( new_act, SIGNAL(triggered()),
				 this, SLOT(Delete_USB_From_VM()) );
		
		ui.menuDisconnect->addAction( new_act );
	}
}

void Emulator_Control_Window::Init()
{
	First_Start = false;
	Show_Close_Warning = true;
	
	// Create Recent Menu Items
	int max = Settings.value( "CD_ROM_Exits_Images/Max", "5" ).toString().toInt();
	
	for( int ix = 0; ix < max; ++ix )
	{
		QAction *tmp_act = new QAction( this );
		Recent_Files_Items << tmp_act;
		
		Recent_Files_Items[ ix ]->setText( "" );
		Recent_Files_Items[ ix ]->setData( "" );
		Recent_Files_Items[ ix ]->setVisible( false );
		
		connect( Recent_Files_Items[ix], SIGNAL(triggered()),
				 this, SLOT(Open_Recent_CD_ROM_Image()) );
	}
	
	Update_Recent_CD_ROM_Images_List();
	
	// Use VNC Embedded Display
	#ifdef VNC_DISPLAY
	if( Settings.value("Use_VNC_Display", "yes").toString() == "yes" && Cur_VM->Use_VNC() == false )
	{
		if( Cur_VM->Use_VNC() )
		{
			ui.menuView->setEnabled( false );
			return;
		}
		
		setMaximumSize( 4096, 2048 );
		
		// Add VNC Display Widget
		if( ! Machine_View )
		{
			delete Machine_View;
		}
		
		Machine_View = new MachineView( this );
		
		QVBoxLayout *vnc_layout = new QVBoxLayout( centralWidget() );
		vnc_layout->setContentsMargins( 0, 1, 0, 1 );
		vnc_layout->setSizeConstraint( QLayout::SetMaximumSize );
		
		Machine_View->setLayout( vnc_layout );
		
		setCentralWidget( Machine_View );
		
		connect( Machine_View, SIGNAL(Full_Size(int,int)),
				 this, SLOT(Apply_Full_Size(int,int)) );
		
		Machine_View->Set_VNC_URL( "localhost", Cur_VM->Get_Embedded_Display_Port() +
				(Settings.value("First_VNC_Port", "6000").toString().toInt()) );
		
		
		//Machine_View->initView();
	}
	#else
	ui.menuView->setEnabled( false );
	#endif
}

void Emulator_Control_Window::Set_Show_Close_Warning( bool on )
{
	Show_Close_Warning = on;
}

void Emulator_Control_Window::on_actionSave_Screenshot_triggered()
{
	if( Settings.value("Use_Screenshots_Folder", "no").toString() == "yes" )
	{
		if( ! Settings.value("Screenshot_Folder_Path", "").toString().isEmpty() )
		{
			// create unique file name
            QString unic_name = QUuid::createUuid().toString();
			unic_name = unic_name.mid( 25, 12 );
			
			// save screenshot
			Cur_VM->Take_Screenshot( Settings.value("Screenshot_Folder_Path", "").toString() +
					unic_name + "." + Settings.value( "Screenshot_Save_Format", "PNG" ).toString() );
		}
	}
	else
	{
		AQGraphic_Warning( "Warning!",
						   "Shared Screenshots Folder Not Enabled!\nPlease Enter Name for New Screenshot." );
		on_actionSave_Screenshot_As_triggered();
	}
}

void Emulator_Control_Window::on_actionSave_Screenshot_As_triggered()
{
	QString file_name = QFileDialog::getSaveFileName( this, tr("Save Screenshot As..."),
													  QDir::homePath(), tr("All Files (*)") );
	
	if( file_name.isEmpty() )
	{
		AQWarning( "void Emulator_Control_Window::on_actionSave_Screenshot_As_triggered()",
				   "File Name is Empty! Screenshot Cannot be Save!" );
		return;
	}
	else
	{
		Cur_VM->Take_Screenshot( file_name );
	}
}

void Emulator_Control_Window::on_actionSave_VM_triggered()
{
	Cur_VM->Save_VM_State();
}

void Emulator_Control_Window::on_actionManage_Snapshots_triggered()
{
	Snapshots_Window *snapshot_win = new Snapshots_Window( this );
	snapshot_win->Set_VM( Cur_VM );
	snapshot_win->exec();
	delete snapshot_win;
}

void Emulator_Control_Window::on_actionCommit_triggered()
{
	emit Ready_Read_Command( "commit all" );
}

void Emulator_Control_Window::on_actionPause_VM_triggered()
{
	Cur_VM->Pause();
}

void Emulator_Control_Window::on_actionPower_Off_triggered()
{
	Cur_VM->Stop();
}

void Emulator_Control_Window::on_actionReset_VM_triggered()
{
	Cur_VM->Reset();
}

void Emulator_Control_Window::on_actionQEMU_Monitor_triggered()
{
	connect( Mon_Win, SIGNAL(Command_Sended(QString)), Cur_VM,
			 SLOT(Execute_Emu_Ctl_Command(QString)) );
	
	connect( Cur_VM, SIGNAL(Clean_Console(QString)), Mon_Win,
			 SLOT(Add_QEMU_Out(QString)) );
	
	Mon_Win->show();
}

void Emulator_Control_Window::on_actionQuit_triggered()
{
	Show_Close_Warning = false;
	this->close();
}

void Emulator_Control_Window::on_actionFD0_dev_fd0_triggered()
{
	if( ! FD0_Available() ) return;
	
	on_actionFD0_Eject_triggered();
	Set_Device( "fda", true, "/dev/fd0" );
}

void Emulator_Control_Window::on_actionFD0_dev_null_triggered()
{
	if( ! FD0_Available() ) return;
	
	on_actionFD0_Eject_triggered();
	Set_Device( "fda", false, "/dev/null" );
}

void Emulator_Control_Window::on_actionFD0_Other_triggered()
{
	if( ! FD0_Available() ) return;
	
	QString prev_file;
	
	if( Cur_VM->Get_FD0().Get_Host_Device() )
	{
		prev_file = Cur_VM->Get_FD0().Get_Host_File_Name();
	}
	else
	{
		prev_file = Cur_VM->Get_FD0().Get_Image_File_Name();
	}
	
	QString file_name = QFileDialog::getOpenFileName( this,
			tr("Open Device or Image File"),
			prev_file, tr("All Files (*);;Images Files (*.img *.ima)") );
	
	if( file_name.isEmpty() )
	{
		AQWarning( "void Emulator_Control_Window::on_actionFD0_Other_triggered()",
				   "Floppy Cannot be Changet! File Name is Empty!" );
		return;
	}
	else
	{
		on_actionFD1_Eject_triggered();
		Set_Device( "fda", false, file_name );
	}
}

void Emulator_Control_Window::on_actionFD0_Eject_triggered()
{
	if( ! FD0_Available() ) return;
	
	QString qemu_version = Settings.value( "QEMU_Version", "Old" ).toString();
	
	if( qemu_version == "0.9.1" ||
		qemu_version == "New"  )
	{
		emit Ready_Read_Command( "eject -f floppy0" );
	}
	else
	{
		emit Ready_Read_Command( "eject -f fda" );
	}
}

void Emulator_Control_Window::on_actionFD1_dev_fd0_triggered()
{
	if( ! FD1_Available() ) return;
	
	on_actionFD0_Eject_triggered();
	Set_Device( "fdb", true, "/dev/fd0" );
}

void Emulator_Control_Window::on_actionFD1_dev_null_triggered()
{
	if( ! FD1_Available() ) return;
	
	on_actionFD0_Eject_triggered();
	Set_Device( "fdb", false, "/dev/null" );
}

void Emulator_Control_Window::on_actionFD1_Other_triggered()
{
	if( ! FD1_Available() ) return;
	
	QString prev_file;
	
	if( Cur_VM->Get_FD1().Get_Host_Device() )
	{
		prev_file = Cur_VM->Get_FD1().Get_Host_File_Name();
	}
	else
	{
		prev_file = Cur_VM->Get_FD1().Get_Image_File_Name();
	}
	
	QString file_name = QFileDialog::getOpenFileName( this,
			tr("Open Device or Image File"),
			prev_file, tr("All Files (*);;Images Files (*.img *.ima)") );
	
	if( file_name.isEmpty() )
	{
		AQWarning( "void Emulator_Control_Window::on_actionFD1_Other_triggered()",
				   "Floppy Cannot be Changet! File Name is Empty!" );
		return;
	}
	else
	{
		on_actionFD1_Eject_triggered();
		Set_Device( "fdb", false, file_name );
	}
}

void Emulator_Control_Window::on_actionFD1_Eject_triggered()
{
	if( ! FD1_Available() ) return;
	
	QString qemu_version = Settings.value( "QEMU_Version", "Old" ).toString();
	
	if( qemu_version == "0.9.1" ||
		qemu_version == "New"  )
	{
		emit Ready_Read_Command( "eject -f floppy1" );
	}
	else
	{
		emit Ready_Read_Command( "eject -f fdb" );
	}
}

void Emulator_Control_Window::on_actionCDROM_dev_cdrom_triggered()
{
	if( ! CD_ROM_Available() ) return;
	
	on_actionCDROM_Eject_triggered();
	Set_Device( "cdrom", true, "/dev/cdrom" );
}

void Emulator_Control_Window::on_actionCDROM_dev_null_triggered()
{
	if( ! CD_ROM_Available() ) return;
	
	on_actionCDROM_Eject_triggered();
	Set_Device( "cdrom", true, "/dev/null" );
}

void Emulator_Control_Window::on_actionCDROM_Other_triggered()
{
	if( ! CD_ROM_Available() ) return;
	
	QString prev_file;
	
	if( Cur_VM->Get_CD_ROM().Get_Host_Device() )
	{
		prev_file = Cur_VM->Get_CD_ROM().Get_Host_File_Name();
	}
	else
	{
		prev_file = Cur_VM->Get_CD_ROM().Get_Image_File_Name();
	}
	
	QString file_name = QFileDialog::getOpenFileName( this,
			tr("Open Device or Image File"),
			prev_file, tr("All Files (*);;Images Files (*.iso)") );
	
	if( file_name.isEmpty() )
	{
		AQWarning( "void Emulator_Control_Window::on_actionCDROM_Other_triggered()",
				   "CD-ROM Cannot be Changet! File Name is Empty!" );
		return;
	}
	else
	{
		on_actionCDROM_Eject_triggered();
		Set_Device( "cdrom", false, file_name );
		
		// Add to Recent Menu
		Add_To_Recent_Files( file_name );
		Update_Recent_CD_ROM_Images_List();
	}
}

void Emulator_Control_Window::on_actionCDROM_Eject_triggered()
{
	if( ! CD_ROM_Available() ) return;
	
	QString qemu_version = Settings.value( "QEMU_Version", "Old" ).toString();
	
	if( qemu_version == "0.9.1" ||
		qemu_version == "New"  )
	{
		emit Ready_Read_Command( "eject -f ide1-cd0" );
	}
	else
	{
		emit Ready_Read_Command( "eject -f cdrom" );
	}
}

void Emulator_Control_Window::Open_Recent_CD_ROM_Image()
{
	QAction *tmp_act = qobject_cast<QAction*>( sender() );
	
	if( tmp_act )
	{
		if( ! CD_ROM_Available() ) return;
	
		on_actionCDROM_Eject_triggered();
		Set_Device( "cdrom", true, tmp_act->data().toString() );
	}
}

void Emulator_Control_Window::Delete_USB_From_VM()
{
	QAction *usb_item = qobject_cast<QAction*>( sender() );
	
	if( usb_item )
	{
		QList<QAction*> ac_list = ui.menuDisconnect->actions();
		
		for( int ix = 0; ix < ac_list.count(); ++ix )
		{
			if( usb_item->data().toString() == ac_list[ix]->data().toString() )
			{
				// Delete from Running VM
				QString bus_addr = Cur_VM->Get_USB_Bus_Address( usb_item->data().toString() );
				
				if( bus_addr.isEmpty() ) return;
				
				emit Ready_Read_Command( "usb_del " + bus_addr );
				
				// Delete item
				ui.menuDisconnect->removeAction( usb_item );
				
				return;
			}
		}
		
		// Cannot Find
		AQGraphic_Error( "void Emulator_Control_Window::Delete_USB_From_VM()",
						 tr("Error!"), tr("Cannot Find USB Device!"), false );
	}
	else
	{
		AQError( "void Emulator_Control_Window::Delete_USB_From_VM()",
				 "Cannot convert to QAction!" );
	}
}

void Emulator_Control_Window::Add_USB_To_VM()
{
	QAction *usb_item = qobject_cast<QAction*>( sender() );
	
	if( usb_item )
	{
		QList<QAction*> ac_list = ui.menuDisconnect->actions();
		
		for( int ix = 0; ix < ac_list.count(); ++ix )
		{
			// Unique value
			if( usb_item->data().toString() == ac_list[ix]->data().toString() )
			{
				AQWarning( "void Emulator_Control_Window::Add_USB_To_VM()",
						   "This is not unique value: " + usb_item->data().toString() );
				return;
			}
		}
		
		// Create Item for Disconnect Menu
		QAction *dis_act = new QAction( usb_item->text(), ui.menuDisconnect );
		dis_act->setData( usb_item->data() );
		
		connect( dis_act, SIGNAL(triggered()), this, SLOT(Delete_USB_From_VM()) );
		
		ui.menuDisconnect->addAction( dis_act );
		
		// Add To Running VM
		emit Ready_Read_Command( "usb_add host:" + usb_item->data().toString() );
	}
	else
	{
		AQError( "void Emulator_Control_Window::Add_USB_To_VM()",
				 "Cannot convert to QAction!" );
	}
}

void Emulator_Control_Window::on_actionUSB_Update_Device_List_triggered()
{
	// Get New USB Host List
	QList<VM_USB> tmp_list;
	
	if( ! System_Info::Get_All_Host_USB(tmp_list) )
	{
		AQGraphic_Warning( tr("Error!"),
						   tr("Cannot Get USB Information From System!") );
		return;
	}
	
	QList<QAction*> ac_list = ui.menuUSB_Connect->actions();
	
	// Delete Previous Menu (is avirable)
	if( ac_list.count() > 1 )
	{
		ui.menuUSB_Connect->clear();
		
		ui.menuUSB_Connect->addAction( ui.actionUSB_Update_Device_List );
		ui.menuUSB_Connect->addSeparator();
	}
	
	// Add items
	for( int ix = 0; ix < tmp_list.count(); ++ix )
	{
		QAction *new_act = new QAction( tmp_list[ix].Get_Product_Name(), ui.menuUSB_Connect );
		new_act->setData( tmp_list[ix].Get_ID_Line() );
		
		connect( new_act, SIGNAL(triggered()), this, SLOT(Add_USB_To_VM()) );
		
		ui.menuUSB_Connect->addAction( new_act );
	}
}

void Emulator_Control_Window::on_actionBy_Bus_Address_triggered()
{
	bool ok = false;
	
	QString bus_addr = QInputDialog::getText( this, tr("Disconnect USB"),
										  tr("Enter You Bus.Address VM USB Value"),
										  QLineEdit::Normal, "", &ok );
	
	if( ok && ! bus_addr.isEmpty() )
	{
		emit Ready_Read_Command( "usb_del " + bus_addr );
	}
}

void Emulator_Control_Window::on_actionUSB_Disconnect_All_Devices_triggered()
{
	QList<QAction*> ac_list = ui.menuDisconnect->actions();
	
	for( int dx = 0; dx < ac_list.count(); ++dx )
	{
		if( ac_list[dx]->data().isNull() == false &&
			ac_list[dx]->data().isValid() == true )
		{
			QString bus_addr = Cur_VM->Get_USB_Bus_Address( ac_list[dx]->data().toString() );
			
			if( bus_addr.isEmpty() ) return;
			
			emit Ready_Read_Command( "usb_del " + bus_addr );
		}
	}
	
	ui.menuDisconnect->clear();
	ui.menuDisconnect->addAction( ui.actionUSB_Disconnect_All_Devices );
	ui.menuDisconnect->addAction( ui.actionBy_Bus_Address );
	ui.menuDisconnect->addSeparator();
}

void Emulator_Control_Window::on_actionCtrl_Alt_Delete_triggered()
{
	emit Ready_Read_Command( "sendkey ctrl-alt-delete" );
}

void Emulator_Control_Window::on_actionOther_Keys_triggered()
{
	bool ok = false;
	
	QString keys = QInputDialog::getText( this, tr("Send Keys"),
			tr("Enter You Keys as ctrl-alt-delete or alt-f2"),
			QLineEdit::Normal, "", &ok );
	
	if( ok && ! keys.isEmpty() )
	{
		emit Ready_Read_Command( "sendkey " + keys );
	}
}

void Emulator_Control_Window::on_actionCtrl_Alt_Backspace_triggered()
{
	emit Ready_Read_Command( "sendkey ctrl-alt-backspace" );
}

void Emulator_Control_Window::on_actionCtrl_Alt_F1_triggered()
{
	emit Ready_Read_Command( "sendkey ctrl-alt-f1" );
}

void Emulator_Control_Window::on_actionCtrl_Alt_F2_triggered()
{
	emit Ready_Read_Command( "sendkey ctrl-alt-f2" );
}

void Emulator_Control_Window::on_actionCtrl_Alt_F3_triggered()
{
	emit Ready_Read_Command( "sendkey ctrl-alt-f3" );
}

void Emulator_Control_Window::on_actionCtrl_Alt_F4_triggered()
{
	emit Ready_Read_Command( "sendkey ctrl-alt-f4" );
}

void Emulator_Control_Window::on_actionCtrl_Alt_F5_triggered()
{
	emit Ready_Read_Command( "sendkey ctrl-alt-f5" );
}

void Emulator_Control_Window::on_actionCtrl_Alt_F6_triggered()
{
	emit Ready_Read_Command( "sendkey ctrl-alt-f6" );
}

void Emulator_Control_Window::on_actionCtrl_Alt_F7_triggered()
{
	emit Ready_Read_Command( "sendkey ctrl-alt-f7" );
}

void Emulator_Control_Window::on_actionCtrl_Alt_F8_triggered()
{
	emit Ready_Read_Command( "sendkey ctrl-alt-f8" );
}

void Emulator_Control_Window::on_actionCtrl_Alt_F9_triggered()
{
	emit Ready_Read_Command( "sendkey ctrl-alt-f9" );
}

void Emulator_Control_Window::on_actionCtrl_Alt_F10_triggered()
{
	emit Ready_Read_Command( "sendkey ctrl-alt-f10" );
}

void Emulator_Control_Window::on_actionCtrl_Alt_F11_triggered()
{
	emit Ready_Read_Command( "sendkey ctrl-alt-f11" );
}

void Emulator_Control_Window::on_actionCtrl_Alt_F12_triggered()
{
	emit Ready_Read_Command( "sendkey ctrl-alt-f12" );
}

#ifdef VNC_DISPLAY

void Emulator_Control_Window::on_actionDisplay_Scaling_triggered()
{
	Machine_View->Set_Scaling( ui.actionDisplay_Scaling->isChecked() );
}

void Emulator_Control_Window::on_actionFullscreen_Mode_triggered()
{
	static bool act_add = true;
	
	if( act_add )
	{
		Machine_View->addAction( ui.actionFullscreen_Mode );
		act_add = false;
	}
	
	setMaximumSize( 4096, 2048 );
	Machine_View->Set_Scaling( ui.actionFullscreen_Mode->isChecked() );
	Machine_View->Set_Fullscreen( ui.actionFullscreen_Mode->isChecked() );
}

void Emulator_Control_Window::on_actionReinit_VNC_triggered()
{
	Machine_View->initView();
}

void Emulator_Control_Window::Connect_VNC()
{/*
	static int init_count = 0;
	++init_count; AQError( "init_count", QString::number(init_count) );
	
	if( init_count == 2) Machine_View->initView();*/
	Machine_View->initView();
}

#endif

void Emulator_Control_Window::on_actionAbout_Emulator_Control_triggered()
{
	QMessageBox::information( this, tr("About Emulator Control..."),
							  tr("Emulator Control is a Tool for Managing QEMU in Runtime.") );
}

bool Emulator_Control_Window::FD0_Available()
{
	if( Cur_VM->Get_FD0().Get_Enabled() == false )
	{
		QMessageBox::information( this, tr("Warning!"), tr("In This VM Floppy 1 Not Found!") );
		return false;
	}
	else
	{
		return true;
	}
}

bool Emulator_Control_Window::FD1_Available()
{
	if( Cur_VM->Get_FD1().Get_Enabled() == false )
	{
		QMessageBox::information( this, tr("Warning!"), tr("In This VM Floppy 2 Not Found!") );
		return false;
	}
	else
	{
		return true;
	}
}

bool Emulator_Control_Window::CD_ROM_Available()
{
	if( Cur_VM->Get_HDC().Get_Enabled() == true ||
		Cur_VM->Get_CD_ROM().Get_Enabled() == false )
	{
		QMessageBox::information( this, tr("Warning!"), tr("In This VM CD-ROM Not Found!") );
		return false;
	}
	else
	{
		return true;
	}
}

void Emulator_Control_Window::Update_Recent_CD_ROM_Images_List()
{
	// Clear Menu
	for( int dx = 0; dx < Recent_Files_Items.count(); ++dx )
	{
		Recent_Files_Items[ dx ]->setText( "" );
		Recent_Files_Items[ dx ]->setData( "" );
		Recent_Files_Items[ dx ]->setVisible( false );
	}
	
	// Add New
	int max = Settings.value( "CD_ROM_Exits_Images/Max", "5" ).toString().toInt();
	
	while( max > Recent_Files_Items.count() )
	{
		QAction *tmp_act = new QAction( this );
		Recent_Files_Items << tmp_act;
		
		Recent_Files_Items[ Recent_Files_Items.count() -1 ]->setText( "" );
		Recent_Files_Items[ Recent_Files_Items.count() -1 ]->setData( "" );
		Recent_Files_Items[ Recent_Files_Items.count() -1 ]->setVisible( false );
		
		connect( Recent_Files_Items[Recent_Files_Items.count() -1], SIGNAL(triggered()),
				 this, SLOT(Open_Recent_CD_ROM_Image()) );
	}
	
	for( int ix = 0; ix < max; ++ix )
	{
		if( ix < Get_CD_Recent_Images_List().count() && Get_CD_Recent_Images_List()[ix].isEmpty() == false )
		{
			QFileInfo info = QFileInfo( Get_CD_Recent_Images_List()[ix] );
			
			Recent_Files_Items[ ix ]->setText( info.fileName() );
			Recent_Files_Items[ ix ]->setData( Get_CD_Recent_Images_List()[ix] );
			Recent_Files_Items[ ix ]->setVisible( true );
			
			ui.menuCDROM_Recent_Files->addAction( Recent_Files_Items[ix] );
		}
	}
}

void Emulator_Control_Window::Set_Device( const QString &dev_name, bool host_dev, const QString &path )
{
	QString qemu_version = Settings.value( "QEMU_Version", "Old" ).toString();
	
	if( qemu_version == "0.9.1" ||
		qemu_version == "New"  )
	{
		QString new_dev_name;
		
		if( dev_name == "fda" )
		{
			new_dev_name = "floppy0";
		}
		else if( dev_name == "fdb" )
		{
			new_dev_name = "floppy1";
		}
		else if( dev_name == "cdrom" )
		{
			new_dev_name = "ide1-cd0";
		}
		else
		{
			AQError( "void Emulator_Control_Window::Set_Device( const QString &dev_name, const QString &path )",
					 "Cannot Found Device: " + dev_name );
		}
		
		emit Ready_Read_Command( "change " + new_dev_name + " \"" + path + "\"" );
	}
	else
	{
		// For Version 0.9.0 and Old
		emit Ready_Read_Command( "change " + dev_name + " \"" + path + "\"" );
	}
	
	if( dev_name == "fda" )
	{
		Cur_VM->Set_FD0( VM_Floppy(true, host_dev ? path : "",
						 ! host_dev ? path : "", host_dev) );
	}
	else if( dev_name == "fdb" )
	{
		Cur_VM->Set_FD1( VM_Floppy(true, host_dev ? path : "",
						 ! host_dev ? path : "", host_dev) );
	}
	else if( dev_name == "cdrom" )
	{
		Cur_VM->Set_CD_ROM( VM_CDROM(true, host_dev ? path : "",
							! host_dev ? path : "", host_dev) );
	}
	else
	{
		AQError( "void Emulator_Control_Window::Set_Device( const QString &dev_name, const QString &path )",
				 "Cannot Found Device: " + dev_name );
	}
}
