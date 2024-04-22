#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <iostream>
#include "APPServer.h"
#include "ServerLogger.h"

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
    BDCommunication = nullptr;
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

    SQLWCHAR* queryWCHAR = BDCommunication->ConvertToWideChar(query.c_str());

    int len = 0;

    BDCommunication->CreateConnection();
    int nrOfEmails = atoi(BDCommunication->GetQuery(queryWCHAR, len));
    BDCommunication->CloseConnection();
    char messageToSend[254];
    if (nrOfEmails == 0)
    {
        std::string loggAction("LOGIN REQUEST BY EMAIL: ");
        loggAction += email;
        loggAction += "THERE IS NO ACCOUNT REGISTERED WITH THIS MAIL";
        ServerLogger::getInstance("SignUpAndInLogger.txt")->loggAction(loggAction.c_str());

        strcpy(messageToSend, "YOUR EMAIL ADDRESS ISN'T REGISTERED");
        this->tcpServer->send(messageToSend, strlen(messageToSend));
        return false;
    }

    char passwordToCheckWith[50] = "";

    query = "SELECT Parola FROM ContClient WHERE Email = '";
    query += email;
    query += '\'';

    queryWCHAR = BDCommunication->ConvertToWideChar(query.c_str());
    BDCommunication->CreateConnection();
    strcpy(passwordToCheckWith, BDCommunication->GetQuery(queryWCHAR, len));
    BDCommunication->CloseConnection();

    if (strcmp(passwordToCheckWith, password.c_str()) == 0)
    {
        std::string loggAction("THE EMAIL: ");
        loggAction += email;
        loggAction += "LOGGED IN SUCCESFULLY";
        ServerLogger::getInstance("SignUpAndInLogger.txt")->loggAction(loggAction.c_str());

        strcpy(messageToSend, "LOGGED IN SUCCESSFULLY");
        this->tcpServer->send(messageToSend, strlen(messageToSend));
        this->tcpServer->sendImage("C:\\Users\\George\\Desktop\\Proiect POO\\OPP-Project\\3_Solution\\sigla.png");
        return true;
    }
    else
    {
        std::string loggAction("THE EMAIL: ");
        loggAction += email;
        loggAction += "TRIED TO LOGGED IN WITH THE WRONG PASSWORD";
        ServerLogger::getInstance("SignUpAndInLogger.txt")->loggAction(loggAction.c_str());

        strcpy(messageToSend, "WRONG PASSWORD");
        this->tcpServer->send(messageToSend, strlen(messageToSend));
        return false;
    }
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
    case '2':
        tcpServer->sendImage("sigla.png");
    }
    return true;
}

APPServer::~APPServer()
{
    deleteInstance();
}