#include "UserClientRequest.h"
#include"APPClient.h"

UserClientRequest::UserClientRequest() {}



bool UserClientRequest::Request()
{

    this->ID+="C";
    APPClient::getInstance()->getTcpClient()->send(this->ID.c_str(), this->ID.length());
    for(int i=0;i<24;i++){
        if(this->Answer()){
            this->allcredentials+=this->answer;
            this->allcredentials+="#";
        }else{
            std::cout<<"receiving all the credentials failed at iteration :"<<i<<std::endl;
            return false;
        }

    }
    return true;
}



