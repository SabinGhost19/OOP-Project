#pragma once
#include "ForumCategory.h"
#include <vector>

using namespace std;

class Forum
{
private:
	vector<ForumCategory*> forumCategories;
public:
	Forum();
	void addForumCategory(ForumCategory* categoryToAdd);
	void setAllCategories(vector<ForumCategory*> categoriesToSet);
	vector<ForumCategory*> getForumCategories();
	~Forum();
};

