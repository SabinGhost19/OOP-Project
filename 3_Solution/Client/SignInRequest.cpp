#include "SignInRequest.h"

SignInRequest::SignInRequest() {}

SignInRequest::SignInRequest(std::vector<std::string> data_block)
{

    for (int i = 0; i < static_cast<int>(data_block.size()); i++) {
        this->payload += data_block[i];
        this->payload += "#";
    }

}


