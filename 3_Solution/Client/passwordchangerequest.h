#ifndef PASSWORDCHANGEREQUEST_H
#define PASSWORDCHANGEREQUEST_H

#include "DataRequest.h"

class PasswordChangeRequest : public DataRequest
{
    std::string new_pass;
public:
    PasswordChangeRequest();
    void SetPass(std::string);
    void SendPass();

};

#endif // PASSWORDCHANGEREQUEST_H
