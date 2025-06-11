/********************************************************************************
** Form generated from reading UI file 'Monitor_Window.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MONITOR_WINDOW_H
#define UI_MONITOR_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_Monitor_Window
{
public:
    QGridLayout *gridLayout;
    QComboBox *CB_Com_Line;
    QLabel *Label_Command;
    QTextEdit *Edit_Monitor_Out;
    QPushButton *Button_Run;
    QPushButton *Button_Clear;

    void setupUi(QDialog *Monitor_Window)
    {
        if (Monitor_Window->objectName().isEmpty())
            Monitor_Window->setObjectName(QString::fromUtf8("Monitor_Window"));
        Monitor_Window->resize(570, 264);
        gridLayout = new QGridLayout(Monitor_Window);
#ifndef Q_OS_MAC
        gridLayout->setSpacing(6);
#endif
        gridLayout->setContentsMargins(8, 8, 8, 8);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        CB_Com_Line = new QComboBox(Monitor_Window);
        CB_Com_Line->addItem(QString());
        CB_Com_Line->addItem(QString());
        CB_Com_Line->addItem(QString());
        CB_Com_Line->addItem(QString());
        CB_Com_Line->addItem(QString());
        CB_Com_Line->addItem(QString());
        CB_Com_Line->addItem(QString());
        CB_Com_Line->addItem(QString());
        CB_Com_Line->addItem(QString());
        CB_Com_Line->addItem(QString());
        CB_Com_Line->addItem(QString());
        CB_Com_Line->addItem(QString());
        CB_Com_Line->addItem(QString());
        CB_Com_Line->addItem(QString());
        CB_Com_Line->addItem(QString());
        CB_Com_Line->addItem(QString());
        CB_Com_Line->addItem(QString());
        CB_Com_Line->addItem(QString());
        CB_Com_Line->addItem(QString());
        CB_Com_Line->addItem(QString());
        CB_Com_Line->setObjectName(QString::fromUtf8("CB_Com_Line"));
        QSizePolicy sizePolicy(static_cast<QSizePolicy::Policy>(1), static_cast<QSizePolicy::Policy>(0));
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CB_Com_Line->sizePolicy().hasHeightForWidth());
        CB_Com_Line->setSizePolicy(sizePolicy);
        CB_Com_Line->setEditable(true);
        CB_Com_Line->setMaxCount(512);

        gridLayout->addWidget(CB_Com_Line, 1, 1, 1, 1);

        Label_Command = new QLabel(Monitor_Window);
        Label_Command->setObjectName(QString::fromUtf8("Label_Command"));
        QSizePolicy sizePolicy1(static_cast<QSizePolicy::Policy>(4), static_cast<QSizePolicy::Policy>(5));
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(Label_Command->sizePolicy().hasHeightForWidth());
        Label_Command->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(Label_Command, 1, 0, 1, 1);

        Edit_Monitor_Out = new QTextEdit(Monitor_Window);
        Edit_Monitor_Out->setObjectName(QString::fromUtf8("Edit_Monitor_Out"));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush1(QColor(0, 0, 0, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        QBrush brush2(QColor(113, 115, 119, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        Edit_Monitor_Out->setPalette(palette);
        Edit_Monitor_Out->setUndoRedoEnabled(false);
        Edit_Monitor_Out->setReadOnly(true);

        gridLayout->addWidget(Edit_Monitor_Out, 0, 0, 1, 4);

        Button_Run = new QPushButton(Monitor_Window);
        Button_Run->setObjectName(QString::fromUtf8("Button_Run"));
        QSizePolicy sizePolicy2(static_cast<QSizePolicy::Policy>(4), static_cast<QSizePolicy::Policy>(0));
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(Button_Run->sizePolicy().hasHeightForWidth());
        Button_Run->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(Button_Run, 1, 2, 1, 1);

        Button_Clear = new QPushButton(Monitor_Window);
        Button_Clear->setObjectName(QString::fromUtf8("Button_Clear"));
        sizePolicy2.setHeightForWidth(Button_Clear->sizePolicy().hasHeightForWidth());
        Button_Clear->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(Button_Clear, 1, 3, 1, 1);

#ifndef QT_NO_SHORTCUT
        Label_Command->setBuddy(CB_Com_Line);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(CB_Com_Line, Button_Run);
        QWidget::setTabOrder(Button_Run, Button_Clear);
        QWidget::setTabOrder(Button_Clear, Edit_Monitor_Out);

        retranslateUi(Monitor_Window);
        QObject::connect(Button_Clear, SIGNAL(clicked()), Edit_Monitor_Out, SLOT(clear()));

        CB_Com_Line->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(Monitor_Window);
    } // setupUi

    void retranslateUi(QDialog *Monitor_Window)
    {
        Monitor_Window->setWindowTitle(QApplication::translate("Monitor_Window", "QEMU Monitor", nullptr));
        CB_Com_Line->setItemText(0, QApplication::translate("Monitor_Window", "info version", nullptr));
        CB_Com_Line->setItemText(1, QApplication::translate("Monitor_Window", "info network", nullptr));
        CB_Com_Line->setItemText(2, QApplication::translate("Monitor_Window", "info block", nullptr));
        CB_Com_Line->setItemText(3, QApplication::translate("Monitor_Window", "info registers", nullptr));
        CB_Com_Line->setItemText(4, QApplication::translate("Monitor_Window", "info cpus", nullptr));
        CB_Com_Line->setItemText(5, QApplication::translate("Monitor_Window", "info history", nullptr));
        CB_Com_Line->setItemText(6, QApplication::translate("Monitor_Window", "info irq", nullptr));
        CB_Com_Line->setItemText(7, QApplication::translate("Monitor_Window", "info pic", nullptr));
        CB_Com_Line->setItemText(8, QApplication::translate("Monitor_Window", "info pci", nullptr));
        CB_Com_Line->setItemText(9, QApplication::translate("Monitor_Window", "info tlb", nullptr));
        CB_Com_Line->setItemText(10, QApplication::translate("Monitor_Window", "info mem", nullptr));
        CB_Com_Line->setItemText(11, QApplication::translate("Monitor_Window", "info jit", nullptr));
        CB_Com_Line->setItemText(12, QApplication::translate("Monitor_Window", "info kqemu", nullptr));
        CB_Com_Line->setItemText(13, QApplication::translate("Monitor_Window", "info usb", nullptr));
        CB_Com_Line->setItemText(14, QApplication::translate("Monitor_Window", "info usbhost", nullptr));
        CB_Com_Line->setItemText(15, QApplication::translate("Monitor_Window", "info profile", nullptr));
        CB_Com_Line->setItemText(16, QApplication::translate("Monitor_Window", "info capture", nullptr));
        CB_Com_Line->setItemText(17, QApplication::translate("Monitor_Window", "info snapshots", nullptr));
        CB_Com_Line->setItemText(18, QApplication::translate("Monitor_Window", "info mice", nullptr));
        CB_Com_Line->setItemText(19, QApplication::translate("Monitor_Window", "info vnc", nullptr));

        Label_Command->setText(QApplication::translate("Monitor_Window", "Com&mand:", nullptr));
        Button_Run->setText(QApplication::translate("Monitor_Window", "&Run", nullptr));
        Button_Clear->setText(QApplication::translate("Monitor_Window", "&Clear", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Monitor_Window: public Ui_Monitor_Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MONITOR_WINDOW_H
