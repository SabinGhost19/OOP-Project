#ifndef CARDREQUEST_H
#define CARDREQUEST_H

#include "DataRequest.h"
#include"userClient.h"

class CardRequest : public DataRequest
{
    Card*card=nullptr;
public:
    CardRequest();
    bool RecvCard();
    void GetData(Card*card);
    void SendCard();
    Card*GetCardData();

};




#endif // CARDREQUEST_H
