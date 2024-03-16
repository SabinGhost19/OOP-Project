// Need to link with Ws2_32.lib
#pragma comment (lib, "Ws2_32.lib")
#include "TCPServer.h"
#include "Utils.h"

int main() {
	sock_init();
	
	TCPServer *server = new TCPServer(12345);
	
	// blocks untill someone connects
	server->wait_connection();

	char buffer[1024];
	for (;;) {
		int recv_bytes = server->recv(buffer, 1024);
		fwrite(buffer, 1, recv_bytes, stderr);
	}

}