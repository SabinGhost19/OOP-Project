#include "LogInRequest.h"
#include "APPClient.h"

LogInRequest::LogInRequest() {}

void LogInRequest::GetData(std::string email, std::string password){

    this->payload += email;
    this->payload += '#';
    this->payload += password;
}
void LogInRequest::SetMssg(std::string mssg){
    this->payload=mssg;
}
LogInRequest* LogInRequest::getInstance() {
    if (instance != nullptr)
        return instance;
    instance = new LogInRequest();
    return instance;

}

bool LogInRequest::Request()
{
    APPClient::getInstance()->getTcpClient()->send(payload.c_str(), payload.length());
    if(this->Answer()){return true;}else{return false;}
}

bool LogInRequest::Answer()
{

    int recv_bytes=0;
    while(recv_bytes==0)
    {
        recv_bytes =APPClient::getInstance()->getTcpClient()->recv(this->answer, 1024);
        answer[recv_bytes] = '\0';
    }
     if(strcmp(this->answer,"FALSE")!=0){

        std::cout<<"LOG IS In SUCCESFULL  !!!!!!!!!!!!!!!!";

        return true;

    }else{
        std::cout<<"LOG IN CRASHED or the cont doesnt exist  ........................";
        return false;
    }

}
