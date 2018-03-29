/********************************************************************************
** Form generated from reading UI file 'proj_display.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROJ_DISPLAY_H
#define UI_PROJ_DISPLAY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_Proj_display
{
public:
    QGroupBox *groupBox_2;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_5;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_4;
    QCheckBox *checkBox_6;
    QGroupBox *groupBox;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;

    void setupUi(QDialog *Proj_display)
    {
        if (Proj_display->objectName().isEmpty())
            Proj_display->setObjectName(QStringLiteral("Proj_display"));
        Proj_display->resize(400, 300);
        groupBox_2 = new QGroupBox(Proj_display);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(190, 20, 171, 221));
        checkBox = new QCheckBox(groupBox_2);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(20, 30, 121, 20));
        checkBox_2 = new QCheckBox(groupBox_2);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));
        checkBox_2->setGeometry(QRect(20, 60, 121, 20));
        checkBox_5 = new QCheckBox(groupBox_2);
        checkBox_5->setObjectName(QStringLiteral("checkBox_5"));
        checkBox_5->setGeometry(QRect(20, 150, 121, 20));
        checkBox_3 = new QCheckBox(groupBox_2);
        checkBox_3->setObjectName(QStringLiteral("checkBox_3"));
        checkBox_3->setGeometry(QRect(20, 90, 121, 20));
        checkBox_4 = new QCheckBox(groupBox_2);
        checkBox_4->setObjectName(QStringLiteral("checkBox_4"));
        checkBox_4->setGeometry(QRect(20, 120, 121, 20));
        checkBox_6 = new QCheckBox(groupBox_2);
        checkBox_6->setObjectName(QStringLiteral("checkBox_6"));
        checkBox_6->setGeometry(QRect(20, 180, 141, 20));
        groupBox = new QGroupBox(Proj_display);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(20, 30, 120, 201));
        radioButton = new QRadioButton(groupBox);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setGeometry(QRect(10, 30, 95, 20));
        radioButton_2 = new QRadioButton(groupBox);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
        radioButton_2->setGeometry(QRect(10, 70, 95, 20));

        retranslateUi(Proj_display);
        QObject::connect(checkBox_6, SIGNAL(toggled(bool)), checkBox_5, SLOT(setChecked(bool)));
        QObject::connect(checkBox_6, SIGNAL(toggled(bool)), checkBox_4, SLOT(setChecked(bool)));
        QObject::connect(checkBox_6, SIGNAL(toggled(bool)), checkBox_3, SLOT(setChecked(bool)));
        QObject::connect(checkBox_6, SIGNAL(toggled(bool)), checkBox_2, SLOT(setChecked(bool)));
        QObject::connect(checkBox_6, SIGNAL(toggled(bool)), checkBox, SLOT(setChecked(bool)));

        QMetaObject::connectSlotsByName(Proj_display);
    } // setupUi

    void retranslateUi(QDialog *Proj_display)
    {
        Proj_display->setWindowTitle(QApplication::translate("Proj_display", "Dialog", nullptr));
        groupBox_2->setTitle(QApplication::translate("Proj_display", "PROJECTION", nullptr));
        checkBox->setText(QApplication::translate("Proj_display", "PROJECTION 1", nullptr));
        checkBox_2->setText(QApplication::translate("Proj_display", "PROJECTION 2", nullptr));
        checkBox_5->setText(QApplication::translate("Proj_display", "PROJECTION 5", nullptr));
        checkBox_3->setText(QApplication::translate("Proj_display", "PROJECTION 3", nullptr));
        checkBox_4->setText(QApplication::translate("Proj_display", "PROJECTION 4", nullptr));
        checkBox_6->setText(QApplication::translate("Proj_display", "ALL PROJECTIONS", nullptr));
        groupBox->setTitle(QApplication::translate("Proj_display", "VIEW MODE", nullptr));
        radioButton->setText(QApplication::translate("Proj_display", "3D VIEW", nullptr));
        radioButton_2->setText(QApplication::translate("Proj_display", "2D VIEW", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Proj_display: public Ui_Proj_display {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROJ_DISPLAY_H
