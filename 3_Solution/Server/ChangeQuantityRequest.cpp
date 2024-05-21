#include "ChangeQuantityRequest.h"
#include "APPServer.h"
#include <iostream>

using namespace std;

ChangeQuantityRequest::ChangeQuantityRequest()
{
}
bool ChangeQuantityRequest::receiveRequest()
{
	cout << "Company is trying to modify the quantity for a product!" << endl;
	int recvBytes = 0, sentBytes = 0;
	char productID[10] = "";
	char newQuantity[10] = "";
	recvBytes = APPServer::getInstance()->getTcpServer()->recv(productID, 50);
	productID[recvBytes] = '\0';
	sentBytes = APPServer::getInstance()->getTcpServer()->send("ACK", 4);
	recvBytes = APPServer::getInstance()->getTcpServer()->recv(newQuantity, 50);
	newQuantity[recvBytes] = '\0';
	sentBytes = APPServer::getInstance()->getTcpServer()->send("ACK", 4);
	APPServer::getInstance()->getBDComm()->setNewQuantity(atoi(productID), atoi(newQuantity));
	cout << "Quantity has been successfully modified!" << endl;
	return true;
}
bool ChangeQuantityRequest::sendAnswear()
{
	return true;
}
ChangeQuantityRequest::~ChangeQuantityRequest()
{
}