#include "TCPServer.h"

int TCPServer::sock_init()
{
    WSADATA wsaData;
    int iResult;

    // Initialize Winsock
    iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != 0) {
        printf("WSAStartup failed with error: %d\n", iResult);
        return -1;
    }

    return 0;
}

TCPServer::TCPServer(short listen_port) : port(listen_port)
{
    sock_init();

    int iResult;

    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;
    hints.ai_flags = AI_PASSIVE;

    char port_str[6];
    _itoa_s(listen_port, port_str, 10);

    // Resolve the server address and port
    iResult = getaddrinfo(NULL, port_str, &hints, &result);
    if (iResult != 0) {
        printf("getaddrinfo failed with error: %d\n", iResult);
        WSACleanup();
        exit(-1);
    }

    listen_sock = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (listen_sock == INVALID_SOCKET) {
        printf("socket failed with error: %ld\n", WSAGetLastError());
        WSACleanup();
        exit(-1);
    }

    iResult = bind(listen_sock, result->ai_addr, (int)result->ai_addrlen);
    if (iResult == SOCKET_ERROR) {
        printf("bind failed with error: %d\n", WSAGetLastError());
        closesocket(listen_sock);
        WSACleanup();
        exit(-1);
    }

    iResult = listen(listen_sock, SOMAXCONN);
    if (iResult == SOCKET_ERROR) {
        printf("listen failed with error: %d\n", WSAGetLastError());
        closesocket(listen_sock);
        WSACleanup();
        exit(-1);
    }

}

void TCPServer::wait_connection()
{
    client_sock = accept(listen_sock, NULL, NULL);
    if (client_sock == INVALID_SOCKET) {
        printf("accept failed with error: %d\n", WSAGetLastError());
        closesocket(listen_sock);
        WSACleanup();
        exit(-1);
    }
    fprintf(stderr, "Connected\n");
}

int TCPServer::send(const char const* send_buff, const int size) const
{
    int send_bytes = ::send(client_sock, send_buff, size, 0);
	return send_bytes;
}

int TCPServer::recv(char* recv_buff, const int size) const
{
    int recv_bytes = ::recv(client_sock, recv_buff, size, 0);
    return recv_bytes;
}
