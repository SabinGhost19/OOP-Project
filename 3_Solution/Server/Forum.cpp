#include "Forum.h"

Forum::Forum()
{
	this->forumCategories.clear();
}

void Forum::addForumCategory(ForumCategory* categoryToAdd)
{
	this->forumCategories.push_back(categoryToAdd);
}

void Forum::setAllCategories(vector<ForumCategory*> categoriesToSet)
{
	this->forumCategories = categoriesToSet;
}

vector<ForumCategory*> Forum::getForumCategories()
{
	return this->forumCategories;
}

Forum::~Forum()
{
	for (auto iterator : this->forumCategories)
		delete iterator;
	this->forumCategories.clear();
}
