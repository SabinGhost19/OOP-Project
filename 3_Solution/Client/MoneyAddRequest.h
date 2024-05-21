#ifndef MONEYADDREQUEST_H
#define MONEYADDREQUEST_H

#include "DataRequest.h"

class MoneyAddRequest : public DataRequest
{
    std::string money;
public:
    MoneyAddRequest();
    void setValue(std::string);
    void SendMoneyReq();
};

#endif // MONEYADDREQUEST_H
