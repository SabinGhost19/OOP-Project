#include "AClient.h"
#include "APPServer.h"
#include "Exception.h"
#include <string.h>

bool AClient::addReview()
{
	return false;
}

AClient::~AClient()
{
	delete this->clientAccount;
	this->ClientID = 0;
} 

AClient::AClient()
{
	this->clientAccount = new Account;
	this->ClientID = 0;
}

bool AClient::signUpAccount(char* email, char* password,char* functie)
{
	this->clientAccount->setEmail(email);
	this->clientAccount->setPassword(password);
	if (strcmp(functie, "Client") == 0)
		this->clientAccount->setRole(CLIENT);
	else if (strcmp(functie, "Admin") == 0)
		this->clientAccount->setRole(ADMIN);
	else if (strcmp(functie, "Companie") == 0)
		this->clientAccount->setRole(COMPANY);

	APPServer::getInstance()->getBDComm()->insertAccount(email, password, functie);
	return true;
}

bool AClient::logInAccount(char* email, char* password, char* functie)
{
	this->clientAccount->setEmail(email);
	this->clientAccount->setPassword(password);
	if (strcmp(functie, "Client") == 0)
		this->clientAccount->setRole(CLIENT);
	else if (strcmp(functie, "Admin") == 0)
		this->clientAccount->setRole(ADMIN);
	else if (strcmp(functie, "Companie") == 0)
		this->clientAccount->setRole(COMPANY);
	else
		throw "NO ROLE FOR THE CLIENT";
	return true;
}

void AClient::setClientID(int idToSet)
{
	this->ClientID = idToSet;
}

bool AClient::buyProduct(int productID, int quantity)
{
	throw Exception("YOU CAN'T BUY THIS PRODUCT");
	return false;
}

Address* AClient::getClientBillingAddress()
{
	throw "YOU DON'T HAVE A BILLING ADDRESS";
	return nullptr;
}

Address* AClient::getClientDeliveryAddress()
{
	throw "YOU DON'T HAVE A DELIVERY ADDRESS";
	return nullptr;
}

Address* AClient::getCompanyFiscalAddress()
{
	throw "YOU DON'T HAVE A FISCAL ADDRESS";
	return nullptr;
}

Account* AClient::getAccount()
{
	return this->clientAccount;
}

char* AClient::getName()
{
	throw "YOUR ACCOUNT DOESN'T HAVE A NAME";
	return nullptr;
}

int AClient::getClintId()
{
	return this->ClientID;
}
