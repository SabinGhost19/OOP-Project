#include "FirstImageRequest.h"
#include "APPServer.h"
#include "Product.h"
#include "Company.h"
#include <string>

bool FirstImageRequest::receiveRequest()
{
	vector<Product*> listedProducts = static_cast<Company*>(APPServer::getInstance()->getManagedClient())->getListedProducts();
    int recvBytes = 0, sentBytes = 0;
    char ackBuffer[10] = "";
    std::string nrOfProductsStr = std::to_string(listedProducts.size());
    sentBytes = APPServer::getInstance()->getTcpServer()->send(nrOfProductsStr.c_str(), nrOfProductsStr.size());
    recvBytes = APPServer::getInstance()->getTcpServer()->recv(ackBuffer, sizeof(ackBuffer));
    for (auto iterator : listedProducts)
    {
        this->sendProductMainInfo(iterator);
        std::string stockUnits = std::to_string(iterator->getStocUnits());
        sentBytes = APPServer::getInstance()->getTcpServer()->send(stockUnits.c_str(), stockUnits.size());
        recvBytes = APPServer::getInstance()->getTcpServer()->recv(ackBuffer, 10);
    }

    return true;
}

bool FirstImageRequest::sendAnswear()
{
    return false;
}
