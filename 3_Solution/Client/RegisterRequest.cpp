#include "RegisterRequest.h"


RegisterRequest::RegisterRequest()
{

}

void RegisterRequest::Request()
{
    //this->answer=APPClient::getInstance()->getTcpClient()->send(buffer.c_str(), buffer.length());

}

std::string RegisterRequest::Answer()
{
    if (this->answer == 1) {

        return "ok";

    }
    else {

    }
}



