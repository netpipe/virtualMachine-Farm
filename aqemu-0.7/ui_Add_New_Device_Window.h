/********************************************************************************
** Form generated from reading UI file 'Add_New_Device_Window.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADD_NEW_DEVICE_WINDOW_H
#define UI_ADD_NEW_DEVICE_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QToolButton>

QT_BEGIN_NAMESPACE

class Ui_Add_New_Device_Window
{
public:
    QGridLayout *gridLayout;
    QGridLayout *gridLayout1;
    QCheckBox *CH_Bus_Unit;
    QSpinBox *SB_Index;
    QSpinBox *SB_Unit;
    QSpinBox *SB_Bus;
    QCheckBox *CH_Index;
    QCheckBox *CH_Snapshot;
    QHBoxLayout *hboxLayout;
    QSpacerItem *spacerItem;
    QPushButton *Button_OK;
    QPushButton *Button_Cancel;
    QCheckBox *CH_Cache;
    QGridLayout *gridLayout2;
    QComboBox *CB_Media;
    QComboBox *CB_Interface;
    QLineEdit *Edit_File_Path;
    QToolButton *TB_File_Path_Browse;
    QCheckBox *CH_Media;
    QCheckBox *CH_File;
    QCheckBox *CH_Interface;
    QSpacerItem *spacerItem1;
    QGroupBox *GB_hdachs_Settings;
    QGridLayout *gridLayout3;
    QSpacerItem *spacerItem2;
    QGridLayout *gridLayout4;
    QLineEdit *Edit_Trans;
    QLineEdit *Edit_Secs;
    QLabel *Label_Secs;
    QLabel *Label_Trans;
    QGridLayout *gridLayout5;
    QLabel *Label_Cyls;
    QLineEdit *Edit_Cyls;
    QLabel *Label_Heads;
    QLineEdit *Edit_Heads;

    void setupUi(QDialog *Add_New_Device_Window)
    {
        if (Add_New_Device_Window->objectName().isEmpty())
            Add_New_Device_Window->setObjectName(QString::fromUtf8("Add_New_Device_Window"));
        Add_New_Device_Window->resize(329, 332);
        gridLayout = new QGridLayout(Add_New_Device_Window);
#ifndef Q_OS_MAC
        gridLayout->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        gridLayout->setContentsMargins(9, 9, 9, 9);
#endif
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout1 = new QGridLayout();
#ifndef Q_OS_MAC
        gridLayout1->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        gridLayout1->setContentsMargins(0, 0, 0, 0);
#endif
        gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
        CH_Bus_Unit = new QCheckBox(Add_New_Device_Window);
        CH_Bus_Unit->setObjectName(QString::fromUtf8("CH_Bus_Unit"));

        gridLayout1->addWidget(CH_Bus_Unit, 1, 0, 1, 1);

        SB_Index = new QSpinBox(Add_New_Device_Window);
        SB_Index->setObjectName(QString::fromUtf8("SB_Index"));
        SB_Index->setEnabled(false);

        gridLayout1->addWidget(SB_Index, 0, 1, 1, 2);

        SB_Unit = new QSpinBox(Add_New_Device_Window);
        SB_Unit->setObjectName(QString::fromUtf8("SB_Unit"));
        SB_Unit->setEnabled(false);

        gridLayout1->addWidget(SB_Unit, 1, 2, 1, 1);

        SB_Bus = new QSpinBox(Add_New_Device_Window);
        SB_Bus->setObjectName(QString::fromUtf8("SB_Bus"));
        SB_Bus->setEnabled(false);

        gridLayout1->addWidget(SB_Bus, 1, 1, 1, 1);

        CH_Index = new QCheckBox(Add_New_Device_Window);
        CH_Index->setObjectName(QString::fromUtf8("CH_Index"));

        gridLayout1->addWidget(CH_Index, 0, 0, 1, 1);


        gridLayout->addLayout(gridLayout1, 1, 0, 1, 3);

        CH_Snapshot = new QCheckBox(Add_New_Device_Window);
        CH_Snapshot->setObjectName(QString::fromUtf8("CH_Snapshot"));

        gridLayout->addWidget(CH_Snapshot, 2, 0, 1, 1);

        hboxLayout = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout->setSpacing(6);
#endif
        hboxLayout->setContentsMargins(0, 0, 0, 0);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        spacerItem = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(spacerItem);

        Button_OK = new QPushButton(Add_New_Device_Window);
        Button_OK->setObjectName(QString::fromUtf8("Button_OK"));

        hboxLayout->addWidget(Button_OK);

        Button_Cancel = new QPushButton(Add_New_Device_Window);
        Button_Cancel->setObjectName(QString::fromUtf8("Button_Cancel"));

        hboxLayout->addWidget(Button_Cancel);


        gridLayout->addLayout(hboxLayout, 4, 0, 1, 3);

        CH_Cache = new QCheckBox(Add_New_Device_Window);
        CH_Cache->setObjectName(QString::fromUtf8("CH_Cache"));

        gridLayout->addWidget(CH_Cache, 2, 2, 1, 1);

        gridLayout2 = new QGridLayout();
#ifndef Q_OS_MAC
        gridLayout2->setSpacing(6);
#endif
        gridLayout2->setContentsMargins(0, 0, 0, 0);
        gridLayout2->setObjectName(QString::fromUtf8("gridLayout2"));
        CB_Media = new QComboBox(Add_New_Device_Window);
        CB_Media->addItem(QString());
        CB_Media->addItem(QString());
        CB_Media->setObjectName(QString::fromUtf8("CB_Media"));
        CB_Media->setEnabled(false);

        gridLayout2->addWidget(CB_Media, 1, 1, 1, 2);

        CB_Interface = new QComboBox(Add_New_Device_Window);
        CB_Interface->addItem(QString());
        CB_Interface->addItem(QString());
        CB_Interface->addItem(QString());
        CB_Interface->addItem(QString());
        CB_Interface->addItem(QString());
        CB_Interface->addItem(QString());
        CB_Interface->setObjectName(QString::fromUtf8("CB_Interface"));
        CB_Interface->setEnabled(false);

        gridLayout2->addWidget(CB_Interface, 0, 1, 1, 2);

        Edit_File_Path = new QLineEdit(Add_New_Device_Window);
        Edit_File_Path->setObjectName(QString::fromUtf8("Edit_File_Path"));
        Edit_File_Path->setEnabled(false);

        gridLayout2->addWidget(Edit_File_Path, 2, 1, 1, 1);

        TB_File_Path_Browse = new QToolButton(Add_New_Device_Window);
        TB_File_Path_Browse->setObjectName(QString::fromUtf8("TB_File_Path_Browse"));
        TB_File_Path_Browse->setEnabled(false);

        gridLayout2->addWidget(TB_File_Path_Browse, 2, 2, 1, 1);

        CH_Media = new QCheckBox(Add_New_Device_Window);
        CH_Media->setObjectName(QString::fromUtf8("CH_Media"));

        gridLayout2->addWidget(CH_Media, 1, 0, 1, 1);

        CH_File = new QCheckBox(Add_New_Device_Window);
        CH_File->setObjectName(QString::fromUtf8("CH_File"));

        gridLayout2->addWidget(CH_File, 2, 0, 1, 1);

        CH_Interface = new QCheckBox(Add_New_Device_Window);
        CH_Interface->setObjectName(QString::fromUtf8("CH_Interface"));

        gridLayout2->addWidget(CH_Interface, 0, 0, 1, 1);


        gridLayout->addLayout(gridLayout2, 0, 0, 1, 3);

        spacerItem1 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(spacerItem1, 2, 1, 1, 1);

        GB_hdachs_Settings = new QGroupBox(Add_New_Device_Window);
        GB_hdachs_Settings->setObjectName(QString::fromUtf8("GB_hdachs_Settings"));
        GB_hdachs_Settings->setCheckable(true);
        GB_hdachs_Settings->setChecked(false);
        gridLayout3 = new QGridLayout(GB_hdachs_Settings);
#ifndef Q_OS_MAC
        gridLayout3->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        gridLayout3->setContentsMargins(9, 9, 9, 9);
#endif
        gridLayout3->setObjectName(QString::fromUtf8("gridLayout3"));
        spacerItem2 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout3->addItem(spacerItem2, 0, 1, 1, 1);

        gridLayout4 = new QGridLayout();
#ifndef Q_OS_MAC
        gridLayout4->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        gridLayout4->setContentsMargins(0, 0, 0, 0);
#endif
        gridLayout4->setObjectName(QString::fromUtf8("gridLayout4"));
        Edit_Trans = new QLineEdit(GB_hdachs_Settings);
        Edit_Trans->setObjectName(QString::fromUtf8("Edit_Trans"));

        gridLayout4->addWidget(Edit_Trans, 1, 1, 1, 1);

        Edit_Secs = new QLineEdit(GB_hdachs_Settings);
        Edit_Secs->setObjectName(QString::fromUtf8("Edit_Secs"));

        gridLayout4->addWidget(Edit_Secs, 0, 1, 1, 1);

        Label_Secs = new QLabel(GB_hdachs_Settings);
        Label_Secs->setObjectName(QString::fromUtf8("Label_Secs"));

        gridLayout4->addWidget(Label_Secs, 0, 0, 1, 1);

        Label_Trans = new QLabel(GB_hdachs_Settings);
        Label_Trans->setObjectName(QString::fromUtf8("Label_Trans"));

        gridLayout4->addWidget(Label_Trans, 1, 0, 1, 1);


        gridLayout3->addLayout(gridLayout4, 0, 2, 1, 1);

        gridLayout5 = new QGridLayout();
#ifndef Q_OS_MAC
        gridLayout5->setSpacing(6);
#endif
        gridLayout5->setContentsMargins(0, 0, 0, 0);
        gridLayout5->setObjectName(QString::fromUtf8("gridLayout5"));
        Label_Cyls = new QLabel(GB_hdachs_Settings);
        Label_Cyls->setObjectName(QString::fromUtf8("Label_Cyls"));

        gridLayout5->addWidget(Label_Cyls, 0, 0, 1, 1);

        Edit_Cyls = new QLineEdit(GB_hdachs_Settings);
        Edit_Cyls->setObjectName(QString::fromUtf8("Edit_Cyls"));

        gridLayout5->addWidget(Edit_Cyls, 0, 1, 1, 1);

        Label_Heads = new QLabel(GB_hdachs_Settings);
        Label_Heads->setObjectName(QString::fromUtf8("Label_Heads"));

        gridLayout5->addWidget(Label_Heads, 1, 0, 1, 1);

        Edit_Heads = new QLineEdit(GB_hdachs_Settings);
        Edit_Heads->setObjectName(QString::fromUtf8("Edit_Heads"));

        gridLayout5->addWidget(Edit_Heads, 1, 1, 1, 1);


        gridLayout3->addLayout(gridLayout5, 0, 0, 1, 1);


        gridLayout->addWidget(GB_hdachs_Settings, 3, 0, 1, 3);

#ifndef QT_NO_SHORTCUT
        Label_Secs->setBuddy(Edit_Secs);
        Label_Trans->setBuddy(Edit_Trans);
        Label_Cyls->setBuddy(Edit_Cyls);
        Label_Heads->setBuddy(Edit_Heads);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(CH_Interface, CB_Interface);
        QWidget::setTabOrder(CB_Interface, CH_Media);
        QWidget::setTabOrder(CH_Media, CB_Media);
        QWidget::setTabOrder(CB_Media, CH_File);
        QWidget::setTabOrder(CH_File, Edit_File_Path);
        QWidget::setTabOrder(Edit_File_Path, TB_File_Path_Browse);
        QWidget::setTabOrder(TB_File_Path_Browse, CH_Index);
        QWidget::setTabOrder(CH_Index, SB_Index);
        QWidget::setTabOrder(SB_Index, CH_Bus_Unit);
        QWidget::setTabOrder(CH_Bus_Unit, SB_Bus);
        QWidget::setTabOrder(SB_Bus, SB_Unit);
        QWidget::setTabOrder(SB_Unit, CH_Snapshot);
        QWidget::setTabOrder(CH_Snapshot, CH_Cache);
        QWidget::setTabOrder(CH_Cache, Edit_Cyls);
        QWidget::setTabOrder(Edit_Cyls, Edit_Heads);
        QWidget::setTabOrder(Edit_Heads, Edit_Secs);
        QWidget::setTabOrder(Edit_Secs, Edit_Trans);
        QWidget::setTabOrder(Edit_Trans, Button_OK);
        QWidget::setTabOrder(Button_OK, Button_Cancel);

        retranslateUi(Add_New_Device_Window);
        QObject::connect(Button_Cancel, SIGNAL(clicked()), Add_New_Device_Window, SLOT(reject()));
        QObject::connect(CH_Interface, SIGNAL(toggled(bool)), CB_Interface, SLOT(setEnabled(bool)));
        QObject::connect(CH_Media, SIGNAL(toggled(bool)), CB_Media, SLOT(setEnabled(bool)));
        QObject::connect(CH_File, SIGNAL(toggled(bool)), Edit_File_Path, SLOT(setEnabled(bool)));
        QObject::connect(CH_File, SIGNAL(toggled(bool)), TB_File_Path_Browse, SLOT(setEnabled(bool)));
        QObject::connect(CH_Index, SIGNAL(toggled(bool)), SB_Index, SLOT(setEnabled(bool)));
        QObject::connect(CH_Bus_Unit, SIGNAL(toggled(bool)), SB_Bus, SLOT(setEnabled(bool)));
        QObject::connect(CH_Bus_Unit, SIGNAL(toggled(bool)), SB_Unit, SLOT(setEnabled(bool)));

        QMetaObject::connectSlotsByName(Add_New_Device_Window);
    } // setupUi

    void retranslateUi(QDialog *Add_New_Device_Window)
    {
        Add_New_Device_Window->setWindowTitle(QApplication::translate("Add_New_Device_Window", "New Storage Device", nullptr));
        CH_Bus_Unit->setText(QApplication::translate("Add_New_Device_Window", "Bus, Unit (For SCSI)", nullptr));
        CH_Index->setText(QApplication::translate("Add_New_Device_Window", "Index (For IDE, Floppy)", nullptr));
        CH_Snapshot->setText(QApplication::translate("Add_New_Device_Window", "&Snapshot", nullptr));
        Button_OK->setText(QApplication::translate("Add_New_Device_Window", "&OK", nullptr));
        Button_Cancel->setText(QApplication::translate("Add_New_Device_Window", "&Cancel", nullptr));
        CH_Cache->setText(QApplication::translate("Add_New_Device_Window", "Cac&he", nullptr));
        CB_Media->setItemText(0, QApplication::translate("Add_New_Device_Window", "Disk", nullptr));
        CB_Media->setItemText(1, QApplication::translate("Add_New_Device_Window", "CD-ROM", nullptr));

        CB_Interface->setItemText(0, QApplication::translate("Add_New_Device_Window", "ide", nullptr));
        CB_Interface->setItemText(1, QApplication::translate("Add_New_Device_Window", "scsi", nullptr));
        CB_Interface->setItemText(2, QApplication::translate("Add_New_Device_Window", "sd", nullptr));
        CB_Interface->setItemText(3, QApplication::translate("Add_New_Device_Window", "mtd", nullptr));
        CB_Interface->setItemText(4, QApplication::translate("Add_New_Device_Window", "floppy", nullptr));
        CB_Interface->setItemText(5, QApplication::translate("Add_New_Device_Window", "pflash", nullptr));

        TB_File_Path_Browse->setText(QApplication::translate("Add_New_Device_Window", "...", nullptr));
        CH_Media->setText(QApplication::translate("Add_New_Device_Window", "&Media", nullptr));
        CH_File->setText(QApplication::translate("Add_New_Device_Window", "&File", nullptr));
        CH_Interface->setText(QApplication::translate("Add_New_Device_Window", "&Interface", nullptr));
        GB_hdachs_Settings->setTitle(QApplication::translate("Add_New_Device_Window", "Settings for -hdachs Option", nullptr));
        Label_Secs->setText(QApplication::translate("Add_New_Device_Window", "s&ecs", nullptr));
        Label_Trans->setText(QApplication::translate("Add_New_Device_Window", "&trans", nullptr));
        Label_Cyls->setText(QApplication::translate("Add_New_Device_Window", "c&yls", nullptr));
        Label_Heads->setText(QApplication::translate("Add_New_Device_Window", "&heads", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Add_New_Device_Window: public Ui_Add_New_Device_Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADD_NEW_DEVICE_WINDOW_H
