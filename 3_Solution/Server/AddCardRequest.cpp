#include "AddCardRequest.h"
#include "APPServer.h"
#include "Card.h"
#include "Client.h"
#include <iostream>
#include <string>

bool AddCardRequest::receiveRequest()
{
    int sentBytes = 0, recvBytes = 0;
    char cardNumber[50]="";
    char cardOwner[50]="";
    char expirationDate[15]="";
    char CVC[10] = "";
    std::cout << "Client is trying to add a card" << std::endl;
    recvBytes = APPServer::getInstance()->getTcpServer()->recv(cardNumber, sizeof(cardNumber));
    sentBytes = APPServer::getInstance()->getTcpServer()->send("ACK", strlen("ACK"));
    cardNumber[recvBytes] = '\0';
    recvBytes = APPServer::getInstance()->getTcpServer()->recv(cardOwner, sizeof(cardOwner));
    sentBytes = APPServer::getInstance()->getTcpServer()->send("ACK", strlen("ACK"));
    cardOwner[recvBytes] = '\0';
    recvBytes = APPServer::getInstance()->getTcpServer()->recv(expirationDate, sizeof(cardOwner));
    sentBytes = APPServer::getInstance()->getTcpServer()->send("ACK", strlen("ACK"));
    expirationDate[recvBytes] = '\0';
    recvBytes = APPServer::getInstance()->getTcpServer()->recv(CVC, sizeof(cardOwner));
    sentBytes = APPServer::getInstance()->getTcpServer()->send("ACK", strlen("ACK"));
    CVC[recvBytes] = '\0';
    std::string CVCString = CVC;
    int CVCInt = std::stoi(CVCString);
    int clientID = APPServer::getInstance()->getManagedClient()->getClintId();
    Card* newCard = new Card;
    newCard->setCardNumber(cardNumber);
    newCard->setOwnerName(cardOwner);
    newCard->setExpirationDate(expirationDate);
    newCard->setCVC(CVCInt);
    static_cast<Client*>(APPServer::getInstance()->getManagedClient())->setClientCard(newCard);
    APPServer::getInstance()->getBDComm()->addCard(clientID, cardNumber, cardOwner, expirationDate, CVCInt);
    std::cout << "Card has been added successfully!" << std::endl;
    return true;
}

bool AddCardRequest::sendAnswear()
{
    return true;
}
