/********************************************************************************
** Form generated from reading UI file 'dashboard.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DASHBOARD_H
#define UI_DASHBOARD_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DashBoard
{
public:
    QGridLayout *gridLayout_3;
    QWidget *widget;
    QLabel *label;
    QPushButton *signout_short;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QPushButton *dashboard_short;
    QPushButton *cart_short;
    QPushButton *offerts_short;
    QPushButton *notifications_short;
    QPushButton *profile_short;
    QWidget *scrollWidget;
    QGridLayout *gridLayout;
    QStackedWidget *stackedWidget;
    QWidget *page_5;
    QGridLayout *gridLayout_2;
    QScrollArea *scrollArea;
    QWidget *scrollContens;
    QWidget *page_6;
    QLabel *imagine;
    QLabel *Titlu;
    QLabel *Descriere;
    QPushButton *pushButton;
    QLabel *Descriere_2;
    QFrame *frame;
    QPushButton *slide;
    QLineEdit *lineEdit;
    QPushButton *search;
    QComboBox *comboBox;
    QLabel *label_4;
    QWidget *widget_2;
    QLabel *label_2;
    QLabel *label_3;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QPushButton *dashboard;
    QPushButton *cart;
    QPushButton *offerts;
    QPushButton *notifications;
    QPushButton *profile;
    QPushButton *signout;

    void setupUi(QWidget *DashBoard)
    {
        if (DashBoard->objectName().isEmpty())
            DashBoard->setObjectName("DashBoard");
        DashBoard->resize(1305, 813);
        DashBoard->setMaximumSize(QSize(16777215, 16777215));
        DashBoard->setStyleSheet(QString::fromUtf8("background-color:white;"));
        gridLayout_3 = new QGridLayout(DashBoard);
        gridLayout_3->setObjectName("gridLayout_3");
        widget = new QWidget(DashBoard);
        widget->setObjectName("widget");
        widget->setMinimumSize(QSize(101, 615));
        widget->setMaximumSize(QSize(101, 1677721));
        widget->setStyleSheet(QString::fromUtf8("QWidget{\n"
"background-color:rgb(3, 175, 251)\n"
"}\n"
"\n"
"QPushButton{\n"
"color:white;\n"
"height:50px;\n"
"border:none;\n"
"border-radius:10px;\n"
"}\n"
"\n"
"QPushButton:checked{\n"
"background-color:#FFFFFF;\n"
"color:#063263;\n"
"font-weight:bold;\n"
"}"));
        label = new QLabel(widget);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 30, 49, 16));
        signout_short = new QPushButton(widget);
        signout_short->setObjectName("signout_short");
        signout_short->setGeometry(QRect(10, 550, 80, 58));
        signout_short->setBaseSize(QSize(0, 0));
        signout_short->setCheckable(true);
        signout_short->setAutoExclusive(true);
        layoutWidget = new QWidget(widget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 90, 82, 331));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        dashboard_short = new QPushButton(layoutWidget);
        dashboard_short->setObjectName("dashboard_short");
        dashboard_short->setCheckable(true);
        dashboard_short->setAutoExclusive(true);

        verticalLayout_2->addWidget(dashboard_short);

        cart_short = new QPushButton(layoutWidget);
        cart_short->setObjectName("cart_short");
        cart_short->setCheckable(true);
        cart_short->setAutoExclusive(true);

        verticalLayout_2->addWidget(cart_short);

        offerts_short = new QPushButton(layoutWidget);
        offerts_short->setObjectName("offerts_short");
        offerts_short->setCheckable(true);
        offerts_short->setAutoExclusive(true);

        verticalLayout_2->addWidget(offerts_short);

        notifications_short = new QPushButton(layoutWidget);
        notifications_short->setObjectName("notifications_short");
        notifications_short->setCheckable(true);
        notifications_short->setAutoExclusive(true);

        verticalLayout_2->addWidget(notifications_short);

        profile_short = new QPushButton(layoutWidget);
        profile_short->setObjectName("profile_short");
        profile_short->setBaseSize(QSize(0, 0));
        profile_short->setStyleSheet(QString::fromUtf8("QWidget{\n"
"background-color:rgb(3, 175, 251)\n"
"}\n"
"\n"
"QPushButton{\n"
"color:white;\n"
"height:50px;\n"
"border:none;\n"
"border-radius:10px;\n"
"}\n"
"\n"
"QPushButton:checked{\n"
"background-color:#FFFFFF;\n"
"color:#063263;\n"
"font-weight:bold;\n"
"}"));
        profile_short->setCheckable(true);
        profile_short->setAutoExclusive(true);

        verticalLayout_2->addWidget(profile_short);


        gridLayout_3->addWidget(widget, 0, 0, 1, 1);

        scrollWidget = new QWidget(DashBoard);
        scrollWidget->setObjectName("scrollWidget");
        scrollWidget->setStyleSheet(QString::fromUtf8("QWidget{\n"
"border:none;\n"
"}"));
        gridLayout = new QGridLayout(scrollWidget);
        gridLayout->setObjectName("gridLayout");
        stackedWidget = new QStackedWidget(scrollWidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setMinimumSize(QSize(621, 511));
        page_5 = new QWidget();
        page_5->setObjectName("page_5");
        gridLayout_2 = new QGridLayout(page_5);
        gridLayout_2->setObjectName("gridLayout_2");
        scrollArea = new QScrollArea(page_5);
        scrollArea->setObjectName("scrollArea");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy);
        scrollArea->setStyleSheet(QString::fromUtf8("QScrollBar:vertical {\n"
"    border: none;\n"
"    background-color: rgba(192, 192, 192, 0.5); /* Culoare gri transparent */\n"
"    width: 12px; /* L\304\203\310\233imea barei de scroll */\n"
"    margin: 20px 0 20px 0; /* Margini de sus \310\231i jos */\n"
"    border-radius: 6px; /* Rotunjirea col\310\233urilor */\n"
"}\n"
"\n"
"QScrollBar::handle:vertical {\n"
"    background-color: #707070; /* Culoarea m\303\242nerului (butonului de derulare) */\n"
"    min-height: 20px; /* \303\216n\304\203l\310\233ime minim\304\203 a m\303\242nerului */\n"
"    border-radius: 6px; /* Rotunjirea col\310\233urilor */\n"
"}\n"
"\n"
"QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical,\n"
"QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical {\n"
"    background: none; /* Nu se afi\310\231eaz\304\203 fundalul pentru butoanele de derulare */\n"
"}\n"
""));
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        scrollArea->setWidgetResizable(true);
        scrollContens = new QWidget();
        scrollContens->setObjectName("scrollContens");
        scrollContens->setGeometry(QRect(0, 0, 925, 682));
        scrollArea->setWidget(scrollContens);

        gridLayout_2->addWidget(scrollArea, 0, 0, 1, 1);

        stackedWidget->addWidget(page_5);
        page_6 = new QWidget();
        page_6->setObjectName("page_6");
        imagine = new QLabel(page_6);
        imagine->setObjectName("imagine");
        imagine->setGeometry(QRect(10, 0, 281, 271));
        imagine->setPixmap(QPixmap(QString::fromUtf8(":/img/img/iphone15.webp")));
        imagine->setScaledContents(true);
        Titlu = new QLabel(page_6);
        Titlu->setObjectName("Titlu");
        Titlu->setGeometry(QRect(330, 10, 221, 41));
        Titlu->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 170, 255);"));
        Descriere = new QLabel(page_6);
        Descriere->setObjectName("Descriere");
        Descriere->setGeometry(QRect(330, 90, 221, 41));
        Descriere->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 170, 255);"));
        pushButton = new QPushButton(page_6);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(360, 190, 151, 51));
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 170, 255);"));
        Descriere_2 = new QLabel(page_6);
        Descriere_2->setObjectName("Descriere_2");
        Descriere_2->setGeometry(QRect(10, 290, 571, 221));
        Descriere_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 170, 255);"));
        stackedWidget->addWidget(page_6);

        gridLayout->addWidget(stackedWidget, 1, 0, 1, 1);

        frame = new QFrame(scrollWidget);
        frame->setObjectName("frame");
        frame->setMinimumSize(QSize(619, 71));
        frame->setMaximumSize(QSize(16777215, 71));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        slide = new QPushButton(frame);
        slide->setObjectName("slide");
        slide->setGeometry(QRect(80, 10, 71, 51));
        slide->setMinimumSize(QSize(71, 51));
        slide->setStyleSheet(QString::fromUtf8("\n"
"\n"
"QPushButton{\n"
"background-color:#E6E6E6;\n"
"border-radius:10px;\n"
"border:none;\n"
"}\n"
"QPushButton:checked{\n"
"background-color:#E6E6E6;\n"
"border-radius:10px;\n"
"font-weight:bold;\n"
"}\n"
""));
        slide->setCheckable(true);
        slide->setAutoExclusive(true);
        lineEdit = new QLineEdit(frame);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(160, 20, 251, 41));
        lineEdit->setMinimumSize(QSize(251, 41));
        lineEdit->setMaximumSize(QSize(16777215, 41));
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
        search = new QPushButton(frame);
        search->setObjectName("search");
        search->setGeometry(QRect(420, 10, 71, 51));
        search->setMinimumSize(QSize(71, 51));
        search->setMaximumSize(QSize(16777215, 16777215));
        search->setStyleSheet(QString::fromUtf8("\n"
"\n"
"QPushButton{\n"
"background-color:#E6E6E6;\n"
"border-radius:10px;\n"
"border:none;\n"
"}\n"
"QPushButton:checked{\n"
"background-color:#E6E6E6;\n"
"border-radius:10px;\n"
"font-weight:bold;\n"
"}\n"
""));
        comboBox = new QComboBox(frame);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/img/slide.png"), QSize(), QIcon::Normal, QIcon::Off);
        comboBox->addItem(icon, QString());
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/img/img/yahoo.png"), QSize(), QIcon::Normal, QIcon::Off);
        comboBox->addItem(icon1, QString());
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(500, 20, 162, 30));
        comboBox->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    background-color: #C8F7FF; /* Culoarea de fundal */\n"
"    border: 1px solid #C8F7FF; /* Bordura */\n"
"    border-radius: 10px; /* Rotunjirea col\310\233urilor */\n"
"    padding: 5px; /* Spa\310\233iul interior */\n"
"    min-width: 150px; /* L\304\203\310\233ime minim\304\203 */\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"    width: 20px; /* L\304\203\310\233imea butonului de deschidere */\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    image: url(:/images/down_arrow.png); /* Imaginea s\304\203ge\310\233ii \303\256n jos */\n"
"}\n"
"\n"
"QComboBox QAbstractItemView {\n"
"    background-color: #C8F7FF; /* Culoarea de fundal */\n"
"    selection-background-color: #6DDFFF; /* Culoarea de fundal a elementului selectat */\n"
"    color: black; /* Culoarea textului */\n"
"    border: none; /* Eliminarea bordurii */\n"
"    padding: 8px; /* Spa\310\233iul interior al fiec\304\203rui element */\n"
"}\n"
"\n"
"QComboBox::item:selected {\n"
"    background-color: #6DDFFF; /* Culoarea de fundal a ele"
                        "mentului selectat */\n"
"    color: white; /* Culoarea textului pentru elementul selectat */\n"
"}\n"
"\n"
""));
        comboBox->setEditable(true);
        label_4 = new QLabel(frame);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(10, 10, 61, 51));
        label_4->setPixmap(QPixmap(QString::fromUtf8(":/img/img/logo_nou.jpeg")));
        label_4->setScaledContents(true);

        gridLayout->addWidget(frame, 0, 0, 1, 1);


        gridLayout_3->addWidget(scrollWidget, 0, 2, 1, 1);

        widget_2 = new QWidget(DashBoard);
        widget_2->setObjectName("widget_2");
        widget_2->setMinimumSize(QSize(201, 615));
        widget_2->setMaximumSize(QSize(201, 16777215));
        widget_2->setStyleSheet(QString::fromUtf8("QWidget{\n"
"background-color:rgb(3, 175, 251)\n"
"}\n"
"QPushButton{\n"
"color:white;\n"
"text-align:left;\n"
"height:50px;\n"
"border:none;\n"
"border-top-left-radius:10px;\n"
"border-bottom-left-radius:10px;\n"
"}\n"
"QPushButton:checked{\n"
"background-color:#FFFFFF;\n"
"color:#063263;\n"
"font-weight:bold;\n"
"}\n"
""));
        label_2 = new QLabel(widget_2);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 20, 49, 16));
        label_3 = new QLabel(widget_2);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(110, 20, 49, 16));
        layoutWidget1 = new QWidget(widget_2);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(10, 90, 191, 352));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setSpacing(10);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        dashboard = new QPushButton(layoutWidget1);
        dashboard->setObjectName("dashboard");
        QFont font;
        font.setPointSize(13);
        font.setBold(true);
        dashboard->setFont(font);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/img/img/dashboard_w.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon2.addFile(QString::fromUtf8(":/img/img/dashboard.png"), QSize(), QIcon::Normal, QIcon::On);
        dashboard->setIcon(icon2);
        dashboard->setCheckable(true);
        dashboard->setAutoExclusive(true);

        verticalLayout->addWidget(dashboard);

        cart = new QPushButton(layoutWidget1);
        cart->setObjectName("cart");
        cart->setFont(font);
        cart->setCheckable(true);
        cart->setAutoExclusive(true);

        verticalLayout->addWidget(cart);

        offerts = new QPushButton(layoutWidget1);
        offerts->setObjectName("offerts");
        offerts->setFont(font);
        offerts->setCheckable(true);
        offerts->setAutoExclusive(true);

        verticalLayout->addWidget(offerts);

        notifications = new QPushButton(layoutWidget1);
        notifications->setObjectName("notifications");
        notifications->setFont(font);
        notifications->setCheckable(true);
        notifications->setAutoExclusive(true);

        verticalLayout->addWidget(notifications);

        profile = new QPushButton(layoutWidget1);
        profile->setObjectName("profile");
        profile->setBaseSize(QSize(0, 0));
        profile->setFont(font);
        profile->setCheckable(true);
        profile->setAutoExclusive(true);

        verticalLayout->addWidget(profile);

        signout = new QPushButton(widget_2);
        signout->setObjectName("signout");
        signout->setGeometry(QRect(10, 560, 189, 50));
        signout->setBaseSize(QSize(0, 0));
        signout->setFont(font);
        signout->setCheckable(true);
        signout->setAutoExclusive(true);

        gridLayout_3->addWidget(widget_2, 0, 1, 1, 1);


        retranslateUi(DashBoard);
        QObject::connect(slide, &QPushButton::toggled, widget_2, &QWidget::setVisible);
        QObject::connect(slide, &QPushButton::toggled, widget, &QWidget::setHidden);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(DashBoard);
    } // setupUi

    void retranslateUi(QWidget *DashBoard)
    {
        DashBoard->setWindowTitle(QCoreApplication::translate("DashBoard", "Form", nullptr));
        label->setText(QCoreApplication::translate("DashBoard", "TextLabel", nullptr));
        signout_short->setText(QString());
        dashboard_short->setText(QString());
        cart_short->setText(QString());
        offerts_short->setText(QString());
        notifications_short->setText(QString());
        profile_short->setText(QString());
        imagine->setText(QString());
        Titlu->setText(QCoreApplication::translate("DashBoard", "TITLU", nullptr));
        Descriere->setText(QCoreApplication::translate("DashBoard", "Descriere", nullptr));
        pushButton->setText(QCoreApplication::translate("DashBoard", "Buy", nullptr));
        Descriere_2->setText(QCoreApplication::translate("DashBoard", "COMMENTS", nullptr));
        slide->setText(QString());
        search->setText(QString());
        comboBox->setItemText(0, QCoreApplication::translate("DashBoard", "A-Z", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("DashBoard", "Z-A", nullptr));

        label_4->setText(QString());
        label_2->setText(QCoreApplication::translate("DashBoard", "TextLabel", nullptr));
        label_3->setText(QCoreApplication::translate("DashBoard", "TextLabel", nullptr));
        dashboard->setText(QCoreApplication::translate("DashBoard", "Dashboard", nullptr));
        cart->setText(QCoreApplication::translate("DashBoard", "Cart", nullptr));
        offerts->setText(QCoreApplication::translate("DashBoard", "Offerts", nullptr));
        notifications->setText(QCoreApplication::translate("DashBoard", "Notifications", nullptr));
        profile->setText(QCoreApplication::translate("DashBoard", "Profile", nullptr));
        signout->setText(QCoreApplication::translate("DashBoard", "Sign Out", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DashBoard: public Ui_DashBoard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DASHBOARD_H
