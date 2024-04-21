#ifndef LOGINREQUEST_H
#define LOGINREQUEST_H
#include"RegisterRequest.h"
class LogInRequest :public RegisterRequest
{
public:
    LogInRequest();
    LogInRequest(std::string email,std::string password);

};

#endif // LOGINREQUEST_H
