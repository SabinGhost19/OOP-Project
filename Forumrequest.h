#ifndef FORUMREQUEST_H
#define FORUMREQUEST_H

#include "DataRequest.h"
#include <vector>



//periferice 1
//comunicatii 2
//componente 3
//gaming 4
//software 5
//reteliosta 6
//electrocasnice 7
//intrebari/opiiisugfestii 8
//fun 9


class ForumRequest : public DataRequest
{
public:

    std::vector<std::pair<std::string,std::string>>forum_item;
    int index_type=0;

    ForumRequest();

    std::vector<std::pair<std::string, std::string>> RequestForumPage();
    void SendForumComment(int index,std::string comment);
    void setIndex(int index);
    int  GetSize();
};

#endif // FORUMREQUEST_H
