#include "SignInRequest.h"

//SignInRequest* SignInRequest::instance = nullptr;

SignInRequest::SignInRequest() {

}

bool SignInRequest::SendAllData(){

    for(int i=0;i<static_cast<int>(this->data_block.size());i++){

        this->payload=this->data_block[i];
        std::cout<<"Payload:  "<<this->payload<<std::endl;
        if(!this->Request()){
            std::cout<<"CRASHEDDDDDD!!!!!!!!!!!"<<std::endl;
            return false;
        }
    }
    return true;

}
void SignInRequest::GetData(std::vector<std::string> data_block){

    this->data_block=data_block;

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




