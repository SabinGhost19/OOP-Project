#pragma once
#include "Builder.h"

class AdminBuilder : public Builder
{
private:

public:
	AdminBuilder();
	IClient* buildClient(char* email, char* password) override;
	IClient* buildClientFromSignUp(char* email, char* password) override;
	~AdminBuilder();
};

