#include "secondwindow.h"
#include "ui_secondwindow.h"
#include"mainwindow.h"
#include<iostream>
#include<QMessageBox>
#pragma comment (lib, "Ws2_32.lib")
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include"APPClient.h"
#include <QPainter>
//ui(new Ui::SecondWindow)
TCPClient* client=nullptr;

SecondWindow::SecondWindow(QWidget *parent)
    : QDialog(parent)
{
      //ui->setupUi(this);
    //this->setStyleSheet();
    this->resize(869,633);
    //ui->label->show();



}

SecondWindow::~SecondWindow()
{

    delete ui;
}



