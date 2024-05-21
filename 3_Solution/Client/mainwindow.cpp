#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include<QPixmap>
#include <QMdiArea>
#include <QPalette>
#include <QColor>
#pragma comment (lib, "Ws2_32.lib")
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include"APPClient.h"
#include<QMessageBox>
//#include"loadingscreen.h"
#include"LogInRequest.h"
#include<iostream>
#include<string.h>
#include <cstdlib>
#include"FactoryUser.h"
#include"companywindow.h"
#include"dashboard.h"
#include <QInputDialog>
#include"CardRequest.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    //LoadingScreen*load=new LoadingScreen();
    //load->show();
    ui->setupUi(this);

    // Setarea textului implicit pentru un QLineEdit numit lineEdit
    ui->lineEdit->setPlaceholderText("Email");
    // Setarea textului implicit pentru un QLineEdit numit lineEdit
    ui->lineEdit_2->setPlaceholderText("Password");



    this->setWindowFlags(Qt::FramelessWindowHint);
    //setare imagini
    QPixmap pixmapG(":/img/img/google.png");
    // QPixmap pixmapF("C:/Users/sabin/OneDrive/Desktop/facebook.png");
    QPixmap pixmapF(":/img/img/facebook.png");

    QPixmap pixmapDesign(":/img/img/design.png");
    QPixmap imageY(":/img/img/yahoo.png");
    QPixmap logo(":/img/img/Logo.png");


    ui->label_design->setPixmap(pixmapDesign);
    ui->label_design->setScaledContents(true);

   // ui->label_yahoo->setPixmap(imageY);
    //ui->label_yahoo->setScaledContents(true);

    //ui->label_google->setPixmap(pixmapG);
    //ui->label_google->setScaledContents(true);

    //ui->label_facebook->setPixmap(pixmapF);
    //ui->label_facebook->setScaledContents(true);

    ui->label_logo->setPixmap(logo);
    ui->label_logo->setScaledContents(true);


    //setare iconuri butoane
    QIcon icon(":/img/img/exit3.png");

    ui->exitButton->setIcon(icon);
    QSize iconSize(40, 40);
    ui->exitButton->setIconSize(iconSize);
    ui->exitButton->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_SignInButton_clicked()
{

    signin = new SignInWindow(this);

    this->close();
    signin->show();
    std::cout<<"SIGN IN PRESSED !!!!!!!!!!"<<std::endl;


}



void MainWindow::on_exitButton_clicked()
{
    this->close();
}


void MainWindow::on_LoginButton_clicked()
{

    std::string email;
    email = ui->lineEdit->text().toStdString();

    std::string password;
    password = ui->lineEdit_2->text().toStdString();


    std::string mssg="1";
    LogInRequest::getInstance()->SetMssg(mssg);
    //LogInRequest::getInstance()->Answer();
    LogInRequest::getInstance()->Request();

    LogInRequest::getInstance()->SetMssg(email);
    LogInRequest::getInstance()->Request();
    LogInRequest::getInstance()->SetMssg(password);
    LogInRequest::getInstance()->Request();

    LogInRequest::getInstance()->Answer();//true false
    QString answer=QString::fromUtf8(LogInRequest::getInstance()->GetAnswer());
    std::cout<<std::endl<<std::endl<<std::endl<<"answerrrr: "<<answer.toStdString()<<std::endl<<std::endl<<std::endl;
    APPClient::getInstance()->getTcpClient()->send("ACK", strlen("ACK"));

    if(answer.toStdString()=="TRUE"){
        LogInRequest::getInstance()->Answer();
        this->userID=atoi(LogInRequest::getInstance()->GetAnswer());
        APPClient::getInstance()->getTcpClient()->send("ACK", strlen("ACK"));

        FactoryUser*new_fac=new FactoryUser();
        new_fac->setRol(userID);


        if(this->userID==0){

            new_fac->ConstructUser();
            UserClient*new_user=new_fac->ConstrucClienttUser(0);

            CardRequest card_req;
            card_req.RecvCard();
            Card*new_card=card_req.GetCardData();
            new_user->setCard(new_card);

            APPClient::getInstance()->setClientUser(new_user);

            this->close();
            DashBoard*dashboard=new DashBoard();
            dashboard->show();

        }else if(this->userID==1){

            new_fac->ConstructUser();
            UserCompany*new_user=new_fac->ConstrucCompanytUser(0);

            APPClient::getInstance()->setCompanyUser(new_user);

            this->close();
            CompanyWindow*window=new CompanyWindow();
            window->show();
        }
        delete new_fac;

    }
    else{


        this->close();
        SignInWindow*signIn=new SignInWindow();
        signIn->show();
        std::cout<<"GO to the register page , the account dont exist\n";
        //tratare cu exceptie

    }



    // bool ok;
    // QString text = QInputDialog::getText(this, "Introducere text", "Introdu un text:", QLineEdit::Normal, "", &ok);
    // if (ok && !text.isEmpty()) {
    //     // Textul a fost introdus și butonul "OK" a fost apăsat
    //     // Acum poți face ceva cu textul introdus
    //     qDebug() << "Text introdus:" << text;
    // } else {
    //     // Utilizatorul a apăsat butonul "Cancel" sau a închis fereastra
    //     qDebug() << "Utilizatorul a anulat introducerea textului.";
    // }



    // // // std::cout<<"LogInPressed!!!!!!!";
    //this->close();
    // // CompanyWindow*new_comWin=new CompanyWindow();
    // // new_comWin->show();
    //DashBoard*new_d=new DashBoard();
    //new_d->show();
}

