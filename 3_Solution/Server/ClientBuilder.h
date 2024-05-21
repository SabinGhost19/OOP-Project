#pragma once
#include "Builder.h"
class ClientBuilder : public Builder
{
private:

public:
	ClientBuilder();
	IClient* buildClient(char* email, char* password) override;
	IClient* buildClientFromSignUp(char* email, char* password) override;
	~ClientBuilder();
};

