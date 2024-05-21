#include "AdminBuilder.h"
#include "Administrator.h"

AdminBuilder::AdminBuilder()
{
	this->ClientObj = new Administrator;
}

IClient* AdminBuilder::buildClient(char* email, char* password)
{
	this->ClientObj->logInAccount(email, password, (char*)"Admin");
	return this->ClientObj;
}

IClient* AdminBuilder::buildClientFromSignUp(char* email, char* password)
{
	return nullptr;
}

AdminBuilder::~AdminBuilder()
{
	return;
}
