#include "ImageRequest.h"
#include <qdebug.h>


ImageRequest::ImageRequest() {strcpy(this->answer,"");this->message="";}

ImageRequest*ImageRequest::getInstance(){
    if (instance != nullptr)
        return instance;
    instance = new ImageRequest();
    return instance;
}

char*ImageRequest::GetAnswer(){return this->answer;}

QPixmap  ImageRequest::Construct_Images(){

    this->message="2";
    this->Request();
    int size=atoi(this->answer);

    return ReceiveImages();
}

QPixmap ImageRequest::ReceiveImages(){

    int nrOfBytes = 0;
    char dimToRecvChar[50];
    nrOfBytes = APPClient::getInstance()->getTcpClient()->recv(dimToRecvChar,50);

    nrOfBytes = APPClient::getInstance()->getTcpClient()->send("ACCEPT",strlen("ACCEPT"));
    int dimToRecvInt;
    dimToRecvInt = atoi(dimToRecvChar);
    uint8_t* bufferToRecv=(uint8_t*)malloc(dimToRecvInt);
    memset(bufferToRecv,0,dimToRecvInt);

    uint8_t* bufferInter=(uint8_t*)malloc(static_cast<int>(40960));
    memset(bufferInter,0,40960);


    int bytesThatHasBeenSent=0;
    int i=1;
    std::string finalBuffer;
    for(i=1;i<=(dimToRecvInt/40960)+1;i++){
        if(dimToRecvInt - bytesThatHasBeenSent < 40960){
            nrOfBytes = APPClient::getInstance()->getTcpClient()->recv((char*)bufferInter,dimToRecvInt - bytesThatHasBeenSent);
        }
        else{
            nrOfBytes = APPClient::getInstance()->getTcpClient()->recv((char*)bufferInter,40960);
        }
        bytesThatHasBeenSent+=nrOfBytes;
        std::cout<<bytesThatHasBeenSent<<std::endl;
        memcpy(bufferToRecv+(i-1)*40960,bufferInter,nrOfBytes);
        memset(bufferInter,0,40960);

        nrOfBytes = APPClient::getInstance()->getTcpClient()->send("ACCEPT",strlen("ACCEPT"));
    }

    QImage image;
    QByteArray byteArray = QByteArray::fromRawData(reinterpret_cast<const char*>(bufferToRecv), dimToRecvInt);
    image.loadFromData(byteArray,"PNG");
    QPixmap pixmap = QPixmap::fromImage(image);
    if (image.isNull()) {
        qDebug() << "Imaginea este goală!";
    }


    return pixmap;

}
