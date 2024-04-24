#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <QWidget>
#include<QFrame>
#include<QPushButton>
#include"userClient.h"

namespace Ui {
class DashBoard;
}

class DashBoard : public QWidget
{
    Q_OBJECT

public:
    explicit DashBoard(QWidget *parent = nullptr,int userID=0);
    explicit DashBoard(int userID);
    ~DashBoard();

private slots:


    void on_pushButton_clicked();

    void on_signout_clicked();

    void on_signout_short_clicked();

    void on_search_clicked();
    void adaugareFramesToDashBrd();

    void SetStylePolicyforIcons();

    void on_cart_clicked();

    void on_dashboard_clicked();

    void on_dashboard_short_clicked();

    void on_cart_short_clicked();

    void ConstructProductView(int);

    void setUser(int ID);

public slots:
    void onButtonClicked();

private:
    Ui::DashBoard *ui;
    UserClient*user=nullptr;
    QList<QPushButton*> buttonList;
};

#endif // DASHBOARD_H
