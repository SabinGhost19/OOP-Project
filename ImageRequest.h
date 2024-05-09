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
    std::string actual_title="---";
    QPixmap ReceiveImages();
    inline static ImageRequest *instance=nullptr;


public:
    static ImageRequest*getInstance();
    void Construct_Images();
    char*GetAnswer();
    std::string  getTtile();
    QPixmap  getImage();

    ImageRequest();
};

#endif // IMAGEREQUEST_H
