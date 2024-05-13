#include "DescriptionRequest.h"

DescriptionRequest::DescriptionRequest() {
    this->description="";
    this->message="";

}

DescriptionRequest*DescriptionRequest::getInstance(){

    if (instance != nullptr)
        return instance;
    instance = new DescriptionRequest();
    return instance;
}
void DescriptionRequest::SetIndex(std::string index_p){
    this->index=index_p;
}

std::string DescriptionRequest::GetDescription(){
     QString str;

      this->message="5";

      this->Request();
      std::cout<<std::endl<<this->index<<std::endl<<std::endl;

      this->message=this->index;
      this->Request();

      this->Answer();
      str = QString::fromUtf8(this->answer);
      std::string nume=str.toStdString();
      APPClient::getInstance()->getTcpClient()->send("ACK", strlen("ACK"));


      this->Answer();
      str = QString::fromUtf8(this->answer);
      std::string descriere=str.toStdString();
      APPClient::getInstance()->getTcpClient()->send("ACK", strlen("ACK"));
      std::cout<<descriere<<std::endl;


      return descriere;
}
