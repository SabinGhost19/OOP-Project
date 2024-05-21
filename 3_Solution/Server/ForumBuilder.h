#pragma once
#include "Forum.h"

class ForumBuilder
{
private:
	Forum* forumToBuild;
public:
	ForumBuilder();
	Forum* buildForum();
	~ForumBuilder();
};

