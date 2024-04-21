#include "LogInRequest.h"

LogInRequest::LogInRequest() {}

LogInRequest::LogInRequest(std::string email, std::string password)
{

    this->payload += email;
    this->payload += '#';
    this->payload += password;

}
