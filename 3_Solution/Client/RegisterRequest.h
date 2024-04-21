#ifndef REGISTERREQUEST_H
#define REGISTERREQUEST_H

#include "iRequest.h"

class RegisterRequest : public iRequest
{
public:

    std::string payload;
    int answer = 0;

    RegisterRequest();
    virtual void Request();
    virtual std::string Answer();
};

#endif // REGISTERREQUEST_H
