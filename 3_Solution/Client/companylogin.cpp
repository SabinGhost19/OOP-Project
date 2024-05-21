#include "companylogin.h"
#include "dashboard.h"
#include "ui_companylogin.h"
#include"signinwindow.h"
#pragma comment (lib, "Ws2_32.lib")
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include"APPClient.h"
#include<QMessageBox>
#include"SignInRequest.h"
#include"mainwindow.h"

CompanyLogin::CompanyLogin(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CompanyLogin)
{
    ui->setupUi(this);


    ui->Nume->setPlaceholderText("Nume Producator");
    ui->CodPostal->setPlaceholderText("Cod Postal");
    ui->Judet->setPlaceholderText("Judet");
    ui->NrApartament->setPlaceholderText("Optional:Nr Apartament");
    ui->Oras->setPlaceholderText("Oras");
    ui->Scara->setPlaceholderText("Optional:Scara");
    ui->Strada->setPlaceholderText("Strada");
    ui->Numar->setPlaceholderText("Numar Strada");
    ui->Tara->setPlaceholderText("Tara");



}

CompanyLogin::~CompanyLogin()
{
    delete ui;
}

void CompanyLogin::on_Back_clicked()
{

    this->close();
    SignInWindow*signin=new SignInWindow();
    signin->show();
}


void CompanyLogin::on_LoginButton_clicked()
{

    std::vector<std::string> texts;
    std::string null="NULL";
    std::string id="2";
    std::string rol="Companie";
    texts.push_back(id);
    texts.push_back(rol);
    texts.push_back(ui->Email->text().toStdString());
    texts.push_back(ui->Parola->text().toStdString());
    texts.push_back(ui->Nume->text().toStdString());
    texts.push_back(ui->CodPostal->text().toStdString());
    texts.push_back(ui->Tara->text().toStdString());
    texts.push_back(ui->Judet->text().toStdString());
    texts.push_back(ui->Oras->text().toStdString());
    texts.push_back(ui->Strada->text().toStdString());
    texts.push_back(ui->Numar->text().toStdString());
    if(ui->Scara->text().isEmpty()){

        texts.push_back(null);
    }else{
        texts.push_back(ui->Scara->text().toStdString());
    }
    if(ui->NrApartament->text().isEmpty()){
        texts.push_back(null);
    }else{
        texts.push_back(ui->NrApartament->text().toStdString());
    }

    SignInRequest::getInstance()->GetData(texts);
    if(SignInRequest::getInstance()->SendAllData()){
        this->close();
        MainWindow*main=new MainWindow();
        main->show();
    }else{
        //tratare cu exceptie
    }

}



