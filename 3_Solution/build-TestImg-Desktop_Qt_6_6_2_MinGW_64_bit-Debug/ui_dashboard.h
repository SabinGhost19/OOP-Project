/********************************************************************************
** Form generated from reading UI file 'dashboard.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DASHBOARD_H
#define UI_DASHBOARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_DashBoard
{
public:

    void setupUi(QDialog *DashBoard)
    {
        if (DashBoard->objectName().isEmpty())
            DashBoard->setObjectName("DashBoard");
        DashBoard->resize(869, 633);

        retranslateUi(DashBoard);

        QMetaObject::connectSlotsByName(DashBoard);
    } // setupUi

    void retranslateUi(QDialog *DashBoard)
    {
        DashBoard->setWindowTitle(QCoreApplication::translate("DashBoard", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DashBoard: public Ui_DashBoard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DASHBOARD_H
