#include "ForumRequest.h"
#include "APPServer.h"
#include "ForumCategory.h"
#include "ForumPost.h"
#include <string.h>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

bool ForumRequest::receiveRequest()
{
	int recvBytes = 0, sentBytes = 0;
	char forumCategoryIDChar[10] = "";
	char ackBuffer[10] = "";
	recvBytes = APPServer::getInstance()->getTcpServer()->recv(forumCategoryIDChar, sizeof(forumCategoryIDChar));
	sentBytes = APPServer::getInstance()->getTcpServer()->send("ACK", strlen("ACK"));
	cout << "Client is trying to get posts for forum category: " << forumCategoryIDChar << endl;
	int forumCategoryID = atoi(forumCategoryIDChar);
	vector<ForumCategory*> forumCategories = APPServer::getInstance()->getForum()->getForumCategories();
	int nrOfPosts = 0;
	for (auto iterator : forumCategories)
	{
		if (iterator->getForumCatID() == forumCategoryID)
		{
			vector<ForumPost*> postsFromCategory = iterator->getAllPosts();
			nrOfPosts = postsFromCategory.size();
			string nrOfPostsStr = std::to_string(nrOfPosts);
			sentBytes = APPServer::getInstance()->getTcpServer()->send(nrOfPostsStr.c_str(), nrOfPostsStr.size());
			recvBytes = APPServer::getInstance()->getTcpServer()->recv(ackBuffer, sizeof(ackBuffer));
			for (auto iteratorPosts : postsFromCategory)
			{
				sentBytes = APPServer::getInstance()->getTcpServer()->send(iteratorPosts->getUsername(), strlen(iteratorPosts->getUsername()));
				recvBytes = APPServer::getInstance()->getTcpServer()->recv(ackBuffer, sizeof(ackBuffer));			
				sentBytes = APPServer::getInstance()->getTcpServer()->send(iteratorPosts->getPost(),strlen(iteratorPosts->getPost()));
				recvBytes = APPServer::getInstance()->getTcpServer()->recv(ackBuffer, sizeof(ackBuffer));
			}
			break;
		}
	}
	cout << "A number of: "<< nrOfPosts << " posts have been sent succesffully" << endl;
    return true;
}

bool ForumRequest::sendAnswear()
{
    return true;
}
