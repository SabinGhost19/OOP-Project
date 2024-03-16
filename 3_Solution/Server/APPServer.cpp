#include "APPServer.h"

APPServer* APPServer::instance = nullptr;

APPServer* APPServer::getInstance()
{
    if (instance != nullptr)
        return instance;
    instance = new APPServer;
    instance->tcpServer = new TCPServer(12345);
    return instance;
}

TCPServer* APPServer::getTcpServer()
{
    return instance->tcpServer;
}

APPServer::APPServer()
{
    instance = nullptr;
    tcpServer = nullptr;
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

APPServer::~APPServer()
{
    deleteInstance();
}