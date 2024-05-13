/********************************************************************************
** Form generated from reading UI file 'addproduct.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDPRODUCT_H
#define UI_ADDPRODUCT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddProduct
{
public:
    QLabel *TitleLabel;
    QLineEdit *lineEditTitle;
    QLabel *DescriptionLabel;
    QLineEdit *lineEditDescription;
    QLabel *DescriptionLabel_2;
    QLineEdit *lineEditPrice;
    QLabel *DescriptionLabel_3;
    QPushButton *AddImage;
    QFrame *Pathframe;
    QLabel *DescriptionLabel_4;
    QLineEdit *lineEditQuantity;
    QPushButton *Submit;
    QComboBox *comboBox;

    void setupUi(QWidget *AddProduct)
    {
        if (AddProduct->objectName().isEmpty())
            AddProduct->setObjectName("AddProduct");
        AddProduct->resize(1284, 762);
        TitleLabel = new QLabel(AddProduct);
        TitleLabel->setObjectName("TitleLabel");
        TitleLabel->setGeometry(QRect(-10, -20, 501, 201));
        QFont font;
        font.setPointSize(24);
        TitleLabel->setFont(font);
        TitleLabel->setAlignment(Qt::AlignCenter);
        lineEditTitle = new QLineEdit(AddProduct);
        lineEditTitle->setObjectName("lineEditTitle");
        lineEditTitle->setGeometry(QRect(50, 130, 401, 71));
        DescriptionLabel = new QLabel(AddProduct);
        DescriptionLabel->setObjectName("DescriptionLabel");
        DescriptionLabel->setGeometry(QRect(40, 190, 501, 201));
        DescriptionLabel->setFont(font);
        DescriptionLabel->setAlignment(Qt::AlignCenter);
        lineEditDescription = new QLineEdit(AddProduct);
        lineEditDescription->setObjectName("lineEditDescription");
        lineEditDescription->setGeometry(QRect(40, 340, 501, 171));
        DescriptionLabel_2 = new QLabel(AddProduct);
        DescriptionLabel_2->setObjectName("DescriptionLabel_2");
        DescriptionLabel_2->setGeometry(QRect(20, 470, 501, 201));
        DescriptionLabel_2->setFont(font);
        DescriptionLabel_2->setAlignment(Qt::AlignCenter);
        lineEditPrice = new QLineEdit(AddProduct);
        lineEditPrice->setObjectName("lineEditPrice");
        lineEditPrice->setGeometry(QRect(90, 620, 351, 71));
        DescriptionLabel_3 = new QLabel(AddProduct);
        DescriptionLabel_3->setObjectName("DescriptionLabel_3");
        DescriptionLabel_3->setGeometry(QRect(680, 20, 501, 201));
        DescriptionLabel_3->setFont(font);
        DescriptionLabel_3->setAlignment(Qt::AlignCenter);
        AddImage = new QPushButton(AddProduct);
        AddImage->setObjectName("AddImage");
        AddImage->setGeometry(QRect(860, 300, 141, 51));
        Pathframe = new QFrame(AddProduct);
        Pathframe->setObjectName("Pathframe");
        Pathframe->setGeometry(QRect(720, 180, 441, 91));
        Pathframe->setFrameShape(QFrame::StyledPanel);
        Pathframe->setFrameShadow(QFrame::Raised);
        DescriptionLabel_4 = new QLabel(AddProduct);
        DescriptionLabel_4->setObjectName("DescriptionLabel_4");
        DescriptionLabel_4->setGeometry(QRect(680, 360, 501, 201));
        DescriptionLabel_4->setFont(font);
        DescriptionLabel_4->setAlignment(Qt::AlignCenter);
        lineEditQuantity = new QLineEdit(AddProduct);
        lineEditQuantity->setObjectName("lineEditQuantity");
        lineEditQuantity->setGeometry(QRect(800, 510, 251, 71));
        Submit = new QPushButton(AddProduct);
        Submit->setObjectName("Submit");
        Submit->setGeometry(QRect(860, 650, 191, 81));
        comboBox = new QComboBox(AddProduct);
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(510, 180, 201, 41));

        retranslateUi(AddProduct);

        QMetaObject::connectSlotsByName(AddProduct);
    } // setupUi

    void retranslateUi(QWidget *AddProduct)
    {
        AddProduct->setWindowTitle(QCoreApplication::translate("AddProduct", "Form", nullptr));
        TitleLabel->setText(QCoreApplication::translate("AddProduct", "Add the title of the Product:", nullptr));
        DescriptionLabel->setText(QCoreApplication::translate("AddProduct", "Add the Description of the Product:", nullptr));
        DescriptionLabel_2->setText(QCoreApplication::translate("AddProduct", "Add the Price of the Product:", nullptr));
        DescriptionLabel_3->setText(QCoreApplication::translate("AddProduct", "Add the Images for the Product:", nullptr));
        AddImage->setText(QCoreApplication::translate("AddProduct", "AddImage", nullptr));
        DescriptionLabel_4->setText(QCoreApplication::translate("AddProduct", "Add the Quantity of the Product:", nullptr));
        Submit->setText(QCoreApplication::translate("AddProduct", "Submit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddProduct: public Ui_AddProduct {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDPRODUCT_H
