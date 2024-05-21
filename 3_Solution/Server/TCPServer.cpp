#define _CRT_SECURE_NO_WARNINGS
#include "TCPServer.h"
#include "Exception.h"
#include "APPServer.h"
#include "ServerLogger.h"
#include <fstream>
#include <iostream>
#include <stdint.h>
#include <string>

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
    std::cout << "Waiting for connection: ";
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
    std::cout << "Client is closing connection" << endl;
    closesocket(client_sock);
    client_sock = NULL;
    std::string loggAction = "CLIENT ON SOCKET ";
    loggAction += std::to_string(client_sock);
    loggAction += " DISCONNECTED";
    ServerLogger::getInstance("SocketActivity.txt")->loggAction(loggAction.c_str());
    /*IClient* clientToDelete = APPServer::getInstance()->getManagedClient();
    delete clientToDelete;*/
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
    file = fopen(imageName, "rb");
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
        std::cout << bytesthatHasBeenSent << endl;
        bytesRemained -= 40960;
        nrOfBytes = recv(accBuffer, 50);
        memset(buffer, 40960, 0);
    }
    fclose(file);
    free(buffer);
    std::cout << "Image has been sent!" << std::endl;
}

char* TCPServer::recvImage()
{
    int nrOfBytes = 0;
    char dimToRecvChar[50];
    nrOfBytes = this->recv(dimToRecvChar, 50);

    nrOfBytes = this->send("ACK", strlen("ACK"));
    int dimToRecvInt;
    dimToRecvInt = atoi(dimToRecvChar);
    uint8_t* bufferToRecv = (uint8_t*)malloc(dimToRecvInt);
    memset(bufferToRecv, 0, dimToRecvInt);

    uint8_t* bufferInter = (uint8_t*)malloc(static_cast<int>(40960));
    memset(bufferInter, 0, 40960);


    int bytesThatHasBeenSent = 0;
    int i = 1;
    std::string finalBuffer;
    for (i = 1; i <= (dimToRecvInt / 40960) + 1; i++) {
        if (dimToRecvInt - bytesThatHasBeenSent < 40960) {
            nrOfBytes = this->recv((char*)bufferInter, dimToRecvInt - bytesThatHasBeenSent);
        }
        else {
            nrOfBytes = this->recv((char*)bufferInter, 40960);
        }
        bytesThatHasBeenSent += nrOfBytes;
        std::cout << bytesThatHasBeenSent << std::endl;
        memcpy(bufferToRecv + (i - 1) * 40960, bufferInter, nrOfBytes);
        memset(bufferInter, 0, 40960);

        nrOfBytes = this->send("ACK", strlen("ACK"));
    }

    char path[150] = "C:\\Users\\George\\Desktop\\Proiect POO\\OPP-Project\\3_Solution\\Server\\ImaginiSalvateDeServer\\";
    char imageNo[10];
    strcpy(imageNo, APPServer::getInstance()->getBDComm()->getNrOfImages());
    strcat(path, imageNo);
    strcat(path, ".png");
    FILE* f = fopen(path, "wb");
    fwrite(bufferToRecv, 1, bytesThatHasBeenSent, f);
    fclose(f);
    free(bufferToRecv);
    free(bufferInter);
    return path;
}

TCPServer::~TCPServer()
{
    WSACleanup();
}
