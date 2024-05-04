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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ClientLogin
{
public:
    QPushButton *pushButton;
    QLabel *Title;
    QWidget *widget_2;
    QGridLayout *gridLayout;
    QLineEdit *Tara;
    QLineEdit *Judet;
    QLineEdit *Oras;
    QLineEdit *CodPostal;
    QLineEdit *Strada;
    QLineEdit *Numarul;
    QLineEdit *Scara;
    QLineEdit *NumarApartament;
    QPushButton *LoginButton;
    QLabel *Header_1;
    QLabel *Header_2;
    QLabel *Header_3;
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QLineEdit *Email;
    QLineEdit *Parola;
    QWidget *widget1;
    QGridLayout *gridLayout_3;
    QLineEdit *Nume;
    QLineEdit *Prenume;
    QLineEdit *Telefon;
    QLineEdit *DataNasterii;

    void setupUi(QDialog *ClientLogin)
    {
        if (ClientLogin->objectName().isEmpty())
            ClientLogin->setObjectName("ClientLogin");
        ClientLogin->resize(869, 633);
        ClientLogin->setStyleSheet(QString::fromUtf8("background-color:#8AD8FB;"));
        pushButton = new QPushButton(ClientLogin);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(30, 20, 91, 61));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        Title = new QLabel(ClientLogin);
        Title->setObjectName("Title");
        Title->setGeometry(QRect(230, 30, 381, 71));
        QFont font;
        font.setFamilies({QString::fromUtf8("Sitka")});
        font.setPointSize(28);
        Title->setFont(font);
        Title->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #FFFFFF; /* Schimb\304\203m culoarea textului \303\256n #063263 */\n"
"}"));
        Title->setAlignment(Qt::AlignCenter);
        widget_2 = new QWidget(ClientLogin);
        widget_2->setObjectName("widget_2");
        widget_2->setGeometry(QRect(540, 150, 240, 361));
        gridLayout = new QGridLayout(widget_2);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setVerticalSpacing(20);
        Tara = new QLineEdit(widget_2);
        Tara->setObjectName("Tara");
        Tara->setMinimumSize(QSize(200, 40));
        Tara->setMaximumSize(QSize(400, 80));

        gridLayout->addWidget(Tara, 0, 0, 1, 3);

        Judet = new QLineEdit(widget_2);
        Judet->setObjectName("Judet");
        Judet->setMinimumSize(QSize(200, 40));
        Judet->setMaximumSize(QSize(400, 80));

        gridLayout->addWidget(Judet, 1, 0, 1, 3);

        Oras = new QLineEdit(widget_2);
        Oras->setObjectName("Oras");
        Oras->setMinimumSize(QSize(200, 40));
        Oras->setMaximumSize(QSize(400, 80));

        gridLayout->addWidget(Oras, 2, 0, 1, 3);

        CodPostal = new QLineEdit(widget_2);
        CodPostal->setObjectName("CodPostal");
        CodPostal->setMinimumSize(QSize(200, 40));
        CodPostal->setMaximumSize(QSize(400, 80));

        gridLayout->addWidget(CodPostal, 3, 0, 1, 3);

        Strada = new QLineEdit(widget_2);
        Strada->setObjectName("Strada");
        Strada->setMinimumSize(QSize(200, 40));
        Strada->setMaximumSize(QSize(400, 80));
        Strada->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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

        gridLayout->addWidget(Strada, 4, 0, 1, 3);

        Numarul = new QLineEdit(widget_2);
        Numarul->setObjectName("Numarul");
        Numarul->setMinimumSize(QSize(60, 30));
        Numarul->setMaximumSize(QSize(70, 34));

        gridLayout->addWidget(Numarul, 5, 0, 1, 1);

        Scara = new QLineEdit(widget_2);
        Scara->setObjectName("Scara");
        Scara->setMinimumSize(QSize(60, 30));
        Scara->setMaximumSize(QSize(70, 34));

        gridLayout->addWidget(Scara, 5, 1, 1, 1);

        NumarApartament = new QLineEdit(widget_2);
        NumarApartament->setObjectName("NumarApartament");
        NumarApartament->setMinimumSize(QSize(60, 30));
        NumarApartament->setMaximumSize(QSize(70, 34));

        gridLayout->addWidget(NumarApartament, 5, 2, 1, 1);

        LoginButton = new QPushButton(ClientLogin);
        LoginButton->setObjectName("LoginButton");
        LoginButton->setGeometry(QRect(310, 520, 141, 61));
        LoginButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        Header_1 = new QLabel(ClientLogin);
        Header_1->setObjectName("Header_1");
        Header_1->setGeometry(QRect(60, 110, 111, 51));
        Header_2 = new QLabel(ClientLogin);
        Header_2->setObjectName("Header_2");
        Header_2->setGeometry(QRect(310, 120, 81, 41));
        Header_3 = new QLabel(ClientLogin);
        Header_3->setObjectName("Header_3");
        Header_3->setGeometry(QRect(620, 90, 81, 41));
        widget = new QWidget(ClientLogin);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(10, 190, 211, 151));
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        Email = new QLineEdit(widget);
        Email->setObjectName("Email");
        Email->setMinimumSize(QSize(200, 30));
        Email->setMaximumSize(QSize(380, 40));
        Email->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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

        gridLayout_2->addWidget(Email, 0, 0, 1, 1);

        Parola = new QLineEdit(widget);
        Parola->setObjectName("Parola");
        Parola->setMinimumSize(QSize(200, 30));
        Parola->setMaximumSize(QSize(380, 40));
        Parola->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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

        gridLayout_2->addWidget(Parola, 1, 0, 1, 1);

        widget1 = new QWidget(ClientLogin);
        widget1->setObjectName("widget1");
        widget1->setGeometry(QRect(270, 160, 202, 271));
        gridLayout_3 = new QGridLayout(widget1);
        gridLayout_3->setObjectName("gridLayout_3");
        gridLayout_3->setVerticalSpacing(20);
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        Nume = new QLineEdit(widget1);
        Nume->setObjectName("Nume");
        Nume->setMinimumSize(QSize(200, 40));
        Nume->setMaximumSize(QSize(400, 60));

        gridLayout_3->addWidget(Nume, 0, 0, 1, 1);

        Prenume = new QLineEdit(widget1);
        Prenume->setObjectName("Prenume");
        Prenume->setMinimumSize(QSize(200, 40));
        Prenume->setMaximumSize(QSize(400, 60));

        gridLayout_3->addWidget(Prenume, 1, 0, 1, 1);

        Telefon = new QLineEdit(widget1);
        Telefon->setObjectName("Telefon");
        Telefon->setMinimumSize(QSize(200, 40));
        Telefon->setMaximumSize(QSize(400, 60));

        gridLayout_3->addWidget(Telefon, 2, 0, 1, 1);

        DataNasterii = new QLineEdit(widget1);
        DataNasterii->setObjectName("DataNasterii");
        DataNasterii->setMinimumSize(QSize(200, 40));
        DataNasterii->setMaximumSize(QSize(400, 60));

        gridLayout_3->addWidget(DataNasterii, 3, 0, 1, 1);


        retranslateUi(ClientLogin);

        QMetaObject::connectSlotsByName(ClientLogin);
    } // setupUi

    void retranslateUi(QDialog *ClientLogin)
    {
        ClientLogin->setWindowTitle(QCoreApplication::translate("ClientLogin", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("ClientLogin", "Back", nullptr));
        Title->setText(QCoreApplication::translate("ClientLogin", "Client Login", nullptr));
        LoginButton->setText(QCoreApplication::translate("ClientLogin", "LogIn", nullptr));
        Header_1->setText(QCoreApplication::translate("ClientLogin", "Account Data", nullptr));
        Header_2->setText(QCoreApplication::translate("ClientLogin", "Personal Data", nullptr));
        Header_3->setText(QCoreApplication::translate("ClientLogin", "Adress Infos", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ClientLogin: public Ui_ClientLogin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTLOGIN_H
