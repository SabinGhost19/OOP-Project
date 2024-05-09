#ifndef COMMENTSREQUEST_H
#define COMMENTSREQUEST_H
#include<vector>
#include "DataRequest.h"
#include <utility>

class CommentsRequest : public DataRequest
{

    inline static  CommentsRequest *instance=nullptr;
    std::vector<std::pair<std::string, std::string>> comments;
    int index=0;
    virtual bool Answer();
    int point_phase=-1;

public:

    std::pair<std::string, std::string> GetComments();
    static CommentsRequest*getInstance();
    CommentsRequest();
    int Size();
    void SetIndex(int);

};


#endif // COMMENTSREQUEST_H
