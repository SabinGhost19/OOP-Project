#include "companywindow.h"
#include "ui_companywindow.h"
#include"addProduct.h"

CompanyWindow::CompanyWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CompanyWindow)
{
    ui->setupUi(this);
}

CompanyWindow::~CompanyWindow()
{
    delete ui;
}

void CompanyWindow::on_AddNewProduct_clicked()
{
    this->close();
    AddProduct*new_add_window=new AddProduct();
    new_add_window->show();
}

