/********************************************************************************
** Form generated from reading UI file 'Settings_Window.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGS_WINDOW_H
#define UI_SETTINGS_WINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Settings_Window
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *Label_Default_VM_Template;
    QComboBox *CB_Default_VM_Template;
    QPushButton *Button_Create_Template_from_VM;
    QHBoxLayout *horizontalLayout_2;
    QLabel *Label_VM_Folder;
    QLineEdit *Edit_VM_Folder;
    QToolButton *TB_VM_Folder;
    QHBoxLayout *horizontalLayout;
    QLabel *Label_Language;
    QSpacerItem *horizontalSpacer;
    QComboBox *CB_Language;
    QFrame *line_4;
    QVBoxLayout *verticalLayout;
    QCheckBox *CH_Use_Device_Manager;
    QCheckBox *CH_Use_USB;
    QCheckBox *CH_Show_Emulator_Control_Window;
    QCheckBox *CH_Use_VNC_Display;
    QCheckBox *CH_Screenshot_for_OS_Logo;
    QCheckBox *CH_64_Icons;
    QHBoxLayout *horizontalLayout_4;
    QLabel *Label_Other_Settings;
    QFrame *line;
    QPushButton *Button_Advanced_Settings;
    QPushButton *Button_Screenshots_Settings;
    QPushButton *Button_QEMU_Binary;
    QFrame *line_2;
    QDialogButtonBox *Button_Box;

    void setupUi(QDialog *Settings_Window)
    {
        if (Settings_Window->objectName().isEmpty())
            Settings_Window->setObjectName(QString::fromUtf8("Settings_Window"));
        Settings_Window->resize(381, 435);
        QIcon icon;
        icon.addFile(QString::fromUtf8("../../../../usr/kde/3.5/share/icons/crystalsvg/16x16/actions/view_choose.png"), QSize(), QIcon::Normal, QIcon::Off);
        Settings_Window->setWindowIcon(icon);
        gridLayout = new QGridLayout(Settings_Window);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        Label_Default_VM_Template = new QLabel(Settings_Window);
        Label_Default_VM_Template->setObjectName(QString::fromUtf8("Label_Default_VM_Template"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Label_Default_VM_Template->sizePolicy().hasHeightForWidth());
        Label_Default_VM_Template->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(Label_Default_VM_Template);

        CB_Default_VM_Template = new QComboBox(Settings_Window);
        CB_Default_VM_Template->setObjectName(QString::fromUtf8("CB_Default_VM_Template"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(CB_Default_VM_Template->sizePolicy().hasHeightForWidth());
        CB_Default_VM_Template->setSizePolicy(sizePolicy1);

        horizontalLayout_3->addWidget(CB_Default_VM_Template);

        Button_Create_Template_from_VM = new QPushButton(Settings_Window);
        Button_Create_Template_from_VM->setObjectName(QString::fromUtf8("Button_Create_Template_from_VM"));
        QSizePolicy sizePolicy2(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(Button_Create_Template_from_VM->sizePolicy().hasHeightForWidth());
        Button_Create_Template_from_VM->setSizePolicy(sizePolicy2);

        horizontalLayout_3->addWidget(Button_Create_Template_from_VM);


        gridLayout->addLayout(horizontalLayout_3, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        Label_VM_Folder = new QLabel(Settings_Window);
        Label_VM_Folder->setObjectName(QString::fromUtf8("Label_VM_Folder"));
        QSizePolicy sizePolicy3(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(Label_VM_Folder->sizePolicy().hasHeightForWidth());
        Label_VM_Folder->setSizePolicy(sizePolicy3);

        horizontalLayout_2->addWidget(Label_VM_Folder);

        Edit_VM_Folder = new QLineEdit(Settings_Window);
        Edit_VM_Folder->setObjectName(QString::fromUtf8("Edit_VM_Folder"));

        horizontalLayout_2->addWidget(Edit_VM_Folder);

        TB_VM_Folder = new QToolButton(Settings_Window);
        TB_VM_Folder->setObjectName(QString::fromUtf8("TB_VM_Folder"));

        horizontalLayout_2->addWidget(TB_VM_Folder);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        Label_Language = new QLabel(Settings_Window);
        Label_Language->setObjectName(QString::fromUtf8("Label_Language"));
        sizePolicy3.setHeightForWidth(Label_Language->sizePolicy().hasHeightForWidth());
        Label_Language->setSizePolicy(sizePolicy3);

        horizontalLayout->addWidget(Label_Language);

        horizontalSpacer = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        CB_Language = new QComboBox(Settings_Window);
        CB_Language->addItem(QString());
        CB_Language->setObjectName(QString::fromUtf8("CB_Language"));

        horizontalLayout->addWidget(CB_Language);


        gridLayout->addLayout(horizontalLayout, 2, 0, 1, 1);

        line_4 = new QFrame(Settings_Window);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_4, 3, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        CH_Use_Device_Manager = new QCheckBox(Settings_Window);
        CH_Use_Device_Manager->setObjectName(QString::fromUtf8("CH_Use_Device_Manager"));

        verticalLayout->addWidget(CH_Use_Device_Manager);

        CH_Use_USB = new QCheckBox(Settings_Window);
        CH_Use_USB->setObjectName(QString::fromUtf8("CH_Use_USB"));
        CH_Use_USB->setEnabled(false);

        verticalLayout->addWidget(CH_Use_USB);

        CH_Show_Emulator_Control_Window = new QCheckBox(Settings_Window);
        CH_Show_Emulator_Control_Window->setObjectName(QString::fromUtf8("CH_Show_Emulator_Control_Window"));
        CH_Show_Emulator_Control_Window->setChecked(true);

        verticalLayout->addWidget(CH_Show_Emulator_Control_Window);

        CH_Use_VNC_Display = new QCheckBox(Settings_Window);
        CH_Use_VNC_Display->setObjectName(QString::fromUtf8("CH_Use_VNC_Display"));
        CH_Use_VNC_Display->setEnabled(false);

        verticalLayout->addWidget(CH_Use_VNC_Display);

        CH_Screenshot_for_OS_Logo = new QCheckBox(Settings_Window);
        CH_Screenshot_for_OS_Logo->setObjectName(QString::fromUtf8("CH_Screenshot_for_OS_Logo"));
        CH_Screenshot_for_OS_Logo->setChecked(true);

        verticalLayout->addWidget(CH_Screenshot_for_OS_Logo);

        CH_64_Icons = new QCheckBox(Settings_Window);
        CH_64_Icons->setObjectName(QString::fromUtf8("CH_64_Icons"));
        CH_64_Icons->setChecked(true);

        verticalLayout->addWidget(CH_64_Icons);


        gridLayout->addLayout(verticalLayout, 4, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        Label_Other_Settings = new QLabel(Settings_Window);
        Label_Other_Settings->setObjectName(QString::fromUtf8("Label_Other_Settings"));
        sizePolicy3.setHeightForWidth(Label_Other_Settings->sizePolicy().hasHeightForWidth());
        Label_Other_Settings->setSizePolicy(sizePolicy3);

        horizontalLayout_4->addWidget(Label_Other_Settings);

        line = new QFrame(Settings_Window);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout_4->addWidget(line);


        gridLayout->addLayout(horizontalLayout_4, 5, 0, 1, 1);

        Button_Advanced_Settings = new QPushButton(Settings_Window);
        Button_Advanced_Settings->setObjectName(QString::fromUtf8("Button_Advanced_Settings"));
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(2);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(Button_Advanced_Settings->sizePolicy().hasHeightForWidth());
        Button_Advanced_Settings->setSizePolicy(sizePolicy4);

        gridLayout->addWidget(Button_Advanced_Settings, 6, 0, 1, 1);

        Button_Screenshots_Settings = new QPushButton(Settings_Window);
        Button_Screenshots_Settings->setObjectName(QString::fromUtf8("Button_Screenshots_Settings"));

        gridLayout->addWidget(Button_Screenshots_Settings, 7, 0, 1, 1);

        Button_QEMU_Binary = new QPushButton(Settings_Window);
        Button_QEMU_Binary->setObjectName(QString::fromUtf8("Button_QEMU_Binary"));

        gridLayout->addWidget(Button_QEMU_Binary, 8, 0, 1, 1);

        line_2 = new QFrame(Settings_Window);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_2, 9, 0, 1, 1);

        Button_Box = new QDialogButtonBox(Settings_Window);
        Button_Box->setObjectName(QString::fromUtf8("Button_Box"));
        QSizePolicy sizePolicy5(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(2);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(Button_Box->sizePolicy().hasHeightForWidth());
        Button_Box->setSizePolicy(sizePolicy5);
        Button_Box->setOrientation(Qt::Horizontal);
        Button_Box->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(Button_Box, 10, 0, 1, 1);

#ifndef QT_NO_SHORTCUT
        Label_Default_VM_Template->setBuddy(CB_Default_VM_Template);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(CB_Default_VM_Template, Button_Create_Template_from_VM);
        QWidget::setTabOrder(Button_Create_Template_from_VM, Edit_VM_Folder);
        QWidget::setTabOrder(Edit_VM_Folder, TB_VM_Folder);
        QWidget::setTabOrder(TB_VM_Folder, CB_Language);
        QWidget::setTabOrder(CB_Language, CH_Use_Device_Manager);
        QWidget::setTabOrder(CH_Use_Device_Manager, CH_Use_USB);
        QWidget::setTabOrder(CH_Use_USB, CH_Show_Emulator_Control_Window);
        QWidget::setTabOrder(CH_Show_Emulator_Control_Window, CH_Use_VNC_Display);
        QWidget::setTabOrder(CH_Use_VNC_Display, CH_Screenshot_for_OS_Logo);
        QWidget::setTabOrder(CH_Screenshot_for_OS_Logo, CH_64_Icons);
        QWidget::setTabOrder(CH_64_Icons, Button_Advanced_Settings);
        QWidget::setTabOrder(Button_Advanced_Settings, Button_Screenshots_Settings);
        QWidget::setTabOrder(Button_Screenshots_Settings, Button_QEMU_Binary);
        QWidget::setTabOrder(Button_QEMU_Binary, Button_Box);

        retranslateUi(Settings_Window);

        QMetaObject::connectSlotsByName(Settings_Window);
    } // setupUi

    void retranslateUi(QDialog *Settings_Window)
    {
        Settings_Window->setWindowTitle(QApplication::translate("Settings_Window", "AQEMU Settings", nullptr));
        Label_Default_VM_Template->setText(QApplication::translate("Settings_Window", "Default VM Template:", nullptr));
        Button_Create_Template_from_VM->setText(QApplication::translate("Settings_Window", "Create Template...", nullptr));
        Label_VM_Folder->setText(QApplication::translate("Settings_Window", "AQEMU VM Folder:", nullptr));
        TB_VM_Folder->setText(QApplication::translate("Settings_Window", "...", nullptr));
        Label_Language->setText(QApplication::translate("Settings_Window", "AQEMU Interface Language:", nullptr));
        CB_Language->setItemText(0, QApplication::translate("Settings_Window", "English", nullptr));

        CH_Use_Device_Manager->setText(QApplication::translate("Settings_Window", "Use Device Manager by Default", nullptr));
        CH_Use_USB->setText(QApplication::translate("Settings_Window", "Support USB Host Devices", nullptr));
        CH_Show_Emulator_Control_Window->setText(QApplication::translate("Settings_Window", "Show Emulator Control Window", nullptr));
        CH_Use_VNC_Display->setText(QApplication::translate("Settings_Window", "Use Embedded Display in Emulator Control Window", nullptr));
        CH_Screenshot_for_OS_Logo->setText(QApplication::translate("Settings_Window", "Use Screenshot for OS Icon in Save Mode", nullptr));
        CH_64_Icons->setText(QApplication::translate("Settings_Window", "Use 64x64 Screenshot Icons", nullptr));
        Label_Other_Settings->setText(QApplication::translate("Settings_Window", "Other Settings", nullptr));
        Button_Advanced_Settings->setText(QApplication::translate("Settings_Window", "Advanced Settings...", nullptr));
        Button_Screenshots_Settings->setText(QApplication::translate("Settings_Window", "Screenshots Settings...", nullptr));
        Button_QEMU_Binary->setText(QApplication::translate("Settings_Window", "Manage QEMU Binary...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Settings_Window: public Ui_Settings_Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGS_WINDOW_H
