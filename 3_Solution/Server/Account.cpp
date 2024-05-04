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

Roles Account::getAccountRole()
{
	return this->accountRole;
}

Account::~Account()
{
	memset(this->email, 0, 100);
	memset(this->password, 0, 100);
	this->accountRole = CLIENT;
}
