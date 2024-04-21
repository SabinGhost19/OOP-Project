#ifndef SIGNINREQUEST_H
#define SIGNINREQUEST_H

#include "RegisterRequest.h"

class SignInRequest : public RegisterRequest
{
public:

    SignInRequest(std::vector<std::string>data_block);
    SignInRequest();
};

#endif // SIGNINREQUEST_H
