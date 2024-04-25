#include "ImageRequest.h"
#include <qdebug.h>
#include <QFile>

ImageRequest::ImageRequest() {strcpy(this->answer,"");this->message="";}

ImageRequest*ImageRequest::getInstance(){
    ImageRequest::index_imagine++;
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










//to be developed---------------------------------------
void ImageRequest::saveByteArrayAsPng(const QByteArray &byteArray) {

    QString fileName = "image";
    fileName+=std::to_string(this->index_imagine);
    fileName+=".png";

    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly)) {
        qDebug() << "Failed to open file for writing:" << file.errorString();
        return;
    }

    if (file.write(byteArray) == -1) {
        qDebug() << "Failed to write to file:" << file.errorString();
        return;
    }
    file.close();

    qDebug() << "Byte array saved as PNG:" << fileName;
}
//to be developed-----------------------------------------------










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

    //to be tested
    //this->saveByteArrayAsPng(byteArray);


    image.loadFromData(byteArray,"PNG");
    QPixmap pixmap = QPixmap::fromImage(image);
    if (image.isNull()) {
        qDebug() << "Imaginea este goală!";
    }


    return pixmap;

}
