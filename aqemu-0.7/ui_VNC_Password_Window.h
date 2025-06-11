/********************************************************************************
** Form generated from reading UI file 'VNC_Password_Window.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VNC_PASSWORD_WINDOW_H
#define UI_VNC_PASSWORD_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_VNC_Password_Window
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *Edit_Password;
    QLineEdit *Edit_Confirm_Password;
    QLabel *label_2;
    QPushButton *Button_OK;
    QSpacerItem *spacerItem;

    void setupUi(QDialog *VNC_Password_Window)
    {
        if (VNC_Password_Window->objectName().isEmpty())
            VNC_Password_Window->setObjectName(QString::fromUtf8("VNC_Password_Window"));
        VNC_Password_Window->resize(274, 153);
        gridLayout = new QGridLayout(VNC_Password_Window);
#ifndef Q_OS_MAC
        gridLayout->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        gridLayout->setContentsMargins(9, 9, 9, 9);
#endif
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(VNC_Password_Window);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 2);

        Edit_Password = new QLineEdit(VNC_Password_Window);
        Edit_Password->setObjectName(QString::fromUtf8("Edit_Password"));
        Edit_Password->setMaxLength(8);
        Edit_Password->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(Edit_Password, 1, 0, 1, 2);

        Edit_Confirm_Password = new QLineEdit(VNC_Password_Window);
        Edit_Confirm_Password->setObjectName(QString::fromUtf8("Edit_Confirm_Password"));
        Edit_Confirm_Password->setMaxLength(8);
        Edit_Confirm_Password->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(Edit_Confirm_Password, 3, 0, 1, 2);

        label_2 = new QLabel(VNC_Password_Window);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 2);

        Button_OK = new QPushButton(VNC_Password_Window);
        Button_OK->setObjectName(QString::fromUtf8("Button_OK"));

        gridLayout->addWidget(Button_OK, 4, 1, 1, 1);

        spacerItem = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(spacerItem, 4, 0, 1, 1);


        retranslateUi(VNC_Password_Window);

        QMetaObject::connectSlotsByName(VNC_Password_Window);
    } // setupUi

    void retranslateUi(QDialog *VNC_Password_Window)
    {
        VNC_Password_Window->setWindowTitle(QApplication::translate("VNC_Password_Window", "VNC Password", nullptr));
        label->setText(QApplication::translate("VNC_Password_Window", "Password:", nullptr));
        label_2->setText(QApplication::translate("VNC_Password_Window", "Confirm:", nullptr));
        Button_OK->setText(QApplication::translate("VNC_Password_Window", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class VNC_Password_Window: public Ui_VNC_Password_Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VNC_PASSWORD_WINDOW_H
