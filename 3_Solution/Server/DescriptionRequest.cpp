#include "DescriptionRequest.h"
#include "APPServer.h"
#include <iostream>
DescriptionRequest::DescriptionRequest()
{
	this->producerName = nullptr;
	this->productDescription = nullptr;
}

bool DescriptionRequest::receiveRequest()
{
	int recvBytes = 0, sentBytes = 0;
	char productIDChar[10];
	recvBytes = APPServer::getInstance()->getTcpServer()->recv(productIDChar, sizeof(productIDChar));
	sentBytes = APPServer::getInstance()->getTcpServer()->send("ACK", strlen("ACK"));
	productIDChar[recvBytes] = '\0';
	std::cout << "Trying to get description for product: " << productIDChar << std::endl;
	for(auto iterator:APPServer::getInstance()->getListedProducts())
		if (iterator->getProductId() == atoi(productIDChar))
		{
			this->producerName = iterator->getProducerName();
			this->productDescription = iterator->getProductDescription();
			return true;
		}
	return false;
}

bool DescriptionRequest::sendAnswear()
{
	int recvBytes = 0, sentBytes = 0;
	char ackBuffer[10];
	sentBytes = APPServer::getInstance()->getTcpServer()->send(this->producerName, strlen(this->producerName));
	recvBytes = APPServer::getInstance()->getTcpServer()->recv(ackBuffer, sizeof(ackBuffer));
	sentBytes = APPServer::getInstance()->getTcpServer()->send(this->productDescription, strlen(this->productDescription));
	recvBytes = APPServer::getInstance()->getTcpServer()->recv(ackBuffer, sizeof(ackBuffer));
	std::cout << "Description has been sent!" << std::endl;
	return true;
}

DescriptionRequest::~DescriptionRequest()
{
	this->producerName = nullptr;
	this->productDescription = nullptr;
}
