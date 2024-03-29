/********************************************************************************
** Form generated from reading UI file 'adminlogin.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINLOGIN_H
#define UI_ADMINLOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdminLogin
{
public:
    QWidget *widget;
    QPushButton *LoginButton;
    QWidget *widget1;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QPushButton *backButton;
    QLabel *label;

    void setupUi(QDialog *AdminLogin)
    {
        if (AdminLogin->objectName().isEmpty())
            AdminLogin->setObjectName("AdminLogin");
        AdminLogin->resize(869, 633);
        widget = new QWidget(AdminLogin);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(250, 100, 301, 331));
        LoginButton = new QPushButton(widget);
        LoginButton->setObjectName("LoginButton");
        LoginButton->setGeometry(QRect(100, 280, 80, 24));
        widget1 = new QWidget(widget);
        widget1->setObjectName("widget1");
        widget1->setGeometry(QRect(60, 30, 181, 221));
        verticalLayout = new QVBoxLayout(widget1);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        lineEdit = new QLineEdit(widget1);
        lineEdit->setObjectName("lineEdit");

        verticalLayout->addWidget(lineEdit);

        lineEdit_2 = new QLineEdit(widget1);
        lineEdit_2->setObjectName("lineEdit_2");

        verticalLayout->addWidget(lineEdit_2);

        lineEdit_3 = new QLineEdit(widget1);
        lineEdit_3->setObjectName("lineEdit_3");

        verticalLayout->addWidget(lineEdit_3);

        lineEdit_4 = new QLineEdit(widget1);
        lineEdit_4->setObjectName("lineEdit_4");

        verticalLayout->addWidget(lineEdit_4);

        backButton = new QPushButton(AdminLogin);
        backButton->setObjectName("backButton");
        backButton->setGeometry(QRect(60, 80, 80, 24));
        label = new QLabel(AdminLogin);
        label->setObjectName("label");
        label->setGeometry(QRect(220, 30, 381, 71));
        QFont font;
        font.setFamilies({QString::fromUtf8("Sitka")});
        font.setPointSize(28);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #FFFFFF; /* Schimb\304\203m culoarea textului \303\256n #063263 */\n"
"}"));
        label->setAlignment(Qt::AlignCenter);

        retranslateUi(AdminLogin);

        QMetaObject::connectSlotsByName(AdminLogin);
    } // setupUi

    void retranslateUi(QDialog *AdminLogin)
    {
        AdminLogin->setWindowTitle(QCoreApplication::translate("AdminLogin", "Dialog", nullptr));
        LoginButton->setText(QCoreApplication::translate("AdminLogin", "Login", nullptr));
        backButton->setText(QCoreApplication::translate("AdminLogin", "Back", nullptr));
        label->setText(QCoreApplication::translate("AdminLogin", "Admin Login", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdminLogin: public Ui_AdminLogin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINLOGIN_H
