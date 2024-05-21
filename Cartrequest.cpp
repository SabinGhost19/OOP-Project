#include "Cartrequest.h"
#include"APPClient.h"

CartRequest::CartRequest() {}


void CartRequest::SetData(std::vector<std::pair<std::string, std::string>>data){
    this->data_to_send=data;
}

bool CartRequest::SendCart(){
    int flag=0;
    int size=static_cast<int>(this->data_to_send.size());
    std::cout<<"Marimea: "<<size<<std::endl;
    this->message="7";
    this->Request();

    for(int i=0;i<size;i++){
        this->message=this->data_to_send[i].first;
        this->Request();
        this->message=this->data_to_send[i].second;
        this->Request();
    }

    this->Answer();
    if(strcmp(this->answer,"ERROR")==0){
        //fail
        flag=1;

    }

    APPClient::getInstance()->getTcpClient()->send("ACK", strlen("ACK"));
    if(flag==1){
        return false;
    }else{return true;}
}
