#include "loadingscreen.h"
#include "ui_loadingscreen.h"
#include <QTimer>

LoadingScreen::LoadingScreen(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LoadingScreen)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    //setWindowFlags(windowFlags() | Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint | Qt::Tool);


    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &LoadingScreen::updateImage);
    timer->start(130);



    QStringList imageList;
    imageList << ":/img/img/loading1.png" << ":/img/img/loading2.png"
              << ":/img/img/loading3.png"<<":/img/img/loading4.png";


    m_imageList = imageList;
    m_currentImageIndex = 0;

   // QPixmap current=QPixmap(m_imageList[m_currentImageIndex]);
   // current.setScaledContents(true);
    ui->label->setPixmap(QPixmap(m_imageList[m_currentImageIndex]));
}

LoadingScreen::~LoadingScreen()
{
    delete ui;
}


void LoadingScreen::updateImage()
{
    // Actualizează imaginea cu următoarea din listă
    m_currentImageIndex = (m_currentImageIndex + 1) % m_imageList.size();
    ui->label->setPixmap(QPixmap(m_imageList[m_currentImageIndex]));
}
