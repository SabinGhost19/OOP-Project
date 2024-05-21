/********************************************************************************
** Form generated from reading UI file 'clientlogin.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENTLOGIN_H
#define UI_CLIENTLOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ClientLogin
{
public:
    QLineEdit *Email;
    QLineEdit *Parola;
    QLineEdit *Nume;
    QLineEdit *Prenume;
    QLineEdit *Telefon;
    QLineEdit *DataNasterii;
    QLineEdit *CodPostal;
    QLineEdit *Tara;
    QLineEdit *Judet;
    QLineEdit *Oras;
    QLineEdit *Strada;
    QLineEdit *Numarul;
    QPushButton *Back;
    QPushButton *LoginButton;
    QLineEdit *Scara;
    QLineEdit *NumarApartament;

    void setupUi(QDialog *ClientLogin)
    {
        if (ClientLogin->objectName().isEmpty())
            ClientLogin->setObjectName("ClientLogin");
        ClientLogin->resize(1200, 790);
        Email = new QLineEdit(ClientLogin);
        Email->setObjectName("Email");
        Email->setGeometry(QRect(40, 210, 191, 51));
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
        Parola = new QLineEdit(ClientLogin);
        Parola->setObjectName("Parola");
        Parola->setGeometry(QRect(40, 290, 191, 51));
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
        Nume = new QLineEdit(ClientLogin);
        Nume->setObjectName("Nume");
        Nume->setGeometry(QRect(420, 150, 191, 51));
        Nume->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        Prenume = new QLineEdit(ClientLogin);
        Prenume->setObjectName("Prenume");
        Prenume->setGeometry(QRect(420, 230, 191, 51));
        Prenume->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        Telefon = new QLineEdit(ClientLogin);
        Telefon->setObjectName("Telefon");
        Telefon->setGeometry(QRect(420, 340, 191, 51));
        Telefon->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        DataNasterii = new QLineEdit(ClientLogin);
        DataNasterii->setObjectName("DataNasterii");
        DataNasterii->setGeometry(QRect(430, 440, 191, 51));
        DataNasterii->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        CodPostal = new QLineEdit(ClientLogin);
        CodPostal->setObjectName("CodPostal");
        CodPostal->setGeometry(QRect(780, 140, 191, 51));
        CodPostal->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        Tara = new QLineEdit(ClientLogin);
        Tara->setObjectName("Tara");
        Tara->setGeometry(QRect(780, 220, 191, 51));
        Tara->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        Judet = new QLineEdit(ClientLogin);
        Judet->setObjectName("Judet");
        Judet->setGeometry(QRect(780, 290, 191, 51));
        Judet->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        Oras = new QLineEdit(ClientLogin);
        Oras->setObjectName("Oras");
        Oras->setGeometry(QRect(780, 370, 191, 51));
        Oras->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        Strada = new QLineEdit(ClientLogin);
        Strada->setObjectName("Strada");
        Strada->setGeometry(QRect(780, 460, 191, 51));
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
        Numarul = new QLineEdit(ClientLogin);
        Numarul->setObjectName("Numarul");
        Numarul->setGeometry(QRect(770, 550, 191, 51));
        Numarul->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        Back = new QPushButton(ClientLogin);
        Back->setObjectName("Back");
        Back->setGeometry(QRect(80, 50, 131, 61));
        Back->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        LoginButton = new QPushButton(ClientLogin);
        LoginButton->setObjectName("LoginButton");
        LoginButton->setGeometry(QRect(430, 630, 131, 61));
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
        Scara = new QLineEdit(ClientLogin);
        Scara->setObjectName("Scara");
        Scara->setGeometry(QRect(750, 640, 101, 41));
        Scara->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        NumarApartament = new QLineEdit(ClientLogin);
        NumarApartament->setObjectName("NumarApartament");
        NumarApartament->setGeometry(QRect(910, 640, 111, 41));
        NumarApartament->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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

        retranslateUi(ClientLogin);

        QMetaObject::connectSlotsByName(ClientLogin);
    } // setupUi

    void retranslateUi(QDialog *ClientLogin)
    {
        ClientLogin->setWindowTitle(QCoreApplication::translate("ClientLogin", "Dialog", nullptr));
        Back->setText(QCoreApplication::translate("ClientLogin", "Back", nullptr));
        LoginButton->setText(QCoreApplication::translate("ClientLogin", "LogIn", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ClientLogin: public Ui_ClientLogin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTLOGIN_H
