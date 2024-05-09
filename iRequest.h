#ifndef IREQUEST_H
#define IREQUEST_H
#include<iostream>
#include<vector>

class iRequest
{
public:
    iRequest();

    virtual bool Request() = 0;
    virtual bool Answer() = 0;

    char answer[1024];


};

#endif // IREQUEST_H
