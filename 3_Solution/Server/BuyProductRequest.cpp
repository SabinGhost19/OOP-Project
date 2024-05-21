#include "BuyProductRequest.h"
#include "APPServer.h"
#include <iostream>
#include <string>
#include "Client.h"
BuyProductRequest::BuyProductRequest()
{
	this->result = false;
}

bool BuyProductRequest::receiveRequest()
{
    int sentBytes = 0, recvBytes = 0;
    char productIDChar[10]="";
    char quantityChar[10]="";
    char ackBuffer[10] = "";
    recvBytes = APPServer::getInstance()->getTcpServer()->recv(productIDChar, sizeof(productIDChar));
    sentBytes = APPServer::getInstance()->getTcpServer()->send("ACK", strlen("ACK"));
    productIDChar[recvBytes] = '\0';
    recvBytes = APPServer::getInstance()->getTcpServer()->recv(quantityChar, sizeof(productIDChar));
    sentBytes = APPServer::getInstance()->getTcpServer()->send("ACK", strlen("ACK"));
    quantityChar[recvBytes] = '\0';
    std::string productIDString = productIDChar;
    std::string quantityString = quantityChar;
    int productIDInt = std::stoi(productIDString);
    int quantityInt = std::stoi(quantityString);
    std::cout << "Client is trying to buy product with ID: " << productIDInt << " in quantity of: " << quantityInt << endl;
    for (auto iterator : APPServer::getInstance()->getListedProducts())
        if (iterator->getProductId() == productIDInt && iterator->getStocUnits() >= quantityInt && 
            static_cast<Client*>(APPServer::getInstance()->getManagedClient())->getBalance() >= iterator->getPrice() * quantityInt)
        {
            this->result = true;
            break;
        }
    if (this->result == false)
    {
        return false;
    }
    APPServer::getInstance()->getBDComm()->buyProduct(productIDInt, quantityInt);
    APPServer::getInstance()->getManagedClient()->buyProduct(productIDInt, quantityInt);
    return true;
}

bool BuyProductRequest::sendAnswear()
{
    int recvBytes = 0, sentBytes = 0;
    char ackBuffer[10] = "";
    if (!this->result)
    {
        sentBytes = APPServer::getInstance()->getTcpServer()->send("ERROR", strlen("ERROR"));
        recvBytes = APPServer::getInstance()->getTcpServer()->recv(ackBuffer, sizeof(ackBuffer));
        std::cout << "ERROR WHILE TRYING TO BUY THE PRODUCT" << endl;
        return false;
    }
    else
    {
        sentBytes = APPServer::getInstance()->getTcpServer()->send("SUCCESS", strlen("SUCCESS"));
        recvBytes = APPServer::getInstance()->getTcpServer()->recv(ackBuffer, sizeof(ackBuffer));
        std::cout << "Product bought successfully" << endl;
    }
    return true;
}

BuyProductRequest::~BuyProductRequest()
{
	this->result = false;
}
