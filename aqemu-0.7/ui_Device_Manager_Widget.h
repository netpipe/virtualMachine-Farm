/********************************************************************************
** Form generated from reading UI file 'Device_Manager_Widget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEVICE_MANAGER_WIDGET_H
#define UI_DEVICE_MANAGER_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Device_Manager_Widget
{
public:
    QAction *actionAdd_Floppy;
    QAction *actionAdd_CD_ROM;
    QAction *actionAdd_HDD;
    QAction *actionFormat_HDD;
    QAction *actionProperties;
    QAction *actionDelete;
    QAction *actionList_Mode;
    QAction *actionIcon_Mode;
    QAction *actionQuick_Format;
    QAction *actionAdd_Device;
    QGridLayout *gridLayout;
    QSpacerItem *spacerItem;
    QFrame *line;
    QGridLayout *gridLayout1;
    QLabel *Label_View_Mode;
    QHBoxLayout *hboxLayout;
    QToolButton *TB_Icon_Mode;
    QToolButton *TB_List_Mode;
    QVBoxLayout *vboxLayout;
    QLabel *Label_Manage_Devices;
    QHBoxLayout *hboxLayout1;
    QToolButton *TB_Edit_Device;
    QToolButton *TB_Delete_Device;
    QToolButton *TB_Format_HDD;
    QToolButton *TB_Quick_Format;
    QFrame *line_3;
    QVBoxLayout *vboxLayout1;
    QLabel *Label_Add_Devices;
    QHBoxLayout *hboxLayout2;
    QToolButton *TB_Add_Floppy;
    QToolButton *TB_Add_CDROM;
    QToolButton *TB_Add_HDD;
    QToolButton *TB_Add_Device;
    QFrame *line_2;
    QVBoxLayout *vboxLayout2;
    QLabel *Label_Devices_List;
    QListWidget *Devices_List;
    QLabel *Label_Information;
    QLabel *Label_Connected_To;

    void setupUi(QWidget *Device_Manager_Widget)
    {
        if (Device_Manager_Widget->objectName().isEmpty())
            Device_Manager_Widget->setObjectName(QString::fromUtf8("Device_Manager_Widget"));
        Device_Manager_Widget->resize(544, 265);
        actionAdd_Floppy = new QAction(Device_Manager_Widget);
        actionAdd_Floppy->setObjectName(QString::fromUtf8("actionAdd_Floppy"));
        const QIcon icon = QIcon(QString::fromUtf8(":/images/3floppy_unmount.png"));
        actionAdd_Floppy->setIcon(icon);
        actionAdd_CD_ROM = new QAction(Device_Manager_Widget);
        actionAdd_CD_ROM->setObjectName(QString::fromUtf8("actionAdd_CD_ROM"));
        const QIcon icon1 = QIcon(QString::fromUtf8(":/images/cdrom_unmount.png"));
        actionAdd_CD_ROM->setIcon(icon1);
        actionAdd_HDD = new QAction(Device_Manager_Widget);
        actionAdd_HDD->setObjectName(QString::fromUtf8("actionAdd_HDD"));
        const QIcon icon2 = QIcon(QString::fromUtf8(":/images/hdd_unmount.png"));
        actionAdd_HDD->setIcon(icon2);
        actionFormat_HDD = new QAction(Device_Manager_Widget);
        actionFormat_HDD->setObjectName(QString::fromUtf8("actionFormat_HDD"));
        const QIcon icon3 = QIcon(QString::fromUtf8(":/images/wizard.png"));
        actionFormat_HDD->setIcon(icon3);
        actionProperties = new QAction(Device_Manager_Widget);
        actionProperties->setObjectName(QString::fromUtf8("actionProperties"));
        const QIcon icon4 = QIcon(QString::fromUtf8(":/images/edit.png"));
        actionProperties->setIcon(icon4);
        actionDelete = new QAction(Device_Manager_Widget);
        actionDelete->setObjectName(QString::fromUtf8("actionDelete"));
        const QIcon icon5 = QIcon(QString::fromUtf8(":/images/button_cancel.png"));
        actionDelete->setIcon(icon5);
        actionList_Mode = new QAction(Device_Manager_Widget);
        actionList_Mode->setObjectName(QString::fromUtf8("actionList_Mode"));
        const QIcon icon6 = QIcon(QString::fromUtf8(":/images/view_detailed.png"));
        actionList_Mode->setIcon(icon6);
        actionIcon_Mode = new QAction(Device_Manager_Widget);
        actionIcon_Mode->setObjectName(QString::fromUtf8("actionIcon_Mode"));
        const QIcon icon7 = QIcon(QString::fromUtf8(":/images/view_icon.png"));
        actionIcon_Mode->setIcon(icon7);
        actionQuick_Format = new QAction(Device_Manager_Widget);
        actionQuick_Format->setObjectName(QString::fromUtf8("actionQuick_Format"));
        const QIcon icon8 = QIcon(QString::fromUtf8(":/images/reload.png"));
        actionQuick_Format->setIcon(icon8);
        actionAdd_Device = new QAction(Device_Manager_Widget);
        actionAdd_Device->setObjectName(QString::fromUtf8("actionAdd_Device"));
        const QIcon icon9 = QIcon(QString::fromUtf8(":/images/add.png"));
        actionAdd_Device->setIcon(icon9);
        gridLayout = new QGridLayout(Device_Manager_Widget);
#ifndef Q_OS_MAC
        gridLayout->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        gridLayout->setContentsMargins(9, 9, 9, 9);
#endif
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        spacerItem = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(spacerItem, 0, 5, 1, 1);

        line = new QFrame(Device_Manager_Widget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 0, 3, 1, 1);

        gridLayout1 = new QGridLayout();
#ifndef Q_OS_MAC
        gridLayout1->setSpacing(6);
#endif
        gridLayout1->setContentsMargins(0, 0, 0, 0);
        gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
        Label_View_Mode = new QLabel(Device_Manager_Widget);
        Label_View_Mode->setObjectName(QString::fromUtf8("Label_View_Mode"));

        gridLayout1->addWidget(Label_View_Mode, 0, 0, 1, 1);

        hboxLayout = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout->setSpacing(6);
#endif
        hboxLayout->setContentsMargins(0, 0, 0, 0);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        TB_Icon_Mode = new QToolButton(Device_Manager_Widget);
        TB_Icon_Mode->setObjectName(QString::fromUtf8("TB_Icon_Mode"));
        TB_Icon_Mode->setIcon(icon7);
        TB_Icon_Mode->setIconSize(QSize(32, 32));

        hboxLayout->addWidget(TB_Icon_Mode);

        TB_List_Mode = new QToolButton(Device_Manager_Widget);
        TB_List_Mode->setObjectName(QString::fromUtf8("TB_List_Mode"));
        TB_List_Mode->setIcon(icon6);
        TB_List_Mode->setIconSize(QSize(32, 32));

        hboxLayout->addWidget(TB_List_Mode);


        gridLayout1->addLayout(hboxLayout, 1, 0, 1, 1);


        gridLayout->addLayout(gridLayout1, 0, 4, 1, 1);

        vboxLayout = new QVBoxLayout();
#ifndef Q_OS_MAC
        vboxLayout->setSpacing(6);
#endif
        vboxLayout->setContentsMargins(0, 0, 0, 0);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        Label_Manage_Devices = new QLabel(Device_Manager_Widget);
        Label_Manage_Devices->setObjectName(QString::fromUtf8("Label_Manage_Devices"));

        vboxLayout->addWidget(Label_Manage_Devices);

        hboxLayout1 = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout1->setSpacing(6);
#endif
        hboxLayout1->setContentsMargins(0, 0, 0, 0);
        hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
        TB_Edit_Device = new QToolButton(Device_Manager_Widget);
        TB_Edit_Device->setObjectName(QString::fromUtf8("TB_Edit_Device"));
        TB_Edit_Device->setIcon(icon4);
        TB_Edit_Device->setIconSize(QSize(32, 32));

        hboxLayout1->addWidget(TB_Edit_Device);

        TB_Delete_Device = new QToolButton(Device_Manager_Widget);
        TB_Delete_Device->setObjectName(QString::fromUtf8("TB_Delete_Device"));
        TB_Delete_Device->setIcon(icon5);
        TB_Delete_Device->setIconSize(QSize(32, 32));

        hboxLayout1->addWidget(TB_Delete_Device);

        TB_Format_HDD = new QToolButton(Device_Manager_Widget);
        TB_Format_HDD->setObjectName(QString::fromUtf8("TB_Format_HDD"));
        const QIcon icon10 = QIcon(QString::fromUtf8(":/images/hdd_mount.png"));
        TB_Format_HDD->setIcon(icon10);
        TB_Format_HDD->setIconSize(QSize(32, 32));

        hboxLayout1->addWidget(TB_Format_HDD);

        TB_Quick_Format = new QToolButton(Device_Manager_Widget);
        TB_Quick_Format->setObjectName(QString::fromUtf8("TB_Quick_Format"));
        const QIcon icon11 = QIcon(QString::fromUtf8(":/images/eraser.png"));
        TB_Quick_Format->setIcon(icon11);
        TB_Quick_Format->setIconSize(QSize(32, 32));

        hboxLayout1->addWidget(TB_Quick_Format);


        vboxLayout->addLayout(hboxLayout1);


        gridLayout->addLayout(vboxLayout, 0, 2, 1, 1);

        line_3 = new QFrame(Device_Manager_Widget);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_3, 0, 1, 1, 1);

        vboxLayout1 = new QVBoxLayout();
#ifndef Q_OS_MAC
        vboxLayout1->setSpacing(6);
#endif
        vboxLayout1->setContentsMargins(0, 0, 0, 0);
        vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
        Label_Add_Devices = new QLabel(Device_Manager_Widget);
        Label_Add_Devices->setObjectName(QString::fromUtf8("Label_Add_Devices"));

        vboxLayout1->addWidget(Label_Add_Devices);

        hboxLayout2 = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout2->setSpacing(6);
#endif
        hboxLayout2->setContentsMargins(0, 0, 0, 0);
        hboxLayout2->setObjectName(QString::fromUtf8("hboxLayout2"));
        TB_Add_Floppy = new QToolButton(Device_Manager_Widget);
        TB_Add_Floppy->setObjectName(QString::fromUtf8("TB_Add_Floppy"));
        TB_Add_Floppy->setIcon(icon);
        TB_Add_Floppy->setIconSize(QSize(32, 32));

        hboxLayout2->addWidget(TB_Add_Floppy);

        TB_Add_CDROM = new QToolButton(Device_Manager_Widget);
        TB_Add_CDROM->setObjectName(QString::fromUtf8("TB_Add_CDROM"));
        TB_Add_CDROM->setIcon(icon1);
        TB_Add_CDROM->setIconSize(QSize(32, 32));

        hboxLayout2->addWidget(TB_Add_CDROM);

        TB_Add_HDD = new QToolButton(Device_Manager_Widget);
        TB_Add_HDD->setObjectName(QString::fromUtf8("TB_Add_HDD"));
        TB_Add_HDD->setIcon(icon2);
        TB_Add_HDD->setIconSize(QSize(32, 32));

        hboxLayout2->addWidget(TB_Add_HDD);

        TB_Add_Device = new QToolButton(Device_Manager_Widget);
        TB_Add_Device->setObjectName(QString::fromUtf8("TB_Add_Device"));
        TB_Add_Device->setEnabled(false);
        TB_Add_Device->setIcon(icon9);
        TB_Add_Device->setIconSize(QSize(32, 32));

        hboxLayout2->addWidget(TB_Add_Device);


        vboxLayout1->addLayout(hboxLayout2);


        gridLayout->addLayout(vboxLayout1, 0, 0, 1, 1);

        line_2 = new QFrame(Device_Manager_Widget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_2, 1, 0, 1, 6);

        vboxLayout2 = new QVBoxLayout();
#ifndef Q_OS_MAC
        vboxLayout2->setSpacing(6);
#endif
        vboxLayout2->setContentsMargins(0, 0, 0, 0);
        vboxLayout2->setObjectName(QString::fromUtf8("vboxLayout2"));
        Label_Devices_List = new QLabel(Device_Manager_Widget);
        Label_Devices_List->setObjectName(QString::fromUtf8("Label_Devices_List"));

        vboxLayout2->addWidget(Label_Devices_List);

        Devices_List = new QListWidget(Device_Manager_Widget);
        Devices_List->setObjectName(QString::fromUtf8("Devices_List"));
        Devices_List->setContextMenuPolicy(Qt::CustomContextMenu);
        Devices_List->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        Devices_List->setIconSize(QSize(32, 32));
        Devices_List->setTextElideMode(Qt::ElideMiddle);
        Devices_List->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        Devices_List->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
        Devices_List->setMovement(QListView::Static);
        Devices_List->setFlow(QListView::LeftToRight);
        Devices_List->setSpacing(10);
        Devices_List->setViewMode(QListView::IconMode);

        vboxLayout2->addWidget(Devices_List);

        Label_Information = new QLabel(Device_Manager_Widget);
        Label_Information->setObjectName(QString::fromUtf8("Label_Information"));
        QSizePolicy sizePolicy(static_cast<QSizePolicy::Policy>(4), static_cast<QSizePolicy::Policy>(5));
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Label_Information->sizePolicy().hasHeightForWidth());
        Label_Information->setSizePolicy(sizePolicy);

        vboxLayout2->addWidget(Label_Information);

        Label_Connected_To = new QLabel(Device_Manager_Widget);
        Label_Connected_To->setObjectName(QString::fromUtf8("Label_Connected_To"));

        vboxLayout2->addWidget(Label_Connected_To);


        gridLayout->addLayout(vboxLayout2, 2, 0, 1, 6);

        QWidget::setTabOrder(TB_Add_Floppy, TB_Add_CDROM);
        QWidget::setTabOrder(TB_Add_CDROM, TB_Add_HDD);
        QWidget::setTabOrder(TB_Add_HDD, TB_Edit_Device);
        QWidget::setTabOrder(TB_Edit_Device, TB_Delete_Device);
        QWidget::setTabOrder(TB_Delete_Device, TB_Format_HDD);
        QWidget::setTabOrder(TB_Format_HDD, TB_Quick_Format);
        QWidget::setTabOrder(TB_Quick_Format, TB_Icon_Mode);
        QWidget::setTabOrder(TB_Icon_Mode, TB_List_Mode);
        QWidget::setTabOrder(TB_List_Mode, Devices_List);

        retranslateUi(Device_Manager_Widget);
        QObject::connect(TB_Add_Floppy, SIGNAL(clicked()), actionAdd_Floppy, SLOT(trigger()));
        QObject::connect(TB_Add_CDROM, SIGNAL(clicked()), actionAdd_CD_ROM, SLOT(trigger()));
        QObject::connect(TB_Add_HDD, SIGNAL(clicked()), actionAdd_HDD, SLOT(trigger()));
        QObject::connect(TB_Edit_Device, SIGNAL(clicked()), actionProperties, SLOT(trigger()));
        QObject::connect(TB_Delete_Device, SIGNAL(clicked()), actionDelete, SLOT(trigger()));
        QObject::connect(TB_Icon_Mode, SIGNAL(clicked()), actionIcon_Mode, SLOT(trigger()));
        QObject::connect(TB_List_Mode, SIGNAL(clicked()), actionList_Mode, SLOT(trigger()));
        QObject::connect(TB_Format_HDD, SIGNAL(clicked()), actionFormat_HDD, SLOT(trigger()));
        QObject::connect(TB_Quick_Format, SIGNAL(clicked()), actionQuick_Format, SLOT(trigger()));
        QObject::connect(TB_Add_Device, SIGNAL(clicked()), actionAdd_Device, SLOT(trigger()));

        QMetaObject::connectSlotsByName(Device_Manager_Widget);
    } // setupUi

    void retranslateUi(QWidget *Device_Manager_Widget)
    {
        Device_Manager_Widget->setWindowTitle(QApplication::translate("Device_Manager_Widget", "Device Manager Widget", nullptr));
        actionAdd_Floppy->setText(QApplication::translate("Device_Manager_Widget", "Add Floppy", nullptr));
        actionAdd_CD_ROM->setText(QApplication::translate("Device_Manager_Widget", "Add CD/DVD-ROM", nullptr));
        actionAdd_HDD->setText(QApplication::translate("Device_Manager_Widget", "Add HDD", nullptr));
        actionFormat_HDD->setText(QApplication::translate("Device_Manager_Widget", "Format HDD", nullptr));
        actionProperties->setText(QApplication::translate("Device_Manager_Widget", "Properties", nullptr));
        actionProperties->setIconText(QApplication::translate("Device_Manager_Widget", "Properties", nullptr));
#ifndef QT_NO_TOOLTIP
        actionProperties->setToolTip(QApplication::translate("Device_Manager_Widget", "Properties", nullptr));
#endif // QT_NO_TOOLTIP
        actionDelete->setText(QApplication::translate("Device_Manager_Widget", "Delete", nullptr));
        actionList_Mode->setText(QApplication::translate("Device_Manager_Widget", "List Mode", nullptr));
        actionIcon_Mode->setText(QApplication::translate("Device_Manager_Widget", "Icon Mode", nullptr));
        actionQuick_Format->setText(QApplication::translate("Device_Manager_Widget", "Quick Format", nullptr));
        actionAdd_Device->setText(QApplication::translate("Device_Manager_Widget", "Add Device", nullptr));
        actionAdd_Device->setIconText(QApplication::translate("Device_Manager_Widget", "Add Device", nullptr));
#ifndef QT_NO_TOOLTIP
        actionAdd_Device->setToolTip(QApplication::translate("Device_Manager_Widget", "Add Device", nullptr));
#endif // QT_NO_TOOLTIP
        Label_View_Mode->setText(QApplication::translate("Device_Manager_Widget", "View Mode", nullptr));
#ifndef QT_NO_TOOLTIP
        TB_Icon_Mode->setToolTip(QApplication::translate("Device_Manager_Widget", "Icon Mode", nullptr));
#endif // QT_NO_TOOLTIP
        TB_Icon_Mode->setText(QString());
#ifndef QT_NO_TOOLTIP
        TB_List_Mode->setToolTip(QApplication::translate("Device_Manager_Widget", "List Mode", nullptr));
#endif // QT_NO_TOOLTIP
        TB_List_Mode->setText(QString());
        Label_Manage_Devices->setText(QApplication::translate("Device_Manager_Widget", "Manage Devices", nullptr));
#ifndef QT_NO_TOOLTIP
        TB_Edit_Device->setToolTip(QApplication::translate("Device_Manager_Widget", "Properties", nullptr));
#endif // QT_NO_TOOLTIP
        TB_Edit_Device->setText(QString());
#ifndef QT_NO_TOOLTIP
        TB_Delete_Device->setToolTip(QApplication::translate("Device_Manager_Widget", "Delete", nullptr));
#endif // QT_NO_TOOLTIP
        TB_Delete_Device->setText(QString());
#ifndef QT_NO_TOOLTIP
        TB_Format_HDD->setToolTip(QApplication::translate("Device_Manager_Widget", "Format HDD", nullptr));
#endif // QT_NO_TOOLTIP
        TB_Format_HDD->setText(QString());
#ifndef QT_NO_TOOLTIP
        TB_Quick_Format->setToolTip(QApplication::translate("Device_Manager_Widget", "Quick Format", nullptr));
#endif // QT_NO_TOOLTIP
        TB_Quick_Format->setText(QApplication::translate("Device_Manager_Widget", "Quick Format", nullptr));
        Label_Add_Devices->setText(QApplication::translate("Device_Manager_Widget", "Add Devices", nullptr));
#ifndef QT_NO_TOOLTIP
        TB_Add_Floppy->setToolTip(QApplication::translate("Device_Manager_Widget", "Add Floppy", nullptr));
#endif // QT_NO_TOOLTIP
        TB_Add_Floppy->setText(QString());
#ifndef QT_NO_TOOLTIP
        TB_Add_CDROM->setToolTip(QApplication::translate("Device_Manager_Widget", "Add CD/DVD-ROM", nullptr));
#endif // QT_NO_TOOLTIP
        TB_Add_CDROM->setText(QString());
#ifndef QT_NO_TOOLTIP
        TB_Add_HDD->setToolTip(QApplication::translate("Device_Manager_Widget", "Add HDD", nullptr));
#endif // QT_NO_TOOLTIP
        TB_Add_HDD->setText(QString());
#ifndef QT_NO_TOOLTIP
        TB_Add_Device->setToolTip(QApplication::translate("Device_Manager_Widget", "Add Storage Device", nullptr));
#endif // QT_NO_TOOLTIP
        TB_Add_Device->setText(QString());
        Label_Devices_List->setText(QApplication::translate("Device_Manager_Widget", "Devices List:", nullptr));
        Label_Information->setText(QApplication::translate("Device_Manager_Widget", "Information:", nullptr));
        Label_Connected_To->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Device_Manager_Widget: public Ui_Device_Manager_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEVICE_MANAGER_WIDGET_H
