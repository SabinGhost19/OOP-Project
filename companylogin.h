#ifndef COMPANYLOGIN_H
#define COMPANYLOGIN_H

#include <QDialog>

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
    void on_Back_clicked();
    void on_LoginButton_clicked();



private:
    Ui::CompanyLogin *ui;
};

#endif // COMPANYLOGIN_H
