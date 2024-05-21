#define _CRT_SECURE_NO_WARNINGS
#include "ForumCategory.h"
#include <string.h>

ForumCategory::ForumCategory()
{
	this->forumCatID = 0;
	this->forumCatDescription = nullptr;
	this->forumCatName = nullptr;
	this->forumPosts.clear();
}

void ForumCategory::setForumCatID(int idToSet)
{
	this->forumCatID = idToSet;
}

void ForumCategory::setForumCatName(char* nameToSet)
{
	this->forumCatName = new char[strlen(nameToSet)];
	strcpy(this->forumCatName, nameToSet);
}

void ForumCategory::setForumCatDescription(char* descriptionToSet)
{
	this->forumCatDescription = new char[strlen(descriptionToSet)];
	strcpy(this->forumCatDescription, descriptionToSet);
}

void ForumCategory::setForumPosts(vector<ForumPost*> postsToSet)
{
	this->forumPosts = postsToSet;
}

void ForumCategory::addForumPost(ForumPost* postToAdd)
{
	this->forumPosts.push_back(postToAdd);
}

int ForumCategory::getForumCatID()
{
	return this->forumCatID;
}

char* ForumCategory::getForumCatName()
{
	return this->forumCatName;
}

char* ForumCategory::getForumCatDescription()
{
	return this->forumCatDescription;
}

vector<ForumPost*> ForumCategory::getAllPosts()
{
	return this->forumPosts;
}

ForumCategory::~ForumCategory()
{
	this->forumCatID = 0;
	delete[] this->forumCatDescription;
	delete[] this->forumCatName;
	for (auto iterator : this->forumPosts)
		delete iterator;
}
