#include "LogInRequest.h"

LogInRequest::LogInRequest() {this->payload="1";}

void LogInRequest::GetData(std::string email, std::string password){

    this->payload += email;
    this->payload += '#';
    this->payload += password;
}

LogInRequest* LogInRequest::getInstance() {
    if (instance != nullptr)
        return instance;
    instance = new LogInRequest();
    return instance;

}
