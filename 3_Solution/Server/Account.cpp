#define _CRT_SECURE_NO_WARNINGS
#include "Account.h"
#include <string.h>

Account::Account()
{
	memset(this->email, 0, 100);
	memset(this->password, 0, 100);
	this->accountRole = CLIENT;
}

void Account::setEmail(char* email)
{
	strcpy(this->email, email);
}

void Account::setPassword(char* password)
{
	strcpy(this->password, password);
}

void Account::setRole(Roles role)
{
	this->accountRole = role;
}

char* Account::getEmail()
{
	return this->email;
}

char* Account::getPassword()
{
	return this->password;
}

char* Account::getAccountRole()
{
	switch (this->accountRole)
	{
	case ADMIN:
		return (char*)"Admin";
	case CLIENT:
		return (char*)"Client";
	case COMPANY:
		return (char*)"Company";
	default:
		return (char*)"NO ROLE!";
	}
}

Account::~Account()
{
	memset(this->email, 0, 100);
	memset(this->password, 0, 100);
	this->accountRole = CLIENT;
}
