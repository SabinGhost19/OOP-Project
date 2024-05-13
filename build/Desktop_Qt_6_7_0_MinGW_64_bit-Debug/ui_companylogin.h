/********************************************************************************
** Form generated from reading UI file 'companylogin.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
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
    QPushButton *Back;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLineEdit *Email;
    QLineEdit *Parola;
    QLineEdit *Nume;
    QLineEdit *CodPostal;
    QLineEdit *Tara;
    QLineEdit *Judet;
    QLineEdit *Oras;
    QLabel *label;
    QLineEdit *Numar;
    QLineEdit *Scara;
    QLineEdit *NrApartament;
    QLineEdit *Strada;
    QPushButton *LoginButton;

    void setupUi(QDialog *CompanyLogin)
    {
        if (CompanyLogin->objectName().isEmpty())
            CompanyLogin->setObjectName("CompanyLogin");
        CompanyLogin->resize(929, 615);
        CompanyLogin->setStyleSheet(QString::fromUtf8("background-color: rgb(172, 198, 255);"));
        Back = new QPushButton(CompanyLogin);
        Back->setObjectName("Back");
        Back->setGeometry(QRect(30, 30, 141, 61));
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
        verticalLayoutWidget = new QWidget(CompanyLogin);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(90, 130, 331, 421));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        Email = new QLineEdit(verticalLayoutWidget);
        Email->setObjectName("Email");
        Email->setMinimumSize(QSize(0, 41));
        Email->setMaximumSize(QSize(16777215, 41));
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

        verticalLayout->addWidget(Email);

        Parola = new QLineEdit(verticalLayoutWidget);
        Parola->setObjectName("Parola");
        Parola->setMinimumSize(QSize(0, 41));
        Parola->setMaximumSize(QSize(16777215, 41));
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

        verticalLayout->addWidget(Parola);

        Nume = new QLineEdit(verticalLayoutWidget);
        Nume->setObjectName("Nume");
        Nume->setMinimumSize(QSize(0, 41));
        Nume->setMaximumSize(QSize(16777215, 41));
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

        verticalLayout->addWidget(Nume);

        CodPostal = new QLineEdit(verticalLayoutWidget);
        CodPostal->setObjectName("CodPostal");
        CodPostal->setMinimumSize(QSize(0, 41));
        CodPostal->setMaximumSize(QSize(16777215, 41));
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

        verticalLayout->addWidget(CodPostal);

        Tara = new QLineEdit(verticalLayoutWidget);
        Tara->setObjectName("Tara");
        Tara->setMinimumSize(QSize(0, 41));
        Tara->setMaximumSize(QSize(16777215, 41));
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

        verticalLayout->addWidget(Tara);

        Judet = new QLineEdit(verticalLayoutWidget);
        Judet->setObjectName("Judet");
        Judet->setMinimumSize(QSize(0, 41));
        Judet->setMaximumSize(QSize(16777215, 41));
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

        verticalLayout->addWidget(Judet);

        Oras = new QLineEdit(verticalLayoutWidget);
        Oras->setObjectName("Oras");
        Oras->setMinimumSize(QSize(0, 41));
        Oras->setMaximumSize(QSize(16777215, 41));
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

        verticalLayout->addWidget(Oras);

        label = new QLabel(CompanyLogin);
        label->setObjectName("label");
        label->setGeometry(QRect(330, -10, 251, 101));
        QFont font;
        font.setPointSize(19);
        font.setBold(true);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        Numar = new QLineEdit(CompanyLogin);
        Numar->setObjectName("Numar");
        Numar->setGeometry(QRect(490, 290, 151, 41));
        Numar->setMinimumSize(QSize(0, 41));
        Numar->setMaximumSize(QSize(16777215, 41));
        Numar->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        Scara = new QLineEdit(CompanyLogin);
        Scara->setObjectName("Scara");
        Scara->setGeometry(QRect(660, 290, 151, 41));
        Scara->setMinimumSize(QSize(0, 41));
        Scara->setMaximumSize(QSize(16777215, 41));
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
        NrApartament = new QLineEdit(CompanyLogin);
        NrApartament->setObjectName("NrApartament");
        NrApartament->setGeometry(QRect(580, 360, 151, 41));
        NrApartament->setMinimumSize(QSize(0, 41));
        NrApartament->setMaximumSize(QSize(16777215, 41));
        NrApartament->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        Strada = new QLineEdit(CompanyLogin);
        Strada->setObjectName("Strada");
        Strada->setGeometry(QRect(490, 230, 329, 41));
        Strada->setMinimumSize(QSize(0, 41));
        Strada->setMaximumSize(QSize(16777215, 41));
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
        LoginButton = new QPushButton(CompanyLogin);
        LoginButton->setObjectName("LoginButton");
        LoginButton->setGeometry(QRect(580, 460, 151, 61));
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

        retranslateUi(CompanyLogin);

        QMetaObject::connectSlotsByName(CompanyLogin);
    } // setupUi

    void retranslateUi(QDialog *CompanyLogin)
    {
        CompanyLogin->setWindowTitle(QCoreApplication::translate("CompanyLogin", "Dialog", nullptr));
        Back->setText(QCoreApplication::translate("CompanyLogin", "Back", nullptr));
        label->setText(QCoreApplication::translate("CompanyLogin", "Company LogIn", nullptr));
        LoginButton->setText(QCoreApplication::translate("CompanyLogin", "LogIn", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CompanyLogin: public Ui_CompanyLogin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMPANYLOGIN_H
