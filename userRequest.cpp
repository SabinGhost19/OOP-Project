#include "userRequest.h"
#include"APPClient.h"

UserRequest::UserRequest() {}

UserRequest::UserRequest(std::string id_str){this->ID+=id_str;}

void UserRequest::setCredentialSize(int size_param){
    this->size=size_param;
}
void UserRequest::Clear(){
    this->vec.clear();
}
bool UserRequest::Request()
{

    for(int i=0;i<this->size;i++){
        if(this->Answer()){

            QString str = QString::fromUtf8(this->answer);
            this->vec.push_back(str.toStdString());
            //this->allcredentials+=this->answer;
            //this->allcredentials+="#";
            APPClient::getInstance()->getTcpClient()->send("ACK", strlen("ACK"));
        }else{
            std::cout<<"receiving all the credentials failed at iteration :"<<i<<std::endl;
            return false;
        }

    }



    return true;
}

bool UserRequest::Answer()
{
    //FORR WHILE?????
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

}
std::vector<std::string> UserRequest::GetCredentials(){return this->vec;}


