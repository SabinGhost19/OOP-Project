#include "ChangePasswdRequest.h"
#include "APPServer.h"
#include <iostream>

bool ChangePasswdRequest::receiveRequest()
{
    std::cout << "Client is trying to change his password" << std::endl;
    int sentBytes = 0, recvBytes = 0;
    char newPasswd[50] = "";
    recvBytes = APPServer::getInstance()->getTcpServer()->recv(newPasswd, sizeof(newPasswd));
    sentBytes = APPServer::getInstance()->getTcpServer()->send("ACK", strlen("ACK"));
    APPServer::getInstance()->getBDComm()->changeClientPasswd(APPServer::getInstance()->getManagedClient()->getClintId(), newPasswd);
    std::cout << "Password has been successfully changed!" << std::endl;
    return true;
}

bool ChangePasswdRequest::sendAnswear()
{
    return true;
}
