#include "SignInRequest.h"
#include<iostream>
#include<string.h>
#include<QMessageBox>
//SignInRequest* SignInRequest::instance = nullptr;
#include"APPClient.h"

SignInRequest::SignInRequest() {

}

bool SignInRequest::SendAllData(){

    for(int i=0;i<static_cast<int>(this->data_block.size());i++){

        this->payload=this->data_block[i];
        std::cout<<"Payload:  "<<this->payload<<std::endl;
        if(i==4){
            this->Answer();
            if(strcmp(this->answer,"FALSE")==0){
                QMessageBox::warning(nullptr, "Eroare", "Emailul este deja folosit, incearca altul");
                this->payload="ACK";
                APPClient::getInstance()->getTcpClient()->send(payload.c_str(), payload.length());
                return  false;
            }
            this->payload="ACK";
            APPClient::getInstance()->getTcpClient()->send(payload.c_str(), payload.length());
        }
        this->payload=this->data_block[i];
        if(!this->Request()){
            std::cout<<"CRASHEDDDDDD!!!!!!!!!!!"<<std::endl;
            return false;
        }
    }
    return true;

}

void SignInRequest::SetFlag(int param_flag){
    this->flag=param_flag;
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




