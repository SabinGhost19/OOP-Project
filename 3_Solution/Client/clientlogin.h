#ifndef CLIENTLOGIN_H
#define CLIENTLOGIN_H

#include <QDialog>
#include "dashboard.h"
namespace Ui {
class ClientLogin;
}

class ClientLogin : public QDialog
{
    Q_OBJECT

public:
    explicit ClientLogin(QWidget *parent = nullptr);
    ~ClientLogin();

private slots:

    void on_LoginButton_clicked();

    void on_Back_clicked();

private:
    Ui::ClientLogin *ui;
    DashBoard *dashboard = nullptr;
};

#endif // CLIENTLOGIN_H
