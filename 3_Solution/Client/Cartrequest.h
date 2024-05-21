#ifndef CARTREQUEST_H
#define CARTREQUEST_H

#include "DataRequest.h"

class CartRequest : public DataRequest
{

    std::vector<std::pair<std::string, std::string>>data_to_send;
public:
    CartRequest();
    void SetData(std::vector<std::pair<std::string, std::string>>data);
    bool SendCart();
};

#endif // CARTREQUEST_H
