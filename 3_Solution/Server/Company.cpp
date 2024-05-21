#define _CRT_SECURE_NO_WARNINGS
#include "Company.h"
#include "APPServer.h"
#include <iostream>
#include <string>

Company::Company()
{
	strcpy(this->companyName, "");
	this->fiscalAddress = NULL;
	this->listedProducts.clear();
	this->profit = 0;
}

void Company::setCompanyName(char* name)
{
	strcpy(this->companyName, name);
}

void Company::setCompanyProfit(double newProfit)
{
	this->profit = newProfit;
}

void Company::setFiscalAddress(Address* addressToSet)
{
	this->fiscalAddress = addressToSet;
}

void Company::sendInformations()
{
	int recvBytes = 0, sentBytes = 0;
	char ackBuffer[10] = "";
	char clientIDChar[3] = "";
	_itoa(this->ClientID, clientIDChar, 10);
	sentBytes = APPServer::getInstance()->getTcpServer()->send(clientIDChar, strlen(clientIDChar));
	recvBytes = APPServer::getInstance()->getTcpServer()->recv(ackBuffer, sizeof(ackBuffer));
	sentBytes = APPServer::getInstance()->getTcpServer()->send((char*)"Companie", strlen("Companie"));
	recvBytes = APPServer::getInstance()->getTcpServer()->recv(ackBuffer, sizeof(ackBuffer));
	sentBytes = APPServer::getInstance()->getTcpServer()->send(this->clientAccount->getEmail(), strlen(this->clientAccount->getEmail()));
	recvBytes = APPServer::getInstance()->getTcpServer()->recv(ackBuffer, sizeof(ackBuffer));
	sentBytes = APPServer::getInstance()->getTcpServer()->send(this->clientAccount->getPassword(), strlen(this->clientAccount->getPassword()));
	recvBytes = APPServer::getInstance()->getTcpServer()->recv(ackBuffer, sizeof(ackBuffer));
	sentBytes = APPServer::getInstance()->getTcpServer()->send(this->companyName, strlen(this->companyName));
	recvBytes = APPServer::getInstance()->getTcpServer()->recv(ackBuffer, sizeof(ackBuffer));

	//ADRESA Fiscala
	sentBytes = APPServer::getInstance()->getTcpServer()->send(this->fiscalAddress->getPostalCode(), strlen(this->fiscalAddress->getPostalCode()));
	recvBytes = APPServer::getInstance()->getTcpServer()->recv(ackBuffer, sizeof(ackBuffer));
	sentBytes = APPServer::getInstance()->getTcpServer()->send(this->fiscalAddress->getCountry(), strlen(this->fiscalAddress->getCountry()));
	recvBytes = APPServer::getInstance()->getTcpServer()->recv(ackBuffer, sizeof(ackBuffer));
	sentBytes = APPServer::getInstance()->getTcpServer()->send(this->fiscalAddress->getCounty(), strlen(this->fiscalAddress->getCounty()));
	recvBytes = APPServer::getInstance()->getTcpServer()->recv(ackBuffer, sizeof(ackBuffer));
	sentBytes = APPServer::getInstance()->getTcpServer()->send(this->fiscalAddress->getTown(), strlen(this->fiscalAddress->getTown()));
	recvBytes = APPServer::getInstance()->getTcpServer()->recv(ackBuffer, sizeof(ackBuffer));
	sentBytes = APPServer::getInstance()->getTcpServer()->send(this->fiscalAddress->getStreet(), strlen(this->fiscalAddress->getStreet()));
	recvBytes = APPServer::getInstance()->getTcpServer()->recv(ackBuffer, sizeof(ackBuffer));
	sentBytes = APPServer::getInstance()->getTcpServer()->send(this->fiscalAddress->getNr(), strlen(this->fiscalAddress->getNr()));
	recvBytes = APPServer::getInstance()->getTcpServer()->recv(ackBuffer, sizeof(ackBuffer));
	sentBytes = APPServer::getInstance()->getTcpServer()->send(this->fiscalAddress->getEntrance(), strlen(this->fiscalAddress->getEntrance()));
	recvBytes = APPServer::getInstance()->getTcpServer()->recv(ackBuffer, sizeof(ackBuffer));
	std::string nrString = std::to_string(this->fiscalAddress->getNrAppart());
	sentBytes = APPServer::getInstance()->getTcpServer()->send(nrString.c_str(), nrString.size());
	recvBytes = APPServer::getInstance()->getTcpServer()->recv(ackBuffer, sizeof(ackBuffer));

	std::string companyProfit = std::to_string(this->profit);
	sentBytes = APPServer::getInstance()->getTcpServer()->send(companyProfit.c_str(), companyProfit.size());
	recvBytes = APPServer::getInstance()->getTcpServer()->recv(ackBuffer, sizeof(ackBuffer));
}

bool Company::listProduct(Product* productToAdd)
{
	APPServer::getInstance()->listProduct(productToAdd);
	this->listedProducts.push_back(productToAdd);
	return true;
}

void Company::addProduct(Product* productToAdd)
{
	this->listedProducts.push_back(productToAdd);
}

bool Company::deleteProduct()
{
	return false;
}

void Company::setCompanyFiscalAddress(Address* address)
{
	this->fiscalAddress = address;
}

Address* Company::getCompanyFiscalAddress()
{
	return this->fiscalAddress;
}

char* Company::getName()
{
	return this->companyName;
}

char* Company::getRole()
{
	return (char*)"Companie";
}

vector<Product*> Company::getListedProducts()
{
	return this->listedProducts;
}

double Company::getCompanyProfit()
{
	return this->profit;
}

Company::~Company()
{
	strcpy(this->companyName, "");
	delete this->fiscalAddress;
	for (auto iterator : this->listedProducts)
		delete iterator;
	this->profit = 0;
}
