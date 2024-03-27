#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include<QPixmap>
#include <QMdiArea>
#include <QPalette>
#include <QColor>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // this->showFullScreen();
    this->setWindowFlags(Qt::FramelessWindowHint);
    //setAttribute(Qt::WA_TranslucentBackground);
    //ui->label_4->setStyleSheet("color:#9EFFD1 ");
    //ui->label_4->setStyleSheet("QLabel { background-color: #063263; border: 2px solid #C8F7FF; color: #FFFFFF; padding: 10px; border-radius: 20px; opacity: 0.8; }");
    //ui->tabWidget->setStyleSheet("QTabWidget::pane { background-color: transparent; }");

    //ui->label_4->show();

   // ui->lineEdit->setPlaceholderText("Username");
   // ui->lineEdit_2->setPlaceholderText("Password");

    QPixmap pixmap("C:/Users/sabin/OneDrive/Desktop/t.png");
    QPixmap pixmapG("C:/Users/sabin/OneDrive/Desktop/google.png");
    QPixmap pixmapF("C:/Users/sabin/OneDrive/Desktop/facebook.png");
    QPixmap pixmapY("C:/Users/sabin/OneDrive/Desktop/yahoo.png");

    QPixmap pixmapDesign("C:/Users/sabin/OneDrive/Desktop/Design.png");
    //pixmap = pixmap.scaled(QSize(480, 240, Qt::KeepAspectRatio);
    QSize newSize = pixmap.size().scaled(512, 512,Qt::KeepAspectRatio);
    QSize MediaSize = pixmap.size().scaled(50, 50,Qt::KeepAspectRatio);
    QSize DesignSize = pixmap.size().scaled(880, 1600,Qt::KeepAspectRatio);


    // Redimensionați pixmap-ul la noua dimensiune
    pixmap = pixmap.scaled(MediaSize, Qt::KeepAspectRatio);
    // pixmapG=pixmapG.scaled(MediaSize,Qt::KeepAspectRatio);
    // pixmapF=pixmapF.scaled(MediaSize,Qt::KeepAspectRatio);
    // pixmapY=pixmapY.scaled(MediaSize,Qt::KeepAspectRatio);
    pixmapDesign=pixmapDesign.scaled(DesignSize,Qt::KeepAspectRatio);

    //ui->label->setPixmap(pixmap);
    // ui->label_google->setPixmap(pixmapG);
    // ui->label_facebook->setPixmap(pixmapF);
    // ui->label_yahoo->setPixmap(pixmapY);
   // ui->label->setPixmap(pixmapDesign);
    //ui->label_yahoo->show();
    //ui->label_google->show();

    // ui->label->adjustSize();





    //int h=ui->label_pic->height();
    //int w=ui->label_pic->width();
    //QPixmap pix("C:/Users/sabin/OneDrive/Desktop/ProjectImages/pp.png");
    //ui->label_pic->setPixmap(pix.scaled(700,700,Qt::KeepAspectRatio));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

   secondW= new SecondWindow(this);

    QObject::connect(this, &MainWindow::showSecondWindow, secondW, &SecondWindow::show);

    // Emite semnalul pentru a afișa secondWindow
    //secondW->showFullScreen();
    this->showSecondWindow();

    hide();

    //secondW= new SecondWindow(this);
    //secondW->show();

}
void MainWindow::on_pushButton_2_clicked()
{

    signin= new SignInWindow(this);

    //---------QObject::connect(this, &MainWindow::showSecondWindow, secondW, &SecondWindow::show);

    // Emite semnalul pentru a afișa secondWindow
    //secondW->showFullScreen();
    //this->showSecondWindow();
    this->close();
    signin->show();

    //secondW= new SecondWindow(this);
    //secondW->show();

}
void MainWindow::on_pushButton_4_clicked()
{
    this->close();
}

