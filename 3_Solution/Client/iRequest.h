#ifndef IREQUEST_H
#define IREQUEST_H
#include<iostream>
#include<vector>

class iRequest
{
public:
    iRequest();

    virtual void Request() = 0;
    virtual std::string Answer() = 0;
};

#endif // IREQUEST_H
