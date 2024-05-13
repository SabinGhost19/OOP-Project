#include "CompanyAddRequest.h"
#include"APPClient.h"
#include<fstream>
#include<iostream>
#include <cstdio>

CompanyAddRequest::CompanyAddRequest() {}

void CompanyAddRequest::sendImage(std::string filename){

    FILE* file;
    if (!file) {
        throw "Eroare la deschidere fisier";
    }

    file=fopen(filename.c_str(), "rb");

    fseek(file, 0, SEEK_END);
    int imgDim = ftell(file);
    fseek(file, 0, SEEK_SET);
    char imgDimChar[50];
    _itoa(imgDim, imgDimChar, 10);
    int sentBytes = APPClient::getInstance()->getTcpClient()->send(imgDimChar, strlen(imgDimChar));
    char accBuffer[50];
    int nrOfBytes = APPClient::getInstance()->getTcpClient()->recv(accBuffer, 50);
    uint8_t* buffer = (uint8_t*)malloc(40960 * sizeof(uint8_t));
    int bytesRemained = imgDim;
    int bytesthatHasBeenSent=0;
    for (int i = 1; i <= (imgDim / 40960)+1; i++)
    {
        if (bytesRemained < 40960)
        {
            fread(buffer, 1, bytesRemained, file);
            sentBytes = APPClient::getInstance()->getTcpClient()->send((const char*)buffer, bytesRemained);
            bytesthatHasBeenSent -= sentBytes;
        }
        else
        {
            fread(buffer, 1, 40960, file);
            sentBytes = APPClient::getInstance()->getTcpClient()->send((const char*)buffer, 40960);
            bytesthatHasBeenSent -= sentBytes;
        }
        bytesRemained -= 40960;
        std::cout << sentBytes<<std::endl;
        nrOfBytes = APPClient::getInstance()->getTcpClient()->recv(accBuffer, 50);
        memset(buffer, 40960, 0);
    }
    fclose(file);

    free (buffer);
    std::cout << bytesthatHasBeenSent;

}
void CompanyAddRequest::sendText(std::string text){
    this->message=text;
    if(!this->Request()){
        std::cout<<"Trimitere text Companie ESUATA!!!!!!!!!";
    }
}
