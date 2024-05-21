#include "ChangePriceRequest.h"
#include "APPServer.h"
#include <iostream>

using namespace std;

bool ChangePriceRequest::receiveRequest()
{
	cout << "Company is trying to modify the price for a product!" << endl;
	int recvBytes = 0, sentBytes = 0;
	char productID[10] = "";
	char newQuantity[10] = "";
	recvBytes = APPServer::getInstance()->getTcpServer()->recv(productID, 50);
	productID[recvBytes] = '\0';
	sentBytes = APPServer::getInstance()->getTcpServer()->send("ACK", 4);
	recvBytes = APPServer::getInstance()->getTcpServer()->recv(newQuantity, 50);
	newQuantity[recvBytes] = '\0';
	sentBytes = APPServer::getInstance()->getTcpServer()->send("ACK", 4);
	APPServer::getInstance()->getBDComm()->setNewPrice(atoi(productID), atof(newQuantity));
	cout << "Price has been successfully modified!" << endl;
	return true;
}

bool ChangePriceRequest::sendAnswear()
{
    return false;
}
