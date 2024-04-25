#include "userRequest.h"
#include"APPClient.h"

UserRequest::UserRequest() {}

UserRequest::UserRequest(std::string id_str){this->ID=id_str;}

bool UserRequest::Request()
{

    APPClient::getInstance()->getTcpClient()->send(this->ID.c_str(), this->ID.length());
    if(this->Answer()){return true;}else{return false;}
}


std::string UserRequest::GetCredentials(){this->answer;}


