/********************************************************************************
** Form generated from reading UI file 'proj.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROJ_H
#define UI_PROJ_H

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

class Ui_Projection
{
public:
    QGroupBox *groupBox;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QGroupBox *groupBox_2;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_5;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_4;
    QCheckBox *checkBox_6;

    void setupUi(QDialog *Projection)
    {
        if (Projection->objectName().isEmpty())
            Projection->setObjectName(QStringLiteral("Projection"));
        Projection->resize(400, 300);
        groupBox = new QGroupBox(Projection);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 20, 120, 201));
        radioButton = new QRadioButton(groupBox);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setGeometry(QRect(10, 30, 95, 20));
        radioButton_2 = new QRadioButton(groupBox);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
        radioButton_2->setGeometry(QRect(10, 70, 95, 20));
        groupBox_2 = new QGroupBox(Projection);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(180, 10, 171, 221));
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

        retranslateUi(Projection);
        QObject::connect(checkBox_6, SIGNAL(toggled(bool)), checkBox_5, SLOT(setChecked(bool)));
        QObject::connect(checkBox_6, SIGNAL(toggled(bool)), checkBox_4, SLOT(setChecked(bool)));
        QObject::connect(checkBox_6, SIGNAL(toggled(bool)), checkBox_3, SLOT(setChecked(bool)));
        QObject::connect(checkBox_6, SIGNAL(toggled(bool)), checkBox_2, SLOT(setChecked(bool)));
        QObject::connect(checkBox_6, SIGNAL(toggled(bool)), checkBox, SLOT(setChecked(bool)));

        QMetaObject::connectSlotsByName(Projection);
    } // setupUi

    void retranslateUi(QDialog *Projection)
    {
        Projection->setWindowTitle(QApplication::translate("Projection", "Dialog", nullptr));
        groupBox->setTitle(QApplication::translate("Projection", "VIEW MODE", nullptr));
        radioButton->setText(QApplication::translate("Projection", "3D VIEW", nullptr));
        radioButton_2->setText(QApplication::translate("Projection", "2D VIEW", nullptr));
        groupBox_2->setTitle(QApplication::translate("Projection", "PROJECTION", nullptr));
        checkBox->setText(QApplication::translate("Projection", "PROJECTION 1", nullptr));
        checkBox_2->setText(QApplication::translate("Projection", "PROJECTION 2", nullptr));
        checkBox_5->setText(QApplication::translate("Projection", "PROJECTION 5", nullptr));
        checkBox_3->setText(QApplication::translate("Projection", "PROJECTION 3", nullptr));
        checkBox_4->setText(QApplication::translate("Projection", "PROJECTION 4", nullptr));
        checkBox_6->setText(QApplication::translate("Projection", "ALL PROJECTIONS", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Projection: public Ui_Projection {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROJ_H
