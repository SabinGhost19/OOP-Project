#include "APPClient.h"

APPClient* APPClient::instance = nullptr;

APPClient* APPClient::getInstance()
{
    if (instance != nullptr)
        return instance;
    instance = new APPClient;
    instance->tcpClient = new TCPClient();
    instance->tcpClient->connect("172.20.10.3", 12345);
    return instance;
}

void APPClient::setClientUser(UserClient*new_user){
    this->user_client=new_user;
}
void APPClient::setCompanyUser(UserCompany*new_user){

    this->user_company=new_user;
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
