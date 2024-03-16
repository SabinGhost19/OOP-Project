#pragma once
#include "TCPServer.h"

class APPServer
{
private:
	APPServer();
	APPServer(APPServer& obj) = delete;
	static APPServer* instance;
	TCPServer* tcpServer;
public:
	static APPServer* getInstance();
	TCPServer* getTcpServer();
	static void deleteInstance();
	~APPServer();
};
