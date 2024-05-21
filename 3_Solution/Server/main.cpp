#pragma comment (lib, "Ws2_32.lib")
#include "APPServer.h"
#include "Exception.h"
#include <iostream>

int main() {
	APPServer::getInstance()->getTcpServer()->wait_connection();
	char buffer[1024];
	for (;;) {
		int recv_bytes = APPServer::getInstance()->getTcpServer()->recv(buffer, 1024);
		if (recv_bytes > 0) {
			buffer[recv_bytes] = '\0';
			APPServer::getInstance()->manageRequest(buffer);
		}
		else if (recv_bytes <= 0)
		{
			APPServer::getInstance()->getTcpServer()->closeConnection();
			APPServer::getInstance()->getTcpServer()->wait_connection();
		}
	}
}