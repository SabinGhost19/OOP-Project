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

void ImageRequest:: Construct_MoreImages(int id){

    this->message="6";
    this->Request();

    QString str = QString::number(id);
    this->message=str.toStdString();
    this->Request();

    this->Answer();
    int size=atoi(this->answer);
    APPClient::getInstance()->getTcpClient()->send("ACK", strlen("ACK"));

    for(int i=0;i<size;i++){
        QPixmap pixmap=ReceiveImages();
        this->new_images.push_back(pixmap);
    }

}
std::vector<QPixmap> ImageRequest::GetNewImages()const{
    return this->new_images;
}
int ImageRequest::FindSize(){

    //this->message="3";
    //if(this->Request()){
        DataRequest::Answer();
        APPClient::getInstance()->getTcpClient()->send("ACK", strlen("ACK"));
        return atoi(this->answer);
    //}
}
void  ImageRequest::Construct_Images(){

    DataRequest::Answer();
    APPClient::getInstance()->getTcpClient()->send("ACK", strlen("ACK"));
    this->actual_title=this->answer;
    DataRequest::Answer();
    APPClient::getInstance()->getTcpClient()->send("ACK", strlen("ACK"));
    this->price=this->answer;
    DataRequest::Answer();
    APPClient::getInstance()->getTcpClient()->send("ACK", strlen("ACK"));
    QString qstr = QString::fromUtf8(this->answer);
    this->ID=qstr.toStdString();
    std::cout<<this->ID<<std::endl;
    //this->actual_pixmap=ReceiveImages();

}
std::string  ImageRequest::getTtile(){
    return this->actual_title;
}
std::string ImageRequest::GetPrice(){
    return this->price;
}
std::string ImageRequest::GetID(){
    return this->ID;
}
std::string ImageRequest::getCantitate(){
    return this->cantitate;
}
QPixmap  ImageRequest::getImage(){
    return this->actual_pixmap;
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

    FILE*f=fopen("C:\\Users\\sabin\\Desktop\\imagine.png","wb");
    fwrite(bufferToRecv,1,dimToRecvInt,f);

    QImage image;
    QByteArray byteArray = QByteArray::fromRawData(reinterpret_cast<const char*>(bufferToRecv), dimToRecvInt);
    image.loadFromData(byteArray,"PNG");



   QPixmap pixmap=QPixmap::fromImage(image);

    if (image.isNull()) {
        qDebug() << "Imaginea este goală!";
    }


    return pixmap;

}
