#include "CardRequest.h"

CardRequest::CardRequest() {}

bool CardRequest::RecvCard(){


    this->Answer();
    APPClient::getInstance()->getTcpClient()->send("ACK", strlen("ACK"));
    if(strcmp(this->answer,"NULL")==0){
        return false;
    }
    else{
        this->card=new Card();
        //nr
        this->Answer();
        APPClient::getInstance()->getTcpClient()->send("ACK", strlen("ACK"));
        std::cout<<this->message<<" ";

        this->card->Number=this->answer;


        //owner
        this->Answer();
        APPClient::getInstance()->getTcpClient()->send("ACK", strlen("ACK"));
         std::cout<<this->message<<" ";
         this->card->Nume_Detinator=this->answer;


        //data
        this->Answer();
        APPClient::getInstance()->getTcpClient()->send("ACK", strlen("ACK"));
         std::cout<<this->message<<" ";
        this->card->Data=this->answer;


        //cvc
        this->Answer();
        APPClient::getInstance()->getTcpClient()->send("ACK", strlen("ACK"));
         std::cout<<this->message<<" ";
        this->card->cvc=this->answer;

        return true;
    }
}

void CardRequest::GetData(Card*card){
    this->card=card;
}
Card*CardRequest::GetCardData(){
    return this->card;
}
void  CardRequest::SendCard(){

    this->message="8";
    this->Request();


    this->message=card->Number;
    this->Request();

    this->message=card->Nume_Detinator;
    this->Request();

    this->message=card->Data;
    this->Request();

    this->message=card->cvc;
    this->Request();

}

