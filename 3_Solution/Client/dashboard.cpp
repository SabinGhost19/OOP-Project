#include "dashboard.h"
#include "ui_dashboard.h"
#include <QtWidgets>
#include <QWidget>
#include <QApplication>
#include <QPushButton>
#include <QIcon>
#include <QVBoxLayout>
#include "mainwindow.h";

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
    for (int i = 0; i < 20; ++i) {

        QLabel *label = new QLabel("Text rosu");
        label->setGeometry(50, 20, 70, 50); // Setează geometria label-ului
        label->setStyleSheet("QLabel { color : red;"
                             "background: red }");
        label->setMinimumSize(200, 200);
        label->setMaximumSize(200, 200);
        layout->addWidget(label, i / 4, i % 4); // Adaugă label-ul în layout, calculând rândul și coloana
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

