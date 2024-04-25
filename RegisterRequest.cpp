#include "RegisterRequest.h"
#include"APPClient.h"


RegisterRequest::RegisterRequest()
{

}

char*RegisterRequest::GetAnswer(){return this->answer;}

bool RegisterRequest::Request()
{
    APPClient::getInstance()->getTcpClient()->send(payload.c_str(), payload.length());
    if(this->Answer()){return true;}else{return false;}
}

bool RegisterRequest::Answer()
{

    int recv_bytes=0;
    while(recv_bytes==0)
    {
        recv_bytes =APPClient::getInstance()->getTcpClient()->recv(this->answer, 1024);
        answer[recv_bytes] = '\0';
    }
    if(strcmp(this->answer,"CRASHED")!=0){

        std::cout<<"Sign In SUCCESFULL  !!!!!!!!!!!!!!!!";

        return true;

    }else{
         std::cout<<"Sign In CRASHED  ........................";
         return false;
    }

}



