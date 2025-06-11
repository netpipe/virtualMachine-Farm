/********************************************************************************
** Form generated from reading UI file 'VM_Wizard_Window.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VM_WIZARD_WINDOW_H
#define UI_VM_WIZARD_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VM_Wizard_Window
{
public:
    QGridLayout *gridLayout;
    QStackedWidget *Wizard_Pages;
    QWidget *Welcome_Page;
    QGridLayout *gridLayout1;
    QLabel *Label_Welcome_Text;
    QSpacerItem *spacerItem;
    QWidget *Wizard_Mode_Page;
    QGridLayout *gridLayout2;
    QSpacerItem *spacerItem1;
    QGroupBox *GB_Wizard_Mode;
    QGridLayout *gridLayout3;
    QRadioButton *RB_Custom;
    QLabel *Label_Custom_Mode_Info;
    QLabel *Label_Typical_Mode_Info;
    QRadioButton *RB_Typical;
    QLabel *Label_Confiration_Mode;
    QWidget *Template_Page;
    QGridLayout *gridLayout4;
    QComboBox *CB_OS_Type;
    QLabel *Label_OS_Type;
    QLabel *Label_Computer_Type;
    QLabel *Label_Relese_Date;
    QComboBox *CB_Relese_Date;
    QComboBox *CB_Computer_Type;
    QSpacerItem *spacerItem2;
    QHBoxLayout *hboxLayout;
    QRadioButton *RB_Generate_VM;
    QFrame *line_3;
    QHBoxLayout *hboxLayout1;
    QRadioButton *RB_VM_Template;
    QFrame *line;
    QLabel *Label_Template;
    QWidget *General_Settings_Page;
    QGridLayout *gridLayout5;
    QGroupBox *GB_CPU_Type;
    QGridLayout *gridLayout6;
    QComboBox *CB_CPU_Type;
    QLabel *Label_CPU_Type;
    QGroupBox *GB_VM_Name;
    QVBoxLayout *vboxLayout;
    QLabel *Label_VM_Name;
    QLineEdit *Edit_VM_Name;
    QSpacerItem *spacerItem3;
    QWidget *Memory_Page;
    QGridLayout *gridLayout7;
    QSpacerItem *spacerItem4;
    QGroupBox *GB_Memory;
    QGridLayout *gridLayout8;
    QLabel *Label_Memory_Size;
    QHBoxLayout *hboxLayout2;
    QLabel *label_min_mem;
    QSpacerItem *spacerItem5;
    QLabel *label_max_mem;
    QCheckBox *Check_Host_Mem;
    QSpinBox *Mem_Size_Spin;
    QLabel *label_mb;
    QSpacerItem *spacerItem6;
    QSlider *Memory_Size;
    QWidget *Custom_HDD_Page;
    QGridLayout *gridLayout9;
    QSpacerItem *spacerItem7;
    QGroupBox *GB_HDD;
    QGridLayout *gridLayout10;
    QPushButton *Button_New_HDD;
    QPushButton *Button_Existing;
    QLineEdit *Edit_HDA_File_Name;
    QSpacerItem *spacerItem8;
    QLabel *Label_HDD;
    QSpacerItem *spacerItem9;
    QWidget *Network_Page;
    QGridLayout *gridLayout11;
    QGroupBox *GB_Network_Mode;
    QGridLayout *gridLayout12;
    QVBoxLayout *vboxLayout1;
    QRadioButton *RB_User_Mode_Network;
    QLabel *Label_User_Mone_Network;
    QVBoxLayout *vboxLayout2;
    QRadioButton *RB_No_Network;
    QLabel *Label_No_Network;
    QSpacerItem *spacerItem10;
    QLabel *Label_Network_Type;
    QWidget *Finish_Page;
    QGridLayout *gridLayout13;
    QSpacerItem *spacerItem11;
    QLabel *Label_Finish_Text;
    QWidget *Typical_HDD_Page;
    QVBoxLayout *vboxLayout3;
    QLabel *Label_Typical_HDD;
    QGroupBox *GB_HDD_Size;
    QHBoxLayout *hboxLayout3;
    QLabel *Label_HDD_Size;
    QDoubleSpinBox *SB_HDD_Size;
    QSpacerItem *spacerItem12;
    QHBoxLayout *hboxLayout4;
    QSpacerItem *spacerItem13;
    QPushButton *Button_Back;
    QPushButton *Button_Next;
    QSpacerItem *spacerItem14;
    QPushButton *Button_Cancel;
    QLabel *Label_Page;
    QFrame *line_2;

    void setupUi(QDialog *VM_Wizard_Window)
    {
        if (VM_Wizard_Window->objectName().isEmpty())
            VM_Wizard_Window->setObjectName(QString::fromUtf8("VM_Wizard_Window"));
        VM_Wizard_Window->resize(461, 385);
        gridLayout = new QGridLayout(VM_Wizard_Window);
#ifndef Q_OS_MAC
        gridLayout->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        gridLayout->setContentsMargins(9, 9, 9, 9);
#endif
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        Wizard_Pages = new QStackedWidget(VM_Wizard_Window);
        Wizard_Pages->setObjectName(QString::fromUtf8("Wizard_Pages"));
        Welcome_Page = new QWidget();
        Welcome_Page->setObjectName(QString::fromUtf8("Welcome_Page"));
        gridLayout1 = new QGridLayout(Welcome_Page);
#ifndef Q_OS_MAC
        gridLayout1->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        gridLayout1->setContentsMargins(9, 9, 9, 9);
#endif
        gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
        Label_Welcome_Text = new QLabel(Welcome_Page);
        Label_Welcome_Text->setObjectName(QString::fromUtf8("Label_Welcome_Text"));
        Label_Welcome_Text->setWordWrap(true);
        Label_Welcome_Text->setTextInteractionFlags(Qt::TextSelectableByMouse);

        gridLayout1->addWidget(Label_Welcome_Text, 0, 0, 1, 1);

        spacerItem = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout1->addItem(spacerItem, 1, 0, 1, 1);

        Wizard_Pages->addWidget(Welcome_Page);
        Wizard_Mode_Page = new QWidget();
        Wizard_Mode_Page->setObjectName(QString::fromUtf8("Wizard_Mode_Page"));
        gridLayout2 = new QGridLayout(Wizard_Mode_Page);
#ifndef Q_OS_MAC
        gridLayout2->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        gridLayout2->setContentsMargins(9, 9, 9, 9);
#endif
        gridLayout2->setObjectName(QString::fromUtf8("gridLayout2"));
        spacerItem1 = new QSpacerItem(411, 21, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout2->addItem(spacerItem1, 2, 0, 1, 1);

        GB_Wizard_Mode = new QGroupBox(Wizard_Mode_Page);
        GB_Wizard_Mode->setObjectName(QString::fromUtf8("GB_Wizard_Mode"));
        gridLayout3 = new QGridLayout(GB_Wizard_Mode);
#ifndef Q_OS_MAC
        gridLayout3->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        gridLayout3->setContentsMargins(9, 9, 9, 9);
#endif
        gridLayout3->setObjectName(QString::fromUtf8("gridLayout3"));
        RB_Custom = new QRadioButton(GB_Wizard_Mode);
        RB_Custom->setObjectName(QString::fromUtf8("RB_Custom"));

        gridLayout3->addWidget(RB_Custom, 2, 0, 1, 1);

        Label_Custom_Mode_Info = new QLabel(GB_Wizard_Mode);
        Label_Custom_Mode_Info->setObjectName(QString::fromUtf8("Label_Custom_Mode_Info"));
        Label_Custom_Mode_Info->setWordWrap(true);

        gridLayout3->addWidget(Label_Custom_Mode_Info, 3, 0, 1, 1);

        Label_Typical_Mode_Info = new QLabel(GB_Wizard_Mode);
        Label_Typical_Mode_Info->setObjectName(QString::fromUtf8("Label_Typical_Mode_Info"));
        Label_Typical_Mode_Info->setWordWrap(true);

        gridLayout3->addWidget(Label_Typical_Mode_Info, 1, 0, 1, 1);

        RB_Typical = new QRadioButton(GB_Wizard_Mode);
        RB_Typical->setObjectName(QString::fromUtf8("RB_Typical"));
        RB_Typical->setChecked(true);

        gridLayout3->addWidget(RB_Typical, 0, 0, 1, 1);


        gridLayout2->addWidget(GB_Wizard_Mode, 1, 0, 1, 1);

        Label_Confiration_Mode = new QLabel(Wizard_Mode_Page);
        Label_Confiration_Mode->setObjectName(QString::fromUtf8("Label_Confiration_Mode"));

        gridLayout2->addWidget(Label_Confiration_Mode, 0, 0, 1, 1);

        Wizard_Pages->addWidget(Wizard_Mode_Page);
        Template_Page = new QWidget();
        Template_Page->setObjectName(QString::fromUtf8("Template_Page"));
        gridLayout4 = new QGridLayout(Template_Page);
#ifndef Q_OS_MAC
        gridLayout4->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        gridLayout4->setContentsMargins(9, 9, 9, 9);
#endif
        gridLayout4->setObjectName(QString::fromUtf8("gridLayout4"));
        CB_OS_Type = new QComboBox(Template_Page);
        CB_OS_Type->addItem(QString());
        CB_OS_Type->setObjectName(QString::fromUtf8("CB_OS_Type"));
        CB_OS_Type->setMaxCount(1024);

        gridLayout4->addWidget(CB_OS_Type, 2, 1, 1, 1);

        Label_OS_Type = new QLabel(Template_Page);
        Label_OS_Type->setObjectName(QString::fromUtf8("Label_OS_Type"));
        QSizePolicy sizePolicy(static_cast<QSizePolicy::Policy>(4), static_cast<QSizePolicy::Policy>(5));
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Label_OS_Type->sizePolicy().hasHeightForWidth());
        Label_OS_Type->setSizePolicy(sizePolicy);

        gridLayout4->addWidget(Label_OS_Type, 2, 0, 1, 1);

        Label_Computer_Type = new QLabel(Template_Page);
        Label_Computer_Type->setObjectName(QString::fromUtf8("Label_Computer_Type"));
        Label_Computer_Type->setEnabled(false);
        sizePolicy.setHeightForWidth(Label_Computer_Type->sizePolicy().hasHeightForWidth());
        Label_Computer_Type->setSizePolicy(sizePolicy);

        gridLayout4->addWidget(Label_Computer_Type, 4, 0, 1, 1);

        Label_Relese_Date = new QLabel(Template_Page);
        Label_Relese_Date->setObjectName(QString::fromUtf8("Label_Relese_Date"));
        Label_Relese_Date->setEnabled(false);
        sizePolicy.setHeightForWidth(Label_Relese_Date->sizePolicy().hasHeightForWidth());
        Label_Relese_Date->setSizePolicy(sizePolicy);

        gridLayout4->addWidget(Label_Relese_Date, 5, 0, 1, 1);

        CB_Relese_Date = new QComboBox(Template_Page);
        CB_Relese_Date->addItem(QString());
        CB_Relese_Date->addItem(QString());
        CB_Relese_Date->addItem(QString());
        CB_Relese_Date->addItem(QString());
        CB_Relese_Date->addItem(QString());
        CB_Relese_Date->addItem(QString());
        CB_Relese_Date->setObjectName(QString::fromUtf8("CB_Relese_Date"));
        CB_Relese_Date->setEnabled(false);

        gridLayout4->addWidget(CB_Relese_Date, 5, 1, 1, 1);

        CB_Computer_Type = new QComboBox(Template_Page);
        CB_Computer_Type->addItem(QString());
        CB_Computer_Type->setObjectName(QString::fromUtf8("CB_Computer_Type"));
        CB_Computer_Type->setEnabled(false);

        gridLayout4->addWidget(CB_Computer_Type, 4, 1, 1, 1);

        spacerItem2 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout4->addItem(spacerItem2, 6, 1, 1, 1);

        hboxLayout = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout->setSpacing(6);
#endif
        hboxLayout->setContentsMargins(0, 0, 0, 0);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        RB_Generate_VM = new QRadioButton(Template_Page);
        RB_Generate_VM->setObjectName(QString::fromUtf8("RB_Generate_VM"));
        QSizePolicy sizePolicy1(static_cast<QSizePolicy::Policy>(4), static_cast<QSizePolicy::Policy>(0));
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(RB_Generate_VM->sizePolicy().hasHeightForWidth());
        RB_Generate_VM->setSizePolicy(sizePolicy1);

        hboxLayout->addWidget(RB_Generate_VM);

        line_3 = new QFrame(Template_Page);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        hboxLayout->addWidget(line_3);


        gridLayout4->addLayout(hboxLayout, 3, 0, 1, 2);

        hboxLayout1 = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout1->setSpacing(6);
#endif
        hboxLayout1->setContentsMargins(0, 0, 0, 0);
        hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
        RB_VM_Template = new QRadioButton(Template_Page);
        RB_VM_Template->setObjectName(QString::fromUtf8("RB_VM_Template"));
        sizePolicy1.setHeightForWidth(RB_VM_Template->sizePolicy().hasHeightForWidth());
        RB_VM_Template->setSizePolicy(sizePolicy1);
        RB_VM_Template->setChecked(true);

        hboxLayout1->addWidget(RB_VM_Template);

        line = new QFrame(Template_Page);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        hboxLayout1->addWidget(line);


        gridLayout4->addLayout(hboxLayout1, 1, 0, 1, 2);

        Label_Template = new QLabel(Template_Page);
        Label_Template->setObjectName(QString::fromUtf8("Label_Template"));

        gridLayout4->addWidget(Label_Template, 0, 0, 1, 2);

        Wizard_Pages->addWidget(Template_Page);
        General_Settings_Page = new QWidget();
        General_Settings_Page->setObjectName(QString::fromUtf8("General_Settings_Page"));
        gridLayout5 = new QGridLayout(General_Settings_Page);
#ifndef Q_OS_MAC
        gridLayout5->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        gridLayout5->setContentsMargins(9, 9, 9, 9);
#endif
        gridLayout5->setObjectName(QString::fromUtf8("gridLayout5"));
        GB_CPU_Type = new QGroupBox(General_Settings_Page);
        GB_CPU_Type->setObjectName(QString::fromUtf8("GB_CPU_Type"));
        gridLayout6 = new QGridLayout(GB_CPU_Type);
#ifndef Q_OS_MAC
        gridLayout6->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        gridLayout6->setContentsMargins(9, 9, 9, 9);
#endif
        gridLayout6->setObjectName(QString::fromUtf8("gridLayout6"));
        CB_CPU_Type = new QComboBox(GB_CPU_Type);
        CB_CPU_Type->setObjectName(QString::fromUtf8("CB_CPU_Type"));
        QSizePolicy sizePolicy2(static_cast<QSizePolicy::Policy>(1), static_cast<QSizePolicy::Policy>(0));
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(CB_CPU_Type->sizePolicy().hasHeightForWidth());
        CB_CPU_Type->setSizePolicy(sizePolicy2);

        gridLayout6->addWidget(CB_CPU_Type, 0, 1, 1, 1);

        Label_CPU_Type = new QLabel(GB_CPU_Type);
        Label_CPU_Type->setObjectName(QString::fromUtf8("Label_CPU_Type"));
        Label_CPU_Type->setWordWrap(true);

        gridLayout6->addWidget(Label_CPU_Type, 0, 0, 1, 1);


        gridLayout5->addWidget(GB_CPU_Type, 1, 0, 1, 1);

        GB_VM_Name = new QGroupBox(General_Settings_Page);
        GB_VM_Name->setObjectName(QString::fromUtf8("GB_VM_Name"));
        vboxLayout = new QVBoxLayout(GB_VM_Name);
#ifndef Q_OS_MAC
        vboxLayout->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        vboxLayout->setContentsMargins(9, 9, 9, 9);
#endif
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        Label_VM_Name = new QLabel(GB_VM_Name);
        Label_VM_Name->setObjectName(QString::fromUtf8("Label_VM_Name"));
        Label_VM_Name->setWordWrap(true);
        Label_VM_Name->setTextInteractionFlags(Qt::TextSelectableByMouse);

        vboxLayout->addWidget(Label_VM_Name);

        Edit_VM_Name = new QLineEdit(GB_VM_Name);
        Edit_VM_Name->setObjectName(QString::fromUtf8("Edit_VM_Name"));

        vboxLayout->addWidget(Edit_VM_Name);


        gridLayout5->addWidget(GB_VM_Name, 0, 0, 1, 1);

        spacerItem3 = new QSpacerItem(20, 31, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout5->addItem(spacerItem3, 2, 0, 1, 1);

        Wizard_Pages->addWidget(General_Settings_Page);
        Memory_Page = new QWidget();
        Memory_Page->setObjectName(QString::fromUtf8("Memory_Page"));
        gridLayout7 = new QGridLayout(Memory_Page);
#ifndef Q_OS_MAC
        gridLayout7->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        gridLayout7->setContentsMargins(9, 9, 9, 9);
#endif
        gridLayout7->setObjectName(QString::fromUtf8("gridLayout7"));
        spacerItem4 = new QSpacerItem(20, 191, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout7->addItem(spacerItem4, 1, 0, 1, 1);

        GB_Memory = new QGroupBox(Memory_Page);
        GB_Memory->setObjectName(QString::fromUtf8("GB_Memory"));
        gridLayout8 = new QGridLayout(GB_Memory);
#ifndef Q_OS_MAC
        gridLayout8->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        gridLayout8->setContentsMargins(9, 9, 9, 9);
#endif
        gridLayout8->setObjectName(QString::fromUtf8("gridLayout8"));
        Label_Memory_Size = new QLabel(GB_Memory);
        Label_Memory_Size->setObjectName(QString::fromUtf8("Label_Memory_Size"));
        Label_Memory_Size->setWordWrap(true);
        Label_Memory_Size->setTextInteractionFlags(Qt::TextSelectableByMouse);

        gridLayout8->addWidget(Label_Memory_Size, 0, 0, 1, 3);

        hboxLayout2 = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout2->setSpacing(6);
#endif
        hboxLayout2->setContentsMargins(0, 0, 0, 0);
        hboxLayout2->setObjectName(QString::fromUtf8("hboxLayout2"));
        label_min_mem = new QLabel(GB_Memory);
        label_min_mem->setObjectName(QString::fromUtf8("label_min_mem"));

        hboxLayout2->addWidget(label_min_mem);

        spacerItem5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout2->addItem(spacerItem5);

        label_max_mem = new QLabel(GB_Memory);
        label_max_mem->setObjectName(QString::fromUtf8("label_max_mem"));
        label_max_mem->setMinimumSize(QSize(32, 20));
        label_max_mem->setMaximumSize(QSize(55, 20));

        hboxLayout2->addWidget(label_max_mem);


        gridLayout8->addLayout(hboxLayout2, 2, 0, 1, 2);

        Check_Host_Mem = new QCheckBox(GB_Memory);
        Check_Host_Mem->setObjectName(QString::fromUtf8("Check_Host_Mem"));

        gridLayout8->addWidget(Check_Host_Mem, 3, 0, 1, 1);

        Mem_Size_Spin = new QSpinBox(GB_Memory);
        Mem_Size_Spin->setObjectName(QString::fromUtf8("Mem_Size_Spin"));
        Mem_Size_Spin->setMinimumSize(QSize(55, 25));
        Mem_Size_Spin->setMaximumSize(QSize(55, 25));
        Mem_Size_Spin->setMaximum(2048);
        Mem_Size_Spin->setMinimum(1);
        Mem_Size_Spin->setValue(128);

        gridLayout8->addWidget(Mem_Size_Spin, 1, 1, 1, 1);

        label_mb = new QLabel(GB_Memory);
        label_mb->setObjectName(QString::fromUtf8("label_mb"));

        gridLayout8->addWidget(label_mb, 1, 2, 1, 1);

        spacerItem6 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout8->addItem(spacerItem6, 2, 2, 1, 1);

        Memory_Size = new QSlider(GB_Memory);
        Memory_Size->setObjectName(QString::fromUtf8("Memory_Size"));
        Memory_Size->setMinimum(1);
        Memory_Size->setMaximum(2048);
        Memory_Size->setValue(128);
        Memory_Size->setOrientation(Qt::Horizontal);

        gridLayout8->addWidget(Memory_Size, 1, 0, 1, 1);


        gridLayout7->addWidget(GB_Memory, 0, 0, 1, 1);

        Wizard_Pages->addWidget(Memory_Page);
        Custom_HDD_Page = new QWidget();
        Custom_HDD_Page->setObjectName(QString::fromUtf8("Custom_HDD_Page"));
        gridLayout9 = new QGridLayout(Custom_HDD_Page);
#ifndef Q_OS_MAC
        gridLayout9->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        gridLayout9->setContentsMargins(9, 9, 9, 9);
#endif
        gridLayout9->setObjectName(QString::fromUtf8("gridLayout9"));
        spacerItem7 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout9->addItem(spacerItem7, 3, 0, 1, 1);

        GB_HDD = new QGroupBox(Custom_HDD_Page);
        GB_HDD->setObjectName(QString::fromUtf8("GB_HDD"));
        gridLayout10 = new QGridLayout(GB_HDD);
#ifndef Q_OS_MAC
        gridLayout10->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        gridLayout10->setContentsMargins(9, 9, 9, 9);
#endif
        gridLayout10->setObjectName(QString::fromUtf8("gridLayout10"));
        Button_New_HDD = new QPushButton(GB_HDD);
        Button_New_HDD->setObjectName(QString::fromUtf8("Button_New_HDD"));

        gridLayout10->addWidget(Button_New_HDD, 1, 0, 1, 1);

        Button_Existing = new QPushButton(GB_HDD);
        Button_Existing->setObjectName(QString::fromUtf8("Button_Existing"));

        gridLayout10->addWidget(Button_Existing, 1, 1, 1, 1);

        Edit_HDA_File_Name = new QLineEdit(GB_HDD);
        Edit_HDA_File_Name->setObjectName(QString::fromUtf8("Edit_HDA_File_Name"));

        gridLayout10->addWidget(Edit_HDA_File_Name, 0, 0, 1, 3);

        spacerItem8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout10->addItem(spacerItem8, 1, 2, 1, 1);


        gridLayout9->addWidget(GB_HDD, 2, 0, 1, 1);

        Label_HDD = new QLabel(Custom_HDD_Page);
        Label_HDD->setObjectName(QString::fromUtf8("Label_HDD"));
        Label_HDD->setWordWrap(true);
        Label_HDD->setTextInteractionFlags(Qt::TextSelectableByMouse);

        gridLayout9->addWidget(Label_HDD, 0, 0, 1, 1);

        spacerItem9 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout9->addItem(spacerItem9, 1, 0, 1, 1);

        Wizard_Pages->addWidget(Custom_HDD_Page);
        Network_Page = new QWidget();
        Network_Page->setObjectName(QString::fromUtf8("Network_Page"));
        gridLayout11 = new QGridLayout(Network_Page);
#ifndef Q_OS_MAC
        gridLayout11->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        gridLayout11->setContentsMargins(9, 9, 9, 9);
#endif
        gridLayout11->setObjectName(QString::fromUtf8("gridLayout11"));
        GB_Network_Mode = new QGroupBox(Network_Page);
        GB_Network_Mode->setObjectName(QString::fromUtf8("GB_Network_Mode"));
        gridLayout12 = new QGridLayout(GB_Network_Mode);
#ifndef Q_OS_MAC
        gridLayout12->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        gridLayout12->setContentsMargins(9, 9, 9, 9);
#endif
        gridLayout12->setObjectName(QString::fromUtf8("gridLayout12"));
        vboxLayout1 = new QVBoxLayout();
        vboxLayout1->setSpacing(1);
#ifndef Q_OS_MAC
        vboxLayout1->setContentsMargins(0, 0, 0, 0);
#endif
        vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
        RB_User_Mode_Network = new QRadioButton(GB_Network_Mode);
        RB_User_Mode_Network->setObjectName(QString::fromUtf8("RB_User_Mode_Network"));
        RB_User_Mode_Network->setChecked(true);

        vboxLayout1->addWidget(RB_User_Mode_Network);

        Label_User_Mone_Network = new QLabel(GB_Network_Mode);
        Label_User_Mone_Network->setObjectName(QString::fromUtf8("Label_User_Mone_Network"));

        vboxLayout1->addWidget(Label_User_Mone_Network);


        gridLayout12->addLayout(vboxLayout1, 0, 0, 1, 1);

        vboxLayout2 = new QVBoxLayout();
        vboxLayout2->setSpacing(1);
        vboxLayout2->setContentsMargins(0, 0, 0, 0);
        vboxLayout2->setObjectName(QString::fromUtf8("vboxLayout2"));
        RB_No_Network = new QRadioButton(GB_Network_Mode);
        RB_No_Network->setObjectName(QString::fromUtf8("RB_No_Network"));

        vboxLayout2->addWidget(RB_No_Network);

        Label_No_Network = new QLabel(GB_Network_Mode);
        Label_No_Network->setObjectName(QString::fromUtf8("Label_No_Network"));

        vboxLayout2->addWidget(Label_No_Network);


        gridLayout12->addLayout(vboxLayout2, 1, 0, 1, 1);


        gridLayout11->addWidget(GB_Network_Mode, 1, 0, 1, 1);

        spacerItem10 = new QSpacerItem(411, 21, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout11->addItem(spacerItem10, 2, 0, 1, 1);

        Label_Network_Type = new QLabel(Network_Page);
        Label_Network_Type->setObjectName(QString::fromUtf8("Label_Network_Type"));

        gridLayout11->addWidget(Label_Network_Type, 0, 0, 1, 1);

        Wizard_Pages->addWidget(Network_Page);
        Finish_Page = new QWidget();
        Finish_Page->setObjectName(QString::fromUtf8("Finish_Page"));
        gridLayout13 = new QGridLayout(Finish_Page);
#ifndef Q_OS_MAC
        gridLayout13->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        gridLayout13->setContentsMargins(9, 9, 9, 9);
#endif
        gridLayout13->setObjectName(QString::fromUtf8("gridLayout13"));
        spacerItem11 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout13->addItem(spacerItem11, 1, 0, 1, 1);

        Label_Finish_Text = new QLabel(Finish_Page);
        Label_Finish_Text->setObjectName(QString::fromUtf8("Label_Finish_Text"));
        Label_Finish_Text->setWordWrap(true);
        Label_Finish_Text->setTextInteractionFlags(Qt::TextSelectableByMouse);

        gridLayout13->addWidget(Label_Finish_Text, 0, 0, 1, 1);

        Wizard_Pages->addWidget(Finish_Page);
        Typical_HDD_Page = new QWidget();
        Typical_HDD_Page->setObjectName(QString::fromUtf8("Typical_HDD_Page"));
        vboxLayout3 = new QVBoxLayout(Typical_HDD_Page);
#ifndef Q_OS_MAC
        vboxLayout3->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        vboxLayout3->setContentsMargins(9, 9, 9, 9);
#endif
        vboxLayout3->setObjectName(QString::fromUtf8("vboxLayout3"));
        Label_Typical_HDD = new QLabel(Typical_HDD_Page);
        Label_Typical_HDD->setObjectName(QString::fromUtf8("Label_Typical_HDD"));

        vboxLayout3->addWidget(Label_Typical_HDD);

        GB_HDD_Size = new QGroupBox(Typical_HDD_Page);
        GB_HDD_Size->setObjectName(QString::fromUtf8("GB_HDD_Size"));
        hboxLayout3 = new QHBoxLayout(GB_HDD_Size);
#ifndef Q_OS_MAC
        hboxLayout3->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        hboxLayout3->setContentsMargins(9, 9, 9, 9);
#endif
        hboxLayout3->setObjectName(QString::fromUtf8("hboxLayout3"));
        Label_HDD_Size = new QLabel(GB_HDD_Size);
        Label_HDD_Size->setObjectName(QString::fromUtf8("Label_HDD_Size"));

        hboxLayout3->addWidget(Label_HDD_Size);

        SB_HDD_Size = new QDoubleSpinBox(GB_HDD_Size);
        SB_HDD_Size->setObjectName(QString::fromUtf8("SB_HDD_Size"));
        SB_HDD_Size->setDecimals(1);
        SB_HDD_Size->setMaximum(500.000000000000000);
        SB_HDD_Size->setMinimum(0.100000000000000);
        SB_HDD_Size->setValue(10.000000000000000);

        hboxLayout3->addWidget(SB_HDD_Size);


        vboxLayout3->addWidget(GB_HDD_Size);

        spacerItem12 = new QSpacerItem(411, 21, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vboxLayout3->addItem(spacerItem12);

        Wizard_Pages->addWidget(Typical_HDD_Page);

        gridLayout->addWidget(Wizard_Pages, 1, 0, 1, 1);

        hboxLayout4 = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout4->setSpacing(6);
#endif
        hboxLayout4->setContentsMargins(0, 0, 0, 0);
        hboxLayout4->setObjectName(QString::fromUtf8("hboxLayout4"));
        spacerItem13 = new QSpacerItem(211, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout4->addItem(spacerItem13);

        Button_Back = new QPushButton(VM_Wizard_Window);
        Button_Back->setObjectName(QString::fromUtf8("Button_Back"));
        Button_Back->setEnabled(false);

        hboxLayout4->addWidget(Button_Back);

        Button_Next = new QPushButton(VM_Wizard_Window);
        Button_Next->setObjectName(QString::fromUtf8("Button_Next"));

        hboxLayout4->addWidget(Button_Next);

        spacerItem14 = new QSpacerItem(7, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        hboxLayout4->addItem(spacerItem14);

        Button_Cancel = new QPushButton(VM_Wizard_Window);
        Button_Cancel->setObjectName(QString::fromUtf8("Button_Cancel"));

        hboxLayout4->addWidget(Button_Cancel);


        gridLayout->addLayout(hboxLayout4, 3, 0, 1, 1);

        Label_Page = new QLabel(VM_Wizard_Window);
        Label_Page->setObjectName(QString::fromUtf8("Label_Page"));
        QSizePolicy sizePolicy3(static_cast<QSizePolicy::Policy>(5), static_cast<QSizePolicy::Policy>(0));
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(Label_Page->sizePolicy().hasHeightForWidth());
        Label_Page->setSizePolicy(sizePolicy3);
        Label_Page->setMinimumSize(QSize(0, 38));
        QFont font;
        font.setFamily(QString::fromUtf8("Sans Serif"));
        font.setPointSize(12);
        Label_Page->setFont(font);
        Label_Page->setAutoFillBackground(true);
        Label_Page->setFrameShape(QFrame::StyledPanel);
        Label_Page->setFrameShadow(QFrame::Plain);

        gridLayout->addWidget(Label_Page, 0, 0, 1, 1);

        line_2 = new QFrame(VM_Wizard_Window);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_2, 2, 0, 1, 1);

#ifndef QT_NO_SHORTCUT
        Label_Custom_Mode_Info->setBuddy(RB_Custom);
        Label_Typical_Mode_Info->setBuddy(RB_Typical);
        Label_OS_Type->setBuddy(CB_Computer_Type);
        Label_Computer_Type->setBuddy(CB_Computer_Type);
        Label_Relese_Date->setBuddy(CB_Relese_Date);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(Button_Back, Button_Next);
        QWidget::setTabOrder(Button_Next, Button_Cancel);
        QWidget::setTabOrder(Button_Cancel, RB_Typical);
        QWidget::setTabOrder(RB_Typical, RB_Custom);
        QWidget::setTabOrder(RB_Custom, RB_VM_Template);
        QWidget::setTabOrder(RB_VM_Template, CB_OS_Type);
        QWidget::setTabOrder(CB_OS_Type, RB_Generate_VM);
        QWidget::setTabOrder(RB_Generate_VM, CB_Computer_Type);
        QWidget::setTabOrder(CB_Computer_Type, CB_Relese_Date);
        QWidget::setTabOrder(CB_Relese_Date, Edit_VM_Name);
        QWidget::setTabOrder(Edit_VM_Name, CB_CPU_Type);
        QWidget::setTabOrder(CB_CPU_Type, Memory_Size);
        QWidget::setTabOrder(Memory_Size, Mem_Size_Spin);
        QWidget::setTabOrder(Mem_Size_Spin, Check_Host_Mem);
        QWidget::setTabOrder(Check_Host_Mem, Edit_HDA_File_Name);
        QWidget::setTabOrder(Edit_HDA_File_Name, Button_New_HDD);
        QWidget::setTabOrder(Button_New_HDD, Button_Existing);
        QWidget::setTabOrder(Button_Existing, RB_User_Mode_Network);
        QWidget::setTabOrder(RB_User_Mode_Network, RB_No_Network);
        QWidget::setTabOrder(RB_No_Network, SB_HDD_Size);

        retranslateUi(VM_Wizard_Window);
        QObject::connect(Button_Cancel, SIGNAL(clicked()), VM_Wizard_Window, SLOT(reject()));
        QObject::connect(RB_VM_Template, SIGNAL(toggled(bool)), Label_OS_Type, SLOT(setEnabled(bool)));
        QObject::connect(RB_VM_Template, SIGNAL(toggled(bool)), CB_OS_Type, SLOT(setEnabled(bool)));
        QObject::connect(RB_Generate_VM, SIGNAL(toggled(bool)), Label_Computer_Type, SLOT(setEnabled(bool)));
        QObject::connect(RB_Generate_VM, SIGNAL(toggled(bool)), CB_Computer_Type, SLOT(setEnabled(bool)));
        QObject::connect(RB_Generate_VM, SIGNAL(toggled(bool)), Label_Relese_Date, SLOT(setEnabled(bool)));
        QObject::connect(RB_Generate_VM, SIGNAL(toggled(bool)), CB_Relese_Date, SLOT(setEnabled(bool)));
        QObject::connect(Memory_Size, SIGNAL(valueChanged(int)), Mem_Size_Spin, SLOT(setValue(int)));
        QObject::connect(Mem_Size_Spin, SIGNAL(valueChanged(int)), Memory_Size, SLOT(setValue(int)));

        Wizard_Pages->setCurrentIndex(0);
        CB_CPU_Type->setCurrentIndex(-1);
        Button_Next->setDefault(true);


        QMetaObject::connectSlotsByName(VM_Wizard_Window);
    } // setupUi

    void retranslateUi(QDialog *VM_Wizard_Window)
    {
        VM_Wizard_Window->setWindowTitle(QApplication::translate("VM_Wizard_Window", "New Virtual Machine Wizard", nullptr));
        Label_Welcome_Text->setText(QApplication::translate("VM_Wizard_Window", "<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:9pt; font-weight:400; font-style:normal; text-decoration:none;\">\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">This wizard will guide you through the steps that are necessary to create a new virtual machine for AQEMU.</p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Use the <span style=\" font-weight:600;\">Next</span> button to go the next page of the wizard and the <span style=\" font-weight:600;\">Back</span> button to return to the previous page.</p></body></html>", nullptr));
        GB_Wizard_Mode->setTitle(QApplication::translate("VM_Wizard_Window", "Configuration Mode:", nullptr));
        RB_Custom->setText(QApplication::translate("VM_Wizard_Window", "&Custom", nullptr));
        Label_Custom_Mode_Info->setText(QApplication::translate("VM_Wizard_Window", "Create new virtual machine with additional configuration options.", nullptr));
        Label_Typical_Mode_Info->setText(QApplication::translate("VM_Wizard_Window", "Create new virtual machine with most common devices and configuration options.", nullptr));
        RB_Typical->setText(QApplication::translate("VM_Wizard_Window", "&Typical (For Beginners)", nullptr));
        Label_Confiration_Mode->setText(QApplication::translate("VM_Wizard_Window", "Select AQEMU Configuration Mode", nullptr));
        CB_OS_Type->setItemText(0, QApplication::translate("VM_Wizard_Window", "No Selected", nullptr));

        Label_OS_Type->setText(QApplication::translate("VM_Wizard_Window", "OS Type:", nullptr));
        Label_Computer_Type->setText(QApplication::translate("VM_Wizard_Window", "C&omputer Type:", nullptr));
        Label_Relese_Date->setText(QApplication::translate("VM_Wizard_Window", "Release Date:", nullptr));
        CB_Relese_Date->setItemText(0, QApplication::translate("VM_Wizard_Window", "No Selected", nullptr));
        CB_Relese_Date->setItemText(1, QApplication::translate("VM_Wizard_Window", "1985-1990", nullptr));
        CB_Relese_Date->setItemText(2, QApplication::translate("VM_Wizard_Window", "1990-1995", nullptr));
        CB_Relese_Date->setItemText(3, QApplication::translate("VM_Wizard_Window", "1995-2000", nullptr));
        CB_Relese_Date->setItemText(4, QApplication::translate("VM_Wizard_Window", "2000-2005", nullptr));
        CB_Relese_Date->setItemText(5, QApplication::translate("VM_Wizard_Window", "2005-2008", nullptr));

        CB_Computer_Type->setItemText(0, QApplication::translate("VM_Wizard_Window", "No Selected", nullptr));

        RB_Generate_VM->setText(QApplication::translate("VM_Wizard_Window", "Generate VM", nullptr));
        RB_VM_Template->setText(QApplication::translate("VM_Wizard_Window", "Template", nullptr));
        Label_Template->setText(QApplication::translate("VM_Wizard_Window", "Please Select VM Hardware Template", nullptr));
        GB_CPU_Type->setTitle(QApplication::translate("VM_Wizard_Window", "CPU &Type:", nullptr));
        Label_CPU_Type->setText(QApplication::translate("VM_Wizard_Window", "Select a CPU type for you new virtual machine.", nullptr));
        GB_VM_Name->setTitle(QApplication::translate("VM_Wizard_Window", "VM N&ame:", nullptr));
        Label_VM_Name->setText(QApplication::translate("VM_Wizard_Window", "Enter a name for the new virtual machine. The name of the virtual machine usually indicates its software and hardware configuration.", nullptr));
        GB_Memory->setTitle(QApplication::translate("VM_Wizard_Window", "&Memory Size:", nullptr));
        Label_Memory_Size->setText(QApplication::translate("VM_Wizard_Window", "Select the amount of base memory (RAM) in megabytes to be allocated to the virtual machine.", nullptr));
        label_min_mem->setText(QApplication::translate("VM_Wizard_Window", "1 MB", nullptr));
        label_max_mem->setText(QApplication::translate("VM_Wizard_Window", "2048 MB", nullptr));
        Check_Host_Mem->setText(QApplication::translate("VM_Wizard_Window", "C&heck Free Memory", nullptr));
        label_mb->setText(QApplication::translate("VM_Wizard_Window", "MB", nullptr));
        GB_HDD->setTitle(QApplication::translate("VM_Wizard_Window", "B&oot Hard Disk (Primary Master)", nullptr));
        Button_New_HDD->setText(QApplication::translate("VM_Wizard_Window", "N&ew...", nullptr));
        Button_Existing->setText(QApplication::translate("VM_Wizard_Window", "E&xisting...", nullptr));
        Label_HDD->setText(QApplication::translate("VM_Wizard_Window", "<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:9pt; font-weight:400; font-style:normal; text-decoration:none;\">\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Select a hard disk image to be used as a boot hard disk of the virtual machine. You can either create a new hard disk using the <span style=\" font-weight:600;\">New</span> button or select an existing hard disk image by pressing the <span style=\" font-weight:600;\">Existing</span> button.</p></body></html>", nullptr));
        GB_Network_Mode->setTitle(QApplication::translate("VM_Wizard_Window", "Network Connection:", nullptr));
        RB_User_Mode_Network->setText(QApplication::translate("VM_Wizard_Window", "&User Mode Network Connection", nullptr));
        Label_User_Mone_Network->setText(QApplication::translate("VM_Wizard_Window", "Use the user mode network stack", nullptr));
        RB_No_Network->setText(QApplication::translate("VM_Wizard_Window", "N&o Network", nullptr));
        Label_No_Network->setText(QApplication::translate("VM_Wizard_Window", "No net cards installed on VM", nullptr));
        Label_Network_Type->setText(QApplication::translate("VM_Wizard_Window", "Select network type using on you new virtual machine.", nullptr));
        Label_Finish_Text->setText(QApplication::translate("VM_Wizard_Window", "<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:9pt; font-weight:400; font-style:normal; text-decoration:none;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">If the above is correct press the <span style=\" font-weight:600;\">Finish</span> button. Once you press it, a new virtual machine will be created. </p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Note that you can alter these and all other setting of the created virtual machine at any time. </p></body></html>", nullptr));
        Label_Typical_HDD->setText(QApplication::translate("VM_Wizard_Window", "Enter you new virtual machine hard disk capacity.", nullptr));
        GB_HDD_Size->setTitle(QApplication::translate("VM_Wizard_Window", "Hard Disk Capacity:", nullptr));
        Label_HDD_Size->setText(QApplication::translate("VM_Wizard_Window", "Disk Size in GB (Gigabytes):", nullptr));
        Button_Back->setText(QApplication::translate("VM_Wizard_Window", "&Back", nullptr));
        Button_Next->setText(QApplication::translate("VM_Wizard_Window", "&Next", nullptr));
        Button_Cancel->setText(QApplication::translate("VM_Wizard_Window", "&Cancel", nullptr));
        Label_Page->setText(QApplication::translate("VM_Wizard_Window", "New Virtual Machine Wizard", nullptr));
    } // retranslateUi

};

namespace Ui {
    class VM_Wizard_Window: public Ui_VM_Wizard_Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VM_WIZARD_WINDOW_H
