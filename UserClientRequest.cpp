#include "UserClientRequest.h"
#include"APPClient.h"

UserClientRequest::UserClientRequest() {}

UserClientRequest::UserClientRequest(std::string ID):UserRequest(ID) {}

bool UserClientRequest::Request()
{
    //precizare id!!!!!!!!!!!!
    this->ID+="C";//de la client
    APPClient::getInstance()->getTcpClient()->send(this->ID.c_str(), this->ID.length());
    if(this->Answer()){return true;}else{return false;}
}


bool UserClientRequest::Answer()
{
    //FORR WHILE?????
    int recv_bytes=0;

    recv_bytes =APPClient::getInstance()->getTcpClient()->recv(this->answer, 1024);
    answer[recv_bytes] = '\0';

    if(strcmp(this->answer,"CRASHED")==0){
        std::cout<<"Answer CRASHED  ........................";
        return false;
    }else{
        std::cout<<"Answer from data succesfull  !!!!!!!!!!!!!!!!";
        return true;
    }

}
