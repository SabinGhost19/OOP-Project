/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *exitButton;
    QLineEdit *lineEdit;
    QFrame *frame;
    QLabel *label_facebook;
    QLabel *label_google;
    QLabel *label_yahoo;
    QLabel *label_Title;
    QLabel *label_subtitle;
    QLineEdit *lineEdit_2;
    QLabel *label_design;
    QLabel *label_titleright;
    QPushButton *SignInButton;
    QPushButton *LoginButton;
    QLabel *label_logo;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(869, 633);
        MainWindow->setStyleSheet(QString::fromUtf8("QMainWindow{\n"
"background-color:#9EFFD1\n"
"}"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        exitButton = new QPushButton(centralwidget);
        exitButton->setObjectName("exitButton");
        exitButton->setGeometry(QRect(490, 20, 91, 81));
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
        QIcon icon;
        icon.addFile(QString::fromUtf8("../../../../OneDrive/Desktop/exit3.png"), QSize(), QIcon::Normal, QIcon::Off);
        exitButton->setIcon(icon);
        exitButton->setIconSize(QSize(40, 40));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(170, 350, 211, 51));
        lineEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 2px solid #ccc;  /* Adaug\304\203 un contur de 2px solid cu o culoare gri deschis */\n"
"    border-radius: 5px;      /* Rotunjeste marginile */\n"
"    padding: 5px;            /* Adaug\304\203 un spa\310\233iu de 5px \303\256n interiorul lineEdit-ului */\n"
"    font-family: Arial, sans-serif; /* Seteaz\304\203 fontul textului */\n"
"    font-size: 14px;         /* Seteaz\304\203 dimensiunea fontului */\n"
"    color: #333;             /* Seteaz\304\203 culoarea textului la un gri mai \303\256nchis */\n"
"}\n"
"\n"
"QLineEdit:hover {\n"
"    border-color: #aaa;      /* Schimb\304\203 culoarea conturului la un gri mai deschis atunci c\303\242nd mouse-ul este deasupra */\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border-color: #0078d7;  /* Schimb\304\203 culoarea conturului la albastru atunci c\303\242nd lineEdit-ul are focus */\n"
"}"));
        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(130, 250, 291, 80));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label_facebook = new QLabel(frame);
        label_facebook->setObjectName("label_facebook");
        label_facebook->setGeometry(QRect(190, 20, 71, 61));
        label_facebook->setPixmap(QPixmap(QString::fromUtf8("../../../../OneDrive/Desktop/facebook.png")));
        label_facebook->setScaledContents(true);
        label_google = new QLabel(frame);
        label_google->setObjectName("label_google");
        label_google->setGeometry(QRect(110, 30, 61, 51));
        label_google->setPixmap(QPixmap(QString::fromUtf8("../../../../OneDrive/Desktop/google.png")));
        label_google->setScaledContents(true);
        label_yahoo = new QLabel(frame);
        label_yahoo->setObjectName("label_yahoo");
        label_yahoo->setGeometry(QRect(20, 30, 61, 51));
        label_yahoo->setPixmap(QPixmap(QString::fromUtf8("../../../../OneDrive/Desktop/yahoo.png")));
        label_yahoo->setScaledContents(true);
        label_yahoo->setOpenExternalLinks(true);
        label_Title = new QLabel(centralwidget);
        label_Title->setObjectName("label_Title");
        label_Title->setGeometry(QRect(-10, 140, 541, 71));
        QFont font;
        font.setPointSize(36);
        label_Title->setFont(font);
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
        label_subtitle->setGeometry(QRect(80, 210, 381, 41));
        QFont font1;
        font1.setPointSize(20);
        label_subtitle->setFont(font1);
        label_subtitle->setAlignment(Qt::AlignCenter);
        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(170, 420, 211, 51));
        lineEdit_2->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 2px solid #ccc;  /* Adaug\304\203 un contur de 2px solid cu o culoare gri deschis */\n"
"    border-radius: 5px;      /* Rotunjeste marginile */\n"
"    padding: 5px;            /* Adaug\304\203 un spa\310\233iu de 5px \303\256n interiorul lineEdit-ului */\n"
"    font-family: Arial, sans-serif; /* Seteaz\304\203 fontul textului */\n"
"    font-size: 14px;         /* Seteaz\304\203 dimensiunea fontului */\n"
"    color: #333;             /* Seteaz\304\203 culoarea textului la un gri mai \303\256nchis */\n"
"}\n"
"\n"
"QLineEdit:hover {\n"
"    border-color: #aaa;      /* Schimb\304\203 culoarea conturului la un gri mai deschis atunci c\303\242nd mouse-ul este deasupra */\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border-color: #0078d7;  /* Schimb\304\203 culoarea conturului la albastru atunci c\303\242nd lineEdit-ul are focus */\n"
"}"));
        label_design = new QLabel(centralwidget);
        label_design->setObjectName("label_design");
        label_design->setGeometry(QRect(530, 0, 361, 631));
        label_design->setPixmap(QPixmap(QString::fromUtf8("../../../../OneDrive/Desktop/design.png")));
        label_design->setScaledContents(true);
        label_titleright = new QLabel(centralwidget);
        label_titleright->setObjectName("label_titleright");
        label_titleright->setGeometry(QRect(630, 230, 171, 71));
        label_titleright->setFont(font1);
        label_titleright->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: #063263; /* Culorile de fundal */\n"
"    border: 2px solid #C8F7FF; /* Chenarul cu grosimea specificat\304\203 \310\231i culoarea specificat\304\203 */\n"
"    color: #FFFFFF; /* Textul pe alb */\n"
"    padding: 10px; /* Spa\310\233ierea \303\256ntre con\310\233inut \310\231i chenar */\n"
"    border-radius: 5px; /* Rotunjirea col\310\233urilor */\n"
"    opacity: 0.8; /* Opacitatea pentru a face chenarul u\310\231or transparent */\n"
"}"));
        SignInButton = new QPushButton(centralwidget);
        SignInButton->setObjectName("SignInButton");
        SignInButton->setGeometry(QRect(640, 390, 161, 71));
        SignInButton->setAutoFillBackground(false);
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
        LoginButton = new QPushButton(centralwidget);
        LoginButton->setObjectName("LoginButton");
        LoginButton->setGeometry(QRect(200, 500, 161, 61));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("sans-serif")});
        LoginButton->setFont(font2);
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
        LoginButton->setFlat(false);
        label_logo = new QLabel(centralwidget);
        label_logo->setObjectName("label_logo");
        label_logo->setGeometry(QRect(50, 40, 131, 101));
        label_logo->setPixmap(QPixmap(QString::fromUtf8("../../../../OneDrive/Desktop/k.jpg")));
        label_logo->setScaledContents(true);
        MainWindow->setCentralWidget(centralwidget);
        label_design->raise();
        frame->raise();
        exitButton->raise();
        lineEdit->raise();
        label_Title->raise();
        label_subtitle->raise();
        lineEdit_2->raise();
        label_titleright->raise();
        SignInButton->raise();
        LoginButton->raise();
        label_logo->raise();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        exitButton->setText(QString());
        label_facebook->setText(QString());
        label_google->setText(QString());
        label_yahoo->setText(QString());
        label_Title->setText(QCoreApplication::translate("MainWindow", " Login to Your Account", nullptr));
        label_subtitle->setText(QCoreApplication::translate("MainWindow", "Login using social network", nullptr));
        label_design->setText(QString());
        label_titleright->setText(QCoreApplication::translate("MainWindow", "New here ?", nullptr));
        SignInButton->setText(QCoreApplication::translate("MainWindow", "Sign Up", nullptr));
        LoginButton->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
        label_logo->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
