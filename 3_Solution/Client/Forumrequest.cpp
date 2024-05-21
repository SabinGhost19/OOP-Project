#include "Forumrequest.h"

ForumRequest::ForumRequest() {}

void ForumRequest::SendForumComment(int index,std::string comment){


    QString str = QString::number(index);

    this->message="14";
    this->Request();

    this->message=str.toStdString();
    this->Request();

    this->message=comment;
    this->Request();

}


 std::vector<std::pair<std::string, std::string>> ForumRequest::RequestForumPage(){

    this->forum_item.clear();

    QString str = QString::number(this->index_type);

    this->message="13";
    this->Request();

    this->message=str.toStdString();
    this->Request();

    DataRequest::Answer();
    APPClient::getInstance()->getTcpClient()->send("ACK", strlen("ACK"));
    int size= atoi(this->answer);


    std::string nume;
    std::string comment;

    for(int i=0;i<size;i++){

        this->Answer();
        str = QString::fromUtf8(this->answer);
        nume=str.toStdString();
        APPClient::getInstance()->getTcpClient()->send("ACK", strlen("ACK"));


        this->Answer();
        str = QString::fromUtf8(this->answer);
        comment=str.toStdString();
        APPClient::getInstance()->getTcpClient()->send("ACK", strlen("ACK"));

        std::pair<std::string, std::string> pairOfStrings(nume, comment);

        this->forum_item.push_back(pairOfStrings);
    }

    return this->forum_item;
}
int  ForumRequest::GetSize(){

    DataRequest::Answer();
    APPClient::getInstance()->getTcpClient()->send("ACK", strlen("ACK"));
    return atoi(this->answer);
}
void ForumRequest::setIndex(int index){

    this->index_type=index;

}
