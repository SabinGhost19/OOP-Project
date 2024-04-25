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
    inline static int index_imagine=0;
    void saveByteArrayAsPng(const QByteArray &byteArray);

public:
    static ImageRequest*getInstance();
    QPixmap Construct_Images();
    char*GetAnswer();

    ImageRequest();
};

#endif // IMAGEREQUEST_H
