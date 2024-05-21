#pragma once
#include "IClient.h"
class Builder
{
protected:
	IClient* ClientObj;
public:
	Builder();
	virtual IClient* buildClient(char* email, char* password) = 0;
	virtual IClient* buildClientFromSignUp(char* email,char* password) = 0;
	virtual ~Builder();
};

