#pragma once

enum Roles {ADMIN,CLIENT,COMPANY};

class Account
{
private:
	char email[100];
	char password[100];
	Roles accountRole;
public:
	Account();
	void setEmail(char* email);
	void setPassword(char* password);
	void setRole(Roles role);
	char* getEmail();
	char* getPassword();
	char* getAccountRole();
	~Account();
};

