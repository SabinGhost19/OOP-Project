#ifndef IMAGEREQUEST_H
#define IMAGEREQUEST_H
#include"DataRequest.h"
#include<iostream>
#include<string.h>
#include<QPixmap>

class ImageRequest: public DataRequest
{
private:
    QPixmap actual_pixmap;
    std::vector<QPixmap>new_images;
    std::string actual_title="---";
    std::string price;
    std::string cantitate;
    std::string ID;
    //QPixmap ReceiveImages();
    inline static ImageRequest *instance=nullptr;


public:
    QPixmap ReceiveImages();
    static ImageRequest*getInstance();
    std::vector<QPixmap> GetNewImages()const;
    void Construct_Images();
    void Construct_MoreImages(int id);
    char*GetAnswer();
    std::string  getTtile();
    QPixmap  getImage();
    std::string getCantitate();
    std::string GetPrice();
    std::string GetID();
    int FindSize();
    ImageRequest();
};

#endif // IMAGEREQUEST_H
