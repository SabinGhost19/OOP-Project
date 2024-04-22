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

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
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
    QPixmap logo(":/img/img/logo_nou.jpeg");


    ui->label_design->setPixmap(pixmapDesign);
    ui->label_design->setScaledContents(true);

    ui->label_yahoo->setPixmap(imageY);
    ui->label_yahoo->setScaledContents(true);

    ui->label_google->setPixmap(pixmapG);
    ui->label_google->setScaledContents(true);

    ui->label_facebook->setPixmap(pixmapF);
    ui->label_facebook->setScaledContents(true);

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



}
void MainWindow::on_exitButton_clicked()
{
    this->close();
}


void MainWindow::on_LoginButton_clicked()
{

    // std::string email;
    // email = ui->lineEdit->text().toStdString();

    // std::string password;
    // password = ui->lineEdit_2->text().toStdString();

    // std::string buffer="1";
    // buffer +=email;
    // buffer +="#";
    // buffer +=password;

    // APPClient::getInstance()->getTcpClient()->send(buffer.c_str(), buffer.length());

    // char bufferRecv[1024];
    // int recv_bytes=0;

    // while(recv_bytes==0)
    // {
    //     recv_bytes = APPClient::getInstance()->getTcpClient()->recv(bufferRecv, 1024);
    //     bufferRecv[recv_bytes] = '\0';
    // }
    // if(strcmp(bufferRecv,"LOGGED IN SUCCESSFULLY")==0)
    //     QMessageBox::information(this,"Login","LOGGED IN SUCCESSFULLY");
    // else if(strcmp(bufferRecv,"YOUR EMAIL ADDRESS ISN'T REGISTERED")==0)
    //     QMessageBox::warning(this,"Login","YOUR EMAIL ADDRESS ISN'T REGISTERED!");
    // else if(strcmp(bufferRecv,"WRONG PASSWORD")==0)
    //     QMessageBox::warning(this,"Login","WRONG PASSWORD!");




    this->close();
    DashBoard*dashboard=new DashBoard();
    dashboard->show();

}

