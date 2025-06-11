/********************************************************************************
** Form generated from reading UI file 'Select_Icon_Window.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECT_ICON_WINDOW_H
#define UI_SELECT_ICON_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Select_Icon_Window
{
public:
    QVBoxLayout *vboxLayout;
    QGroupBox *GB_Default_Icons;
    QHBoxLayout *hboxLayout;
    QRadioButton *RB_Icon_Other;
    QSpacerItem *spacerItem;
    QRadioButton *RB_Icon_Windows;
    QSpacerItem *spacerItem1;
    QRadioButton *RB_Icon_Linux;
    QGroupBox *GB_All_Icons;
    QGridLayout *gridLayout;
    QListWidget *All_Icons_List;
    QGroupBox *GB_Other_Icons;
    QGridLayout *gridLayout1;
    QPushButton *Button_Browse;
    QLineEdit *Edit_Other_Icon_Path;
    QLabel *Label_You_Icon_Path;
    QGridLayout *gridLayout2;
    QPushButton *Button_OK;
    QSpacerItem *spacerItem2;
    QPushButton *Button_Cancel;

    void setupUi(QDialog *Select_Icon_Window)
    {
        if (Select_Icon_Window->objectName().isEmpty())
            Select_Icon_Window->setObjectName(QString::fromUtf8("Select_Icon_Window"));
        Select_Icon_Window->resize(463, 435);
        vboxLayout = new QVBoxLayout(Select_Icon_Window);
#ifndef Q_OS_MAC
        vboxLayout->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        vboxLayout->setContentsMargins(9, 9, 9, 9);
#endif
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        GB_Default_Icons = new QGroupBox(Select_Icon_Window);
        GB_Default_Icons->setObjectName(QString::fromUtf8("GB_Default_Icons"));
        QSizePolicy sizePolicy(static_cast<QSizePolicy::Policy>(5), static_cast<QSizePolicy::Policy>(4));
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(GB_Default_Icons->sizePolicy().hasHeightForWidth());
        GB_Default_Icons->setSizePolicy(sizePolicy);
        GB_Default_Icons->setCheckable(true);
        GB_Default_Icons->setChecked(true);
        hboxLayout = new QHBoxLayout(GB_Default_Icons);
#ifndef Q_OS_MAC
        hboxLayout->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        hboxLayout->setContentsMargins(9, 9, 9, 9);
#endif
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        RB_Icon_Other = new QRadioButton(GB_Default_Icons);
        RB_Icon_Other->setObjectName(QString::fromUtf8("RB_Icon_Other"));

        hboxLayout->addWidget(RB_Icon_Other);

        spacerItem = new QSpacerItem(16, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(spacerItem);

        RB_Icon_Windows = new QRadioButton(GB_Default_Icons);
        RB_Icon_Windows->setObjectName(QString::fromUtf8("RB_Icon_Windows"));

        hboxLayout->addWidget(RB_Icon_Windows);

        spacerItem1 = new QSpacerItem(16, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(spacerItem1);

        RB_Icon_Linux = new QRadioButton(GB_Default_Icons);
        RB_Icon_Linux->setObjectName(QString::fromUtf8("RB_Icon_Linux"));

        hboxLayout->addWidget(RB_Icon_Linux);


        vboxLayout->addWidget(GB_Default_Icons);

        GB_All_Icons = new QGroupBox(Select_Icon_Window);
        GB_All_Icons->setObjectName(QString::fromUtf8("GB_All_Icons"));
        QSizePolicy sizePolicy1(static_cast<QSizePolicy::Policy>(5), static_cast<QSizePolicy::Policy>(1));
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(GB_All_Icons->sizePolicy().hasHeightForWidth());
        GB_All_Icons->setSizePolicy(sizePolicy1);
        GB_All_Icons->setCheckable(true);
        GB_All_Icons->setChecked(true);
        gridLayout = new QGridLayout(GB_All_Icons);
        gridLayout->setSpacing(3);
        gridLayout->setContentsMargins(6, 6, 6, 6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        All_Icons_List = new QListWidget(GB_All_Icons);
        All_Icons_List->setObjectName(QString::fromUtf8("All_Icons_List"));
        All_Icons_List->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        All_Icons_List->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        All_Icons_List->setAutoScroll(false);
        All_Icons_List->setDragDropMode(QAbstractItemView::NoDragDrop);
        All_Icons_List->setIconSize(QSize(64, 64));
        All_Icons_List->setTextElideMode(Qt::ElideMiddle);
        All_Icons_List->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        All_Icons_List->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
        All_Icons_List->setMovement(QListView::Static);
        All_Icons_List->setLayoutMode(QListView::Batched);
        All_Icons_List->setSpacing(10);
        All_Icons_List->setViewMode(QListView::IconMode);
        All_Icons_List->setWordWrap(true);

        gridLayout->addWidget(All_Icons_List, 0, 0, 1, 1);


        vboxLayout->addWidget(GB_All_Icons);

        GB_Other_Icons = new QGroupBox(Select_Icon_Window);
        GB_Other_Icons->setObjectName(QString::fromUtf8("GB_Other_Icons"));
        sizePolicy.setHeightForWidth(GB_Other_Icons->sizePolicy().hasHeightForWidth());
        GB_Other_Icons->setSizePolicy(sizePolicy);
        GB_Other_Icons->setCheckable(true);
        GB_Other_Icons->setChecked(true);
        gridLayout1 = new QGridLayout(GB_Other_Icons);
        gridLayout1->setSpacing(3);
        gridLayout1->setContentsMargins(6, 6, 6, 6);
        gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
        Button_Browse = new QPushButton(GB_Other_Icons);
        Button_Browse->setObjectName(QString::fromUtf8("Button_Browse"));

        gridLayout1->addWidget(Button_Browse, 1, 1, 1, 1);

        Edit_Other_Icon_Path = new QLineEdit(GB_Other_Icons);
        Edit_Other_Icon_Path->setObjectName(QString::fromUtf8("Edit_Other_Icon_Path"));

        gridLayout1->addWidget(Edit_Other_Icon_Path, 1, 0, 1, 1);

        Label_You_Icon_Path = new QLabel(GB_Other_Icons);
        Label_You_Icon_Path->setObjectName(QString::fromUtf8("Label_You_Icon_Path"));

        gridLayout1->addWidget(Label_You_Icon_Path, 0, 0, 1, 1);


        vboxLayout->addWidget(GB_Other_Icons);

        gridLayout2 = new QGridLayout();
#ifndef Q_OS_MAC
        gridLayout2->setSpacing(6);
#endif
        gridLayout2->setContentsMargins(0, 0, 0, 0);
        gridLayout2->setObjectName(QString::fromUtf8("gridLayout2"));
        Button_OK = new QPushButton(Select_Icon_Window);
        Button_OK->setObjectName(QString::fromUtf8("Button_OK"));

        gridLayout2->addWidget(Button_OK, 0, 1, 1, 1);

        spacerItem2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout2->addItem(spacerItem2, 0, 0, 1, 1);

        Button_Cancel = new QPushButton(Select_Icon_Window);
        Button_Cancel->setObjectName(QString::fromUtf8("Button_Cancel"));

        gridLayout2->addWidget(Button_Cancel, 0, 2, 1, 1);


        vboxLayout->addLayout(gridLayout2);

        QWidget::setTabOrder(RB_Icon_Other, RB_Icon_Windows);
        QWidget::setTabOrder(RB_Icon_Windows, RB_Icon_Linux);
        QWidget::setTabOrder(RB_Icon_Linux, All_Icons_List);
        QWidget::setTabOrder(All_Icons_List, Edit_Other_Icon_Path);
        QWidget::setTabOrder(Edit_Other_Icon_Path, Button_Browse);
        QWidget::setTabOrder(Button_Browse, Button_OK);
        QWidget::setTabOrder(Button_OK, Button_Cancel);

        retranslateUi(Select_Icon_Window);
        QObject::connect(Button_Cancel, SIGNAL(clicked()), Select_Icon_Window, SLOT(reject()));

        QMetaObject::connectSlotsByName(Select_Icon_Window);
    } // setupUi

    void retranslateUi(QDialog *Select_Icon_Window)
    {
        Select_Icon_Window->setWindowTitle(QApplication::translate("Select_Icon_Window", "Change Icon", nullptr));
        GB_Default_Icons->setTitle(QApplication::translate("Select_Icon_Window", "&Default OS Icons", nullptr));
        RB_Icon_Other->setText(QApplication::translate("Select_Icon_Window", "Default &Other System", nullptr));
        RB_Icon_Windows->setText(QApplication::translate("Select_Icon_Window", "Default &Windows", nullptr));
        RB_Icon_Linux->setText(QApplication::translate("Select_Icon_Window", "Default &Linux", nullptr));
        GB_All_Icons->setTitle(QApplication::translate("Select_Icon_Window", "&All OS Icons", nullptr));
        GB_Other_Icons->setTitle(QApplication::translate("Select_Icon_Window", "Other &Icon", nullptr));
        Button_Browse->setText(QApplication::translate("Select_Icon_Window", "&Browse...", nullptr));
        Label_You_Icon_Path->setText(QApplication::translate("Select_Icon_Window", "You Icon Path:", nullptr));
        Button_OK->setText(QApplication::translate("Select_Icon_Window", "&OK", nullptr));
        Button_Cancel->setText(QApplication::translate("Select_Icon_Window", "&Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Select_Icon_Window: public Ui_Select_Icon_Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECT_ICON_WINDOW_H
