#ifndef DESCRIPTIONREQUEST_H
#define DESCRIPTIONREQUEST_H
#include<iostream>
#include<string.h>
#include"DataRequest.h"

class DescriptionRequest:public DataRequest
{
    inline static  DescriptionRequest *instance=nullptr;
    std::string description;
    int index=0;
public:
    DescriptionRequest();
    void SetIndex(int);
    static DescriptionRequest*getInstance();
    std::string GetDescription();

};

#endif // DESCRIPTIONREQUEST_H
