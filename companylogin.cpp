#include "companylogin.h"
#include "dashboard.h"
#include "ui_companylogin.h"
#include"signinwindow.h"
#pragma comment (lib, "Ws2_32.lib")
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include"APPClient.h"
#include<QMessageBox>

CompanyLogin::CompanyLogin(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CompanyLogin)
{
    ui->setupUi(this);


    ui->lineEdit->setPlaceholderText("First Name");
    // Setarea textului implicit pentru un QLineEdit numit lineEdit
    ui->lineEdit_2->setPlaceholderText("Last Name");

    ui->lineEdit_3->setPlaceholderText("Email");
    // Setarea textului implicit pentru un QLineEdit numit lineEdit
    ui->lineEdit_4->setPlaceholderText("Password");
}

CompanyLogin::~CompanyLogin()
{
    delete ui;
}

void CompanyLogin::on_backButton_clicked()
{

        this->close();
        SignInWindow*signin=new SignInWindow();
        signin->show();
}


void CompanyLogin::on_LoginButton_clicked()
{
    char name[50];
    char username[50];
    char email[50];
    char password[50];
    strcpy(name,ui->lineEdit->text().toUtf8());
    strcpy(username,ui->lineEdit_2->text().toUtf8());
    strcpy(email,ui->lineEdit->text().toUtf8());
    strcpy(password,ui->lineEdit_2->text().toUtf8());


    //all set to n for testing
    //-!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    if((strcmp(name,"n")==0) && (strcmp(username,"n")==0)&&(strcmp(email,"n")==0) && (strcmp(username,"n")==0)){


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

