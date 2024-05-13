#include "CommentsRequest.h"
#include <sstream>

CommentsRequest::CommentsRequest() {

    this->message="";

}

CommentsRequest*CommentsRequest::getInstance(){

    if (instance != nullptr)
        return instance;
    instance = new CommentsRequest();
    return instance;
}

void CommentsRequest::SetIndex(std::string index_p){
    this->index=index_p;
}
void CommentsRequest::SendComment(std::string review,std::string nota){


    this->message="4";
    this->Request();
    this->message="2";
    this->Request();
    this->message=this->index;
    this->Request();

    this->message=nota;
    this->Request();
    this->message=review;
    this->Request();

}
int CommentsRequest::Size(){return static_cast<int>(this->comments.size());}

std::vector<std::pair<std::string, std::string>> CommentsRequest::GetComments(){
    //std::string indexValue = std::to_string(index);
    this->message="4";
    this->Request();
    this->message="1";
    this->Request();
    this->message=this->index;
    this->Request();

    this->Answer();
    int size=atoi(this->answer);
    APPClient::getInstance()->getTcpClient()->send("ACK", strlen("ACK"));

    std::string nota;
    std::string nume;
    std::string comment;
    QString str;
    for(int i=0;i<size;i++){
         this->Answer();
          str = QString::fromUtf8(this->answer);
         nume=str.toStdString();
         APPClient::getInstance()->getTcpClient()->send("ACK", strlen("ACK"));

        this->Answer();
        str = QString::fromUtf8(this->answer);
        nota=str.toStdString();
        APPClient::getInstance()->getTcpClient()->send("ACK", strlen("ACK"));

        this->Answer();
        str = QString::fromUtf8(this->answer);
        comment=str.toStdString();
        APPClient::getInstance()->getTcpClient()->send("ACK", strlen("ACK"));

        std::pair<std::string, std::string> pairOfStrings(nume, comment);

        this->comments.push_back(pairOfStrings);
        this->note.push_back(nota);
    }


    //this->answer;
    //this->point_phase++;
   // return this->comments[point_phase];

    //verify??!?!?!?!?!?!?

    return this->comments;
}

bool CommentsRequest::Answer()
{

    int recv_bytes=0;

    recv_bytes =APPClient::getInstance()->getTcpClient()->recv(this->answer, 1024);
    answer[recv_bytes] = '\0';

    if(strcmp(this->answer,"CRASHED")==0){
        std::cout<<"Answer CRASHED  ........................";
        return false;
    }else{
        std::cout<<"Answer from data succesfull  !!!!!!!!!!!!!!!!";
        return true;
    }


    //adaugare in vectro
    // std::stringstream ss(this->answer);
    // std::string token;

    // while (std::getline(ss, token, '#')) {
    //     std::string titlu = token;
    //     if (std::getline(ss, token, '#')) {
    //         std::string descriere = token;
    //         this->comments.push_back(std::make_pair(titlu, descriere));
    //     } else {
    //         break;
    //     }
    // }

}
