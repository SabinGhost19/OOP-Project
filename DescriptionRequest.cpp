#include "DescriptionRequest.h"

DescriptionRequest::DescriptionRequest() {
    this->description="";
    this->message="";
    this->index=0;
}

DescriptionRequest*DescriptionRequest::getInstance(){

    if (instance != nullptr)
        return instance;
    instance = new DescriptionRequest();
    return instance;
}
void DescriptionRequest::SetIndex(int index_p){
    this->index=index_p;
}

std::string DescriptionRequest::GetDescription(){

    // std::string indexValue = std::to_string(index);
    // this->message="3#";
    // this->message+=indexValue;
    // this->Request();
    // return this->answer;
    if(index%2==0){return "raspuns 1";}else{return "raspunsssssssss 2";}
}
