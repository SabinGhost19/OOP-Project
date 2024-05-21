#ifndef COMMENTSREQUEST_H
#define COMMENTSREQUEST_H
#include<vector>
#include "DataRequest.h"
#include <utility>

class CommentsRequest : public DataRequest
{

    inline static  CommentsRequest *instance=nullptr;
    std::vector<std::pair<std::string, std::string>> comments;
    std::string index;
    virtual bool Answer();
    int point_phase=-1;
    std::vector<std::string>note;

public:

    std::vector<std::pair<std::string, std::string>> GetComments();
    static CommentsRequest*getInstance();
    CommentsRequest();
    void SendComment(std::string review,std::string nota);
    int Size();
    void SetIndex(std::string);

};


#endif // COMMENTSREQUEST_H
