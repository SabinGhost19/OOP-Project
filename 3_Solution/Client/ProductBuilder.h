#ifndef PRODUCTBUILDER_H
#define PRODUCTBUILDER_H
#include<QPixmap>
#include<vector>
#include<iostream>
#include<QFrame>
#include<QLabel>
#include<QPushButton>

class ProductBuilder
{
public:

    static ProductBuilder*getInstance();
    void GetPixmapDatafromServer(std::vector<QPixmap>);


    int GetNrOfFrames();
    int GetIndex();

    void RestartIndex();

    QLabel*ProduceTitle(QFrame*frame);
    QFrame*ProduceFrame();
    QLabel*ProducePixmapLable(QFrame*frame);
    QPushButton*ProduceButton(QFrame*frame);

private:


    ProductBuilder();
    inline static int index=0;

    inline static ProductBuilder*instance=nullptr;
    std::vector<QPixmap>pixmap_list;

};

#endif // PRODUCTBUILDER_H

