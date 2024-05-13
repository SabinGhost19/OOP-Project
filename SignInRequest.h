#ifndef SIGNINREQUEST_H
#define SIGNINREQUEST_H

#include "RegisterRequest.h"

class SignInRequest : public RegisterRequest
{
public:

    static SignInRequest*getInstance();
    int flag=0;

    virtual void GetData(std::vector<std::string> data_block);
    bool SendAllData();

private:

    std::vector<std::string> data_block;

    inline static SignInRequest *instance=nullptr;
    void SetFlag(int param_flag);

    SignInRequest();
};

#endif // SIGNINREQUEST_H

