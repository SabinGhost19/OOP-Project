#define _CRT_SECURE_NO_WARNINGS
#include "ARequest.h"
#include "IClient.h"
#include "Account.h"
#include "APPServer.h"
#include "Product.h"
#include "Company.h"
#include "Client.h"
#include <stdio.h>
#include <string>

void ARequest::sendAccountDetails(IClient* client)
{
	int recvBytes = 0, sentBytes = 0;
	Account* clientAccount = client->getAccount();
	char ackBuffer[10] = "", accountRole[10];
	strcpy(accountRole, clientAccount->getAccountRole());

	char ClientIdChar[20];
	_itoa(client->getClintId(), ClientIdChar, 10);
	sentBytes = APPServer::getInstance()->getTcpServer()->send(accountRole, strlen(accountRole));
	recvBytes = APPServer::getInstance()->getTcpServer()->recv(ackBuffer, sizeof(ackBuffer));

	//sentBytes = APPServer::getInstance()->getTcpServer()->send(ClientIdChar, strlen(ClientIdChar));
	//recvBytes = APPServer::getInstance()->getTcpServer()->recv(ackBuffer, sizeof(ackBuffer));


	if (strcmp(accountRole, "Company") == 0)
	{
		sentBytes = APPServer::getInstance()->getTcpServer()->send(client->getName(), strlen(client->getName()));
		recvBytes = APPServer::getInstance()->getTcpServer()->recv(ackBuffer, sizeof(ackBuffer));
		for (auto iterator : static_cast<Company*>(client)->getListedProducts())
			this->sendProductMainInfo(iterator);
	}
	else if (strcmp(accountRole, "Client") == 0)
	{
		sentBytes = APPServer::getInstance()->getTcpServer()->send(client->getName(), strlen(client->getName()));
		recvBytes = APPServer::getInstance()->getTcpServer()->recv(ackBuffer, sizeof(ackBuffer));
		sentBytes = APPServer::getInstance()->getTcpServer()->send(static_cast<Client*>(client)->getTelephone(), strlen(static_cast<Client*>(client)->getTelephone()));
		recvBytes = APPServer::getInstance()->getTcpServer()->recv(ackBuffer, sizeof(ackBuffer));
		sentBytes = APPServer::getInstance()->getTcpServer()->send(static_cast<Client*>(client)->getBirthDate(), strlen(static_cast<Client*>(client)->getBirthDate()));
		recvBytes = APPServer::getInstance()->getTcpServer()->recv(ackBuffer, sizeof(ackBuffer));
		float balanceFloat = static_cast<Client*>(client)->getBalance();
		char balanceChar[10] = "";
		sprintf(balanceChar, "%f", balanceFloat);
		sentBytes = APPServer::getInstance()->getTcpServer()->send(balanceChar, strlen(balanceChar));
		recvBytes = APPServer::getInstance()->getTcpServer()->recv(ackBuffer, sizeof(ackBuffer));
		this->sendClientAddress(client->getClientDeliveryAddress());
		this->sendClientAddress(client->getClientBillingAddress());
	}
}

void ARequest::sendClientAddress(Address* address)
{
	int sentBytes = 0, recvBytes = 0;
	char ackBuffer[10];
	sentBytes = APPServer::getInstance()->getTcpServer()->send(address->getPostalCode(), strlen(address->getPostalCode()));
	recvBytes = APPServer::getInstance()->getTcpServer()->recv(ackBuffer, sizeof(ackBuffer));
	sentBytes = APPServer::getInstance()->getTcpServer()->send(address->getCountry(), strlen(address->getCountry()));
	recvBytes = APPServer::getInstance()->getTcpServer()->recv(ackBuffer, sizeof(ackBuffer));
	sentBytes = APPServer::getInstance()->getTcpServer()->send(address->getTown(), strlen(address->getTown()));
	recvBytes = APPServer::getInstance()->getTcpServer()->recv(ackBuffer, sizeof(ackBuffer));
	sentBytes = APPServer::getInstance()->getTcpServer()->send(address->getStreet(), strlen(address->getStreet()));
	recvBytes = APPServer::getInstance()->getTcpServer()->recv(ackBuffer, sizeof(ackBuffer));
	sentBytes = APPServer::getInstance()->getTcpServer()->send(address->getNr(), strlen(address->getNr()));
	recvBytes = APPServer::getInstance()->getTcpServer()->recv(ackBuffer, sizeof(ackBuffer));
	sentBytes = APPServer::getInstance()->getTcpServer()->send(address->getEntrance(), strlen(address->getEntrance()));
	recvBytes = APPServer::getInstance()->getTcpServer()->recv(ackBuffer, sizeof(ackBuffer));
	char nrAppartInt[10] = "";
	_itoa(address->getNrAppart(), nrAppartInt, 10);
	sentBytes = APPServer::getInstance()->getTcpServer()->send(nrAppartInt, strlen(nrAppartInt));
	recvBytes = APPServer::getInstance()->getTcpServer()->recv(ackBuffer, sizeof(ackBuffer));
}

void ARequest::sendProductMainInfo(Product* product)
{
	int sentBytes = 0, recvBytes = 0;
	char ackBuffer[10];
	sentBytes = APPServer::getInstance()->getTcpServer()->send(product->getProductName(), strlen(product->getProductName()));
	recvBytes = APPServer::getInstance()->getTcpServer()->recv(ackBuffer, sizeof(ackBuffer));
	float priceFloat = product->getPrice();
	std::string priceString = to_string(priceFloat);
	sentBytes = APPServer::getInstance()->getTcpServer()->send(priceString.c_str(), priceString.size());
	recvBytes = APPServer::getInstance()->getTcpServer()->recv(ackBuffer, sizeof(ackBuffer));
	int IDFloat = product->getProductId();
	std::string IDString = to_string(IDFloat);
	sentBytes = APPServer::getInstance()->getTcpServer()->send(IDString.c_str(), IDString.size());
	recvBytes = APPServer::getInstance()->getTcpServer()->recv(ackBuffer, sizeof(ackBuffer));
	sentBytes = APPServer::getInstance()->getTcpServer()->sendImage((char*)product->getFirstImage());
}
