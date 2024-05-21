#include "ImageRequest.h"
#include "APPServer.h"
#include "Product.h"
#include <string>
#include <iostream>



ImageRequest::ImageRequest()
{
	this->imagesPaths.clear();
}

bool ImageRequest::receiveRequest()
{
	int recvBytes = 0, sentBytes = 0;
	char productIDChar[10];
	recvBytes = APPServer::getInstance()->getTcpServer()->recv(productIDChar, sizeof(productIDChar));
	sentBytes = APPServer::getInstance()->getTcpServer()->send("ACK", strlen("ACK"));
	productIDChar[recvBytes] = '\0';
	std::cout << "Trying to send images for product: " << productIDChar <<endl;
	std::string productIDString = productIDChar;
	int productIDInt = std::stoi(productIDString);
	for (auto iterator : APPServer::getInstance()->getListedProducts())
	{
		if (iterator->getProductId() == productIDInt)
		{
			this->imagesPaths = iterator->getAllImages();
			return true;
		}
	}
	return false;
}

bool ImageRequest::sendAnswear()
{
	int recvBytes = 0, sentBytes = 0;
	char ackBuffer[10] = "";
	int nrOfImagesWithoutFirst = this->imagesPaths.size() - 1;
	string nrOfImagesStr = std::to_string(nrOfImagesWithoutFirst);
	sentBytes = APPServer::getInstance()->getTcpServer()->send(nrOfImagesStr.c_str(), nrOfImagesStr.size());
	recvBytes = APPServer::getInstance()->getTcpServer()->recv(ackBuffer, sizeof(ackBuffer));
	for (int i = 1; i < this->imagesPaths.size(); i++)
		APPServer::getInstance()->getTcpServer()->sendImage(this->imagesPaths[i]);
	std::cout << "Images has been sent successfully!" << endl;
	return true;
}

ImageRequest::~ImageRequest()
{
	this->imagesPaths.clear();
}
