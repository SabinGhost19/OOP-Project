#pragma once
#include "ForumPost.h"
#include <vector>

using namespace std;

class ForumCategory
{
private:
	int forumCatID;
	char* forumCatName;
	char* forumCatDescription;
	vector<ForumPost*> forumPosts;
public:
	ForumCategory();
	void setForumCatID(int idToSet);
	void setForumCatName(char* nameToSet);
	void setForumCatDescription(char* descriptionToSet);
	void setForumPosts(vector<ForumPost*> postsToSet);
	void addForumPost(ForumPost* postToAdd);
	int getForumCatID();
	char* getForumCatName();
	char* getForumCatDescription();
	vector<ForumPost*> getAllPosts();
	~ForumCategory();
};

