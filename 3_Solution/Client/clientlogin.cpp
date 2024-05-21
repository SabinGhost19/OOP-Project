#include "clientlogin.h"
#include "ui_clientlogin.h"
#include "signinwindow.h"
#pragma comment (lib, "Ws2_32.lib")
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include"APPClient.h"
#include<QMessageBox>
#include <QtWidgets>
#include"SignInRequest.h"
#include"mainwindow.h"


ClientLogin::ClientLogin(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ClientLogin)
{
    ui->setupUi(this);

    ui->Email->setPlaceholderText("Nume");
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
    ui->Email->setStyleSheet("QLineEdit {"
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
    if (telefon.size() > 7) {
        // Dacă textul depășește dimensiunea 7, afișează un mesaj de eroare
        QMessageBox::warning(nullptr, "Eroare", "Dimensiunea numărului de telefon trebuie să fie maxim 7 caractere.");
        return;
    }

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


    std::vector<std::string> date;

    // Adaugă toate șirurile de caractere în vector
    std::string id="2";
    std::string rol="Client";
    date.push_back(id);
    date.push_back(rol);
    date.push_back(email);
    date.push_back(password);
    date.push_back(nume);
    date.push_back(prenume);
    date.push_back(telefon);
    date.push_back(DataNasterii);
    date.push_back(codPostal);
    date.push_back(tara);
    date.push_back(judet);
    date.push_back(oras);
    date.push_back(strada);
    date.push_back(numar);
    date.push_back(scara);
    date.push_back(numarApp);
    date.push_back(codPostal);
    date.push_back(tara);
    date.push_back(judet);
    date.push_back(oras);
    date.push_back(strada);
    date.push_back(numar);
    date.push_back(scara);
    date.push_back(numarApp);






    SignInRequest::getInstance()->GetData(date);
    if(SignInRequest::getInstance()->SendAllData()){
        this->close();
        MainWindow*main=new MainWindow();
        main->show();
    }else{

    }

    // this->close();
    // MainWindow*main=new MainWindow();
    // main->show();

}



void ClientLogin::on_Back_clicked()
{


        this->close();
        SignInWindow*signin=new SignInWindow();
        signin->show();

}

