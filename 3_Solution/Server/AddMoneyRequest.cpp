#include "AddMoneyRequest.h"
#include "APPServer.h"
#include "Client.h"
#include <iostream>
bool AddMoneyRequest::receiveRequest()
{
    std::cout << "Client is trying to add money!" << std::endl;
    int sentBytes = 0, recvBytes = 0;
    char moneyToAdd[10] = "";
    recvBytes = APPServer::getInstance()->getTcpServer()->recv(moneyToAdd, sizeof(moneyToAdd));
    sentBytes = APPServer::getInstance()->getTcpServer()->send("ACK", strlen("ACK"));
    moneyToAdd[recvBytes] = '\0';
    float balanceToBeSet = static_cast<Client*>(APPServer::getInstance()->getManagedClient())->getBalance() + atof(moneyToAdd);
    static_cast<Client*>(APPServer::getInstance()->getManagedClient())->setBalance(balanceToBeSet);
    int clientID = APPServer::getInstance()->getManagedClient()->getClintId();
    APPServer::getInstance()->getBDComm()->addMoneyToAccount(clientID, atof(moneyToAdd));
    std::cout << "Client successfully added money!" << std::endl;
    return true;
}

bool AddMoneyRequest::sendAnswear()
{
    return true;
}
