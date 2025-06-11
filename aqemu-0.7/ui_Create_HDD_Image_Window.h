/********************************************************************************
** Form generated from reading UI file 'Create_HDD_Image_Window.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATE_HDD_IMAGE_WINDOW_H
#define UI_CREATE_HDD_IMAGE_WINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_Create_HDD_Image_Window
{
public:
    QGridLayout *gridLayout;
    QCheckBox *CH_Encrypted;
    QHBoxLayout *hboxLayout;
    QSpacerItem *spacerItem;
    QPushButton *Button_Create;
    QPushButton *Button_Cancel;
    QGroupBox *GB_Base_Image;
    QGridLayout *gridLayout1;
    QPushButton *Button_Browse_Base_Image;
    QLabel *Label_Base_Image;
    QLineEdit *Edit_Base_Image_File_Name;
    QGroupBox *GB_New_Image;
    QGridLayout *gridLayout2;
    QPushButton *Button_Browse_New_Image;
    QLineEdit *Edit_File_Name;
    QGroupBox *GB_Format_and_Size;
    QGridLayout *gridLayout3;
    QDoubleSpinBox *SB_Size;
    QPushButton *Button_Format_Help;
    QComboBox *CB_Format;
    QComboBox *CB_Suffix;
    QLabel *Label_Size;
    QLabel *Lebel_Format;

    void setupUi(QDialog *Create_HDD_Image_Window)
    {
        if (Create_HDD_Image_Window->objectName().isEmpty())
            Create_HDD_Image_Window->setObjectName(QString::fromUtf8("Create_HDD_Image_Window"));
        Create_HDD_Image_Window->resize(400, 385);
        const QIcon icon = QIcon(QString::fromUtf8(":/images/hdd_unmount.png"));
        Create_HDD_Image_Window->setWindowIcon(icon);
        gridLayout = new QGridLayout(Create_HDD_Image_Window);
#ifndef Q_OS_MAC
        gridLayout->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        gridLayout->setContentsMargins(9, 9, 9, 9);
#endif
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        CH_Encrypted = new QCheckBox(Create_HDD_Image_Window);
        CH_Encrypted->setObjectName(QString::fromUtf8("CH_Encrypted"));

        gridLayout->addWidget(CH_Encrypted, 3, 0, 1, 1);

        hboxLayout = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout->setSpacing(6);
#endif
        hboxLayout->setContentsMargins(0, 0, 0, 0);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        spacerItem = new QSpacerItem(201, 29, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(spacerItem);

        Button_Create = new QPushButton(Create_HDD_Image_Window);
        Button_Create->setObjectName(QString::fromUtf8("Button_Create"));

        hboxLayout->addWidget(Button_Create);

        Button_Cancel = new QPushButton(Create_HDD_Image_Window);
        Button_Cancel->setObjectName(QString::fromUtf8("Button_Cancel"));

        hboxLayout->addWidget(Button_Cancel);


        gridLayout->addLayout(hboxLayout, 4, 0, 1, 1);

        GB_Base_Image = new QGroupBox(Create_HDD_Image_Window);
        GB_Base_Image->setObjectName(QString::fromUtf8("GB_Base_Image"));
        GB_Base_Image->setCheckable(true);
        GB_Base_Image->setChecked(false);
        gridLayout1 = new QGridLayout(GB_Base_Image);
#ifndef Q_OS_MAC
        gridLayout1->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        gridLayout1->setContentsMargins(9, 9, 9, 9);
#endif
        gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
        Button_Browse_Base_Image = new QPushButton(GB_Base_Image);
        Button_Browse_Base_Image->setObjectName(QString::fromUtf8("Button_Browse_Base_Image"));

        gridLayout1->addWidget(Button_Browse_Base_Image, 1, 1, 1, 1);

        Label_Base_Image = new QLabel(GB_Base_Image);
        Label_Base_Image->setObjectName(QString::fromUtf8("Label_Base_Image"));

        gridLayout1->addWidget(Label_Base_Image, 0, 0, 1, 1);

        Edit_Base_Image_File_Name = new QLineEdit(GB_Base_Image);
        Edit_Base_Image_File_Name->setObjectName(QString::fromUtf8("Edit_Base_Image_File_Name"));

        gridLayout1->addWidget(Edit_Base_Image_File_Name, 1, 0, 1, 1);


        gridLayout->addWidget(GB_Base_Image, 0, 0, 1, 1);

        GB_New_Image = new QGroupBox(Create_HDD_Image_Window);
        GB_New_Image->setObjectName(QString::fromUtf8("GB_New_Image"));
        gridLayout2 = new QGridLayout(GB_New_Image);
#ifndef Q_OS_MAC
        gridLayout2->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        gridLayout2->setContentsMargins(9, 9, 9, 9);
#endif
        gridLayout2->setObjectName(QString::fromUtf8("gridLayout2"));
        Button_Browse_New_Image = new QPushButton(GB_New_Image);
        Button_Browse_New_Image->setObjectName(QString::fromUtf8("Button_Browse_New_Image"));

        gridLayout2->addWidget(Button_Browse_New_Image, 0, 1, 1, 1);

        Edit_File_Name = new QLineEdit(GB_New_Image);
        Edit_File_Name->setObjectName(QString::fromUtf8("Edit_File_Name"));

        gridLayout2->addWidget(Edit_File_Name, 0, 0, 1, 1);


        gridLayout->addWidget(GB_New_Image, 1, 0, 1, 1);

        GB_Format_and_Size = new QGroupBox(Create_HDD_Image_Window);
        GB_Format_and_Size->setObjectName(QString::fromUtf8("GB_Format_and_Size"));
        gridLayout3 = new QGridLayout(GB_Format_and_Size);
#ifndef Q_OS_MAC
        gridLayout3->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        gridLayout3->setContentsMargins(9, 9, 9, 9);
#endif
        gridLayout3->setObjectName(QString::fromUtf8("gridLayout3"));
        SB_Size = new QDoubleSpinBox(GB_Format_and_Size);
        SB_Size->setObjectName(QString::fromUtf8("SB_Size"));
        SB_Size->setDecimals(1);
        SB_Size->setMaximum(1024.000000000000000);
        SB_Size->setMinimum(1.000000000000000);
        SB_Size->setSingleStep(1.000000000000000);
        SB_Size->setValue(10.000000000000000);

        gridLayout3->addWidget(SB_Size, 3, 0, 1, 1);

        Button_Format_Help = new QPushButton(GB_Format_and_Size);
        Button_Format_Help->setObjectName(QString::fromUtf8("Button_Format_Help"));

        gridLayout3->addWidget(Button_Format_Help, 1, 1, 1, 1);

        CB_Format = new QComboBox(GB_Format_and_Size);
        CB_Format->addItem(QString());
        CB_Format->addItem(QString());
        CB_Format->addItem(QString());
        CB_Format->addItem(QString());
        CB_Format->addItem(QString());
        CB_Format->addItem(QString());
        CB_Format->setObjectName(QString::fromUtf8("CB_Format"));
        QSizePolicy sizePolicy(static_cast<QSizePolicy::Policy>(7), static_cast<QSizePolicy::Policy>(0));
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CB_Format->sizePolicy().hasHeightForWidth());
        CB_Format->setSizePolicy(sizePolicy);
        CB_Format->setMaxCount(32);

        gridLayout3->addWidget(CB_Format, 1, 0, 1, 1);

        CB_Suffix = new QComboBox(GB_Format_and_Size);
        CB_Suffix->addItem(QString());
        CB_Suffix->addItem(QString());
        CB_Suffix->addItem(QString());
        CB_Suffix->setObjectName(QString::fromUtf8("CB_Suffix"));
        QSizePolicy sizePolicy1(static_cast<QSizePolicy::Policy>(5), static_cast<QSizePolicy::Policy>(0));
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(CB_Suffix->sizePolicy().hasHeightForWidth());
        CB_Suffix->setSizePolicy(sizePolicy1);

        gridLayout3->addWidget(CB_Suffix, 3, 1, 1, 1);

        Label_Size = new QLabel(GB_Format_and_Size);
        Label_Size->setObjectName(QString::fromUtf8("Label_Size"));

        gridLayout3->addWidget(Label_Size, 2, 0, 1, 1);

        Lebel_Format = new QLabel(GB_Format_and_Size);
        Lebel_Format->setObjectName(QString::fromUtf8("Lebel_Format"));

        gridLayout3->addWidget(Lebel_Format, 0, 0, 1, 1);


        gridLayout->addWidget(GB_Format_and_Size, 2, 0, 1, 1);

#ifndef QT_NO_SHORTCUT
        Label_Base_Image->setBuddy(Edit_Base_Image_File_Name);
        Label_Size->setBuddy(SB_Size);
        Lebel_Format->setBuddy(CB_Format);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(Edit_Base_Image_File_Name, Button_Browse_Base_Image);
        QWidget::setTabOrder(Button_Browse_Base_Image, Edit_File_Name);
        QWidget::setTabOrder(Edit_File_Name, Button_Browse_New_Image);
        QWidget::setTabOrder(Button_Browse_New_Image, CB_Format);
        QWidget::setTabOrder(CB_Format, Button_Format_Help);
        QWidget::setTabOrder(Button_Format_Help, SB_Size);
        QWidget::setTabOrder(SB_Size, CB_Suffix);
        QWidget::setTabOrder(CB_Suffix, CH_Encrypted);
        QWidget::setTabOrder(CH_Encrypted, Button_Create);
        QWidget::setTabOrder(Button_Create, Button_Cancel);

        retranslateUi(Create_HDD_Image_Window);
        QObject::connect(Button_Cancel, SIGNAL(clicked()), Create_HDD_Image_Window, SLOT(reject()));

        CB_Suffix->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(Create_HDD_Image_Window);
    } // setupUi

    void retranslateUi(QDialog *Create_HDD_Image_Window)
    {
        Create_HDD_Image_Window->setWindowTitle(QApplication::translate("Create_HDD_Image_Window", "Create HDD Image", nullptr));
        CH_Encrypted->setText(QApplication::translate("Create_HDD_Image_Window", "Image Must be &Encrypted (QCOW Format Only)", nullptr));
        Button_Create->setText(QApplication::translate("Create_HDD_Image_Window", "C&reate", nullptr));
        Button_Cancel->setText(QApplication::translate("Create_HDD_Image_Window", "&Cancel", nullptr));
        GB_Base_Image->setTitle(QApplication::translate("Create_HDD_Image_Window", "Use &Base HDD Image", nullptr));
        Button_Browse_Base_Image->setText(QApplication::translate("Create_HDD_Image_Window", "Browse...", nullptr));
        Label_Base_Image->setText(QApplication::translate("Create_HDD_Image_Window", "Base HDD Image File Name:", nullptr));
        GB_New_Image->setTitle(QApplication::translate("Create_HDD_Image_Window", "New Image &File Name:", nullptr));
        Button_Browse_New_Image->setText(QApplication::translate("Create_HDD_Image_Window", "Browse...", nullptr));
        GB_Format_and_Size->setTitle(QString());
        Button_Format_Help->setText(QApplication::translate("Create_HDD_Image_Window", "&Help...", nullptr));
        CB_Format->setItemText(0, QApplication::translate("Create_HDD_Image_Window", "qcow2", nullptr));
        CB_Format->setItemText(1, QApplication::translate("Create_HDD_Image_Window", "qcow", nullptr));
        CB_Format->setItemText(2, QApplication::translate("Create_HDD_Image_Window", "vmdk", nullptr));
        CB_Format->setItemText(3, QApplication::translate("Create_HDD_Image_Window", "cow", nullptr));
        CB_Format->setItemText(4, QApplication::translate("Create_HDD_Image_Window", "raw", nullptr));
        CB_Format->setItemText(5, QApplication::translate("Create_HDD_Image_Window", "cloop", nullptr));

        CB_Suffix->setItemText(0, QApplication::translate("Create_HDD_Image_Window", "KB", nullptr));
        CB_Suffix->setItemText(1, QApplication::translate("Create_HDD_Image_Window", "MB", nullptr));
        CB_Suffix->setItemText(2, QApplication::translate("Create_HDD_Image_Window", "GB", nullptr));

        Label_Size->setText(QApplication::translate("Create_HDD_Image_Window", "&Size:", nullptr));
        Lebel_Format->setText(QApplication::translate("Create_HDD_Image_Window", "&Format:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Create_HDD_Image_Window: public Ui_Create_HDD_Image_Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATE_HDD_IMAGE_WINDOW_H
