#ifndef SIGNINREQUEST_H
#define SIGNINREQUEST_H

#include "RegisterRequest.h"

class SignInRequest : public RegisterRequest
{
public:

    static SignInRequest*getInstance();

    virtual void GetData(std::vector<std::string> data_block);

private:

    inline static SignInRequest *instance=nullptr;

    SignInRequest();
};

#endif // SIGNINREQUEST_H

