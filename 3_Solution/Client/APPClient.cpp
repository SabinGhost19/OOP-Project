#include "APPClient.h"

APPClient* APPClient::instance = nullptr;

APPClient* APPClient::getInstance()
{
    if (instance != nullptr)
        return instance;
    instance = new APPClient;
    instance->tcpClient = new TCPClient();
    instance->tcpClient->connect("127.0.0.1", 12345);
    return instance;
}

TCPClient* APPClient::getTcpClient()
{
    return instance->tcpClient;
}

APPClient::APPClient()
{
    instance = nullptr;
    tcpClient = nullptr;
}

void APPClient::deleteInstance()
{
    if (instance == nullptr)
        return;
    if (instance->tcpClient != nullptr)
    {
        delete instance->tcpClient;
        instance->tcpClient = nullptr;
    }
    delete instance;
}

APPClient::~APPClient()
{
    deleteInstance();
}