#include "signinwindow.h"
#include "ui_signinwindow.h"
#include "mainwindow.h"
#include"companylogin.h"
#include"adminlogin.h"
#include"clientlogin.h"
SignInWindow::SignInWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SignInWindow)
{
    ui->setupUi(this);
    //this->setWindowFlags(Qt::FramelessWindowHint);

    QPixmap circle("C:/Users/sabin/OneDrive/Desktop/circle.png");


    ui->label_circle->setPixmap(circle);
    ui->label_circle->setScaledContents(true);


    QIcon admin("C:/Users/sabin/OneDrive/Desktop/admin.png");
    QIcon box("C:/Users/sabin/OneDrive/Desktop/box.png");
    QIcon shop("C:/Users/sabin/OneDrive/Desktop/shop.png");

    ui->CompanyButton->setIcon(box);
    ui->AdminButton->setIcon(admin);
    ui->ClientButton->setIcon(shop);

    QSize iconSize(50, 50);

    ui->CompanyButton->setIconSize(iconSize);
    ui->CompanyButton->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);

    ui->ClientButton->setIconSize(iconSize);
    ui->ClientButton->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);

    ui->AdminButton->setIconSize(iconSize);
    ui->AdminButton->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);


}

SignInWindow::~SignInWindow()
{
    delete ui;
}

void SignInWindow::on_backButton_clicked()
{

    this->close();
    MainWindow*main=new MainWindow();
    main->show();

}


void SignInWindow::on_CompanyButton_clicked()
{
    this->close();
    CompanyLogin*company=new CompanyLogin();
    company->show();
}


void SignInWindow::on_ClientButton_clicked()
{
    this->close();
    ClientLogin*client=new ClientLogin();
    client->show();
}


void SignInWindow::on_AdminButton_clicked()
{
    this->close();
    AdminLogin*admin=new AdminLogin();
    admin->show();
}

