/********************************************************************************
** Form generated from reading UI file 'Properties_Window.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROPERTIES_WINDOW_H
#define UI_PROPERTIES_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Properties_Window
{
public:
    QVBoxLayout *vboxLayout;
    QGroupBox *GB_Floppy;
    QGridLayout *gridLayout;
    QRadioButton *RB_FD_Host;
    QRadioButton *RB_FD_Image;
    QComboBox *CB_FD_Host_Devices;
    QLineEdit *Edit_FD_Image_Path;
    QToolButton *TB_FD_Image_Browse;
    QGroupBox *GB_CDROM;
    QGridLayout *gridLayout1;
    QComboBox *CB_CDROM_Host_Devices;
    QRadioButton *RB_CDROM_Host;
    QLineEdit *Edit_CDROM_Image_Path;
    QToolButton *TB_CDROM_Image_Browse;
    QRadioButton *RB_CDROM_Image;
    QGroupBox *GB_HDD;
    QGridLayout *gridLayout2;
    QPushButton *Button_HDD_Format;
    QPushButton *Button_HDD_New;
    QLineEdit *Edit_HDD_Image_Path;
    QToolButton *TB_HDD_Image_Browse;
    QLabel *Label_HDD_Path_to_Image;
    QGroupBox *GB_Info;
    QGridLayout *gridLayout3;
    QLabel *Label_Name;
    QPushButton *Button_Update_Info;
    QLabel *Label_Info;
    QHBoxLayout *hboxLayout;
    QSpacerItem *spacerItem;
    QPushButton *Button_OK;
    QPushButton *Button_Cancel;

    void setupUi(QDialog *Properties_Window)
    {
        if (Properties_Window->objectName().isEmpty())
            Properties_Window->setObjectName(QString::fromUtf8("Properties_Window"));
        Properties_Window->setWindowModality(Qt::WindowModal);
        Properties_Window->resize(400, 586);
        vboxLayout = new QVBoxLayout(Properties_Window);
#ifndef Q_OS_MAC
        vboxLayout->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        vboxLayout->setContentsMargins(9, 9, 9, 9);
#endif
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        GB_Floppy = new QGroupBox(Properties_Window);
        GB_Floppy->setObjectName(QString::fromUtf8("GB_Floppy"));
        gridLayout = new QGridLayout(GB_Floppy);
#ifndef Q_OS_MAC
        gridLayout->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        gridLayout->setContentsMargins(9, 9, 9, 9);
#endif
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        RB_FD_Host = new QRadioButton(GB_Floppy);
        RB_FD_Host->setObjectName(QString::fromUtf8("RB_FD_Host"));
        RB_FD_Host->setChecked(true);

        gridLayout->addWidget(RB_FD_Host, 0, 0, 1, 1);

        RB_FD_Image = new QRadioButton(GB_Floppy);
        RB_FD_Image->setObjectName(QString::fromUtf8("RB_FD_Image"));

        gridLayout->addWidget(RB_FD_Image, 2, 0, 1, 1);

        CB_FD_Host_Devices = new QComboBox(GB_Floppy);
        CB_FD_Host_Devices->setObjectName(QString::fromUtf8("CB_FD_Host_Devices"));

        gridLayout->addWidget(CB_FD_Host_Devices, 1, 0, 1, 2);

        Edit_FD_Image_Path = new QLineEdit(GB_Floppy);
        Edit_FD_Image_Path->setObjectName(QString::fromUtf8("Edit_FD_Image_Path"));

        gridLayout->addWidget(Edit_FD_Image_Path, 3, 0, 1, 1);

        TB_FD_Image_Browse = new QToolButton(GB_Floppy);
        TB_FD_Image_Browse->setObjectName(QString::fromUtf8("TB_FD_Image_Browse"));

        gridLayout->addWidget(TB_FD_Image_Browse, 3, 1, 1, 1);


        vboxLayout->addWidget(GB_Floppy);

        GB_CDROM = new QGroupBox(Properties_Window);
        GB_CDROM->setObjectName(QString::fromUtf8("GB_CDROM"));
        gridLayout1 = new QGridLayout(GB_CDROM);
#ifndef Q_OS_MAC
        gridLayout1->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        gridLayout1->setContentsMargins(9, 9, 9, 9);
#endif
        gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
        CB_CDROM_Host_Devices = new QComboBox(GB_CDROM);
        CB_CDROM_Host_Devices->setObjectName(QString::fromUtf8("CB_CDROM_Host_Devices"));

        gridLayout1->addWidget(CB_CDROM_Host_Devices, 1, 0, 1, 2);

        RB_CDROM_Host = new QRadioButton(GB_CDROM);
        RB_CDROM_Host->setObjectName(QString::fromUtf8("RB_CDROM_Host"));
        RB_CDROM_Host->setChecked(true);

        gridLayout1->addWidget(RB_CDROM_Host, 0, 0, 1, 1);

        Edit_CDROM_Image_Path = new QLineEdit(GB_CDROM);
        Edit_CDROM_Image_Path->setObjectName(QString::fromUtf8("Edit_CDROM_Image_Path"));

        gridLayout1->addWidget(Edit_CDROM_Image_Path, 3, 0, 1, 1);

        TB_CDROM_Image_Browse = new QToolButton(GB_CDROM);
        TB_CDROM_Image_Browse->setObjectName(QString::fromUtf8("TB_CDROM_Image_Browse"));

        gridLayout1->addWidget(TB_CDROM_Image_Browse, 3, 1, 1, 1);

        RB_CDROM_Image = new QRadioButton(GB_CDROM);
        RB_CDROM_Image->setObjectName(QString::fromUtf8("RB_CDROM_Image"));

        gridLayout1->addWidget(RB_CDROM_Image, 2, 0, 1, 1);


        vboxLayout->addWidget(GB_CDROM);

        GB_HDD = new QGroupBox(Properties_Window);
        GB_HDD->setObjectName(QString::fromUtf8("GB_HDD"));
        gridLayout2 = new QGridLayout(GB_HDD);
#ifndef Q_OS_MAC
        gridLayout2->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        gridLayout2->setContentsMargins(9, 9, 9, 9);
#endif
        gridLayout2->setObjectName(QString::fromUtf8("gridLayout2"));
        Button_HDD_Format = new QPushButton(GB_HDD);
        Button_HDD_Format->setObjectName(QString::fromUtf8("Button_HDD_Format"));

        gridLayout2->addWidget(Button_HDD_Format, 2, 1, 1, 1);

        Button_HDD_New = new QPushButton(GB_HDD);
        Button_HDD_New->setObjectName(QString::fromUtf8("Button_HDD_New"));

        gridLayout2->addWidget(Button_HDD_New, 2, 0, 1, 1);

        Edit_HDD_Image_Path = new QLineEdit(GB_HDD);
        Edit_HDD_Image_Path->setObjectName(QString::fromUtf8("Edit_HDD_Image_Path"));

        gridLayout2->addWidget(Edit_HDD_Image_Path, 1, 0, 1, 2);

        TB_HDD_Image_Browse = new QToolButton(GB_HDD);
        TB_HDD_Image_Browse->setObjectName(QString::fromUtf8("TB_HDD_Image_Browse"));

        gridLayout2->addWidget(TB_HDD_Image_Browse, 1, 2, 1, 1);

        Label_HDD_Path_to_Image = new QLabel(GB_HDD);
        Label_HDD_Path_to_Image->setObjectName(QString::fromUtf8("Label_HDD_Path_to_Image"));

        gridLayout2->addWidget(Label_HDD_Path_to_Image, 0, 0, 1, 1);


        vboxLayout->addWidget(GB_HDD);

        GB_Info = new QGroupBox(Properties_Window);
        GB_Info->setObjectName(QString::fromUtf8("GB_Info"));
        gridLayout3 = new QGridLayout(GB_Info);
#ifndef Q_OS_MAC
        gridLayout3->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        gridLayout3->setContentsMargins(9, 9, 9, 9);
#endif
        gridLayout3->setObjectName(QString::fromUtf8("gridLayout3"));
        Label_Name = new QLabel(GB_Info);
        Label_Name->setObjectName(QString::fromUtf8("Label_Name"));
        QSizePolicy sizePolicy(static_cast<QSizePolicy::Policy>(1), static_cast<QSizePolicy::Policy>(5));
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Label_Name->sizePolicy().hasHeightForWidth());
        Label_Name->setSizePolicy(sizePolicy);

        gridLayout3->addWidget(Label_Name, 0, 0, 1, 1);

        Button_Update_Info = new QPushButton(GB_Info);
        Button_Update_Info->setObjectName(QString::fromUtf8("Button_Update_Info"));
        QSizePolicy sizePolicy1(static_cast<QSizePolicy::Policy>(4), static_cast<QSizePolicy::Policy>(0));
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(Button_Update_Info->sizePolicy().hasHeightForWidth());
        Button_Update_Info->setSizePolicy(sizePolicy1);

        gridLayout3->addWidget(Button_Update_Info, 0, 1, 1, 1);

        Label_Info = new QLabel(GB_Info);
        Label_Info->setObjectName(QString::fromUtf8("Label_Info"));
        Label_Info->setTextInteractionFlags(Qt::TextSelectableByMouse);

        gridLayout3->addWidget(Label_Info, 1, 0, 1, 2);


        vboxLayout->addWidget(GB_Info);

        hboxLayout = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout->setSpacing(6);
#endif
        hboxLayout->setContentsMargins(0, 0, 0, 0);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        spacerItem = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(spacerItem);

        Button_OK = new QPushButton(Properties_Window);
        Button_OK->setObjectName(QString::fromUtf8("Button_OK"));

        hboxLayout->addWidget(Button_OK);

        Button_Cancel = new QPushButton(Properties_Window);
        Button_Cancel->setObjectName(QString::fromUtf8("Button_Cancel"));

        hboxLayout->addWidget(Button_Cancel);


        vboxLayout->addLayout(hboxLayout);

        QWidget::setTabOrder(RB_FD_Host, CB_FD_Host_Devices);
        QWidget::setTabOrder(CB_FD_Host_Devices, RB_FD_Image);
        QWidget::setTabOrder(RB_FD_Image, Edit_FD_Image_Path);
        QWidget::setTabOrder(Edit_FD_Image_Path, TB_FD_Image_Browse);
        QWidget::setTabOrder(TB_FD_Image_Browse, RB_CDROM_Host);
        QWidget::setTabOrder(RB_CDROM_Host, CB_CDROM_Host_Devices);
        QWidget::setTabOrder(CB_CDROM_Host_Devices, RB_CDROM_Image);
        QWidget::setTabOrder(RB_CDROM_Image, Edit_CDROM_Image_Path);
        QWidget::setTabOrder(Edit_CDROM_Image_Path, TB_CDROM_Image_Browse);
        QWidget::setTabOrder(TB_CDROM_Image_Browse, Edit_HDD_Image_Path);
        QWidget::setTabOrder(Edit_HDD_Image_Path, Button_HDD_New);
        QWidget::setTabOrder(Button_HDD_New, Button_HDD_Format);
        QWidget::setTabOrder(Button_HDD_Format, TB_HDD_Image_Browse);
        QWidget::setTabOrder(TB_HDD_Image_Browse, Button_Update_Info);
        QWidget::setTabOrder(Button_Update_Info, Button_OK);
        QWidget::setTabOrder(Button_OK, Button_Cancel);

        retranslateUi(Properties_Window);

        QMetaObject::connectSlotsByName(Properties_Window);
    } // setupUi

    void retranslateUi(QDialog *Properties_Window)
    {
        Properties_Window->setWindowTitle(QApplication::translate("Properties_Window", "Properties", nullptr));
        GB_Floppy->setTitle(QApplication::translate("Properties_Window", "Floppy", nullptr));
        RB_FD_Host->setText(QApplication::translate("Properties_Window", "Host Device:", nullptr));
        RB_FD_Image->setText(QApplication::translate("Properties_Window", "Image File:", nullptr));
        TB_FD_Image_Browse->setText(QApplication::translate("Properties_Window", "...", nullptr));
        GB_CDROM->setTitle(QApplication::translate("Properties_Window", "CD/DVD-ROM", nullptr));
        RB_CDROM_Host->setText(QApplication::translate("Properties_Window", "Host Device:", nullptr));
        TB_CDROM_Image_Browse->setText(QApplication::translate("Properties_Window", "...", nullptr));
        RB_CDROM_Image->setText(QApplication::translate("Properties_Window", "Image File:", nullptr));
        GB_HDD->setTitle(QApplication::translate("Properties_Window", "Hard Disk", nullptr));
        Button_HDD_Format->setText(QApplication::translate("Properties_Window", "&Format Exist", nullptr));
        Button_HDD_New->setText(QApplication::translate("Properties_Window", "Create &New", nullptr));
        TB_HDD_Image_Browse->setText(QApplication::translate("Properties_Window", "...", nullptr));
        Label_HDD_Path_to_Image->setText(QApplication::translate("Properties_Window", "Path to Image:", nullptr));
        GB_Info->setTitle(QApplication::translate("Properties_Window", "Information", nullptr));
        Label_Name->setText(QApplication::translate("Properties_Window", "Device Name: ", nullptr));
        Button_Update_Info->setText(QApplication::translate("Properties_Window", "Up&date Info", nullptr));
        Label_Info->setText(QString());
        Button_OK->setText(QApplication::translate("Properties_Window", "&OK", nullptr));
        Button_Cancel->setText(QApplication::translate("Properties_Window", "&Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Properties_Window: public Ui_Properties_Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROPERTIES_WINDOW_H
