#include "dashboard.h"
#include "ui_dashboard.h"
#include <QtWidgets>
#include <QWidget>
#include <QApplication>
#include <QPushButton>
#include <QIcon>
#include <QVBoxLayout>
#include "mainwindow.h"
#include"APPClient.h"
#include"ProductBuilder.h"
#include"ImageRequest.h"
#include"DescriptionRequest.h"
#include"UserClientRequest.h"
#include"FactoryUser.h"
#include"CommentsRequest.h"

DashBoard::DashBoard(QWidget *parent,int userID)
    : QWidget(parent)
    , ui(new Ui::DashBoard)
{
    ui->setupUi(this);

    //apel la server pentru construirea userului cu informatiile sale //client doar care cumpara
    this->SetStylePolicyforIcons();
    this->adaugareFramesToDashBrd();
    //this->setUser(user_ID);

}
void DashBoard::setUser(int ID){
    FactoryUser*new_factory=new FactoryUser();
    this->user=new_factory->ConstructClientUser(ID);
}
void DashBoard::onButtonClicked(){

    QPushButton *clickedButton = qobject_cast<QPushButton*>(sender()); // Află butonul apăsat

    if (clickedButton) {

        int index = buttonList.indexOf(clickedButton);

        if (index != -1) {

            emit ConstructProductView(index);
        } else {
            qDebug() << "Indexul butonului nu a fost găsit!";
        }
    }

}

void DashBoard::ConstructProductView(int index){

    DescriptionRequest::getInstance()->SetIndex(index);
    std::string description=DescriptionRequest::getInstance()->GetDescription();

    CommentsRequest::getInstance()->SetIndex(index);

    ui->scrollArea_3->setWidgetResizable(true);
    ui->scrollArea_3->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    ui->scrollArea_3->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    ui->scrollArea_3->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->scrollArea_3->setGeometry(10, 60, 1011, 211);
    ui->scrollArea_3->setMinimumSize(1011, 211);
    ui->scrollArea_3->setContentsMargins(0, 0, 0, 0);

    QGridLayout *gridLayout = new QGridLayout(ui->scrollContent_3);

     //for(int i=0;i<CommentsRequest::getInstance()->Size();i++)
    for (int i = 0; i < 5; ++i) {

        std::pair<std::string, std::string>pair=CommentsRequest::getInstance()->GetComments();

        QFrame *frame = new QFrame;
        frame->setFixedSize(911, 171);
        frame->setStyleSheet("background-color: white;");


        QLabel *titleLabel = new QLabel("Titlu");
        titleLabel->setFixedSize(161, 31);
        titleLabel->setStyleSheet("background-color: blue;");
        titleLabel->setText(pair.first.c_str());


        QLabel *descriptionLabel = new QLabel("Descriere");
        descriptionLabel->setFixedSize(881, 111);
        descriptionLabel->setStyleSheet("background-color: blue;");
        descriptionLabel->setText(pair.second.c_str());


        QVBoxLayout *frameLayout = new QVBoxLayout;
        frameLayout->addWidget(titleLabel);
        frameLayout->addWidget(descriptionLabel);
        frame->setLayout(frameLayout);


        gridLayout->addWidget(frame, i, 0);
    }

    ui->imageLabel->setFixedSize(401, 391);
    ui->imageLabel->setMinimumSize(401, 391);
    ui->imageLabel->move(10, 20);
    ui->imageLabel->setStyleSheet("background-color: red;");



    ui->titleLabel->setFixedSize(461, 71);
    ui->titleLabel->setMinimumSize(461, 71);
    ui->titleLabel->move(440, 30);
    ui->titleLabel->setStyleSheet("background-color: white;");



    ui->descriptionLabel->setFixedSize(461, 291);
    ui->descriptionLabel->setMinimumSize(461, 291);
    ui->descriptionLabel->move(440, 120);
    ui->descriptionLabel->setStyleSheet("background-color: yellow;");



    ui->miniTitleLabel->setFixedSize(161, 41);
    ui->miniTitleLabel->setMinimumSize(161, 41);
    ui->miniTitleLabel->move(10, 410);
    ui->miniTitleLabel->setStyleSheet("background-color: blue;");

    ui->scrollArea_3->setWidget(ui->scrollContent_3);

    ui->imageLabel->setText(description.c_str());
    ui->titleLabel->setText("----------------------");
    ui->stackedWidget->setCurrentIndex(1);

}


void DashBoard::adaugareFramesToDashBrd(){

    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    //!
    //!
    //!
    //! cred ca va trebui sa ne facem o clasa de produs,
    //!
    //! altfel nu am putea rezolva probleam cu butonul si trimiterea la pagina de view a lui
    //!
    //!
    //!
    //! plus modul de filtrare, memorare in clasa doar a pixmap pret, cantitate si a titlului
    //!
    //! astfel facem filtrare alfaetica, pret etc, fara apeluri multe la server
    //!
    //! iar apelarea de view page facila
    //!
    //!
    //!
    //! ///////////////////////////////////

    QGridLayout *layout = new QGridLayout(ui->scrollContens);

    ui->scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    ui->scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    ui->scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


    //while(strcmp(ImageRequest::getInstance()->GetAnswer(),"end")!=0){}
    //!!!!!!!!!!!!?!??!???????????!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    for (int i = 0; i <10; ++i) {
   //trebuie luata lungimea sau un semnal de oprire in imagerequest!!!!!!!!
        QFrame *frame = ProductBuilder::getInstance()->ProduceFrame();
        frame->setObjectName("myFrame");
        frame->setFixedSize(241, 241);
        frame->setMaximumSize(241, 241);
        frame->setStyleSheet("QFrame#myFrame { background-color: yellow; }"); // Setează culoarea de fundal
        QGridLayout *gridLayout = new QGridLayout(frame);
        frame->setLayout(gridLayout);
        // Creează label-ul cu pixmap

        QLabel *pixmapLabel = ProductBuilder::getInstance()->ProducePixmapLable(frame);

        //QPixmap pixmap=ImageRequest::getInstance()->Construct_Images();
        // pixmapLabel->setPixmap(pixmap);
        // pixmapLabel->setScaledContents(true);        // Setează imaginea
        pixmapLabel->setFixedSize(221, 191);
        pixmapLabel->setMaximumSize(221, 191);
        pixmapLabel->setGeometry(9, 9, 221, 191);
        gridLayout->addWidget(pixmapLabel, 0, 0);


        QLabel *label1 = ProductBuilder::getInstance()->ProduceTitle(frame);
        label1->setFixedSize(121, 31);
        label1->setMinimumSize(121, 31);
        label1->setStyleSheet("QLabel { color: green; }"); // Setează culoarea textului verde
        gridLayout->addWidget(label1, 0, 0); // Adaugă label1 pe prima poziție a grid-ului
        label1->setGeometry(9, 201, 121, 31); // Setează coordonatele
        gridLayout->addWidget(label1, 1, 0);

        QPushButton *button = ProductBuilder::getInstance()->ProduceButton(frame);
        gridLayout->addWidget(button, 1, 1);
        this->buttonList.append(button);
        connect(button, &QPushButton::clicked, this, & DashBoard::onButtonClicked);
        layout->addWidget(frame, i / 3, i % 3);

    }

      ui->scrollArea->setWidget(ui->scrollContens);


}
void DashBoard::SetStylePolicyforIcons(){


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



    ui->cart_short->setIcon(QIcon(":/img/img/cart_w.png"));
    connect(ui->cart_short, &QPushButton::toggled, this, [=](bool checked) {
        if (checked) {
            // Setăm pictograma când butonul este verificat
            ui->cart_short->setIcon(QIcon(":/img/img/cart.png"));
        }else{
            ui->cart_short->setIcon(QIcon(":/img/img/cart_w.png"));
        }
    });

    ui->dashboard->setIcon(QIcon(":/img/img/dashboard_w.png"));
    connect(ui->dashboard, &QPushButton::toggled, this, [=](bool checked) {
        if (checked) {
            // Setăm pictograma când butonul este verificat
            ui->dashboard->setIcon(QIcon(":/img/img/dashboard.png"));
        }else{
            ui->dashboard->setIcon(QIcon(":/img/img/dashboard_w.png"));
        }
    });

    ui->dashboard_short->setIcon(QIcon(":/img/img/dashboard_w.png"));
    connect(ui->dashboard_short, &QPushButton::toggled, this, [=](bool checked) {
        if (checked) {
            // Setăm pictograma când butonul este verificat
            ui->dashboard_short->setIcon(QIcon(":/img/img/dashboard.png"));
        }else{
            ui->dashboard_short->setIcon(QIcon(":/img/img/dashboard_w.png"));
        }
    });


    ui->profile->setIcon(profile);
    ui->profile_short->setIcon(profile);



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


void DashBoard::on_cart_clicked()
{
      ui->stackedWidget->setCurrentIndex(1);
}


void DashBoard::on_dashboard_clicked()
{
     ui->stackedWidget->setCurrentIndex(0);
}


void DashBoard::on_dashboard_short_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void DashBoard::on_cart_short_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

