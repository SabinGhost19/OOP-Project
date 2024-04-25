#ifndef DATAREQUEST_H
#define DATAREQUEST_H

#include "iRequest.h"
#include"APPClient.h"

class DataRequest : public iRequest
{

public:

    DataRequest();
    std::string message;
    virtual bool Request();
    virtual bool Answer();
};

#endif // DATAREQUEST_H
