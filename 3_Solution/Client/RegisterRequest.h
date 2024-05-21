#ifndef REGISTERREQUEST_H
#define REGISTERREQUEST_H

#include "iRequest.h"

class RegisterRequest : public iRequest
{
public:

    std::string payload;
    char answer[1024];

    RegisterRequest();
    virtual bool Request();
    virtual bool Answer();
    char*GetAnswer();
};

#endif // REGISTERREQUEST_H
