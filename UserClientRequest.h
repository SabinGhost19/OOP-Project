#ifndef USERCLIENTREQUEST_H
#define USERCLIENTREQUEST_H
#include"UserRequest.h"

class UserClientRequest : public UserRequest
{
public:
    UserClientRequest();
    UserClientRequest(std::string);

    virtual bool Request();
    virtual bool Answer();
};

#endif // USERCLIENTREQUEST_H
