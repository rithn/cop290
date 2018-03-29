/********************************************************************************
** Form generated from reading UI file 'reconstruction.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECONSTRUCTION_H
#define UI_RECONSTRUCTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_Reconstruction
{
public:

    void setupUi(QDialog *Reconstruction)
    {
        if (Reconstruction->objectName().isEmpty())
            Reconstruction->setObjectName(QStringLiteral("Reconstruction"));
        Reconstruction->resize(400, 300);

        retranslateUi(Reconstruction);

        QMetaObject::connectSlotsByName(Reconstruction);
    } // setupUi

    void retranslateUi(QDialog *Reconstruction)
    {
        Reconstruction->setWindowTitle(QApplication::translate("Reconstruction", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Reconstruction: public Ui_Reconstruction {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECONSTRUCTION_H
