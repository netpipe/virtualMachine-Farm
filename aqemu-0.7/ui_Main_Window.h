/********************************************************************************
** Form generated from reading UI file 'Main_Window.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAIN_WINDOW_H
#define UI_MAIN_WINDOW_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Main_Window
{
public:
    QAction *actionAbout;
    QAction *actionAbout_Qt;
    QAction *actionDelete_Virtual_Machine;
    QAction *actionExit;
    QAction *actionWizard;
    QAction *actionCreate;
    QAction *actionCreate_HDD_Image;
    QAction *actionConvert_HDD_Image;
    QAction *actionAQEMU_Settings;
    QAction *action_Power_On;
    QAction *actionPower_Off;
    QAction *actionPause;
    QAction *actionReset;
    QAction *actionLoad_VM_From_File;
    QAction *actionSave_As_Template;
    QAction *actionShow_QEMU_Arguments;
    QAction *actionSave;
    QAction *actionChange_Icon;
    QAction *actionCopy;
    QAction *actionManage_Snapshots;
    QAction *actionShow_Emulator_Control;
    QWidget *centralwidget;
    QGridLayout *gridLayout_4;
    QListWidget *Machines_List;
    QVBoxLayout *verticalLayout;
    QTabWidget *Tabs;
    QWidget *Tab_Info;
    QGridLayout *gridLayout_2;
    QTextEdit *VM_Information_Text;
    QWidget *Tab_General;
    QGridLayout *gridLayout;
    QGroupBox *GB_Options;
    QGridLayout *gridLayout1;
    QSpacerItem *spacerItem;
    QSpacerItem *spacerItem1;
    QCheckBox *CH_Start_CPU;
    QCheckBox *CH_Local_Time;
    QSpacerItem *spacerItem2;
    QSpacerItem *spacerItem3;
    QCheckBox *CH_ACPI;
    QCheckBox *CH_Fullscreen;
    QCheckBox *CH_Snapshot;
    QCheckBox *CH_No_Reboot;
    QHBoxLayout *hboxLayout;
    QLabel *Label_Machine_Name;
    QLineEdit *Edit_Machine_Name;
    QHBoxLayout *hboxLayout1;
    QGridLayout *gridLayout2;
    QComboBox *CB_Acseleration;
    QLabel *Label_CPU_Type;
    QLabel *Label_Acseleration;
    QComboBox *CB_CPU_Type;
    QLabel *Label_Computer_Type;
    QComboBox *CB_Computer_Type;
    QLabel *Label_CPU_Count;
    QComboBox *CB_CPU_Count;
    QSpacerItem *spacerItem4;
    QGridLayout *gridLayout3;
    QLabel *Label_Video_Card;
    QComboBox *CB_Boot_Prioritet;
    QLabel *Label_Boot_Prioritet;
    QComboBox *CB_Machine_Type;
    QComboBox *CB_Video_Card;
    QComboBox *CB_Keyboard_Layout;
    QLabel *Label_Keyboard_Layout;
    QLabel *Label_Machine_Type;
    QGroupBox *GB_Memory;
    QGridLayout *gridLayout4;
    QCheckBox *Check_Host_Mem;
    QGridLayout *gridLayout5;
    QSpacerItem *spacerItem5;
    QLabel *Label_Min_Mem;
    QSlider *Memory_Size;
    QVBoxLayout *vboxLayout;
    QLabel *Label_MB;
    QSpacerItem *spacerItem6;
    QVBoxLayout *vboxLayout1;
    QComboBox *CB_RAM_Size;
    QLabel *Label_Max_Mem;
    QGroupBox *GB_Audio;
    QGridLayout *gridLayout6;
    QSpacerItem *spacerItem7;
    QSpacerItem *spacerItem8;
    QCheckBox *CH_GUS;
    QCheckBox *CH_es1370;
    QSpacerItem *spacerItem9;
    QSpacerItem *spacerItem10;
    QCheckBox *CH_Adlib;
    QCheckBox *CH_PCSPK;
    QCheckBox *CH_AC97;
    QCheckBox *CH_sb16;
    QWidget *Tab_HDD;
    QVBoxLayout *vboxLayout2;
    QGroupBox *GB_HDA;
    QGridLayout *gridLayout7;
    QLabel *Label_HDA_Info;
    QVBoxLayout *vboxLayout3;
    QToolButton *TB_HDA_SetPath;
    QSpacerItem *spacerItem11;
    QToolButton *TB_HDA_Create_HDD;
    QLineEdit *Edit_HDA_Image_Path;
    QGroupBox *GB_HDB;
    QGridLayout *gridLayout8;
    QVBoxLayout *vboxLayout4;
    QToolButton *TB_HDB_SetPath;
    QSpacerItem *spacerItem12;
    QToolButton *TB_HDB_Create_HDD;
    QLabel *Label_HDB_Info;
    QLineEdit *Edit_HDB_Image_Path;
    QGroupBox *GB_HDC;
    QGridLayout *gridLayout9;
    QVBoxLayout *vboxLayout5;
    QToolButton *TB_HDC_SetPath;
    QSpacerItem *spacerItem13;
    QToolButton *TB_HDC_Create_HDD;
    QLabel *Label_HDC_Info;
    QLineEdit *Edit_HDC_Image_Path;
    QGroupBox *GB_HDD;
    QGridLayout *gridLayout10;
    QVBoxLayout *vboxLayout6;
    QToolButton *TB_HDD_SetPath;
    QSpacerItem *spacerItem14;
    QToolButton *TB_HDD_Create_HDD;
    QLabel *Label_HDD_Info;
    QLineEdit *Edit_HDD_Image_Path;
    QWidget *Tab_Removable_Disks;
    QGridLayout *gridLayout11;
    QGroupBox *GB_Floppy0;
    QGridLayout *gridLayout12;
    QComboBox *CB_FD0_Host_Devices;
    QRadioButton *RB_FD0_Use_Image_File;
    QLineEdit *Edit_FD0_Image_File_Path;
    QToolButton *TB_FD0_SetPath;
    QRadioButton *RB_FD0_Use_Host_Device;
    QGroupBox *GB_CDROM;
    QGridLayout *gridLayout13;
    QRadioButton *RB_CDROM_Use_Host_Device;
    QComboBox *CB_CDROM_Host_Devices;
    QLineEdit *Edit_CDROM_Image_File_Path;
    QToolButton *TB_CDROM_SetPath;
    QRadioButton *RB_CDROM_Use_Image_File;
    QGroupBox *GB_Floppy1;
    QGridLayout *gridLayout14;
    QRadioButton *RB_FD1_Use_Host_Device;
    QComboBox *CB_FD1_Host_Devices;
    QLineEdit *Edit_FD1_Image_File_Path;
    QToolButton *TB_FD1_SetPath;
    QRadioButton *RB_FD1_Use_Image_File;
    QWidget *Tab_Network;
    QGridLayout *gridLayout15;
    QTabWidget *Network_Cards_Tabs;
    QWidget *Network_Cards_Tab;
    QGridLayout *gridLayout16;
    QWidget *Net_Card_Options;
    QGridLayout *gridLayout17;
    QVBoxLayout *vboxLayout7;
    QGridLayout *gridLayout18;
    QLabel *Label_NetCard_Model;
    QLabel *Label_Connection_Mode;
    QComboBox *CB_Network_Card_Model;
    QComboBox *CB_Connection_Mode;
    QFrame *Line_nc_2;
    QHBoxLayout *hboxLayout2;
    QGridLayout *gridLayout19;
    QLabel *Label_IP;
    QLineEdit *Edit_IP_Address;
    QLabel *Label_MAC;
    QLineEdit *Edit_MAC_Address;
    QToolButton *TB_Generate_New_MAC;
    QLabel *Label_Host_Name;
    QLineEdit *Edit_Hostname;
    QSpacerItem *spacerItem15;
    QGridLayout *gridLayout20;
    QSpinBox *SB_Port;
    QLabel *Label_Port;
    QLabel *Label_VLAN;
    QSpinBox *SB_File_Descriptor;
    QSpinBox *SB_VLAN;
    QLabel *Label_File_Descriptor;
    QGridLayout *gridLayout21;
    QToolButton *TB_Browse_TUN_Script;
    QLineEdit *Edit_TUN_TAP_Script;
    QLabel *Label_If_Name;
    QLineEdit *Edit_Interface_Name;
    QFrame *Line_nc_3;
    QCheckBox *CH_TUN_TAP_Script;
    QGridLayout *gridLayout22;
    QPushButton *Button_Delete_Net_Card;
    QSpacerItem *spacerItem16;
    QPushButton *Button_Add_Net_Card;
    QLabel *Label_Cards_List;
    QListWidget *Network_Cards_List;
    QWidget *Tab_Network_Settings;
    QGridLayout *gridLayout23;
    QGroupBox *GB_Redirections;
    QGridLayout *gridLayout24;
    QHBoxLayout *hboxLayout3;
    QLabel *Label_Protocol;
    QRadioButton *RB_TCP;
    QRadioButton *RB_UDP;
    QSpacerItem *spacerItem17;
    QHBoxLayout *hboxLayout4;
    QLabel *Label_Port1;
    QSpinBox *SB_Redir_Port;
    QLabel *Label_To_Guest_IP;
    QLineEdit *Edit_Guest_IP;
    QLabel *Label_Port2;
    QSpinBox *SB_Guest_Port;
    QHBoxLayout *hboxLayout5;
    QPushButton *Button_Add_Redirections;
    QPushButton *Button_Delete_Redirections;
    QPushButton *Button_Apply_Redirections;
    QPushButton *Button_Clear_Redirections;
    QTableWidget *Redirections_List;
    QHBoxLayout *hboxLayout6;
    QLabel *Label_Redirect_Settings;
    QFrame *line_redir_1;
    QGridLayout *gridLayout25;
    QLabel *Label_SMB_Folder;
    QLineEdit *Edit_TFTP_Prefix;
    QLabel *Label_TFTP;
    QLineEdit *Edit_SMB_Folder;
    QToolButton *TB_Browse_SMB;
    QCheckBox *CH_Use_Network;
    QWidget *Tab_Advanced;
    QGridLayout *gridLayout9999;
    QHBoxLayout *horizontalLayout_2;
    QLabel *Label_QEMU_Window_Options;
    QFrame *line_5;
    QCheckBox *CH_No_Frame;
    QCheckBox *CH_Alt_Grab;
    QCheckBox *CH_No_Quit;
    QCheckBox *CH_Portrait;
    QHBoxLayout *horizontalLayout;
    QLabel *Label_Additional_Options;
    QFrame *line_4;
    QCheckBox *CH_FDD_Boot;
    QCheckBox *CH_QEMU_Log;
    QCheckBox *CH_Win2K_Hack;
    QHBoxLayout *horizontalLayout_5;
    QCheckBox *CH_Start_Date;
    QSpacerItem *horizontalSpacer_4;
    QDateTimeEdit *DTE_Start_Date;
    QHBoxLayout *horizontalLayout_4;
    QCheckBox *CH_Init_Graphic_Mode;
    QSpacerItem *horizontalSpacer_3;
    QLabel *Label_W;
    QSpinBox *SB_InitGM_Width;
    QSpacerItem *horizontalSpacer;
    QLabel *Label_H;
    QSpinBox *SB_InitGM_Height;
    QSpacerItem *horizontalSpacer_2;
    QLabel *Label_Depth;
    QComboBox *CB_InitGM_Depth;
    QHBoxLayout *horizontalLayout_3;
    QLabel *Label_Use_KVM;
    QFrame *line_6;
    QCheckBox *CH_No_KVM_IRQChip;
    QCheckBox *CH_No_KVM_Pit;
    QCheckBox *CH_KVM_Shadow_Memory;
    QSpinBox *SB_KVM_Shadow_Memory_Size;
    QLabel *Label_KVM_Shadow_Memory_Mb;
    QSpacerItem *horizontalSpacer_5;
    QWidget *Tab_Other;
    QGridLayout *gridLayout26;
    QTabWidget *Tabs_Other;
    QWidget *Tab_VNC;
    QGridLayout *gridLayout_3;
    QCheckBox *CH_Activate_VNC;
    QWidget *VNC_Panel;
    QGridLayout *gridLayout27;
    QVBoxLayout *vboxLayout8;
    QGridLayout *gridLayout28;
    QFrame *line;
    QSpinBox *SB_VNC_Display;
    QLineEdit *Edit_VNC_Unix_Socket;
    QRadioButton *RB_VNC_Unix_Socket;
    QCheckBox *CH_VNC_Password;
    QToolButton *TB_VNC_Unix_Socket_Browse;
    QFrame *line_3;
    QCheckBox *CH_Use_VNC_TLS;
    QRadioButton *RB_VNC_Display_Number;
    QFrame *line_2;
    QWidget *VNC_TLS_Panel;
    QGridLayout *gridLayout29;
    QGridLayout *gridLayout30;
    QToolButton *TB_x509verify_Browse;
    QLineEdit *Edit_x509verify_Folder;
    QLineEdit *Edit_x509_Folder;
    QToolButton *TB_x509_Browse;
    QCheckBox *CH_x509_Folder;
    QCheckBox *CH_x509verify_Folder;
    QSpacerItem *verticalSpacer;
    QWidget *Tab_Optional_Images;
    QGridLayout *gridLayout31;
    QGridLayout *gridLayout32;
    QLineEdit *Edit_PFlash_File;
    QToolButton *TB_SD_Image_File_Browse;
    QCheckBox *CH_PFlash;
    QToolButton *TB_ROM_File_Browse;
    QCheckBox *CH_ROM_File;
    QCheckBox *CH_MTDBlock;
    QToolButton *TB_MTDBlock_File_Browse;
    QLineEdit *Edit_SD_Image_File;
    QLineEdit *Edit_ROM_File;
    QLineEdit *Edit_MTDBlock_File;
    QCheckBox *CH_SD_Image;
    QToolButton *TB_PFlash_File_Browse;
    QSpacerItem *spacerItem18;
    QWidget *Tab_Boot_Linux;
    QGridLayout *gridLayout33;
    QSpacerItem *spacerItem19;
    QCheckBox *CH_Use_Linux_Boot;
    QToolButton *TB_Linux_bzImage_SetPath;
    QToolButton *TB_Linux_Initrd_SetPath;
    QSpacerItem *spacerItem20;
    QLineEdit *Edit_Linux_bzImage_Path;
    QLineEdit *Edit_Linux_Initrd_Path;
    QLineEdit *Edit_Linux_Command_Line;
    QLabel *Label_KernelCom;
    QLabel *Label_InitRD;
    QLabel *Label_bzImage;
    QGridLayout *gridLayout34;
    QLabel *Label_Additional_QEMU_Args;
    QCheckBox *CH_Use_GDB;
    QLineEdit *Edit_Additional_Args;
    QSpinBox *SB_GDB_Port;
    QHBoxLayout *hboxLayout7;
    QSpacerItem *spacerItem21;
    QPushButton *Button_Apply;
    QPushButton *Button_Cancel;
    QMenuBar *menubar;
    QMenu *menuVM;
    QMenu *menuNew_VM;
    QMenu *menuHelp;
    QMenu *menuFile;
    QStatusBar *Status_Bar;
    QToolBar *Tool_Bar_VM_Manage;
    QToolBar *Tool_Bar_VM_Control;

    void setupUi(QMainWindow *Main_Window)
    {
        if (Main_Window->objectName().isEmpty())
            Main_Window->setObjectName(QString::fromUtf8("Main_Window"));
        Main_Window->resize(731, 606);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        Main_Window->setWindowIcon(icon);
        actionAbout = new QAction(Main_Window);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/help.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAbout->setIcon(icon1);
        actionAbout_Qt = new QAction(Main_Window);
        actionAbout_Qt->setObjectName(QString::fromUtf8("actionAbout_Qt"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/svn_status.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAbout_Qt->setIcon(icon2);
        actionDelete_Virtual_Machine = new QAction(Main_Window);
        actionDelete_Virtual_Machine->setObjectName(QString::fromUtf8("actionDelete_Virtual_Machine"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/remove.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDelete_Virtual_Machine->setIcon(icon3);
        actionExit = new QAction(Main_Window);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExit->setIcon(icon4);
        actionWizard = new QAction(Main_Window);
        actionWizard->setObjectName(QString::fromUtf8("actionWizard"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/wizard.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionWizard->setIcon(icon5);
        actionCreate = new QAction(Main_Window);
        actionCreate->setObjectName(QString::fromUtf8("actionCreate"));
        actionCreate->setIcon(icon);
        actionCreate_HDD_Image = new QAction(Main_Window);
        actionCreate_HDD_Image->setObjectName(QString::fromUtf8("actionCreate_HDD_Image"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/images/hdd_unmount.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCreate_HDD_Image->setIcon(icon6);
        actionConvert_HDD_Image = new QAction(Main_Window);
        actionConvert_HDD_Image->setObjectName(QString::fromUtf8("actionConvert_HDD_Image"));
        actionConvert_HDD_Image->setIcon(icon6);
        actionAQEMU_Settings = new QAction(Main_Window);
        actionAQEMU_Settings->setObjectName(QString::fromUtf8("actionAQEMU_Settings"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/images/configure.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAQEMU_Settings->setIcon(icon7);
        action_Power_On = new QAction(Main_Window);
        action_Power_On->setObjectName(QString::fromUtf8("action_Power_On"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/images/player_play.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Power_On->setIcon(icon8);
        actionPower_Off = new QAction(Main_Window);
        actionPower_Off->setObjectName(QString::fromUtf8("actionPower_Off"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/images/player_stop.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPower_Off->setIcon(icon9);
        actionPause = new QAction(Main_Window);
        actionPause->setObjectName(QString::fromUtf8("actionPause"));
        actionPause->setCheckable(true);
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/images/player_pause.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPause->setIcon(icon10);
        actionReset = new QAction(Main_Window);
        actionReset->setObjectName(QString::fromUtf8("actionReset"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/images/reload.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionReset->setIcon(icon11);
        actionLoad_VM_From_File = new QAction(Main_Window);
        actionLoad_VM_From_File->setObjectName(QString::fromUtf8("actionLoad_VM_From_File"));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/images/project_open.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionLoad_VM_From_File->setIcon(icon12);
        actionSave_As_Template = new QAction(Main_Window);
        actionSave_As_Template->setObjectName(QString::fromUtf8("actionSave_As_Template"));
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/images/filesave.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave_As_Template->setIcon(icon13);
        actionShow_QEMU_Arguments = new QAction(Main_Window);
        actionShow_QEMU_Arguments->setObjectName(QString::fromUtf8("actionShow_QEMU_Arguments"));
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/images/other.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionShow_QEMU_Arguments->setIcon(icon14);
        actionSave = new QAction(Main_Window);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionSave->setIcon(icon13);
        actionChange_Icon = new QAction(Main_Window);
        actionChange_Icon->setObjectName(QString::fromUtf8("actionChange_Icon"));
        actionChange_Icon->setIcon(icon7);
        actionCopy = new QAction(Main_Window);
        actionCopy->setObjectName(QString::fromUtf8("actionCopy"));
        QIcon icon15;
        icon15.addFile(QString::fromUtf8(":/images/copy.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCopy->setIcon(icon15);
        actionManage_Snapshots = new QAction(Main_Window);
        actionManage_Snapshots->setObjectName(QString::fromUtf8("actionManage_Snapshots"));
        QIcon icon16;
        icon16.addFile(QString::fromUtf8(":/Menu_16px/images/menu_16_px/clock.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionManage_Snapshots->setIcon(icon16);
        actionShow_Emulator_Control = new QAction(Main_Window);
        actionShow_Emulator_Control->setObjectName(QString::fromUtf8("actionShow_Emulator_Control"));
        actionShow_Emulator_Control->setIcon(icon7);
        centralwidget = new QWidget(Main_Window);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_4 = new QGridLayout(centralwidget);
        gridLayout_4->setSpacing(4);
        gridLayout_4->setContentsMargins(6, 6, 6, 6);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        Machines_List = new QListWidget(centralwidget);
        Machines_List->setObjectName(QString::fromUtf8("Machines_List"));
        Machines_List->setMinimumSize(QSize(200, 500));
        Machines_List->setMaximumSize(QSize(200, 2048));
        Machines_List->setContextMenuPolicy(Qt::CustomContextMenu);
        Machines_List->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        Machines_List->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        Machines_List->setDragDropMode(QAbstractItemView::NoDragDrop);
        Machines_List->setIconSize(QSize(64, 64));
        Machines_List->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        Machines_List->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
        Machines_List->setMovement(QListView::Static);
        Machines_List->setWordWrap(true);

        gridLayout_4->addWidget(Machines_List, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(4);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(4, -1, -1, -1);
        Tabs = new QTabWidget(centralwidget);
        Tabs->setObjectName(QString::fromUtf8("Tabs"));
        Tab_Info = new QWidget();
        Tab_Info->setObjectName(QString::fromUtf8("Tab_Info"));
        gridLayout_2 = new QGridLayout(Tab_Info);
        gridLayout_2->setSpacing(4);
        gridLayout_2->setContentsMargins(6, 6, 6, 6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        VM_Information_Text = new QTextEdit(Tab_Info);
        VM_Information_Text->setObjectName(QString::fromUtf8("VM_Information_Text"));
        VM_Information_Text->setFrameShape(QFrame::NoFrame);
        VM_Information_Text->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        VM_Information_Text->setReadOnly(true);

        gridLayout_2->addWidget(VM_Information_Text, 0, 0, 1, 1);

        Tabs->addTab(Tab_Info, QString());
        Tab_General = new QWidget();
        Tab_General->setObjectName(QString::fromUtf8("Tab_General"));
        gridLayout = new QGridLayout(Tab_General);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(9, 9, 9, 9);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        GB_Options = new QGroupBox(Tab_General);
        GB_Options->setObjectName(QString::fromUtf8("GB_Options"));
        gridLayout1 = new QGridLayout(GB_Options);
        gridLayout1->setSpacing(3);
        gridLayout1->setContentsMargins(6, 6, 6, 6);
        gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
        spacerItem = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout1->addItem(spacerItem, 1, 3, 1, 1);

        spacerItem1 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout1->addItem(spacerItem1, 0, 3, 1, 1);

        CH_Start_CPU = new QCheckBox(GB_Options);
        CH_Start_CPU->setObjectName(QString::fromUtf8("CH_Start_CPU"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CH_Start_CPU->sizePolicy().hasHeightForWidth());
        CH_Start_CPU->setSizePolicy(sizePolicy);

        gridLayout1->addWidget(CH_Start_CPU, 1, 2, 1, 1);

        CH_Local_Time = new QCheckBox(GB_Options);
        CH_Local_Time->setObjectName(QString::fromUtf8("CH_Local_Time"));
        sizePolicy.setHeightForWidth(CH_Local_Time->sizePolicy().hasHeightForWidth());
        CH_Local_Time->setSizePolicy(sizePolicy);

        gridLayout1->addWidget(CH_Local_Time, 0, 2, 1, 1);

        spacerItem2 = new QSpacerItem(31, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout1->addItem(spacerItem2, 1, 1, 1, 1);

        spacerItem3 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout1->addItem(spacerItem3, 0, 1, 1, 1);

        CH_ACPI = new QCheckBox(GB_Options);
        CH_ACPI->setObjectName(QString::fromUtf8("CH_ACPI"));
        sizePolicy.setHeightForWidth(CH_ACPI->sizePolicy().hasHeightForWidth());
        CH_ACPI->setSizePolicy(sizePolicy);

        gridLayout1->addWidget(CH_ACPI, 1, 0, 1, 1);

        CH_Fullscreen = new QCheckBox(GB_Options);
        CH_Fullscreen->setObjectName(QString::fromUtf8("CH_Fullscreen"));
        sizePolicy.setHeightForWidth(CH_Fullscreen->sizePolicy().hasHeightForWidth());
        CH_Fullscreen->setSizePolicy(sizePolicy);

        gridLayout1->addWidget(CH_Fullscreen, 0, 0, 1, 1);

        CH_Snapshot = new QCheckBox(GB_Options);
        CH_Snapshot->setObjectName(QString::fromUtf8("CH_Snapshot"));
        sizePolicy.setHeightForWidth(CH_Snapshot->sizePolicy().hasHeightForWidth());
        CH_Snapshot->setSizePolicy(sizePolicy);

        gridLayout1->addWidget(CH_Snapshot, 0, 4, 1, 1);

        CH_No_Reboot = new QCheckBox(GB_Options);
        CH_No_Reboot->setObjectName(QString::fromUtf8("CH_No_Reboot"));
        sizePolicy.setHeightForWidth(CH_No_Reboot->sizePolicy().hasHeightForWidth());
        CH_No_Reboot->setSizePolicy(sizePolicy);

        gridLayout1->addWidget(CH_No_Reboot, 1, 4, 1, 1);


        gridLayout->addWidget(GB_Options, 4, 0, 1, 1);

        hboxLayout = new QHBoxLayout();
        hboxLayout->setSpacing(6);
        hboxLayout->setContentsMargins(0, 0, 0, 0);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        Label_Machine_Name = new QLabel(Tab_General);
        Label_Machine_Name->setObjectName(QString::fromUtf8("Label_Machine_Name"));

        hboxLayout->addWidget(Label_Machine_Name);

        Edit_Machine_Name = new QLineEdit(Tab_General);
        Edit_Machine_Name->setObjectName(QString::fromUtf8("Edit_Machine_Name"));
        Edit_Machine_Name->setMaxLength(256);

        hboxLayout->addWidget(Edit_Machine_Name);


        gridLayout->addLayout(hboxLayout, 0, 0, 1, 1);

        hboxLayout1 = new QHBoxLayout();
        hboxLayout1->setSpacing(2);
        hboxLayout1->setContentsMargins(0, 0, 0, 0);
        hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
        gridLayout2 = new QGridLayout();
        gridLayout2->setSpacing(3);
        gridLayout2->setContentsMargins(0, 0, 0, 0);
        gridLayout2->setObjectName(QString::fromUtf8("gridLayout2"));
        CB_Acseleration = new QComboBox(Tab_General);
        CB_Acseleration->addItem(QString());
        CB_Acseleration->addItem(QString());
        CB_Acseleration->addItem(QString());
        CB_Acseleration->addItem(QString());
        CB_Acseleration->setObjectName(QString::fromUtf8("CB_Acseleration"));
        sizePolicy.setHeightForWidth(CB_Acseleration->sizePolicy().hasHeightForWidth());
        CB_Acseleration->setSizePolicy(sizePolicy);
        CB_Acseleration->setMaxCount(5);

        gridLayout2->addWidget(CB_Acseleration, 3, 1, 1, 1);

        Label_CPU_Type = new QLabel(Tab_General);
        Label_CPU_Type->setObjectName(QString::fromUtf8("Label_CPU_Type"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(Label_CPU_Type->sizePolicy().hasHeightForWidth());
        Label_CPU_Type->setSizePolicy(sizePolicy1);

        gridLayout2->addWidget(Label_CPU_Type, 1, 0, 1, 1);

        Label_Acseleration = new QLabel(Tab_General);
        Label_Acseleration->setObjectName(QString::fromUtf8("Label_Acseleration"));
        sizePolicy1.setHeightForWidth(Label_Acseleration->sizePolicy().hasHeightForWidth());
        Label_Acseleration->setSizePolicy(sizePolicy1);

        gridLayout2->addWidget(Label_Acseleration, 3, 0, 1, 1);

        CB_CPU_Type = new QComboBox(Tab_General);
        CB_CPU_Type->setObjectName(QString::fromUtf8("CB_CPU_Type"));
        sizePolicy.setHeightForWidth(CB_CPU_Type->sizePolicy().hasHeightForWidth());
        CB_CPU_Type->setSizePolicy(sizePolicy);
        CB_CPU_Type->setMaxCount(1024);

        gridLayout2->addWidget(CB_CPU_Type, 1, 1, 1, 1);

        Label_Computer_Type = new QLabel(Tab_General);
        Label_Computer_Type->setObjectName(QString::fromUtf8("Label_Computer_Type"));
        sizePolicy1.setHeightForWidth(Label_Computer_Type->sizePolicy().hasHeightForWidth());
        Label_Computer_Type->setSizePolicy(sizePolicy1);

        gridLayout2->addWidget(Label_Computer_Type, 0, 0, 1, 1);

        CB_Computer_Type = new QComboBox(Tab_General);
        CB_Computer_Type->setObjectName(QString::fromUtf8("CB_Computer_Type"));
        sizePolicy.setHeightForWidth(CB_Computer_Type->sizePolicy().hasHeightForWidth());
        CB_Computer_Type->setSizePolicy(sizePolicy);
        CB_Computer_Type->setMaxCount(64);

        gridLayout2->addWidget(CB_Computer_Type, 0, 1, 1, 1);

        Label_CPU_Count = new QLabel(Tab_General);
        Label_CPU_Count->setObjectName(QString::fromUtf8("Label_CPU_Count"));
        sizePolicy1.setHeightForWidth(Label_CPU_Count->sizePolicy().hasHeightForWidth());
        Label_CPU_Count->setSizePolicy(sizePolicy1);

        gridLayout2->addWidget(Label_CPU_Count, 2, 0, 1, 1);

        CB_CPU_Count = new QComboBox(Tab_General);
        CB_CPU_Count->addItem(QString());
        CB_CPU_Count->addItem(QString());
        CB_CPU_Count->addItem(QString());
        CB_CPU_Count->addItem(QString());
        CB_CPU_Count->addItem(QString());
        CB_CPU_Count->addItem(QString());
        CB_CPU_Count->addItem(QString());
        CB_CPU_Count->addItem(QString());
        CB_CPU_Count->addItem(QString());
        CB_CPU_Count->setObjectName(QString::fromUtf8("CB_CPU_Count"));
        sizePolicy.setHeightForWidth(CB_CPU_Count->sizePolicy().hasHeightForWidth());
        CB_CPU_Count->setSizePolicy(sizePolicy);
        CB_CPU_Count->setMaxCount(16);

        gridLayout2->addWidget(CB_CPU_Count, 2, 1, 1, 1);


        hboxLayout1->addLayout(gridLayout2);

        spacerItem4 = new QSpacerItem(5, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        hboxLayout1->addItem(spacerItem4);

        gridLayout3 = new QGridLayout();
        gridLayout3->setSpacing(3);
        gridLayout3->setContentsMargins(0, 0, 0, 0);
        gridLayout3->setObjectName(QString::fromUtf8("gridLayout3"));
        Label_Video_Card = new QLabel(Tab_General);
        Label_Video_Card->setObjectName(QString::fromUtf8("Label_Video_Card"));
        sizePolicy1.setHeightForWidth(Label_Video_Card->sizePolicy().hasHeightForWidth());
        Label_Video_Card->setSizePolicy(sizePolicy1);

        gridLayout3->addWidget(Label_Video_Card, 2, 0, 1, 1);

        CB_Boot_Prioritet = new QComboBox(Tab_General);
        CB_Boot_Prioritet->addItem(QString());
        CB_Boot_Prioritet->addItem(QString());
        CB_Boot_Prioritet->addItem(QString());
        CB_Boot_Prioritet->addItem(QString());
        CB_Boot_Prioritet->addItem(QString());
        CB_Boot_Prioritet->setObjectName(QString::fromUtf8("CB_Boot_Prioritet"));
        sizePolicy.setHeightForWidth(CB_Boot_Prioritet->sizePolicy().hasHeightForWidth());
        CB_Boot_Prioritet->setSizePolicy(sizePolicy);
        CB_Boot_Prioritet->setMaxCount(8);

        gridLayout3->addWidget(CB_Boot_Prioritet, 1, 1, 1, 1);

        Label_Boot_Prioritet = new QLabel(Tab_General);
        Label_Boot_Prioritet->setObjectName(QString::fromUtf8("Label_Boot_Prioritet"));
        sizePolicy1.setHeightForWidth(Label_Boot_Prioritet->sizePolicy().hasHeightForWidth());
        Label_Boot_Prioritet->setSizePolicy(sizePolicy1);

        gridLayout3->addWidget(Label_Boot_Prioritet, 1, 0, 1, 1);

        CB_Machine_Type = new QComboBox(Tab_General);
        CB_Machine_Type->setObjectName(QString::fromUtf8("CB_Machine_Type"));
        sizePolicy.setHeightForWidth(CB_Machine_Type->sizePolicy().hasHeightForWidth());
        CB_Machine_Type->setSizePolicy(sizePolicy);
        CB_Machine_Type->setMaxCount(64);

        gridLayout3->addWidget(CB_Machine_Type, 0, 1, 1, 1);

        CB_Video_Card = new QComboBox(Tab_General);
        CB_Video_Card->setObjectName(QString::fromUtf8("CB_Video_Card"));
        sizePolicy.setHeightForWidth(CB_Video_Card->sizePolicy().hasHeightForWidth());
        CB_Video_Card->setSizePolicy(sizePolicy);
        CB_Video_Card->setMaxCount(8);

        gridLayout3->addWidget(CB_Video_Card, 2, 1, 1, 1);

        CB_Keyboard_Layout = new QComboBox(Tab_General);
        CB_Keyboard_Layout->addItem(QString());
        CB_Keyboard_Layout->addItem(QString());
        CB_Keyboard_Layout->addItem(QString());
        CB_Keyboard_Layout->addItem(QString());
        CB_Keyboard_Layout->addItem(QString());
        CB_Keyboard_Layout->addItem(QString());
        CB_Keyboard_Layout->addItem(QString());
        CB_Keyboard_Layout->addItem(QString());
        CB_Keyboard_Layout->addItem(QString());
        CB_Keyboard_Layout->addItem(QString());
        CB_Keyboard_Layout->addItem(QString());
        CB_Keyboard_Layout->addItem(QString());
        CB_Keyboard_Layout->addItem(QString());
        CB_Keyboard_Layout->addItem(QString());
        CB_Keyboard_Layout->addItem(QString());
        CB_Keyboard_Layout->addItem(QString());
        CB_Keyboard_Layout->addItem(QString());
        CB_Keyboard_Layout->addItem(QString());
        CB_Keyboard_Layout->addItem(QString());
        CB_Keyboard_Layout->addItem(QString());
        CB_Keyboard_Layout->addItem(QString());
        CB_Keyboard_Layout->addItem(QString());
        CB_Keyboard_Layout->addItem(QString());
        CB_Keyboard_Layout->addItem(QString());
        CB_Keyboard_Layout->addItem(QString());
        CB_Keyboard_Layout->addItem(QString());
        CB_Keyboard_Layout->addItem(QString());
        CB_Keyboard_Layout->addItem(QString());
        CB_Keyboard_Layout->addItem(QString());
        CB_Keyboard_Layout->addItem(QString());
        CB_Keyboard_Layout->addItem(QString());
        CB_Keyboard_Layout->addItem(QString());
        CB_Keyboard_Layout->addItem(QString());
        CB_Keyboard_Layout->addItem(QString());
        CB_Keyboard_Layout->setObjectName(QString::fromUtf8("CB_Keyboard_Layout"));
        sizePolicy.setHeightForWidth(CB_Keyboard_Layout->sizePolicy().hasHeightForWidth());
        CB_Keyboard_Layout->setSizePolicy(sizePolicy);
        CB_Keyboard_Layout->setMaxCount(128);

        gridLayout3->addWidget(CB_Keyboard_Layout, 3, 1, 1, 1);

        Label_Keyboard_Layout = new QLabel(Tab_General);
        Label_Keyboard_Layout->setObjectName(QString::fromUtf8("Label_Keyboard_Layout"));
        sizePolicy1.setHeightForWidth(Label_Keyboard_Layout->sizePolicy().hasHeightForWidth());
        Label_Keyboard_Layout->setSizePolicy(sizePolicy1);

        gridLayout3->addWidget(Label_Keyboard_Layout, 3, 0, 1, 1);

        Label_Machine_Type = new QLabel(Tab_General);
        Label_Machine_Type->setObjectName(QString::fromUtf8("Label_Machine_Type"));
        sizePolicy1.setHeightForWidth(Label_Machine_Type->sizePolicy().hasHeightForWidth());
        Label_Machine_Type->setSizePolicy(sizePolicy1);

        gridLayout3->addWidget(Label_Machine_Type, 0, 0, 1, 1);


        hboxLayout1->addLayout(gridLayout3);


        gridLayout->addLayout(hboxLayout1, 1, 0, 1, 1);

        GB_Memory = new QGroupBox(Tab_General);
        GB_Memory->setObjectName(QString::fromUtf8("GB_Memory"));
        gridLayout4 = new QGridLayout(GB_Memory);
        gridLayout4->setSpacing(3);
        gridLayout4->setContentsMargins(6, 6, 6, 6);
        gridLayout4->setObjectName(QString::fromUtf8("gridLayout4"));
        Check_Host_Mem = new QCheckBox(GB_Memory);
        Check_Host_Mem->setObjectName(QString::fromUtf8("Check_Host_Mem"));

        gridLayout4->addWidget(Check_Host_Mem, 1, 0, 1, 2);

        gridLayout5 = new QGridLayout();
        gridLayout5->setSpacing(6);
        gridLayout5->setContentsMargins(0, 0, 0, 0);
        gridLayout5->setObjectName(QString::fromUtf8("gridLayout5"));
        spacerItem5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout5->addItem(spacerItem5, 1, 1, 1, 1);

        Label_Min_Mem = new QLabel(GB_Memory);
        Label_Min_Mem->setObjectName(QString::fromUtf8("Label_Min_Mem"));

        gridLayout5->addWidget(Label_Min_Mem, 1, 0, 1, 1);

        Memory_Size = new QSlider(GB_Memory);
        Memory_Size->setObjectName(QString::fromUtf8("Memory_Size"));
        sizePolicy.setHeightForWidth(Memory_Size->sizePolicy().hasHeightForWidth());
        Memory_Size->setSizePolicy(sizePolicy);
        Memory_Size->setMinimum(2);
        Memory_Size->setMaximum(2048);
        Memory_Size->setSingleStep(4);
        Memory_Size->setPageStep(8);
        Memory_Size->setValue(128);
        Memory_Size->setOrientation(Qt::Horizontal);
        Memory_Size->setTickPosition(QSlider::TicksAbove);
        Memory_Size->setTickInterval(128);

        gridLayout5->addWidget(Memory_Size, 0, 0, 1, 2);


        gridLayout4->addLayout(gridLayout5, 0, 0, 1, 1);

        vboxLayout = new QVBoxLayout();
        vboxLayout->setSpacing(6);
        vboxLayout->setContentsMargins(0, 0, 0, 0);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        Label_MB = new QLabel(GB_Memory);
        Label_MB->setObjectName(QString::fromUtf8("Label_MB"));

        vboxLayout->addWidget(Label_MB);

        spacerItem6 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        vboxLayout->addItem(spacerItem6);


        gridLayout4->addLayout(vboxLayout, 0, 2, 1, 1);

        vboxLayout1 = new QVBoxLayout();
        vboxLayout1->setSpacing(6);
        vboxLayout1->setContentsMargins(0, 0, 0, 0);
        vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
        CB_RAM_Size = new QComboBox(GB_Memory);
        CB_RAM_Size->addItem(QString());
        CB_RAM_Size->addItem(QString());
        CB_RAM_Size->addItem(QString());
        CB_RAM_Size->addItem(QString());
        CB_RAM_Size->addItem(QString());
        CB_RAM_Size->addItem(QString());
        CB_RAM_Size->addItem(QString());
        CB_RAM_Size->addItem(QString());
        CB_RAM_Size->addItem(QString());
        CB_RAM_Size->addItem(QString());
        CB_RAM_Size->addItem(QString());
        CB_RAM_Size->setObjectName(QString::fromUtf8("CB_RAM_Size"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(CB_RAM_Size->sizePolicy().hasHeightForWidth());
        CB_RAM_Size->setSizePolicy(sizePolicy2);
        CB_RAM_Size->setMaximumSize(QSize(60, 16777215));
        CB_RAM_Size->setEditable(true);
        CB_RAM_Size->setMaxVisibleItems(12);
        CB_RAM_Size->setMaxCount(32);

        vboxLayout1->addWidget(CB_RAM_Size);

        Label_Max_Mem = new QLabel(GB_Memory);
        Label_Max_Mem->setObjectName(QString::fromUtf8("Label_Max_Mem"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(Label_Max_Mem->sizePolicy().hasHeightForWidth());
        Label_Max_Mem->setSizePolicy(sizePolicy3);
        Label_Max_Mem->setMinimumSize(QSize(32, 20));
        Label_Max_Mem->setMaximumSize(QSize(60, 20));

        vboxLayout1->addWidget(Label_Max_Mem);


        gridLayout4->addLayout(vboxLayout1, 0, 1, 1, 1);


        gridLayout->addWidget(GB_Memory, 2, 0, 1, 1);

        GB_Audio = new QGroupBox(Tab_General);
        GB_Audio->setObjectName(QString::fromUtf8("GB_Audio"));
        gridLayout6 = new QGridLayout(GB_Audio);
        gridLayout6->setSpacing(4);
        gridLayout6->setContentsMargins(4, 4, 4, 4);
        gridLayout6->setObjectName(QString::fromUtf8("gridLayout6"));
        spacerItem7 = new QSpacerItem(16, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout6->addItem(spacerItem7, 1, 1, 1, 1);

        spacerItem8 = new QSpacerItem(21, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout6->addItem(spacerItem8, 0, 1, 1, 1);

        CH_GUS = new QCheckBox(GB_Audio);
        CH_GUS->setObjectName(QString::fromUtf8("CH_GUS"));

        gridLayout6->addWidget(CH_GUS, 1, 2, 1, 1);

        CH_es1370 = new QCheckBox(GB_Audio);
        CH_es1370->setObjectName(QString::fromUtf8("CH_es1370"));

        gridLayout6->addWidget(CH_es1370, 0, 2, 1, 1);

        spacerItem9 = new QSpacerItem(16, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout6->addItem(spacerItem9, 0, 3, 1, 1);

        spacerItem10 = new QSpacerItem(16, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout6->addItem(spacerItem10, 1, 3, 1, 1);

        CH_Adlib = new QCheckBox(GB_Audio);
        CH_Adlib->setObjectName(QString::fromUtf8("CH_Adlib"));

        gridLayout6->addWidget(CH_Adlib, 0, 4, 1, 1);

        CH_PCSPK = new QCheckBox(GB_Audio);
        CH_PCSPK->setObjectName(QString::fromUtf8("CH_PCSPK"));

        gridLayout6->addWidget(CH_PCSPK, 1, 4, 1, 1);

        CH_AC97 = new QCheckBox(GB_Audio);
        CH_AC97->setObjectName(QString::fromUtf8("CH_AC97"));

        gridLayout6->addWidget(CH_AC97, 1, 0, 1, 1);

        CH_sb16 = new QCheckBox(GB_Audio);
        CH_sb16->setObjectName(QString::fromUtf8("CH_sb16"));
        CH_sb16->setChecked(false);

        gridLayout6->addWidget(CH_sb16, 0, 0, 1, 1);


        gridLayout->addWidget(GB_Audio, 3, 0, 1, 1);

        Tabs->addTab(Tab_General, QString());
        Tab_HDD = new QWidget();
        Tab_HDD->setObjectName(QString::fromUtf8("Tab_HDD"));
        vboxLayout2 = new QVBoxLayout(Tab_HDD);
        vboxLayout2->setSpacing(6);
        vboxLayout2->setContentsMargins(9, 9, 9, 9);
        vboxLayout2->setObjectName(QString::fromUtf8("vboxLayout2"));
        GB_HDA = new QGroupBox(Tab_HDD);
        GB_HDA->setObjectName(QString::fromUtf8("GB_HDA"));
        GB_HDA->setCheckable(true);
        GB_HDA->setChecked(false);
        gridLayout7 = new QGridLayout(GB_HDA);
        gridLayout7->setSpacing(3);
        gridLayout7->setContentsMargins(6, 6, 6, 6);
        gridLayout7->setObjectName(QString::fromUtf8("gridLayout7"));
        Label_HDA_Info = new QLabel(GB_HDA);
        Label_HDA_Info->setObjectName(QString::fromUtf8("Label_HDA_Info"));
        Label_HDA_Info->setTextInteractionFlags(Qt::TextSelectableByMouse);

        gridLayout7->addWidget(Label_HDA_Info, 1, 0, 1, 1);

        vboxLayout3 = new QVBoxLayout();
        vboxLayout3->setSpacing(0);
        vboxLayout3->setContentsMargins(0, 0, 0, 0);
        vboxLayout3->setObjectName(QString::fromUtf8("vboxLayout3"));
        TB_HDA_SetPath = new QToolButton(GB_HDA);
        TB_HDA_SetPath->setObjectName(QString::fromUtf8("TB_HDA_SetPath"));
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(TB_HDA_SetPath->sizePolicy().hasHeightForWidth());
        TB_HDA_SetPath->setSizePolicy(sizePolicy4);

        vboxLayout3->addWidget(TB_HDA_SetPath);

        spacerItem11 = new QSpacerItem(20, 16, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vboxLayout3->addItem(spacerItem11);

        TB_HDA_Create_HDD = new QToolButton(GB_HDA);
        TB_HDA_Create_HDD->setObjectName(QString::fromUtf8("TB_HDA_Create_HDD"));
        sizePolicy4.setHeightForWidth(TB_HDA_Create_HDD->sizePolicy().hasHeightForWidth());
        TB_HDA_Create_HDD->setSizePolicy(sizePolicy4);
        TB_HDA_Create_HDD->setIcon(icon);

        vboxLayout3->addWidget(TB_HDA_Create_HDD);


        gridLayout7->addLayout(vboxLayout3, 0, 1, 2, 1);

        Edit_HDA_Image_Path = new QLineEdit(GB_HDA);
        Edit_HDA_Image_Path->setObjectName(QString::fromUtf8("Edit_HDA_Image_Path"));

        gridLayout7->addWidget(Edit_HDA_Image_Path, 0, 0, 1, 1);


        vboxLayout2->addWidget(GB_HDA);

        GB_HDB = new QGroupBox(Tab_HDD);
        GB_HDB->setObjectName(QString::fromUtf8("GB_HDB"));
        GB_HDB->setCheckable(true);
        GB_HDB->setChecked(false);
        gridLayout8 = new QGridLayout(GB_HDB);
        gridLayout8->setSpacing(3);
        gridLayout8->setContentsMargins(6, 6, 6, 6);
        gridLayout8->setObjectName(QString::fromUtf8("gridLayout8"));
        vboxLayout4 = new QVBoxLayout();
        vboxLayout4->setSpacing(0);
        vboxLayout4->setContentsMargins(0, 0, 0, 0);
        vboxLayout4->setObjectName(QString::fromUtf8("vboxLayout4"));
        TB_HDB_SetPath = new QToolButton(GB_HDB);
        TB_HDB_SetPath->setObjectName(QString::fromUtf8("TB_HDB_SetPath"));
        sizePolicy4.setHeightForWidth(TB_HDB_SetPath->sizePolicy().hasHeightForWidth());
        TB_HDB_SetPath->setSizePolicy(sizePolicy4);

        vboxLayout4->addWidget(TB_HDB_SetPath);

        spacerItem12 = new QSpacerItem(20, 16, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vboxLayout4->addItem(spacerItem12);

        TB_HDB_Create_HDD = new QToolButton(GB_HDB);
        TB_HDB_Create_HDD->setObjectName(QString::fromUtf8("TB_HDB_Create_HDD"));
        sizePolicy4.setHeightForWidth(TB_HDB_Create_HDD->sizePolicy().hasHeightForWidth());
        TB_HDB_Create_HDD->setSizePolicy(sizePolicy4);
        TB_HDB_Create_HDD->setIcon(icon);

        vboxLayout4->addWidget(TB_HDB_Create_HDD);


        gridLayout8->addLayout(vboxLayout4, 0, 1, 2, 1);

        Label_HDB_Info = new QLabel(GB_HDB);
        Label_HDB_Info->setObjectName(QString::fromUtf8("Label_HDB_Info"));
        Label_HDB_Info->setTextInteractionFlags(Qt::TextSelectableByMouse);

        gridLayout8->addWidget(Label_HDB_Info, 1, 0, 1, 1);

        Edit_HDB_Image_Path = new QLineEdit(GB_HDB);
        Edit_HDB_Image_Path->setObjectName(QString::fromUtf8("Edit_HDB_Image_Path"));

        gridLayout8->addWidget(Edit_HDB_Image_Path, 0, 0, 1, 1);


        vboxLayout2->addWidget(GB_HDB);

        GB_HDC = new QGroupBox(Tab_HDD);
        GB_HDC->setObjectName(QString::fromUtf8("GB_HDC"));
        GB_HDC->setCheckable(true);
        GB_HDC->setChecked(false);
        gridLayout9 = new QGridLayout(GB_HDC);
        gridLayout9->setSpacing(3);
        gridLayout9->setContentsMargins(6, 6, 6, 6);
        gridLayout9->setObjectName(QString::fromUtf8("gridLayout9"));
        vboxLayout5 = new QVBoxLayout();
        vboxLayout5->setSpacing(0);
        vboxLayout5->setContentsMargins(0, 0, 0, 0);
        vboxLayout5->setObjectName(QString::fromUtf8("vboxLayout5"));
        TB_HDC_SetPath = new QToolButton(GB_HDC);
        TB_HDC_SetPath->setObjectName(QString::fromUtf8("TB_HDC_SetPath"));
        sizePolicy4.setHeightForWidth(TB_HDC_SetPath->sizePolicy().hasHeightForWidth());
        TB_HDC_SetPath->setSizePolicy(sizePolicy4);

        vboxLayout5->addWidget(TB_HDC_SetPath);

        spacerItem13 = new QSpacerItem(20, 21, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vboxLayout5->addItem(spacerItem13);

        TB_HDC_Create_HDD = new QToolButton(GB_HDC);
        TB_HDC_Create_HDD->setObjectName(QString::fromUtf8("TB_HDC_Create_HDD"));
        sizePolicy4.setHeightForWidth(TB_HDC_Create_HDD->sizePolicy().hasHeightForWidth());
        TB_HDC_Create_HDD->setSizePolicy(sizePolicy4);
        TB_HDC_Create_HDD->setIcon(icon);

        vboxLayout5->addWidget(TB_HDC_Create_HDD);


        gridLayout9->addLayout(vboxLayout5, 0, 1, 2, 1);

        Label_HDC_Info = new QLabel(GB_HDC);
        Label_HDC_Info->setObjectName(QString::fromUtf8("Label_HDC_Info"));
        Label_HDC_Info->setTextInteractionFlags(Qt::TextSelectableByMouse);

        gridLayout9->addWidget(Label_HDC_Info, 1, 0, 1, 1);

        Edit_HDC_Image_Path = new QLineEdit(GB_HDC);
        Edit_HDC_Image_Path->setObjectName(QString::fromUtf8("Edit_HDC_Image_Path"));

        gridLayout9->addWidget(Edit_HDC_Image_Path, 0, 0, 1, 1);


        vboxLayout2->addWidget(GB_HDC);

        GB_HDD = new QGroupBox(Tab_HDD);
        GB_HDD->setObjectName(QString::fromUtf8("GB_HDD"));
        GB_HDD->setCheckable(true);
        GB_HDD->setChecked(false);
        gridLayout10 = new QGridLayout(GB_HDD);
        gridLayout10->setSpacing(3);
        gridLayout10->setContentsMargins(6, 6, 6, 6);
        gridLayout10->setObjectName(QString::fromUtf8("gridLayout10"));
        vboxLayout6 = new QVBoxLayout();
        vboxLayout6->setSpacing(0);
        vboxLayout6->setContentsMargins(0, 0, 0, 0);
        vboxLayout6->setObjectName(QString::fromUtf8("vboxLayout6"));
        TB_HDD_SetPath = new QToolButton(GB_HDD);
        TB_HDD_SetPath->setObjectName(QString::fromUtf8("TB_HDD_SetPath"));
        sizePolicy4.setHeightForWidth(TB_HDD_SetPath->sizePolicy().hasHeightForWidth());
        TB_HDD_SetPath->setSizePolicy(sizePolicy4);

        vboxLayout6->addWidget(TB_HDD_SetPath);

        spacerItem14 = new QSpacerItem(20, 16, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vboxLayout6->addItem(spacerItem14);

        TB_HDD_Create_HDD = new QToolButton(GB_HDD);
        TB_HDD_Create_HDD->setObjectName(QString::fromUtf8("TB_HDD_Create_HDD"));
        sizePolicy4.setHeightForWidth(TB_HDD_Create_HDD->sizePolicy().hasHeightForWidth());
        TB_HDD_Create_HDD->setSizePolicy(sizePolicy4);
        TB_HDD_Create_HDD->setIcon(icon);

        vboxLayout6->addWidget(TB_HDD_Create_HDD);


        gridLayout10->addLayout(vboxLayout6, 0, 1, 2, 1);

        Label_HDD_Info = new QLabel(GB_HDD);
        Label_HDD_Info->setObjectName(QString::fromUtf8("Label_HDD_Info"));
        Label_HDD_Info->setTextInteractionFlags(Qt::TextSelectableByMouse);

        gridLayout10->addWidget(Label_HDD_Info, 1, 0, 1, 1);

        Edit_HDD_Image_Path = new QLineEdit(GB_HDD);
        Edit_HDD_Image_Path->setObjectName(QString::fromUtf8("Edit_HDD_Image_Path"));

        gridLayout10->addWidget(Edit_HDD_Image_Path, 0, 0, 1, 1);


        vboxLayout2->addWidget(GB_HDD);

        Tabs->addTab(Tab_HDD, QString());
        Tab_Removable_Disks = new QWidget();
        Tab_Removable_Disks->setObjectName(QString::fromUtf8("Tab_Removable_Disks"));
        gridLayout11 = new QGridLayout(Tab_Removable_Disks);
        gridLayout11->setSpacing(6);
        gridLayout11->setContentsMargins(9, 9, 9, 9);
        gridLayout11->setObjectName(QString::fromUtf8("gridLayout11"));
        GB_Floppy0 = new QGroupBox(Tab_Removable_Disks);
        GB_Floppy0->setObjectName(QString::fromUtf8("GB_Floppy0"));
        GB_Floppy0->setCheckable(true);
        GB_Floppy0->setChecked(false);
        gridLayout12 = new QGridLayout(GB_Floppy0);
        gridLayout12->setSpacing(3);
        gridLayout12->setContentsMargins(6, 6, 6, 6);
        gridLayout12->setObjectName(QString::fromUtf8("gridLayout12"));
        CB_FD0_Host_Devices = new QComboBox(GB_Floppy0);
        CB_FD0_Host_Devices->setObjectName(QString::fromUtf8("CB_FD0_Host_Devices"));

        gridLayout12->addWidget(CB_FD0_Host_Devices, 1, 0, 1, 2);

        RB_FD0_Use_Image_File = new QRadioButton(GB_Floppy0);
        RB_FD0_Use_Image_File->setObjectName(QString::fromUtf8("RB_FD0_Use_Image_File"));

        gridLayout12->addWidget(RB_FD0_Use_Image_File, 2, 0, 1, 1);

        Edit_FD0_Image_File_Path = new QLineEdit(GB_Floppy0);
        Edit_FD0_Image_File_Path->setObjectName(QString::fromUtf8("Edit_FD0_Image_File_Path"));
        Edit_FD0_Image_File_Path->setEnabled(false);

        gridLayout12->addWidget(Edit_FD0_Image_File_Path, 3, 0, 1, 1);

        TB_FD0_SetPath = new QToolButton(GB_Floppy0);
        TB_FD0_SetPath->setObjectName(QString::fromUtf8("TB_FD0_SetPath"));
        TB_FD0_SetPath->setEnabled(false);

        gridLayout12->addWidget(TB_FD0_SetPath, 3, 1, 1, 1);

        RB_FD0_Use_Host_Device = new QRadioButton(GB_Floppy0);
        RB_FD0_Use_Host_Device->setObjectName(QString::fromUtf8("RB_FD0_Use_Host_Device"));
        RB_FD0_Use_Host_Device->setChecked(true);

        gridLayout12->addWidget(RB_FD0_Use_Host_Device, 0, 0, 1, 1);


        gridLayout11->addWidget(GB_Floppy0, 1, 0, 1, 1);

        GB_CDROM = new QGroupBox(Tab_Removable_Disks);
        GB_CDROM->setObjectName(QString::fromUtf8("GB_CDROM"));
        GB_CDROM->setCheckable(true);
        GB_CDROM->setChecked(false);
        gridLayout13 = new QGridLayout(GB_CDROM);
        gridLayout13->setSpacing(3);
        gridLayout13->setContentsMargins(6, 6, 6, 6);
        gridLayout13->setObjectName(QString::fromUtf8("gridLayout13"));
        RB_CDROM_Use_Host_Device = new QRadioButton(GB_CDROM);
        RB_CDROM_Use_Host_Device->setObjectName(QString::fromUtf8("RB_CDROM_Use_Host_Device"));
        RB_CDROM_Use_Host_Device->setChecked(true);

        gridLayout13->addWidget(RB_CDROM_Use_Host_Device, 0, 0, 1, 1);

        CB_CDROM_Host_Devices = new QComboBox(GB_CDROM);
        CB_CDROM_Host_Devices->setObjectName(QString::fromUtf8("CB_CDROM_Host_Devices"));

        gridLayout13->addWidget(CB_CDROM_Host_Devices, 1, 0, 1, 2);

        Edit_CDROM_Image_File_Path = new QLineEdit(GB_CDROM);
        Edit_CDROM_Image_File_Path->setObjectName(QString::fromUtf8("Edit_CDROM_Image_File_Path"));
        Edit_CDROM_Image_File_Path->setEnabled(false);

        gridLayout13->addWidget(Edit_CDROM_Image_File_Path, 3, 0, 1, 1);

        TB_CDROM_SetPath = new QToolButton(GB_CDROM);
        TB_CDROM_SetPath->setObjectName(QString::fromUtf8("TB_CDROM_SetPath"));
        TB_CDROM_SetPath->setEnabled(false);

        gridLayout13->addWidget(TB_CDROM_SetPath, 3, 1, 1, 1);

        RB_CDROM_Use_Image_File = new QRadioButton(GB_CDROM);
        RB_CDROM_Use_Image_File->setObjectName(QString::fromUtf8("RB_CDROM_Use_Image_File"));

        gridLayout13->addWidget(RB_CDROM_Use_Image_File, 2, 0, 1, 1);


        gridLayout11->addWidget(GB_CDROM, 0, 0, 1, 1);

        GB_Floppy1 = new QGroupBox(Tab_Removable_Disks);
        GB_Floppy1->setObjectName(QString::fromUtf8("GB_Floppy1"));
        GB_Floppy1->setCheckable(true);
        GB_Floppy1->setChecked(false);
        gridLayout14 = new QGridLayout(GB_Floppy1);
        gridLayout14->setSpacing(3);
        gridLayout14->setContentsMargins(6, 6, 6, 6);
        gridLayout14->setObjectName(QString::fromUtf8("gridLayout14"));
        RB_FD1_Use_Host_Device = new QRadioButton(GB_Floppy1);
        RB_FD1_Use_Host_Device->setObjectName(QString::fromUtf8("RB_FD1_Use_Host_Device"));
        RB_FD1_Use_Host_Device->setChecked(true);

        gridLayout14->addWidget(RB_FD1_Use_Host_Device, 0, 0, 1, 1);

        CB_FD1_Host_Devices = new QComboBox(GB_Floppy1);
        CB_FD1_Host_Devices->setObjectName(QString::fromUtf8("CB_FD1_Host_Devices"));

        gridLayout14->addWidget(CB_FD1_Host_Devices, 1, 0, 1, 2);

        Edit_FD1_Image_File_Path = new QLineEdit(GB_Floppy1);
        Edit_FD1_Image_File_Path->setObjectName(QString::fromUtf8("Edit_FD1_Image_File_Path"));
        Edit_FD1_Image_File_Path->setEnabled(false);

        gridLayout14->addWidget(Edit_FD1_Image_File_Path, 3, 0, 1, 1);

        TB_FD1_SetPath = new QToolButton(GB_Floppy1);
        TB_FD1_SetPath->setObjectName(QString::fromUtf8("TB_FD1_SetPath"));
        TB_FD1_SetPath->setEnabled(false);

        gridLayout14->addWidget(TB_FD1_SetPath, 3, 1, 1, 1);

        RB_FD1_Use_Image_File = new QRadioButton(GB_Floppy1);
        RB_FD1_Use_Image_File->setObjectName(QString::fromUtf8("RB_FD1_Use_Image_File"));

        gridLayout14->addWidget(RB_FD1_Use_Image_File, 2, 0, 1, 1);


        gridLayout11->addWidget(GB_Floppy1, 2, 0, 1, 1);

        Tabs->addTab(Tab_Removable_Disks, QString());
        Tab_Network = new QWidget();
        Tab_Network->setObjectName(QString::fromUtf8("Tab_Network"));
        gridLayout15 = new QGridLayout(Tab_Network);
        gridLayout15->setSpacing(6);
        gridLayout15->setContentsMargins(9, 9, 9, 9);
        gridLayout15->setObjectName(QString::fromUtf8("gridLayout15"));
        Network_Cards_Tabs = new QTabWidget(Tab_Network);
        Network_Cards_Tabs->setObjectName(QString::fromUtf8("Network_Cards_Tabs"));
        Network_Cards_Tab = new QWidget();
        Network_Cards_Tab->setObjectName(QString::fromUtf8("Network_Cards_Tab"));
        gridLayout16 = new QGridLayout(Network_Cards_Tab);
        gridLayout16->setSpacing(6);
        gridLayout16->setContentsMargins(9, 9, 9, 9);
        gridLayout16->setObjectName(QString::fromUtf8("gridLayout16"));
        Net_Card_Options = new QWidget(Network_Cards_Tab);
        Net_Card_Options->setObjectName(QString::fromUtf8("Net_Card_Options"));
        gridLayout17 = new QGridLayout(Net_Card_Options);
        gridLayout17->setSpacing(0);
        gridLayout17->setContentsMargins(0, 0, 0, 0);
        gridLayout17->setObjectName(QString::fromUtf8("gridLayout17"));
        vboxLayout7 = new QVBoxLayout();
        vboxLayout7->setSpacing(6);
        vboxLayout7->setContentsMargins(0, 0, 0, 0);
        vboxLayout7->setObjectName(QString::fromUtf8("vboxLayout7"));
        gridLayout18 = new QGridLayout();
        gridLayout18->setSpacing(6);
        gridLayout18->setContentsMargins(0, 0, 0, 0);
        gridLayout18->setObjectName(QString::fromUtf8("gridLayout18"));
        Label_NetCard_Model = new QLabel(Net_Card_Options);
        Label_NetCard_Model->setObjectName(QString::fromUtf8("Label_NetCard_Model"));

        gridLayout18->addWidget(Label_NetCard_Model, 0, 0, 1, 1);

        Label_Connection_Mode = new QLabel(Net_Card_Options);
        Label_Connection_Mode->setObjectName(QString::fromUtf8("Label_Connection_Mode"));
        sizePolicy1.setHeightForWidth(Label_Connection_Mode->sizePolicy().hasHeightForWidth());
        Label_Connection_Mode->setSizePolicy(sizePolicy1);

        gridLayout18->addWidget(Label_Connection_Mode, 1, 0, 1, 1);

        CB_Network_Card_Model = new QComboBox(Net_Card_Options);
        CB_Network_Card_Model->setObjectName(QString::fromUtf8("CB_Network_Card_Model"));
        CB_Network_Card_Model->setMaxCount(32);

        gridLayout18->addWidget(CB_Network_Card_Model, 0, 1, 1, 1);

        CB_Connection_Mode = new QComboBox(Net_Card_Options);
        CB_Connection_Mode->addItem(QString());
        CB_Connection_Mode->addItem(QString());
        CB_Connection_Mode->addItem(QString());
        CB_Connection_Mode->addItem(QString());
        CB_Connection_Mode->addItem(QString());
        CB_Connection_Mode->addItem(QString());
        CB_Connection_Mode->addItem(QString());
        CB_Connection_Mode->addItem(QString());
        CB_Connection_Mode->addItem(QString());
        CB_Connection_Mode->setObjectName(QString::fromUtf8("CB_Connection_Mode"));
        sizePolicy.setHeightForWidth(CB_Connection_Mode->sizePolicy().hasHeightForWidth());
        CB_Connection_Mode->setSizePolicy(sizePolicy);
        CB_Connection_Mode->setMaxCount(32);

        gridLayout18->addWidget(CB_Connection_Mode, 1, 1, 1, 1);

        Line_nc_2 = new QFrame(Net_Card_Options);
        Line_nc_2->setObjectName(QString::fromUtf8("Line_nc_2"));
        Line_nc_2->setFrameShape(QFrame::HLine);
        Line_nc_2->setFrameShadow(QFrame::Sunken);

        gridLayout18->addWidget(Line_nc_2, 2, 0, 1, 2);


        vboxLayout7->addLayout(gridLayout18);

        hboxLayout2 = new QHBoxLayout();
        hboxLayout2->setSpacing(6);
        hboxLayout2->setContentsMargins(0, 0, 0, 0);
        hboxLayout2->setObjectName(QString::fromUtf8("hboxLayout2"));
        gridLayout19 = new QGridLayout();
        gridLayout19->setSpacing(6);
        gridLayout19->setContentsMargins(0, 0, 0, 0);
        gridLayout19->setObjectName(QString::fromUtf8("gridLayout19"));
        Label_IP = new QLabel(Net_Card_Options);
        Label_IP->setObjectName(QString::fromUtf8("Label_IP"));
        sizePolicy1.setHeightForWidth(Label_IP->sizePolicy().hasHeightForWidth());
        Label_IP->setSizePolicy(sizePolicy1);

        gridLayout19->addWidget(Label_IP, 1, 0, 1, 1);

        Edit_IP_Address = new QLineEdit(Net_Card_Options);
        Edit_IP_Address->setObjectName(QString::fromUtf8("Edit_IP_Address"));
        Edit_IP_Address->setMaxLength(24);
        Edit_IP_Address->setCursorPosition(0);

        gridLayout19->addWidget(Edit_IP_Address, 1, 1, 1, 1);

        Label_MAC = new QLabel(Net_Card_Options);
        Label_MAC->setObjectName(QString::fromUtf8("Label_MAC"));
        sizePolicy1.setHeightForWidth(Label_MAC->sizePolicy().hasHeightForWidth());
        Label_MAC->setSizePolicy(sizePolicy1);

        gridLayout19->addWidget(Label_MAC, 2, 0, 1, 1);

        Edit_MAC_Address = new QLineEdit(Net_Card_Options);
        Edit_MAC_Address->setObjectName(QString::fromUtf8("Edit_MAC_Address"));
        Edit_MAC_Address->setMaxLength(18);
        Edit_MAC_Address->setCursorPosition(0);

        gridLayout19->addWidget(Edit_MAC_Address, 2, 1, 1, 1);

        TB_Generate_New_MAC = new QToolButton(Net_Card_Options);
        TB_Generate_New_MAC->setObjectName(QString::fromUtf8("TB_Generate_New_MAC"));
        TB_Generate_New_MAC->setIcon(icon);

        gridLayout19->addWidget(TB_Generate_New_MAC, 2, 2, 1, 1);

        Label_Host_Name = new QLabel(Net_Card_Options);
        Label_Host_Name->setObjectName(QString::fromUtf8("Label_Host_Name"));

        gridLayout19->addWidget(Label_Host_Name, 0, 0, 1, 1);

        Edit_Hostname = new QLineEdit(Net_Card_Options);
        Edit_Hostname->setObjectName(QString::fromUtf8("Edit_Hostname"));

        gridLayout19->addWidget(Edit_Hostname, 0, 1, 1, 1);


        hboxLayout2->addLayout(gridLayout19);

        spacerItem15 = new QSpacerItem(16, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        hboxLayout2->addItem(spacerItem15);

        gridLayout20 = new QGridLayout();
        gridLayout20->setSpacing(6);
        gridLayout20->setContentsMargins(0, 0, 0, 0);
        gridLayout20->setObjectName(QString::fromUtf8("gridLayout20"));
        SB_Port = new QSpinBox(Net_Card_Options);
        SB_Port->setObjectName(QString::fromUtf8("SB_Port"));
        sizePolicy2.setHeightForWidth(SB_Port->sizePolicy().hasHeightForWidth());
        SB_Port->setSizePolicy(sizePolicy2);
        SB_Port->setMinimumSize(QSize(80, 0));
        SB_Port->setMaximumSize(QSize(80, 16777215));
        SB_Port->setMinimum(1);
        SB_Port->setMaximum(50000);

        gridLayout20->addWidget(SB_Port, 1, 1, 1, 1);

        Label_Port = new QLabel(Net_Card_Options);
        Label_Port->setObjectName(QString::fromUtf8("Label_Port"));
        sizePolicy1.setHeightForWidth(Label_Port->sizePolicy().hasHeightForWidth());
        Label_Port->setSizePolicy(sizePolicy1);

        gridLayout20->addWidget(Label_Port, 1, 0, 1, 1);

        Label_VLAN = new QLabel(Net_Card_Options);
        Label_VLAN->setObjectName(QString::fromUtf8("Label_VLAN"));
        sizePolicy1.setHeightForWidth(Label_VLAN->sizePolicy().hasHeightForWidth());
        Label_VLAN->setSizePolicy(sizePolicy1);

        gridLayout20->addWidget(Label_VLAN, 2, 0, 1, 1);

        SB_File_Descriptor = new QSpinBox(Net_Card_Options);
        SB_File_Descriptor->setObjectName(QString::fromUtf8("SB_File_Descriptor"));
        SB_File_Descriptor->setMinimumSize(QSize(80, 0));
        SB_File_Descriptor->setMaximumSize(QSize(80, 16777215));
        SB_File_Descriptor->setMinimum(1);
        SB_File_Descriptor->setMaximum(99999999);

        gridLayout20->addWidget(SB_File_Descriptor, 0, 1, 1, 1);

        SB_VLAN = new QSpinBox(Net_Card_Options);
        SB_VLAN->setObjectName(QString::fromUtf8("SB_VLAN"));
        SB_VLAN->setMinimumSize(QSize(80, 0));
        SB_VLAN->setMaximumSize(QSize(80, 16777215));

        gridLayout20->addWidget(SB_VLAN, 2, 1, 1, 1);

        Label_File_Descriptor = new QLabel(Net_Card_Options);
        Label_File_Descriptor->setObjectName(QString::fromUtf8("Label_File_Descriptor"));

        gridLayout20->addWidget(Label_File_Descriptor, 0, 0, 1, 1);


        hboxLayout2->addLayout(gridLayout20);


        vboxLayout7->addLayout(hboxLayout2);

        gridLayout21 = new QGridLayout();
        gridLayout21->setSpacing(6);
        gridLayout21->setContentsMargins(0, 0, 0, 0);
        gridLayout21->setObjectName(QString::fromUtf8("gridLayout21"));
        TB_Browse_TUN_Script = new QToolButton(Net_Card_Options);
        TB_Browse_TUN_Script->setObjectName(QString::fromUtf8("TB_Browse_TUN_Script"));

        gridLayout21->addWidget(TB_Browse_TUN_Script, 1, 2, 1, 1);

        Edit_TUN_TAP_Script = new QLineEdit(Net_Card_Options);
        Edit_TUN_TAP_Script->setObjectName(QString::fromUtf8("Edit_TUN_TAP_Script"));

        gridLayout21->addWidget(Edit_TUN_TAP_Script, 1, 1, 1, 1);

        Label_If_Name = new QLabel(Net_Card_Options);
        Label_If_Name->setObjectName(QString::fromUtf8("Label_If_Name"));

        gridLayout21->addWidget(Label_If_Name, 2, 0, 1, 1);

        Edit_Interface_Name = new QLineEdit(Net_Card_Options);
        Edit_Interface_Name->setObjectName(QString::fromUtf8("Edit_Interface_Name"));

        gridLayout21->addWidget(Edit_Interface_Name, 2, 1, 1, 2);

        Line_nc_3 = new QFrame(Net_Card_Options);
        Line_nc_3->setObjectName(QString::fromUtf8("Line_nc_3"));
        Line_nc_3->setFrameShape(QFrame::HLine);
        Line_nc_3->setFrameShadow(QFrame::Sunken);

        gridLayout21->addWidget(Line_nc_3, 0, 0, 1, 3);

        CH_TUN_TAP_Script = new QCheckBox(Net_Card_Options);
        CH_TUN_TAP_Script->setObjectName(QString::fromUtf8("CH_TUN_TAP_Script"));
        CH_TUN_TAP_Script->setChecked(true);

        gridLayout21->addWidget(CH_TUN_TAP_Script, 1, 0, 1, 1);


        vboxLayout7->addLayout(gridLayout21);


        gridLayout17->addLayout(vboxLayout7, 0, 0, 1, 1);


        gridLayout16->addWidget(Net_Card_Options, 1, 0, 1, 1);

        gridLayout22 = new QGridLayout();
        gridLayout22->setSpacing(6);
        gridLayout22->setContentsMargins(0, 0, 0, 0);
        gridLayout22->setObjectName(QString::fromUtf8("gridLayout22"));
        Button_Delete_Net_Card = new QPushButton(Network_Cards_Tab);
        Button_Delete_Net_Card->setObjectName(QString::fromUtf8("Button_Delete_Net_Card"));

        gridLayout22->addWidget(Button_Delete_Net_Card, 3, 1, 1, 1);

        spacerItem16 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout22->addItem(spacerItem16, 2, 1, 1, 1);

        Button_Add_Net_Card = new QPushButton(Network_Cards_Tab);
        Button_Add_Net_Card->setObjectName(QString::fromUtf8("Button_Add_Net_Card"));

        gridLayout22->addWidget(Button_Add_Net_Card, 1, 1, 1, 1);

        Label_Cards_List = new QLabel(Network_Cards_Tab);
        Label_Cards_List->setObjectName(QString::fromUtf8("Label_Cards_List"));
        QSizePolicy sizePolicy5(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(Label_Cards_List->sizePolicy().hasHeightForWidth());
        Label_Cards_List->setSizePolicy(sizePolicy5);

        gridLayout22->addWidget(Label_Cards_List, 0, 0, 1, 2);

        Network_Cards_List = new QListWidget(Network_Cards_Tab);
        Network_Cards_List->setObjectName(QString::fromUtf8("Network_Cards_List"));
        QSizePolicy sizePolicy6(QSizePolicy::Expanding, QSizePolicy::Ignored);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(Network_Cards_List->sizePolicy().hasHeightForWidth());
        Network_Cards_List->setSizePolicy(sizePolicy6);

        gridLayout22->addWidget(Network_Cards_List, 1, 0, 3, 1);


        gridLayout16->addLayout(gridLayout22, 0, 0, 1, 1);

        Network_Cards_Tabs->addTab(Network_Cards_Tab, QString());
        Tab_Network_Settings = new QWidget();
        Tab_Network_Settings->setObjectName(QString::fromUtf8("Tab_Network_Settings"));
        gridLayout23 = new QGridLayout(Tab_Network_Settings);
        gridLayout23->setSpacing(6);
        gridLayout23->setContentsMargins(9, 9, 9, 9);
        gridLayout23->setObjectName(QString::fromUtf8("gridLayout23"));
        GB_Redirections = new QGroupBox(Tab_Network_Settings);
        GB_Redirections->setObjectName(QString::fromUtf8("GB_Redirections"));
        GB_Redirections->setCheckable(true);
        GB_Redirections->setChecked(false);
        gridLayout24 = new QGridLayout(GB_Redirections);
        gridLayout24->setSpacing(5);
        gridLayout24->setContentsMargins(7, 7, 7, 7);
        gridLayout24->setObjectName(QString::fromUtf8("gridLayout24"));
        hboxLayout3 = new QHBoxLayout();
        hboxLayout3->setSpacing(6);
        hboxLayout3->setContentsMargins(0, 0, 0, 0);
        hboxLayout3->setObjectName(QString::fromUtf8("hboxLayout3"));
        Label_Protocol = new QLabel(GB_Redirections);
        Label_Protocol->setObjectName(QString::fromUtf8("Label_Protocol"));

        hboxLayout3->addWidget(Label_Protocol);

        RB_TCP = new QRadioButton(GB_Redirections);
        RB_TCP->setObjectName(QString::fromUtf8("RB_TCP"));
        RB_TCP->setChecked(true);

        hboxLayout3->addWidget(RB_TCP);

        RB_UDP = new QRadioButton(GB_Redirections);
        RB_UDP->setObjectName(QString::fromUtf8("RB_UDP"));

        hboxLayout3->addWidget(RB_UDP);

        spacerItem17 = new QSpacerItem(271, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout3->addItem(spacerItem17);


        gridLayout24->addLayout(hboxLayout3, 3, 0, 1, 1);

        hboxLayout4 = new QHBoxLayout();
        hboxLayout4->setSpacing(6);
        hboxLayout4->setContentsMargins(0, 0, 0, 0);
        hboxLayout4->setObjectName(QString::fromUtf8("hboxLayout4"));
        Label_Port1 = new QLabel(GB_Redirections);
        Label_Port1->setObjectName(QString::fromUtf8("Label_Port1"));

        hboxLayout4->addWidget(Label_Port1);

        SB_Redir_Port = new QSpinBox(GB_Redirections);
        SB_Redir_Port->setObjectName(QString::fromUtf8("SB_Redir_Port"));
        SB_Redir_Port->setMinimum(1);
        SB_Redir_Port->setMaximum(65535);
        SB_Redir_Port->setValue(1024);

        hboxLayout4->addWidget(SB_Redir_Port);

        Label_To_Guest_IP = new QLabel(GB_Redirections);
        Label_To_Guest_IP->setObjectName(QString::fromUtf8("Label_To_Guest_IP"));

        hboxLayout4->addWidget(Label_To_Guest_IP);

        Edit_Guest_IP = new QLineEdit(GB_Redirections);
        Edit_Guest_IP->setObjectName(QString::fromUtf8("Edit_Guest_IP"));

        hboxLayout4->addWidget(Edit_Guest_IP);

        Label_Port2 = new QLabel(GB_Redirections);
        Label_Port2->setObjectName(QString::fromUtf8("Label_Port2"));

        hboxLayout4->addWidget(Label_Port2);

        SB_Guest_Port = new QSpinBox(GB_Redirections);
        SB_Guest_Port->setObjectName(QString::fromUtf8("SB_Guest_Port"));
        SB_Guest_Port->setMinimum(1);
        SB_Guest_Port->setMaximum(65535);
        SB_Guest_Port->setValue(1024);

        hboxLayout4->addWidget(SB_Guest_Port);


        gridLayout24->addLayout(hboxLayout4, 4, 0, 1, 1);

        hboxLayout5 = new QHBoxLayout();
        hboxLayout5->setSpacing(6);
        hboxLayout5->setContentsMargins(0, 0, 0, 0);
        hboxLayout5->setObjectName(QString::fromUtf8("hboxLayout5"));
        Button_Add_Redirections = new QPushButton(GB_Redirections);
        Button_Add_Redirections->setObjectName(QString::fromUtf8("Button_Add_Redirections"));

        hboxLayout5->addWidget(Button_Add_Redirections);

        Button_Delete_Redirections = new QPushButton(GB_Redirections);
        Button_Delete_Redirections->setObjectName(QString::fromUtf8("Button_Delete_Redirections"));

        hboxLayout5->addWidget(Button_Delete_Redirections);

        Button_Apply_Redirections = new QPushButton(GB_Redirections);
        Button_Apply_Redirections->setObjectName(QString::fromUtf8("Button_Apply_Redirections"));

        hboxLayout5->addWidget(Button_Apply_Redirections);

        Button_Clear_Redirections = new QPushButton(GB_Redirections);
        Button_Clear_Redirections->setObjectName(QString::fromUtf8("Button_Clear_Redirections"));

        hboxLayout5->addWidget(Button_Clear_Redirections);


        gridLayout24->addLayout(hboxLayout5, 1, 0, 1, 1);

        Redirections_List = new QTableWidget(GB_Redirections);
        if (Redirections_List->columnCount() < 4)
            Redirections_List->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        Redirections_List->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        Redirections_List->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        Redirections_List->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        Redirections_List->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        Redirections_List->setObjectName(QString::fromUtf8("Redirections_List"));
        QSizePolicy sizePolicy7(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(Redirections_List->sizePolicy().hasHeightForWidth());
        Redirections_List->setSizePolicy(sizePolicy7);
        Redirections_List->setMinimumSize(QSize(400, 95));
        Redirections_List->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        Redirections_List->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        Redirections_List->setSelectionMode(QAbstractItemView::SingleSelection);
        Redirections_List->setSelectionBehavior(QAbstractItemView::SelectRows);
        Redirections_List->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);

        gridLayout24->addWidget(Redirections_List, 0, 0, 1, 1);

        hboxLayout6 = new QHBoxLayout();
        hboxLayout6->setSpacing(6);
        hboxLayout6->setContentsMargins(0, 0, 0, 0);
        hboxLayout6->setObjectName(QString::fromUtf8("hboxLayout6"));
        Label_Redirect_Settings = new QLabel(GB_Redirections);
        Label_Redirect_Settings->setObjectName(QString::fromUtf8("Label_Redirect_Settings"));
        sizePolicy1.setHeightForWidth(Label_Redirect_Settings->sizePolicy().hasHeightForWidth());
        Label_Redirect_Settings->setSizePolicy(sizePolicy1);

        hboxLayout6->addWidget(Label_Redirect_Settings);

        line_redir_1 = new QFrame(GB_Redirections);
        line_redir_1->setObjectName(QString::fromUtf8("line_redir_1"));
        line_redir_1->setFrameShape(QFrame::HLine);
        line_redir_1->setFrameShadow(QFrame::Sunken);

        hboxLayout6->addWidget(line_redir_1);


        gridLayout24->addLayout(hboxLayout6, 2, 0, 1, 1);


        gridLayout23->addWidget(GB_Redirections, 0, 0, 1, 1);

        gridLayout25 = new QGridLayout();
        gridLayout25->setSpacing(3);
        gridLayout25->setContentsMargins(0, 0, 0, 0);
        gridLayout25->setObjectName(QString::fromUtf8("gridLayout25"));
        Label_SMB_Folder = new QLabel(Tab_Network_Settings);
        Label_SMB_Folder->setObjectName(QString::fromUtf8("Label_SMB_Folder"));

        gridLayout25->addWidget(Label_SMB_Folder, 1, 0, 1, 1);

        Edit_TFTP_Prefix = new QLineEdit(Tab_Network_Settings);
        Edit_TFTP_Prefix->setObjectName(QString::fromUtf8("Edit_TFTP_Prefix"));

        gridLayout25->addWidget(Edit_TFTP_Prefix, 0, 1, 1, 2);

        Label_TFTP = new QLabel(Tab_Network_Settings);
        Label_TFTP->setObjectName(QString::fromUtf8("Label_TFTP"));

        gridLayout25->addWidget(Label_TFTP, 0, 0, 1, 1);

        Edit_SMB_Folder = new QLineEdit(Tab_Network_Settings);
        Edit_SMB_Folder->setObjectName(QString::fromUtf8("Edit_SMB_Folder"));

        gridLayout25->addWidget(Edit_SMB_Folder, 1, 1, 1, 1);

        TB_Browse_SMB = new QToolButton(Tab_Network_Settings);
        TB_Browse_SMB->setObjectName(QString::fromUtf8("TB_Browse_SMB"));

        gridLayout25->addWidget(TB_Browse_SMB, 1, 2, 1, 1);


        gridLayout23->addLayout(gridLayout25, 1, 0, 1, 1);

        Network_Cards_Tabs->addTab(Tab_Network_Settings, QString());

        gridLayout15->addWidget(Network_Cards_Tabs, 1, 0, 1, 1);

        CH_Use_Network = new QCheckBox(Tab_Network);
        CH_Use_Network->setObjectName(QString::fromUtf8("CH_Use_Network"));

        gridLayout15->addWidget(CH_Use_Network, 0, 0, 1, 1);

        Tabs->addTab(Tab_Network, QString());
        Tab_Advanced = new QWidget();
        Tab_Advanced->setObjectName(QString::fromUtf8("Tab_Advanced"));
        gridLayout9999 = new QGridLayout(Tab_Advanced);
        gridLayout9999->setSpacing(4);
        gridLayout9999->setContentsMargins(6, 6, 6, 6);
        gridLayout9999->setObjectName(QString::fromUtf8("gridLayout9999"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(4);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        Label_QEMU_Window_Options = new QLabel(Tab_Advanced);
        Label_QEMU_Window_Options->setObjectName(QString::fromUtf8("Label_QEMU_Window_Options"));
        sizePolicy1.setHeightForWidth(Label_QEMU_Window_Options->sizePolicy().hasHeightForWidth());
        Label_QEMU_Window_Options->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(Label_QEMU_Window_Options);

        line_5 = new QFrame(Tab_Advanced);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);

        horizontalLayout_2->addWidget(line_5);


        gridLayout9999->addLayout(horizontalLayout_2, 0, 0, 1, 4);

        CH_No_Frame = new QCheckBox(Tab_Advanced);
        CH_No_Frame->setObjectName(QString::fromUtf8("CH_No_Frame"));

        gridLayout9999->addWidget(CH_No_Frame, 1, 0, 1, 4);

        CH_Alt_Grab = new QCheckBox(Tab_Advanced);
        CH_Alt_Grab->setObjectName(QString::fromUtf8("CH_Alt_Grab"));

        gridLayout9999->addWidget(CH_Alt_Grab, 2, 0, 1, 4);

        CH_No_Quit = new QCheckBox(Tab_Advanced);
        CH_No_Quit->setObjectName(QString::fromUtf8("CH_No_Quit"));

        gridLayout9999->addWidget(CH_No_Quit, 3, 0, 1, 4);

        CH_Portrait = new QCheckBox(Tab_Advanced);
        CH_Portrait->setObjectName(QString::fromUtf8("CH_Portrait"));

        gridLayout9999->addWidget(CH_Portrait, 4, 0, 1, 4);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(4);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        Label_Additional_Options = new QLabel(Tab_Advanced);
        Label_Additional_Options->setObjectName(QString::fromUtf8("Label_Additional_Options"));
        sizePolicy1.setHeightForWidth(Label_Additional_Options->sizePolicy().hasHeightForWidth());
        Label_Additional_Options->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(Label_Additional_Options);

        line_4 = new QFrame(Tab_Advanced);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line_4);


        gridLayout9999->addLayout(horizontalLayout, 5, 0, 1, 4);

        CH_FDD_Boot = new QCheckBox(Tab_Advanced);
        CH_FDD_Boot->setObjectName(QString::fromUtf8("CH_FDD_Boot"));

        gridLayout9999->addWidget(CH_FDD_Boot, 6, 0, 1, 4);

        CH_QEMU_Log = new QCheckBox(Tab_Advanced);
        CH_QEMU_Log->setObjectName(QString::fromUtf8("CH_QEMU_Log"));

        gridLayout9999->addWidget(CH_QEMU_Log, 7, 0, 1, 4);

        CH_Win2K_Hack = new QCheckBox(Tab_Advanced);
        CH_Win2K_Hack->setObjectName(QString::fromUtf8("CH_Win2K_Hack"));

        gridLayout9999->addWidget(CH_Win2K_Hack, 8, 0, 1, 4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(4);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        CH_Start_Date = new QCheckBox(Tab_Advanced);
        CH_Start_Date->setObjectName(QString::fromUtf8("CH_Start_Date"));

        horizontalLayout_5->addWidget(CH_Start_Date);

        horizontalSpacer_4 = new QSpacerItem(5, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_4);

        DTE_Start_Date = new QDateTimeEdit(Tab_Advanced);
        DTE_Start_Date->setObjectName(QString::fromUtf8("DTE_Start_Date"));
        DTE_Start_Date->setEnabled(false);
        DTE_Start_Date->setDate(QDate(2009, 1, 20));
        DTE_Start_Date->setTime(QTime(14, 30, 0));
        DTE_Start_Date->setMaximumDate(QDate(2100, 12, 31));
        DTE_Start_Date->setMinimumDate(QDate(1975, 1, 1));

        horizontalLayout_5->addWidget(DTE_Start_Date);


        gridLayout9999->addLayout(horizontalLayout_5, 9, 0, 1, 4);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(4);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        CH_Init_Graphic_Mode = new QCheckBox(Tab_Advanced);
        CH_Init_Graphic_Mode->setObjectName(QString::fromUtf8("CH_Init_Graphic_Mode"));

        horizontalLayout_4->addWidget(CH_Init_Graphic_Mode);

        horizontalSpacer_3 = new QSpacerItem(18, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        Label_W = new QLabel(Tab_Advanced);
        Label_W->setObjectName(QString::fromUtf8("Label_W"));
        Label_W->setEnabled(false);

        horizontalLayout_4->addWidget(Label_W);

        SB_InitGM_Width = new QSpinBox(Tab_Advanced);
        SB_InitGM_Width->setObjectName(QString::fromUtf8("SB_InitGM_Width"));
        SB_InitGM_Width->setEnabled(false);
        SB_InitGM_Width->setMinimum(640);
        SB_InitGM_Width->setMaximum(1600);
        SB_InitGM_Width->setValue(800);

        horizontalLayout_4->addWidget(SB_InitGM_Width);

        horizontalSpacer = new QSpacerItem(13, 17, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        Label_H = new QLabel(Tab_Advanced);
        Label_H->setObjectName(QString::fromUtf8("Label_H"));
        Label_H->setEnabled(false);

        horizontalLayout_4->addWidget(Label_H);

        SB_InitGM_Height = new QSpinBox(Tab_Advanced);
        SB_InitGM_Height->setObjectName(QString::fromUtf8("SB_InitGM_Height"));
        SB_InitGM_Height->setEnabled(false);
        SB_InitGM_Height->setMinimum(480);
        SB_InitGM_Height->setMaximum(1200);
        SB_InitGM_Height->setValue(600);

        horizontalLayout_4->addWidget(SB_InitGM_Height);

        horizontalSpacer_2 = new QSpacerItem(13, 17, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        Label_Depth = new QLabel(Tab_Advanced);
        Label_Depth->setObjectName(QString::fromUtf8("Label_Depth"));
        Label_Depth->setEnabled(false);

        horizontalLayout_4->addWidget(Label_Depth);

        CB_InitGM_Depth = new QComboBox(Tab_Advanced);
        CB_InitGM_Depth->addItem(QString());
        CB_InitGM_Depth->addItem(QString());
        CB_InitGM_Depth->addItem(QString());
        CB_InitGM_Depth->addItem(QString());
        CB_InitGM_Depth->setObjectName(QString::fromUtf8("CB_InitGM_Depth"));
        CB_InitGM_Depth->setEnabled(false);

        horizontalLayout_4->addWidget(CB_InitGM_Depth);


        gridLayout9999->addLayout(horizontalLayout_4, 10, 0, 1, 4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(4);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        Label_Use_KVM = new QLabel(Tab_Advanced);
        Label_Use_KVM->setObjectName(QString::fromUtf8("Label_Use_KVM"));
        sizePolicy1.setHeightForWidth(Label_Use_KVM->sizePolicy().hasHeightForWidth());
        Label_Use_KVM->setSizePolicy(sizePolicy1);

        horizontalLayout_3->addWidget(Label_Use_KVM);

        line_6 = new QFrame(Tab_Advanced);
        line_6->setObjectName(QString::fromUtf8("line_6"));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);

        horizontalLayout_3->addWidget(line_6);


        gridLayout9999->addLayout(horizontalLayout_3, 11, 0, 1, 4);

        CH_No_KVM_IRQChip = new QCheckBox(Tab_Advanced);
        CH_No_KVM_IRQChip->setObjectName(QString::fromUtf8("CH_No_KVM_IRQChip"));

        gridLayout9999->addWidget(CH_No_KVM_IRQChip, 12, 0, 1, 4);

        CH_No_KVM_Pit = new QCheckBox(Tab_Advanced);
        CH_No_KVM_Pit->setObjectName(QString::fromUtf8("CH_No_KVM_Pit"));

        gridLayout9999->addWidget(CH_No_KVM_Pit, 13, 0, 1, 4);

        CH_KVM_Shadow_Memory = new QCheckBox(Tab_Advanced);
        CH_KVM_Shadow_Memory->setObjectName(QString::fromUtf8("CH_KVM_Shadow_Memory"));

        gridLayout9999->addWidget(CH_KVM_Shadow_Memory, 14, 0, 1, 1);

        SB_KVM_Shadow_Memory_Size = new QSpinBox(Tab_Advanced);
        SB_KVM_Shadow_Memory_Size->setObjectName(QString::fromUtf8("SB_KVM_Shadow_Memory_Size"));
        SB_KVM_Shadow_Memory_Size->setEnabled(false);
        SB_KVM_Shadow_Memory_Size->setMinimum(1);
        SB_KVM_Shadow_Memory_Size->setMaximum(2048);

        gridLayout9999->addWidget(SB_KVM_Shadow_Memory_Size, 14, 1, 1, 1);

        Label_KVM_Shadow_Memory_Mb = new QLabel(Tab_Advanced);
        Label_KVM_Shadow_Memory_Mb->setObjectName(QString::fromUtf8("Label_KVM_Shadow_Memory_Mb"));
        Label_KVM_Shadow_Memory_Mb->setEnabled(false);
        sizePolicy1.setHeightForWidth(Label_KVM_Shadow_Memory_Mb->sizePolicy().hasHeightForWidth());
        Label_KVM_Shadow_Memory_Mb->setSizePolicy(sizePolicy1);

        gridLayout9999->addWidget(Label_KVM_Shadow_Memory_Mb, 14, 2, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(235, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout9999->addItem(horizontalSpacer_5, 14, 3, 1, 1);

        Tabs->addTab(Tab_Advanced, QString());
        Tab_Other = new QWidget();
        Tab_Other->setObjectName(QString::fromUtf8("Tab_Other"));
        gridLayout26 = new QGridLayout(Tab_Other);
        gridLayout26->setSpacing(6);
        gridLayout26->setContentsMargins(9, 9, 9, 9);
        gridLayout26->setObjectName(QString::fromUtf8("gridLayout26"));
        Tabs_Other = new QTabWidget(Tab_Other);
        Tabs_Other->setObjectName(QString::fromUtf8("Tabs_Other"));
        Tab_VNC = new QWidget();
        Tab_VNC->setObjectName(QString::fromUtf8("Tab_VNC"));
        gridLayout_3 = new QGridLayout(Tab_VNC);
        gridLayout_3->setSpacing(4);
        gridLayout_3->setContentsMargins(6, 6, 6, 6);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        CH_Activate_VNC = new QCheckBox(Tab_VNC);
        CH_Activate_VNC->setObjectName(QString::fromUtf8("CH_Activate_VNC"));

        gridLayout_3->addWidget(CH_Activate_VNC, 0, 0, 1, 1);

        VNC_Panel = new QWidget(Tab_VNC);
        VNC_Panel->setObjectName(QString::fromUtf8("VNC_Panel"));
        VNC_Panel->setEnabled(false);
        gridLayout27 = new QGridLayout(VNC_Panel);
        gridLayout27->setSpacing(0);
        gridLayout27->setContentsMargins(0, 0, 0, 0);
        gridLayout27->setObjectName(QString::fromUtf8("gridLayout27"));
        vboxLayout8 = new QVBoxLayout();
        vboxLayout8->setSpacing(6);
        vboxLayout8->setContentsMargins(0, 0, 0, 0);
        vboxLayout8->setObjectName(QString::fromUtf8("vboxLayout8"));
        gridLayout28 = new QGridLayout();
        gridLayout28->setSpacing(6);
        gridLayout28->setContentsMargins(0, 0, 0, 0);
        gridLayout28->setObjectName(QString::fromUtf8("gridLayout28"));
        line = new QFrame(VNC_Panel);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout28->addWidget(line, 5, 0, 1, 3);

        SB_VNC_Display = new QSpinBox(VNC_Panel);
        SB_VNC_Display->setObjectName(QString::fromUtf8("SB_VNC_Display"));
        SB_VNC_Display->setMinimum(1);
        SB_VNC_Display->setMaximum(1024);
        SB_VNC_Display->setValue(1);

        gridLayout28->addWidget(SB_VNC_Display, 1, 1, 1, 2);

        Edit_VNC_Unix_Socket = new QLineEdit(VNC_Panel);
        Edit_VNC_Unix_Socket->setObjectName(QString::fromUtf8("Edit_VNC_Unix_Socket"));
        Edit_VNC_Unix_Socket->setEnabled(false);

        gridLayout28->addWidget(Edit_VNC_Unix_Socket, 2, 1, 1, 1);

        RB_VNC_Unix_Socket = new QRadioButton(VNC_Panel);
        RB_VNC_Unix_Socket->setObjectName(QString::fromUtf8("RB_VNC_Unix_Socket"));

        gridLayout28->addWidget(RB_VNC_Unix_Socket, 2, 0, 1, 1);

        CH_VNC_Password = new QCheckBox(VNC_Panel);
        CH_VNC_Password->setObjectName(QString::fromUtf8("CH_VNC_Password"));

        gridLayout28->addWidget(CH_VNC_Password, 4, 0, 1, 2);

        TB_VNC_Unix_Socket_Browse = new QToolButton(VNC_Panel);
        TB_VNC_Unix_Socket_Browse->setObjectName(QString::fromUtf8("TB_VNC_Unix_Socket_Browse"));
        TB_VNC_Unix_Socket_Browse->setEnabled(false);

        gridLayout28->addWidget(TB_VNC_Unix_Socket_Browse, 2, 2, 1, 1);

        line_3 = new QFrame(VNC_Panel);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        gridLayout28->addWidget(line_3, 0, 0, 1, 3);

        CH_Use_VNC_TLS = new QCheckBox(VNC_Panel);
        CH_Use_VNC_TLS->setObjectName(QString::fromUtf8("CH_Use_VNC_TLS"));

        gridLayout28->addWidget(CH_Use_VNC_TLS, 6, 0, 1, 1);

        RB_VNC_Display_Number = new QRadioButton(VNC_Panel);
        RB_VNC_Display_Number->setObjectName(QString::fromUtf8("RB_VNC_Display_Number"));
        RB_VNC_Display_Number->setChecked(true);

        gridLayout28->addWidget(RB_VNC_Display_Number, 1, 0, 1, 1);

        line_2 = new QFrame(VNC_Panel);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout28->addWidget(line_2, 3, 0, 1, 3);


        vboxLayout8->addLayout(gridLayout28);

        VNC_TLS_Panel = new QWidget(VNC_Panel);
        VNC_TLS_Panel->setObjectName(QString::fromUtf8("VNC_TLS_Panel"));
        VNC_TLS_Panel->setEnabled(false);
        gridLayout29 = new QGridLayout(VNC_TLS_Panel);
        gridLayout29->setSpacing(0);
        gridLayout29->setContentsMargins(0, 0, 0, 0);
        gridLayout29->setObjectName(QString::fromUtf8("gridLayout29"));
        gridLayout30 = new QGridLayout();
        gridLayout30->setSpacing(6);
        gridLayout30->setContentsMargins(0, 0, 0, 0);
        gridLayout30->setObjectName(QString::fromUtf8("gridLayout30"));
        TB_x509verify_Browse = new QToolButton(VNC_TLS_Panel);
        TB_x509verify_Browse->setObjectName(QString::fromUtf8("TB_x509verify_Browse"));
        TB_x509verify_Browse->setEnabled(false);

        gridLayout30->addWidget(TB_x509verify_Browse, 3, 1, 1, 1);

        Edit_x509verify_Folder = new QLineEdit(VNC_TLS_Panel);
        Edit_x509verify_Folder->setObjectName(QString::fromUtf8("Edit_x509verify_Folder"));
        Edit_x509verify_Folder->setEnabled(false);

        gridLayout30->addWidget(Edit_x509verify_Folder, 3, 0, 1, 1);

        Edit_x509_Folder = new QLineEdit(VNC_TLS_Panel);
        Edit_x509_Folder->setObjectName(QString::fromUtf8("Edit_x509_Folder"));
        Edit_x509_Folder->setEnabled(false);

        gridLayout30->addWidget(Edit_x509_Folder, 1, 0, 1, 1);

        TB_x509_Browse = new QToolButton(VNC_TLS_Panel);
        TB_x509_Browse->setObjectName(QString::fromUtf8("TB_x509_Browse"));
        TB_x509_Browse->setEnabled(false);

        gridLayout30->addWidget(TB_x509_Browse, 1, 1, 1, 1);

        CH_x509_Folder = new QCheckBox(VNC_TLS_Panel);
        CH_x509_Folder->setObjectName(QString::fromUtf8("CH_x509_Folder"));

        gridLayout30->addWidget(CH_x509_Folder, 0, 0, 1, 1);

        CH_x509verify_Folder = new QCheckBox(VNC_TLS_Panel);
        CH_x509verify_Folder->setObjectName(QString::fromUtf8("CH_x509verify_Folder"));

        gridLayout30->addWidget(CH_x509verify_Folder, 2, 0, 1, 1);


        gridLayout29->addLayout(gridLayout30, 0, 0, 1, 1);


        vboxLayout8->addWidget(VNC_TLS_Panel);


        gridLayout27->addLayout(vboxLayout8, 0, 0, 1, 1);


        gridLayout_3->addWidget(VNC_Panel, 1, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 27, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer, 2, 0, 1, 1);

        Tabs_Other->addTab(Tab_VNC, QString());
        Tab_Optional_Images = new QWidget();
        Tab_Optional_Images->setObjectName(QString::fromUtf8("Tab_Optional_Images"));
        gridLayout31 = new QGridLayout(Tab_Optional_Images);
        gridLayout31->setSpacing(6);
        gridLayout31->setContentsMargins(9, 9, 9, 9);
        gridLayout31->setObjectName(QString::fromUtf8("gridLayout31"));
        gridLayout32 = new QGridLayout();
        gridLayout32->setSpacing(6);
        gridLayout32->setContentsMargins(0, 0, 0, 0);
        gridLayout32->setObjectName(QString::fromUtf8("gridLayout32"));
        Edit_PFlash_File = new QLineEdit(Tab_Optional_Images);
        Edit_PFlash_File->setObjectName(QString::fromUtf8("Edit_PFlash_File"));
        Edit_PFlash_File->setEnabled(false);

        gridLayout32->addWidget(Edit_PFlash_File, 7, 0, 1, 1);

        TB_SD_Image_File_Browse = new QToolButton(Tab_Optional_Images);
        TB_SD_Image_File_Browse->setObjectName(QString::fromUtf8("TB_SD_Image_File_Browse"));
        TB_SD_Image_File_Browse->setEnabled(false);

        gridLayout32->addWidget(TB_SD_Image_File_Browse, 5, 1, 1, 1);

        CH_PFlash = new QCheckBox(Tab_Optional_Images);
        CH_PFlash->setObjectName(QString::fromUtf8("CH_PFlash"));

        gridLayout32->addWidget(CH_PFlash, 6, 0, 1, 1);

        TB_ROM_File_Browse = new QToolButton(Tab_Optional_Images);
        TB_ROM_File_Browse->setObjectName(QString::fromUtf8("TB_ROM_File_Browse"));
        TB_ROM_File_Browse->setEnabled(false);

        gridLayout32->addWidget(TB_ROM_File_Browse, 1, 1, 1, 1);

        CH_ROM_File = new QCheckBox(Tab_Optional_Images);
        CH_ROM_File->setObjectName(QString::fromUtf8("CH_ROM_File"));

        gridLayout32->addWidget(CH_ROM_File, 0, 0, 1, 1);

        CH_MTDBlock = new QCheckBox(Tab_Optional_Images);
        CH_MTDBlock->setObjectName(QString::fromUtf8("CH_MTDBlock"));

        gridLayout32->addWidget(CH_MTDBlock, 2, 0, 1, 1);

        TB_MTDBlock_File_Browse = new QToolButton(Tab_Optional_Images);
        TB_MTDBlock_File_Browse->setObjectName(QString::fromUtf8("TB_MTDBlock_File_Browse"));
        TB_MTDBlock_File_Browse->setEnabled(false);

        gridLayout32->addWidget(TB_MTDBlock_File_Browse, 3, 1, 1, 1);

        Edit_SD_Image_File = new QLineEdit(Tab_Optional_Images);
        Edit_SD_Image_File->setObjectName(QString::fromUtf8("Edit_SD_Image_File"));
        Edit_SD_Image_File->setEnabled(false);

        gridLayout32->addWidget(Edit_SD_Image_File, 5, 0, 1, 1);

        Edit_ROM_File = new QLineEdit(Tab_Optional_Images);
        Edit_ROM_File->setObjectName(QString::fromUtf8("Edit_ROM_File"));
        Edit_ROM_File->setEnabled(false);

        gridLayout32->addWidget(Edit_ROM_File, 1, 0, 1, 1);

        Edit_MTDBlock_File = new QLineEdit(Tab_Optional_Images);
        Edit_MTDBlock_File->setObjectName(QString::fromUtf8("Edit_MTDBlock_File"));
        Edit_MTDBlock_File->setEnabled(false);

        gridLayout32->addWidget(Edit_MTDBlock_File, 3, 0, 1, 1);

        CH_SD_Image = new QCheckBox(Tab_Optional_Images);
        CH_SD_Image->setObjectName(QString::fromUtf8("CH_SD_Image"));

        gridLayout32->addWidget(CH_SD_Image, 4, 0, 1, 1);

        TB_PFlash_File_Browse = new QToolButton(Tab_Optional_Images);
        TB_PFlash_File_Browse->setObjectName(QString::fromUtf8("TB_PFlash_File_Browse"));
        TB_PFlash_File_Browse->setEnabled(false);

        gridLayout32->addWidget(TB_PFlash_File_Browse, 7, 1, 1, 1);


        gridLayout31->addLayout(gridLayout32, 0, 0, 1, 1);

        spacerItem18 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout31->addItem(spacerItem18, 1, 0, 1, 1);

        Tabs_Other->addTab(Tab_Optional_Images, QString());
        Tab_Boot_Linux = new QWidget();
        Tab_Boot_Linux->setObjectName(QString::fromUtf8("Tab_Boot_Linux"));
        gridLayout33 = new QGridLayout(Tab_Boot_Linux);
        gridLayout33->setSpacing(6);
        gridLayout33->setContentsMargins(9, 9, 9, 9);
        gridLayout33->setObjectName(QString::fromUtf8("gridLayout33"));
        spacerItem19 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout33->addItem(spacerItem19, 7, 0, 1, 1);

        CH_Use_Linux_Boot = new QCheckBox(Tab_Boot_Linux);
        CH_Use_Linux_Boot->setObjectName(QString::fromUtf8("CH_Use_Linux_Boot"));

        gridLayout33->addWidget(CH_Use_Linux_Boot, 0, 0, 1, 1);

        TB_Linux_bzImage_SetPath = new QToolButton(Tab_Boot_Linux);
        TB_Linux_bzImage_SetPath->setObjectName(QString::fromUtf8("TB_Linux_bzImage_SetPath"));
        TB_Linux_bzImage_SetPath->setEnabled(false);

        gridLayout33->addWidget(TB_Linux_bzImage_SetPath, 2, 1, 1, 1);

        TB_Linux_Initrd_SetPath = new QToolButton(Tab_Boot_Linux);
        TB_Linux_Initrd_SetPath->setObjectName(QString::fromUtf8("TB_Linux_Initrd_SetPath"));
        TB_Linux_Initrd_SetPath->setEnabled(false);

        gridLayout33->addWidget(TB_Linux_Initrd_SetPath, 4, 1, 1, 1);

        spacerItem20 = new QSpacerItem(33, 26, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout33->addItem(spacerItem20, 6, 1, 1, 1);

        Edit_Linux_bzImage_Path = new QLineEdit(Tab_Boot_Linux);
        Edit_Linux_bzImage_Path->setObjectName(QString::fromUtf8("Edit_Linux_bzImage_Path"));
        Edit_Linux_bzImage_Path->setEnabled(false);

        gridLayout33->addWidget(Edit_Linux_bzImage_Path, 2, 0, 1, 1);

        Edit_Linux_Initrd_Path = new QLineEdit(Tab_Boot_Linux);
        Edit_Linux_Initrd_Path->setObjectName(QString::fromUtf8("Edit_Linux_Initrd_Path"));
        Edit_Linux_Initrd_Path->setEnabled(false);

        gridLayout33->addWidget(Edit_Linux_Initrd_Path, 4, 0, 1, 1);

        Edit_Linux_Command_Line = new QLineEdit(Tab_Boot_Linux);
        Edit_Linux_Command_Line->setObjectName(QString::fromUtf8("Edit_Linux_Command_Line"));
        Edit_Linux_Command_Line->setEnabled(false);

        gridLayout33->addWidget(Edit_Linux_Command_Line, 6, 0, 1, 1);

        Label_KernelCom = new QLabel(Tab_Boot_Linux);
        Label_KernelCom->setObjectName(QString::fromUtf8("Label_KernelCom"));
        Label_KernelCom->setEnabled(false);

        gridLayout33->addWidget(Label_KernelCom, 5, 0, 1, 1);

        Label_InitRD = new QLabel(Tab_Boot_Linux);
        Label_InitRD->setObjectName(QString::fromUtf8("Label_InitRD"));
        Label_InitRD->setEnabled(false);

        gridLayout33->addWidget(Label_InitRD, 3, 0, 1, 1);

        Label_bzImage = new QLabel(Tab_Boot_Linux);
        Label_bzImage->setObjectName(QString::fromUtf8("Label_bzImage"));
        Label_bzImage->setEnabled(false);

        gridLayout33->addWidget(Label_bzImage, 1, 0, 1, 1);

        Tabs_Other->addTab(Tab_Boot_Linux, QString());

        gridLayout26->addWidget(Tabs_Other, 0, 0, 1, 1);

        gridLayout34 = new QGridLayout();
        gridLayout34->setSpacing(3);
        gridLayout34->setContentsMargins(0, 0, 0, 0);
        gridLayout34->setObjectName(QString::fromUtf8("gridLayout34"));
        Label_Additional_QEMU_Args = new QLabel(Tab_Other);
        Label_Additional_QEMU_Args->setObjectName(QString::fromUtf8("Label_Additional_QEMU_Args"));

        gridLayout34->addWidget(Label_Additional_QEMU_Args, 1, 0, 1, 1);

        CH_Use_GDB = new QCheckBox(Tab_Other);
        CH_Use_GDB->setObjectName(QString::fromUtf8("CH_Use_GDB"));

        gridLayout34->addWidget(CH_Use_GDB, 0, 0, 1, 1);

        Edit_Additional_Args = new QLineEdit(Tab_Other);
        Edit_Additional_Args->setObjectName(QString::fromUtf8("Edit_Additional_Args"));
        QSizePolicy sizePolicy8(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy8.setHorizontalStretch(0);
        sizePolicy8.setVerticalStretch(0);
        sizePolicy8.setHeightForWidth(Edit_Additional_Args->sizePolicy().hasHeightForWidth());
        Edit_Additional_Args->setSizePolicy(sizePolicy8);
        Edit_Additional_Args->setMaxLength(2048);

        gridLayout34->addWidget(Edit_Additional_Args, 1, 1, 1, 1);

        SB_GDB_Port = new QSpinBox(Tab_Other);
        SB_GDB_Port->setObjectName(QString::fromUtf8("SB_GDB_Port"));
        SB_GDB_Port->setEnabled(false);
        SB_GDB_Port->setMinimum(1);
        SB_GDB_Port->setMaximum(65536);
        SB_GDB_Port->setValue(1234);

        gridLayout34->addWidget(SB_GDB_Port, 0, 1, 1, 1);


        gridLayout26->addLayout(gridLayout34, 1, 0, 1, 1);

        Tabs->addTab(Tab_Other, QString());

        verticalLayout->addWidget(Tabs);

        hboxLayout7 = new QHBoxLayout();
        hboxLayout7->setSpacing(6);
        hboxLayout7->setContentsMargins(0, 0, 0, 0);
        hboxLayout7->setObjectName(QString::fromUtf8("hboxLayout7"));
        spacerItem21 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout7->addItem(spacerItem21);

        Button_Apply = new QPushButton(centralwidget);
        Button_Apply->setObjectName(QString::fromUtf8("Button_Apply"));

        hboxLayout7->addWidget(Button_Apply);

        Button_Cancel = new QPushButton(centralwidget);
        Button_Cancel->setObjectName(QString::fromUtf8("Button_Cancel"));

        hboxLayout7->addWidget(Button_Cancel);


        verticalLayout->addLayout(hboxLayout7);


        gridLayout_4->addLayout(verticalLayout, 0, 1, 1, 1);

        Main_Window->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Main_Window);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 731, 28));
        menuVM = new QMenu(menubar);
        menuVM->setObjectName(QString::fromUtf8("menuVM"));
        menuNew_VM = new QMenu(menuVM);
        menuNew_VM->setObjectName(QString::fromUtf8("menuNew_VM"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        Main_Window->setMenuBar(menubar);
        Status_Bar = new QStatusBar(Main_Window);
        Status_Bar->setObjectName(QString::fromUtf8("Status_Bar"));
        Main_Window->setStatusBar(Status_Bar);
        Tool_Bar_VM_Manage = new QToolBar(Main_Window);
        Tool_Bar_VM_Manage->setObjectName(QString::fromUtf8("Tool_Bar_VM_Manage"));
        Tool_Bar_VM_Manage->setOrientation(Qt::Horizontal);
        Main_Window->addToolBar(Qt::TopToolBarArea, Tool_Bar_VM_Manage);
        Tool_Bar_VM_Control = new QToolBar(Main_Window);
        Tool_Bar_VM_Control->setObjectName(QString::fromUtf8("Tool_Bar_VM_Control"));
        Tool_Bar_VM_Control->setOrientation(Qt::Horizontal);
        Main_Window->addToolBar(Qt::TopToolBarArea, Tool_Bar_VM_Control);
#ifndef QT_NO_SHORTCUT
        Label_Machine_Name->setBuddy(Edit_Machine_Name);
        Label_CPU_Type->setBuddy(CB_CPU_Type);
        Label_Acseleration->setBuddy(CB_Acseleration);
        Label_CPU_Count->setBuddy(CB_CPU_Count);
        Label_Video_Card->setBuddy(CB_Video_Card);
        Label_Boot_Prioritet->setBuddy(CB_Boot_Prioritet);
        Label_Keyboard_Layout->setBuddy(CB_Keyboard_Layout);
        Label_Machine_Type->setBuddy(CB_Machine_Type);
        Label_Connection_Mode->setBuddy(CB_Connection_Mode);
        Label_IP->setBuddy(Edit_IP_Address);
        Label_MAC->setBuddy(Edit_MAC_Address);
        Label_Port->setBuddy(SB_Redir_Port);
        Label_VLAN->setBuddy(SB_VLAN);
        Label_File_Descriptor->setBuddy(SB_File_Descriptor);
        Label_If_Name->setBuddy(Edit_Interface_Name);
        Label_Port1->setBuddy(SB_Redir_Port);
        Label_To_Guest_IP->setBuddy(Edit_Guest_IP);
        Label_Port2->setBuddy(SB_Guest_Port);
        Label_SMB_Folder->setBuddy(Edit_SMB_Folder);
        Label_TFTP->setBuddy(Edit_TFTP_Prefix);
        Label_KernelCom->setBuddy(Edit_Linux_Command_Line);
        Label_InitRD->setBuddy(Edit_Linux_Initrd_Path);
        Label_bzImage->setBuddy(Edit_Linux_bzImage_Path);
        Label_Additional_QEMU_Args->setBuddy(Edit_Additional_Args);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(Machines_List, Tabs);
        QWidget::setTabOrder(Tabs, VM_Information_Text);
        QWidget::setTabOrder(VM_Information_Text, Button_Apply);
        QWidget::setTabOrder(Button_Apply, Button_Cancel);
        QWidget::setTabOrder(Button_Cancel, Edit_Machine_Name);
        QWidget::setTabOrder(Edit_Machine_Name, CB_Computer_Type);
        QWidget::setTabOrder(CB_Computer_Type, CB_CPU_Type);
        QWidget::setTabOrder(CB_CPU_Type, CB_CPU_Count);
        QWidget::setTabOrder(CB_CPU_Count, CB_Acseleration);
        QWidget::setTabOrder(CB_Acseleration, CB_Machine_Type);
        QWidget::setTabOrder(CB_Machine_Type, CB_Boot_Prioritet);
        QWidget::setTabOrder(CB_Boot_Prioritet, CB_Video_Card);
        QWidget::setTabOrder(CB_Video_Card, CB_Keyboard_Layout);
        QWidget::setTabOrder(CB_Keyboard_Layout, Memory_Size);
        QWidget::setTabOrder(Memory_Size, CB_RAM_Size);
        QWidget::setTabOrder(CB_RAM_Size, Check_Host_Mem);
        QWidget::setTabOrder(Check_Host_Mem, CH_sb16);
        QWidget::setTabOrder(CH_sb16, CH_AC97);
        QWidget::setTabOrder(CH_AC97, CH_es1370);
        QWidget::setTabOrder(CH_es1370, CH_GUS);
        QWidget::setTabOrder(CH_GUS, CH_Adlib);
        QWidget::setTabOrder(CH_Adlib, CH_PCSPK);
        QWidget::setTabOrder(CH_PCSPK, CH_Fullscreen);
        QWidget::setTabOrder(CH_Fullscreen, CH_ACPI);
        QWidget::setTabOrder(CH_ACPI, CH_Local_Time);
        QWidget::setTabOrder(CH_Local_Time, CH_Start_CPU);
        QWidget::setTabOrder(CH_Start_CPU, CH_Snapshot);
        QWidget::setTabOrder(CH_Snapshot, CH_No_Reboot);
        QWidget::setTabOrder(CH_No_Reboot, Edit_HDA_Image_Path);
        QWidget::setTabOrder(Edit_HDA_Image_Path, TB_HDA_SetPath);
        QWidget::setTabOrder(TB_HDA_SetPath, TB_HDA_Create_HDD);
        QWidget::setTabOrder(TB_HDA_Create_HDD, Edit_HDB_Image_Path);
        QWidget::setTabOrder(Edit_HDB_Image_Path, TB_HDB_SetPath);
        QWidget::setTabOrder(TB_HDB_SetPath, TB_HDB_Create_HDD);
        QWidget::setTabOrder(TB_HDB_Create_HDD, Edit_HDC_Image_Path);
        QWidget::setTabOrder(Edit_HDC_Image_Path, TB_HDC_SetPath);
        QWidget::setTabOrder(TB_HDC_SetPath, TB_HDC_Create_HDD);
        QWidget::setTabOrder(TB_HDC_Create_HDD, Edit_HDD_Image_Path);
        QWidget::setTabOrder(Edit_HDD_Image_Path, TB_HDD_SetPath);
        QWidget::setTabOrder(TB_HDD_SetPath, TB_HDD_Create_HDD);
        QWidget::setTabOrder(TB_HDD_Create_HDD, RB_CDROM_Use_Host_Device);
        QWidget::setTabOrder(RB_CDROM_Use_Host_Device, CB_CDROM_Host_Devices);
        QWidget::setTabOrder(CB_CDROM_Host_Devices, RB_CDROM_Use_Image_File);
        QWidget::setTabOrder(RB_CDROM_Use_Image_File, Edit_CDROM_Image_File_Path);
        QWidget::setTabOrder(Edit_CDROM_Image_File_Path, TB_CDROM_SetPath);
        QWidget::setTabOrder(TB_CDROM_SetPath, RB_FD0_Use_Host_Device);
        QWidget::setTabOrder(RB_FD0_Use_Host_Device, CB_FD0_Host_Devices);
        QWidget::setTabOrder(CB_FD0_Host_Devices, RB_FD0_Use_Image_File);
        QWidget::setTabOrder(RB_FD0_Use_Image_File, Edit_FD0_Image_File_Path);
        QWidget::setTabOrder(Edit_FD0_Image_File_Path, TB_FD0_SetPath);
        QWidget::setTabOrder(TB_FD0_SetPath, RB_FD1_Use_Host_Device);
        QWidget::setTabOrder(RB_FD1_Use_Host_Device, CB_FD1_Host_Devices);
        QWidget::setTabOrder(CB_FD1_Host_Devices, RB_FD1_Use_Image_File);
        QWidget::setTabOrder(RB_FD1_Use_Image_File, Edit_FD1_Image_File_Path);
        QWidget::setTabOrder(Edit_FD1_Image_File_Path, TB_FD1_SetPath);
        QWidget::setTabOrder(TB_FD1_SetPath, CH_Use_Network);
        QWidget::setTabOrder(CH_Use_Network, Network_Cards_Tabs);
        QWidget::setTabOrder(Network_Cards_Tabs, Network_Cards_List);
        QWidget::setTabOrder(Network_Cards_List, Button_Add_Net_Card);
        QWidget::setTabOrder(Button_Add_Net_Card, Button_Delete_Net_Card);
        QWidget::setTabOrder(Button_Delete_Net_Card, CB_Network_Card_Model);
        QWidget::setTabOrder(CB_Network_Card_Model, CB_Connection_Mode);
        QWidget::setTabOrder(CB_Connection_Mode, Edit_Hostname);
        QWidget::setTabOrder(Edit_Hostname, Edit_IP_Address);
        QWidget::setTabOrder(Edit_IP_Address, Edit_MAC_Address);
        QWidget::setTabOrder(Edit_MAC_Address, TB_Generate_New_MAC);
        QWidget::setTabOrder(TB_Generate_New_MAC, SB_File_Descriptor);
        QWidget::setTabOrder(SB_File_Descriptor, SB_Port);
        QWidget::setTabOrder(SB_Port, SB_VLAN);
        QWidget::setTabOrder(SB_VLAN, CH_TUN_TAP_Script);
        QWidget::setTabOrder(CH_TUN_TAP_Script, Edit_TUN_TAP_Script);
        QWidget::setTabOrder(Edit_TUN_TAP_Script, TB_Browse_TUN_Script);
        QWidget::setTabOrder(TB_Browse_TUN_Script, Edit_Interface_Name);
        QWidget::setTabOrder(Edit_Interface_Name, Redirections_List);
        QWidget::setTabOrder(Redirections_List, Button_Add_Redirections);
        QWidget::setTabOrder(Button_Add_Redirections, Button_Delete_Redirections);
        QWidget::setTabOrder(Button_Delete_Redirections, Button_Apply_Redirections);
        QWidget::setTabOrder(Button_Apply_Redirections, Button_Clear_Redirections);
        QWidget::setTabOrder(Button_Clear_Redirections, RB_TCP);
        QWidget::setTabOrder(RB_TCP, RB_UDP);
        QWidget::setTabOrder(RB_UDP, SB_Redir_Port);
        QWidget::setTabOrder(SB_Redir_Port, Edit_Guest_IP);
        QWidget::setTabOrder(Edit_Guest_IP, SB_Guest_Port);
        QWidget::setTabOrder(SB_Guest_Port, Edit_TFTP_Prefix);
        QWidget::setTabOrder(Edit_TFTP_Prefix, Edit_SMB_Folder);
        QWidget::setTabOrder(Edit_SMB_Folder, TB_Browse_SMB);
        QWidget::setTabOrder(TB_Browse_SMB, SB_InitGM_Width);
        QWidget::setTabOrder(SB_InitGM_Width, SB_InitGM_Height);
        QWidget::setTabOrder(SB_InitGM_Height, CB_InitGM_Depth);
        QWidget::setTabOrder(CB_InitGM_Depth, CH_No_Frame);
        QWidget::setTabOrder(CH_No_Frame, CH_Alt_Grab);
        QWidget::setTabOrder(CH_Alt_Grab, CH_No_Quit);
        QWidget::setTabOrder(CH_No_Quit, CH_Portrait);
        QWidget::setTabOrder(CH_Portrait, Tabs_Other);
        QWidget::setTabOrder(Tabs_Other, CH_Activate_VNC);
        QWidget::setTabOrder(CH_Activate_VNC, RB_VNC_Display_Number);
        QWidget::setTabOrder(RB_VNC_Display_Number, SB_VNC_Display);
        QWidget::setTabOrder(SB_VNC_Display, RB_VNC_Unix_Socket);
        QWidget::setTabOrder(RB_VNC_Unix_Socket, Edit_VNC_Unix_Socket);
        QWidget::setTabOrder(Edit_VNC_Unix_Socket, TB_VNC_Unix_Socket_Browse);
        QWidget::setTabOrder(TB_VNC_Unix_Socket_Browse, CH_VNC_Password);
        QWidget::setTabOrder(CH_VNC_Password, CH_Use_VNC_TLS);
        QWidget::setTabOrder(CH_Use_VNC_TLS, CH_x509_Folder);
        QWidget::setTabOrder(CH_x509_Folder, Edit_x509_Folder);
        QWidget::setTabOrder(Edit_x509_Folder, TB_x509_Browse);
        QWidget::setTabOrder(TB_x509_Browse, CH_x509verify_Folder);
        QWidget::setTabOrder(CH_x509verify_Folder, Edit_x509verify_Folder);
        QWidget::setTabOrder(Edit_x509verify_Folder, TB_x509verify_Browse);
        QWidget::setTabOrder(TB_x509verify_Browse, TB_Linux_Initrd_SetPath);
        QWidget::setTabOrder(TB_Linux_Initrd_SetPath, Edit_Linux_bzImage_Path);
        QWidget::setTabOrder(Edit_Linux_bzImage_Path, TB_Linux_bzImage_SetPath);
        QWidget::setTabOrder(TB_Linux_bzImage_SetPath, CH_ROM_File);
        QWidget::setTabOrder(CH_ROM_File, Edit_ROM_File);
        QWidget::setTabOrder(Edit_ROM_File, TB_ROM_File_Browse);
        QWidget::setTabOrder(TB_ROM_File_Browse, CH_MTDBlock);
        QWidget::setTabOrder(CH_MTDBlock, Edit_MTDBlock_File);
        QWidget::setTabOrder(Edit_MTDBlock_File, TB_MTDBlock_File_Browse);
        QWidget::setTabOrder(TB_MTDBlock_File_Browse, CH_SD_Image);
        QWidget::setTabOrder(CH_SD_Image, Edit_SD_Image_File);
        QWidget::setTabOrder(Edit_SD_Image_File, TB_SD_Image_File_Browse);
        QWidget::setTabOrder(TB_SD_Image_File_Browse, CH_PFlash);
        QWidget::setTabOrder(CH_PFlash, Edit_PFlash_File);
        QWidget::setTabOrder(Edit_PFlash_File, TB_PFlash_File_Browse);
        QWidget::setTabOrder(TB_PFlash_File_Browse, CH_Use_GDB);
        QWidget::setTabOrder(CH_Use_GDB, SB_GDB_Port);
        QWidget::setTabOrder(SB_GDB_Port, Edit_Additional_Args);
        QWidget::setTabOrder(Edit_Additional_Args, CH_Use_Linux_Boot);
        QWidget::setTabOrder(CH_Use_Linux_Boot, Edit_Linux_Command_Line);
        QWidget::setTabOrder(Edit_Linux_Command_Line, Edit_Linux_Initrd_Path);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuVM->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuVM->addAction(menuNew_VM->menuAction());
        menuVM->addAction(actionDelete_Virtual_Machine);
        menuVM->addAction(actionSave_As_Template);
        menuVM->addAction(actionCopy);
        menuVM->addSeparator();
        menuVM->addAction(action_Power_On);
        menuVM->addAction(actionSave);
        menuVM->addAction(actionPause);
        menuVM->addAction(actionPower_Off);
        menuVM->addAction(actionReset);
        menuVM->addSeparator();
        menuVM->addAction(actionManage_Snapshots);
        menuVM->addAction(actionShow_Emulator_Control);
        menuVM->addAction(actionShow_QEMU_Arguments);
        menuNew_VM->addAction(actionCreate);
        menuNew_VM->addAction(actionWizard);
        menuNew_VM->addSeparator();
        menuNew_VM->addAction(actionLoad_VM_From_File);
        menuHelp->addAction(actionAbout);
        menuHelp->addAction(actionAbout_Qt);
        menuFile->addAction(actionCreate_HDD_Image);
        menuFile->addAction(actionConvert_HDD_Image);
        menuFile->addAction(actionAQEMU_Settings);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        Tool_Bar_VM_Manage->addAction(actionCreate);
        Tool_Bar_VM_Manage->addAction(actionDelete_Virtual_Machine);
        Tool_Bar_VM_Manage->addAction(actionWizard);
        Tool_Bar_VM_Manage->addAction(actionCreate_HDD_Image);
        Tool_Bar_VM_Control->addAction(action_Power_On);
        Tool_Bar_VM_Control->addAction(actionSave);
        Tool_Bar_VM_Control->addAction(actionPause);
        Tool_Bar_VM_Control->addAction(actionPower_Off);
        Tool_Bar_VM_Control->addAction(actionReset);

        retranslateUi(Main_Window);
        QObject::connect(CH_ROM_File, SIGNAL(toggled(bool)), Edit_ROM_File, SLOT(setEnabled(bool)));
        QObject::connect(CH_Use_GDB, SIGNAL(toggled(bool)), SB_GDB_Port, SLOT(setEnabled(bool)));
        QObject::connect(CH_ROM_File, SIGNAL(toggled(bool)), TB_ROM_File_Browse, SLOT(setEnabled(bool)));
        QObject::connect(CH_MTDBlock, SIGNAL(toggled(bool)), Edit_MTDBlock_File, SLOT(setEnabled(bool)));
        QObject::connect(CH_SD_Image, SIGNAL(toggled(bool)), Edit_SD_Image_File, SLOT(setEnabled(bool)));
        QObject::connect(CH_PFlash, SIGNAL(toggled(bool)), Edit_PFlash_File, SLOT(setEnabled(bool)));
        QObject::connect(CH_PFlash, SIGNAL(toggled(bool)), TB_PFlash_File_Browse, SLOT(setEnabled(bool)));
        QObject::connect(CH_SD_Image, SIGNAL(toggled(bool)), TB_SD_Image_File_Browse, SLOT(setEnabled(bool)));
        QObject::connect(CH_MTDBlock, SIGNAL(toggled(bool)), TB_MTDBlock_File_Browse, SLOT(setEnabled(bool)));
        QObject::connect(CH_KVM_Shadow_Memory, SIGNAL(toggled(bool)), SB_KVM_Shadow_Memory_Size, SLOT(setEnabled(bool)));
        QObject::connect(CH_KVM_Shadow_Memory, SIGNAL(toggled(bool)), Label_KVM_Shadow_Memory_Mb, SLOT(setEnabled(bool)));
        QObject::connect(CH_TUN_TAP_Script, SIGNAL(toggled(bool)), Edit_TUN_TAP_Script, SLOT(setEnabled(bool)));
        QObject::connect(CH_TUN_TAP_Script, SIGNAL(toggled(bool)), TB_Browse_TUN_Script, SLOT(setEnabled(bool)));
        QObject::connect(CH_Use_Linux_Boot, SIGNAL(toggled(bool)), Label_bzImage, SLOT(setEnabled(bool)));
        QObject::connect(CH_Use_Linux_Boot, SIGNAL(toggled(bool)), Edit_Linux_bzImage_Path, SLOT(setEnabled(bool)));
        QObject::connect(CH_Use_Linux_Boot, SIGNAL(toggled(bool)), Label_InitRD, SLOT(setEnabled(bool)));
        QObject::connect(CH_Use_Linux_Boot, SIGNAL(toggled(bool)), Edit_Linux_Initrd_Path, SLOT(setEnabled(bool)));
        QObject::connect(CH_Use_Linux_Boot, SIGNAL(toggled(bool)), Label_KernelCom, SLOT(setEnabled(bool)));
        QObject::connect(CH_Use_Linux_Boot, SIGNAL(toggled(bool)), Edit_Linux_Command_Line, SLOT(setEnabled(bool)));
        QObject::connect(CH_Use_Linux_Boot, SIGNAL(toggled(bool)), TB_Linux_bzImage_SetPath, SLOT(setEnabled(bool)));
        QObject::connect(CH_Use_Linux_Boot, SIGNAL(toggled(bool)), TB_Linux_Initrd_SetPath, SLOT(setEnabled(bool)));
        QObject::connect(RB_VNC_Display_Number, SIGNAL(toggled(bool)), SB_VNC_Display, SLOT(setEnabled(bool)));
        QObject::connect(RB_VNC_Unix_Socket, SIGNAL(toggled(bool)), Edit_VNC_Unix_Socket, SLOT(setEnabled(bool)));
        QObject::connect(RB_VNC_Unix_Socket, SIGNAL(toggled(bool)), TB_VNC_Unix_Socket_Browse, SLOT(setEnabled(bool)));
        QObject::connect(CH_x509_Folder, SIGNAL(toggled(bool)), Edit_x509_Folder, SLOT(setEnabled(bool)));
        QObject::connect(CH_x509verify_Folder, SIGNAL(toggled(bool)), Edit_x509verify_Folder, SLOT(setEnabled(bool)));
        QObject::connect(CH_x509_Folder, SIGNAL(toggled(bool)), TB_x509_Browse, SLOT(setEnabled(bool)));
        QObject::connect(CH_x509verify_Folder, SIGNAL(toggled(bool)), TB_x509verify_Browse, SLOT(setEnabled(bool)));
        QObject::connect(CH_Use_VNC_TLS, SIGNAL(toggled(bool)), VNC_TLS_Panel, SLOT(setEnabled(bool)));
        QObject::connect(CH_Activate_VNC, SIGNAL(toggled(bool)), VNC_Panel, SLOT(setEnabled(bool)));
        QObject::connect(CH_Use_Network, SIGNAL(toggled(bool)), Network_Cards_Tabs, SLOT(setEnabled(bool)));
        QObject::connect(CH_Start_Date, SIGNAL(toggled(bool)), DTE_Start_Date, SLOT(setEnabled(bool)));
        QObject::connect(CH_Init_Graphic_Mode, SIGNAL(toggled(bool)), Label_W, SLOT(setEnabled(bool)));
        QObject::connect(CH_Init_Graphic_Mode, SIGNAL(toggled(bool)), SB_InitGM_Width, SLOT(setEnabled(bool)));
        QObject::connect(CH_Init_Graphic_Mode, SIGNAL(toggled(bool)), Label_H, SLOT(setEnabled(bool)));
        QObject::connect(CH_Init_Graphic_Mode, SIGNAL(toggled(bool)), SB_InitGM_Height, SLOT(setEnabled(bool)));
        QObject::connect(CH_Init_Graphic_Mode, SIGNAL(toggled(bool)), Label_Depth, SLOT(setEnabled(bool)));
        QObject::connect(CH_Init_Graphic_Mode, SIGNAL(toggled(bool)), CB_InitGM_Depth, SLOT(setEnabled(bool)));

        Tabs->setCurrentIndex(0);
        CB_Acseleration->setCurrentIndex(0);
        CB_CPU_Type->setCurrentIndex(-1);
        CB_Computer_Type->setCurrentIndex(-1);
        CB_Boot_Prioritet->setCurrentIndex(0);
        CB_Video_Card->setCurrentIndex(-1);
        CB_RAM_Size->setCurrentIndex(6);
        Network_Cards_Tabs->setCurrentIndex(0);
        CB_Connection_Mode->setCurrentIndex(8);
        CB_InitGM_Depth->setCurrentIndex(2);
        Tabs_Other->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Main_Window);
    } // setupUi

    void retranslateUi(QMainWindow *Main_Window)
    {
        Main_Window->setWindowTitle(QApplication::translate("Main_Window", "AQEMU", nullptr));
        actionAbout->setText(QApplication::translate("Main_Window", "&About AQEMU", nullptr));
        actionAbout->setIconText(QApplication::translate("Main_Window", "About AQEMU", nullptr));
#ifndef QT_NO_TOOLTIP
        actionAbout->setToolTip(QApplication::translate("Main_Window", "About AQEMU", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionAbout->setShortcut(QApplication::translate("Main_Window", "F1", nullptr));
#endif // QT_NO_SHORTCUT
        actionAbout_Qt->setText(QApplication::translate("Main_Window", "About &Qt", nullptr));
        actionDelete_Virtual_Machine->setText(QApplication::translate("Main_Window", "&Delete Current VM", nullptr));
        actionExit->setText(QApplication::translate("Main_Window", "&Exit", nullptr));
#ifndef QT_NO_SHORTCUT
        actionExit->setShortcut(QApplication::translate("Main_Window", "Ctrl+Q", nullptr));
#endif // QT_NO_SHORTCUT
        actionWizard->setText(QApplication::translate("Main_Window", "&Wizard...", nullptr));
#ifndef QT_NO_SHORTCUT
        actionWizard->setShortcut(QApplication::translate("Main_Window", "Ctrl+W", nullptr));
#endif // QT_NO_SHORTCUT
        actionCreate->setText(QApplication::translate("Main_Window", "&Add New VM", nullptr));
#ifndef QT_NO_SHORTCUT
        actionCreate->setShortcut(QApplication::translate("Main_Window", "Ctrl+N", nullptr));
#endif // QT_NO_SHORTCUT
        actionCreate_HDD_Image->setText(QApplication::translate("Main_Window", "&Create HDD Image", nullptr));
        actionConvert_HDD_Image->setText(QApplication::translate("Main_Window", "Con&vert HDD Image", nullptr));
        actionConvert_HDD_Image->setIconText(QApplication::translate("Main_Window", "Convert HDD Image", nullptr));
#ifndef QT_NO_TOOLTIP
        actionConvert_HDD_Image->setToolTip(QApplication::translate("Main_Window", "Convert HDD Image", nullptr));
#endif // QT_NO_TOOLTIP
        actionAQEMU_Settings->setText(QApplication::translate("Main_Window", "AQEMU &Settings", nullptr));
        actionAQEMU_Settings->setIconText(QApplication::translate("Main_Window", "AQEMU &Settings", nullptr));
#ifndef QT_NO_TOOLTIP
        actionAQEMU_Settings->setToolTip(QApplication::translate("Main_Window", "AQEMU &Settings", nullptr));
#endif // QT_NO_TOOLTIP
        action_Power_On->setText(QApplication::translate("Main_Window", "&Start", nullptr));
#ifndef QT_NO_SHORTCUT
        action_Power_On->setShortcut(QApplication::translate("Main_Window", "Ctrl+S", nullptr));
#endif // QT_NO_SHORTCUT
        actionPower_Off->setText(QApplication::translate("Main_Window", "Sto&p", nullptr));
#ifndef QT_NO_SHORTCUT
        actionPower_Off->setShortcut(QApplication::translate("Main_Window", "Ctrl+D", nullptr));
#endif // QT_NO_SHORTCUT
        actionPause->setText(QApplication::translate("Main_Window", "&Pause", nullptr));
#ifndef QT_NO_SHORTCUT
        actionPause->setShortcut(QApplication::translate("Main_Window", "Ctrl+P", nullptr));
#endif // QT_NO_SHORTCUT
        actionReset->setText(QApplication::translate("Main_Window", "&Reset", nullptr));
#ifndef QT_NO_SHORTCUT
        actionReset->setShortcut(QApplication::translate("Main_Window", "Ctrl+R", nullptr));
#endif // QT_NO_SHORTCUT
        actionLoad_VM_From_File->setText(QApplication::translate("Main_Window", "&Load VM From File", nullptr));
        actionSave_As_Template->setText(QApplication::translate("Main_Window", "Save As &Template", nullptr));
        actionShow_QEMU_Arguments->setText(QApplication::translate("Main_Window", "Show QEMU &Arguments", nullptr));
        actionSave->setText(QApplication::translate("Main_Window", "Sa&ve", nullptr));
        actionChange_Icon->setText(QApplication::translate("Main_Window", "Change Icon", nullptr));
        actionCopy->setText(QApplication::translate("Main_Window", "Copy", nullptr));
        actionManage_Snapshots->setText(QApplication::translate("Main_Window", "Manage Snapshots", nullptr));
        actionShow_Emulator_Control->setText(QApplication::translate("Main_Window", "Show Emulator Control", nullptr));
        Tabs->setTabText(Tabs->indexOf(Tab_Info), QApplication::translate("Main_Window", "Info", nullptr));
        GB_Options->setTitle(QApplication::translate("Main_Window", "Options", nullptr));
        CH_Start_CPU->setText(QApplication::translate("Main_Window", "Start CP&U at Startup", nullptr));
#ifndef QT_NO_TOOLTIP
        CH_Local_Time->setToolTip(QApplication::translate("Main_Window", "Set the real time clock to local time. Default=utc", nullptr));
#endif // QT_NO_TOOLTIP
        CH_Local_Time->setText(QApplication::translate("Main_Window", "Use &Local Time", nullptr));
        CH_ACPI->setText(QApplication::translate("Main_Window", "Enable ACP&I", nullptr));
#ifndef QT_NO_TOOLTIP
        CH_Fullscreen->setToolTip(QApplication::translate("Main_Window", "Start in full screen", nullptr));
#endif // QT_NO_TOOLTIP
        CH_Fullscreen->setText(QApplication::translate("Main_Window", "&Fullscreen Mode", nullptr));
        CH_Snapshot->setText(QApplication::translate("Main_Window", "Snapshot &Mode", nullptr));
#ifndef QT_NO_TOOLTIP
        CH_No_Reboot->setToolTip(QApplication::translate("Main_Window", "Exit instead of rebooting", nullptr));
#endif // QT_NO_TOOLTIP
        CH_No_Reboot->setText(QApplication::translate("Main_Window", "No Reboot", nullptr));
        Label_Machine_Name->setText(QApplication::translate("Main_Window", "Machine &Name:", nullptr));
        CB_Acseleration->setItemText(0, QApplication::translate("Main_Window", "Enabled (default)", nullptr));
        CB_Acseleration->setItemText(1, QApplication::translate("Main_Window", "Disabled", nullptr));
        CB_Acseleration->setItemText(2, QApplication::translate("Main_Window", "Enabled", nullptr));
        CB_Acseleration->setItemText(3, QApplication::translate("Main_Window", "Full", nullptr));

        Label_CPU_Type->setText(QApplication::translate("Main_Window", "&CPU Type:", nullptr));
#ifndef QT_NO_TOOLTIP
        Label_Acseleration->setToolTip(QApplication::translate("Main_Window", "KQEMU Acceleration Kernel Module", nullptr));
#endif // QT_NO_TOOLTIP
        Label_Acseleration->setText(QApplication::translate("Main_Window", "Ac&celeration:", nullptr));
        Label_Computer_Type->setText(QApplication::translate("Main_Window", "Computer Type:", nullptr));
        Label_CPU_Count->setText(QApplication::translate("Main_Window", "Number of CP&U:", nullptr));
        CB_CPU_Count->setItemText(0, QApplication::translate("Main_Window", "1", nullptr));
        CB_CPU_Count->setItemText(1, QApplication::translate("Main_Window", "2", nullptr));
        CB_CPU_Count->setItemText(2, QApplication::translate("Main_Window", "4", nullptr));
        CB_CPU_Count->setItemText(3, QApplication::translate("Main_Window", "8", nullptr));
        CB_CPU_Count->setItemText(4, QApplication::translate("Main_Window", "16", nullptr));
        CB_CPU_Count->setItemText(5, QApplication::translate("Main_Window", "32", nullptr));
        CB_CPU_Count->setItemText(6, QApplication::translate("Main_Window", "64", nullptr));
        CB_CPU_Count->setItemText(7, QApplication::translate("Main_Window", "128", nullptr));
        CB_CPU_Count->setItemText(8, QApplication::translate("Main_Window", "255", nullptr));

        Label_Video_Card->setText(QApplication::translate("Main_Window", "&Video Card:", nullptr));
        CB_Boot_Prioritet->setItemText(0, QApplication::translate("Main_Window", "Floppy", nullptr));
        CB_Boot_Prioritet->setItemText(1, QApplication::translate("Main_Window", "HDD", nullptr));
        CB_Boot_Prioritet->setItemText(2, QApplication::translate("Main_Window", "CD-ROM", nullptr));
        CB_Boot_Prioritet->setItemText(3, QApplication::translate("Main_Window", "Network", nullptr));
        CB_Boot_Prioritet->setItemText(4, QApplication::translate("Main_Window", "None", nullptr));

        Label_Boot_Prioritet->setText(QApplication::translate("Main_Window", "B&oot Priority:", nullptr));
        CB_Keyboard_Layout->setItemText(0, QApplication::translate("Main_Window", "en-us (default)", nullptr));
        CB_Keyboard_Layout->setItemText(1, QApplication::translate("Main_Window", "ar", nullptr));
        CB_Keyboard_Layout->setItemText(2, QApplication::translate("Main_Window", "da", nullptr));
        CB_Keyboard_Layout->setItemText(3, QApplication::translate("Main_Window", "de", nullptr));
        CB_Keyboard_Layout->setItemText(4, QApplication::translate("Main_Window", "de-ch", nullptr));
        CB_Keyboard_Layout->setItemText(5, QApplication::translate("Main_Window", "en-gb", nullptr));
        CB_Keyboard_Layout->setItemText(6, QApplication::translate("Main_Window", "en-us", nullptr));
        CB_Keyboard_Layout->setItemText(7, QApplication::translate("Main_Window", "es", nullptr));
        CB_Keyboard_Layout->setItemText(8, QApplication::translate("Main_Window", "et", nullptr));
        CB_Keyboard_Layout->setItemText(9, QApplication::translate("Main_Window", "fi", nullptr));
        CB_Keyboard_Layout->setItemText(10, QApplication::translate("Main_Window", "fo", nullptr));
        CB_Keyboard_Layout->setItemText(11, QApplication::translate("Main_Window", "fr", nullptr));
        CB_Keyboard_Layout->setItemText(12, QApplication::translate("Main_Window", "fr-be", nullptr));
        CB_Keyboard_Layout->setItemText(13, QApplication::translate("Main_Window", "fr-ca", nullptr));
        CB_Keyboard_Layout->setItemText(14, QApplication::translate("Main_Window", "fr-ch", nullptr));
        CB_Keyboard_Layout->setItemText(15, QApplication::translate("Main_Window", "hr", nullptr));
        CB_Keyboard_Layout->setItemText(16, QApplication::translate("Main_Window", "hu", nullptr));
        CB_Keyboard_Layout->setItemText(17, QApplication::translate("Main_Window", "is", nullptr));
        CB_Keyboard_Layout->setItemText(18, QApplication::translate("Main_Window", "it", nullptr));
        CB_Keyboard_Layout->setItemText(19, QApplication::translate("Main_Window", "ja", nullptr));
        CB_Keyboard_Layout->setItemText(20, QApplication::translate("Main_Window", "lt", nullptr));
        CB_Keyboard_Layout->setItemText(21, QApplication::translate("Main_Window", "lv", nullptr));
        CB_Keyboard_Layout->setItemText(22, QApplication::translate("Main_Window", "mk", nullptr));
        CB_Keyboard_Layout->setItemText(23, QApplication::translate("Main_Window", "nl", nullptr));
        CB_Keyboard_Layout->setItemText(24, QApplication::translate("Main_Window", "nl-be", nullptr));
        CB_Keyboard_Layout->setItemText(25, QApplication::translate("Main_Window", "no", nullptr));
        CB_Keyboard_Layout->setItemText(26, QApplication::translate("Main_Window", "pl", nullptr));
        CB_Keyboard_Layout->setItemText(27, QApplication::translate("Main_Window", "pt", nullptr));
        CB_Keyboard_Layout->setItemText(28, QApplication::translate("Main_Window", "pt-br", nullptr));
        CB_Keyboard_Layout->setItemText(29, QApplication::translate("Main_Window", "ru", nullptr));
        CB_Keyboard_Layout->setItemText(30, QApplication::translate("Main_Window", "sl", nullptr));
        CB_Keyboard_Layout->setItemText(31, QApplication::translate("Main_Window", "sv", nullptr));
        CB_Keyboard_Layout->setItemText(32, QApplication::translate("Main_Window", "th", nullptr));
        CB_Keyboard_Layout->setItemText(33, QApplication::translate("Main_Window", "tr", nullptr));

        Label_Keyboard_Layout->setText(QApplication::translate("Main_Window", "&Keyboard Layout:", nullptr));
        Label_Machine_Type->setText(QApplication::translate("Main_Window", "Machine &Type:", nullptr));
        GB_Memory->setTitle(QApplication::translate("Main_Window", "Memory Size", nullptr));
        Check_Host_Mem->setText(QApplication::translate("Main_Window", "C&heck Free Memory", nullptr));
        Label_Min_Mem->setText(QApplication::translate("Main_Window", "2 MB", nullptr));
        Label_MB->setText(QApplication::translate("Main_Window", "MB", nullptr));
        CB_RAM_Size->setItemText(0, QApplication::translate("Main_Window", "2", nullptr));
        CB_RAM_Size->setItemText(1, QApplication::translate("Main_Window", "4", nullptr));
        CB_RAM_Size->setItemText(2, QApplication::translate("Main_Window", "8", nullptr));
        CB_RAM_Size->setItemText(3, QApplication::translate("Main_Window", "16", nullptr));
        CB_RAM_Size->setItemText(4, QApplication::translate("Main_Window", "32", nullptr));
        CB_RAM_Size->setItemText(5, QApplication::translate("Main_Window", "64", nullptr));
        CB_RAM_Size->setItemText(6, QApplication::translate("Main_Window", "128", nullptr));
        CB_RAM_Size->setItemText(7, QApplication::translate("Main_Window", "256", nullptr));
        CB_RAM_Size->setItemText(8, QApplication::translate("Main_Window", "512", nullptr));
        CB_RAM_Size->setItemText(9, QApplication::translate("Main_Window", "1024", nullptr));
        CB_RAM_Size->setItemText(10, QApplication::translate("Main_Window", "2048", nullptr));

        Label_Max_Mem->setText(QApplication::translate("Main_Window", "2048 MB", nullptr));
        GB_Audio->setTitle(QApplication::translate("Main_Window", "Audio Cards", nullptr));
        CH_GUS->setText(QApplication::translate("Main_Window", "Gravis &Ultrasound GF1", nullptr));
        CH_es1370->setText(QApplication::translate("Main_Window", "&ENSONIQ ES1370", nullptr));
        CH_Adlib->setText(QApplication::translate("Main_Window", "&Yamaha YM3812", nullptr));
        CH_PCSPK->setText(QApplication::translate("Main_Window", "PC Speaker", nullptr));
        CH_AC97->setText(QApplication::translate("Main_Window", "AC97 (Intel 82801AA)", nullptr));
        CH_sb16->setText(QApplication::translate("Main_Window", "Sound &Blaster 16", nullptr));
        Tabs->setTabText(Tabs->indexOf(Tab_General), QApplication::translate("Main_Window", "General", nullptr));
        GB_HDA->setTitle(QApplication::translate("Main_Window", "HDA (Primary Master)", nullptr));
        Label_HDA_Info->setText(QApplication::translate("Main_Window", "<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:9pt; font-weight:400; font-style:normal; text-decoration:none;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">Information:</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\"\">Type: File Format: qcow2 Size: 10 GB</span></p></body></html>", nullptr));
#ifndef QT_NO_TOOLTIP
        TB_HDA_SetPath->setToolTip(QApplication::translate("Main_Window", "Select Disk Image", nullptr));
#endif // QT_NO_TOOLTIP
        TB_HDA_SetPath->setText(QApplication::translate("Main_Window", "...", nullptr));
#ifndef QT_NO_TOOLTIP
        TB_HDA_Create_HDD->setToolTip(QApplication::translate("Main_Window", "Create New HDD", nullptr));
#endif // QT_NO_TOOLTIP
        TB_HDA_Create_HDD->setText(QString());
        GB_HDB->setTitle(QApplication::translate("Main_Window", "HDB (Primary Slave)", nullptr));
#ifndef QT_NO_TOOLTIP
        TB_HDB_SetPath->setToolTip(QApplication::translate("Main_Window", "Select Disk Image", nullptr));
#endif // QT_NO_TOOLTIP
        TB_HDB_SetPath->setText(QApplication::translate("Main_Window", "...", nullptr));
#ifndef QT_NO_TOOLTIP
        TB_HDB_Create_HDD->setToolTip(QApplication::translate("Main_Window", "Create New HDD", nullptr));
#endif // QT_NO_TOOLTIP
        TB_HDB_Create_HDD->setText(QString());
        Label_HDB_Info->setText(QApplication::translate("Main_Window", "<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:9pt; font-weight:400; font-style:normal; text-decoration:none;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">Information:</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\"\">Type: File Format: qcow2 Size: 10 GB</span></p></body></html>", nullptr));
        GB_HDC->setTitle(QApplication::translate("Main_Window", "HDC (Secondary Master)", nullptr));
#ifndef QT_NO_TOOLTIP
        TB_HDC_SetPath->setToolTip(QApplication::translate("Main_Window", "Select Disk Image", nullptr));
#endif // QT_NO_TOOLTIP
        TB_HDC_SetPath->setText(QApplication::translate("Main_Window", "...", nullptr));
#ifndef QT_NO_TOOLTIP
        TB_HDC_Create_HDD->setToolTip(QApplication::translate("Main_Window", "Create New HDD", nullptr));
#endif // QT_NO_TOOLTIP
        TB_HDC_Create_HDD->setText(QString());
        Label_HDC_Info->setText(QApplication::translate("Main_Window", "<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:9pt; font-weight:400; font-style:normal; text-decoration:none;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">Information:</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\"\">Type: File Format: qcow2 Size: 10 GB</span></p></body></html>", nullptr));
        GB_HDD->setTitle(QApplication::translate("Main_Window", "HDD (Secondary Slave)", nullptr));
#ifndef QT_NO_TOOLTIP
        TB_HDD_SetPath->setToolTip(QApplication::translate("Main_Window", "Select Disk Image", nullptr));
#endif // QT_NO_TOOLTIP
        TB_HDD_SetPath->setText(QApplication::translate("Main_Window", "...", nullptr));
#ifndef QT_NO_TOOLTIP
        TB_HDD_Create_HDD->setToolTip(QApplication::translate("Main_Window", "Create New HDD", nullptr));
#endif // QT_NO_TOOLTIP
        TB_HDD_Create_HDD->setText(QString());
        Label_HDD_Info->setText(QApplication::translate("Main_Window", "<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:9pt; font-weight:400; font-style:normal; text-decoration:none;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">Information:</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\"\">Type: File Format: qcow2 Size: 10 GB</span></p></body></html>", nullptr));
        Tabs->setTabText(Tabs->indexOf(Tab_HDD), QApplication::translate("Main_Window", "HDD", nullptr));
        GB_Floppy0->setTitle(QApplication::translate("Main_Window", "Floppy 1", nullptr));
        RB_FD0_Use_Image_File->setText(QApplication::translate("Main_Window", "Image File:", nullptr));
        TB_FD0_SetPath->setText(QApplication::translate("Main_Window", "...", nullptr));
        RB_FD0_Use_Host_Device->setText(QApplication::translate("Main_Window", "Host Device:", nullptr));
        GB_CDROM->setTitle(QApplication::translate("Main_Window", "CD/DVD-ROM", nullptr));
        RB_CDROM_Use_Host_Device->setText(QApplication::translate("Main_Window", "Host Device:", nullptr));
        TB_CDROM_SetPath->setText(QApplication::translate("Main_Window", "...", nullptr));
        RB_CDROM_Use_Image_File->setText(QApplication::translate("Main_Window", "Image File:", nullptr));
        GB_Floppy1->setTitle(QApplication::translate("Main_Window", "Floppy 2", nullptr));
        RB_FD1_Use_Host_Device->setText(QApplication::translate("Main_Window", "Host Device:", nullptr));
        TB_FD1_SetPath->setText(QApplication::translate("Main_Window", "...", nullptr));
        RB_FD1_Use_Image_File->setText(QApplication::translate("Main_Window", "Image File:", nullptr));
        Tabs->setTabText(Tabs->indexOf(Tab_Removable_Disks), QApplication::translate("Main_Window", "CD/DVD/Floppy", nullptr));
        Label_NetCard_Model->setText(QApplication::translate("Main_Window", "Network Card Model:", nullptr));
        Label_Connection_Mode->setText(QApplication::translate("Main_Window", "Connection &Mode:", nullptr));
        CB_Connection_Mode->setItemText(0, QApplication::translate("Main_Window", "Use the user mode network stack", nullptr));
        CB_Connection_Mode->setItemText(1, QApplication::translate("Main_Window", "Open a TUN/TAP interface", nullptr));
        CB_Connection_Mode->setItemText(2, QApplication::translate("Main_Window", "Use an already open TUN/TAP interface", nullptr));
        CB_Connection_Mode->setItemText(3, QApplication::translate("Main_Window", "Open a listening TCP socket", nullptr));
        CB_Connection_Mode->setItemText(4, QApplication::translate("Main_Window", "Use an already open TCP socket", nullptr));
        CB_Connection_Mode->setItemText(5, QApplication::translate("Main_Window", "Connect to listening TCP socket", nullptr));
        CB_Connection_Mode->setItemText(6, QApplication::translate("Main_Window", "Create shared VLAN via UDP multicast socket", nullptr));
        CB_Connection_Mode->setItemText(7, QApplication::translate("Main_Window", "Use an already open UDP multicast socket", nullptr));
        CB_Connection_Mode->setItemText(8, QApplication::translate("Main_Window", "No connection", nullptr));

        Label_IP->setText(QApplication::translate("Main_Window", "&IP Address:", nullptr));
        Edit_IP_Address->setText(QString());
        Label_MAC->setText(QApplication::translate("Main_Window", "&MAC Address:", nullptr));
        Edit_MAC_Address->setText(QString());
#ifndef QT_NO_TOOLTIP
        TB_Generate_New_MAC->setToolTip(QApplication::translate("Main_Window", "Generate New MAC", nullptr));
#endif // QT_NO_TOOLTIP
        TB_Generate_New_MAC->setText(QString());
        Label_Host_Name->setText(QApplication::translate("Main_Window", "VM Hostname:", nullptr));
        Label_Port->setText(QApplication::translate("Main_Window", "&Port:", nullptr));
        Label_VLAN->setText(QApplication::translate("Main_Window", "&VLAN:", nullptr));
        Label_File_Descriptor->setText(QApplication::translate("Main_Window", "&FD:", nullptr));
        TB_Browse_TUN_Script->setText(QApplication::translate("Main_Window", "...", nullptr));
        Label_If_Name->setText(QApplication::translate("Main_Window", "&Interface Name:", nullptr));
        CH_TUN_TAP_Script->setText(QApplication::translate("Main_Window", "&TUN/TAP Script:", nullptr));
        Button_Delete_Net_Card->setText(QApplication::translate("Main_Window", "&Delete", nullptr));
        Button_Add_Net_Card->setText(QApplication::translate("Main_Window", "Add", nullptr));
        Label_Cards_List->setText(QApplication::translate("Main_Window", "Cards List:", nullptr));
        Network_Cards_Tabs->setTabText(Network_Cards_Tabs->indexOf(Network_Cards_Tab), QApplication::translate("Main_Window", "Network Cards", nullptr));
        GB_Redirections->setTitle(QApplication::translate("Main_Window", "&Redirections", nullptr));
        Label_Protocol->setText(QApplication::translate("Main_Window", "Protocol:", nullptr));
        RB_TCP->setText(QApplication::translate("Main_Window", "&TCP", nullptr));
        RB_UDP->setText(QApplication::translate("Main_Window", "&UDP", nullptr));
        Label_Port1->setText(QApplication::translate("Main_Window", "&Host Port", nullptr));
        Label_To_Guest_IP->setText(QApplication::translate("Main_Window", "to &guest IP", nullptr));
        Label_Port2->setText(QApplication::translate("Main_Window", "Guest Por&t", nullptr));
        Button_Add_Redirections->setText(QApplication::translate("Main_Window", "A&dd", nullptr));
        Button_Delete_Redirections->setText(QApplication::translate("Main_Window", "D&elete", nullptr));
        Button_Apply_Redirections->setText(QApplication::translate("Main_Window", "Appl&y", nullptr));
        Button_Clear_Redirections->setText(QApplication::translate("Main_Window", "&Clear", nullptr));
        QTableWidgetItem *___qtablewidgetitem = Redirections_List->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Main_Window", "Protocol", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = Redirections_List->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("Main_Window", "Host Port", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = Redirections_List->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("Main_Window", "Guest IP", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = Redirections_List->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("Main_Window", "Guest Port", nullptr));
        Label_Redirect_Settings->setText(QApplication::translate("Main_Window", "Redirect Settings", nullptr));
        Label_SMB_Folder->setText(QApplication::translate("Main_Window", "Allow &SMB Access to:", nullptr));
        Label_TFTP->setText(QApplication::translate("Main_Window", "T&FTP Server Prefix:", nullptr));
        TB_Browse_SMB->setText(QApplication::translate("Main_Window", "...", nullptr));
        Network_Cards_Tabs->setTabText(Network_Cards_Tabs->indexOf(Tab_Network_Settings), QApplication::translate("Main_Window", "Additional Settings", nullptr));
        CH_Use_Network->setText(QApplication::translate("Main_Window", "Use &Network", nullptr));
        Tabs->setTabText(Tabs->indexOf(Tab_Network), QApplication::translate("Main_Window", "Network", nullptr));
        Label_QEMU_Window_Options->setText(QApplication::translate("Main_Window", "QEMU Window Options", nullptr));
        CH_No_Frame->setText(QApplication::translate("Main_Window", "Show QEMU Window Without a Frame and Window Decorations", nullptr));
        CH_Alt_Grab->setText(QApplication::translate("Main_Window", "Use Ctrl-Alt-Shift to Grab Mouse (Default Ctrl-Alt)", nullptr));
        CH_No_Quit->setText(QApplication::translate("Main_Window", "Disable QEMU Window Close Capability", nullptr));
        CH_Portrait->setText(QApplication::translate("Main_Window", "Rotate Graphical Output 90 Deg Left (Only PXA LCD)", nullptr));
        Label_Additional_Options->setText(QApplication::translate("Main_Window", "Additional Options", nullptr));
#ifndef QT_NO_TOOLTIP
        CH_FDD_Boot->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        CH_FDD_Boot->setText(QApplication::translate("Main_Window", "Check Boot Secto&r on FDD (Boot Signature For Floppy Disks in VM BIOS)", nullptr));
#ifndef QT_NO_TOOLTIP
        CH_QEMU_Log->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        CH_QEMU_Log->setText(QApplication::translate("Main_Window", "Use QEMU Log (Output Log in /tmp/qemu.log)", nullptr));
#ifndef QT_NO_TOOLTIP
        CH_Win2K_Hack->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        CH_Win2K_Hack->setText(QApplication::translate("Main_Window", "&Windows 2000 Hack (Fix Installation Windows 2000 Bug)", nullptr));
        CH_Start_Date->setText(QApplication::translate("Main_Window", "Start Date (Day.Month.Year Hour:Minute:Second)", nullptr));
        DTE_Start_Date->setDisplayFormat(QApplication::translate("Main_Window", "dd.MM.yyyy HH:mm:ss", nullptr));
        CH_Init_Graphic_Mode->setText(QApplication::translate("Main_Window", "Initial Graphical Mode", nullptr));
        Label_W->setText(QApplication::translate("Main_Window", "Width", nullptr));
        Label_H->setText(QApplication::translate("Main_Window", "Height", nullptr));
        Label_Depth->setText(QApplication::translate("Main_Window", "Depth", nullptr));
        CB_InitGM_Depth->setItemText(0, QApplication::translate("Main_Window", "8", nullptr));
        CB_InitGM_Depth->setItemText(1, QApplication::translate("Main_Window", "16", nullptr));
        CB_InitGM_Depth->setItemText(2, QApplication::translate("Main_Window", "24", nullptr));
        CB_InitGM_Depth->setItemText(3, QApplication::translate("Main_Window", "32", nullptr));

        Label_Use_KVM->setText(QApplication::translate("Main_Window", "KVM Options", nullptr));
        CH_No_KVM_IRQChip->setText(QApplication::translate("Main_Window", "Disable KVM kernel mode PIC/IOAPIC/LAPIC", nullptr));
        CH_No_KVM_Pit->setText(QApplication::translate("Main_Window", "Disable KVM kernel mode PIT", nullptr));
        CH_KVM_Shadow_Memory->setText(QApplication::translate("Main_Window", "KVM Shadow Memory", nullptr));
        Label_KVM_Shadow_Memory_Mb->setText(QApplication::translate("Main_Window", "Mb", nullptr));
        Tabs->setTabText(Tabs->indexOf(Tab_Advanced), QApplication::translate("Main_Window", "Advanced", nullptr));
        CH_Activate_VNC->setText(QApplication::translate("Main_Window", "Activate VNC", nullptr));
#ifndef QT_NO_TOOLTIP
        SB_VNC_Display->setToolTip(QApplication::translate("Main_Window", "For Connection Use Port 5900 + VNC Display Number", nullptr));
#endif // QT_NO_TOOLTIP
        RB_VNC_Unix_Socket->setText(QApplication::translate("Main_Window", "UNIX Domain Socket", nullptr));
        CH_VNC_Password->setText(QApplication::translate("Main_Window", "Use Password (You must set a password when you start the VM)", nullptr));
        TB_VNC_Unix_Socket_Browse->setText(QApplication::translate("Main_Window", "...", nullptr));
        CH_Use_VNC_TLS->setText(QApplication::translate("Main_Window", "Use TLS", nullptr));
        RB_VNC_Display_Number->setText(QApplication::translate("Main_Window", "VNC Display Number", nullptr));
        TB_x509verify_Browse->setText(QApplication::translate("Main_Window", "...", nullptr));
        TB_x509_Browse->setText(QApplication::translate("Main_Window", "...", nullptr));
        CH_x509_Folder->setText(QApplication::translate("Main_Window", "x509 Folder Path", nullptr));
        CH_x509verify_Folder->setText(QApplication::translate("Main_Window", "x509verify Folder Path", nullptr));
        Tabs_Other->setTabText(Tabs_Other->indexOf(Tab_VNC), QApplication::translate("Main_Window", "VNC", nullptr));
        TB_SD_Image_File_Browse->setText(QApplication::translate("Main_Window", "...", nullptr));
        CH_PFlash->setText(QApplication::translate("Main_Window", "Parallel Flash Image", nullptr));
        TB_ROM_File_Browse->setText(QApplication::translate("Main_Window", "...", nullptr));
        CH_ROM_File->setText(QApplication::translate("Main_Window", "ROM File (For EtherBoot)", nullptr));
        CH_MTDBlock->setText(QApplication::translate("Main_Window", "On-Board Flash Image", nullptr));
        TB_MTDBlock_File_Browse->setText(QApplication::translate("Main_Window", "...", nullptr));
        CH_SD_Image->setText(QApplication::translate("Main_Window", "SecureDigital Card Image", nullptr));
        TB_PFlash_File_Browse->setText(QApplication::translate("Main_Window", "...", nullptr));
        Tabs_Other->setTabText(Tabs_Other->indexOf(Tab_Optional_Images), QApplication::translate("Main_Window", "Optional Images", nullptr));
        CH_Use_Linux_Boot->setText(QApplication::translate("Main_Window", "Use &Linux Boot", nullptr));
        TB_Linux_bzImage_SetPath->setText(QApplication::translate("Main_Window", "...", nullptr));
        TB_Linux_Initrd_SetPath->setText(QApplication::translate("Main_Window", "...", nullptr));
        Label_KernelCom->setText(QApplication::translate("Main_Window", "Append Command Line:", nullptr));
        Label_InitRD->setText(QApplication::translate("Main_Window", "&Initrd File:", nullptr));
        Label_bzImage->setText(QApplication::translate("Main_Window", "Kernel bzImage File:", nullptr));
        Tabs_Other->setTabText(Tabs_Other->indexOf(Tab_Boot_Linux), QApplication::translate("Main_Window", "Boot Linux Kernel", nullptr));
        Label_Additional_QEMU_Args->setText(QApplication::translate("Main_Window", "Additional QEMU &Arguments:", nullptr));
#ifndef QT_NO_TOOLTIP
        CH_Use_GDB->setToolTip(QApplication::translate("Main_Window", "Wait gdb connection to port 1234", nullptr));
#endif // QT_NO_TOOLTIP
        CH_Use_GDB->setText(QApplication::translate("Main_Window", "&Wait GDB Connection on Port", nullptr));
        Tabs->setTabText(Tabs->indexOf(Tab_Other), QApplication::translate("Main_Window", "Other", nullptr));
        Button_Apply->setText(QApplication::translate("Main_Window", "&Apply", nullptr));
        Button_Cancel->setText(QApplication::translate("Main_Window", "&Discard Changes", nullptr));
        menuVM->setTitle(QApplication::translate("Main_Window", "&VM", nullptr));
        menuNew_VM->setTitle(QApplication::translate("Main_Window", "&New VM", nullptr));
        menuHelp->setTitle(QApplication::translate("Main_Window", "&Help", nullptr));
        menuFile->setTitle(QApplication::translate("Main_Window", "&File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Main_Window: public Ui_Main_Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_WINDOW_H
