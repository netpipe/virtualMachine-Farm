/********************************************************************************
** Form generated from reading UI file 'Error_Log_Window.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ERROR_LOG_WINDOW_H
#define UI_ERROR_LOG_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_Error_Log_Window
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *spacerItem;
    QTextEdit *Edit_Log;
    QPushButton *Button_Clear_Log;
    QPushButton *Button_Hide;

    void setupUi(QDialog *Error_Log_Window)
    {
        if (Error_Log_Window->objectName().isEmpty())
            Error_Log_Window->setObjectName(QString::fromUtf8("Error_Log_Window"));
        Error_Log_Window->resize(457, 241);
        gridLayout = new QGridLayout(Error_Log_Window);
#ifndef Q_OS_MAC
        gridLayout->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        gridLayout->setContentsMargins(9, 9, 9, 9);
#endif
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        spacerItem = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(spacerItem, 1, 1, 1, 1);

        Edit_Log = new QTextEdit(Error_Log_Window);
        Edit_Log->setObjectName(QString::fromUtf8("Edit_Log"));
        Edit_Log->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        Edit_Log->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

        gridLayout->addWidget(Edit_Log, 0, 0, 1, 3);

        Button_Clear_Log = new QPushButton(Error_Log_Window);
        Button_Clear_Log->setObjectName(QString::fromUtf8("Button_Clear_Log"));

        gridLayout->addWidget(Button_Clear_Log, 1, 0, 1, 1);

        Button_Hide = new QPushButton(Error_Log_Window);
        Button_Hide->setObjectName(QString::fromUtf8("Button_Hide"));

        gridLayout->addWidget(Button_Hide, 1, 2, 1, 1);


        retranslateUi(Error_Log_Window);
        QObject::connect(Button_Clear_Log, SIGNAL(clicked()), Edit_Log, SLOT(clear()));
        QObject::connect(Button_Hide, SIGNAL(clicked()), Error_Log_Window, SLOT(close()));

        QMetaObject::connectSlotsByName(Error_Log_Window);
    } // setupUi

    void retranslateUi(QDialog *Error_Log_Window)
    {
        Error_Log_Window->setWindowTitle(QApplication::translate("Error_Log_Window", "QEMU Error Log", nullptr));
        Button_Clear_Log->setText(QApplication::translate("Error_Log_Window", "&Clear", nullptr));
        Button_Hide->setText(QApplication::translate("Error_Log_Window", "&Hide", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Error_Log_Window: public Ui_Error_Log_Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ERROR_LOG_WINDOW_H
