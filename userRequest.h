#ifndef USERREQUEST_H
#define USERREQUEST_H

#include "iRequest.h"

class UserRequest : public iRequest
{
private:

public:
    std::string ID;
    UserRequest();
    UserRequest(std::string);

    virtual bool Request();
    std::string GetCredentials();
};

#endif // USERREQUEST_H
