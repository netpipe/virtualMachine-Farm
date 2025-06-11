/********************************************************************************
** Form generated from reading UI file 'Snapshots_Window.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SNAPSHOTS_WINDOW_H
#define UI_SNAPSHOTS_WINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTreeWidget>

QT_BEGIN_NAMESPACE

class Ui_Snapshots_Window
{
public:
    QGridLayout *gridLayout;
    QFrame *Info_Frame;
    QGridLayout *gridLayout1;
    QLabel *Label_Description;
    QLabel *Label_Size;
    QLabel *Label_VM_Clock;
    QLabel *Label_ID;
    QLabel *Label_Date;
    QSpacerItem *spacerItem;
    QPushButton *Button_Properties;
    QPushButton *Button_Start;
    QPushButton *Button_Delete;
    QPushButton *Button_Create;
    QPushButton *Button_OK;
    QPushButton *Button_Update;
    QTreeWidget *Snapshots_Tree;

    void setupUi(QDialog *Snapshots_Window)
    {
        if (Snapshots_Window->objectName().isEmpty())
            Snapshots_Window->setObjectName(QString::fromUtf8("Snapshots_Window"));
        Snapshots_Window->resize(474, 301);
        gridLayout = new QGridLayout(Snapshots_Window);
#ifndef Q_OS_MAC
        gridLayout->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        gridLayout->setContentsMargins(9, 9, 9, 9);
#endif
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        Info_Frame = new QFrame(Snapshots_Window);
        Info_Frame->setObjectName(QString::fromUtf8("Info_Frame"));
        QSizePolicy sizePolicy(static_cast<QSizePolicy::Policy>(7), static_cast<QSizePolicy::Policy>(7));
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Info_Frame->sizePolicy().hasHeightForWidth());
        Info_Frame->setSizePolicy(sizePolicy);
        Info_Frame->setFrameShape(QFrame::StyledPanel);
        Info_Frame->setFrameShadow(QFrame::Sunken);
        gridLayout1 = new QGridLayout(Info_Frame);
#ifndef Q_OS_MAC
        gridLayout1->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        gridLayout1->setContentsMargins(9, 9, 9, 9);
#endif
        gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
        Label_Description = new QLabel(Info_Frame);
        Label_Description->setObjectName(QString::fromUtf8("Label_Description"));

        gridLayout1->addWidget(Label_Description, 2, 0, 1, 2);

        Label_Size = new QLabel(Info_Frame);
        Label_Size->setObjectName(QString::fromUtf8("Label_Size"));
        QSizePolicy sizePolicy1(static_cast<QSizePolicy::Policy>(1), static_cast<QSizePolicy::Policy>(5));
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(Label_Size->sizePolicy().hasHeightForWidth());
        Label_Size->setSizePolicy(sizePolicy1);

        gridLayout1->addWidget(Label_Size, 1, 0, 1, 1);

        Label_VM_Clock = new QLabel(Info_Frame);
        Label_VM_Clock->setObjectName(QString::fromUtf8("Label_VM_Clock"));
        sizePolicy1.setHeightForWidth(Label_VM_Clock->sizePolicy().hasHeightForWidth());
        Label_VM_Clock->setSizePolicy(sizePolicy1);

        gridLayout1->addWidget(Label_VM_Clock, 1, 1, 1, 1);

        Label_ID = new QLabel(Info_Frame);
        Label_ID->setObjectName(QString::fromUtf8("Label_ID"));
        sizePolicy1.setHeightForWidth(Label_ID->sizePolicy().hasHeightForWidth());
        Label_ID->setSizePolicy(sizePolicy1);

        gridLayout1->addWidget(Label_ID, 0, 0, 1, 1);

        Label_Date = new QLabel(Info_Frame);
        Label_Date->setObjectName(QString::fromUtf8("Label_Date"));
        sizePolicy1.setHeightForWidth(Label_Date->sizePolicy().hasHeightForWidth());
        Label_Date->setSizePolicy(sizePolicy1);

        gridLayout1->addWidget(Label_Date, 0, 1, 1, 1);


        gridLayout->addWidget(Info_Frame, 5, 0, 2, 1);

        spacerItem = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(spacerItem, 5, 1, 1, 1);

        Button_Properties = new QPushButton(Snapshots_Window);
        Button_Properties->setObjectName(QString::fromUtf8("Button_Properties"));
        QSizePolicy sizePolicy2(static_cast<QSizePolicy::Policy>(5), static_cast<QSizePolicy::Policy>(0));
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(Button_Properties->sizePolicy().hasHeightForWidth());
        Button_Properties->setSizePolicy(sizePolicy2);
        const QIcon icon = QIcon(QString::fromUtf8(":/images/edit.png"));
        Button_Properties->setIcon(icon);
        Button_Properties->setIconSize(QSize(24, 24));

        gridLayout->addWidget(Button_Properties, 3, 1, 1, 1);

        Button_Start = new QPushButton(Snapshots_Window);
        Button_Start->setObjectName(QString::fromUtf8("Button_Start"));
        sizePolicy2.setHeightForWidth(Button_Start->sizePolicy().hasHeightForWidth());
        Button_Start->setSizePolicy(sizePolicy2);
        const QIcon icon1 = QIcon(QString::fromUtf8(":/images/player_play.png"));
        Button_Start->setIcon(icon1);
        Button_Start->setIconSize(QSize(24, 24));

        gridLayout->addWidget(Button_Start, 2, 1, 1, 1);

        Button_Delete = new QPushButton(Snapshots_Window);
        Button_Delete->setObjectName(QString::fromUtf8("Button_Delete"));
        sizePolicy2.setHeightForWidth(Button_Delete->sizePolicy().hasHeightForWidth());
        Button_Delete->setSizePolicy(sizePolicy2);
        const QIcon icon2 = QIcon(QString::fromUtf8(":/images/button_cancel.png"));
        Button_Delete->setIcon(icon2);
        Button_Delete->setIconSize(QSize(24, 24));

        gridLayout->addWidget(Button_Delete, 1, 1, 1, 1);

        Button_Create = new QPushButton(Snapshots_Window);
        Button_Create->setObjectName(QString::fromUtf8("Button_Create"));
        sizePolicy2.setHeightForWidth(Button_Create->sizePolicy().hasHeightForWidth());
        Button_Create->setSizePolicy(sizePolicy2);
        const QIcon icon3 = QIcon(QString::fromUtf8(":/images/add.png"));
        Button_Create->setIcon(icon3);
        Button_Create->setIconSize(QSize(24, 24));

        gridLayout->addWidget(Button_Create, 0, 1, 1, 1);

        Button_OK = new QPushButton(Snapshots_Window);
        Button_OK->setObjectName(QString::fromUtf8("Button_OK"));
        sizePolicy2.setHeightForWidth(Button_OK->sizePolicy().hasHeightForWidth());
        Button_OK->setSizePolicy(sizePolicy2);
        Button_OK->setIconSize(QSize(24, 24));

        gridLayout->addWidget(Button_OK, 6, 1, 1, 1);

        Button_Update = new QPushButton(Snapshots_Window);
        Button_Update->setObjectName(QString::fromUtf8("Button_Update"));
        sizePolicy2.setHeightForWidth(Button_Update->sizePolicy().hasHeightForWidth());
        Button_Update->setSizePolicy(sizePolicy2);
        const QIcon icon4 = QIcon(QString::fromUtf8(":/images/reload.png"));
        Button_Update->setIcon(icon4);
        Button_Update->setIconSize(QSize(24, 24));

        gridLayout->addWidget(Button_Update, 4, 1, 1, 1);

        Snapshots_Tree = new QTreeWidget(Snapshots_Window);
        Snapshots_Tree->setObjectName(QString::fromUtf8("Snapshots_Tree"));

        gridLayout->addWidget(Snapshots_Tree, 0, 0, 5, 1);

        QWidget::setTabOrder(Snapshots_Tree, Button_Create);
        QWidget::setTabOrder(Button_Create, Button_Delete);
        QWidget::setTabOrder(Button_Delete, Button_Start);
        QWidget::setTabOrder(Button_Start, Button_Properties);
        QWidget::setTabOrder(Button_Properties, Button_Update);
        QWidget::setTabOrder(Button_Update, Button_OK);

        retranslateUi(Snapshots_Window);
        QObject::connect(Button_OK, SIGNAL(clicked()), Snapshots_Window, SLOT(accept()));

        Button_OK->setDefault(true);


        QMetaObject::connectSlotsByName(Snapshots_Window);
    } // setupUi

    void retranslateUi(QDialog *Snapshots_Window)
    {
        Snapshots_Window->setWindowTitle(QApplication::translate("Snapshots_Window", "Manage VM Snapshots", nullptr));
        Label_Description->setText(QApplication::translate("Snapshots_Window", "Description:", nullptr));
        Label_Size->setText(QApplication::translate("Snapshots_Window", "Size:", nullptr));
        Label_VM_Clock->setText(QApplication::translate("Snapshots_Window", "VM Clock:", nullptr));
        Label_ID->setText(QApplication::translate("Snapshots_Window", "ID:", nullptr));
        Label_Date->setText(QApplication::translate("Snapshots_Window", "Date:", nullptr));
        Button_Properties->setText(QApplication::translate("Snapshots_Window", "Properties", nullptr));
        Button_Start->setText(QApplication::translate("Snapshots_Window", "Start", nullptr));
        Button_Delete->setText(QApplication::translate("Snapshots_Window", "Delete", nullptr));
        Button_Create->setText(QApplication::translate("Snapshots_Window", "Create", nullptr));
        Button_OK->setText(QApplication::translate("Snapshots_Window", "OK", nullptr));
        Button_Update->setText(QApplication::translate("Snapshots_Window", "Update Info", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = Snapshots_Tree->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("Snapshots_Window", "Snapshot List:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Snapshots_Window: public Ui_Snapshots_Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SNAPSHOTS_WINDOW_H
