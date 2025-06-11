/********************************************************************************
** Form generated from reading UI file 'Copy_VM_Window.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COPY_VM_WINDOW_H
#define UI_COPY_VM_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_Copy_VM_Window
{
public:
    QGridLayout *gridLayout;
    QLabel *Label_Name;
    QLineEdit *Edit_New_VM_Name;
    QCheckBox *CH_Copy_Disk_Images;
    QCheckBox *CH_Copy_Floppy;
    QCheckBox *CH_Copy_Hard_Drive;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *Button_OK;
    QPushButton *Button_Cancel;

    void setupUi(QDialog *Copy_VM_Window)
    {
        if (Copy_VM_Window->objectName().isEmpty())
            Copy_VM_Window->setObjectName(QString::fromUtf8("Copy_VM_Window"));
        Copy_VM_Window->resize(328, 129);
        gridLayout = new QGridLayout(Copy_VM_Window);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        Label_Name = new QLabel(Copy_VM_Window);
        Label_Name->setObjectName(QString::fromUtf8("Label_Name"));

        gridLayout->addWidget(Label_Name, 0, 0, 1, 1);

        Edit_New_VM_Name = new QLineEdit(Copy_VM_Window);
        Edit_New_VM_Name->setObjectName(QString::fromUtf8("Edit_New_VM_Name"));

        gridLayout->addWidget(Edit_New_VM_Name, 0, 1, 1, 2);

        CH_Copy_Disk_Images = new QCheckBox(Copy_VM_Window);
        CH_Copy_Disk_Images->setObjectName(QString::fromUtf8("CH_Copy_Disk_Images"));
        CH_Copy_Disk_Images->setChecked(true);

        gridLayout->addWidget(CH_Copy_Disk_Images, 1, 0, 1, 2);

        CH_Copy_Floppy = new QCheckBox(Copy_VM_Window);
        CH_Copy_Floppy->setObjectName(QString::fromUtf8("CH_Copy_Floppy"));

        gridLayout->addWidget(CH_Copy_Floppy, 2, 0, 1, 2);

        CH_Copy_Hard_Drive = new QCheckBox(Copy_VM_Window);
        CH_Copy_Hard_Drive->setObjectName(QString::fromUtf8("CH_Copy_Hard_Drive"));
        CH_Copy_Hard_Drive->setChecked(true);

        gridLayout->addWidget(CH_Copy_Hard_Drive, 2, 2, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        Button_OK = new QPushButton(Copy_VM_Window);
        Button_OK->setObjectName(QString::fromUtf8("Button_OK"));

        horizontalLayout->addWidget(Button_OK);

        Button_Cancel = new QPushButton(Copy_VM_Window);
        Button_Cancel->setObjectName(QString::fromUtf8("Button_Cancel"));

        horizontalLayout->addWidget(Button_Cancel);


        gridLayout->addLayout(horizontalLayout, 3, 0, 1, 3);

#ifndef QT_NO_SHORTCUT
        Label_Name->setBuddy(Edit_New_VM_Name);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(Edit_New_VM_Name, CH_Copy_Disk_Images);
        QWidget::setTabOrder(CH_Copy_Disk_Images, CH_Copy_Floppy);
        QWidget::setTabOrder(CH_Copy_Floppy, CH_Copy_Hard_Drive);
        QWidget::setTabOrder(CH_Copy_Hard_Drive, Button_OK);
        QWidget::setTabOrder(Button_OK, Button_Cancel);

        retranslateUi(Copy_VM_Window);
        QObject::connect(CH_Copy_Disk_Images, SIGNAL(toggled(bool)), CH_Copy_Floppy, SLOT(setEnabled(bool)));
        QObject::connect(CH_Copy_Disk_Images, SIGNAL(toggled(bool)), CH_Copy_Hard_Drive, SLOT(setEnabled(bool)));
        QObject::connect(Button_Cancel, SIGNAL(clicked()), Copy_VM_Window, SLOT(reject()));

        QMetaObject::connectSlotsByName(Copy_VM_Window);
    } // setupUi

    void retranslateUi(QDialog *Copy_VM_Window)
    {
        Copy_VM_Window->setWindowTitle(QApplication::translate("Copy_VM_Window", "Copy VM", nullptr));
        Label_Name->setText(QApplication::translate("Copy_VM_Window", "New VM Name:", nullptr));
        CH_Copy_Disk_Images->setText(QApplication::translate("Copy_VM_Window", "Copy Disk Images", nullptr));
        CH_Copy_Floppy->setText(QApplication::translate("Copy_VM_Window", "Copy Floppy Images", nullptr));
        CH_Copy_Hard_Drive->setText(QApplication::translate("Copy_VM_Window", "Copy Hard Drive Images", nullptr));
        Button_OK->setText(QApplication::translate("Copy_VM_Window", "&OK", nullptr));
        Button_Cancel->setText(QApplication::translate("Copy_VM_Window", "&Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Copy_VM_Window: public Ui_Copy_VM_Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COPY_VM_WINDOW_H
