/********************************************************************************
** Form generated from reading UI file 'companylogin.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMPANYLOGIN_H
#define UI_COMPANYLOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CompanyLogin
{
public:
    QPushButton *backButton;
    QWidget *widget;
    QPushButton *LoginButton;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLabel *label;

    void setupUi(QDialog *CompanyLogin)
    {
        if (CompanyLogin->objectName().isEmpty())
            CompanyLogin->setObjectName("CompanyLogin");
        CompanyLogin->resize(869, 633);
        backButton = new QPushButton(CompanyLogin);
        backButton->setObjectName("backButton");
        backButton->setGeometry(QRect(90, 140, 80, 24));
        widget = new QWidget(CompanyLogin);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(280, 160, 301, 331));
        LoginButton = new QPushButton(widget);
        LoginButton->setObjectName("LoginButton");
        LoginButton->setGeometry(QRect(100, 280, 80, 24));
        layoutWidget = new QWidget(widget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(60, 30, 181, 221));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        lineEdit = new QLineEdit(layoutWidget);
        lineEdit->setObjectName("lineEdit");

        verticalLayout->addWidget(lineEdit);

        lineEdit_2 = new QLineEdit(layoutWidget);
        lineEdit_2->setObjectName("lineEdit_2");

        verticalLayout->addWidget(lineEdit_2);

        lineEdit_3 = new QLineEdit(layoutWidget);
        lineEdit_3->setObjectName("lineEdit_3");

        verticalLayout->addWidget(lineEdit_3);

        lineEdit_4 = new QLineEdit(layoutWidget);
        lineEdit_4->setObjectName("lineEdit_4");

        verticalLayout->addWidget(lineEdit_4);

        label = new QLabel(CompanyLogin);
        label->setObjectName("label");
        label->setGeometry(QRect(250, 50, 381, 71));
        QFont font;
        font.setFamilies({QString::fromUtf8("Sitka")});
        font.setPointSize(28);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #FFFFFF; /* Schimb\304\203m culoarea textului \303\256n #063263 */\n"
"}"));
        label->setAlignment(Qt::AlignCenter);

        retranslateUi(CompanyLogin);

        QMetaObject::connectSlotsByName(CompanyLogin);
    } // setupUi

    void retranslateUi(QDialog *CompanyLogin)
    {
        CompanyLogin->setWindowTitle(QCoreApplication::translate("CompanyLogin", "Dialog", nullptr));
        backButton->setText(QCoreApplication::translate("CompanyLogin", "Back", nullptr));
        LoginButton->setText(QCoreApplication::translate("CompanyLogin", "Login", nullptr));
        label->setText(QCoreApplication::translate("CompanyLogin", "Company Login", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CompanyLogin: public Ui_CompanyLogin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMPANYLOGIN_H
