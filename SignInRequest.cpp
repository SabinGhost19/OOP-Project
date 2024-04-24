#include "SignInRequest.h"

//SignInRequest* SignInRequest::instance = nullptr;

SignInRequest::SignInRequest() {

}


void SignInRequest::GetData(std::vector<std::string> data_block){

    for (int i = 0; i < static_cast<int>(data_block.size()); i++) {
    this->payload += data_block[i];
    this->payload += "#";
    }
}

SignInRequest* SignInRequest::getInstance() {
    if (instance != nullptr)
        return instance;
    instance = new SignInRequest();
    return instance;

}




