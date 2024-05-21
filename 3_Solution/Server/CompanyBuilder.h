#pragma once
#include "Builder.h"
class CompanyBuilder : public Builder
{
private:

public:
	CompanyBuilder();
	IClient* buildClient(char* email, char* password) override;
	IClient* buildClientFromSignUp(char* email, char* password) override;
	~CompanyBuilder();
};

