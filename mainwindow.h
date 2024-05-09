#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"signinwindow.h"
#include"dashboard.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
signals://------------------------------
    void showSecondWindow();

    void onShowSecondWindow();
    //-----------------------------------



public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_exitButton_clicked();

    void on_SignInButton_clicked();

    void on_LoginButton_clicked();



private:
    int userID=0;
    Ui::MainWindow *ui;
    SignInWindow*signin=nullptr;
    //DashBoard*dashboard=nullptr;
};
#endif // MAINWINDOW_H





























