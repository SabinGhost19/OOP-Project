#include "ForumBuilder.h"
#include "ForumCategory.h"
#include "APPServer.h"

ForumBuilder::ForumBuilder()
{
	this->forumToBuild = new Forum;
}

Forum* ForumBuilder::buildForum()
{
	vector<ForumCategory*> forumCategories = APPServer::getInstance()->getBDComm()->getAllForumCategories();
	for (auto iterator : forumCategories)
		iterator->setForumPosts(APPServer::getInstance()->getBDComm()->getAllPostsForCategory(iterator->getForumCatID()));
	this->forumToBuild->setAllCategories(forumCategories);
	return this->forumToBuild;
}

ForumBuilder::~ForumBuilder()
{
	this->forumToBuild = nullptr;
}
