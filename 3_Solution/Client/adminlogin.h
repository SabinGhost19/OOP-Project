#ifndef ADMINLOGIN_H
#define ADMINLOGIN_H

#include <QDialog>
#include"dashboard.h"

namespace Ui {
class AdminLogin;
}

class AdminLogin : public QDialog
{
    Q_OBJECT

public:
    explicit AdminLogin(QWidget *parent = nullptr);
    ~AdminLogin();

private slots:
    void on_backButton_clicked();

    void on_LoginButton_clicked();

private:
    Ui::AdminLogin *ui;
    DashBoard*dashboard=nullptr;
};

#endif // ADMINLOGIN_H
