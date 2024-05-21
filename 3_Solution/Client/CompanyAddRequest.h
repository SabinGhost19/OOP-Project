#ifndef COMPANYADDREQUEST_H
#define COMPANYADDREQUEST_H
#include"DataRequest.h"
#include<iostream>
#include<string.h>
#include<QPixmap>
#include<QByteArray>

class CompanyAddRequest : public DataRequest
{
public:
    void sendImage(std::string filename);
    void sendText(std::string text);
    CompanyAddRequest();
};

#endif // COMPANYADDREQUEST_H
