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
    QWidget *scrollAreaWidgetContents;
    QLabel *label_profit;
    QLabel *profit;

    void setupUi(QWidget *CompanyWindow)
    {
        if (CompanyWindow->objectName().isEmpty())
            CompanyWindow->setObjectName("CompanyWindow");
        CompanyWindow->resize(1184, 747);
        CompanyWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(155, 255, 195);"));
        label = new QLabel(CompanyWindow);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 20, 411, 161));
        QFont font;
        font.setFamilies({QString::fromUtf8("Sitka Text Semibold")});
        font.setPointSize(23);
        font.setBold(true);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        AddNewProduct = new QPushButton(CompanyWindow);
        AddNewProduct->setObjectName("AddNewProduct");
        AddNewProduct->setGeometry(QRect(100, 490, 201, 51));
        label_2 = new QLabel(CompanyWindow);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(50, 400, 301, 91));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Segoe UI Symbol")});
        font1.setPointSize(20);
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignCenter);
        label_products = new QLabel(CompanyWindow);
        label_products->setObjectName("label_products");
        label_products->setGeometry(QRect(760, 30, 241, 71));
        QFont font2;
        font2.setPointSize(19);
        label_products->setFont(font2);
        label_products->setAlignment(Qt::AlignCenter);
        scrollArea = new QScrollArea(CompanyWindow);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(640, 120, 501, 351));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 499, 349));
        scrollArea->setWidget(scrollAreaWidgetContents);
        label_profit = new QLabel(CompanyWindow);
        label_profit->setObjectName("label_profit");
        label_profit->setGeometry(QRect(640, 490, 181, 61));
        QFont font3;
        font3.setPointSize(15);
        label_profit->setFont(font3);
        label_profit->setAlignment(Qt::AlignCenter);
        profit = new QLabel(CompanyWindow);
        profit->setObjectName("profit");
        profit->setGeometry(QRect(850, 490, 181, 61));
        profit->setFont(font3);
        profit->setAlignment(Qt::AlignCenter);

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
        label_profit->setText(QCoreApplication::translate("CompanyWindow", "Total Profit:", nullptr));
        profit->setText(QCoreApplication::translate("CompanyWindow", "$$$$$", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CompanyWindow: public Ui_CompanyWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMPANYWINDOW_H
