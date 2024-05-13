#ifndef USERREQUEST_H
#define USERREQUEST_H

#include "iRequest.h"

class UserRequest : public iRequest
{
protected:
    std::string allcredentials=".";
    std::vector<std::string>vec;
    int size=0;
public:
    std::string ID="U";
    UserRequest();
    UserRequest(std::string);
    void setCredentialSize(int);
    virtual bool Request();
    virtual bool Answer();
    std::vector<std::string> GetCredentials();
    void Clear();
};

#endif // USERREQUEST_H
