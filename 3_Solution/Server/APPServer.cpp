#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <iostream>
#include "APPServer.h"

APPServer* APPServer::instance = nullptr;

APPServer* APPServer::getInstance()
{
    if (instance != nullptr)
        return instance;
    instance = new APPServer;
    instance->tcpServer = new TCPServer(12345);
    instance->BDCommunication = new BDComm;
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

SQLWCHAR* ConvertToWideChar(const char* str)
{
    int wideLen = MultiByteToWideChar(CP_ACP, 0, str, -1, NULL, 0);
    if (wideLen == 0) {
       
        return nullptr;
    }

    SQLWCHAR* wideStr = new SQLWCHAR[wideLen];
    if (!MultiByteToWideChar(CP_ACP, 0, str, -1, wideStr, wideLen)) {
        delete[] wideStr;
        return nullptr;
    }

    return wideStr;
}

bool APPServer::manageLogIn(const char* buffer)
{
    std::string bufferNou(buffer);
    size_t delimiterPos = bufferNou.find('#');
    if (delimiterPos == std::string::npos) {
        std::cerr << "Delimitatorul # nu a fost gasit în sirul de intrare." << std::endl;
        return 1;
    }

    std::string email = bufferNou.substr(0, delimiterPos);


    std::string password = bufferNou.substr(delimiterPos + 1);


    password.erase(0, password.find_first_not_of(' '));
    password.erase(password.find_last_not_of(' ') + 1);

    std::string query("SELECT COUNT(*) FROM ContClient WHERE Email = '");

    query += email;
    query += '\'';

    SQLWCHAR* queryWCHAR = ConvertToWideChar(query.c_str());

    int len = 0;

    BDCommunication->CreateConnection();
    int nrOfEmails = atoi(BDCommunication->GetQuery(queryWCHAR, len));
    BDCommunication->CloseConnection();
    char messageToSend[254];
    if (nrOfEmails == 0)
    {
        strcpy(messageToSend, "YOUR EMAIL ADDRESS ISN'T REGISTERED");
        std::cout << "Emailul nu este inregistrat" << std::endl;
        this->tcpServer->send(messageToSend, strlen(messageToSend));
        return false;
    }

    char passwordToCheckWith[50] = "";

    query = "SELECT Parola FROM ContClient WHERE Email = '";
    query += email;
    query += '\'';

    queryWCHAR = ConvertToWideChar(query.c_str());
    BDCommunication->CreateConnection();
    strcpy(passwordToCheckWith, BDCommunication->GetQuery(queryWCHAR, len));

    if (strcmp(passwordToCheckWith, password.c_str()) == 0)
    {
        strcpy(messageToSend, "LOGGED IN SUCCESSFULLY");
        std::cout << "LOGAT" << std::endl;
        this->tcpServer->send(messageToSend, strlen(messageToSend));
        return true;
    }
    else
    {
        strcpy(messageToSend, "WRONG PASSWORD");
        std::cout << "PAROLA GRESITA!" << std::endl;
        this->tcpServer->send(messageToSend, strlen(messageToSend));
        return false;
    }
    BDCommunication->CloseConnection();
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
    char action1,action2;
    action1 = buffer[0];
    strcpy(buffer, buffer + 1);
    switch (action1)
    {
    case '1':
        manageLogIn(buffer);
    }
    return true;
}

APPServer::~APPServer()
{
    deleteInstance();
}