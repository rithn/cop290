/********************************************************************************
** Form generated from reading UI file 'solid_display.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SOLID_DISPLAY_H
#define UI_SOLID_DISPLAY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_Solid_display
{
public:

    void setupUi(QDialog *Solid_display)
    {
        if (Solid_display->objectName().isEmpty())
            Solid_display->setObjectName(QStringLiteral("Solid_display"));
        Solid_display->resize(400, 300);

        retranslateUi(Solid_display);

        QMetaObject::connectSlotsByName(Solid_display);
    } // setupUi

    void retranslateUi(QDialog *Solid_display)
    {
        Solid_display->setWindowTitle(QApplication::translate("Solid_display", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Solid_display: public Ui_Solid_display {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SOLID_DISPLAY_H
