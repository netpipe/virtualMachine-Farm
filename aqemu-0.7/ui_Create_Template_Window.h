/********************************************************************************
** Form generated from reading UI file 'Create_Template_Window.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATE_TEMPLATE_WINDOW_H
#define UI_CREATE_TEMPLATE_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Create_Template_Window
{
public:
    QGridLayout *gridLayout;
    QGroupBox *GB_Options;
    QVBoxLayout *vboxLayout;
    QCheckBox *CH_FDD_CD;
    QCheckBox *CH_HDD;
    QCheckBox *CH_Network;
    QCheckBox *CH_Ports;
    QGroupBox *GB_Files;
    QGridLayout *gridLayout1;
    QCheckBox *CH_Use_Default_Folder;
    QLabel *Label_Template_Folder;
    QToolButton *TB_Template_Folder_Browse;
    QLineEdit *Edit_Template_Folder;
    QLabel *Label_VM_File;
    QLineEdit *Edit_VM_File;
    QToolButton *TB_VM_File_Browse;
    QLabel *Label_Template_Name;
    QLineEdit *Edit_Template_Name;
    QHBoxLayout *hboxLayout;
    QSpacerItem *spacerItem;
    QPushButton *Button_Create;
    QPushButton *Button_Cancel;

    void setupUi(QDialog *Create_Template_Window)
    {
        if (Create_Template_Window->objectName().isEmpty())
            Create_Template_Window->setObjectName(QString::fromUtf8("Create_Template_Window"));
        Create_Template_Window->resize(400, 409);
        gridLayout = new QGridLayout(Create_Template_Window);
#ifndef Q_OS_MAC
        gridLayout->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        gridLayout->setContentsMargins(9, 9, 9, 9);
#endif
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        GB_Options = new QGroupBox(Create_Template_Window);
        GB_Options->setObjectName(QString::fromUtf8("GB_Options"));
        vboxLayout = new QVBoxLayout(GB_Options);
        vboxLayout->setSpacing(4);
        vboxLayout->setContentsMargins(6, 6, 6, 6);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        CH_FDD_CD = new QCheckBox(GB_Options);
        CH_FDD_CD->setObjectName(QString::fromUtf8("CH_FDD_CD"));
        CH_FDD_CD->setChecked(true);

        vboxLayout->addWidget(CH_FDD_CD);

        CH_HDD = new QCheckBox(GB_Options);
        CH_HDD->setObjectName(QString::fromUtf8("CH_HDD"));
        CH_HDD->setChecked(true);

        vboxLayout->addWidget(CH_HDD);

        CH_Network = new QCheckBox(GB_Options);
        CH_Network->setObjectName(QString::fromUtf8("CH_Network"));
        CH_Network->setChecked(true);

        vboxLayout->addWidget(CH_Network);

        CH_Ports = new QCheckBox(GB_Options);
        CH_Ports->setObjectName(QString::fromUtf8("CH_Ports"));
        CH_Ports->setChecked(true);

        vboxLayout->addWidget(CH_Ports);


        gridLayout->addWidget(GB_Options, 3, 0, 1, 1);

        GB_Files = new QGroupBox(Create_Template_Window);
        GB_Files->setObjectName(QString::fromUtf8("GB_Files"));
        gridLayout1 = new QGridLayout(GB_Files);
        gridLayout1->setSpacing(4);
        gridLayout1->setContentsMargins(6, 6, 6, 6);
        gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
        CH_Use_Default_Folder = new QCheckBox(GB_Files);
        CH_Use_Default_Folder->setObjectName(QString::fromUtf8("CH_Use_Default_Folder"));
        CH_Use_Default_Folder->setChecked(true);

        gridLayout1->addWidget(CH_Use_Default_Folder, 2, 0, 1, 1);

        Label_Template_Folder = new QLabel(GB_Files);
        Label_Template_Folder->setObjectName(QString::fromUtf8("Label_Template_Folder"));
        Label_Template_Folder->setEnabled(false);

        gridLayout1->addWidget(Label_Template_Folder, 3, 0, 1, 1);

        TB_Template_Folder_Browse = new QToolButton(GB_Files);
        TB_Template_Folder_Browse->setObjectName(QString::fromUtf8("TB_Template_Folder_Browse"));
        TB_Template_Folder_Browse->setEnabled(false);

        gridLayout1->addWidget(TB_Template_Folder_Browse, 4, 1, 1, 1);

        Edit_Template_Folder = new QLineEdit(GB_Files);
        Edit_Template_Folder->setObjectName(QString::fromUtf8("Edit_Template_Folder"));
        Edit_Template_Folder->setEnabled(false);

        gridLayout1->addWidget(Edit_Template_Folder, 4, 0, 1, 1);

        Label_VM_File = new QLabel(GB_Files);
        Label_VM_File->setObjectName(QString::fromUtf8("Label_VM_File"));

        gridLayout1->addWidget(Label_VM_File, 0, 0, 1, 1);

        Edit_VM_File = new QLineEdit(GB_Files);
        Edit_VM_File->setObjectName(QString::fromUtf8("Edit_VM_File"));

        gridLayout1->addWidget(Edit_VM_File, 1, 0, 1, 1);

        TB_VM_File_Browse = new QToolButton(GB_Files);
        TB_VM_File_Browse->setObjectName(QString::fromUtf8("TB_VM_File_Browse"));

        gridLayout1->addWidget(TB_VM_File_Browse, 1, 1, 1, 1);


        gridLayout->addWidget(GB_Files, 2, 0, 1, 1);

        Label_Template_Name = new QLabel(Create_Template_Window);
        Label_Template_Name->setObjectName(QString::fromUtf8("Label_Template_Name"));

        gridLayout->addWidget(Label_Template_Name, 0, 0, 1, 1);

        Edit_Template_Name = new QLineEdit(Create_Template_Window);
        Edit_Template_Name->setObjectName(QString::fromUtf8("Edit_Template_Name"));

        gridLayout->addWidget(Edit_Template_Name, 1, 0, 1, 1);

        hboxLayout = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout->setSpacing(6);
#endif
        hboxLayout->setContentsMargins(0, 0, 0, 0);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        spacerItem = new QSpacerItem(291, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(spacerItem);

        Button_Create = new QPushButton(Create_Template_Window);
        Button_Create->setObjectName(QString::fromUtf8("Button_Create"));

        hboxLayout->addWidget(Button_Create);

        Button_Cancel = new QPushButton(Create_Template_Window);
        Button_Cancel->setObjectName(QString::fromUtf8("Button_Cancel"));

        hboxLayout->addWidget(Button_Cancel);


        gridLayout->addLayout(hboxLayout, 4, 0, 1, 1);

        QWidget::setTabOrder(Edit_Template_Name, Edit_VM_File);
        QWidget::setTabOrder(Edit_VM_File, TB_VM_File_Browse);
        QWidget::setTabOrder(TB_VM_File_Browse, CH_Use_Default_Folder);
        QWidget::setTabOrder(CH_Use_Default_Folder, Edit_Template_Folder);
        QWidget::setTabOrder(Edit_Template_Folder, TB_Template_Folder_Browse);
        QWidget::setTabOrder(TB_Template_Folder_Browse, CH_FDD_CD);
        QWidget::setTabOrder(CH_FDD_CD, CH_HDD);
        QWidget::setTabOrder(CH_HDD, CH_Network);
        QWidget::setTabOrder(CH_Network, CH_Ports);
        QWidget::setTabOrder(CH_Ports, Button_Create);
        QWidget::setTabOrder(Button_Create, Button_Cancel);

        retranslateUi(Create_Template_Window);
        QObject::connect(Button_Cancel, SIGNAL(clicked()), Create_Template_Window, SLOT(reject()));
        QObject::connect(CH_Use_Default_Folder, SIGNAL(toggled(bool)), Label_Template_Folder, SLOT(setDisabled(bool)));
        QObject::connect(CH_Use_Default_Folder, SIGNAL(toggled(bool)), Edit_Template_Folder, SLOT(setDisabled(bool)));
        QObject::connect(CH_Use_Default_Folder, SIGNAL(toggled(bool)), TB_Template_Folder_Browse, SLOT(setDisabled(bool)));

        QMetaObject::connectSlotsByName(Create_Template_Window);
    } // setupUi

    void retranslateUi(QDialog *Create_Template_Window)
    {
        Create_Template_Window->setWindowTitle(QApplication::translate("Create_Template_Window", "Create Template", nullptr));
        GB_Options->setTitle(QApplication::translate("Create_Template_Window", "Creating Options", nullptr));
        CH_FDD_CD->setText(QApplication::translate("Create_Template_Window", "Save Floppy and CD-ROM Settings", nullptr));
        CH_HDD->setText(QApplication::translate("Create_Template_Window", "Save Hard Disks Size or Format Settings", nullptr));
        CH_Network->setText(QApplication::translate("Create_Template_Window", "Save Network Settings", nullptr));
        CH_Ports->setText(QApplication::translate("Create_Template_Window", "Save Ports (USB/Serial/Parallel)", nullptr));
        GB_Files->setTitle(QApplication::translate("Create_Template_Window", "Files", nullptr));
        CH_Use_Default_Folder->setText(QApplication::translate("Create_Template_Window", "Use default folder for new template", nullptr));
        Label_Template_Folder->setText(QApplication::translate("Create_Template_Window", "Other folder for new template:", nullptr));
        TB_Template_Folder_Browse->setText(QApplication::translate("Create_Template_Window", "...", nullptr));
        Label_VM_File->setText(QApplication::translate("Create_Template_Window", "Virtual machine file:", nullptr));
        TB_VM_File_Browse->setText(QApplication::translate("Create_Template_Window", "...", nullptr));
        Label_Template_Name->setText(QApplication::translate("Create_Template_Window", "New VM Template Name:", nullptr));
        Button_Create->setText(QApplication::translate("Create_Template_Window", "C&reate", nullptr));
        Button_Cancel->setText(QApplication::translate("Create_Template_Window", "&Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Create_Template_Window: public Ui_Create_Template_Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATE_TEMPLATE_WINDOW_H
