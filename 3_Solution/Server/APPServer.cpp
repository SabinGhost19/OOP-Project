#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <iostream>
#include "APPServer.h"
#include "ServerLogger.h"
#include "SignInRequest.h"
#include "SignUpRequest.h"
#include "AddProductRequest.h"
#include "ReviewRequest.h"
#include "DescriptionRequest.h"
#include "ImageRequest.h"
#include "BuyProductRequest.h"
#include "AddCardRequest.h"
#include "ChangePasswdRequest.h"
#include "AddMoneyRequest.h"
#include "ServerLogger.h"
#include "Exception.h"
#include "ChangeQuantityRequest.h"
#include "ChangePriceRequest.h"
#include "ForumBuilder.h"
#include "ForumRequest.h"
#include "AddForumPostRequest.h"
#include "FirstImageRequest.h"

using namespace std;

APPServer* APPServer::instance = nullptr;

APPServer* APPServer::getInstance()
{
    if (instance != nullptr)
        return instance;
    instance = new APPServer;
    instance->tcpServer = new TCPServer(12345);
    instance->BDCommunication = new BDComm;
    instance->bringProductsFromDB();
    ForumBuilder builderForForum;
    instance->forum = builderForForum.buildForum();
    instance->managedClient = nullptr;
    return instance;
}

TCPServer* APPServer::getTcpServer()
{
    return instance->tcpServer;
}

BDComm* APPServer::getBDComm()
{
    return instance->BDCommunication;
}

IClient* APPServer::getManagedClient()
{
    return this->managedClient;
}

std::vector<Product*> APPServer::getListedProducts()
{
    return this->listedProducts;
}

Forum* APPServer::getForum()
{
    return this->forum;
}

void APPServer::setManagedClient(IClient* ClientToManage)
{
    this->managedClient = ClientToManage;
}

APPServer::APPServer()
{
    instance = nullptr;
    tcpServer = nullptr;
    BDCommunication = nullptr;
    managedClient = nullptr;
    listedProducts.clear();
}

void APPServer::deleteInstance()
{
    if (instance == nullptr)
        return;
    if (instance->tcpServer != nullptr)
    {
        delete instance->tcpServer;
        instance->tcpServer = nullptr;
    }
    delete instance;
}

bool APPServer::manageRequest(char* buffer)
{
    try {
        int sentBytes = APPServer::getInstance()->getTcpServer()->send("ACK", 4);
        int action = atoi(buffer);
        IRequest* newRequest = nullptr;
        switch (action)
        {
        case 1:
            newRequest = new SignInRequest;
            newRequest->receiveRequest();
            newRequest->sendAnswear();
            break;
        case 2:
            newRequest = new SignUpRequest;
            newRequest->receiveRequest();
            break;
        case 3:
            newRequest = new AddProductRequest;
            newRequest->receiveRequest();
            break;
        case 4:
            newRequest = new ReviewRequest;
            newRequest->receiveRequest();
            break;
        case 5:
            newRequest = new DescriptionRequest;
            newRequest->receiveRequest();
            newRequest->sendAnswear();
            break;
        case 6:
            newRequest = new ImageRequest;
            newRequest->receiveRequest();
            newRequest->sendAnswear();
            break;
        case 7:
            newRequest = new BuyProductRequest;
            newRequest->receiveRequest();
            newRequest->sendAnswear();
            break;
        case 8:
            newRequest = new AddCardRequest;
            newRequest->receiveRequest();
            break;
        case 9:
            newRequest = new ChangePasswdRequest;
            newRequest->receiveRequest();
            break;
        case 10:
            newRequest = new AddMoneyRequest;
            newRequest->receiveRequest();
            break;
        case 11:
            newRequest = new ChangePriceRequest;
            newRequest->receiveRequest();
            break;
        case 12:
            newRequest = new ChangeQuantityRequest;
            newRequest->receiveRequest();
            break;
        case 13:
            newRequest = new ForumRequest;
            newRequest->receiveRequest();
            break;
        case 14:
            newRequest = new AddForumPostRequest;
            newRequest->receiveRequest();
            break;
        case 15:
            newRequest = new FirstImageRequest;
            newRequest->receiveRequest();
            break;
        default:
            break;
        }
        if (newRequest != nullptr)
            delete newRequest;
        return true;
    }
    catch (Exception& e)
    {
        ServerLogger::getInstance("ExceptionLogger.txt")->loggAction(e.what());
    }
    catch (...)
    {
        ServerLogger::getInstance("ExceptionLogger.txt")->loggAction("SOMETHING WENT WRONG!");
        this->tcpServer->closeConnection();
    }
}

void APPServer::listProduct(Product* listedProduct)
{
    this->listedProducts.push_back(listedProduct);
}

void APPServer::bringProductsFromDB()
{
    this->listedProducts = this->BDCommunication->getAllProducts();
    for (auto iterator : this->listedProducts)
        iterator->setAllImages(this->BDCommunication->getProductPhotos(iterator->getProductId()));
    for (auto iterator : this->listedProducts)
        iterator->addAllReviews(APPServer::getBDComm()->getProductReviews(iterator->getProductId()));
}

APPServer::~APPServer()
{
    deleteInstance();
}