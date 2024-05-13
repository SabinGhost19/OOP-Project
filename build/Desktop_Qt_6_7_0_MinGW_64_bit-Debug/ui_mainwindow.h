/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QPushButton *LoginButton;
    QPushButton *SignInButton;
    QLabel *label_design;
    QLabel *label_logo;
    QPushButton *exitButton;
    QLabel *label_logo_2;
    QLabel *label_Title;
    QLabel *label_subtitle;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1149, 722);
        MainWindow->setStyleSheet(QString::fromUtf8("QMainWindow{\n"
"background-color:#9EFFD1\n"
"}"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(200, 380, 271, 71));
        lineEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 2px solid #0078d7;  /* Adaug\304\203 un contur de 2px solid cu culoarea albastr\304\203 */\n"
"    border-radius: 5px;          /* Rotunjeste marginile */\n"
"    padding: 5px;                /* Adaug\304\203 un spa\310\233iu de 5px \303\256n interiorul lineEdit-ului */\n"
"    font-family: Arial, sans-serif; /* Seteaz\304\203 fontul textului */\n"
"    font-size: 14px;             /* Seteaz\304\203 dimensiunea fontului */\n"
"    color: #333;                 /* Seteaz\304\203 culoarea textului la un gri mai \303\256nchis */\n"
"    background-color: #cce6ff;   /* Seteaz\304\203 culoarea de fundal la albastru deschis */\n"
"}\n"
"\n"
"QLineEdit:hover {\n"
"    border-color: #aaa;          /* Schimb\304\203 culoarea conturului la un gri mai deschis atunci c\303\242nd mouse-ul este deasupra */\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border-color: #0078d7;      /* Schimb\304\203 culoarea conturului la albastru atunci c\303\242nd lineEdit-ul are focus */\n"
"}"));
        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(200, 480, 271, 71));
        lineEdit_2->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 2px solid #0078d7;  /* Adaug\304\203 un contur de 2px solid cu culoarea albastr\304\203 */\n"
"    border-radius: 5px;          /* Rotunjeste marginile */\n"
"    padding: 5px;                /* Adaug\304\203 un spa\310\233iu de 5px \303\256n interiorul lineEdit-ului */\n"
"    font-family: Arial, sans-serif; /* Seteaz\304\203 fontul textului */\n"
"    font-size: 14px;             /* Seteaz\304\203 dimensiunea fontului */\n"
"    color: #333;                 /* Seteaz\304\203 culoarea textului la un gri mai \303\256nchis */\n"
"    background-color: #cce6ff;   /* Seteaz\304\203 culoarea de fundal la albastru deschis */\n"
"}\n"
"\n"
"QLineEdit:hover {\n"
"    border-color: #aaa;          /* Schimb\304\203 culoarea conturului la un gri mai deschis atunci c\303\242nd mouse-ul este deasupra */\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border-color: #0078d7;      /* Schimb\304\203 culoarea conturului la albastru atunci c\303\242nd lineEdit-ul are focus */\n"
"}"));
        LoginButton = new QPushButton(centralwidget);
        LoginButton->setObjectName("LoginButton");
        LoginButton->setGeometry(QRect(260, 570, 141, 61));
        LoginButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"  font-family: sans-serif;\n"
"  font-size: 20px;\n"
"  color: #fff;\n"
"  background-color: #007bff;\n"
"  padding: 12px 24px;\n"
"  border: none;\n"
"  border-radius: 30px;\n"
"  cursor: pointer;\n"
"  transition: background-color 0.3s ease;\n"
"}\n"
"QPushButton:hover {\n"
"  background-color: #0056b3;\n"
"}\n"
""));
        SignInButton = new QPushButton(centralwidget);
        SignInButton->setObjectName("SignInButton");
        SignInButton->setGeometry(QRect(850, 410, 161, 71));
        QFont font;
        font.setFamilies({QString::fromUtf8("sans-serif")});
        SignInButton->setFont(font);
        SignInButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        label_design = new QLabel(centralwidget);
        label_design->setObjectName("label_design");
        label_design->setGeometry(QRect(690, -20, 471, 711));
        label_design->setPixmap(QPixmap(QString::fromUtf8("img/design.png")));
        label_design->setScaledContents(true);
        label_logo = new QLabel(centralwidget);
        label_logo->setObjectName("label_logo");
        label_logo->setGeometry(QRect(220, 0, 231, 211));
        label_logo->setPixmap(QPixmap(QString::fromUtf8("img/Logo.png")));
        label_logo->setScaledContents(true);
        exitButton = new QPushButton(centralwidget);
        exitButton->setObjectName("exitButton");
        exitButton->setGeometry(QRect(640, 20, 101, 81));
        exitButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"  font-family: Arial, sans-serif;\n"
"  font-size: 16px;\n"
"  color: #fff;\n"
"  background-color: #9EFFD1;\n"
"  padding: 12px 24px;\n"
"  border: none;\n"
"  border-radius: 40px;\n"
"  cursor: pointer;\n"
"  transition: background-color 0.3s ease;\n"
"}\n"
"QPushButton:hover {\n"
"  background-color: #7ECCA7;\n"
"}\n"
""));
        label_logo_2 = new QLabel(centralwidget);
        label_logo_2->setObjectName("label_logo_2");
        label_logo_2->setGeometry(QRect(840, 250, 191, 81));
        QFont font1;
        font1.setPointSize(24);
        label_logo_2->setFont(font1);
        label_logo_2->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: #063263; /* Culorile de fundal */\n"
"    border: 2px solid #C8F7FF; /* Chenarul cu grosimea specificat\304\203 \310\231i culoarea specificat\304\203 */\n"
"    color: #FFFFFF; /* Textul pe alb */\n"
"    padding: 10px; /* Spa\310\233ierea \303\256ntre con\310\233inut \310\231i chenar */\n"
"    border-radius: 5px; /* Rotunjirea col\310\233urilor */\n"
"    opacity: 0.8; /* Opacitatea pentru a face chenarul u\310\231or transparent */\n"
"}"));
        label_logo_2->setAlignment(Qt::AlignCenter);
        label_Title = new QLabel(centralwidget);
        label_Title->setObjectName("label_Title");
        label_Title->setGeometry(QRect(70, 220, 541, 71));
        QFont font2;
        font2.setPointSize(36);
        label_Title->setFont(font2);
        label_Title->setStyleSheet(QString::fromUtf8("QLabel{\n"
"    font-family: \"Segoe UI\",  /* Tahoma, Geneva, Verdana, sans-serif;Schimba\310\233i fontul la alegere */\n"
"    font-size: 48px; /* Ajusta\310\233i dimensiunea fontului */\n"
"    color: #333; /* Alege\310\233i o culoare potrivit\304\203 */\n"
"    text-align: center; /* Alinierea textului la centru */\n"
"    text-transform: uppercase; /* Converti\310\233i textul \303\256n majuscule */\n"
"    letter-spacing: 2px; /* Spa\310\233iere \303\256ntre litere */\n"
"    margin-top: 50px; /* Spa\310\233ierea superioar\304\203 */\n"
"    margin-bottom: 20px; /* Spa\310\233ierea inferioar\304\203 */\n"
"}"));
        label_Title->setAlignment(Qt::AlignCenter);
        label_subtitle = new QLabel(centralwidget);
        label_subtitle->setObjectName("label_subtitle");
        label_subtitle->setGeometry(QRect(140, 300, 381, 41));
        QFont font3;
        font3.setPointSize(20);
        label_subtitle->setFont(font3);
        label_subtitle->setAlignment(Qt::AlignCenter);
        MainWindow->setCentralWidget(centralwidget);
        label_design->raise();
        lineEdit->raise();
        lineEdit_2->raise();
        LoginButton->raise();
        SignInButton->raise();
        label_logo->raise();
        exitButton->raise();
        label_logo_2->raise();
        label_Title->raise();
        label_subtitle->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1149, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        LoginButton->setText(QCoreApplication::translate("MainWindow", "LogIn", nullptr));
        SignInButton->setText(QCoreApplication::translate("MainWindow", "SignIn", nullptr));
        label_design->setText(QString());
        label_logo->setText(QString());
        exitButton->setText(QString());
        label_logo_2->setText(QCoreApplication::translate("MainWindow", "New Here ?", nullptr));
        label_Title->setText(QCoreApplication::translate("MainWindow", " Login to Your Account", nullptr));
        label_subtitle->setText(QCoreApplication::translate("MainWindow", "Login using any account", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
