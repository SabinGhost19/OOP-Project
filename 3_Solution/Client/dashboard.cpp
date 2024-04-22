#include "dashboard.h"
#include "ui_dashboard.h"

DashBoard::DashBoard(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DashBoard)
{
    ui->setupUi(this);
}

DashBoard::~DashBoard()
{
    delete ui;
}
