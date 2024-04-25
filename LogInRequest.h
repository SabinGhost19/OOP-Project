#ifndef LOGINREQUEST_H
#define LOGINREQUEST_H
#include"RegisterRequest.h"
class LogInRequest :public RegisterRequest
{
public:

    void GetData(std::string email,std::string password);
    static LogInRequest*getInstance();
private:

    inline static LogInRequest*instance=nullptr;
    LogInRequest();

};

#endif // LOGINREQUEST_H
