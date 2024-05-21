#define _CRT_SECURE_NO_WARNINGS
#include "Client.h"
#include "APPServer.h"
#include "Exception.h"
#include <string.h>
#include <iostream>
#include <string>

Client::Client()
{
	strcpy(this->lastName,"");
	strcpy(this->firstName,"");
	strcpy(this->telephoneNo, "");
	strcpy(this->BirthDate, "");
	this->balance = 0;
	deliveryAddress = NULL;
	billingAddress = NULL;
	clientCard = nullptr;
}

void Client::sendInformations()
{
	int recvBytes = 0, sentBytes = 0;
	char ackBuffer[10] = "";
	char clientIDChar[3] = "";
	_itoa(this->ClientID, clientIDChar, 10);
	sentBytes = APPServer::getInstance()->getTcpServer()->send(clientIDChar, strlen(clientIDChar));
	recvBytes = APPServer::getInstance()->getTcpServer()->recv(ackBuffer, sizeof(ackBuffer));
	sentBytes = APPServer::getInstance()->getTcpServer()->send((char*)"Client", strlen("Client"));
	recvBytes = APPServer::getInstance()->getTcpServer()->recv(ackBuffer, sizeof(ackBuffer));
	sentBytes = APPServer::getInstance()->getTcpServer()->send(this->clientAccount->getEmail(), strlen(this->clientAccount->getEmail()));
	recvBytes = APPServer::getInstance()->getTcpServer()->recv(ackBuffer, sizeof(ackBuffer));
	sentBytes = APPServer::getInstance()->getTcpServer()->send(this->clientAccount->getPassword(), strlen(this->clientAccount->getPassword()));
	recvBytes = APPServer::getInstance()->getTcpServer()->recv(ackBuffer, sizeof(ackBuffer));
	sentBytes = APPServer::getInstance()->getTcpServer()->send(this->lastName, strlen(this->lastName));
	recvBytes = APPServer::getInstance()->getTcpServer()->recv(ackBuffer, sizeof(ackBuffer));
	sentBytes = APPServer::getInstance()->getTcpServer()->send(this->firstName, strlen(this->firstName));
	recvBytes = APPServer::getInstance()->getTcpServer()->recv(ackBuffer, sizeof(ackBuffer));
	sentBytes = APPServer::getInstance()->getTcpServer()->send(this->telephoneNo, strlen(this->telephoneNo));
	recvBytes = APPServer::getInstance()->getTcpServer()->recv(ackBuffer, sizeof(ackBuffer));
	sentBytes = APPServer::getInstance()->getTcpServer()->send(this->BirthDate, strlen(this->BirthDate));
	recvBytes = APPServer::getInstance()->getTcpServer()->recv(ackBuffer, sizeof(ackBuffer));
	//ADRESA LIVRARE
	sentBytes = APPServer::getInstance()->getTcpServer()->send(this->deliveryAddress->getPostalCode(), strlen(this->deliveryAddress->getPostalCode()));
	recvBytes = APPServer::getInstance()->getTcpServer()->recv(ackBuffer, sizeof(ackBuffer));
	sentBytes = APPServer::getInstance()->getTcpServer()->send(this->deliveryAddress->getCountry(), strlen(this->deliveryAddress->getCountry()));
	recvBytes = APPServer::getInstance()->getTcpServer()->recv(ackBuffer, sizeof(ackBuffer));
	sentBytes = APPServer::getInstance()->getTcpServer()->send(this->deliveryAddress->getCounty(), strlen(this->deliveryAddress->getCounty()));
	recvBytes = APPServer::getInstance()->getTcpServer()->recv(ackBuffer, sizeof(ackBuffer));
	sentBytes = APPServer::getInstance()->getTcpServer()->send(this->deliveryAddress->getTown(), strlen(this->deliveryAddress->getTown()));
	recvBytes = APPServer::getInstance()->getTcpServer()->recv(ackBuffer, sizeof(ackBuffer));
	sentBytes = APPServer::getInstance()->getTcpServer()->send(this->deliveryAddress->getStreet(), strlen(this->deliveryAddress->getStreet()));
	recvBytes = APPServer::getInstance()->getTcpServer()->recv(ackBuffer, sizeof(ackBuffer));
	sentBytes = APPServer::getInstance()->getTcpServer()->send(this->deliveryAddress->getNr(), strlen(this->deliveryAddress->getNr()));
	recvBytes = APPServer::getInstance()->getTcpServer()->recv(ackBuffer, sizeof(ackBuffer));
	sentBytes = APPServer::getInstance()->getTcpServer()->send(this->deliveryAddress->getEntrance(), strlen(this->deliveryAddress->getEntrance()));
	recvBytes = APPServer::getInstance()->getTcpServer()->recv(ackBuffer, sizeof(ackBuffer));
	std::string nrString = std::to_string(this->deliveryAddress->getNrAppart());
	sentBytes = APPServer::getInstance()->getTcpServer()->send(nrString.c_str(), nrString.size());
	recvBytes = APPServer::getInstance()->getTcpServer()->recv(ackBuffer, sizeof(ackBuffer));
	//ADRESA FACTURARE
	sentBytes = APPServer::getInstance()->getTcpServer()->send(this->billingAddress->getPostalCode(), strlen(this->billingAddress->getPostalCode()));
	recvBytes = APPServer::getInstance()->getTcpServer()->recv(ackBuffer, sizeof(ackBuffer));
	sentBytes = APPServer::getInstance()->getTcpServer()->send(this->billingAddress->getCountry(), strlen(this->billingAddress->getCountry()));
	recvBytes = APPServer::getInstance()->getTcpServer()->recv(ackBuffer, sizeof(ackBuffer));
	sentBytes = APPServer::getInstance()->getTcpServer()->send(this->billingAddress->getCounty(), strlen(this->billingAddress->getCounty()));
	recvBytes = APPServer::getInstance()->getTcpServer()->recv(ackBuffer, sizeof(ackBuffer));
	sentBytes = APPServer::getInstance()->getTcpServer()->send(this->billingAddress->getTown(), strlen(this->billingAddress->getTown()));
	recvBytes = APPServer::getInstance()->getTcpServer()->recv(ackBuffer, sizeof(ackBuffer));
	sentBytes = APPServer::getInstance()->getTcpServer()->send(this->billingAddress->getStreet(), strlen(this->billingAddress->getStreet()));
	recvBytes = APPServer::getInstance()->getTcpServer()->recv(ackBuffer, sizeof(ackBuffer));
	sentBytes = APPServer::getInstance()->getTcpServer()->send(this->billingAddress->getNr(), strlen(this->billingAddress->getNr()));
	recvBytes = APPServer::getInstance()->getTcpServer()->recv(ackBuffer, sizeof(ackBuffer));
	sentBytes = APPServer::getInstance()->getTcpServer()->send(this->billingAddress->getEntrance(), strlen(this->billingAddress->getEntrance()));
	recvBytes = APPServer::getInstance()->getTcpServer()->recv(ackBuffer, sizeof(ackBuffer));
	nrString = std::to_string(this->billingAddress->getNrAppart());
	sentBytes = APPServer::getInstance()->getTcpServer()->send(nrString.c_str(), nrString.size());
	recvBytes = APPServer::getInstance()->getTcpServer()->recv(ackBuffer, sizeof(ackBuffer));

	if (this->clientCard == nullptr)
	{
		sentBytes = APPServer::getInstance()->getTcpServer()->send("NULL", strlen("NULL"));
		recvBytes = APPServer::getInstance()->getTcpServer()->recv(ackBuffer, sizeof(ackBuffer));
		return;
	}
	else
	{
		sentBytes = APPServer::getInstance()->getTcpServer()->send("TRUE", strlen("TRUE"));
		recvBytes = APPServer::getInstance()->getTcpServer()->recv(ackBuffer, sizeof(ackBuffer));
	}
	sentBytes = APPServer::getInstance()->getTcpServer()->send(this->clientCard->getCardNumber(), strlen(this->clientCard->getCardNumber()));
	recvBytes = APPServer::getInstance()->getTcpServer()->recv(ackBuffer, sizeof(ackBuffer));
	sentBytes = APPServer::getInstance()->getTcpServer()->send(this->clientCard->getOwnerName(), strlen(this->clientCard->getOwnerName()));
	recvBytes = APPServer::getInstance()->getTcpServer()->recv(ackBuffer, sizeof(ackBuffer));
	sentBytes = APPServer::getInstance()->getTcpServer()->send(this->clientCard->getExpirationDate(), strlen(this->clientCard->getExpirationDate()));
	recvBytes = APPServer::getInstance()->getTcpServer()->recv(ackBuffer, sizeof(ackBuffer));
	std::string CVCString = std::to_string(this->clientCard->getCVC());
	sentBytes = APPServer::getInstance()->getTcpServer()->send(CVCString.c_str(), CVCString.size());
	recvBytes = APPServer::getInstance()->getTcpServer()->recv(ackBuffer, sizeof(ackBuffer));
}

bool Client::listProduct(Product* productToAdd)
{
	throw Exception("CLIENT DOESN'T HAVE ACCESS TO EXECUTE THIS ACTION!");
	return false;
}

void Client::setLastName(char* lastNameToSet)
{
	strcpy(this->lastName, lastNameToSet);
}

void Client::setFirstName(char* firstNameToSet)
{
	strcpy(this->firstName, firstNameToSet);
}

void Client::setTelephoneNo(char* telephoneNoToSet)
{
	strcpy(this->telephoneNo, telephoneNoToSet);
}

void Client::setBirthDate(char* birthDateToSet)
{
	strcpy(this->BirthDate, birthDateToSet);
}

void Client::setDeliveryAddress(Address* addressToSet)
{
	this->deliveryAddress = addressToSet;
}

void Client::setBillingAddress(Address* addressToSet)
{
	this->billingAddress = addressToSet;
}

void Client::setClientCard(Card* cardToSet)
{
	this->clientCard = cardToSet;
}

void Client::setBalance(float balanceToSet)
{
	this->balance = balanceToSet;
}

bool Client::buyProduct(int productID, int quantity)
{
	Product* productToBuy = nullptr;
	for (auto iterator : APPServer::getInstance()->getListedProducts())
		if (iterator->getProductId() == productID)
		{
			productToBuy = iterator;
			break;
		}
	int stockUnits = productToBuy->getStocUnits();
	productToBuy->setStockUnits(stockUnits - quantity);
	this->balance = this->balance - productToBuy->getPrice() * quantity;
	float moneyToPay = -(productToBuy->getPrice() * quantity);
	APPServer::getInstance()->getBDComm()->addMoneyToAccount(this->ClientID, moneyToPay);
	return true;
}

Address* Client::getClientDeliveryAddress()
{
	return this->deliveryAddress;
}

Address* Client::getClientBillingAddress()
{
	return this->billingAddress;
}

Card* Client::getClientCard(Card* card)
{
	return this->clientCard;
}

char* Client::getName()
{
	char* fullName = new char[strlen(lastName) + strlen(firstName) + 1];
	strcpy(fullName, lastName);
	strcat(fullName, " ");
	strcat(fullName, firstName);
	return fullName;
}

char* Client::getRole()
{
	return (char*)"Client";
}

char* Client::getTelephone()
{
	return this->telephoneNo;
}

char* Client::getBirthDate()
{
	return this->BirthDate;
}

float Client::getBalance()
{
	return this->balance;
}

bool Client::deleteProduct()
{
	throw Exception("CLIENT DOESN'T HAVE ACCESS TO EXECUTE THIS ACTION!");
	return false;
}

Client::~Client()
{
	delete deliveryAddress;
	delete billingAddress;
	delete clientCard;
}
