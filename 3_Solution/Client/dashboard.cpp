#include "dashboard.h"
#include "ui_dashboard.h"
#include <QtWidgets>
#include <QWidget>
#include <QApplication>
#include <QPushButton>
#include <QIcon>
#include <QVBoxLayout>
#include "mainwindow.h";
#include"APPClient.h"

DashBoard::DashBoard(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::DashBoard)
{
    ui->setupUi(this);


    ui->widget_2->hide();
    QIcon cart(":/img/img/cart_w.png");
    QIcon profile(":/img/img/profile_w.png");
    QIcon notifications(":/img/img/notifications_w.png");
    QIcon dashboard(":/img/img/dashboard_w.png");
    QIcon offerts(":/img/img/offert_w.png");
    QIcon signout(":/img/img/signout_w.png");
    QIcon slide(":/img/img/slide.png");
    QIcon search(":/img/img/search.png");

     ui->cart->setIcon(QIcon(":/img/img/cart_w.png"));
    connect(ui->cart, &QPushButton::toggled, this, [=](bool checked) {
        if (checked) {
            // Setăm pictograma când butonul este verificat
            ui->cart->setIcon(QIcon(":/img/img/cart.png"));
        }else{
            ui->cart->setIcon(QIcon(":/img/img/cart_w.png"));
        }
    });

    ui->cart_short->setIcon(cart);

    ui->profile->setIcon(profile);
    ui->profile_short->setIcon(profile);

    ui->dashboard->setIcon(dashboard);
    ui->dashboard_short->setIcon(dashboard);

    ui->notifications_short->setIcon(notifications);
    ui->notifications->setIcon(notifications);

    ui->signout->setIcon(signout);
    ui->signout_short->setIcon(signout);

    ui->offerts->setIcon(offerts);
    ui->offerts_short->setIcon(offerts);

    QSize iconSize(70, 50);

    ui->cart->setIconSize(iconSize);
    ui->cart->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);

    ui->profile->setIconSize(iconSize);
    ui->profile->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);

    ui->dashboard->setIconSize(iconSize);
    ui->dashboard->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);

    ui->notifications->setIconSize(iconSize);
    ui->notifications->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);

    ui->signout->setIconSize(iconSize);
    ui->signout->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);

    ui->offerts->setIconSize(iconSize);
    ui->offerts->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    //----------------------------

    ui->cart_short->setIconSize(iconSize);
    ui->cart_short->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);

    ui->profile_short->setIconSize(iconSize);
    ui->profile_short->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);

    ui->dashboard_short->setIconSize(iconSize);
    ui->dashboard_short->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);

    ui->notifications_short->setIconSize(iconSize);
    ui->notifications_short->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);

    ui->signout_short->setIconSize(iconSize);
    ui->signout_short->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);

    ui->offerts_short->setIconSize(iconSize);
    ui->offerts_short->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);

    QGridLayout *layout = new QGridLayout(ui->scrollContens); // Layout-ul tip grid pentru label-uri
    //ui->scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    ui->scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    ui->scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    ui->scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    // Adaugă label-uri în layout-ul grid
    for (int i = 0; i < 10; ++i) {

        QFrame *frame = new QFrame;
        frame->setObjectName("myFrame");
        frame->setFixedSize(241, 241);
        frame->setMaximumSize(241, 241);
        frame->setStyleSheet("QFrame#myFrame { background-color: yellow; }"); // Setează culoarea de fundal
        QGridLayout *gridLayout = new QGridLayout(frame);
        frame->setLayout(gridLayout);
        // Creează label-ul cu pixmap

        QLabel *pixmapLabel = new QLabel(frame);
        APPClient::getInstance()->getTcpClient()->send("2",2);
        QPixmap pixmap=APPClient::getInstance()->getTcpClient()->receiveImage();
        pixmapLabel->setPixmap(pixmap);
        pixmapLabel->setScaledContents(true);        // Setează imaginea
        pixmapLabel->setFixedSize(221, 191);
        pixmapLabel->setMaximumSize(221, 191);
        pixmapLabel->setGeometry(9, 9, 221, 191);
        gridLayout->addWidget(pixmapLabel, 0, 0);

        // Creează cele două label-uri suplimentare
        QLabel *label1 = new QLabel("Label 1", frame);
        label1->setFixedSize(121, 31);
        label1->setMinimumSize(121, 31);
        label1->setStyleSheet("QLabel { color: green; }"); // Setează culoarea textului verde
        //gridLayout->addWidget(label1, 0, 0); // Adaugă label1 pe prima poziție a grid-ului
        label1->setGeometry(9, 201, 121, 31); // Setează coordonatele
        gridLayout->addWidget(label1, 1, 0);

        QPushButton *button = new QPushButton("Button", frame);
        button->setFixedSize(101, 31);
        button->setMinimumSize(101, 31);
        button->setStyleSheet("QPushButton { color: blue; border: none; background-color: transparent; }" // Setează culoarea textului albastru și elimină stilurile butonului
                              "QPushButton:hover { background-color: #e0e0e0; }" // Adaugă un efect de hover pentru buton
                              "QPushButton:pressed { background-color: #c0c0c0; }"); // Adaugă un efect pentru când butonul este apăsat
        gridLayout->addWidget(button, 1, 1);


        layout->addWidget(frame, i / 3, i % 3);

    }

    // Setează widget-ul interior ca fiind widget-ul de vizualizare pentru Scroll Area
    ui->scrollArea->setWidget(ui->scrollContens);



    QSize iconSizeSlide(40, 40);
    ui->slide->setIcon(slide);
    ui->slide->setIconSize(iconSizeSlide);
    ui->slide->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);


    ui->search->setIcon(search);
    ui->search->setIconSize(iconSizeSlide);
    ui->search->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);

}

DashBoard::~DashBoard()
{
    delete ui;
}




void DashBoard::on_pushButton_clicked()
{

    if(ui->widget->isHidden()){
        ui->widget->show();
        ui->widget_2->hide();
    }else{
        ui->widget->hide();
        ui->widget_2->show();
    }
}


void DashBoard::on_signout_clicked()
{
    this->close();
    MainWindow *main=new MainWindow();
    main->show();
}


void DashBoard::on_signout_short_clicked()
{
    this->close();
    MainWindow *main=new MainWindow();
    main->show();
}


void DashBoard::on_search_clicked()
{

}

