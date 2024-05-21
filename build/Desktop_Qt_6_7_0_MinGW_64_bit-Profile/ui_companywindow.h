/********************************************************************************
** Form generated from reading UI file 'companywindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMPANYWINDOW_H
#define UI_COMPANYWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CompanyWindow
{
public:
    QLabel *label;
    QPushButton *AddNewProduct;
    QLabel *label_2;
    QLabel *label_products;
    QScrollArea *scrollArea;
    QWidget *scrollAreaContents;
    QFrame *frame;
    QLabel *label_5;
    QPushButton *pushButton;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QPushButton *pushButton_2;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_profit;
    QLabel *profit;
    QPushButton *Back;
    QLabel *label_3;
    QLabel *NrProduseListate;
    QLabel *label_12;
    QLabel *NumeCompanie;

    void setupUi(QWidget *CompanyWindow)
    {
        if (CompanyWindow->objectName().isEmpty())
            CompanyWindow->setObjectName("CompanyWindow");
        CompanyWindow->resize(1184, 747);
        CompanyWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(199, 255, 230);"));
        label = new QLabel(CompanyWindow);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 50, 411, 161));
        QFont font;
        font.setFamilies({QString::fromUtf8("Sitka Text Semibold")});
        font.setPointSize(23);
        font.setBold(true);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        AddNewProduct = new QPushButton(CompanyWindow);
        AddNewProduct->setObjectName("AddNewProduct");
        AddNewProduct->setGeometry(QRect(110, 600, 121, 51));
        AddNewProduct->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #007aff;      /* Culorile caracteristice Apple */\n"
"    border: 2px solid #007aff;      /* Conturul butonului */\n"
"    border-radius: 10px;            /* Col\310\233urile rotunjite */\n"
"    color: white;                   /* Culoarea textului */\n"
"    padding: 10px 20px;             /* Spa\310\233iul intern */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #0056b3;      /* Culoare de fundal la hover */\n"
"}"));
        label_2 = new QLabel(CompanyWindow);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(30, 550, 291, 111));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Segoe UI Variable Small Semibol")});
        font1.setPointSize(20);
        font1.setBold(true);
        label_2->setFont(font1);
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(60, 122, 255);\n"
"background-color: rgb(190, 250, 235);\n"
"border-radius: 30px; "));
        label_2->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        label_products = new QLabel(CompanyWindow);
        label_products->setObjectName("label_products");
        label_products->setGeometry(QRect(640, 30, 241, 71));
        QFont font2;
        font2.setPointSize(19);
        label_products->setFont(font2);
        label_products->setAlignment(Qt::AlignCenter);
        scrollArea = new QScrollArea(CompanyWindow);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(440, 120, 701, 471));
        scrollArea->setWidgetResizable(true);
        scrollAreaContents = new QWidget();
        scrollAreaContents->setObjectName("scrollAreaContents");
        scrollAreaContents->setGeometry(QRect(0, 0, 699, 469));
        frame = new QFrame(scrollAreaContents);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(10, 50, 681, 311));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label_5 = new QLabel(frame);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(310, 10, 361, 291));
        label_5->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pushButton = new QPushButton(frame);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(10, 240, 131, 51));
        label_6 = new QLabel(frame);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(20, 20, 131, 51));
        label_6->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_7 = new QLabel(frame);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(20, 80, 131, 51));
        label_7->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_8 = new QLabel(frame);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(20, 140, 131, 51));
        label_8->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pushButton_2 = new QPushButton(frame);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(160, 240, 131, 51));
        label_9 = new QLabel(frame);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(160, 20, 131, 51));
        label_9->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_10 = new QLabel(frame);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(160, 80, 131, 51));
        label_10->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_11 = new QLabel(frame);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(160, 140, 131, 51));
        label_11->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        scrollArea->setWidget(scrollAreaContents);
        label_profit = new QLabel(CompanyWindow);
        label_profit->setObjectName("label_profit");
        label_profit->setGeometry(QRect(570, 600, 191, 61));
        QFont font3;
        font3.setPointSize(15);
        label_profit->setFont(font3);
        label_profit->setStyleSheet(QString::fromUtf8("color: rgb(60, 122, 255);\n"
"background-color: rgb(190, 250, 235);\n"
"border-radius: 30px; "));
        label_profit->setAlignment(Qt::AlignCenter);
        profit = new QLabel(CompanyWindow);
        profit->setObjectName("profit");
        profit->setGeometry(QRect(780, 600, 181, 61));
        profit->setFont(font3);
        profit->setStyleSheet(QString::fromUtf8("color: rgb(176, 201, 255);\n"
"background-color: rgb(190, 250, 235);\n"
"border-radius: 30px; "));
        profit->setAlignment(Qt::AlignCenter);
        Back = new QPushButton(CompanyWindow);
        Back->setObjectName("Back");
        Back->setGeometry(QRect(30, 10, 141, 61));
        Back->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #007aff;      /* Culorile caracteristice Apple */\n"
"    border: 2px solid #007aff;      /* Conturul butonului */\n"
"    border-radius: 10px;            /* Col\310\233urile rotunjite */\n"
"    color: white;                   /* Culoarea textului */\n"
"    padding: 10px 20px;             /* Spa\310\233iul intern */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #0056b3;      /* Culoare de fundal la hover */\n"
"}"));
        label_3 = new QLabel(CompanyWindow);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(20, 320, 191, 51));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Segoe UI Variable Display Semib")});
        font4.setPointSize(12);
        font4.setBold(true);
        label_3->setFont(font4);
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(60, 122, 255);\n"
"background-color: rgb(190, 250, 235);\n"
"border-radius: 30px; "));
        NrProduseListate = new QLabel(CompanyWindow);
        NrProduseListate->setObjectName("NrProduseListate");
        NrProduseListate->setGeometry(QRect(230, 320, 161, 51));
        NrProduseListate->setStyleSheet(QString::fromUtf8("color: rgb(60, 122, 255);\n"
"background-color: rgb(190, 250, 235);\n"
"border-radius: 30px; "));
        label_12 = new QLabel(CompanyWindow);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(30, 240, 181, 51));
        label_12->setFont(font4);
        label_12->setStyleSheet(QString::fromUtf8("color: rgb(60, 122, 255);\n"
"background-color: rgb(190, 250, 235);\n"
"border-radius: 30px; "));
        NumeCompanie = new QLabel(CompanyWindow);
        NumeCompanie->setObjectName("NumeCompanie");
        NumeCompanie->setGeometry(QRect(230, 240, 161, 51));
        NumeCompanie->setStyleSheet(QString::fromUtf8("color: rgb(60, 122, 255);\n"
"background-color: rgb(190, 250, 235);\n"
"border-radius: 30px; "));
        label_2->raise();
        label->raise();
        AddNewProduct->raise();
        label_products->raise();
        scrollArea->raise();
        label_profit->raise();
        profit->raise();
        Back->raise();
        label_3->raise();
        NrProduseListate->raise();
        label_12->raise();
        NumeCompanie->raise();

        retranslateUi(CompanyWindow);

        QMetaObject::connectSlotsByName(CompanyWindow);
    } // setupUi

    void retranslateUi(QWidget *CompanyWindow)
    {
        CompanyWindow->setWindowTitle(QCoreApplication::translate("CompanyWindow", "Form", nullptr));
        label->setText(QCoreApplication::translate("CompanyWindow", "Welcom to your Profile", nullptr));
        AddNewProduct->setText(QCoreApplication::translate("CompanyWindow", "GO", nullptr));
        label_2->setText(QCoreApplication::translate("CompanyWindow", "ADD new Products", nullptr));
        label_products->setText(QCoreApplication::translate("CompanyWindow", "Your Products", nullptr));
        label_5->setText(QString());
        pushButton->setText(QCoreApplication::translate("CompanyWindow", "Schimba pret", nullptr));
        label_6->setText(QString());
        label_7->setText(QString());
        label_8->setText(QString());
        pushButton_2->setText(QCoreApplication::translate("CompanyWindow", "Schimba pret", nullptr));
        label_9->setText(QString());
        label_10->setText(QString());
        label_11->setText(QString());
        label_profit->setText(QCoreApplication::translate("CompanyWindow", "Total Profit:", nullptr));
        profit->setText(QString());
        Back->setText(QCoreApplication::translate("CompanyWindow", "Back", nullptr));
        label_3->setText(QCoreApplication::translate("CompanyWindow", "Numar de Produse Listate:", nullptr));
        NrProduseListate->setText(QString());
        label_12->setText(QCoreApplication::translate("CompanyWindow", "Nume Companie:", nullptr));
        NumeCompanie->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CompanyWindow: public Ui_CompanyWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMPANYWINDOW_H
