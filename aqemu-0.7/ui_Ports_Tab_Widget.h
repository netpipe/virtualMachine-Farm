/********************************************************************************
** Form generated from reading UI file 'Ports_Tab_Widget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PORTS_TAB_WIDGET_H
#define UI_PORTS_TAB_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Ports_Tab_Widget
{
public:
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *Tab_Serial_Port;
    QGridLayout *gridLayout1;
    QSpacerItem *spacerItem;
    QRadioButton *RB_Serial_UDP;
    QRadioButton *RB_Serial_Unix;
    QRadioButton *RB_Serial_File;
    QRadioButton *RB_Serial_Dev;
    QRadioButton *RB_Serial_Default;
    QRadioButton *RB_Serial_stdio;
    QRadioButton *RB_Serial_none;
    QRadioButton *RB_Serial_Pipe;
    QRadioButton *RB_Serial_TCP;
    QRadioButton *RB_Serial_pty;
    QRadioButton *RB_Serial_Host_Port;
    QLabel *Label_Serial_Port;
    QGridLayout *gridLayout2;
    QLineEdit *Edit_Serial_Other;
    QToolButton *TB_Serial_Other;
    QLabel *Label_Serial_Args;
    QRadioButton *RB_Serial_Telnet;
    QRadioButton *RB_Serial_null;
    QRadioButton *RB_Serial_vc;
    QSpacerItem *spacerItem1;
    QSpacerItem *spacerItem2;
    QWidget *Tab_Parallel_Port;
    QGridLayout *gridLayout3;
    QSpacerItem *spacerItem3;
    QSpacerItem *spacerItem4;
    QSpacerItem *spacerItem5;
    QLabel *Label_Parallel_Port;
    QGridLayout *gridLayout4;
    QToolButton *TB_Parallel_Other;
    QLabel *Label_Parallel_Args;
    QLineEdit *Edit_Parallel_Other;
    QRadioButton *RB_Parallel_Telnet;
    QRadioButton *RB_Parallel_vc;
    QRadioButton *RB_Parallel_null;
    QRadioButton *RB_Parallel_pty;
    QRadioButton *RB_Parallel_Host_Port;
    QRadioButton *RB_Parallel_TCP;
    QRadioButton *RB_Parallel_Pipe;
    QRadioButton *RB_Parallel_none;
    QRadioButton *RB_Parallel_stdio;
    QRadioButton *RB_Parallel_Default;
    QRadioButton *RB_Parallel_Dev;
    QRadioButton *RB_Parallel_File;
    QRadioButton *RB_Parallel_Unix;
    QRadioButton *RB_Parallel_UDP;
    QWidget *Tab_USB_Ports;
    QGridLayout *gridLayout5;
    QSpacerItem *spacerItem6;
    QCheckBox *CH_USB_Hub;
    QGridLayout *gridLayout6;
    QPushButton *Button_Clear_VM_USB_List;
    QPushButton *Button_Update_Host_USB;
    QTableWidget *Table_VM_USB;
    QLabel *Label_VM_USB_Devices;
    QLabel *Label_Host_USB_Devices;
    QPushButton *Button_Add_USB_Device;
    QTableWidget *Table_Host_USB;
    QPushButton *Button_Delete_USB_Device;

    void setupUi(QWidget *Ports_Tab_Widget)
    {
        if (Ports_Tab_Widget->objectName().isEmpty())
            Ports_Tab_Widget->setObjectName(QString::fromUtf8("Ports_Tab_Widget"));
        Ports_Tab_Widget->resize(471, 380);
        gridLayout = new QGridLayout(Ports_Tab_Widget);
#ifndef Q_OS_MAC
        gridLayout->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        gridLayout->setContentsMargins(9, 9, 9, 9);
#endif
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tabWidget = new QTabWidget(Ports_Tab_Widget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        Tab_Serial_Port = new QWidget();
        Tab_Serial_Port->setObjectName(QString::fromUtf8("Tab_Serial_Port"));
        gridLayout1 = new QGridLayout(Tab_Serial_Port);
#ifndef Q_OS_MAC
        gridLayout1->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        gridLayout1->setContentsMargins(9, 9, 9, 9);
#endif
        gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
        spacerItem = new QSpacerItem(431, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout1->addItem(spacerItem, 7, 0, 1, 5);

        RB_Serial_UDP = new QRadioButton(Tab_Serial_Port);
        RB_Serial_UDP->setObjectName(QString::fromUtf8("RB_Serial_UDP"));

        gridLayout1->addWidget(RB_Serial_UDP, 5, 0, 1, 1);

        RB_Serial_Unix = new QRadioButton(Tab_Serial_Port);
        RB_Serial_Unix->setObjectName(QString::fromUtf8("RB_Serial_Unix"));

        gridLayout1->addWidget(RB_Serial_Unix, 4, 0, 1, 1);

        RB_Serial_File = new QRadioButton(Tab_Serial_Port);
        RB_Serial_File->setObjectName(QString::fromUtf8("RB_Serial_File"));

        gridLayout1->addWidget(RB_Serial_File, 3, 0, 1, 1);

        RB_Serial_Dev = new QRadioButton(Tab_Serial_Port);
        RB_Serial_Dev->setObjectName(QString::fromUtf8("RB_Serial_Dev"));

        gridLayout1->addWidget(RB_Serial_Dev, 2, 0, 1, 1);

        RB_Serial_Default = new QRadioButton(Tab_Serial_Port);
        RB_Serial_Default->setObjectName(QString::fromUtf8("RB_Serial_Default"));
        RB_Serial_Default->setChecked(true);

        gridLayout1->addWidget(RB_Serial_Default, 1, 0, 1, 1);

        RB_Serial_stdio = new QRadioButton(Tab_Serial_Port);
        RB_Serial_stdio->setObjectName(QString::fromUtf8("RB_Serial_stdio"));

        gridLayout1->addWidget(RB_Serial_stdio, 1, 4, 1, 1);

        RB_Serial_none = new QRadioButton(Tab_Serial_Port);
        RB_Serial_none->setObjectName(QString::fromUtf8("RB_Serial_none"));

        gridLayout1->addWidget(RB_Serial_none, 2, 4, 1, 1);

        RB_Serial_Pipe = new QRadioButton(Tab_Serial_Port);
        RB_Serial_Pipe->setObjectName(QString::fromUtf8("RB_Serial_Pipe"));

        gridLayout1->addWidget(RB_Serial_Pipe, 4, 4, 1, 1);

        RB_Serial_TCP = new QRadioButton(Tab_Serial_Port);
        RB_Serial_TCP->setObjectName(QString::fromUtf8("RB_Serial_TCP"));

        gridLayout1->addWidget(RB_Serial_TCP, 5, 2, 1, 1);

        RB_Serial_pty = new QRadioButton(Tab_Serial_Port);
        RB_Serial_pty->setObjectName(QString::fromUtf8("RB_Serial_pty"));

        gridLayout1->addWidget(RB_Serial_pty, 3, 2, 1, 1);

        RB_Serial_Host_Port = new QRadioButton(Tab_Serial_Port);
        RB_Serial_Host_Port->setObjectName(QString::fromUtf8("RB_Serial_Host_Port"));

        gridLayout1->addWidget(RB_Serial_Host_Port, 4, 2, 1, 1);

        Label_Serial_Port = new QLabel(Tab_Serial_Port);
        Label_Serial_Port->setObjectName(QString::fromUtf8("Label_Serial_Port"));
        QSizePolicy sizePolicy(static_cast<QSizePolicy::Policy>(5), static_cast<QSizePolicy::Policy>(5));
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Label_Serial_Port->sizePolicy().hasHeightForWidth());
        Label_Serial_Port->setSizePolicy(sizePolicy);

        gridLayout1->addWidget(Label_Serial_Port, 0, 0, 1, 5);

        gridLayout2 = new QGridLayout();
#ifndef Q_OS_MAC
        gridLayout2->setSpacing(6);
#endif
        gridLayout2->setContentsMargins(0, 0, 0, 0);
        gridLayout2->setObjectName(QString::fromUtf8("gridLayout2"));
        Edit_Serial_Other = new QLineEdit(Tab_Serial_Port);
        Edit_Serial_Other->setObjectName(QString::fromUtf8("Edit_Serial_Other"));

        gridLayout2->addWidget(Edit_Serial_Other, 1, 0, 1, 1);

        TB_Serial_Other = new QToolButton(Tab_Serial_Port);
        TB_Serial_Other->setObjectName(QString::fromUtf8("TB_Serial_Other"));

        gridLayout2->addWidget(TB_Serial_Other, 1, 1, 1, 1);

        Label_Serial_Args = new QLabel(Tab_Serial_Port);
        Label_Serial_Args->setObjectName(QString::fromUtf8("Label_Serial_Args"));

        gridLayout2->addWidget(Label_Serial_Args, 0, 0, 1, 1);


        gridLayout1->addLayout(gridLayout2, 6, 0, 1, 5);

        RB_Serial_Telnet = new QRadioButton(Tab_Serial_Port);
        RB_Serial_Telnet->setObjectName(QString::fromUtf8("RB_Serial_Telnet"));

        gridLayout1->addWidget(RB_Serial_Telnet, 3, 4, 1, 1);

        RB_Serial_null = new QRadioButton(Tab_Serial_Port);
        RB_Serial_null->setObjectName(QString::fromUtf8("RB_Serial_null"));

        gridLayout1->addWidget(RB_Serial_null, 2, 2, 1, 1);

        RB_Serial_vc = new QRadioButton(Tab_Serial_Port);
        RB_Serial_vc->setObjectName(QString::fromUtf8("RB_Serial_vc"));

        gridLayout1->addWidget(RB_Serial_vc, 1, 2, 1, 1);

        spacerItem1 = new QSpacerItem(40, 121, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout1->addItem(spacerItem1, 1, 1, 5, 1);

        spacerItem2 = new QSpacerItem(21, 131, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout1->addItem(spacerItem2, 1, 3, 5, 1);

        tabWidget->addTab(Tab_Serial_Port, QString());
        Tab_Parallel_Port = new QWidget();
        Tab_Parallel_Port->setObjectName(QString::fromUtf8("Tab_Parallel_Port"));
        gridLayout3 = new QGridLayout(Tab_Parallel_Port);
#ifndef Q_OS_MAC
        gridLayout3->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        gridLayout3->setContentsMargins(9, 9, 9, 9);
#endif
        gridLayout3->setObjectName(QString::fromUtf8("gridLayout3"));
        spacerItem3 = new QSpacerItem(40, 131, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout3->addItem(spacerItem3, 1, 3, 5, 1);

        spacerItem4 = new QSpacerItem(40, 131, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout3->addItem(spacerItem4, 1, 1, 5, 1);

        spacerItem5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout3->addItem(spacerItem5, 7, 2, 1, 1);

        Label_Parallel_Port = new QLabel(Tab_Parallel_Port);
        Label_Parallel_Port->setObjectName(QString::fromUtf8("Label_Parallel_Port"));
        sizePolicy.setHeightForWidth(Label_Parallel_Port->sizePolicy().hasHeightForWidth());
        Label_Parallel_Port->setSizePolicy(sizePolicy);

        gridLayout3->addWidget(Label_Parallel_Port, 0, 0, 1, 5);

        gridLayout4 = new QGridLayout();
#ifndef Q_OS_MAC
        gridLayout4->setSpacing(6);
#endif
        gridLayout4->setContentsMargins(0, 0, 0, 0);
        gridLayout4->setObjectName(QString::fromUtf8("gridLayout4"));
        TB_Parallel_Other = new QToolButton(Tab_Parallel_Port);
        TB_Parallel_Other->setObjectName(QString::fromUtf8("TB_Parallel_Other"));

        gridLayout4->addWidget(TB_Parallel_Other, 1, 1, 1, 1);

        Label_Parallel_Args = new QLabel(Tab_Parallel_Port);
        Label_Parallel_Args->setObjectName(QString::fromUtf8("Label_Parallel_Args"));

        gridLayout4->addWidget(Label_Parallel_Args, 0, 0, 1, 1);

        Edit_Parallel_Other = new QLineEdit(Tab_Parallel_Port);
        Edit_Parallel_Other->setObjectName(QString::fromUtf8("Edit_Parallel_Other"));

        gridLayout4->addWidget(Edit_Parallel_Other, 1, 0, 1, 1);


        gridLayout3->addLayout(gridLayout4, 6, 0, 1, 5);

        RB_Parallel_Telnet = new QRadioButton(Tab_Parallel_Port);
        RB_Parallel_Telnet->setObjectName(QString::fromUtf8("RB_Parallel_Telnet"));

        gridLayout3->addWidget(RB_Parallel_Telnet, 3, 4, 1, 1);

        RB_Parallel_vc = new QRadioButton(Tab_Parallel_Port);
        RB_Parallel_vc->setObjectName(QString::fromUtf8("RB_Parallel_vc"));

        gridLayout3->addWidget(RB_Parallel_vc, 1, 2, 1, 1);

        RB_Parallel_null = new QRadioButton(Tab_Parallel_Port);
        RB_Parallel_null->setObjectName(QString::fromUtf8("RB_Parallel_null"));

        gridLayout3->addWidget(RB_Parallel_null, 2, 2, 1, 1);

        RB_Parallel_pty = new QRadioButton(Tab_Parallel_Port);
        RB_Parallel_pty->setObjectName(QString::fromUtf8("RB_Parallel_pty"));

        gridLayout3->addWidget(RB_Parallel_pty, 3, 2, 1, 1);

        RB_Parallel_Host_Port = new QRadioButton(Tab_Parallel_Port);
        RB_Parallel_Host_Port->setObjectName(QString::fromUtf8("RB_Parallel_Host_Port"));

        gridLayout3->addWidget(RB_Parallel_Host_Port, 4, 2, 1, 1);

        RB_Parallel_TCP = new QRadioButton(Tab_Parallel_Port);
        RB_Parallel_TCP->setObjectName(QString::fromUtf8("RB_Parallel_TCP"));

        gridLayout3->addWidget(RB_Parallel_TCP, 5, 2, 1, 1);

        RB_Parallel_Pipe = new QRadioButton(Tab_Parallel_Port);
        RB_Parallel_Pipe->setObjectName(QString::fromUtf8("RB_Parallel_Pipe"));

        gridLayout3->addWidget(RB_Parallel_Pipe, 4, 4, 1, 1);

        RB_Parallel_none = new QRadioButton(Tab_Parallel_Port);
        RB_Parallel_none->setObjectName(QString::fromUtf8("RB_Parallel_none"));

        gridLayout3->addWidget(RB_Parallel_none, 2, 4, 1, 1);

        RB_Parallel_stdio = new QRadioButton(Tab_Parallel_Port);
        RB_Parallel_stdio->setObjectName(QString::fromUtf8("RB_Parallel_stdio"));

        gridLayout3->addWidget(RB_Parallel_stdio, 1, 4, 1, 1);

        RB_Parallel_Default = new QRadioButton(Tab_Parallel_Port);
        RB_Parallel_Default->setObjectName(QString::fromUtf8("RB_Parallel_Default"));
        RB_Parallel_Default->setChecked(true);

        gridLayout3->addWidget(RB_Parallel_Default, 1, 0, 1, 1);

        RB_Parallel_Dev = new QRadioButton(Tab_Parallel_Port);
        RB_Parallel_Dev->setObjectName(QString::fromUtf8("RB_Parallel_Dev"));

        gridLayout3->addWidget(RB_Parallel_Dev, 2, 0, 1, 1);

        RB_Parallel_File = new QRadioButton(Tab_Parallel_Port);
        RB_Parallel_File->setObjectName(QString::fromUtf8("RB_Parallel_File"));

        gridLayout3->addWidget(RB_Parallel_File, 3, 0, 1, 1);

        RB_Parallel_Unix = new QRadioButton(Tab_Parallel_Port);
        RB_Parallel_Unix->setObjectName(QString::fromUtf8("RB_Parallel_Unix"));

        gridLayout3->addWidget(RB_Parallel_Unix, 4, 0, 1, 1);

        RB_Parallel_UDP = new QRadioButton(Tab_Parallel_Port);
        RB_Parallel_UDP->setObjectName(QString::fromUtf8("RB_Parallel_UDP"));

        gridLayout3->addWidget(RB_Parallel_UDP, 5, 0, 1, 1);

        tabWidget->addTab(Tab_Parallel_Port, QString());
        Tab_USB_Ports = new QWidget();
        Tab_USB_Ports->setObjectName(QString::fromUtf8("Tab_USB_Ports"));
        gridLayout5 = new QGridLayout(Tab_USB_Ports);
#ifndef Q_OS_MAC
        gridLayout5->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        gridLayout5->setContentsMargins(9, 9, 9, 9);
#endif
        gridLayout5->setObjectName(QString::fromUtf8("gridLayout5"));
        spacerItem6 = new QSpacerItem(431, 16, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout5->addItem(spacerItem6, 2, 0, 1, 1);

        CH_USB_Hub = new QCheckBox(Tab_USB_Ports);
        CH_USB_Hub->setObjectName(QString::fromUtf8("CH_USB_Hub"));
        CH_USB_Hub->setChecked(true);

        gridLayout5->addWidget(CH_USB_Hub, 0, 0, 1, 1);

        gridLayout6 = new QGridLayout();
#ifndef Q_OS_MAC
        gridLayout6->setSpacing(6);
#endif
        gridLayout6->setContentsMargins(0, 0, 0, 0);
        gridLayout6->setObjectName(QString::fromUtf8("gridLayout6"));
        Button_Clear_VM_USB_List = new QPushButton(Tab_USB_Ports);
        Button_Clear_VM_USB_List->setObjectName(QString::fromUtf8("Button_Clear_VM_USB_List"));

        gridLayout6->addWidget(Button_Clear_VM_USB_List, 2, 3, 1, 1);

        Button_Update_Host_USB = new QPushButton(Tab_USB_Ports);
        Button_Update_Host_USB->setObjectName(QString::fromUtf8("Button_Update_Host_USB"));

        gridLayout6->addWidget(Button_Update_Host_USB, 2, 2, 1, 1);

        Table_VM_USB = new QTableWidget(Tab_USB_Ports);
        if (Table_VM_USB->columnCount() < 2)
            Table_VM_USB->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        Table_VM_USB->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        Table_VM_USB->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        Table_VM_USB->setObjectName(QString::fromUtf8("Table_VM_USB"));
        Table_VM_USB->setEditTriggers(QAbstractItemView::NoEditTriggers);
        Table_VM_USB->setSelectionMode(QAbstractItemView::SingleSelection);
        Table_VM_USB->setSelectionBehavior(QAbstractItemView::SelectRows);
        Table_VM_USB->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        Table_VM_USB->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);

        gridLayout6->addWidget(Table_VM_USB, 4, 0, 1, 4);

        Label_VM_USB_Devices = new QLabel(Tab_USB_Ports);
        Label_VM_USB_Devices->setObjectName(QString::fromUtf8("Label_VM_USB_Devices"));

        gridLayout6->addWidget(Label_VM_USB_Devices, 3, 0, 1, 2);

        Label_Host_USB_Devices = new QLabel(Tab_USB_Ports);
        Label_Host_USB_Devices->setObjectName(QString::fromUtf8("Label_Host_USB_Devices"));

        gridLayout6->addWidget(Label_Host_USB_Devices, 0, 0, 1, 2);

        Button_Add_USB_Device = new QPushButton(Tab_USB_Ports);
        Button_Add_USB_Device->setObjectName(QString::fromUtf8("Button_Add_USB_Device"));

        gridLayout6->addWidget(Button_Add_USB_Device, 2, 0, 1, 1);

        Table_Host_USB = new QTableWidget(Tab_USB_Ports);
        if (Table_Host_USB->columnCount() < 2)
            Table_Host_USB->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        Table_Host_USB->setHorizontalHeaderItem(0, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        Table_Host_USB->setHorizontalHeaderItem(1, __qtablewidgetitem3);
        Table_Host_USB->setObjectName(QString::fromUtf8("Table_Host_USB"));
        Table_Host_USB->setEditTriggers(QAbstractItemView::NoEditTriggers);
        Table_Host_USB->setSelectionMode(QAbstractItemView::SingleSelection);
        Table_Host_USB->setSelectionBehavior(QAbstractItemView::SelectRows);
        Table_Host_USB->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        Table_Host_USB->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);

        gridLayout6->addWidget(Table_Host_USB, 1, 0, 1, 4);

        Button_Delete_USB_Device = new QPushButton(Tab_USB_Ports);
        Button_Delete_USB_Device->setObjectName(QString::fromUtf8("Button_Delete_USB_Device"));

        gridLayout6->addWidget(Button_Delete_USB_Device, 2, 1, 1, 1);


        gridLayout5->addLayout(gridLayout6, 1, 0, 1, 1);

        tabWidget->addTab(Tab_USB_Ports, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);

        QWidget::setTabOrder(tabWidget, RB_Serial_Default);
        QWidget::setTabOrder(RB_Serial_Default, RB_Serial_Dev);
        QWidget::setTabOrder(RB_Serial_Dev, RB_Serial_File);
        QWidget::setTabOrder(RB_Serial_File, RB_Serial_Unix);
        QWidget::setTabOrder(RB_Serial_Unix, RB_Serial_UDP);
        QWidget::setTabOrder(RB_Serial_UDP, RB_Serial_vc);
        QWidget::setTabOrder(RB_Serial_vc, RB_Serial_null);
        QWidget::setTabOrder(RB_Serial_null, RB_Serial_pty);
        QWidget::setTabOrder(RB_Serial_pty, RB_Serial_Host_Port);
        QWidget::setTabOrder(RB_Serial_Host_Port, RB_Serial_TCP);
        QWidget::setTabOrder(RB_Serial_TCP, RB_Serial_stdio);
        QWidget::setTabOrder(RB_Serial_stdio, RB_Serial_none);
        QWidget::setTabOrder(RB_Serial_none, RB_Serial_Telnet);
        QWidget::setTabOrder(RB_Serial_Telnet, RB_Serial_Pipe);
        QWidget::setTabOrder(RB_Serial_Pipe, Edit_Serial_Other);
        QWidget::setTabOrder(Edit_Serial_Other, TB_Serial_Other);
        QWidget::setTabOrder(TB_Serial_Other, RB_Parallel_Default);
        QWidget::setTabOrder(RB_Parallel_Default, RB_Parallel_Dev);
        QWidget::setTabOrder(RB_Parallel_Dev, RB_Parallel_File);
        QWidget::setTabOrder(RB_Parallel_File, RB_Parallel_Unix);
        QWidget::setTabOrder(RB_Parallel_Unix, RB_Parallel_UDP);
        QWidget::setTabOrder(RB_Parallel_UDP, RB_Parallel_vc);
        QWidget::setTabOrder(RB_Parallel_vc, RB_Parallel_null);
        QWidget::setTabOrder(RB_Parallel_null, RB_Parallel_pty);
        QWidget::setTabOrder(RB_Parallel_pty, RB_Parallel_Host_Port);
        QWidget::setTabOrder(RB_Parallel_Host_Port, RB_Parallel_TCP);
        QWidget::setTabOrder(RB_Parallel_TCP, RB_Parallel_stdio);
        QWidget::setTabOrder(RB_Parallel_stdio, RB_Parallel_none);
        QWidget::setTabOrder(RB_Parallel_none, RB_Parallel_Telnet);
        QWidget::setTabOrder(RB_Parallel_Telnet, RB_Parallel_Pipe);
        QWidget::setTabOrder(RB_Parallel_Pipe, Edit_Parallel_Other);
        QWidget::setTabOrder(Edit_Parallel_Other, TB_Parallel_Other);
        QWidget::setTabOrder(TB_Parallel_Other, CH_USB_Hub);
        QWidget::setTabOrder(CH_USB_Hub, Table_Host_USB);
        QWidget::setTabOrder(Table_Host_USB, Button_Add_USB_Device);
        QWidget::setTabOrder(Button_Add_USB_Device, Button_Delete_USB_Device);
        QWidget::setTabOrder(Button_Delete_USB_Device, Button_Update_Host_USB);
        QWidget::setTabOrder(Button_Update_Host_USB, Button_Clear_VM_USB_List);
        QWidget::setTabOrder(Button_Clear_VM_USB_List, Table_VM_USB);

        retranslateUi(Ports_Tab_Widget);
        QObject::connect(CH_USB_Hub, SIGNAL(toggled(bool)), Button_Delete_USB_Device, SLOT(setEnabled(bool)));
        QObject::connect(CH_USB_Hub, SIGNAL(toggled(bool)), Button_Update_Host_USB, SLOT(setEnabled(bool)));
        QObject::connect(CH_USB_Hub, SIGNAL(toggled(bool)), Button_Clear_VM_USB_List, SLOT(setEnabled(bool)));
        QObject::connect(CH_USB_Hub, SIGNAL(toggled(bool)), Button_Add_USB_Device, SLOT(setEnabled(bool)));
        QObject::connect(CH_USB_Hub, SIGNAL(toggled(bool)), Label_VM_USB_Devices, SLOT(setEnabled(bool)));
        QObject::connect(CH_USB_Hub, SIGNAL(toggled(bool)), Label_Host_USB_Devices, SLOT(setEnabled(bool)));
        QObject::connect(CH_USB_Hub, SIGNAL(toggled(bool)), Table_Host_USB, SLOT(setEnabled(bool)));
        QObject::connect(CH_USB_Hub, SIGNAL(toggled(bool)), Table_VM_USB, SLOT(setEnabled(bool)));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Ports_Tab_Widget);
    } // setupUi

    void retranslateUi(QWidget *Ports_Tab_Widget)
    {
        Ports_Tab_Widget->setWindowTitle(QApplication::translate("Ports_Tab_Widget", "Ports", nullptr));
        RB_Serial_UDP->setText(QApplication::translate("Ports_Tab_Widget", "UDP", nullptr));
        RB_Serial_Unix->setText(QApplication::translate("Ports_Tab_Widget", "Unix", nullptr));
        RB_Serial_File->setText(QApplication::translate("Ports_Tab_Widget", "File", nullptr));
        RB_Serial_Dev->setText(QApplication::translate("Ports_Tab_Widget", "/dev/", nullptr));
        RB_Serial_Default->setText(QApplication::translate("Ports_Tab_Widget", "Default", nullptr));
        RB_Serial_stdio->setText(QApplication::translate("Ports_Tab_Widget", "stdio", nullptr));
        RB_Serial_none->setText(QApplication::translate("Ports_Tab_Widget", "none", nullptr));
        RB_Serial_Pipe->setText(QApplication::translate("Ports_Tab_Widget", "Pipe", nullptr));
        RB_Serial_TCP->setText(QApplication::translate("Ports_Tab_Widget", "TCP", nullptr));
        RB_Serial_pty->setText(QApplication::translate("Ports_Tab_Widget", "pty (Pseudo TTY)", nullptr));
        RB_Serial_Host_Port->setText(QApplication::translate("Ports_Tab_Widget", "Host Port", nullptr));
        Label_Serial_Port->setText(QApplication::translate("Ports_Tab_Widget", "Select redirect virtual serial port to:", nullptr));
        TB_Serial_Other->setText(QApplication::translate("Ports_Tab_Widget", "...", nullptr));
        Label_Serial_Args->setText(QApplication::translate("Ports_Tab_Widget", "Additional QEMU Arguments:", nullptr));
        RB_Serial_Telnet->setText(QApplication::translate("Ports_Tab_Widget", "Telnet", nullptr));
        RB_Serial_null->setText(QApplication::translate("Ports_Tab_Widget", "null (/dev/null)", nullptr));
        RB_Serial_vc->setText(QApplication::translate("Ports_Tab_Widget", "vc (Virtual console)", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Tab_Serial_Port), QApplication::translate("Ports_Tab_Widget", "&Serial Port", nullptr));
        Label_Parallel_Port->setText(QApplication::translate("Ports_Tab_Widget", "Select redirect virtual parallel port to:", nullptr));
        TB_Parallel_Other->setText(QApplication::translate("Ports_Tab_Widget", "...", nullptr));
        Label_Parallel_Args->setText(QApplication::translate("Ports_Tab_Widget", "Additional QEMU Arguments:", nullptr));
        RB_Parallel_Telnet->setText(QApplication::translate("Ports_Tab_Widget", "Telnet", nullptr));
        RB_Parallel_vc->setText(QApplication::translate("Ports_Tab_Widget", "vc (Virtual console)", nullptr));
        RB_Parallel_null->setText(QApplication::translate("Ports_Tab_Widget", "null (/dev/null)", nullptr));
        RB_Parallel_pty->setText(QApplication::translate("Ports_Tab_Widget", "pty (Pseudo TTY)", nullptr));
        RB_Parallel_Host_Port->setText(QApplication::translate("Ports_Tab_Widget", "Host Port", nullptr));
        RB_Parallel_TCP->setText(QApplication::translate("Ports_Tab_Widget", "TCP", nullptr));
        RB_Parallel_Pipe->setText(QApplication::translate("Ports_Tab_Widget", "Pipe", nullptr));
        RB_Parallel_none->setText(QApplication::translate("Ports_Tab_Widget", "none", nullptr));
        RB_Parallel_stdio->setText(QApplication::translate("Ports_Tab_Widget", "stdio", nullptr));
        RB_Parallel_Default->setText(QApplication::translate("Ports_Tab_Widget", "Default", nullptr));
        RB_Parallel_Dev->setText(QApplication::translate("Ports_Tab_Widget", "/dev/", nullptr));
        RB_Parallel_File->setText(QApplication::translate("Ports_Tab_Widget", "File", nullptr));
        RB_Parallel_Unix->setText(QApplication::translate("Ports_Tab_Widget", "Unix", nullptr));
        RB_Parallel_UDP->setText(QApplication::translate("Ports_Tab_Widget", "UDP", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Tab_Parallel_Port), QApplication::translate("Ports_Tab_Widget", "Para&llel Port", nullptr));
        CH_USB_Hub->setText(QApplication::translate("Ports_Tab_Widget", "Enable VM USB Controller", nullptr));
        Button_Clear_VM_USB_List->setText(QApplication::translate("Ports_Tab_Widget", "Clear VM USB", nullptr));
        Button_Update_Host_USB->setText(QApplication::translate("Ports_Tab_Widget", "Update USB Host List", nullptr));
        QTableWidgetItem *___qtablewidgetitem = Table_VM_USB->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Ports_Tab_Widget", "Manufacturer:", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = Table_VM_USB->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("Ports_Tab_Widget", "Product:", nullptr));
        Label_VM_USB_Devices->setText(QApplication::translate("Ports_Tab_Widget", "Virtual Machine USB Devices:", nullptr));
        Label_Host_USB_Devices->setText(QApplication::translate("Ports_Tab_Widget", "Host USB Devices:", nullptr));
        Button_Add_USB_Device->setText(QApplication::translate("Ports_Tab_Widget", "Add To VM", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = Table_Host_USB->horizontalHeaderItem(0);
        ___qtablewidgetitem2->setText(QApplication::translate("Ports_Tab_Widget", "Manufacturer:", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = Table_Host_USB->horizontalHeaderItem(1);
        ___qtablewidgetitem3->setText(QApplication::translate("Ports_Tab_Widget", "Product:", nullptr));
        Button_Delete_USB_Device->setText(QApplication::translate("Ports_Tab_Widget", "Delete From VM", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Tab_USB_Ports), QApplication::translate("Ports_Tab_Widget", "&USB Ports", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Ports_Tab_Widget: public Ui_Ports_Tab_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PORTS_TAB_WIDGET_H
