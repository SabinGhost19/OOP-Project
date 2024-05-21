#define _CRT_SECURE_NO_WARNINGS
#include "SignUpRequest.h"
#include "CompanyBuilder.h"
#include "AdminBuilder.h"
#include "ClientBuilder.h"
#include "APPServer.h"
#include <iostream>

SignUpRequest::SignUpRequest()
{
	this->signUpResult = false;
}

bool SignUpRequest::receiveRequest()
{
	std::cout << "Client tries to sign up" << std::endl;
	int recvBytes = 0, sentBytes = 0;
	char ackBuffer[10]="";
	char clientRole[20]="";
	char email[50]="";
	char password[50]="";
	recvBytes = APPServer::getInstance()->getTcpServer()->recv(clientRole, sizeof(clientRole));
	clientRole[recvBytes] = '\0';
	sentBytes = APPServer::getInstance()->getTcpServer()->send("ACK", 4);
	recvBytes = APPServer::getInstance()->getTcpServer()->recv(email, sizeof(email));
	email[recvBytes] = '\0';
	sentBytes = APPServer::getInstance()->getTcpServer()->send("ACK", 4);
	recvBytes = APPServer::getInstance()->getTcpServer()->recv(password, sizeof(password));
	password[recvBytes] = '\0';
	sentBytes = APPServer::getInstance()->getTcpServer()->send("ACK", 4);
	char role[20];
	int existance = APPServer::getInstance()->getBDComm()->verifyEmailExistance(email); 

	//VERIFICA DACA EMAIL-UL ESTE DEJA INREGISTRAT
	if (existance)
	{
		sentBytes = APPServer::getInstance()->getTcpServer()->send("FALSE", 6); //FALSE IN CAZUL IN CARE CONTUL EXISTA DEJA 
		recvBytes = APPServer::getInstance()->getTcpServer()->recv(ackBuffer, sizeof(ackBuffer));
		cout << "THIS EMAIL HAS ALREADY BEEN SIGNED UP!" << endl;
		return false;
	}
	else
	{
		sentBytes = APPServer::getInstance()->getTcpServer()->send("TRUE", 5); //TRUE DACA NU
		recvBytes = APPServer::getInstance()->getTcpServer()->recv(ackBuffer, sizeof(ackBuffer));
	}

	if (strcmp(clientRole, "Client") == 0)
	{
		ClientBuilder builderForClient;
		APPServer::getInstance()->setManagedClient(builderForClient.buildClientFromSignUp(email,password));
		cout << "Client signed up succesfully" << endl;
		return true;
	}
	if (strcmp(clientRole, "Companie") == 0)
	{
		CompanyBuilder builderForClient;
		APPServer::getInstance()->setManagedClient(builderForClient.buildClientFromSignUp(email,password));
		cout << "Client signed up succesfully" << endl;
		return true;
	}
}

bool SignUpRequest::sendAnswear()
{
	return false;
}

SignUpRequest::~SignUpRequest()
{
	this->signUpResult = false;
}
