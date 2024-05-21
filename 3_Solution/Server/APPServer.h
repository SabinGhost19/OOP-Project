#pragma once
#include "TCPServer.h"
#include "BDComm.h"
#include "IClient.h"
#include "Product.h"
#include "Forum.h"
#include <vector>

class APPServer
{
private:
	static APPServer* instance;
	TCPServer* tcpServer;
	BDComm* BDCommunication;
	IClient* managedClient;
	std::vector<Product*> listedProducts;
	Forum* forum;
	APPServer();
	APPServer(APPServer& obj) = delete;
public:
	static APPServer* getInstance();
	TCPServer* getTcpServer();
	BDComm* getBDComm();
	IClient* getManagedClient();
	std::vector<Product*> getListedProducts();
	Forum* getForum();
	void setManagedClient(IClient* ClientToManage);
	static void deleteInstance();
	bool manageRequest(char* buffer);
	void listProduct(Product* listedProduct);
	void bringProductsFromDB();
	~APPServer();
};
