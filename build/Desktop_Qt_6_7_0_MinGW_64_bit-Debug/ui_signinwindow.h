/********************************************************************************
** Form generated from reading UI file 'signinwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNINWINDOW_H
#define UI_SIGNINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_SignInWindow
{
public:
    QPushButton *CompanyButton;
    QPushButton *ClientButton;
    QLabel *label_circle;
    QPushButton *backButton;
    QLabel *label;
    QPushButton *CompanyButton_2;
    QPushButton *CompanyButton_3;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;

    void setupUi(QDialog *SignInWindow)
    {
        if (SignInWindow->objectName().isEmpty())
            SignInWindow->setObjectName("SignInWindow");
        SignInWindow->resize(1147, 743);
        SignInWindow->setStyleSheet(QString::fromUtf8("QDialog{\n"
"background-color:#9EFFD1\n"
"}\n"
""));
        CompanyButton = new QPushButton(SignInWindow);
        CompanyButton->setObjectName("CompanyButton");
        CompanyButton->setGeometry(QRect(698, 301, 201, 111));
        CompanyButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(240, 240, 240, 255), stop:1 rgba(255, 255, 255, 255));\n"
"    border: 1px solid rgba(200, 200, 200, 255); /* Bordura de culoare gri deschis */\n"
"    border-radius: 40px;\n"
"    padding: 5px 10px;\n"
"    font-size: 16px;\n"
"    color: rgb(100, 100, 100); /* Textul de culoare gri */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(220, 220, 220, 255), stop:1 rgba(255, 255, 255, 255));\n"
"    border: 1px solid #9EFFD; /* Schimb\304\203m culoarea marginii la hover la #9EFFD */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(200, 200, 200, 255), stop:1 rgba(240, 240, 240, 255));\n"
"}\n"
""));
        ClientButton = new QPushButton(SignInWindow);
        ClientButton->setObjectName("ClientButton");
        ClientButton->setGeometry(QRect(700, 460, 201, 111));
        ClientButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(240, 240, 240, 255), stop:1 rgba(255, 255, 255, 255));\n"
"    border: 1px solid rgba(200, 200, 200, 255); /* Bordura de culoare gri deschis */\n"
"    border-radius: 40px;\n"
"    padding: 5px 10px;\n"
"    font-size: 16px;\n"
"    color: rgb(100, 100, 100); /* Textul de culoare gri */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(220, 220, 220, 255), stop:1 rgba(255, 255, 255, 255));\n"
"    border: 1px solid #9EFFD; /* Schimb\304\203m culoarea marginii la hover la #9EFFD */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(200, 200, 200, 255), stop:1 rgba(240, 240, 240, 255));\n"
"}\n"
""));
        label_circle = new QLabel(SignInWindow);
        label_circle->setObjectName("label_circle");
        label_circle->setGeometry(QRect(-240, 120, 681, 661));
        label_circle->setPixmap(QPixmap(QString::fromUtf8("img/circle.png")));
        label_circle->setScaledContents(true);
        backButton = new QPushButton(SignInWindow);
        backButton->setObjectName("backButton");
        backButton->setGeometry(QRect(130, 30, 151, 71));
        backButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font-family: sans-serif;\n"
"    font-size: 20px;\n"
"    color: #fff;\n"
"    background-color: #6188FF;\n"
"    padding: 12px 24px;\n"
"    border: 2px solid #063263; /* Ad\304\203uga\310\233i contur cu grosimea \310\231i culoarea specificat\304\203 */\n"
"    border-radius: 30px;\n"
"    cursor: pointer;\n"
"    transition: background-color 0.3s ease;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #0056b3;\n"
"}\n"
"/* Stil pentru butoanele QPushButton */\n"
"\n"
"\n"
""));
        label = new QLabel(SignInWindow);
        label->setObjectName("label");
        label->setGeometry(QRect(100, 230, 49, 16));
        CompanyButton_2 = new QPushButton(SignInWindow);
        CompanyButton_2->setObjectName("CompanyButton_2");
        CompanyButton_2->setGeometry(QRect(690, 301, 201, 121));
        CompanyButton_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(138, 255, 60);\n"
"	background-color: rgb(158, 255, 129);\n"
"    border-radius: 40px;\n"
"}\n"
"\n"
"\n"
""));
        CompanyButton_3 = new QPushButton(SignInWindow);
        CompanyButton_3->setObjectName("CompanyButton_3");
        CompanyButton_3->setGeometry(QRect(690, 460, 201, 121));
        CompanyButton_3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(138, 255, 60);\n"
"	background-color: rgb(158, 255, 129);\n"
"    border-radius: 40px;\n"
"}\n"
"\n"
"\n"
""));
        label_2 = new QLabel(SignInWindow);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 430, 301, 71));
        QFont font;
        font.setFamilies({QString::fromUtf8("Segoe UI Variable Text Semibold")});
        font.setPointSize(30);
        font.setBold(true);
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(SignInWindow);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(30, 450, 401, 141));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Segoe UI Variable Text Semibold")});
        font1.setPointSize(39);
        font1.setBold(true);
        label_3->setFont(font1);
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(159, 159, 159);"));
        label_3->setAlignment(Qt::AlignCenter);
        label_4 = new QLabel(SignInWindow);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(0, 160, 271, 231));
        label_4->setPixmap(QPixmap(QString::fromUtf8("img/Logo.png")));
        label_4->setScaledContents(true);
        label_5 = new QLabel(SignInWindow);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(510, 60, 621, 91));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Sitka Subheading Semibold")});
        font2.setPointSize(37);
        font2.setBold(true);
        label_5->setFont(font2);
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(115, 169, 255);"));
        label_5->setAlignment(Qt::AlignCenter);
        label_6 = new QLabel(SignInWindow);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(620, 110, 431, 121));
        QFont font3;
        font3.setPointSize(27);
        font3.setBold(true);
        label_6->setFont(font3);
        label_6->setStyleSheet(QString::fromUtf8("color: rgb(92, 176, 255);"));
        label_6->setAlignment(Qt::AlignCenter);
        CompanyButton_3->raise();
        CompanyButton_2->raise();
        CompanyButton->raise();
        ClientButton->raise();
        label_circle->raise();
        backButton->raise();
        label->raise();
        label_2->raise();
        label_3->raise();
        label_4->raise();
        label_5->raise();
        label_6->raise();

        retranslateUi(SignInWindow);

        QMetaObject::connectSlotsByName(SignInWindow);
    } // setupUi

    void retranslateUi(QDialog *SignInWindow)
    {
        SignInWindow->setWindowTitle(QCoreApplication::translate("SignInWindow", "Dialog", nullptr));
        CompanyButton->setText(QCoreApplication::translate("SignInWindow", "Company", nullptr));
        ClientButton->setText(QCoreApplication::translate("SignInWindow", "Client", nullptr));
        label_circle->setText(QString());
        backButton->setText(QCoreApplication::translate("SignInWindow", "Back", nullptr));
        label->setText(QString());
        CompanyButton_2->setText(QCoreApplication::translate("SignInWindow", "Company", nullptr));
        CompanyButton_3->setText(QCoreApplication::translate("SignInWindow", "Company", nullptr));
        label_2->setText(QCoreApplication::translate("SignInWindow", "Welcome to the", nullptr));
        label_3->setText(QCoreApplication::translate("SignInWindow", "Marketplace", nullptr));
        label_4->setText(QString());
        label_5->setText(QCoreApplication::translate("SignInWindow", "SignIn below to get started", nullptr));
        label_6->setText(QCoreApplication::translate("SignInWindow", "Select the type of service", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SignInWindow: public Ui_SignInWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNINWINDOW_H
