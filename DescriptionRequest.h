#ifndef DESCRIPTIONREQUEST_H
#define DESCRIPTIONREQUEST_H
#include<iostream>
#include<string.h>
#include"DataRequest.h"

class DescriptionRequest:public DataRequest
{
    inline static  DescriptionRequest *instance=nullptr;
    std::string description;
    std::string index;
public:
    DescriptionRequest();
    void SetIndex(std::string);
    static DescriptionRequest*getInstance();
    std::string GetDescription();

};

#endif // DESCRIPTIONREQUEST_H
