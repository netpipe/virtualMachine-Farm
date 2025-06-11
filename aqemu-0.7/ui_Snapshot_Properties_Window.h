/********************************************************************************
** Form generated from reading UI file 'Snapshot_Properties_Window.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SNAPSHOT_PROPERTIES_WINDOW_H
#define UI_SNAPSHOT_PROPERTIES_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_Snapshot_Properties_Window
{
public:
    QGridLayout *gridLayout;
    QLabel *Label_Name;
    QLineEdit *Edit_Name;
    QLabel *Label_Desc;
    QPlainTextEdit *Edit_Description;
    QHBoxLayout *hboxLayout;
    QSpacerItem *spacerItem;
    QPushButton *Button_OK;
    QPushButton *Button_Cancel;

    void setupUi(QDialog *Snapshot_Properties_Window)
    {
        if (Snapshot_Properties_Window->objectName().isEmpty())
            Snapshot_Properties_Window->setObjectName(QString::fromUtf8("Snapshot_Properties_Window"));
        Snapshot_Properties_Window->resize(356, 217);
        gridLayout = new QGridLayout(Snapshot_Properties_Window);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        Label_Name = new QLabel(Snapshot_Properties_Window);
        Label_Name->setObjectName(QString::fromUtf8("Label_Name"));

        gridLayout->addWidget(Label_Name, 0, 0, 1, 1);

        Edit_Name = new QLineEdit(Snapshot_Properties_Window);
        Edit_Name->setObjectName(QString::fromUtf8("Edit_Name"));
        Edit_Name->setMaxLength(512);

        gridLayout->addWidget(Edit_Name, 1, 0, 1, 1);

        Label_Desc = new QLabel(Snapshot_Properties_Window);
        Label_Desc->setObjectName(QString::fromUtf8("Label_Desc"));

        gridLayout->addWidget(Label_Desc, 2, 0, 1, 1);

        Edit_Description = new QPlainTextEdit(Snapshot_Properties_Window);
        Edit_Description->setObjectName(QString::fromUtf8("Edit_Description"));

        gridLayout->addWidget(Edit_Description, 3, 0, 1, 1);

        hboxLayout = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout->setSpacing(6);
#endif
        hboxLayout->setContentsMargins(0, 0, 0, 0);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        spacerItem = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(spacerItem);

        Button_OK = new QPushButton(Snapshot_Properties_Window);
        Button_OK->setObjectName(QString::fromUtf8("Button_OK"));

        hboxLayout->addWidget(Button_OK);

        Button_Cancel = new QPushButton(Snapshot_Properties_Window);
        Button_Cancel->setObjectName(QString::fromUtf8("Button_Cancel"));

        hboxLayout->addWidget(Button_Cancel);


        gridLayout->addLayout(hboxLayout, 4, 0, 1, 1);

        QWidget::setTabOrder(Edit_Name, Button_OK);
        QWidget::setTabOrder(Button_OK, Button_Cancel);

        retranslateUi(Snapshot_Properties_Window);
        QObject::connect(Button_Cancel, SIGNAL(clicked()), Snapshot_Properties_Window, SLOT(reject()));

        QMetaObject::connectSlotsByName(Snapshot_Properties_Window);
    } // setupUi

    void retranslateUi(QDialog *Snapshot_Properties_Window)
    {
        Snapshot_Properties_Window->setWindowTitle(QApplication::translate("Snapshot_Properties_Window", "Snapshot Properties", nullptr));
        Label_Name->setText(QApplication::translate("Snapshot_Properties_Window", "Snapshot Name:", nullptr));
        Label_Desc->setText(QApplication::translate("Snapshot_Properties_Window", "Snapshot Description:", nullptr));
        Edit_Description->setPlainText(QString());
        Button_OK->setText(QApplication::translate("Snapshot_Properties_Window", "&OK", nullptr));
        Button_Cancel->setText(QApplication::translate("Snapshot_Properties_Window", "&Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Snapshot_Properties_Window: public Ui_Snapshot_Properties_Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SNAPSHOT_PROPERTIES_WINDOW_H
