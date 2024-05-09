#include "ProductBuilder.h"
#include<utility>
#include<memory.h>
#include<QGridLayout>
#include<QAbstractButton>

ProductBuilder::ProductBuilder() {}

ProductBuilder* ProductBuilder::getInstance() {
    if (instance != nullptr)
        return instance;
    instance = new ProductBuilder();
    return instance;

}
void ProductBuilder::GetPixmapDatafromServer(std::vector<QPixmap>data){

    this->pixmap_list=std::move(data);
}

QLabel*ProductBuilder::ProducePixmapLable(QFrame*frame){


    QLabel *pixmapLabel = new QLabel(frame);
    // APPClient::getInstance()->getTcpClient()->send("2",2);
    // QPixmap pixmap=APPClient::getInstance()->getTcpClient()->receiveImage();
    // pixmapLabel->setPixmap(pixmap);
    // pixmapLabel->setScaledContents(true);        // Setează imaginea
    pixmapLabel->setFixedSize(221, 191);
    pixmapLabel->setMaximumSize(221, 191);
    pixmapLabel->setGeometry(9, 9, 221, 191);

    return pixmapLabel;
}
QFrame*ProductBuilder::ProduceFrame(){
    this->index++;
    QFrame *frame = new QFrame;
    frame->setObjectName("ProductFrame");
    frame->setFixedSize(241, 241);
    frame->setMaximumSize(241, 241);
    frame->setStyleSheet("QFrame#myFrame { background-color: yellow; }");
    return frame;
}

QLabel*ProductBuilder::ProduceTitle(QFrame*frame){

    QLabel *label1 = new QLabel("Label 1", frame);
    label1->setFixedSize(121, 31);
    label1->setMinimumSize(121, 31);
    label1->setStyleSheet("QLabel { color: green; }"); // Setează culoarea textului verde
    //gridLayout->addWidget(label1, 0, 0); // Adaugă label1 pe prima poziție a grid-ului
    label1->setGeometry(9, 201, 121, 31); // Setează coordonatele
    return label1;
}


QPushButton*ProductBuilder::ProduceButton(QFrame*frame){

    QPushButton *button = new QPushButton("View Product", frame);
    button->setFixedSize(101, 31);
    button->setMinimumSize(101, 31);
    button->setStyleSheet("QPushButton { color: blue; border: none; background-color: transparent; }" // Setează culoarea textului albastru și elimină stilurile butonului
                      "QPushButton:hover { background-color: #e0e0e0; }" // Adaugă un efect de hover pentru buton
                      "QPushButton:pressed { background-color: #c0c0c0; }"); // Adaugă un efect pentru când butonul este apăsat

    return button;

}

int ProductBuilder::GetNrOfFrames(){

    return static_cast<int>(this->pixmap_list.size());
}

int ProductBuilder::GetIndex(){return this->index;}
void ProductBuilder::RestartIndex(){this->index=0;}




