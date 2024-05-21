#ifndef USERCLIENTREQUEST_H
#define USERCLIENTREQUEST_H
#include"UserRequest.h"

class UserClientRequest : public UserRequest
{
public:
    UserClientRequest();


    virtual bool Request();

};

#endif // USERCLIENTREQUEST_H
