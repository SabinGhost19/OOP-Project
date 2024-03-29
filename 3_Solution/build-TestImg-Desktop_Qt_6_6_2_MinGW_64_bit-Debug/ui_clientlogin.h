/********************************************************************************
** Form generated from reading UI file 'clientlogin.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENTLOGIN_H
#define UI_CLIENTLOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ClientLogin
{
public:
    QPushButton *pushButton;
    QWidget *widget;
    QPushButton *LoginButton;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLabel *label;

    void setupUi(QDialog *ClientLogin)
    {
        if (ClientLogin->objectName().isEmpty())
            ClientLogin->setObjectName("ClientLogin");
        ClientLogin->resize(869, 633);
        pushButton = new QPushButton(ClientLogin);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(70, 100, 80, 24));
        widget = new QWidget(ClientLogin);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(260, 120, 301, 331));
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

        label = new QLabel(ClientLogin);
        label->setObjectName("label");
        label->setGeometry(QRect(220, 40, 381, 71));
        QFont font;
        font.setFamilies({QString::fromUtf8("Sitka")});
        font.setPointSize(28);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #FFFFFF; /* Schimb\304\203m culoarea textului \303\256n #063263 */\n"
"}"));
        label->setAlignment(Qt::AlignCenter);

        retranslateUi(ClientLogin);

        QMetaObject::connectSlotsByName(ClientLogin);
    } // setupUi

    void retranslateUi(QDialog *ClientLogin)
    {
        ClientLogin->setWindowTitle(QCoreApplication::translate("ClientLogin", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("ClientLogin", "Back", nullptr));
        LoginButton->setText(QCoreApplication::translate("ClientLogin", "Login", nullptr));
        label->setText(QCoreApplication::translate("ClientLogin", "Client Login", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ClientLogin: public Ui_ClientLogin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTLOGIN_H
