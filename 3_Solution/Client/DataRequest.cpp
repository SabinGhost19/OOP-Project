#include "DataRequest.h"

DataRequest::DataRequest() {}

bool DataRequest::Request()
{
    APPClient::getInstance()->getTcpClient()->send(this->message.c_str(), this->message.length());
    if(this->Answer()){return true;}else{return false;}
}

bool DataRequest::Answer()
{

    int recv_bytes=0;

    recv_bytes =APPClient::getInstance()->getTcpClient()->recv(this->answer, 1024);
    answer[recv_bytes] = '\0';
    std::cout<<std::endl<<std::endl<<answer<<std::endl<<std::endl;

    if(strcmp(this->answer,"CRASHED")==0){
        std::cout<<"Answer CRASHED  ........................";
        return false;
    }else{
        std::cout<<"Answer from data succesfull  !!!!!!!!!!!!!!!!";
         return true;
    }

}
