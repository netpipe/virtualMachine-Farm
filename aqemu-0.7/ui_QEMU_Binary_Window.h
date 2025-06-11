/********************************************************************************
** Form generated from reading UI file 'QEMU_Binary_Window.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QEMU_BINARY_WINDOW_H
#define UI_QEMU_BINARY_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_QEMU_Binary_Window
{
public:
    QVBoxLayout *vboxLayout;
    QHBoxLayout *hboxLayout;
    QLabel *Label_Binary_Name;
    QLineEdit *Edit_Binary_Path;
    QToolButton *TB_Binary_Browse;
    QTableWidget *Table_QEMU_Systems;
    QHBoxLayout *hboxLayout1;
    QPushButton *Button_Reset_Settings;
    QSpacerItem *spacerItem;
    QPushButton *Button_OK;
    QPushButton *Button_Cancel;

    void setupUi(QDialog *QEMU_Binary_Window)
    {
        if (QEMU_Binary_Window->objectName().isEmpty())
            QEMU_Binary_Window->setObjectName(QString::fromUtf8("QEMU_Binary_Window"));
        QEMU_Binary_Window->resize(430, 357);
        QEMU_Binary_Window->setMaximumSize(QSize(430, 16777215));
        vboxLayout = new QVBoxLayout(QEMU_Binary_Window);
#ifndef Q_OS_MAC
        vboxLayout->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        vboxLayout->setContentsMargins(9, 9, 9, 9);
#endif
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        hboxLayout = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        hboxLayout->setContentsMargins(0, 0, 0, 0);
#endif
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        Label_Binary_Name = new QLabel(QEMU_Binary_Window);
        Label_Binary_Name->setObjectName(QString::fromUtf8("Label_Binary_Name"));

        hboxLayout->addWidget(Label_Binary_Name);

        Edit_Binary_Path = new QLineEdit(QEMU_Binary_Window);
        Edit_Binary_Path->setObjectName(QString::fromUtf8("Edit_Binary_Path"));

        hboxLayout->addWidget(Edit_Binary_Path);

        TB_Binary_Browse = new QToolButton(QEMU_Binary_Window);
        TB_Binary_Browse->setObjectName(QString::fromUtf8("TB_Binary_Browse"));

        hboxLayout->addWidget(TB_Binary_Browse);


        vboxLayout->addLayout(hboxLayout);

        Table_QEMU_Systems = new QTableWidget(QEMU_Binary_Window);
        if (Table_QEMU_Systems->columnCount() < 2)
            Table_QEMU_Systems->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        Table_QEMU_Systems->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        Table_QEMU_Systems->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        Table_QEMU_Systems->setObjectName(QString::fromUtf8("Table_QEMU_Systems"));
        Table_QEMU_Systems->setEditTriggers(QAbstractItemView::NoEditTriggers);
        Table_QEMU_Systems->setSelectionMode(QAbstractItemView::SingleSelection);
        Table_QEMU_Systems->setSelectionBehavior(QAbstractItemView::SelectRows);

        vboxLayout->addWidget(Table_QEMU_Systems);

        hboxLayout1 = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout1->setSpacing(6);
#endif
        hboxLayout1->setContentsMargins(0, 0, 0, 0);
        hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
        Button_Reset_Settings = new QPushButton(QEMU_Binary_Window);
        Button_Reset_Settings->setObjectName(QString::fromUtf8("Button_Reset_Settings"));

        hboxLayout1->addWidget(Button_Reset_Settings);

        spacerItem = new QSpacerItem(151, 27, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout1->addItem(spacerItem);

        Button_OK = new QPushButton(QEMU_Binary_Window);
        Button_OK->setObjectName(QString::fromUtf8("Button_OK"));

        hboxLayout1->addWidget(Button_OK);

        Button_Cancel = new QPushButton(QEMU_Binary_Window);
        Button_Cancel->setObjectName(QString::fromUtf8("Button_Cancel"));

        hboxLayout1->addWidget(Button_Cancel);


        vboxLayout->addLayout(hboxLayout1);

        QWidget::setTabOrder(Edit_Binary_Path, TB_Binary_Browse);
        QWidget::setTabOrder(TB_Binary_Browse, Table_QEMU_Systems);
        QWidget::setTabOrder(Table_QEMU_Systems, Button_Reset_Settings);
        QWidget::setTabOrder(Button_Reset_Settings, Button_OK);
        QWidget::setTabOrder(Button_OK, Button_Cancel);

        retranslateUi(QEMU_Binary_Window);
        QObject::connect(Button_Cancel, SIGNAL(clicked()), QEMU_Binary_Window, SLOT(reject()));

        QMetaObject::connectSlotsByName(QEMU_Binary_Window);
    } // setupUi

    void retranslateUi(QDialog *QEMU_Binary_Window)
    {
        QEMU_Binary_Window->setWindowTitle(QApplication::translate("QEMU_Binary_Window", "QEMU Binary", nullptr));
        Label_Binary_Name->setText(QApplication::translate("QEMU_Binary_Window", "Binary File Name:", nullptr));
        TB_Binary_Browse->setText(QApplication::translate("QEMU_Binary_Window", "...", nullptr));
        QTableWidgetItem *___qtablewidgetitem = Table_QEMU_Systems->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("QEMU_Binary_Window", "QEMU System", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = Table_QEMU_Systems->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("QEMU_Binary_Window", "Binary File Name", nullptr));
        Button_Reset_Settings->setText(QApplication::translate("QEMU_Binary_Window", "Reset to Default", nullptr));
        Button_OK->setText(QApplication::translate("QEMU_Binary_Window", "&OK", nullptr));
        Button_Cancel->setText(QApplication::translate("QEMU_Binary_Window", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QEMU_Binary_Window: public Ui_QEMU_Binary_Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QEMU_BINARY_WINDOW_H
