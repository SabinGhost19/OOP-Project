#include "CommentsRequest.h"
#include <sstream>

CommentsRequest::CommentsRequest() {

    this->message="";
    this->index=0;
}

CommentsRequest*CommentsRequest::getInstance(){

    if (instance != nullptr)
        return instance;
    instance = new CommentsRequest();
    return instance;
}

void CommentsRequest::SetIndex(int index_p){
    this->index=index_p;
}

int CommentsRequest::Size(){return static_cast<int>(this->comments.size());}

std::pair<std::string, std::string> CommentsRequest::GetComments(){
    // std::string indexValue = std::to_string(index);
    // this->message="4#";
    // this->message+=indexValue;
    // this->Request();
    // this->answer;
    //this->point_phase++;
    //return this->comments[point_phase];

    //verify??!?!?!?!?!?!?
    std::pair<std::string, std::string> myPair("TITLUUUUUU VERIFYYYY", "DESCRIPTION VERIFYYYY");
    return myPair;
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
    std::stringstream ss(this->answer);
    std::string token;

    while (std::getline(ss, token, '#')) {
        std::string titlu = token;
        if (std::getline(ss, token, '#')) {
            std::string descriere = token;
            this->comments.push_back(std::make_pair(titlu, descriere));
        } else {
            break;
        }
    }

}
