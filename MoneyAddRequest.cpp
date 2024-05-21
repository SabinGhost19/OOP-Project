#include "MoneyAddRequest.h"

MoneyAddRequest::MoneyAddRequest() {}

void MoneyAddRequest::setValue(std::string money_param){
    this->money=money_param;
}
void MoneyAddRequest::SendMoneyReq(){

    this->message="10";
    this->Request();

    this->message=this->money;
    this->Request();
}
