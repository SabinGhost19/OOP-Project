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
    QPixmap logo(":/img/img/k.jpg");


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
    char name[50];
    char username[50];
    strcpy(name,ui->lineEdit->text().toUtf8());
    strcpy(username,ui->lineEdit_2->text().toUtf8());



    //-!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    if((strcmp(name,"A")==0) && (strcmp(username,"M")==0)){


        APPClient::getInstance()->getTcpClient()->send(name, strlen(name));
        APPClient::getInstance()->getTcpClient() ->send(username, strlen(username));
      //---VERIFICARE DE DATE-----
        //un if :)
        dashboard= new DashBoard(this);

        this->close();
        dashboard->show();

         QMessageBox::information(this,"Login","Name and Username are correct");


    }else{
        QMessageBox::warning(this,"Login","Name and Username are INCORRECT");
    }





}

