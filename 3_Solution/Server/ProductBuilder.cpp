#define _CRT_SECURE_NO_WARNINGS
#include "ProductBuilder.h"
#include "APPServer.h"
#include <iostream>

using namespace std;

ProductBuilder::ProductBuilder()
{
	this->productObj = new Product;
}

Product* ProductBuilder::buildProductFromRequest()
{
    int recvBytes = 0, sentBytes = 0;
    char productName[200] = ""; char categoryName[100] = ""; char productDescription[4000] = "";
    char productPrice[10] = ""; char quantity[10] = "";
    recvBytes = APPServer::getInstance()->getTcpServer()->recv(productName, sizeof(productName));
    sentBytes = APPServer::getInstance()->getTcpServer()->send("ACK", 4);
    productName[recvBytes] = '\0';
    recvBytes = APPServer::getInstance()->getTcpServer()->recv(categoryName, sizeof(categoryName));
    sentBytes = APPServer::getInstance()->getTcpServer()->send("ACK", 4);
    categoryName[recvBytes] = '\0';
    cout << "Trying to list product named: " << productName << " in category: " << categoryName << endl;
    recvBytes = APPServer::getInstance()->getTcpServer()->recv(productDescription, sizeof(productDescription));
    sentBytes = APPServer::getInstance()->getTcpServer()->send("ACK", 4);
    productDescription[recvBytes] = '\0';
    recvBytes = APPServer::getInstance()->getTcpServer()->recv(productPrice, sizeof(productPrice));
    sentBytes = APPServer::getInstance()->getTcpServer()->send("ACK", 4);
    productPrice[recvBytes] = '\0';
    recvBytes = APPServer::getInstance()->getTcpServer()->recv(quantity, sizeof(quantity));
    sentBytes = APPServer::getInstance()->getTcpServer()->send("ACK", 4);
    quantity[recvBytes] = '\0';
    this->productObj->setProductName(productName);
    this->productObj->setCategory(categoryName);
    this->productObj->setProductDescription(productDescription);
    this->productObj->setPrice(atof(productPrice));
    this->productObj->setStockUnits(atoi(quantity));
    int categoryID = APPServer::getInstance()->getBDComm()->getCategoryId(categoryName);
    int productID = APPServer::getInstance()->getBDComm()->insertProduct(APPServer::getInstance()->getManagedClient()->getClintId(), categoryID, productName, productDescription, quantity, productPrice);
    this->productObj->setProductID(productID);

    char nrOfImages[5] = "";
    recvBytes = APPServer::getInstance()->getTcpServer()->recv(nrOfImages, sizeof(quantity));
    sentBytes = APPServer::getInstance()->getTcpServer()->send("ACK", 4);
    nrOfImages[recvBytes] = '\0';
    int intNrOfImages = atoi(nrOfImages);
    for (int i = 0; i < intNrOfImages; i++)
    {
        char imagePath[150];
        strcpy(imagePath,APPServer::getInstance()->getTcpServer()->recvImage());
        APPServer::getInstance()->getBDComm()->insertImage(productID,imagePath);
        this->productObj->addImagePath(imagePath);
    }
    APPServer::getInstance()->getManagedClient()->listProduct(productObj);
    cout << "Product listed!" << endl;
	return this->productObj;
}

std::vector<Product*> ProductBuilder::buildProductsForCompany(int companyID)
{
    std::vector<Product*> listedProducts;
    listedProducts = APPServer::getInstance()->getBDComm()->getCompanyListedProducts(companyID);

    return listedProducts;
}

ProductBuilder::~ProductBuilder()
{
}
