#include "APPClient.h"
#include <QCoreApplication>

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
    instance->getTcpClient()->closeConnection();
    WSACleanup();
    if (instance->tcpClient != nullptr)
    {
        delete instance->tcpClient;
        instance->tcpClient = nullptr;
    }
}

void APPClient::cleanUpBeforeQuit()
{
    instance->deleteInstance();
}

APPClient::~APPClient()
{
    instance->deleteInstance();
}
