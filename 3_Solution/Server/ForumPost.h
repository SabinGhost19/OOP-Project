#pragma once
class ForumPost
{
private:
	char* username;
	char* post;
public:
	ForumPost();
	void setUsername(char* usernameToSet);
	void setPost(char* postToSet);
	char* getUsername();
	char* getPost();
	~ForumPost();
};

