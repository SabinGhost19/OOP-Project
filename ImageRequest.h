#ifndef IMAGEREQUEST_H
#define IMAGEREQUEST_H
#include"DataRequest.h"
#include<iostream>
#include<string.h>
#include<QPixmap>

class ImageRequest: public DataRequest
{
private:

    QPixmap ReceiveImages();
    inline static ImageRequest *instance=nullptr;


public:
    static ImageRequest*getInstance();
    QPixmap Construct_Images();
    char*GetAnswer();

    ImageRequest();
};

#endif // IMAGEREQUEST_H
