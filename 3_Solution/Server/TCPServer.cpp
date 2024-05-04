#define _CRT_SECURE_NO_WARNINGS
#include "TCPServer.h"
#include "Exception.h"
#include "ServerLogger.h"
#include <fstream>
#include <iostream>
#include <stdint.h>
#include <string>

int n = 0;

int TCPServer::sock_init()
{
    WSADATA wsaData;
    int iResult;

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
    std::string loggAction = "CLIENT ON SOCKET ";
    loggAction += std::to_string(client_sock);
    loggAction += " CONNECTED";

    ServerLogger::getInstance("SocketActivity.txt")->loggAction(loggAction.c_str());
    if (client_sock == INVALID_SOCKET) {
        printf("accept failed with error: %d\n", WSAGetLastError());
        closesocket(listen_sock);
        WSACleanup();
        exit(-1);
    }
    fprintf(stderr, "Connected\n");
}

bool TCPServer::closeConnection()
{
    closesocket(client_sock);
    client_sock = NULL;
    std::string loggAction = "CLIENT ON SOCKET ";
    loggAction += std::to_string(client_sock);
    loggAction += " DISCONNECTED";
    ServerLogger::getInstance("SocketActivity.txt")->loggAction(loggAction.c_str());
    return true;
}

int TCPServer::send(const char const* send_buff, const int size)
{
    int send_bytes = ::send(client_sock, send_buff, size, 0);
	return send_bytes;
}

int TCPServer::recv(char* recv_buff, const int size)
{
    int recv_bytes = ::recv(client_sock, recv_buff, size, 0);
    return recv_bytes;
}

int TCPServer::sendImage(const char* imageName)
{
    FILE* file;
    if(n%2==0)
        file = fopen("C:\\Users\\George\\Desktop\\Proiect POO\\OPP-Project\\3_Solution\\sigla.png", "rb");
    else
        file = fopen("C:\\Users\\George\\Desktop\\download.png", "rb");
    n++;
    if (!file) {
        throw "Eroare la deschidere fisier";
    }
    fseek(file, 0, SEEK_END);
    int imgDim = ftell(file);
    fseek(file, 0, SEEK_SET);
    char imgDimChar[50];
    _itoa(imgDim, imgDimChar, 10);
    int sentBytes = send(imgDimChar, strlen(imgDimChar));
    char accBuffer[50];
    int nrOfBytes = recv(accBuffer, 50);
    uint8_t* buffer = (uint8_t*)malloc(40960 * sizeof(uint8_t));
    int bytesRemained = imgDim;
    int bytesthatHasBeenSent=0;
    for (int i = 1; i <= (imgDim / 40960)+1; i++)
    {
        if (bytesRemained < 40960)
        {
            fread(buffer, 1, bytesRemained, file);
            sentBytes = send((const char*)buffer, bytesRemained);
            bytesthatHasBeenSent -= sentBytes;
        }
        else
        {
            fread(buffer, 1, 40960, file);
            sentBytes = send((const char*)buffer, 40960);
            bytesthatHasBeenSent -= sentBytes;
        }
        bytesRemained -= 40960;
        std::cout << sentBytes<<std::endl;
        nrOfBytes = recv(accBuffer, 50);
        memset(buffer, 40960, 0);
    }
    fclose(file);
    std::cout << bytesthatHasBeenSent;
}

TCPServer::~TCPServer()
{
    WSACleanup();
}
