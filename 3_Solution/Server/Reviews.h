#pragma once
class Reviews
{
private:
	int clientID;
	int rating;
	char* comment;
public:
	Reviews();
	void setComment(char* commentToAdd);
	void setRating(int rating);
	void setClientID(int clientID);
	int getClientID();
	int getRating();
	char* getComment();
	~Reviews();
};

