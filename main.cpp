#include "mainwindow.h"

#include <QApplication>
#include "APPClient.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    APPClient* APPClientC = APPClient::getInstance();
    MainWindow w;
    w.show();
    return a.exec();
}
