#include "mainwindow.h"
#include <QApplication>
#include "APPClient.h"
int main(int argc, char *argv[])
{
    APPClient* APPClientC = APPClient::getInstance();
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    QObject::connect(&a,QApplication::aboutToQuit,[=](){
        delete APPClientC;
    });
    return a.exec();
}
