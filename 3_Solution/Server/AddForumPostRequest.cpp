#include "AddForumPostRequest.h"
#include <iostream>
#include "ForumPost.h"
#include "APPServer.h"

using namespace std;

bool AddForumPostRequest::receiveRequest()
{
    cout << "Client is trying to add a new post in forum" << endl;
    ForumPost* newPost = new ForumPost;

    int recvBytes = 0, sentBytes = 0;
    char forumCategoryIDChar[10] = "", post[3000] = "";
    char ackBuffer[10] = "";
    recvBytes = APPServer::getInstance()->getTcpServer()->recv(forumCategoryIDChar, sizeof(forumCategoryIDChar));
    sentBytes = APPServer::getInstance()->getTcpServer()->send("ACK", strlen("ACK"));
    int forumCategoryID = atoi(forumCategoryIDChar);
    recvBytes = APPServer::getInstance()->getTcpServer()->recv(post, sizeof(post));
    sentBytes = APPServer::getInstance()->getTcpServer()->send("ACK", strlen("ACK"));
    APPServer::getInstance()->getBDComm()->addPost(forumCategoryID, APPServer::getInstance()->getManagedClient()->getName(), post);
    newPost->setPost(post);
    newPost->setUsername(APPServer::getInstance()->getManagedClient()->getName());
    for (auto iterator : APPServer::getInstance()->getForum()->getForumCategories())
        if (iterator->getForumCatID() == forumCategoryID)
        {
            iterator->addForumPost(newPost);
            break;
        }
    cout << "The post has been added succesffully!" << endl;
    return true;
}

bool AddForumPostRequest::sendAnswear()
{
    return true;
}
