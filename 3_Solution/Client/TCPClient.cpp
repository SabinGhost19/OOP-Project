#include "TCPClient.h"
#include "qpixmap.h"
#include <QPixmap>
#include <qdebug.h>
#include<iostream>

int TCPClient::sock_init()
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

TCPClient::TCPClient()
{
    sock_init();

    int iResult;
    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;

}
QPixmap TCPClient::receiveImage()
{
        int nrOfBytes = 0;
        char dimToRecvChar[50];
        nrOfBytes = recv(dimToRecvChar,50);
        nrOfBytes = send("ACCEPT",strlen("ACCEPT"));
        int dimToRecvInt;
        dimToRecvInt = atoi(dimToRecvChar);
        uint8_t* bufferToRecv=(uint8_t*)malloc(dimToRecvInt);
        memset(bufferToRecv,0,dimToRecvInt);

        uint8_t* bufferInter=(uint8_t*)malloc(static_cast<int>(40960));
        memset(bufferInter,0,40960);


        int bytesThatHasBeenSent=0;
        int i=1;
        std::string finalBuffer;
        for(i=1;i<=(dimToRecvInt/40960)+1;i++){
            if(dimToRecvInt - bytesThatHasBeenSent < 40960){
                nrOfBytes = recv((char*)bufferInter,dimToRecvInt - bytesThatHasBeenSent);
            }
            else{
                nrOfBytes = recv((char*)bufferInter,40960);
            }
            bytesThatHasBeenSent+=nrOfBytes;
            std::cout<<bytesThatHasBeenSent<<std::endl;
            memcpy(bufferToRecv+(i-1)*40960,bufferInter,nrOfBytes);
            memset(bufferInter,0,40960);

            nrOfBytes = send("ACCEPT",strlen("ACCEPT"));
        }

        QImage image;
        QByteArray byteArray = QByteArray::fromRawData(reinterpret_cast<const char*>(bufferToRecv), dimToRecvInt);
        image.loadFromData(byteArray,"PNG");
        QPixmap pixmap = QPixmap::fromImage(image);
        if (image.isNull()) {
            qDebug() << "Imaginea este goală!";
        }
        return pixmap;
}
void TCPClient::closeConnection()
{
    closesocket(this->sock);
    sock = NULL;
}
void TCPClient::connect(const char * ip_dest, short port_dest)
{
    int iResult;
    char port_str[6];
    _itoa_s(port_dest, port_str, 10);

    iResult = getaddrinfo(ip_dest, port_str, &hints, &ptr);
    if (iResult != 0) {
        printf("getaddrinfo failed with error: %d\n", iResult);
        WSACleanup();
        exit(-1);
    }

    sock = socket(ptr->ai_family, ptr->ai_socktype,
                  ptr->ai_protocol);

    if (sock == INVALID_SOCKET) {
        printf("socket failed with error: %ld\n", WSAGetLastError());
        WSACleanup();
        exit(-1);
    }

    iResult = ::connect(sock, ptr->ai_addr, (int)ptr->ai_addrlen);
    if (iResult == SOCKET_ERROR) {
        closesocket(sock);
        sock = INVALID_SOCKET;
    }

}

int TCPClient::send(const char * send_buff, const int size) const
{
    int send_bytes = ::send(sock, send_buff, size, 0);
    return send_bytes;
}

int TCPClient::recv(char* recv_buff, const int size) const
{
    int recv_bytes = ::recv(sock, recv_buff, size, 0);
    return recv_bytes;
}

SOCKET TCPClient::getSocket()
{
    return this->sock;
}

TCPClient::~TCPClient()
{
    this->closeConnection();
    WSACleanup();
}
