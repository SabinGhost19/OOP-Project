// Need to link with Ws2_32.lib
#pragma comment (lib, "Ws2_32.lib")
#include "APPServer.h"

int main() {
	
	// blocks untill someone connects
	APPServer::getInstance()->getTcpServer()->wait_connection();
	char buffer[1024];
	for (;;) {
		int recv_bytes = APPServer::getInstance()->getTcpServer()->recv(buffer, 1024);
		buffer[recv_bytes] = '\0';
		APPServer::getInstance()->manageRequest(buffer);
	}

}