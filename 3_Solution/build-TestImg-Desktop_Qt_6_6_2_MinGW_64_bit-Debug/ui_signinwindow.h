/********************************************************************************
** Form generated from reading UI file 'signinwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNINWINDOW_H
#define UI_SIGNINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_SignInWindow
{
public:
    QLabel *label_circle;
    QPushButton *ClientButton;
    QLabel *label;
    QLabel *label_3;
    QPushButton *AdminButton;
    QPushButton *CompanyButton;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QPushButton *backButton;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;

    void setupUi(QDialog *SignInWindow)
    {
        if (SignInWindow->objectName().isEmpty())
            SignInWindow->setObjectName("SignInWindow");
        SignInWindow->resize(869, 633);
        QFont font;
        font.setPointSize(8);
        SignInWindow->setFont(font);
        SignInWindow->setStyleSheet(QString::fromUtf8("QDialog{\n"
"background-color:#9EFFD1\n"
"}\n"
"\n"
""));
        label_circle = new QLabel(SignInWindow);
        label_circle->setObjectName("label_circle");
        label_circle->setGeometry(QRect(-270, -30, 701, 681));
        label_circle->setStyleSheet(QString::fromUtf8("SignInWindow{\n"
"background-color:#9EFFD1\n"
"}"));
        label_circle->setPixmap(QPixmap(QString::fromUtf8("../../../../../../OneDrive/Desktop/elipsefinal.png")));
        label_circle->setScaledContents(true);
        ClientButton = new QPushButton(SignInWindow);
        ClientButton->setObjectName("ClientButton");
        ClientButton->setGeometry(QRect(460, 310, 171, 81));
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
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(200, 200, 200, 255), stop:1 rgba(240, 240, 240, 255));\n"
"}\n"
"\n"
""));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../../../../../../Downloads/shop.png"), QSize(), QIcon::Normal, QIcon::Off);
        ClientButton->setIcon(icon);
        ClientButton->setIconSize(QSize(50, 50));
        label = new QLabel(SignInWindow);
        label->setObjectName("label");
        label->setGeometry(QRect(-30, 200, 381, 71));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Sitka")});
        font1.setPointSize(28);
        label->setFont(font1);
        label->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #FFFFFF; /* Schimb\304\203m culoarea textului \303\256n #063263 */\n"
"}"));
        label->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(SignInWindow);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(-20, 260, 381, 71));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Sitka")});
        font2.setPointSize(24);
        label_3->setFont(font2);
        label_3->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #E3E3E3; /* Schimb\304\203m culoarea textului \303\256n #063263 */\n"
"}"));
        label_3->setAlignment(Qt::AlignCenter);
        AdminButton = new QPushButton(SignInWindow);
        AdminButton->setObjectName("AdminButton");
        AdminButton->setGeometry(QRect(460, 450, 171, 81));
        AdminButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(200, 200, 200, 255), stop:1 rgba(240, 240, 240, 255));\n"
"}\n"
"\n"
""));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("../../../../../../Downloads/admin.png"), QSize(), QIcon::Normal, QIcon::Off);
        AdminButton->setIcon(icon1);
        AdminButton->setIconSize(QSize(50, 50));
        CompanyButton = new QPushButton(SignInWindow);
        CompanyButton->setObjectName("CompanyButton");
        CompanyButton->setGeometry(QRect(460, 180, 171, 81));
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
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("../../../../../../Downloads/box.png"), QSize(), QIcon::Normal, QIcon::Off);
        CompanyButton->setIcon(icon2);
        CompanyButton->setIconSize(QSize(50, 50));
        label_4 = new QLabel(SignInWindow);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(360, 20, 471, 71));
        label_4->setFont(font2);
        label_4->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #063263; /* Schimb\304\203m culoarea textului \303\256n #063263 */\n"
"}\n"
""));
        label_4->setAlignment(Qt::AlignCenter);
        label_5 = new QLabel(SignInWindow);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(460, 90, 361, 61));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Sitka")});
        font3.setPointSize(18);
        label_5->setFont(font3);
        label_5->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #083F7D; /* Schimb\304\203m culoarea textului \303\256n #063263 */\n"
"}\n"
""));
        label_5->setAlignment(Qt::AlignCenter);
        label_6 = new QLabel(SignInWindow);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(660, 200, 151, 31));
        label_6->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #063263; /* Schimb\304\203m culoarea textului \303\256n #063263 */\n"
"}\n"
""));
        label_7 = new QLabel(SignInWindow);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(660, 340, 151, 31));
        label_7->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #063263; /* Schimb\304\203m culoarea textului \303\256n #063263 */\n"
"}\n"
""));
        label_8 = new QLabel(SignInWindow);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(660, 470, 151, 31));
        label_8->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #063263; /* Schimb\304\203m culoarea textului \303\256n #063263 */\n"
"}\n"
""));
        backButton = new QPushButton(SignInWindow);
        backButton->setObjectName("backButton");
        backButton->setGeometry(QRect(70, 50, 80, 24));
        pushButton = new QPushButton(SignInWindow);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(454, 310, 176, 86));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color:#0AFB90;\n"
"    border: none; /* Bordura de culoare gri deschis */\n"
"    border-radius: 40px;\n"
"    padding: 5px 10px;\n"
"    font-size: 16px;\n"
"    color: rgb(100, 100, 100); /* Textul de culoare gri */\n"
"}\n"
"\n"
"\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(200, 200, 200, 255), stop:1 rgba(240, 240, 240, 255));\n"
"}\n"
""));
        pushButton_2 = new QPushButton(SignInWindow);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(454, 450, 176, 86));
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color:#0AFB90;\n"
"    border: none; /* Bordura de culoare gri deschis */\n"
"    border-radius: 40px;\n"
"    padding: 5px 10px;\n"
"    font-size: 16px;\n"
"    color: rgb(100, 100, 100); /* Textul de culoare gri */\n"
"}\n"
"\n"
"\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(200, 200, 200, 255), stop:1 rgba(240, 240, 240, 255));\n"
"}\n"
""));
        pushButton_3 = new QPushButton(SignInWindow);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(454, 180, 174, 86));
        pushButton_3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color:#0AFB90;\n"
"    border: none; /* Bordura de culoare gri deschis */\n"
"    border-radius: 40px;\n"
"    padding: 5px 10px;\n"
"    font-size: 16px;\n"
"    color: rgb(100, 100, 100); /* Textul de culoare gri */\n"
"}\n"
"\n"
"\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(200, 200, 200, 255), stop:1 rgba(240, 240, 240, 255));\n"
"}\n"
""));
        pushButton_2->raise();
        pushButton_3->raise();
        pushButton->raise();
        label_circle->raise();
        ClientButton->raise();
        label->raise();
        label_3->raise();
        AdminButton->raise();
        CompanyButton->raise();
        label_4->raise();
        label_5->raise();
        label_6->raise();
        label_7->raise();
        label_8->raise();
        backButton->raise();

        retranslateUi(SignInWindow);

        QMetaObject::connectSlotsByName(SignInWindow);
    } // setupUi

    void retranslateUi(QDialog *SignInWindow)
    {
        SignInWindow->setWindowTitle(QCoreApplication::translate("SignInWindow", "Dialog", nullptr));
        label_circle->setText(QString());
        ClientButton->setText(QCoreApplication::translate("SignInWindow", "   Client", nullptr));
        label->setText(QCoreApplication::translate("SignInWindow", "Welcome to the", nullptr));
        label_3->setText(QCoreApplication::translate("SignInWindow", "Marketplace", nullptr));
        AdminButton->setText(QCoreApplication::translate("SignInWindow", "   Admin", nullptr));
        CompanyButton->setText(QCoreApplication::translate("SignInWindow", "   Company", nullptr));
        label_4->setText(QCoreApplication::translate("SignInWindow", "Login below to get started", nullptr));
        label_5->setText(QCoreApplication::translate("SignInWindow", "Select the type of service", nullptr));
        label_6->setText(QCoreApplication::translate("SignInWindow", "Descirere scurta a profilui de companie", nullptr));
        label_7->setText(QCoreApplication::translate("SignInWindow", "Descirere scurta a profilui de companie", nullptr));
        label_8->setText(QCoreApplication::translate("SignInWindow", "Descirere scurta a profilui de companie", nullptr));
        backButton->setText(QCoreApplication::translate("SignInWindow", "Back", nullptr));
        pushButton->setText(QString());
        pushButton_2->setText(QString());
        pushButton_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SignInWindow: public Ui_SignInWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNINWINDOW_H
