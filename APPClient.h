#pragma once
#include "TCPClient.h"
#include"userClient.h"
#include"userCompany.h"

class APPClient
{
private:
	APPClient();
	APPClient(APPClient& obj) = delete;
	static APPClient* instance;
	TCPClient* tcpClient;
public:
    void setClientUser(UserClient*);
    void setCompanyUser(UserCompany*);
	static APPClient* getInstance();
	TCPClient* getTcpClient();
	static void deleteInstance();
    UserClient*user_client=nullptr;
    UserCompany*user_company=nullptr;
	~APPClient();
};

