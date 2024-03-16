#pragma once
#undef UNICODE

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>


class TCPServer
{
private:
	short port;
	struct addrinfo* result = NULL;
	struct addrinfo hints;
	SOCKET listen_sock = NULL;
	SOCKET client_sock = NULL;

	int sock_init();
public:
	TCPServer(short listen_port);
	void wait_connection();
	SOCKET getClientSock() { return client_sock; };
	int send(const char const* send_buf, const int size) const;
	int recv(char* recv_buf, const int size) const;
};

