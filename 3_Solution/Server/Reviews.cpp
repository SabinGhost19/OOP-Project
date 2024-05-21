#define _CRT_SECURE_NO_WARNINGS
#include "Reviews.h"
#include <string.h>

Reviews::Reviews()
{
	this->rating = 0;
	this->clientID = 0;
	delete[] this->comment;
}

void Reviews::setComment(char* commentToAdd)
{
	this->comment = new char[strlen(commentToAdd)];
	strcpy(this->comment, commentToAdd);
}

void Reviews::setRating(int rating)
{
	this->rating = rating;
}

void Reviews::setClientID(int clientID)
{
	this->clientID = clientID;
}

int Reviews::getClientID()
{
	return this->clientID;
}

int Reviews::getRating()
{
	return this->rating;
}

char* Reviews::getComment()
{
	return this->comment;
}

Reviews::~Reviews()
{
	this->rating = 0;
	this->clientID = 0;
	delete[] this->comment;
}
