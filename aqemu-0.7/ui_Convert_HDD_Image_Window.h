/********************************************************************************
** Form generated from reading UI file 'Convert_HDD_Image_Window.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONVERT_HDD_IMAGE_WINDOW_H
#define UI_CONVERT_HDD_IMAGE_WINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
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

QT_BEGIN_NAMESPACE

class Ui_Convert_HDD_Image_Window
{
public:
    QGridLayout *gridLayout;
    QGroupBox *GB_QCOW_Options;
    QGridLayout *gridLayout1;
    QSpacerItem *spacerItem;
    QCheckBox *CH_Compressed;
    QCheckBox *CH_Encrypted;
    QPushButton *Button_Identify;
    QHBoxLayout *hboxLayout;
    QPushButton *Button_Convert;
    QPushButton *Button_Cancel;
    QSpacerItem *spacerItem1;
    QLabel *Label_Base_File_Name;
    QLineEdit *Edit_Base_File_Name;
    QPushButton *Button_Browse_Base;
    QLabel *Label_Output_Format;
    QLineEdit *Edit_Output_File_Name;
    QLabel *Label_Output_File_Name;
    QLabel *Label_Input_Format;
    QComboBox *CB_Input_Format;
    QPushButton *Button_Browse_Output;
    QComboBox *CB_Output_Format;

    void setupUi(QDialog *Convert_HDD_Image_Window)
    {
        if (Convert_HDD_Image_Window->objectName().isEmpty())
            Convert_HDD_Image_Window->setObjectName(QString::fromUtf8("Convert_HDD_Image_Window"));
        Convert_HDD_Image_Window->resize(496, 345);
        const QIcon icon = QIcon(QString::fromUtf8(":/images/hdd_unmount.png"));
        Convert_HDD_Image_Window->setWindowIcon(icon);
        gridLayout = new QGridLayout(Convert_HDD_Image_Window);
#ifndef Q_OS_MAC
        gridLayout->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        gridLayout->setContentsMargins(9, 9, 9, 9);
#endif
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        GB_QCOW_Options = new QGroupBox(Convert_HDD_Image_Window);
        GB_QCOW_Options->setObjectName(QString::fromUtf8("GB_QCOW_Options"));
        gridLayout1 = new QGridLayout(GB_QCOW_Options);
#ifndef Q_OS_MAC
        gridLayout1->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        gridLayout1->setContentsMargins(9, 9, 9, 9);
#endif
        gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
        spacerItem = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout1->addItem(spacerItem, 0, 1, 1, 1);

        CH_Compressed = new QCheckBox(GB_QCOW_Options);
        CH_Compressed->setObjectName(QString::fromUtf8("CH_Compressed"));

        gridLayout1->addWidget(CH_Compressed, 0, 0, 1, 1);

        CH_Encrypted = new QCheckBox(GB_QCOW_Options);
        CH_Encrypted->setObjectName(QString::fromUtf8("CH_Encrypted"));

        gridLayout1->addWidget(CH_Encrypted, 0, 2, 1, 1);


        gridLayout->addWidget(GB_QCOW_Options, 8, 0, 1, 3);

        Button_Identify = new QPushButton(Convert_HDD_Image_Window);
        Button_Identify->setObjectName(QString::fromUtf8("Button_Identify"));

        gridLayout->addWidget(Button_Identify, 3, 2, 1, 1);

        hboxLayout = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout->setSpacing(6);
#endif
        hboxLayout->setContentsMargins(0, 0, 0, 0);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        Button_Convert = new QPushButton(Convert_HDD_Image_Window);
        Button_Convert->setObjectName(QString::fromUtf8("Button_Convert"));

        hboxLayout->addWidget(Button_Convert);

        Button_Cancel = new QPushButton(Convert_HDD_Image_Window);
        Button_Cancel->setObjectName(QString::fromUtf8("Button_Cancel"));

        hboxLayout->addWidget(Button_Cancel);


        gridLayout->addLayout(hboxLayout, 9, 1, 1, 2);

        spacerItem1 = new QSpacerItem(141, 29, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(spacerItem1, 9, 0, 1, 1);

        Label_Base_File_Name = new QLabel(Convert_HDD_Image_Window);
        Label_Base_File_Name->setObjectName(QString::fromUtf8("Label_Base_File_Name"));

        gridLayout->addWidget(Label_Base_File_Name, 0, 0, 1, 2);

        Edit_Base_File_Name = new QLineEdit(Convert_HDD_Image_Window);
        Edit_Base_File_Name->setObjectName(QString::fromUtf8("Edit_Base_File_Name"));

        gridLayout->addWidget(Edit_Base_File_Name, 1, 0, 1, 2);

        Button_Browse_Base = new QPushButton(Convert_HDD_Image_Window);
        Button_Browse_Base->setObjectName(QString::fromUtf8("Button_Browse_Base"));

        gridLayout->addWidget(Button_Browse_Base, 1, 2, 1, 1);

        Label_Output_Format = new QLabel(Convert_HDD_Image_Window);
        Label_Output_Format->setObjectName(QString::fromUtf8("Label_Output_Format"));

        gridLayout->addWidget(Label_Output_Format, 6, 0, 1, 1);

        Edit_Output_File_Name = new QLineEdit(Convert_HDD_Image_Window);
        Edit_Output_File_Name->setObjectName(QString::fromUtf8("Edit_Output_File_Name"));

        gridLayout->addWidget(Edit_Output_File_Name, 5, 0, 1, 2);

        Label_Output_File_Name = new QLabel(Convert_HDD_Image_Window);
        Label_Output_File_Name->setObjectName(QString::fromUtf8("Label_Output_File_Name"));

        gridLayout->addWidget(Label_Output_File_Name, 4, 0, 1, 2);

        Label_Input_Format = new QLabel(Convert_HDD_Image_Window);
        Label_Input_Format->setObjectName(QString::fromUtf8("Label_Input_Format"));

        gridLayout->addWidget(Label_Input_Format, 2, 0, 1, 1);

        CB_Input_Format = new QComboBox(Convert_HDD_Image_Window);
        CB_Input_Format->addItem(QString());
        CB_Input_Format->addItem(QString());
        CB_Input_Format->addItem(QString());
        CB_Input_Format->addItem(QString());
        CB_Input_Format->addItem(QString());
        CB_Input_Format->addItem(QString());
        CB_Input_Format->setObjectName(QString::fromUtf8("CB_Input_Format"));
        CB_Input_Format->setMaxCount(32);

        gridLayout->addWidget(CB_Input_Format, 3, 0, 1, 2);

        Button_Browse_Output = new QPushButton(Convert_HDD_Image_Window);
        Button_Browse_Output->setObjectName(QString::fromUtf8("Button_Browse_Output"));

        gridLayout->addWidget(Button_Browse_Output, 5, 2, 1, 1);

        CB_Output_Format = new QComboBox(Convert_HDD_Image_Window);
        CB_Output_Format->addItem(QString());
        CB_Output_Format->addItem(QString());
        CB_Output_Format->addItem(QString());
        CB_Output_Format->addItem(QString());
        CB_Output_Format->addItem(QString());
        CB_Output_Format->addItem(QString());
        CB_Output_Format->setObjectName(QString::fromUtf8("CB_Output_Format"));
        CB_Output_Format->setMaxCount(32);

        gridLayout->addWidget(CB_Output_Format, 7, 0, 1, 2);

#ifndef QT_NO_SHORTCUT
        Label_Base_File_Name->setBuddy(Edit_Base_File_Name);
        Label_Output_Format->setBuddy(CB_Output_Format);
        Label_Output_File_Name->setBuddy(Edit_Output_File_Name);
        Label_Input_Format->setBuddy(CB_Input_Format);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(Edit_Base_File_Name, Button_Browse_Base);
        QWidget::setTabOrder(Button_Browse_Base, CB_Input_Format);
        QWidget::setTabOrder(CB_Input_Format, Button_Identify);
        QWidget::setTabOrder(Button_Identify, Edit_Output_File_Name);
        QWidget::setTabOrder(Edit_Output_File_Name, Button_Browse_Output);
        QWidget::setTabOrder(Button_Browse_Output, CB_Output_Format);
        QWidget::setTabOrder(CB_Output_Format, CH_Compressed);
        QWidget::setTabOrder(CH_Compressed, CH_Encrypted);
        QWidget::setTabOrder(CH_Encrypted, Button_Convert);
        QWidget::setTabOrder(Button_Convert, Button_Cancel);

        retranslateUi(Convert_HDD_Image_Window);
        QObject::connect(Button_Cancel, SIGNAL(clicked()), Convert_HDD_Image_Window, SLOT(reject()));

        QMetaObject::connectSlotsByName(Convert_HDD_Image_Window);
    } // setupUi

    void retranslateUi(QDialog *Convert_HDD_Image_Window)
    {
        Convert_HDD_Image_Window->setWindowTitle(QApplication::translate("Convert_HDD_Image_Window", "Convert HDD Image", nullptr));
        GB_QCOW_Options->setTitle(QApplication::translate("Convert_HDD_Image_Window", "QCOW Format Options", nullptr));
        CH_Compressed->setText(QApplication::translate("Convert_HDD_Image_Window", "Image Must be Com&pressed", nullptr));
        CH_Encrypted->setText(QApplication::translate("Convert_HDD_Image_Window", "Image Must be &Encrypted", nullptr));
        Button_Identify->setText(QApplication::translate("Convert_HDD_Image_Window", "I&dentify", nullptr));
        Button_Convert->setText(QApplication::translate("Convert_HDD_Image_Window", "Con&vert", nullptr));
        Button_Cancel->setText(QApplication::translate("Convert_HDD_Image_Window", "&Cancel", nullptr));
        Label_Base_File_Name->setText(QApplication::translate("Convert_HDD_Image_Window", "&Input Image File Name:", nullptr));
        Button_Browse_Base->setText(QApplication::translate("Convert_HDD_Image_Window", "Browse...", nullptr));
        Label_Output_Format->setText(QApplication::translate("Convert_HDD_Image_Window", "Ou&tput Format:", nullptr));
        Label_Output_File_Name->setText(QApplication::translate("Convert_HDD_Image_Window", "&Output Image File Name:", nullptr));
        Label_Input_Format->setText(QApplication::translate("Convert_HDD_Image_Window", "Input &Format:", nullptr));
        CB_Input_Format->setItemText(0, QApplication::translate("Convert_HDD_Image_Window", "qcow2", nullptr));
        CB_Input_Format->setItemText(1, QApplication::translate("Convert_HDD_Image_Window", "qcow", nullptr));
        CB_Input_Format->setItemText(2, QApplication::translate("Convert_HDD_Image_Window", "vmdk", nullptr));
        CB_Input_Format->setItemText(3, QApplication::translate("Convert_HDD_Image_Window", "cow", nullptr));
        CB_Input_Format->setItemText(4, QApplication::translate("Convert_HDD_Image_Window", "raw", nullptr));
        CB_Input_Format->setItemText(5, QApplication::translate("Convert_HDD_Image_Window", "cloop", nullptr));

        Button_Browse_Output->setText(QApplication::translate("Convert_HDD_Image_Window", "Browse...", nullptr));
        CB_Output_Format->setItemText(0, QApplication::translate("Convert_HDD_Image_Window", "qcow2", nullptr));
        CB_Output_Format->setItemText(1, QApplication::translate("Convert_HDD_Image_Window", "qcow", nullptr));
        CB_Output_Format->setItemText(2, QApplication::translate("Convert_HDD_Image_Window", "vmdk", nullptr));
        CB_Output_Format->setItemText(3, QApplication::translate("Convert_HDD_Image_Window", "cow", nullptr));
        CB_Output_Format->setItemText(4, QApplication::translate("Convert_HDD_Image_Window", "raw", nullptr));
        CB_Output_Format->setItemText(5, QApplication::translate("Convert_HDD_Image_Window", "cloop", nullptr));

    } // retranslateUi

};

namespace Ui {
    class Convert_HDD_Image_Window: public Ui_Convert_HDD_Image_Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONVERT_HDD_IMAGE_WINDOW_H
