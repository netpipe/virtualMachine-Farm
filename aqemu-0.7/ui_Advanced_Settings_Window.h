/********************************************************************************
** Form generated from reading UI file 'Advanced_Settings_Window.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADVANCED_SETTINGS_WINDOW_H
#define UI_ADVANCED_SETTINGS_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Advanced_Settings_Window
{
public:
    QGridLayout *gridLayout_5;
    QHBoxLayout *hboxLayout;
    QSpacerItem *spacerItem;
    QPushButton *Button_OK;
    QPushButton *Button_Cancel;
    QTabWidget *All_Tabs;
    QWidget *Tab_General;
    QGridLayout *gridLayout_10;
    QVBoxLayout *verticalLayout;
    QGroupBox *GB_QEMU_Version;
    QGridLayout *gridLayout_8;
    QCheckBox *CH_Check_Version_on_Start;
    QCheckBox *CH_Check_KVM;
    QHBoxLayout *hboxLayout1;
    QLabel *Label_Compatibility_Mode;
    QFrame *line_10;
    QHBoxLayout *hboxLayout2;
    QRadioButton *RB_QEMU_Version_Auto;
    QRadioButton *RB_QEMU_Version_Manual;
    QHBoxLayout *hboxLayout3;
    QLabel *Label_Compatibility;
    QComboBox *CB_QEMU_Version;
    QGroupBox *GB_Start_Stop;
    QGridLayout *gridLayout_9;
    QLabel *Label_Before_Start;
    QLineEdit *Edit_Before_Start_Command;
    QToolButton *TB_Browse_Before;
    QLabel *Label_After_Stop;
    QLineEdit *Edit_After_Stop_Command;
    QToolButton *TB_Browse_After;
    QGroupBox *GB_QEMU_Log;
    QGridLayout *gridLayout;
    QCheckBox *CH_QEMU_Log_exec;
    QCheckBox *CH_QEMU_Log_op;
    QCheckBox *CH_QEMU_Log_int;
    QCheckBox *CH_QEMU_Log_op_opt;
    QCheckBox *CH_QEMU_Log_cpu;
    QCheckBox *CH_QEMU_Log_pcall;
    QCheckBox *CH_QEMU_Log_in_asm;
    QCheckBox *CH_QEMU_Log_out_asm;
    QGroupBox *GB_NetCard_Settings_Mode;
    QGridLayout *gridLayout_11;
    QRadioButton *RB_NetCard_Settings_Default;
    QSpacerItem *spacerItem1;
    QRadioButton *RB_Net_Card_Settings_Old;
    QGroupBox *GB_QEMU_IMG_Binary_Path;
    QGridLayout *gridLayout1;
    QToolButton *TB_QEMU_IMG_Browse;
    QLineEdit *Edit_QEMU_IMG_Path;
    QWidget *Tab_Tab_info;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout;
    QCheckBox *CH_Show_Tab_Info;
    QSpacerItem *horizontalSpacer;
    QCheckBox *CH_Show_QEMU_Args;
    QSpacerItem *horizontalSpacer_2;
    QCheckBox *CH_Show_Screenshot_in_Save_Mode;
    QFrame *line_15;
    QWidget *QEMU_Args_Widget;
    QGridLayout *gridLayout9999;
    QVBoxLayout *vboxLayout;
    QCheckBox *CH_Machine_Details;
    QCheckBox *CH_Machine_Name;
    QVBoxLayout *vboxLayout1;
    QCheckBox *CH_Memory_Size;
    QCheckBox *CH_Use_Sound;
    QVBoxLayout *vboxLayout2;
    QVBoxLayout *vboxLayout3;
    QCheckBox *CH_Show_FDD;
    QCheckBox *CH_Show_CD;
    QCheckBox *CH_Show_HDD;
    QFrame *line_5;
    QVBoxLayout *vboxLayout4;
    QCheckBox *CH_Network_Cards;
    QCheckBox *CH_Redirections;
    QCheckBox *CH_TFTP_Server_Prefix;
    QCheckBox *CH_SMB_Dir;
    QFrame *line_6;
    QVBoxLayout *vboxLayout5;
    QCheckBox *CH_No_Frame;
    QCheckBox *CH_Alt_Grab;
    QCheckBox *CH_No_Quit;
    QCheckBox *CH_Portrait;
    QVBoxLayout *vboxLayout6;
    QCheckBox *CH_Computer_Type;
    QCheckBox *CH_Machine_Type;
    QCheckBox *CH_CPU_Type;
    QCheckBox *CH_Number_of_CPU;
    QCheckBox *CH_Acceleration;
    QCheckBox *CH_Boot_Priority;
    QCheckBox *CH_Video_Card;
    QCheckBox *CH_Keyboard_Layout;
    QVBoxLayout *vboxLayout7;
    QCheckBox *CH_Fullscreen;
    QCheckBox *CH_ACPI;
    QCheckBox *CH_Localtime;
    QCheckBox *CH_Start_CPU;
    QCheckBox *CH_Snapshot;
    QCheckBox *CH_No_Reboot;
    QVBoxLayout *vboxLayout8;
    QCheckBox *CH_Serial_Port;
    QCheckBox *CH_Parallel_Port;
    QCheckBox *CH_USB_Port;
    QVBoxLayout *vboxLayout9;
    QCheckBox *CH_Linux_Boot;
    QCheckBox *CH_ROM_File;
    QCheckBox *CH_PFlash;
    QVBoxLayout *vboxLayout10;
    QCheckBox *CH_MTDBlock;
    QCheckBox *CH_SD_Image;
    QCheckBox *CH_GDB_Port;
    QVBoxLayout *vboxLayout11;
    QCheckBox *CH_Win2K_Hack;
    QCheckBox *CH_QEMU_Log;
    QCheckBox *CH_Check_Boot_on_FDD;
    QFrame *line_9;
    QFrame *line_3;
    QFrame *line_8;
    QFrame *line_2;
    QFrame *line_4;
    QFrame *line;
    QFrame *line_7;
    QFrame *line_12;
    QWidget *Tab_Other;
    QGridLayout *gridLayout_7;
    QGroupBox *GB_NetCard_MAC;
    QGridLayout *gridLayout_4;
    QRadioButton *RB_MAC_Random;
    QRadioButton *RB_MAC_QEMU;
    QRadioButton *RB_MAC_Valid;
    QGroupBox *GB_Audio_Default;
    QGridLayout *gridLayout_6;
    QLabel *Label_Host_Sound_System;
    QSpacerItem *horizontalSpacer_3;
    QComboBox *CB_Host_Sound_System;
    QGroupBox *GB_AQEMU_Log;
    QGridLayout *gridLayout2;
    QHBoxLayout *hboxLayout4;
    QLabel *Label_Save_Log_In;
    QFrame *line_13;
    QHBoxLayout *hboxLayout5;
    QCheckBox *CH_Log_Save_in_File;
    QSpacerItem *spacerItem2;
    QCheckBox *CH_Log_Print_in_STDIO;
    QSpacerItem *spacerItem3;
    QHBoxLayout *hboxLayout6;
    QLabel *Label_Log_Messages;
    QFrame *line_14;
    QHBoxLayout *hboxLayout7;
    QCheckBox *CH_Log_Debug;
    QSpacerItem *spacerItem4;
    QCheckBox *CH_Log_Warning;
    QSpacerItem *spacerItem5;
    QCheckBox *CH_Log_Error;
    QHBoxLayout *hboxLayout8;
    QLabel *Label_Log_Path;
    QLineEdit *Edit_Log_Path;
    QToolButton *TB_Log_File;
    QGridLayout *gridLayout_3;
    QLabel *Label_Recent_Count;
    QSpinBox *SB_Recent_Count;
    QLabel *Label_First_VNC_Port;
    QSpinBox *SB_First_VNC_Port;

    void setupUi(QDialog *Advanced_Settings_Window)
    {
        if (Advanced_Settings_Window->objectName().isEmpty())
            Advanced_Settings_Window->setObjectName(QString::fromUtf8("Advanced_Settings_Window"));
        Advanced_Settings_Window->resize(532, 514);
        gridLayout_5 = new QGridLayout(Advanced_Settings_Window);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(6, 6, 6, 6);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        hboxLayout = new QHBoxLayout();
        hboxLayout->setSpacing(6);
        hboxLayout->setContentsMargins(0, 0, 0, 0);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        spacerItem = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(spacerItem);

        Button_OK = new QPushButton(Advanced_Settings_Window);
        Button_OK->setObjectName(QString::fromUtf8("Button_OK"));

        hboxLayout->addWidget(Button_OK);

        Button_Cancel = new QPushButton(Advanced_Settings_Window);
        Button_Cancel->setObjectName(QString::fromUtf8("Button_Cancel"));

        hboxLayout->addWidget(Button_Cancel);


        gridLayout_5->addLayout(hboxLayout, 1, 0, 1, 1);

        All_Tabs = new QTabWidget(Advanced_Settings_Window);
        All_Tabs->setObjectName(QString::fromUtf8("All_Tabs"));
        Tab_General = new QWidget();
        Tab_General->setObjectName(QString::fromUtf8("Tab_General"));
        gridLayout_10 = new QGridLayout(Tab_General);
        gridLayout_10->setSpacing(6);
        gridLayout_10->setContentsMargins(6, 6, 6, 6);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        GB_QEMU_Version = new QGroupBox(Tab_General);
        GB_QEMU_Version->setObjectName(QString::fromUtf8("GB_QEMU_Version"));
        gridLayout_8 = new QGridLayout(GB_QEMU_Version);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(6, 6, 6, 6);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        CH_Check_Version_on_Start = new QCheckBox(GB_QEMU_Version);
        CH_Check_Version_on_Start->setObjectName(QString::fromUtf8("CH_Check_Version_on_Start"));
        CH_Check_Version_on_Start->setChecked(true);

        gridLayout_8->addWidget(CH_Check_Version_on_Start, 0, 0, 1, 1);

        CH_Check_KVM = new QCheckBox(GB_QEMU_Version);
        CH_Check_KVM->setObjectName(QString::fromUtf8("CH_Check_KVM"));
        CH_Check_KVM->setChecked(true);

        gridLayout_8->addWidget(CH_Check_KVM, 1, 0, 1, 1);

        hboxLayout1 = new QHBoxLayout();
        hboxLayout1->setSpacing(6);
        hboxLayout1->setContentsMargins(0, 0, 0, 0);
        hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
        Label_Compatibility_Mode = new QLabel(GB_QEMU_Version);
        Label_Compatibility_Mode->setObjectName(QString::fromUtf8("Label_Compatibility_Mode"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Label_Compatibility_Mode->sizePolicy().hasHeightForWidth());
        Label_Compatibility_Mode->setSizePolicy(sizePolicy);

        hboxLayout1->addWidget(Label_Compatibility_Mode);

        line_10 = new QFrame(GB_QEMU_Version);
        line_10->setObjectName(QString::fromUtf8("line_10"));
        line_10->setFrameShape(QFrame::HLine);
        line_10->setFrameShadow(QFrame::Sunken);

        hboxLayout1->addWidget(line_10);


        gridLayout_8->addLayout(hboxLayout1, 2, 0, 1, 1);

        hboxLayout2 = new QHBoxLayout();
        hboxLayout2->setSpacing(6);
        hboxLayout2->setContentsMargins(0, 0, 0, 0);
        hboxLayout2->setObjectName(QString::fromUtf8("hboxLayout2"));
        RB_QEMU_Version_Auto = new QRadioButton(GB_QEMU_Version);
        RB_QEMU_Version_Auto->setObjectName(QString::fromUtf8("RB_QEMU_Version_Auto"));
        RB_QEMU_Version_Auto->setChecked(true);

        hboxLayout2->addWidget(RB_QEMU_Version_Auto);

        RB_QEMU_Version_Manual = new QRadioButton(GB_QEMU_Version);
        RB_QEMU_Version_Manual->setObjectName(QString::fromUtf8("RB_QEMU_Version_Manual"));

        hboxLayout2->addWidget(RB_QEMU_Version_Manual);


        gridLayout_8->addLayout(hboxLayout2, 3, 0, 1, 1);

        hboxLayout3 = new QHBoxLayout();
        hboxLayout3->setSpacing(6);
        hboxLayout3->setContentsMargins(0, 0, 0, 0);
        hboxLayout3->setObjectName(QString::fromUtf8("hboxLayout3"));
        Label_Compatibility = new QLabel(GB_QEMU_Version);
        Label_Compatibility->setObjectName(QString::fromUtf8("Label_Compatibility"));
        Label_Compatibility->setEnabled(false);

        hboxLayout3->addWidget(Label_Compatibility);

        CB_QEMU_Version = new QComboBox(GB_QEMU_Version);
        CB_QEMU_Version->addItem(QString());
        CB_QEMU_Version->addItem(QString());
        CB_QEMU_Version->setObjectName(QString::fromUtf8("CB_QEMU_Version"));
        CB_QEMU_Version->setEnabled(false);
        CB_QEMU_Version->setMaxCount(256);

        hboxLayout3->addWidget(CB_QEMU_Version);


        gridLayout_8->addLayout(hboxLayout3, 4, 0, 1, 1);


        verticalLayout->addWidget(GB_QEMU_Version);

        GB_Start_Stop = new QGroupBox(Tab_General);
        GB_Start_Stop->setObjectName(QString::fromUtf8("GB_Start_Stop"));
        gridLayout_9 = new QGridLayout(GB_Start_Stop);
        gridLayout_9->setSpacing(6);
        gridLayout_9->setContentsMargins(6, 6, 6, 6);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        Label_Before_Start = new QLabel(GB_Start_Stop);
        Label_Before_Start->setObjectName(QString::fromUtf8("Label_Before_Start"));

        gridLayout_9->addWidget(Label_Before_Start, 0, 0, 1, 1);

        Edit_Before_Start_Command = new QLineEdit(GB_Start_Stop);
        Edit_Before_Start_Command->setObjectName(QString::fromUtf8("Edit_Before_Start_Command"));

        gridLayout_9->addWidget(Edit_Before_Start_Command, 1, 0, 1, 1);

        TB_Browse_Before = new QToolButton(GB_Start_Stop);
        TB_Browse_Before->setObjectName(QString::fromUtf8("TB_Browse_Before"));

        gridLayout_9->addWidget(TB_Browse_Before, 1, 1, 1, 1);

        Label_After_Stop = new QLabel(GB_Start_Stop);
        Label_After_Stop->setObjectName(QString::fromUtf8("Label_After_Stop"));

        gridLayout_9->addWidget(Label_After_Stop, 2, 0, 1, 1);

        Edit_After_Stop_Command = new QLineEdit(GB_Start_Stop);
        Edit_After_Stop_Command->setObjectName(QString::fromUtf8("Edit_After_Stop_Command"));

        gridLayout_9->addWidget(Edit_After_Stop_Command, 3, 0, 1, 1);

        TB_Browse_After = new QToolButton(GB_Start_Stop);
        TB_Browse_After->setObjectName(QString::fromUtf8("TB_Browse_After"));

        gridLayout_9->addWidget(TB_Browse_After, 3, 1, 1, 1);


        verticalLayout->addWidget(GB_Start_Stop);


        gridLayout_10->addLayout(verticalLayout, 0, 0, 1, 1);

        GB_QEMU_Log = new QGroupBox(Tab_General);
        GB_QEMU_Log->setObjectName(QString::fromUtf8("GB_QEMU_Log"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(GB_QEMU_Log->sizePolicy().hasHeightForWidth());
        GB_QEMU_Log->setSizePolicy(sizePolicy1);
        gridLayout = new QGridLayout(GB_QEMU_Log);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(9, 9, 9, 9);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        CH_QEMU_Log_exec = new QCheckBox(GB_QEMU_Log);
        CH_QEMU_Log_exec->setObjectName(QString::fromUtf8("CH_QEMU_Log_exec"));
        CH_QEMU_Log_exec->setChecked(true);

        gridLayout->addWidget(CH_QEMU_Log_exec, 7, 0, 1, 1);

        CH_QEMU_Log_op = new QCheckBox(GB_QEMU_Log);
        CH_QEMU_Log_op->setObjectName(QString::fromUtf8("CH_QEMU_Log_op"));
        CH_QEMU_Log_op->setChecked(true);

        gridLayout->addWidget(CH_QEMU_Log_op, 6, 0, 1, 1);

        CH_QEMU_Log_int = new QCheckBox(GB_QEMU_Log);
        CH_QEMU_Log_int->setObjectName(QString::fromUtf8("CH_QEMU_Log_int"));
        CH_QEMU_Log_int->setChecked(true);

        gridLayout->addWidget(CH_QEMU_Log_int, 5, 0, 1, 1);

        CH_QEMU_Log_op_opt = new QCheckBox(GB_QEMU_Log);
        CH_QEMU_Log_op_opt->setObjectName(QString::fromUtf8("CH_QEMU_Log_op_opt"));
        CH_QEMU_Log_op_opt->setChecked(true);

        gridLayout->addWidget(CH_QEMU_Log_op_opt, 4, 0, 1, 1);

        CH_QEMU_Log_cpu = new QCheckBox(GB_QEMU_Log);
        CH_QEMU_Log_cpu->setObjectName(QString::fromUtf8("CH_QEMU_Log_cpu"));
        CH_QEMU_Log_cpu->setChecked(true);

        gridLayout->addWidget(CH_QEMU_Log_cpu, 3, 0, 1, 1);

        CH_QEMU_Log_pcall = new QCheckBox(GB_QEMU_Log);
        CH_QEMU_Log_pcall->setObjectName(QString::fromUtf8("CH_QEMU_Log_pcall"));
        CH_QEMU_Log_pcall->setChecked(true);

        gridLayout->addWidget(CH_QEMU_Log_pcall, 2, 0, 1, 1);

        CH_QEMU_Log_in_asm = new QCheckBox(GB_QEMU_Log);
        CH_QEMU_Log_in_asm->setObjectName(QString::fromUtf8("CH_QEMU_Log_in_asm"));
        CH_QEMU_Log_in_asm->setChecked(true);

        gridLayout->addWidget(CH_QEMU_Log_in_asm, 1, 0, 1, 1);

        CH_QEMU_Log_out_asm = new QCheckBox(GB_QEMU_Log);
        CH_QEMU_Log_out_asm->setObjectName(QString::fromUtf8("CH_QEMU_Log_out_asm"));
        CH_QEMU_Log_out_asm->setChecked(true);

        gridLayout->addWidget(CH_QEMU_Log_out_asm, 0, 0, 1, 1);


        gridLayout_10->addWidget(GB_QEMU_Log, 0, 1, 1, 1);

        GB_NetCard_Settings_Mode = new QGroupBox(Tab_General);
        GB_NetCard_Settings_Mode->setObjectName(QString::fromUtf8("GB_NetCard_Settings_Mode"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(GB_NetCard_Settings_Mode->sizePolicy().hasHeightForWidth());
        GB_NetCard_Settings_Mode->setSizePolicy(sizePolicy2);
        gridLayout_11 = new QGridLayout(GB_NetCard_Settings_Mode);
        gridLayout_11->setSpacing(6);
        gridLayout_11->setContentsMargins(4, 4, 4, 4);
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        RB_NetCard_Settings_Default = new QRadioButton(GB_NetCard_Settings_Mode);
        RB_NetCard_Settings_Default->setObjectName(QString::fromUtf8("RB_NetCard_Settings_Default"));
        RB_NetCard_Settings_Default->setEnabled(false);

        gridLayout_11->addWidget(RB_NetCard_Settings_Default, 0, 0, 1, 1);

        spacerItem1 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_11->addItem(spacerItem1, 0, 1, 1, 1);

        RB_Net_Card_Settings_Old = new QRadioButton(GB_NetCard_Settings_Mode);
        RB_Net_Card_Settings_Old->setObjectName(QString::fromUtf8("RB_Net_Card_Settings_Old"));
        RB_Net_Card_Settings_Old->setChecked(true);

        gridLayout_11->addWidget(RB_Net_Card_Settings_Old, 0, 2, 1, 1);


        gridLayout_10->addWidget(GB_NetCard_Settings_Mode, 1, 0, 1, 2);

        GB_QEMU_IMG_Binary_Path = new QGroupBox(Tab_General);
        GB_QEMU_IMG_Binary_Path->setObjectName(QString::fromUtf8("GB_QEMU_IMG_Binary_Path"));
        sizePolicy2.setHeightForWidth(GB_QEMU_IMG_Binary_Path->sizePolicy().hasHeightForWidth());
        GB_QEMU_IMG_Binary_Path->setSizePolicy(sizePolicy2);
        gridLayout1 = new QGridLayout(GB_QEMU_IMG_Binary_Path);
        gridLayout1->setSpacing(6);
        gridLayout1->setContentsMargins(6, 6, 6, 6);
        gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
        TB_QEMU_IMG_Browse = new QToolButton(GB_QEMU_IMG_Binary_Path);
        TB_QEMU_IMG_Browse->setObjectName(QString::fromUtf8("TB_QEMU_IMG_Browse"));

        gridLayout1->addWidget(TB_QEMU_IMG_Browse, 0, 1, 1, 1);

        Edit_QEMU_IMG_Path = new QLineEdit(GB_QEMU_IMG_Binary_Path);
        Edit_QEMU_IMG_Path->setObjectName(QString::fromUtf8("Edit_QEMU_IMG_Path"));

        gridLayout1->addWidget(Edit_QEMU_IMG_Path, 0, 0, 1, 1);


        gridLayout_10->addWidget(GB_QEMU_IMG_Binary_Path, 2, 0, 1, 2);

        All_Tabs->addTab(Tab_General, QString());
        Tab_Tab_info = new QWidget();
        Tab_Tab_info->setObjectName(QString::fromUtf8("Tab_Tab_info"));
        gridLayout_2 = new QGridLayout(Tab_Tab_info);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(6, 6, 6, 6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        CH_Show_Tab_Info = new QCheckBox(Tab_Tab_info);
        CH_Show_Tab_Info->setObjectName(QString::fromUtf8("CH_Show_Tab_Info"));
        CH_Show_Tab_Info->setChecked(true);

        horizontalLayout->addWidget(CH_Show_Tab_Info);

        horizontalSpacer = new QSpacerItem(13, 18, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        CH_Show_QEMU_Args = new QCheckBox(Tab_Tab_info);
        CH_Show_QEMU_Args->setObjectName(QString::fromUtf8("CH_Show_QEMU_Args"));

        horizontalLayout->addWidget(CH_Show_QEMU_Args);

        horizontalSpacer_2 = new QSpacerItem(18, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        CH_Show_Screenshot_in_Save_Mode = new QCheckBox(Tab_Tab_info);
        CH_Show_Screenshot_in_Save_Mode->setObjectName(QString::fromUtf8("CH_Show_Screenshot_in_Save_Mode"));

        horizontalLayout->addWidget(CH_Show_Screenshot_in_Save_Mode);


        gridLayout_2->addLayout(horizontalLayout, 0, 0, 1, 1);

        line_15 = new QFrame(Tab_Tab_info);
        line_15->setObjectName(QString::fromUtf8("line_15"));
        line_15->setFrameShape(QFrame::HLine);
        line_15->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line_15, 1, 0, 1, 1);

        QEMU_Args_Widget = new QWidget(Tab_Tab_info);
        QEMU_Args_Widget->setObjectName(QString::fromUtf8("QEMU_Args_Widget"));
        gridLayout9999 = new QGridLayout(QEMU_Args_Widget);
        gridLayout9999->setSpacing(6);
        gridLayout9999->setContentsMargins(0, 0, 0, 0);
        gridLayout9999->setObjectName(QString::fromUtf8("gridLayout9999"));
        vboxLayout = new QVBoxLayout();
        vboxLayout->setSpacing(2);
        vboxLayout->setContentsMargins(0, 0, 0, 0);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        CH_Machine_Details = new QCheckBox(QEMU_Args_Widget);
        CH_Machine_Details->setObjectName(QString::fromUtf8("CH_Machine_Details"));

        vboxLayout->addWidget(CH_Machine_Details);

        CH_Machine_Name = new QCheckBox(QEMU_Args_Widget);
        CH_Machine_Name->setObjectName(QString::fromUtf8("CH_Machine_Name"));

        vboxLayout->addWidget(CH_Machine_Name);


        gridLayout9999->addLayout(vboxLayout, 0, 0, 1, 1);

        vboxLayout1 = new QVBoxLayout();
        vboxLayout1->setSpacing(2);
        vboxLayout1->setContentsMargins(0, 0, 0, 0);
        vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
        CH_Memory_Size = new QCheckBox(QEMU_Args_Widget);
        CH_Memory_Size->setObjectName(QString::fromUtf8("CH_Memory_Size"));

        vboxLayout1->addWidget(CH_Memory_Size);

        CH_Use_Sound = new QCheckBox(QEMU_Args_Widget);
        CH_Use_Sound->setObjectName(QString::fromUtf8("CH_Use_Sound"));

        vboxLayout1->addWidget(CH_Use_Sound);


        gridLayout9999->addLayout(vboxLayout1, 0, 2, 1, 1);

        vboxLayout2 = new QVBoxLayout();
        vboxLayout2->setSpacing(6);
        vboxLayout2->setContentsMargins(0, 0, 0, 0);
        vboxLayout2->setObjectName(QString::fromUtf8("vboxLayout2"));
        vboxLayout3 = new QVBoxLayout();
        vboxLayout3->setSpacing(2);
        vboxLayout3->setContentsMargins(0, 0, 0, 0);
        vboxLayout3->setObjectName(QString::fromUtf8("vboxLayout3"));
        CH_Show_FDD = new QCheckBox(QEMU_Args_Widget);
        CH_Show_FDD->setObjectName(QString::fromUtf8("CH_Show_FDD"));

        vboxLayout3->addWidget(CH_Show_FDD);

        CH_Show_CD = new QCheckBox(QEMU_Args_Widget);
        CH_Show_CD->setObjectName(QString::fromUtf8("CH_Show_CD"));

        vboxLayout3->addWidget(CH_Show_CD);

        CH_Show_HDD = new QCheckBox(QEMU_Args_Widget);
        CH_Show_HDD->setObjectName(QString::fromUtf8("CH_Show_HDD"));

        vboxLayout3->addWidget(CH_Show_HDD);


        vboxLayout2->addLayout(vboxLayout3);

        line_5 = new QFrame(QEMU_Args_Widget);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);

        vboxLayout2->addWidget(line_5);

        vboxLayout4 = new QVBoxLayout();
        vboxLayout4->setSpacing(2);
        vboxLayout4->setContentsMargins(0, 0, 0, 0);
        vboxLayout4->setObjectName(QString::fromUtf8("vboxLayout4"));
        CH_Network_Cards = new QCheckBox(QEMU_Args_Widget);
        CH_Network_Cards->setObjectName(QString::fromUtf8("CH_Network_Cards"));

        vboxLayout4->addWidget(CH_Network_Cards);

        CH_Redirections = new QCheckBox(QEMU_Args_Widget);
        CH_Redirections->setObjectName(QString::fromUtf8("CH_Redirections"));

        vboxLayout4->addWidget(CH_Redirections);

        CH_TFTP_Server_Prefix = new QCheckBox(QEMU_Args_Widget);
        CH_TFTP_Server_Prefix->setObjectName(QString::fromUtf8("CH_TFTP_Server_Prefix"));

        vboxLayout4->addWidget(CH_TFTP_Server_Prefix);

        CH_SMB_Dir = new QCheckBox(QEMU_Args_Widget);
        CH_SMB_Dir->setObjectName(QString::fromUtf8("CH_SMB_Dir"));

        vboxLayout4->addWidget(CH_SMB_Dir);


        vboxLayout2->addLayout(vboxLayout4);

        line_6 = new QFrame(QEMU_Args_Widget);
        line_6->setObjectName(QString::fromUtf8("line_6"));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);

        vboxLayout2->addWidget(line_6);

        vboxLayout5 = new QVBoxLayout();
        vboxLayout5->setSpacing(2);
        vboxLayout5->setContentsMargins(0, 0, 0, 0);
        vboxLayout5->setObjectName(QString::fromUtf8("vboxLayout5"));
        CH_No_Frame = new QCheckBox(QEMU_Args_Widget);
        CH_No_Frame->setObjectName(QString::fromUtf8("CH_No_Frame"));

        vboxLayout5->addWidget(CH_No_Frame);

        CH_Alt_Grab = new QCheckBox(QEMU_Args_Widget);
        CH_Alt_Grab->setObjectName(QString::fromUtf8("CH_Alt_Grab"));

        vboxLayout5->addWidget(CH_Alt_Grab);

        CH_No_Quit = new QCheckBox(QEMU_Args_Widget);
        CH_No_Quit->setObjectName(QString::fromUtf8("CH_No_Quit"));

        vboxLayout5->addWidget(CH_No_Quit);

        CH_Portrait = new QCheckBox(QEMU_Args_Widget);
        CH_Portrait->setObjectName(QString::fromUtf8("CH_Portrait"));

        vboxLayout5->addWidget(CH_Portrait);


        vboxLayout2->addLayout(vboxLayout5);


        gridLayout9999->addLayout(vboxLayout2, 0, 4, 5, 1);

        vboxLayout6 = new QVBoxLayout();
        vboxLayout6->setSpacing(2);
        vboxLayout6->setContentsMargins(0, 0, 0, 0);
        vboxLayout6->setObjectName(QString::fromUtf8("vboxLayout6"));
        CH_Computer_Type = new QCheckBox(QEMU_Args_Widget);
        CH_Computer_Type->setObjectName(QString::fromUtf8("CH_Computer_Type"));

        vboxLayout6->addWidget(CH_Computer_Type);

        CH_Machine_Type = new QCheckBox(QEMU_Args_Widget);
        CH_Machine_Type->setObjectName(QString::fromUtf8("CH_Machine_Type"));

        vboxLayout6->addWidget(CH_Machine_Type);

        CH_CPU_Type = new QCheckBox(QEMU_Args_Widget);
        CH_CPU_Type->setObjectName(QString::fromUtf8("CH_CPU_Type"));

        vboxLayout6->addWidget(CH_CPU_Type);

        CH_Number_of_CPU = new QCheckBox(QEMU_Args_Widget);
        CH_Number_of_CPU->setObjectName(QString::fromUtf8("CH_Number_of_CPU"));

        vboxLayout6->addWidget(CH_Number_of_CPU);

        CH_Acceleration = new QCheckBox(QEMU_Args_Widget);
        CH_Acceleration->setObjectName(QString::fromUtf8("CH_Acceleration"));

        vboxLayout6->addWidget(CH_Acceleration);

        CH_Boot_Priority = new QCheckBox(QEMU_Args_Widget);
        CH_Boot_Priority->setObjectName(QString::fromUtf8("CH_Boot_Priority"));

        vboxLayout6->addWidget(CH_Boot_Priority);

        CH_Video_Card = new QCheckBox(QEMU_Args_Widget);
        CH_Video_Card->setObjectName(QString::fromUtf8("CH_Video_Card"));

        vboxLayout6->addWidget(CH_Video_Card);

        CH_Keyboard_Layout = new QCheckBox(QEMU_Args_Widget);
        CH_Keyboard_Layout->setObjectName(QString::fromUtf8("CH_Keyboard_Layout"));

        vboxLayout6->addWidget(CH_Keyboard_Layout);


        gridLayout9999->addLayout(vboxLayout6, 2, 0, 3, 1);

        vboxLayout7 = new QVBoxLayout();
        vboxLayout7->setSpacing(2);
        vboxLayout7->setContentsMargins(0, 0, 0, 0);
        vboxLayout7->setObjectName(QString::fromUtf8("vboxLayout7"));
        CH_Fullscreen = new QCheckBox(QEMU_Args_Widget);
        CH_Fullscreen->setObjectName(QString::fromUtf8("CH_Fullscreen"));

        vboxLayout7->addWidget(CH_Fullscreen);

        CH_ACPI = new QCheckBox(QEMU_Args_Widget);
        CH_ACPI->setObjectName(QString::fromUtf8("CH_ACPI"));

        vboxLayout7->addWidget(CH_ACPI);

        CH_Localtime = new QCheckBox(QEMU_Args_Widget);
        CH_Localtime->setObjectName(QString::fromUtf8("CH_Localtime"));

        vboxLayout7->addWidget(CH_Localtime);

        CH_Start_CPU = new QCheckBox(QEMU_Args_Widget);
        CH_Start_CPU->setObjectName(QString::fromUtf8("CH_Start_CPU"));

        vboxLayout7->addWidget(CH_Start_CPU);

        CH_Snapshot = new QCheckBox(QEMU_Args_Widget);
        CH_Snapshot->setObjectName(QString::fromUtf8("CH_Snapshot"));

        vboxLayout7->addWidget(CH_Snapshot);

        CH_No_Reboot = new QCheckBox(QEMU_Args_Widget);
        CH_No_Reboot->setObjectName(QString::fromUtf8("CH_No_Reboot"));

        vboxLayout7->addWidget(CH_No_Reboot);


        gridLayout9999->addLayout(vboxLayout7, 2, 2, 1, 1);

        vboxLayout8 = new QVBoxLayout();
        vboxLayout8->setSpacing(2);
        vboxLayout8->setContentsMargins(0, 0, 0, 0);
        vboxLayout8->setObjectName(QString::fromUtf8("vboxLayout8"));
        CH_Serial_Port = new QCheckBox(QEMU_Args_Widget);
        CH_Serial_Port->setObjectName(QString::fromUtf8("CH_Serial_Port"));

        vboxLayout8->addWidget(CH_Serial_Port);

        CH_Parallel_Port = new QCheckBox(QEMU_Args_Widget);
        CH_Parallel_Port->setObjectName(QString::fromUtf8("CH_Parallel_Port"));

        vboxLayout8->addWidget(CH_Parallel_Port);

        CH_USB_Port = new QCheckBox(QEMU_Args_Widget);
        CH_USB_Port->setObjectName(QString::fromUtf8("CH_USB_Port"));

        vboxLayout8->addWidget(CH_USB_Port);


        gridLayout9999->addLayout(vboxLayout8, 4, 2, 1, 1);

        vboxLayout9 = new QVBoxLayout();
        vboxLayout9->setSpacing(2);
        vboxLayout9->setContentsMargins(0, 0, 0, 0);
        vboxLayout9->setObjectName(QString::fromUtf8("vboxLayout9"));
        CH_Linux_Boot = new QCheckBox(QEMU_Args_Widget);
        CH_Linux_Boot->setObjectName(QString::fromUtf8("CH_Linux_Boot"));

        vboxLayout9->addWidget(CH_Linux_Boot);

        CH_ROM_File = new QCheckBox(QEMU_Args_Widget);
        CH_ROM_File->setObjectName(QString::fromUtf8("CH_ROM_File"));

        vboxLayout9->addWidget(CH_ROM_File);

        CH_PFlash = new QCheckBox(QEMU_Args_Widget);
        CH_PFlash->setObjectName(QString::fromUtf8("CH_PFlash"));

        vboxLayout9->addWidget(CH_PFlash);


        gridLayout9999->addLayout(vboxLayout9, 6, 0, 1, 1);

        vboxLayout10 = new QVBoxLayout();
        vboxLayout10->setSpacing(2);
        vboxLayout10->setContentsMargins(0, 0, 0, 0);
        vboxLayout10->setObjectName(QString::fromUtf8("vboxLayout10"));
        CH_MTDBlock = new QCheckBox(QEMU_Args_Widget);
        CH_MTDBlock->setObjectName(QString::fromUtf8("CH_MTDBlock"));

        vboxLayout10->addWidget(CH_MTDBlock);

        CH_SD_Image = new QCheckBox(QEMU_Args_Widget);
        CH_SD_Image->setObjectName(QString::fromUtf8("CH_SD_Image"));

        vboxLayout10->addWidget(CH_SD_Image);

        CH_GDB_Port = new QCheckBox(QEMU_Args_Widget);
        CH_GDB_Port->setObjectName(QString::fromUtf8("CH_GDB_Port"));

        vboxLayout10->addWidget(CH_GDB_Port);


        gridLayout9999->addLayout(vboxLayout10, 6, 2, 1, 1);

        vboxLayout11 = new QVBoxLayout();
        vboxLayout11->setSpacing(2);
        vboxLayout11->setContentsMargins(0, 0, 0, 0);
        vboxLayout11->setObjectName(QString::fromUtf8("vboxLayout11"));
        CH_Win2K_Hack = new QCheckBox(QEMU_Args_Widget);
        CH_Win2K_Hack->setObjectName(QString::fromUtf8("CH_Win2K_Hack"));

        vboxLayout11->addWidget(CH_Win2K_Hack);

        CH_QEMU_Log = new QCheckBox(QEMU_Args_Widget);
        CH_QEMU_Log->setObjectName(QString::fromUtf8("CH_QEMU_Log"));

        vboxLayout11->addWidget(CH_QEMU_Log);

        CH_Check_Boot_on_FDD = new QCheckBox(QEMU_Args_Widget);
        CH_Check_Boot_on_FDD->setObjectName(QString::fromUtf8("CH_Check_Boot_on_FDD"));

        vboxLayout11->addWidget(CH_Check_Boot_on_FDD);


        gridLayout9999->addLayout(vboxLayout11, 6, 4, 1, 1);

        line_9 = new QFrame(QEMU_Args_Widget);
        line_9->setObjectName(QString::fromUtf8("line_9"));
        line_9->setFrameShape(QFrame::HLine);
        line_9->setFrameShadow(QFrame::Sunken);

        gridLayout9999->addWidget(line_9, 1, 0, 1, 1);

        line_3 = new QFrame(QEMU_Args_Widget);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        gridLayout9999->addWidget(line_3, 1, 2, 1, 1);

        line_8 = new QFrame(QEMU_Args_Widget);
        line_8->setObjectName(QString::fromUtf8("line_8"));
        line_8->setFrameShape(QFrame::HLine);
        line_8->setFrameShadow(QFrame::Sunken);

        gridLayout9999->addWidget(line_8, 3, 2, 1, 1);

        line_2 = new QFrame(QEMU_Args_Widget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout9999->addWidget(line_2, 0, 1, 7, 1);

        line_4 = new QFrame(QEMU_Args_Widget);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setFrameShape(QFrame::VLine);
        line_4->setFrameShadow(QFrame::Sunken);

        gridLayout9999->addWidget(line_4, 0, 3, 7, 1);

        line = new QFrame(QEMU_Args_Widget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout9999->addWidget(line, 5, 0, 1, 1);

        line_7 = new QFrame(QEMU_Args_Widget);
        line_7->setObjectName(QString::fromUtf8("line_7"));
        line_7->setFrameShape(QFrame::HLine);
        line_7->setFrameShadow(QFrame::Sunken);

        gridLayout9999->addWidget(line_7, 5, 2, 1, 1);

        line_12 = new QFrame(QEMU_Args_Widget);
        line_12->setObjectName(QString::fromUtf8("line_12"));
        line_12->setFrameShape(QFrame::HLine);
        line_12->setFrameShadow(QFrame::Sunken);

        gridLayout9999->addWidget(line_12, 5, 4, 1, 1);


        gridLayout_2->addWidget(QEMU_Args_Widget, 2, 0, 1, 1);

        All_Tabs->addTab(Tab_Tab_info, QString());
        Tab_Other = new QWidget();
        Tab_Other->setObjectName(QString::fromUtf8("Tab_Other"));
        gridLayout_7 = new QGridLayout(Tab_Other);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(6, 6, 6, 6);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        GB_NetCard_MAC = new QGroupBox(Tab_Other);
        GB_NetCard_MAC->setObjectName(QString::fromUtf8("GB_NetCard_MAC"));
        sizePolicy2.setHeightForWidth(GB_NetCard_MAC->sizePolicy().hasHeightForWidth());
        GB_NetCard_MAC->setSizePolicy(sizePolicy2);
        GB_NetCard_MAC->setFlat(true);
        gridLayout_4 = new QGridLayout(GB_NetCard_MAC);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(6, 6, 6, 6);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        RB_MAC_Random = new QRadioButton(GB_NetCard_MAC);
        RB_MAC_Random->setObjectName(QString::fromUtf8("RB_MAC_Random"));

        gridLayout_4->addWidget(RB_MAC_Random, 0, 0, 1, 1);

        RB_MAC_QEMU = new QRadioButton(GB_NetCard_MAC);
        RB_MAC_QEMU->setObjectName(QString::fromUtf8("RB_MAC_QEMU"));

        gridLayout_4->addWidget(RB_MAC_QEMU, 1, 0, 1, 1);

        RB_MAC_Valid = new QRadioButton(GB_NetCard_MAC);
        RB_MAC_Valid->setObjectName(QString::fromUtf8("RB_MAC_Valid"));
        RB_MAC_Valid->setChecked(true);

        gridLayout_4->addWidget(RB_MAC_Valid, 2, 0, 1, 1);


        gridLayout_7->addWidget(GB_NetCard_MAC, 0, 0, 1, 1);

        GB_Audio_Default = new QGroupBox(Tab_Other);
        GB_Audio_Default->setObjectName(QString::fromUtf8("GB_Audio_Default"));
        sizePolicy2.setHeightForWidth(GB_Audio_Default->sizePolicy().hasHeightForWidth());
        GB_Audio_Default->setSizePolicy(sizePolicy2);
        GB_Audio_Default->setFlat(true);
        GB_Audio_Default->setCheckable(true);
        GB_Audio_Default->setChecked(false);
        gridLayout_6 = new QGridLayout(GB_Audio_Default);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(6, 6, 6, 6);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        Label_Host_Sound_System = new QLabel(GB_Audio_Default);
        Label_Host_Sound_System->setObjectName(QString::fromUtf8("Label_Host_Sound_System"));
        sizePolicy.setHeightForWidth(Label_Host_Sound_System->sizePolicy().hasHeightForWidth());
        Label_Host_Sound_System->setSizePolicy(sizePolicy);

        gridLayout_6->addWidget(Label_Host_Sound_System, 0, 0, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_3, 0, 1, 1, 1);

        CB_Host_Sound_System = new QComboBox(GB_Audio_Default);
        CB_Host_Sound_System->addItem(QString());
        CB_Host_Sound_System->addItem(QString());
        CB_Host_Sound_System->addItem(QString());
        CB_Host_Sound_System->addItem(QString());
        CB_Host_Sound_System->addItem(QString());
        CB_Host_Sound_System->setObjectName(QString::fromUtf8("CB_Host_Sound_System"));
        CB_Host_Sound_System->setMaxCount(32);

        gridLayout_6->addWidget(CB_Host_Sound_System, 0, 2, 1, 1);


        gridLayout_7->addWidget(GB_Audio_Default, 1, 0, 1, 1);

        GB_AQEMU_Log = new QGroupBox(Tab_Other);
        GB_AQEMU_Log->setObjectName(QString::fromUtf8("GB_AQEMU_Log"));
        gridLayout2 = new QGridLayout(GB_AQEMU_Log);
        gridLayout2->setSpacing(4);
        gridLayout2->setContentsMargins(6, 6, 6, 6);
        gridLayout2->setObjectName(QString::fromUtf8("gridLayout2"));
        hboxLayout4 = new QHBoxLayout();
        hboxLayout4->setSpacing(6);
        hboxLayout4->setContentsMargins(0, 0, 0, 0);
        hboxLayout4->setObjectName(QString::fromUtf8("hboxLayout4"));
        Label_Save_Log_In = new QLabel(GB_AQEMU_Log);
        Label_Save_Log_In->setObjectName(QString::fromUtf8("Label_Save_Log_In"));
        sizePolicy.setHeightForWidth(Label_Save_Log_In->sizePolicy().hasHeightForWidth());
        Label_Save_Log_In->setSizePolicy(sizePolicy);

        hboxLayout4->addWidget(Label_Save_Log_In);

        line_13 = new QFrame(GB_AQEMU_Log);
        line_13->setObjectName(QString::fromUtf8("line_13"));
        line_13->setFrameShape(QFrame::HLine);
        line_13->setFrameShadow(QFrame::Sunken);

        hboxLayout4->addWidget(line_13);


        gridLayout2->addLayout(hboxLayout4, 0, 0, 1, 1);

        hboxLayout5 = new QHBoxLayout();
        hboxLayout5->setSpacing(6);
        hboxLayout5->setContentsMargins(0, 0, 0, 0);
        hboxLayout5->setObjectName(QString::fromUtf8("hboxLayout5"));
        CH_Log_Save_in_File = new QCheckBox(GB_AQEMU_Log);
        CH_Log_Save_in_File->setObjectName(QString::fromUtf8("CH_Log_Save_in_File"));

        hboxLayout5->addWidget(CH_Log_Save_in_File);

        spacerItem2 = new QSpacerItem(13, 15, QSizePolicy::Fixed, QSizePolicy::Minimum);

        hboxLayout5->addItem(spacerItem2);

        CH_Log_Print_in_STDIO = new QCheckBox(GB_AQEMU_Log);
        CH_Log_Print_in_STDIO->setObjectName(QString::fromUtf8("CH_Log_Print_in_STDIO"));

        hboxLayout5->addWidget(CH_Log_Print_in_STDIO);

        spacerItem3 = new QSpacerItem(262, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout5->addItem(spacerItem3);


        gridLayout2->addLayout(hboxLayout5, 1, 0, 1, 1);

        hboxLayout6 = new QHBoxLayout();
        hboxLayout6->setSpacing(6);
        hboxLayout6->setContentsMargins(0, 0, 0, 0);
        hboxLayout6->setObjectName(QString::fromUtf8("hboxLayout6"));
        Label_Log_Messages = new QLabel(GB_AQEMU_Log);
        Label_Log_Messages->setObjectName(QString::fromUtf8("Label_Log_Messages"));
        sizePolicy.setHeightForWidth(Label_Log_Messages->sizePolicy().hasHeightForWidth());
        Label_Log_Messages->setSizePolicy(sizePolicy);

        hboxLayout6->addWidget(Label_Log_Messages);

        line_14 = new QFrame(GB_AQEMU_Log);
        line_14->setObjectName(QString::fromUtf8("line_14"));
        line_14->setFrameShape(QFrame::HLine);
        line_14->setFrameShadow(QFrame::Sunken);

        hboxLayout6->addWidget(line_14);


        gridLayout2->addLayout(hboxLayout6, 2, 0, 1, 1);

        hboxLayout7 = new QHBoxLayout();
        hboxLayout7->setSpacing(6);
        hboxLayout7->setContentsMargins(0, 0, 0, 0);
        hboxLayout7->setObjectName(QString::fromUtf8("hboxLayout7"));
        CH_Log_Debug = new QCheckBox(GB_AQEMU_Log);
        CH_Log_Debug->setObjectName(QString::fromUtf8("CH_Log_Debug"));
        CH_Log_Debug->setChecked(true);

        hboxLayout7->addWidget(CH_Log_Debug);

        spacerItem4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout7->addItem(spacerItem4);

        CH_Log_Warning = new QCheckBox(GB_AQEMU_Log);
        CH_Log_Warning->setObjectName(QString::fromUtf8("CH_Log_Warning"));
        CH_Log_Warning->setChecked(true);

        hboxLayout7->addWidget(CH_Log_Warning);

        spacerItem5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout7->addItem(spacerItem5);

        CH_Log_Error = new QCheckBox(GB_AQEMU_Log);
        CH_Log_Error->setObjectName(QString::fromUtf8("CH_Log_Error"));
        CH_Log_Error->setChecked(true);

        hboxLayout7->addWidget(CH_Log_Error);


        gridLayout2->addLayout(hboxLayout7, 3, 0, 1, 1);

        hboxLayout8 = new QHBoxLayout();
        hboxLayout8->setSpacing(6);
        hboxLayout8->setContentsMargins(0, 0, 0, 0);
        hboxLayout8->setObjectName(QString::fromUtf8("hboxLayout8"));
        Label_Log_Path = new QLabel(GB_AQEMU_Log);
        Label_Log_Path->setObjectName(QString::fromUtf8("Label_Log_Path"));

        hboxLayout8->addWidget(Label_Log_Path);

        Edit_Log_Path = new QLineEdit(GB_AQEMU_Log);
        Edit_Log_Path->setObjectName(QString::fromUtf8("Edit_Log_Path"));

        hboxLayout8->addWidget(Edit_Log_Path);

        TB_Log_File = new QToolButton(GB_AQEMU_Log);
        TB_Log_File->setObjectName(QString::fromUtf8("TB_Log_File"));

        hboxLayout8->addWidget(TB_Log_File);


        gridLayout2->addLayout(hboxLayout8, 4, 0, 1, 1);


        gridLayout_7->addWidget(GB_AQEMU_Log, 2, 0, 1, 1);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        Label_Recent_Count = new QLabel(Tab_Other);
        Label_Recent_Count->setObjectName(QString::fromUtf8("Label_Recent_Count"));

        gridLayout_3->addWidget(Label_Recent_Count, 0, 0, 1, 1);

        SB_Recent_Count = new QSpinBox(Tab_Other);
        SB_Recent_Count->setObjectName(QString::fromUtf8("SB_Recent_Count"));
        SB_Recent_Count->setMinimum(1);
        SB_Recent_Count->setMaximum(10);
        SB_Recent_Count->setValue(5);

        gridLayout_3->addWidget(SB_Recent_Count, 0, 1, 1, 1);

        Label_First_VNC_Port = new QLabel(Tab_Other);
        Label_First_VNC_Port->setObjectName(QString::fromUtf8("Label_First_VNC_Port"));

        gridLayout_3->addWidget(Label_First_VNC_Port, 1, 0, 1, 1);

        SB_First_VNC_Port = new QSpinBox(Tab_Other);
        SB_First_VNC_Port->setObjectName(QString::fromUtf8("SB_First_VNC_Port"));
        SB_First_VNC_Port->setMinimum(5900);
        SB_First_VNC_Port->setMaximum(59636);
        SB_First_VNC_Port->setValue(6000);

        gridLayout_3->addWidget(SB_First_VNC_Port, 1, 1, 1, 1);


        gridLayout_7->addLayout(gridLayout_3, 3, 0, 1, 1);

        All_Tabs->addTab(Tab_Other, QString());

        gridLayout_5->addWidget(All_Tabs, 0, 0, 1, 1);

#ifndef QT_NO_SHORTCUT
        Label_Before_Start->setBuddy(Edit_Before_Start_Command);
        Label_After_Stop->setBuddy(Edit_After_Stop_Command);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(All_Tabs, CH_Check_Version_on_Start);
        QWidget::setTabOrder(CH_Check_Version_on_Start, RB_QEMU_Version_Auto);
        QWidget::setTabOrder(RB_QEMU_Version_Auto, RB_QEMU_Version_Manual);
        QWidget::setTabOrder(RB_QEMU_Version_Manual, CB_QEMU_Version);
        QWidget::setTabOrder(CB_QEMU_Version, Edit_Before_Start_Command);
        QWidget::setTabOrder(Edit_Before_Start_Command, TB_Browse_Before);
        QWidget::setTabOrder(TB_Browse_Before, Edit_After_Stop_Command);
        QWidget::setTabOrder(Edit_After_Stop_Command, TB_Browse_After);
        QWidget::setTabOrder(TB_Browse_After, CH_QEMU_Log_out_asm);
        QWidget::setTabOrder(CH_QEMU_Log_out_asm, CH_QEMU_Log_in_asm);
        QWidget::setTabOrder(CH_QEMU_Log_in_asm, CH_QEMU_Log_pcall);
        QWidget::setTabOrder(CH_QEMU_Log_pcall, CH_QEMU_Log_cpu);
        QWidget::setTabOrder(CH_QEMU_Log_cpu, CH_QEMU_Log_op_opt);
        QWidget::setTabOrder(CH_QEMU_Log_op_opt, CH_QEMU_Log_int);
        QWidget::setTabOrder(CH_QEMU_Log_int, CH_QEMU_Log_op);
        QWidget::setTabOrder(CH_QEMU_Log_op, CH_QEMU_Log_exec);
        QWidget::setTabOrder(CH_QEMU_Log_exec, RB_NetCard_Settings_Default);
        QWidget::setTabOrder(RB_NetCard_Settings_Default, RB_Net_Card_Settings_Old);
        QWidget::setTabOrder(RB_Net_Card_Settings_Old, Edit_QEMU_IMG_Path);
        QWidget::setTabOrder(Edit_QEMU_IMG_Path, TB_QEMU_IMG_Browse);
        QWidget::setTabOrder(TB_QEMU_IMG_Browse, Button_OK);
        QWidget::setTabOrder(Button_OK, Button_Cancel);
        QWidget::setTabOrder(Button_Cancel, CH_Show_Tab_Info);
        QWidget::setTabOrder(CH_Show_Tab_Info, CH_Show_QEMU_Args);
        QWidget::setTabOrder(CH_Show_QEMU_Args, CH_Show_Screenshot_in_Save_Mode);
        QWidget::setTabOrder(CH_Show_Screenshot_in_Save_Mode, CH_Machine_Details);
        QWidget::setTabOrder(CH_Machine_Details, CH_Machine_Name);
        QWidget::setTabOrder(CH_Machine_Name, CH_Computer_Type);
        QWidget::setTabOrder(CH_Computer_Type, CH_Machine_Type);
        QWidget::setTabOrder(CH_Machine_Type, CH_CPU_Type);
        QWidget::setTabOrder(CH_CPU_Type, CH_Number_of_CPU);
        QWidget::setTabOrder(CH_Number_of_CPU, CH_Acceleration);
        QWidget::setTabOrder(CH_Acceleration, CH_Boot_Priority);
        QWidget::setTabOrder(CH_Boot_Priority, CH_Video_Card);
        QWidget::setTabOrder(CH_Video_Card, CH_Keyboard_Layout);
        QWidget::setTabOrder(CH_Keyboard_Layout, CH_Linux_Boot);
        QWidget::setTabOrder(CH_Linux_Boot, CH_ROM_File);
        QWidget::setTabOrder(CH_ROM_File, CH_PFlash);
        QWidget::setTabOrder(CH_PFlash, CH_Memory_Size);
        QWidget::setTabOrder(CH_Memory_Size, CH_Use_Sound);
        QWidget::setTabOrder(CH_Use_Sound, CH_Fullscreen);
        QWidget::setTabOrder(CH_Fullscreen, CH_ACPI);
        QWidget::setTabOrder(CH_ACPI, CH_Localtime);
        QWidget::setTabOrder(CH_Localtime, CH_Start_CPU);
        QWidget::setTabOrder(CH_Start_CPU, CH_Snapshot);
        QWidget::setTabOrder(CH_Snapshot, CH_No_Reboot);
        QWidget::setTabOrder(CH_No_Reboot, CH_Serial_Port);
        QWidget::setTabOrder(CH_Serial_Port, CH_Parallel_Port);
        QWidget::setTabOrder(CH_Parallel_Port, CH_USB_Port);
        QWidget::setTabOrder(CH_USB_Port, CH_MTDBlock);
        QWidget::setTabOrder(CH_MTDBlock, CH_SD_Image);
        QWidget::setTabOrder(CH_SD_Image, CH_GDB_Port);
        QWidget::setTabOrder(CH_GDB_Port, CH_Show_FDD);
        QWidget::setTabOrder(CH_Show_FDD, CH_Show_CD);
        QWidget::setTabOrder(CH_Show_CD, CH_Show_HDD);
        QWidget::setTabOrder(CH_Show_HDD, CH_Network_Cards);
        QWidget::setTabOrder(CH_Network_Cards, CH_Redirections);
        QWidget::setTabOrder(CH_Redirections, CH_TFTP_Server_Prefix);
        QWidget::setTabOrder(CH_TFTP_Server_Prefix, CH_SMB_Dir);
        QWidget::setTabOrder(CH_SMB_Dir, CH_No_Frame);
        QWidget::setTabOrder(CH_No_Frame, CH_Alt_Grab);
        QWidget::setTabOrder(CH_Alt_Grab, CH_No_Quit);
        QWidget::setTabOrder(CH_No_Quit, CH_Portrait);
        QWidget::setTabOrder(CH_Portrait, CH_Win2K_Hack);
        QWidget::setTabOrder(CH_Win2K_Hack, CH_QEMU_Log);
        QWidget::setTabOrder(CH_QEMU_Log, CH_Check_Boot_on_FDD);
        QWidget::setTabOrder(CH_Check_Boot_on_FDD, RB_MAC_Random);
        QWidget::setTabOrder(RB_MAC_Random, RB_MAC_QEMU);
        QWidget::setTabOrder(RB_MAC_QEMU, RB_MAC_Valid);
        QWidget::setTabOrder(RB_MAC_Valid, GB_Audio_Default);
        QWidget::setTabOrder(GB_Audio_Default, CB_Host_Sound_System);
        QWidget::setTabOrder(CB_Host_Sound_System, CH_Log_Save_in_File);
        QWidget::setTabOrder(CH_Log_Save_in_File, CH_Log_Print_in_STDIO);
        QWidget::setTabOrder(CH_Log_Print_in_STDIO, CH_Log_Debug);
        QWidget::setTabOrder(CH_Log_Debug, CH_Log_Warning);
        QWidget::setTabOrder(CH_Log_Warning, CH_Log_Error);
        QWidget::setTabOrder(CH_Log_Error, Edit_Log_Path);
        QWidget::setTabOrder(Edit_Log_Path, TB_Log_File);
        QWidget::setTabOrder(TB_Log_File, SB_Recent_Count);
        QWidget::setTabOrder(SB_Recent_Count, SB_First_VNC_Port);

        retranslateUi(Advanced_Settings_Window);
        QObject::connect(Button_Cancel, SIGNAL(clicked()), Advanced_Settings_Window, SLOT(reject()));
        QObject::connect(RB_QEMU_Version_Manual, SIGNAL(toggled(bool)), CB_QEMU_Version, SLOT(setEnabled(bool)));
        QObject::connect(RB_QEMU_Version_Manual, SIGNAL(toggled(bool)), Label_Compatibility, SLOT(setEnabled(bool)));
        QObject::connect(CH_Show_Tab_Info, SIGNAL(toggled(bool)), QEMU_Args_Widget, SLOT(setEnabled(bool)));
        QObject::connect(CH_Show_Tab_Info, SIGNAL(toggled(bool)), CH_Show_QEMU_Args, SLOT(setEnabled(bool)));
        QObject::connect(CH_Show_Tab_Info, SIGNAL(toggled(bool)), CH_Show_Screenshot_in_Save_Mode, SLOT(setEnabled(bool)));

        All_Tabs->setCurrentIndex(0);
        CB_QEMU_Version->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Advanced_Settings_Window);
    } // setupUi

    void retranslateUi(QDialog *Advanced_Settings_Window)
    {
        Advanced_Settings_Window->setWindowTitle(QApplication::translate("Advanced_Settings_Window", "Advanced Settings", nullptr));
        Button_OK->setText(QApplication::translate("Advanced_Settings_Window", "&OK", nullptr));
        Button_Cancel->setText(QApplication::translate("Advanced_Settings_Window", "&Cancel", nullptr));
        GB_QEMU_Version->setTitle(QApplication::translate("Advanced_Settings_Window", "QEMU Version", nullptr));
        CH_Check_Version_on_Start->setText(QApplication::translate("Advanced_Settings_Window", "Check QEMU Version Always Start AQEMU", nullptr));
        CH_Check_KVM->setText(QApplication::translate("Advanced_Settings_Window", "Check Availability KVM Always Start AQEMU", nullptr));
        Label_Compatibility_Mode->setText(QApplication::translate("Advanced_Settings_Window", "Compatibility Mode", nullptr));
        RB_QEMU_Version_Auto->setText(QApplication::translate("Advanced_Settings_Window", "Auto Select", nullptr));
        RB_QEMU_Version_Manual->setText(QApplication::translate("Advanced_Settings_Window", "Force Version", nullptr));
        Label_Compatibility->setText(QApplication::translate("Advanced_Settings_Window", "Use Compatibility for:", nullptr));
        CB_QEMU_Version->setItemText(0, QApplication::translate("Advanced_Settings_Window", "QEMU 0.9.0", nullptr));
        CB_QEMU_Version->setItemText(1, QApplication::translate("Advanced_Settings_Window", "QEMU 0.9.1 and KVM", nullptr));

        GB_Start_Stop->setTitle(QApplication::translate("Advanced_Settings_Window", "Start and Stop QEMU", nullptr));
        Label_Before_Start->setText(QApplication::translate("Advanced_Settings_Window", "Execute Before Start QEMU:", nullptr));
        TB_Browse_Before->setText(QApplication::translate("Advanced_Settings_Window", "...", nullptr));
        Label_After_Stop->setText(QApplication::translate("Advanced_Settings_Window", "Execute After Stop QEMU:", nullptr));
        TB_Browse_After->setText(QApplication::translate("Advanced_Settings_Window", "...", nullptr));
        GB_QEMU_Log->setTitle(QApplication::translate("Advanced_Settings_Window", "Save to QEMU Log", nullptr));
        CH_QEMU_Log_exec->setText(QApplication::translate("Advanced_Settings_Window", "exec", nullptr));
        CH_QEMU_Log_op->setText(QApplication::translate("Advanced_Settings_Window", "op", nullptr));
        CH_QEMU_Log_int->setText(QApplication::translate("Advanced_Settings_Window", "int", nullptr));
        CH_QEMU_Log_op_opt->setText(QApplication::translate("Advanced_Settings_Window", "op_opt", nullptr));
        CH_QEMU_Log_cpu->setText(QApplication::translate("Advanced_Settings_Window", "cpu", nullptr));
        CH_QEMU_Log_pcall->setText(QApplication::translate("Advanced_Settings_Window", "pcall", nullptr));
        CH_QEMU_Log_in_asm->setText(QApplication::translate("Advanced_Settings_Window", "in_asm", nullptr));
        CH_QEMU_Log_out_asm->setText(QApplication::translate("Advanced_Settings_Window", "out_asm", nullptr));
        GB_NetCard_Settings_Mode->setTitle(QApplication::translate("Advanced_Settings_Window", "Network Card Settings Mode", nullptr));
        RB_NetCard_Settings_Default->setText(QApplication::translate("Advanced_Settings_Window", "Default Mode (Incomplete)", nullptr));
        RB_Net_Card_Settings_Old->setText(QApplication::translate("Advanced_Settings_Window", "Advanced Mode", nullptr));
        GB_QEMU_IMG_Binary_Path->setTitle(QApplication::translate("Advanced_Settings_Window", "QEMU-IMG Binary Path", nullptr));
        TB_QEMU_IMG_Browse->setText(QApplication::translate("Advanced_Settings_Window", "...", nullptr));
        All_Tabs->setTabText(All_Tabs->indexOf(Tab_General), QApplication::translate("Advanced_Settings_Window", "General", nullptr));
        CH_Show_Tab_Info->setText(QApplication::translate("Advanced_Settings_Window", "Show Tab Info", nullptr));
        CH_Show_QEMU_Args->setText(QApplication::translate("Advanced_Settings_Window", "Show QEMU Arguments", nullptr));
        CH_Show_Screenshot_in_Save_Mode->setText(QApplication::translate("Advanced_Settings_Window", "Show Screenshot in Save Mode", nullptr));
        CH_Machine_Details->setText(QApplication::translate("Advanced_Settings_Window", "Machine Details", nullptr));
        CH_Machine_Name->setText(QApplication::translate("Advanced_Settings_Window", "Machine Name", nullptr));
        CH_Memory_Size->setText(QApplication::translate("Advanced_Settings_Window", "Memory Size", nullptr));
        CH_Use_Sound->setText(QApplication::translate("Advanced_Settings_Window", "Use Sound", nullptr));
        CH_Show_FDD->setText(QApplication::translate("Advanced_Settings_Window", "Show Floppy", nullptr));
        CH_Show_CD->setText(QApplication::translate("Advanced_Settings_Window", "Show CD-ROM", nullptr));
        CH_Show_HDD->setText(QApplication::translate("Advanced_Settings_Window", "Show HDD", nullptr));
        CH_Network_Cards->setText(QApplication::translate("Advanced_Settings_Window", "Network Cards", nullptr));
        CH_Redirections->setText(QApplication::translate("Advanced_Settings_Window", "Redirections", nullptr));
        CH_TFTP_Server_Prefix->setText(QApplication::translate("Advanced_Settings_Window", "TFTP Server Prefix", nullptr));
        CH_SMB_Dir->setText(QApplication::translate("Advanced_Settings_Window", "SMB Directory", nullptr));
        CH_No_Frame->setText(QApplication::translate("Advanced_Settings_Window", "No Frame", nullptr));
        CH_Alt_Grab->setText(QApplication::translate("Advanced_Settings_Window", "Alt Grab", nullptr));
        CH_No_Quit->setText(QApplication::translate("Advanced_Settings_Window", "No Quit", nullptr));
        CH_Portrait->setText(QApplication::translate("Advanced_Settings_Window", "Portrait", nullptr));
        CH_Computer_Type->setText(QApplication::translate("Advanced_Settings_Window", "Computer Type", nullptr));
        CH_Machine_Type->setText(QApplication::translate("Advanced_Settings_Window", "Machine Type", nullptr));
        CH_CPU_Type->setText(QApplication::translate("Advanced_Settings_Window", "CPU Type", nullptr));
        CH_Number_of_CPU->setText(QApplication::translate("Advanced_Settings_Window", "Number of CPU", nullptr));
        CH_Acceleration->setText(QApplication::translate("Advanced_Settings_Window", "Acceleration", nullptr));
        CH_Boot_Priority->setText(QApplication::translate("Advanced_Settings_Window", "Boot Priority", nullptr));
        CH_Video_Card->setText(QApplication::translate("Advanced_Settings_Window", "Video Card", nullptr));
        CH_Keyboard_Layout->setText(QApplication::translate("Advanced_Settings_Window", "Keyboard Layout", nullptr));
        CH_Fullscreen->setText(QApplication::translate("Advanced_Settings_Window", "Fullscreen Mode", nullptr));
        CH_ACPI->setText(QApplication::translate("Advanced_Settings_Window", "Enable ACPI", nullptr));
        CH_Localtime->setText(QApplication::translate("Advanced_Settings_Window", "Use Local Time", nullptr));
        CH_Start_CPU->setText(QApplication::translate("Advanced_Settings_Window", "Start CPU at Startup", nullptr));
        CH_Snapshot->setText(QApplication::translate("Advanced_Settings_Window", "Snapshot Mode", nullptr));
        CH_No_Reboot->setText(QApplication::translate("Advanced_Settings_Window", "No Reboot", nullptr));
        CH_Serial_Port->setText(QApplication::translate("Advanced_Settings_Window", "Serial Port", nullptr));
        CH_Parallel_Port->setText(QApplication::translate("Advanced_Settings_Window", "Parallel Port", nullptr));
        CH_USB_Port->setText(QApplication::translate("Advanced_Settings_Window", "USB Ports", nullptr));
        CH_Linux_Boot->setText(QApplication::translate("Advanced_Settings_Window", "Use Linux Boot", nullptr));
        CH_ROM_File->setText(QApplication::translate("Advanced_Settings_Window", "ROM File", nullptr));
        CH_PFlash->setText(QApplication::translate("Advanced_Settings_Window", "Parallel Flash Image", nullptr));
        CH_MTDBlock->setText(QApplication::translate("Advanced_Settings_Window", "Flash Image", nullptr));
        CH_SD_Image->setText(QApplication::translate("Advanced_Settings_Window", "SD Image", nullptr));
        CH_GDB_Port->setText(QApplication::translate("Advanced_Settings_Window", "GDB Port", nullptr));
        CH_Win2K_Hack->setText(QApplication::translate("Advanced_Settings_Window", "Windows 2K Hack", nullptr));
        CH_QEMU_Log->setText(QApplication::translate("Advanced_Settings_Window", "Use QEMU Log", nullptr));
        CH_Check_Boot_on_FDD->setText(QApplication::translate("Advanced_Settings_Window", "Check Boot Sector on FDD", nullptr));
        All_Tabs->setTabText(All_Tabs->indexOf(Tab_Tab_info), QApplication::translate("Advanced_Settings_Window", "Information in Info Tab", nullptr));
        GB_NetCard_MAC->setTitle(QApplication::translate("Advanced_Settings_Window", "VM Network Card MAC Address", nullptr));
        RB_MAC_Random->setText(QApplication::translate("Advanced_Settings_Window", "Random MAC Address", nullptr));
        RB_MAC_QEMU->setText(QApplication::translate("Advanced_Settings_Window", "QEMU Segment MAC Address (52:54:00:XX:XX:XX)", nullptr));
        RB_MAC_Valid->setText(QApplication::translate("Advanced_Settings_Window", "Valid MAC Address (Individualized For Each Model of Network Card)", nullptr));
        GB_Audio_Default->setTitle(QApplication::translate("Advanced_Settings_Window", "Use Not Default Audio Driver", nullptr));
        Label_Host_Sound_System->setText(QApplication::translate("Advanced_Settings_Window", "Host Sound System:", nullptr));
        CB_Host_Sound_System->setItemText(0, QApplication::translate("Advanced_Settings_Window", "alsa", nullptr));
        CB_Host_Sound_System->setItemText(1, QApplication::translate("Advanced_Settings_Window", "oss", nullptr));
        CB_Host_Sound_System->setItemText(2, QApplication::translate("Advanced_Settings_Window", "sdl", nullptr));
        CB_Host_Sound_System->setItemText(3, QApplication::translate("Advanced_Settings_Window", "wav", nullptr));
        CB_Host_Sound_System->setItemText(4, QApplication::translate("Advanced_Settings_Window", "none", nullptr));

        GB_AQEMU_Log->setTitle(QApplication::translate("Advanced_Settings_Window", "AQEMU Logging", nullptr));
        Label_Save_Log_In->setText(QApplication::translate("Advanced_Settings_Window", "Write Log In", nullptr));
        CH_Log_Save_in_File->setText(QApplication::translate("Advanced_Settings_Window", "Save in File", nullptr));
        CH_Log_Print_in_STDIO->setText(QApplication::translate("Advanced_Settings_Window", "Print in STDOUT", nullptr));
        Label_Log_Messages->setText(QApplication::translate("Advanced_Settings_Window", "Log Messages", nullptr));
        CH_Log_Debug->setText(QApplication::translate("Advanced_Settings_Window", "Debug Messages", nullptr));
        CH_Log_Warning->setText(QApplication::translate("Advanced_Settings_Window", "Warning Messages", nullptr));
        CH_Log_Error->setText(QApplication::translate("Advanced_Settings_Window", "Error Messages", nullptr));
        Label_Log_Path->setText(QApplication::translate("Advanced_Settings_Window", "Log Path:", nullptr));
        Edit_Log_Path->setText(QString());
        TB_Log_File->setText(QApplication::translate("Advanced_Settings_Window", "...", nullptr));
        Label_Recent_Count->setText(QApplication::translate("Advanced_Settings_Window", "Recent CD-ROM Images Count", nullptr));
        Label_First_VNC_Port->setText(QApplication::translate("Advanced_Settings_Window", "First VNC Port for Embedded Display", nullptr));
        All_Tabs->setTabText(All_Tabs->indexOf(Tab_Other), QApplication::translate("Advanced_Settings_Window", "Other", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Advanced_Settings_Window: public Ui_Advanced_Settings_Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADVANCED_SETTINGS_WINDOW_H
