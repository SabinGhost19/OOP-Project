#define _CRT_SECURE_NO_WARNINGS
#include "ForumPost.h"
#include <string.h>

ForumPost::ForumPost()
{
	this->username = nullptr;
	this->post = nullptr;
}

void ForumPost::setUsername(char* usernameToSet)
{
	this->username = new char[strlen(usernameToSet)];
	strcpy(this->username, usernameToSet);
}

void ForumPost::setPost(char* postToSet)
{
	this->post = new char[strlen(postToSet)];
	strcpy(this->post, postToSet);
}

char* ForumPost::getUsername()
{
	return this->username;
}

char* ForumPost::getPost()
{
	return this->post;
}

ForumPost::~ForumPost()
{
	delete[] this->username;
	delete[] this->post;
}
