#include "clientlogin.h"
#include "ui_clientlogin.h"
#include "signinwindow.h"
#pragma comment (lib, "Ws2_32.lib")
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include"APPClient.h"
#include<QMessageBox>
#include <QtWidgets>


ClientLogin::ClientLogin(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ClientLogin)
{
    ui->setupUi(this);

    ui->Nume->setPlaceholderText("Nume");
    ui->Prenume->setPlaceholderText("Prenume");
    ui->Tara->setPlaceholderText("Tara");
    ui->Email->setPlaceholderText("Email");
    ui->Parola->setPlaceholderText("Parola");
    ui->DataNasterii->setPlaceholderText("Data Nasterii");
    ui->Judet->setPlaceholderText("Judet");
    ui->NumarApartament->setPlaceholderText("App. Nr.");
    ui->Oras->setPlaceholderText("Oras");
    ui->Strada->setPlaceholderText("Strada");
    ui->Scara->setPlaceholderText("Scara");
    ui->Numarul->setPlaceholderText("Numarul");
    ui->CodPostal->setPlaceholderText("Cod Postal");
    ui->Telefon->setPlaceholderText("Telefon");


    ui->Email->setStyleSheet("QLineEdit {"
                                "background-color: #f2f2f2;"
                                "border: 1px solid #ccc;"
                                "border-radius: 5px;"
                                "padding: 5px;"
                                "}");

    ui->Parola->setStyleSheet("QLineEdit {"
                             "background-color: #f2f2f2;"
                             "border: 1px solid #ccc;"
                             "border-radius: 5px;"
                             "padding: 5px;"
                             "}");
    ui->DataNasterii->setStyleSheet("QLineEdit {"
                             "background-color: #f2f2f2;"
                             "border: 1px solid #ccc;"
                             "border-radius: 5px;"
                             "padding: 5px;"
                             "}");
    ui->Judet->setStyleSheet("QLineEdit {"
                             "background-color: #f2f2f2;"
                             "border: 1px solid #ccc;"
                             "border-radius: 5px;"
                             "padding: 5px;"
                             "}");
    ui->NumarApartament->setStyleSheet("QLineEdit {"
                             "background-color: #f2f2f2;"
                             "border: 1px solid #ccc;"
                             "border-radius: 5px;"
                             "padding: 5px;"
                             "}");
    ui->Oras->setStyleSheet("QLineEdit {"
                             "background-color: #f2f2f2;"
                             "border: 1px solid #ccc;"
                             "border-radius: 5px;"
                             "padding: 5px;"
                             "}");
    ui->Strada->setStyleSheet("QLineEdit {"
                             "background-color: #f2f2f2;"
                             "border: 1px solid #ccc;"
                             "border-radius: 5px;"
                             "padding: 5px;"
                             "}");
    ui->Scara->setStyleSheet("QLineEdit {"
                             "background-color: #f2f2f2;"
                             "border: 1px solid #ccc;"
                             "border-radius: 5px;"
                             "padding: 5px;"
                             "}");
    ui->Numarul->setStyleSheet("QLineEdit {"
                             "background-color: #f2f2f2;"
                             "border: 1px solid #ccc;"
                             "border-radius: 5px;"
                             "padding: 5px;"
                             "}");
    ui->CodPostal->setStyleSheet("QLineEdit {"
                               "background-color: #f2f2f2;"
                               "border: 1px solid #ccc;"
                               "border-radius: 5px;"
                               "padding: 5px;"
                               "}");
    ui->Telefon->setStyleSheet("QLineEdit {"
                               "background-color: #f2f2f2;"
                               "border: 1px solid #ccc;"
                               "border-radius: 5px;"
                               "padding: 5px;"
                               "}");
    ui->Nume->setStyleSheet("QLineEdit {"
                             "background-color: #f2f2f2;"
                             "border: 1px solid #ccc;"
                             "border-radius: 5px;"
                             "padding: 5px;"
                             "}");
    ui->Prenume->setStyleSheet("QLineEdit {"
                             "background-color: #f2f2f2;"
                             "border: 1px solid #ccc;"
                             "border-radius: 5px;"
                             "padding: 5px;"
                             "}");
    ui->Tara->setStyleSheet("QLineEdit {"
                             "background-color: #f2f2f2;"
                             "border: 1px solid #ccc;"
                             "border-radius: 5px;"
                             "padding: 5px;"
                             "}");


}

ClientLogin::~ClientLogin()
{
    delete ui;
}

void ClientLogin::on_pushButton_clicked()
{
    this->close();
    SignInWindow*signin=new SignInWindow();
    signin->show();
}


void ClientLogin::on_LoginButton_clicked()
{


   //------DATE CONT------------------
    std::string email;
    email = ui->Email->text().toStdString();

    std::string password;
    password = ui->Parola->text().toStdString();



   ///------DATE PERSONALE------------
    std::string nume;
    nume = ui->Nume->text().toStdString();

    std::string prenume;
    prenume = ui->Prenume->text().toStdString();

    std::string telefon;
    telefon = ui->Telefon->text().toStdString();

    std::string DataNasterii;
    DataNasterii = ui->DataNasterii->text().toStdString();



    //----------DATE ADRESA----------
    std::string tara;
    tara = ui->Tara->text().toStdString();

    std::string oras;
    oras = ui->Oras->text().toStdString();

    std::string judet;
    judet = ui->Judet->text().toStdString();

    std::string strada;
    strada = ui->Strada->text().toStdString();

    std::string scara;
    scara = ui->Scara->text().toStdString();

    std::string numar;
    numar = ui->Numarul->text().toStdString();

    std::string numarApp;
    numarApp = ui->NumarApartament->text().toStdString();

    std::string codPostal;
    codPostal = ui->CodPostal->text().toStdString();





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



}

