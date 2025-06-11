/********************************************************************************
** Form generated from reading UI file 'Screenshot_Options_Window.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCREENSHOT_OPTIONS_WINDOW_H
#define UI_SCREENSHOT_OPTIONS_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QToolButton>

QT_BEGIN_NAMESPACE

class Ui_Screenshot_Options_Window
{
public:
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout_2;
    QLabel *Label__Screenshot_Save_Format;
    QRadioButton *RB_Format_PPM;
    QRadioButton *RB_Format_Jpeg;
    QRadioButton *RB_Format_PNG;
    QFrame *line_2;
    QGridLayout *gridLayout_3;
    QLabel *Label_Jpeg_Quality;
    QSlider *HS_Jpeg_Quality;
    QSpinBox *SB_Jpeg_Quality;
    QFrame *line_3;
    QGridLayout *gridLayout;
    QCheckBox *CH_Screenshot_Folder;
    QLabel *Label_Folder_Path;
    QLineEdit *Edit_Screenshot_Folder;
    QToolButton *TB_Screenshot_Folder;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *Button_OK;
    QPushButton *Button_Cancel;

    void setupUi(QDialog *Screenshot_Options_Window)
    {
        if (Screenshot_Options_Window->objectName().isEmpty())
            Screenshot_Options_Window->setObjectName(QString::fromUtf8("Screenshot_Options_Window"));
        Screenshot_Options_Window->resize(396, 174);
        gridLayout_4 = new QGridLayout(Screenshot_Options_Window);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        Label__Screenshot_Save_Format = new QLabel(Screenshot_Options_Window);
        Label__Screenshot_Save_Format->setObjectName(QString::fromUtf8("Label__Screenshot_Save_Format"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Label__Screenshot_Save_Format->sizePolicy().hasHeightForWidth());
        Label__Screenshot_Save_Format->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(Label__Screenshot_Save_Format, 0, 0, 1, 1);

        RB_Format_PPM = new QRadioButton(Screenshot_Options_Window);
        RB_Format_PPM->setObjectName(QString::fromUtf8("RB_Format_PPM"));

        gridLayout_2->addWidget(RB_Format_PPM, 1, 0, 1, 1);

        RB_Format_Jpeg = new QRadioButton(Screenshot_Options_Window);
        RB_Format_Jpeg->setObjectName(QString::fromUtf8("RB_Format_Jpeg"));

        gridLayout_2->addWidget(RB_Format_Jpeg, 1, 1, 1, 1);

        RB_Format_PNG = new QRadioButton(Screenshot_Options_Window);
        RB_Format_PNG->setObjectName(QString::fromUtf8("RB_Format_PNG"));

        gridLayout_2->addWidget(RB_Format_PNG, 1, 2, 1, 1);


        gridLayout_4->addLayout(gridLayout_2, 0, 0, 1, 1);

        line_2 = new QFrame(Screenshot_Options_Window);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout_4->addWidget(line_2, 0, 1, 1, 1);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        Label_Jpeg_Quality = new QLabel(Screenshot_Options_Window);
        Label_Jpeg_Quality->setObjectName(QString::fromUtf8("Label_Jpeg_Quality"));
        Label_Jpeg_Quality->setEnabled(false);

        gridLayout_3->addWidget(Label_Jpeg_Quality, 0, 0, 1, 1);

        HS_Jpeg_Quality = new QSlider(Screenshot_Options_Window);
        HS_Jpeg_Quality->setObjectName(QString::fromUtf8("HS_Jpeg_Quality"));
        HS_Jpeg_Quality->setEnabled(false);
        HS_Jpeg_Quality->setMinimum(20);
        HS_Jpeg_Quality->setMaximum(100);
        HS_Jpeg_Quality->setSingleStep(5);
        HS_Jpeg_Quality->setValue(75);
        HS_Jpeg_Quality->setOrientation(Qt::Horizontal);
        HS_Jpeg_Quality->setTickPosition(QSlider::TicksBelow);

        gridLayout_3->addWidget(HS_Jpeg_Quality, 1, 0, 1, 1);

        SB_Jpeg_Quality = new QSpinBox(Screenshot_Options_Window);
        SB_Jpeg_Quality->setObjectName(QString::fromUtf8("SB_Jpeg_Quality"));
        SB_Jpeg_Quality->setEnabled(false);
        SB_Jpeg_Quality->setMinimum(20);
        SB_Jpeg_Quality->setMaximum(100);
        SB_Jpeg_Quality->setSingleStep(5);
        SB_Jpeg_Quality->setValue(75);

        gridLayout_3->addWidget(SB_Jpeg_Quality, 1, 1, 1, 1);


        gridLayout_4->addLayout(gridLayout_3, 0, 2, 1, 1);

        line_3 = new QFrame(Screenshot_Options_Window);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        gridLayout_4->addWidget(line_3, 1, 0, 1, 3);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        CH_Screenshot_Folder = new QCheckBox(Screenshot_Options_Window);
        CH_Screenshot_Folder->setObjectName(QString::fromUtf8("CH_Screenshot_Folder"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(CH_Screenshot_Folder->sizePolicy().hasHeightForWidth());
        CH_Screenshot_Folder->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(CH_Screenshot_Folder, 0, 0, 1, 2);

        Label_Folder_Path = new QLabel(Screenshot_Options_Window);
        Label_Folder_Path->setObjectName(QString::fromUtf8("Label_Folder_Path"));
        Label_Folder_Path->setEnabled(false);

        gridLayout->addWidget(Label_Folder_Path, 1, 0, 1, 1);

        Edit_Screenshot_Folder = new QLineEdit(Screenshot_Options_Window);
        Edit_Screenshot_Folder->setObjectName(QString::fromUtf8("Edit_Screenshot_Folder"));
        Edit_Screenshot_Folder->setEnabled(false);

        gridLayout->addWidget(Edit_Screenshot_Folder, 1, 1, 1, 1);

        TB_Screenshot_Folder = new QToolButton(Screenshot_Options_Window);
        TB_Screenshot_Folder->setObjectName(QString::fromUtf8("TB_Screenshot_Folder"));
        TB_Screenshot_Folder->setEnabled(false);

        gridLayout->addWidget(TB_Screenshot_Folder, 1, 2, 1, 1);


        gridLayout_4->addLayout(gridLayout, 2, 0, 1, 3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        Button_OK = new QPushButton(Screenshot_Options_Window);
        Button_OK->setObjectName(QString::fromUtf8("Button_OK"));

        horizontalLayout->addWidget(Button_OK);

        Button_Cancel = new QPushButton(Screenshot_Options_Window);
        Button_Cancel->setObjectName(QString::fromUtf8("Button_Cancel"));

        horizontalLayout->addWidget(Button_Cancel);


        gridLayout_4->addLayout(horizontalLayout, 3, 0, 1, 3);

#ifndef QT_NO_SHORTCUT
        Label__Screenshot_Save_Format->setBuddy(RB_Format_PPM);
        Label_Jpeg_Quality->setBuddy(SB_Jpeg_Quality);
        Label_Folder_Path->setBuddy(Edit_Screenshot_Folder);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(RB_Format_PPM, RB_Format_Jpeg);
        QWidget::setTabOrder(RB_Format_Jpeg, RB_Format_PNG);
        QWidget::setTabOrder(RB_Format_PNG, HS_Jpeg_Quality);
        QWidget::setTabOrder(HS_Jpeg_Quality, SB_Jpeg_Quality);
        QWidget::setTabOrder(SB_Jpeg_Quality, CH_Screenshot_Folder);
        QWidget::setTabOrder(CH_Screenshot_Folder, Edit_Screenshot_Folder);
        QWidget::setTabOrder(Edit_Screenshot_Folder, TB_Screenshot_Folder);
        QWidget::setTabOrder(TB_Screenshot_Folder, Button_OK);
        QWidget::setTabOrder(Button_OK, Button_Cancel);

        retranslateUi(Screenshot_Options_Window);
        QObject::connect(RB_Format_Jpeg, SIGNAL(toggled(bool)), HS_Jpeg_Quality, SLOT(setEnabled(bool)));
        QObject::connect(RB_Format_Jpeg, SIGNAL(toggled(bool)), SB_Jpeg_Quality, SLOT(setEnabled(bool)));
        QObject::connect(RB_Format_Jpeg, SIGNAL(toggled(bool)), Label_Jpeg_Quality, SLOT(setEnabled(bool)));
        QObject::connect(RB_Format_PPM, SIGNAL(toggled(bool)), Label_Jpeg_Quality, SLOT(setDisabled(bool)));
        QObject::connect(RB_Format_PPM, SIGNAL(toggled(bool)), HS_Jpeg_Quality, SLOT(setDisabled(bool)));
        QObject::connect(RB_Format_PPM, SIGNAL(toggled(bool)), SB_Jpeg_Quality, SLOT(setDisabled(bool)));
        QObject::connect(RB_Format_PNG, SIGNAL(toggled(bool)), Label_Jpeg_Quality, SLOT(setDisabled(bool)));
        QObject::connect(RB_Format_PNG, SIGNAL(toggled(bool)), HS_Jpeg_Quality, SLOT(setDisabled(bool)));
        QObject::connect(RB_Format_PNG, SIGNAL(toggled(bool)), SB_Jpeg_Quality, SLOT(setDisabled(bool)));
        QObject::connect(CH_Screenshot_Folder, SIGNAL(toggled(bool)), Label_Folder_Path, SLOT(setEnabled(bool)));
        QObject::connect(CH_Screenshot_Folder, SIGNAL(toggled(bool)), Edit_Screenshot_Folder, SLOT(setEnabled(bool)));
        QObject::connect(CH_Screenshot_Folder, SIGNAL(toggled(bool)), TB_Screenshot_Folder, SLOT(setEnabled(bool)));
        QObject::connect(Button_Cancel, SIGNAL(clicked()), Screenshot_Options_Window, SLOT(reject()));
        QObject::connect(HS_Jpeg_Quality, SIGNAL(valueChanged(int)), SB_Jpeg_Quality, SLOT(setValue(int)));
        QObject::connect(SB_Jpeg_Quality, SIGNAL(valueChanged(int)), HS_Jpeg_Quality, SLOT(setValue(int)));

        QMetaObject::connectSlotsByName(Screenshot_Options_Window);
    } // setupUi

    void retranslateUi(QDialog *Screenshot_Options_Window)
    {
        Screenshot_Options_Window->setWindowTitle(QApplication::translate("Screenshot_Options_Window", "Screenshot Options", nullptr));
        Label__Screenshot_Save_Format->setText(QApplication::translate("Screenshot_Options_Window", "Save Format:", nullptr));
        RB_Format_PPM->setText(QApplication::translate("Screenshot_Options_Window", "Original (PPM)", nullptr));
        RB_Format_Jpeg->setText(QApplication::translate("Screenshot_Options_Window", "Jpeg", nullptr));
        RB_Format_PNG->setText(QApplication::translate("Screenshot_Options_Window", "PNG", nullptr));
        Label_Jpeg_Quality->setText(QApplication::translate("Screenshot_Options_Window", "Jpeg Quality:", nullptr));
        CH_Screenshot_Folder->setText(QApplication::translate("Screenshot_Options_Window", "Shared Folder to Save All Screenshots", nullptr));
        Label_Folder_Path->setText(QApplication::translate("Screenshot_Options_Window", "Folder Path:", nullptr));
        TB_Screenshot_Folder->setText(QApplication::translate("Screenshot_Options_Window", "...", nullptr));
        Button_OK->setText(QApplication::translate("Screenshot_Options_Window", "&OK", nullptr));
        Button_Cancel->setText(QApplication::translate("Screenshot_Options_Window", "&Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Screenshot_Options_Window: public Ui_Screenshot_Options_Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCREENSHOT_OPTIONS_WINDOW_H
