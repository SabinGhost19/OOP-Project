#ifndef COMPANYLOGIN_H
#define COMPANYLOGIN_H

#include <QDialog>
#include"dashboard.h"
namespace Ui {
class CompanyLogin;
}

class CompanyLogin : public QDialog
{
    Q_OBJECT

public:
    explicit CompanyLogin(QWidget *parent = nullptr);
    ~CompanyLogin();

private slots:
    void on_backButton_clicked();

    void on_LoginButton_clicked();

private:
    Ui::CompanyLogin *ui;
    DashBoard*dashboard=nullptr;
};

#endif // COMPANYLOGIN_H
