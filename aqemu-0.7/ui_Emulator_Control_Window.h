/********************************************************************************
** Form generated from reading UI file 'Emulator_Control_Window.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EMULATOR_CONTROL_WINDOW_H
#define UI_EMULATOR_CONTROL_WINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Emulator_Control_Window
{
public:
    QAction *actionSave_Screenshot;
    QAction *actionSave_VM;
    QAction *actionLoad_VM;
    QAction *actionPause_VM;
    QAction *actionQuit;
    QAction *actionSave_VM_State_As;
    QAction *actionLoad_VM_State;
    QAction *actionReset_VM;
    QAction *actionPower_Off;
    QAction *actionCommit;
    QAction *actionCtrl_Alt_Delete;
    QAction *actionCtrl_Alt_F1;
    QAction *actionCtrl_Alt_F2;
    QAction *actionCtrl_Alt_F3;
    QAction *actionCtrl_Alt_F4;
    QAction *actionCtrl_Alt_F5;
    QAction *actionCtrl_Alt_F6;
    QAction *actionCtrl_Alt_F7;
    QAction *actionCtrl_Alt_F8;
    QAction *actionCtrl_Alt_F9;
    QAction *actionCtrl_Alt_F10;
    QAction *actionCtrl_Alt_F11;
    QAction *actionCtrl_Alt_F12;
    QAction *actionFD0_dev_fd0;
    QAction *actionFD0_dev_null;
    QAction *actionFD0_Other;
    QAction *actionFD0_Eject;
    QAction *actionUSB_Update_Device_List;
    QAction *actionAbout_Emulator_Control;
    QAction *actionFD1_dev_fd0;
    QAction *actionFD1_Other;
    QAction *actionFD1_Eject;
    QAction *actionFD1_dev_null;
    QAction *actionCDROM_dev_cdrom;
    QAction *actionCDROM_Other;
    QAction *actionCDROM_Eject;
    QAction *actionSave_Screenshot_As;
    QAction *actionCDROM_dev_null;
    QAction *actionUSB_Disconnect_All_Devices;
    QAction *actionOther_Keys;
    QAction *actionQEMU_Monitor;
    QAction *actionCtrl_Alt_Backspace;
    QAction *actionSerial_Null;
    QAction *actionStdio_Standard_In_Out;
    QAction *actionSerial_Other;
    QAction *action_Serial_ttyS0;
    QAction *actionParport_Other;
    QAction *actionParport_Null;
    QAction *actionBy_Bus_Address;
    QAction *actionManage_Snapshots;
    QAction *actionD;
    QAction *actionDisplay_Scaling;
    QAction *actionFullscreen_Mode;
    QAction *actionShow_Status_Bar;
    QAction *actionReinit_VNC;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menuHelp;
    QMenu *menuVM;
    QMenu *menuSend_Keys;
    QMenu *menuCtrl_Alt_F;
    QMenu *menuConnect;
    QMenu *menuFloppy_B;
    QMenu *menuFloppy_A;
    QMenu *menuUSB;
    QMenu *menuUSB_Connect;
    QMenu *menuDisconnect;
    QMenu *menuCD_ROM;
    QMenu *menuCDROM_Recent_Files;
    QMenu *menuView;

    void setupUi(QMainWindow *Emulator_Control_Window)
    {
        if (Emulator_Control_Window->objectName().isEmpty())
            Emulator_Control_Window->setObjectName(QString::fromUtf8("Emulator_Control_Window"));
        Emulator_Control_Window->setWindowModality(Qt::WindowModal);
        Emulator_Control_Window->resize(480, 25);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Emulator_Control_Window->sizePolicy().hasHeightForWidth());
        Emulator_Control_Window->setSizePolicy(sizePolicy);
        Emulator_Control_Window->setMaximumSize(QSize(2048, 25));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/configure.png"), QSize(), QIcon::Normal, QIcon::Off);
        Emulator_Control_Window->setWindowIcon(icon);
        actionSave_Screenshot = new QAction(Emulator_Control_Window);
        actionSave_Screenshot->setObjectName(QString::fromUtf8("actionSave_Screenshot"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Menu_16px/images/menu_16_px/filesave.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave_Screenshot->setIcon(icon1);
        actionSave_VM = new QAction(Emulator_Control_Window);
        actionSave_VM->setObjectName(QString::fromUtf8("actionSave_VM"));
        actionSave_VM->setIcon(icon1);
        actionLoad_VM = new QAction(Emulator_Control_Window);
        actionLoad_VM->setObjectName(QString::fromUtf8("actionLoad_VM"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Menu_16px/images/menu_16_px/fileopen.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionLoad_VM->setIcon(icon2);
        actionPause_VM = new QAction(Emulator_Control_Window);
        actionPause_VM->setObjectName(QString::fromUtf8("actionPause_VM"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/Menu_16px/images/menu_16_px/player_pause.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPause_VM->setIcon(icon3);
        actionQuit = new QAction(Emulator_Control_Window);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/Menu_16px/images/menu_16_px/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionQuit->setIcon(icon4);
        actionSave_VM_State_As = new QAction(Emulator_Control_Window);
        actionSave_VM_State_As->setObjectName(QString::fromUtf8("actionSave_VM_State_As"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/Menu_16px/images/menu_16_px/filesaveas.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave_VM_State_As->setIcon(icon5);
        actionLoad_VM_State = new QAction(Emulator_Control_Window);
        actionLoad_VM_State->setObjectName(QString::fromUtf8("actionLoad_VM_State"));
        actionLoad_VM_State->setIcon(icon2);
        actionReset_VM = new QAction(Emulator_Control_Window);
        actionReset_VM->setObjectName(QString::fromUtf8("actionReset_VM"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/Menu_16px/images/menu_16_px/reload.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionReset_VM->setIcon(icon6);
        actionPower_Off = new QAction(Emulator_Control_Window);
        actionPower_Off->setObjectName(QString::fromUtf8("actionPower_Off"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/Menu_16px/images/menu_16_px/player_stop.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPower_Off->setIcon(icon7);
        actionCommit = new QAction(Emulator_Control_Window);
        actionCommit->setObjectName(QString::fromUtf8("actionCommit"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/Menu_16px/images/menu_16_px/save_all.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCommit->setIcon(icon8);
        actionCtrl_Alt_Delete = new QAction(Emulator_Control_Window);
        actionCtrl_Alt_Delete->setObjectName(QString::fromUtf8("actionCtrl_Alt_Delete"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/Menu_16px/images/menu_16_px/keyboard.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCtrl_Alt_Delete->setIcon(icon9);
        actionCtrl_Alt_F1 = new QAction(Emulator_Control_Window);
        actionCtrl_Alt_F1->setObjectName(QString::fromUtf8("actionCtrl_Alt_F1"));
        actionCtrl_Alt_F2 = new QAction(Emulator_Control_Window);
        actionCtrl_Alt_F2->setObjectName(QString::fromUtf8("actionCtrl_Alt_F2"));
        actionCtrl_Alt_F3 = new QAction(Emulator_Control_Window);
        actionCtrl_Alt_F3->setObjectName(QString::fromUtf8("actionCtrl_Alt_F3"));
        actionCtrl_Alt_F4 = new QAction(Emulator_Control_Window);
        actionCtrl_Alt_F4->setObjectName(QString::fromUtf8("actionCtrl_Alt_F4"));
        actionCtrl_Alt_F5 = new QAction(Emulator_Control_Window);
        actionCtrl_Alt_F5->setObjectName(QString::fromUtf8("actionCtrl_Alt_F5"));
        actionCtrl_Alt_F6 = new QAction(Emulator_Control_Window);
        actionCtrl_Alt_F6->setObjectName(QString::fromUtf8("actionCtrl_Alt_F6"));
        actionCtrl_Alt_F7 = new QAction(Emulator_Control_Window);
        actionCtrl_Alt_F7->setObjectName(QString::fromUtf8("actionCtrl_Alt_F7"));
        actionCtrl_Alt_F8 = new QAction(Emulator_Control_Window);
        actionCtrl_Alt_F8->setObjectName(QString::fromUtf8("actionCtrl_Alt_F8"));
        actionCtrl_Alt_F9 = new QAction(Emulator_Control_Window);
        actionCtrl_Alt_F9->setObjectName(QString::fromUtf8("actionCtrl_Alt_F9"));
        actionCtrl_Alt_F10 = new QAction(Emulator_Control_Window);
        actionCtrl_Alt_F10->setObjectName(QString::fromUtf8("actionCtrl_Alt_F10"));
        actionCtrl_Alt_F11 = new QAction(Emulator_Control_Window);
        actionCtrl_Alt_F11->setObjectName(QString::fromUtf8("actionCtrl_Alt_F11"));
        actionCtrl_Alt_F12 = new QAction(Emulator_Control_Window);
        actionCtrl_Alt_F12->setObjectName(QString::fromUtf8("actionCtrl_Alt_F12"));
        actionFD0_dev_fd0 = new QAction(Emulator_Control_Window);
        actionFD0_dev_fd0->setObjectName(QString::fromUtf8("actionFD0_dev_fd0"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/Menu_16px/images/menu_16_px/3floppy_unmount.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionFD0_dev_fd0->setIcon(icon10);
        actionFD0_dev_null = new QAction(Emulator_Control_Window);
        actionFD0_dev_null->setObjectName(QString::fromUtf8("actionFD0_dev_null"));
        actionFD0_Other = new QAction(Emulator_Control_Window);
        actionFD0_Other->setObjectName(QString::fromUtf8("actionFD0_Other"));
        actionFD0_Other->setIcon(icon2);
        actionFD0_Eject = new QAction(Emulator_Control_Window);
        actionFD0_Eject->setObjectName(QString::fromUtf8("actionFD0_Eject"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/Menu_16px/images/menu_16_px/player_eject.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionFD0_Eject->setIcon(icon11);
        actionUSB_Update_Device_List = new QAction(Emulator_Control_Window);
        actionUSB_Update_Device_List->setObjectName(QString::fromUtf8("actionUSB_Update_Device_List"));
        actionAbout_Emulator_Control = new QAction(Emulator_Control_Window);
        actionAbout_Emulator_Control->setObjectName(QString::fromUtf8("actionAbout_Emulator_Control"));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/Menu_16px/images/menu_16_px/help.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAbout_Emulator_Control->setIcon(icon12);
        actionFD1_dev_fd0 = new QAction(Emulator_Control_Window);
        actionFD1_dev_fd0->setObjectName(QString::fromUtf8("actionFD1_dev_fd0"));
        actionFD1_dev_fd0->setIcon(icon10);
        actionFD1_Other = new QAction(Emulator_Control_Window);
        actionFD1_Other->setObjectName(QString::fromUtf8("actionFD1_Other"));
        actionFD1_Other->setIcon(icon2);
        actionFD1_Eject = new QAction(Emulator_Control_Window);
        actionFD1_Eject->setObjectName(QString::fromUtf8("actionFD1_Eject"));
        actionFD1_Eject->setIcon(icon11);
        actionFD1_dev_null = new QAction(Emulator_Control_Window);
        actionFD1_dev_null->setObjectName(QString::fromUtf8("actionFD1_dev_null"));
        actionCDROM_dev_cdrom = new QAction(Emulator_Control_Window);
        actionCDROM_dev_cdrom->setObjectName(QString::fromUtf8("actionCDROM_dev_cdrom"));
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/Menu_16px/images/menu_16_px/cdrom_unmount.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCDROM_dev_cdrom->setIcon(icon13);
        actionCDROM_Other = new QAction(Emulator_Control_Window);
        actionCDROM_Other->setObjectName(QString::fromUtf8("actionCDROM_Other"));
        actionCDROM_Other->setIcon(icon2);
        actionCDROM_Eject = new QAction(Emulator_Control_Window);
        actionCDROM_Eject->setObjectName(QString::fromUtf8("actionCDROM_Eject"));
        actionCDROM_Eject->setIcon(icon11);
        actionSave_Screenshot_As = new QAction(Emulator_Control_Window);
        actionSave_Screenshot_As->setObjectName(QString::fromUtf8("actionSave_Screenshot_As"));
        actionSave_Screenshot_As->setIcon(icon5);
        actionCDROM_dev_null = new QAction(Emulator_Control_Window);
        actionCDROM_dev_null->setObjectName(QString::fromUtf8("actionCDROM_dev_null"));
        actionUSB_Disconnect_All_Devices = new QAction(Emulator_Control_Window);
        actionUSB_Disconnect_All_Devices->setObjectName(QString::fromUtf8("actionUSB_Disconnect_All_Devices"));
        actionOther_Keys = new QAction(Emulator_Control_Window);
        actionOther_Keys->setObjectName(QString::fromUtf8("actionOther_Keys"));
        actionOther_Keys->setIcon(icon9);
        actionQEMU_Monitor = new QAction(Emulator_Control_Window);
        actionQEMU_Monitor->setObjectName(QString::fromUtf8("actionQEMU_Monitor"));
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/Menu_16px/images/menu_16_px/terminal.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionQEMU_Monitor->setIcon(icon14);
        actionCtrl_Alt_Backspace = new QAction(Emulator_Control_Window);
        actionCtrl_Alt_Backspace->setObjectName(QString::fromUtf8("actionCtrl_Alt_Backspace"));
        actionCtrl_Alt_Backspace->setIcon(icon9);
        actionSerial_Null = new QAction(Emulator_Control_Window);
        actionSerial_Null->setObjectName(QString::fromUtf8("actionSerial_Null"));
        actionStdio_Standard_In_Out = new QAction(Emulator_Control_Window);
        actionStdio_Standard_In_Out->setObjectName(QString::fromUtf8("actionStdio_Standard_In_Out"));
        actionSerial_Other = new QAction(Emulator_Control_Window);
        actionSerial_Other->setObjectName(QString::fromUtf8("actionSerial_Other"));
        action_Serial_ttyS0 = new QAction(Emulator_Control_Window);
        action_Serial_ttyS0->setObjectName(QString::fromUtf8("action_Serial_ttyS0"));
        actionParport_Other = new QAction(Emulator_Control_Window);
        actionParport_Other->setObjectName(QString::fromUtf8("actionParport_Other"));
        actionParport_Null = new QAction(Emulator_Control_Window);
        actionParport_Null->setObjectName(QString::fromUtf8("actionParport_Null"));
        actionBy_Bus_Address = new QAction(Emulator_Control_Window);
        actionBy_Bus_Address->setObjectName(QString::fromUtf8("actionBy_Bus_Address"));
        actionManage_Snapshots = new QAction(Emulator_Control_Window);
        actionManage_Snapshots->setObjectName(QString::fromUtf8("actionManage_Snapshots"));
        QIcon icon15;
        icon15.addFile(QString::fromUtf8(":/Menu_16px/images/menu_16_px/clock.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionManage_Snapshots->setIcon(icon15);
        actionD = new QAction(Emulator_Control_Window);
        actionD->setObjectName(QString::fromUtf8("actionD"));
        actionDisplay_Scaling = new QAction(Emulator_Control_Window);
        actionDisplay_Scaling->setObjectName(QString::fromUtf8("actionDisplay_Scaling"));
        actionDisplay_Scaling->setCheckable(true);
        actionFullscreen_Mode = new QAction(Emulator_Control_Window);
        actionFullscreen_Mode->setObjectName(QString::fromUtf8("actionFullscreen_Mode"));
        actionFullscreen_Mode->setCheckable(true);
        actionShow_Status_Bar = new QAction(Emulator_Control_Window);
        actionShow_Status_Bar->setObjectName(QString::fromUtf8("actionShow_Status_Bar"));
        actionShow_Status_Bar->setCheckable(true);
        actionReinit_VNC = new QAction(Emulator_Control_Window);
        actionReinit_VNC->setObjectName(QString::fromUtf8("actionReinit_VNC"));
        centralwidget = new QWidget(Emulator_Control_Window);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setEnabled(false);
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        Emulator_Control_Window->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Emulator_Control_Window);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 480, 27));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        menuVM = new QMenu(menubar);
        menuVM->setObjectName(QString::fromUtf8("menuVM"));
        menuSend_Keys = new QMenu(menubar);
        menuSend_Keys->setObjectName(QString::fromUtf8("menuSend_Keys"));
        menuCtrl_Alt_F = new QMenu(menuSend_Keys);
        menuCtrl_Alt_F->setObjectName(QString::fromUtf8("menuCtrl_Alt_F"));
        menuCtrl_Alt_F->setIcon(icon9);
        menuConnect = new QMenu(menubar);
        menuConnect->setObjectName(QString::fromUtf8("menuConnect"));
        menuFloppy_B = new QMenu(menuConnect);
        menuFloppy_B->setObjectName(QString::fromUtf8("menuFloppy_B"));
        menuFloppy_B->setIcon(icon10);
        menuFloppy_A = new QMenu(menuConnect);
        menuFloppy_A->setObjectName(QString::fromUtf8("menuFloppy_A"));
        menuFloppy_A->setIcon(icon10);
        menuUSB = new QMenu(menuConnect);
        menuUSB->setObjectName(QString::fromUtf8("menuUSB"));
        QIcon icon16;
        icon16.addFile(QString::fromUtf8(":/Menu_16px/images/menu_16_px/usb.png"), QSize(), QIcon::Normal, QIcon::Off);
        menuUSB->setIcon(icon16);
        menuUSB_Connect = new QMenu(menuUSB);
        menuUSB_Connect->setObjectName(QString::fromUtf8("menuUSB_Connect"));
        QIcon icon17;
        icon17.addFile(QString::fromUtf8(":/Menu_16px/images/menu_16_px/connect_established.png"), QSize(), QIcon::Normal, QIcon::Off);
        menuUSB_Connect->setIcon(icon17);
        menuDisconnect = new QMenu(menuUSB);
        menuDisconnect->setObjectName(QString::fromUtf8("menuDisconnect"));
        QIcon icon18;
        icon18.addFile(QString::fromUtf8(":/Menu_16px/images/menu_16_px/connect_no.png"), QSize(), QIcon::Normal, QIcon::Off);
        menuDisconnect->setIcon(icon18);
        menuCD_ROM = new QMenu(menuConnect);
        menuCD_ROM->setObjectName(QString::fromUtf8("menuCD_ROM"));
        menuCD_ROM->setIcon(icon13);
        menuCDROM_Recent_Files = new QMenu(menuCD_ROM);
        menuCDROM_Recent_Files->setObjectName(QString::fromUtf8("menuCDROM_Recent_Files"));
        menuView = new QMenu(menubar);
        menuView->setObjectName(QString::fromUtf8("menuView"));
        Emulator_Control_Window->setMenuBar(menubar);

        menubar->addAction(menuVM->menuAction());
        menubar->addAction(menuConnect->menuAction());
        menubar->addAction(menuSend_Keys->menuAction());
        menubar->addAction(menuView->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuHelp->addAction(actionAbout_Emulator_Control);
        menuVM->addAction(actionSave_Screenshot);
        menuVM->addAction(actionSave_Screenshot_As);
        menuVM->addSeparator();
        menuVM->addAction(actionSave_VM);
        menuVM->addSeparator();
        menuVM->addAction(actionManage_Snapshots);
        menuVM->addSeparator();
        menuVM->addAction(actionCommit);
        menuVM->addSeparator();
        menuVM->addAction(actionPause_VM);
        menuVM->addAction(actionPower_Off);
        menuVM->addAction(actionReset_VM);
        menuVM->addSeparator();
        menuVM->addAction(actionQEMU_Monitor);
        menuVM->addSeparator();
        menuVM->addAction(actionQuit);
        menuSend_Keys->addAction(actionCtrl_Alt_Delete);
        menuSend_Keys->addAction(menuCtrl_Alt_F->menuAction());
        menuSend_Keys->addAction(actionCtrl_Alt_Backspace);
        menuSend_Keys->addAction(actionOther_Keys);
        menuCtrl_Alt_F->addAction(actionCtrl_Alt_F1);
        menuCtrl_Alt_F->addAction(actionCtrl_Alt_F2);
        menuCtrl_Alt_F->addAction(actionCtrl_Alt_F3);
        menuCtrl_Alt_F->addAction(actionCtrl_Alt_F4);
        menuCtrl_Alt_F->addAction(actionCtrl_Alt_F5);
        menuCtrl_Alt_F->addAction(actionCtrl_Alt_F6);
        menuCtrl_Alt_F->addAction(actionCtrl_Alt_F7);
        menuCtrl_Alt_F->addAction(actionCtrl_Alt_F8);
        menuCtrl_Alt_F->addAction(actionCtrl_Alt_F9);
        menuCtrl_Alt_F->addAction(actionCtrl_Alt_F10);
        menuCtrl_Alt_F->addAction(actionCtrl_Alt_F11);
        menuCtrl_Alt_F->addAction(actionCtrl_Alt_F12);
        menuConnect->addAction(menuFloppy_A->menuAction());
        menuConnect->addAction(menuFloppy_B->menuAction());
        menuConnect->addAction(menuCD_ROM->menuAction());
        menuConnect->addAction(menuUSB->menuAction());
        menuFloppy_B->addAction(actionFD1_dev_fd0);
        menuFloppy_B->addAction(actionFD1_dev_null);
        menuFloppy_B->addAction(actionFD1_Other);
        menuFloppy_B->addSeparator();
        menuFloppy_B->addAction(actionFD1_Eject);
        menuFloppy_A->addAction(actionFD0_dev_fd0);
        menuFloppy_A->addAction(actionFD0_dev_null);
        menuFloppy_A->addAction(actionFD0_Other);
        menuFloppy_A->addSeparator();
        menuFloppy_A->addAction(actionFD0_Eject);
        menuUSB->addAction(menuUSB_Connect->menuAction());
        menuUSB->addAction(menuDisconnect->menuAction());
        menuUSB_Connect->addAction(actionUSB_Update_Device_List);
        menuUSB_Connect->addSeparator();
        menuDisconnect->addAction(actionUSB_Disconnect_All_Devices);
        menuDisconnect->addAction(actionBy_Bus_Address);
        menuDisconnect->addSeparator();
        menuCD_ROM->addAction(actionCDROM_dev_cdrom);
        menuCD_ROM->addAction(actionCDROM_dev_null);
        menuCD_ROM->addSeparator();
        menuCD_ROM->addAction(menuCDROM_Recent_Files->menuAction());
        menuCD_ROM->addAction(actionCDROM_Other);
        menuCD_ROM->addSeparator();
        menuCD_ROM->addAction(actionCDROM_Eject);
        menuView->addAction(actionDisplay_Scaling);
        menuView->addAction(actionFullscreen_Mode);
        menuView->addAction(actionReinit_VNC);

        retranslateUi(Emulator_Control_Window);

        QMetaObject::connectSlotsByName(Emulator_Control_Window);
    } // setupUi

    void retranslateUi(QMainWindow *Emulator_Control_Window)
    {
        Emulator_Control_Window->setWindowTitle(QApplication::translate("Emulator_Control_Window", "Emulator Control", nullptr));
        actionSave_Screenshot->setText(QApplication::translate("Emulator_Control_Window", "Save Screens&hot", nullptr));
#ifndef QT_NO_SHORTCUT
        actionSave_Screenshot->setShortcut(QApplication::translate("Emulator_Control_Window", "F12", nullptr));
#endif // QT_NO_SHORTCUT
        actionSave_VM->setText(QApplication::translate("Emulator_Control_Window", "&Save VM", nullptr));
        actionLoad_VM->setText(QApplication::translate("Emulator_Control_Window", "&Load VM", nullptr));
#ifndef QT_NO_SHORTCUT
        actionLoad_VM->setShortcut(QApplication::translate("Emulator_Control_Window", "Ctrl+O", nullptr));
#endif // QT_NO_SHORTCUT
        actionPause_VM->setText(QApplication::translate("Emulator_Control_Window", "&Pause VM", nullptr));
        actionQuit->setText(QApplication::translate("Emulator_Control_Window", "&Quit", nullptr));
        actionSave_VM_State_As->setText(QApplication::translate("Emulator_Control_Window", "Save VM S&tate...", nullptr));
        actionLoad_VM_State->setText(QApplication::translate("Emulator_Control_Window", "Load VM St&ate...", nullptr));
        actionReset_VM->setText(QApplication::translate("Emulator_Control_Window", "&Reset VM", nullptr));
        actionPower_Off->setText(QApplication::translate("Emulator_Control_Window", "Power &Off", nullptr));
        actionCommit->setText(QApplication::translate("Emulator_Control_Window", "&Commit", nullptr));
        actionCtrl_Alt_Delete->setText(QApplication::translate("Emulator_Control_Window", "Ctrl-Alt-&Delete", nullptr));
        actionCtrl_Alt_F1->setText(QApplication::translate("Emulator_Control_Window", "1", nullptr));
        actionCtrl_Alt_F2->setText(QApplication::translate("Emulator_Control_Window", "2", nullptr));
        actionCtrl_Alt_F3->setText(QApplication::translate("Emulator_Control_Window", "3", nullptr));
        actionCtrl_Alt_F4->setText(QApplication::translate("Emulator_Control_Window", "4", nullptr));
        actionCtrl_Alt_F5->setText(QApplication::translate("Emulator_Control_Window", "5", nullptr));
        actionCtrl_Alt_F6->setText(QApplication::translate("Emulator_Control_Window", "6", nullptr));
        actionCtrl_Alt_F7->setText(QApplication::translate("Emulator_Control_Window", "7", nullptr));
        actionCtrl_Alt_F8->setText(QApplication::translate("Emulator_Control_Window", "8", nullptr));
        actionCtrl_Alt_F9->setText(QApplication::translate("Emulator_Control_Window", "9", nullptr));
        actionCtrl_Alt_F10->setText(QApplication::translate("Emulator_Control_Window", "10", nullptr));
        actionCtrl_Alt_F11->setText(QApplication::translate("Emulator_Control_Window", "11", nullptr));
        actionCtrl_Alt_F12->setText(QApplication::translate("Emulator_Control_Window", "12", nullptr));
        actionFD0_dev_fd0->setText(QApplication::translate("Emulator_Control_Window", "/dev/fd0", nullptr));
        actionFD0_dev_null->setText(QApplication::translate("Emulator_Control_Window", "/dev/null", nullptr));
        actionFD0_Other->setText(QApplication::translate("Emulator_Control_Window", "Other...", nullptr));
        actionFD0_Eject->setText(QApplication::translate("Emulator_Control_Window", "Eject", nullptr));
        actionUSB_Update_Device_List->setText(QApplication::translate("Emulator_Control_Window", "Update Device List", nullptr));
        actionAbout_Emulator_Control->setText(QApplication::translate("Emulator_Control_Window", "&About Emulator Control...", nullptr));
        actionFD1_dev_fd0->setText(QApplication::translate("Emulator_Control_Window", "/dev/fd0", nullptr));
        actionFD1_Other->setText(QApplication::translate("Emulator_Control_Window", "Other...", nullptr));
        actionFD1_Eject->setText(QApplication::translate("Emulator_Control_Window", "Eject", nullptr));
        actionFD1_dev_null->setText(QApplication::translate("Emulator_Control_Window", "/dev/null", nullptr));
        actionCDROM_dev_cdrom->setText(QApplication::translate("Emulator_Control_Window", "/dev/cdrom", nullptr));
        actionCDROM_Other->setText(QApplication::translate("Emulator_Control_Window", "Other...", nullptr));
        actionCDROM_Eject->setText(QApplication::translate("Emulator_Control_Window", "Eject", nullptr));
        actionSave_Screenshot_As->setText(QApplication::translate("Emulator_Control_Window", "Save Screenshot As...", nullptr));
        actionCDROM_dev_null->setText(QApplication::translate("Emulator_Control_Window", "/dev/null", nullptr));
        actionUSB_Disconnect_All_Devices->setText(QApplication::translate("Emulator_Control_Window", "All Devices", nullptr));
        actionOther_Keys->setText(QApplication::translate("Emulator_Control_Window", "&Other Keys...", nullptr));
        actionQEMU_Monitor->setText(QApplication::translate("Emulator_Control_Window", "QEMU &Monitor", nullptr));
        actionCtrl_Alt_Backspace->setText(QApplication::translate("Emulator_Control_Window", "Ctrl-Alt-Backspace", nullptr));
        actionSerial_Null->setText(QApplication::translate("Emulator_Control_Window", "null (/dev/null)", nullptr));
        actionStdio_Standard_In_Out->setText(QApplication::translate("Emulator_Control_Window", "stdio (Standard In Out)", nullptr));
        actionSerial_Other->setText(QApplication::translate("Emulator_Control_Window", "Other...", nullptr));
        action_Serial_ttyS0->setText(QApplication::translate("Emulator_Control_Window", "/dev/ttyS0", nullptr));
        actionParport_Other->setText(QApplication::translate("Emulator_Control_Window", "Other...", nullptr));
        actionParport_Null->setText(QApplication::translate("Emulator_Control_Window", "null (/dev/null)", nullptr));
        actionBy_Bus_Address->setText(QApplication::translate("Emulator_Control_Window", "By Bus.Address", nullptr));
        actionManage_Snapshots->setText(QApplication::translate("Emulator_Control_Window", "Manage Snapshots", nullptr));
        actionD->setText(QApplication::translate("Emulator_Control_Window", "d", nullptr));
        actionDisplay_Scaling->setText(QApplication::translate("Emulator_Control_Window", "Display Scaling", nullptr));
        actionFullscreen_Mode->setText(QApplication::translate("Emulator_Control_Window", "Fullscreen Mode", nullptr));
#ifndef QT_NO_SHORTCUT
        actionFullscreen_Mode->setShortcut(QApplication::translate("Emulator_Control_Window", "Ctrl+F", nullptr));
#endif // QT_NO_SHORTCUT
        actionShow_Status_Bar->setText(QApplication::translate("Emulator_Control_Window", "Show Status Bar", nullptr));
        actionReinit_VNC->setText(QApplication::translate("Emulator_Control_Window", "Reinit VNC", nullptr));
        menuHelp->setTitle(QApplication::translate("Emulator_Control_Window", "&Help", nullptr));
        menuVM->setTitle(QApplication::translate("Emulator_Control_Window", "&VM", nullptr));
        menuSend_Keys->setTitle(QApplication::translate("Emulator_Control_Window", "Send &Keys", nullptr));
        menuCtrl_Alt_F->setTitle(QApplication::translate("Emulator_Control_Window", "Ctrl-Alt-&F#", nullptr));
        menuConnect->setTitle(QApplication::translate("Emulator_Control_Window", "&Connect", nullptr));
        menuFloppy_B->setTitle(QApplication::translate("Emulator_Control_Window", "Floppy &B", nullptr));
        menuFloppy_A->setTitle(QApplication::translate("Emulator_Control_Window", "Floppy &A", nullptr));
        menuUSB->setTitle(QApplication::translate("Emulator_Control_Window", "&USB", nullptr));
        menuUSB_Connect->setTitle(QApplication::translate("Emulator_Control_Window", "Connect", nullptr));
        menuDisconnect->setTitle(QApplication::translate("Emulator_Control_Window", "Disconnect", nullptr));
        menuCD_ROM->setTitle(QApplication::translate("Emulator_Control_Window", "&CD-ROM", nullptr));
        menuCDROM_Recent_Files->setTitle(QApplication::translate("Emulator_Control_Window", "Recent Files", nullptr));
        menuView->setTitle(QApplication::translate("Emulator_Control_Window", "View", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Emulator_Control_Window: public Ui_Emulator_Control_Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMULATOR_CONTROL_WINDOW_H
