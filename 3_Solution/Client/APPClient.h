#pragma once
#include "TCPClient.h"

class APPClient
{
private:
	APPClient();
	APPClient(APPClient& obj) = delete;
	static APPClient* instance;
	TCPClient* tcpClient;
public:
	static APPClient* getInstance();
	TCPClient* getTcpClient();
	static void deleteInstance();
	~APPClient();
public slots:
    void cleanUpBeforeQuit();
};

