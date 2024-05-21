#define _CRT_SECURE_NO_WARNINGS
#include "SignInRequest.h"
#include "APPServer.h"
#include "Account.h"
#include "ClientBuilder.h"
#include "AdminBuilder.h"
#include "CompanyBuilder.h"
#include "Product.h"
#include "Company.h"
#include "Exception.h"
#include <vector>
#include <string>
#include <iostream>


SignInRequest::SignInRequest()
{
	this->signInResult = false;
}

bool SignInRequest::receiveRequest()
{
	std::cout << "Client tries to sign in" << std::endl;
	char email[50];
	char password[50];
	char role[20] = {};
	int recv_bytes = 0, sent_bytes = 0;
	recv_bytes = APPServer::getInstance()->getTcpServer()->recv(email, 50);
	email[recv_bytes] = '\0';
	sent_bytes = APPServer::getInstance()->getTcpServer()->send("ACK", 4);
	recv_bytes = APPServer::getInstance()->getTcpServer()->recv(password, 50);
	password[recv_bytes] = '\0';
	sent_bytes = APPServer::getInstance()->getTcpServer()->send("ACK", 4);
	try {
		strcpy(role, APPServer::getInstance()->getBDComm()->verifyAccountLogIn(email, password));
	}
	catch (exception& myException)
	{
		this->signInResult = false;
		std::cout << myException.what() << std::endl;
		return false;
	}
	if (strcmp(role, "Client") == 0)
	{
		this->signInResult = true;
		ClientBuilder builderForClient;
		APPServer::getInstance()->setManagedClient(builderForClient.buildClient(email, password));
		return true;
	}
	else if (strcmp(role, "Admin") == 0)
	{
		this->signInResult = true;
		AdminBuilder builderForAdmin;
		APPServer::getInstance()->setManagedClient(builderForAdmin.buildClient(email, password));
		return true;
	}
	else if (strcmp(role, "Companie") == 0)
	{
		this->signInResult = true;
		CompanyBuilder builderForCompany;
		APPServer::getInstance()->setManagedClient(builderForCompany.buildClient(email, password));
		return true;
	}
	else
	{
		this->signInResult = false;
		return false;
		throw "ERROR WHILE TRYING TO FIND ROLE";
	}
}

bool SignInRequest::sendAnswear()
{
	int sentBytes = 0, recvBytes = 0;
	char recvBuffer[10];
	if (!this->signInResult)
	{
		sentBytes = APPServer::getInstance()->getTcpServer()->send("FALSE", 6);
		recvBytes = APPServer::getInstance()->getTcpServer()->recv(recvBuffer, 10);
		return false;
	}
	sentBytes = APPServer::getInstance()->getTcpServer()->send("TRUE", 5);
	recvBytes = APPServer::getInstance()->getTcpServer()->recv(recvBuffer, 10);
	char role[10];
	strcpy(role, APPServer::getInstance()->getManagedClient()->getRole());
	if(strcmp(role,"Client")==0)
		sentBytes = APPServer::getInstance()->getTcpServer()->send("0", 2);
	else if(strcmp(role,"Companie")==0)
		sentBytes = APPServer::getInstance()->getTcpServer()->send("1", 2);
	else if(strcmp(role,"Admin")==0)
		sentBytes = APPServer::getInstance()->getTcpServer()->send("2", 2);
	recvBytes = APPServer::getInstance()->getTcpServer()->recv(recvBuffer, 10);
	
	//TRIMITEREA INFORMATII LEGATE DE CLIENT (NUME,PRENUME,ID,ADRESA FACTURARE SI LIVRARE,NR TELEFON, DATA NASTERII
	APPServer::getInstance()->getManagedClient()->sendInformations();
	
	//TRIMITEREA INFORMATIILE NECESARE PENTRU AFISAREA PRODUSELOR IN DASHBOARD DOAR PENTRU CLIENT
	if (strcmp(APPServer::getInstance()->getManagedClient()->getRole(), "Client") == 0)
	{
		//TRIMITEREA NUMAR DE PRODUSE
		int nrOfProducts = APPServer::getInstance()->getListedProducts().size();
		std::string nrOfProductsString = std::to_string(nrOfProducts);
		sentBytes = APPServer::getInstance()->getTcpServer()->send(nrOfProductsString.c_str(), nrOfProductsString.size());
		recvBytes = APPServer::getInstance()->getTcpServer()->recv(recvBuffer, 10);

		//TRIMITEREA EFECTIVA DOAR A INFORMATIILOR NECESARE PENTRU AFISAREA PRODUSELOR IN DASHBOARD
		for (auto iterator : APPServer::getInstance()->getListedProducts())
			this->sendProductMainInfo(iterator);
	}
	else
	{
		////TRIMITEREA PRODUSELOR LISTATE DE COMPANIE
		//int nrOfProducts = static_cast<Company*>(APPServer::getInstance()->getManagedClient())->getListedProducts().size();
		//std::string nrOfProductsString = std::to_string(nrOfProducts);
		//sentBytes = APPServer::getInstance()->getTcpServer()->send(nrOfProductsString.c_str(), nrOfProductsString.size());
		//recvBytes = APPServer::getInstance()->getTcpServer()->recv(recvBuffer, 10);

		//std::vector<Product*> listedProductsByCompany = static_cast<Company*>(APPServer::getInstance()->getManagedClient())->getListedProducts();
		//for (auto iterator : listedProductsByCompany)
		//{
		//	this->sendProductMainInfo(iterator);
		//	std::string stockUnits = std::to_string(iterator->getStocUnits());
		//	sentBytes = APPServer::getInstance()->getTcpServer()->send(stockUnits.c_str(), stockUnits.size());
		//	recvBytes = APPServer::getInstance()->getTcpServer()->recv(recvBuffer, 10);
		//}
	}
	
	cout << "Client signed in succesfully" << endl;
	return true;
}

SignInRequest::~SignInRequest()
{
	this->signInResult = false;
}
