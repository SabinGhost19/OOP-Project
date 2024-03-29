#pragma once
#include "TCPServer.h"
#include "BDComm.h"

class APPServer
{
private:
	static APPServer* instance;
	TCPServer* tcpServer;
	BDComm* BDCommunication;
	APPServer();
	APPServer(APPServer& obj) = delete;
	bool manageLogIn(const char* buffer);
public:
	static APPServer* getInstance();
	TCPServer* getTcpServer();
	static void deleteInstance();
	bool manageRequest(char* buffer);
	~APPServer();
};
