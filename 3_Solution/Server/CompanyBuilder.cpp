#include "CompanyBuilder.h"
#include "Company.h"
#include "APPServer.h"
#include "ProductBuilder.h"
#include <vector>
#include <string>

using namespace std;

CompanyBuilder::CompanyBuilder()
{
	this->ClientObj = new Company;
}

IClient* CompanyBuilder::buildClient(char* email, char* password)
{
	vector<char*> companyInfoArray;
	this->ClientObj->logInAccount(email, password, (char*)"Companie");
	companyInfoArray = APPServer::getInstance()->getBDComm()->getCompanyInfoByEmailAndPassword(email, password);
	static_cast<Company*>(this->ClientObj)->setClientID(atoi(companyInfoArray[0]));
	static_cast<Company*>(this->ClientObj)->setCompanyName(companyInfoArray[1]);


	Address* newFiscalAddress = new Address;
	newFiscalAddress->setPostalCode(companyInfoArray[2]);
	newFiscalAddress->setCountry(companyInfoArray[3]);
	newFiscalAddress->setCounty(companyInfoArray[4]);
	newFiscalAddress->setTown(companyInfoArray[5]);
	newFiscalAddress->setStreet(companyInfoArray[6]);
	newFiscalAddress->setNr(companyInfoArray[7]);
	newFiscalAddress->setEntrance(companyInfoArray[8]);
	newFiscalAddress->setNrAppart(companyInfoArray[9]);
	static_cast<Company*>(this->ClientObj)->setFiscalAddress(newFiscalAddress);
	
	string companyProfit = companyInfoArray[10];
	double companyProfitDouble = stod(companyProfit);
	static_cast<Company*>(this->ClientObj)->setCompanyProfit(companyProfitDouble);

	//ADAUGA PRODUSE LISTATE
	ProductBuilder productBuilder;
	vector<Product*> listedProducts = productBuilder.buildProductsForCompany(this->ClientObj->getClintId());
	for (auto iterator : listedProducts)
	{
		for (auto iterator2 : APPServer::getInstance()->getBDComm()->getProductPhotos(iterator->getProductId()))
			iterator->addImagePath(iterator2);
		static_cast<Company*>(this->ClientObj)->addProduct(iterator);
	}
	return this->ClientObj;
}

IClient* CompanyBuilder::buildClientFromSignUp(char* email, char* password)
{
	int recvBytes = 0, sentBytes = 0;
	this->ClientObj->signUpAccount(email, password, (char*)"Companie");
	int accountID = APPServer::getInstance()->getBDComm()->getAccountID(email, password);

	char companyName[100] = "";
	recvBytes = APPServer::getInstance()->getTcpServer()->recv(companyName, sizeof(companyName));
	sentBytes = APPServer::getInstance()->getTcpServer()->send("ACK", 4);
	companyName[recvBytes] = '\0';

	Address* fiscalAddress = new Address;
	char postalCode[10] = "", country[30] = "", county[20] = "", town[30] = "", street[60] = "", nr[15] = "", entrance[10] = "", nrAppart[15] = "";
	recvBytes = APPServer::getInstance()->getTcpServer()->recv(postalCode, sizeof(postalCode));
	sentBytes = APPServer::getInstance()->getTcpServer()->send("ACK", 4);
	postalCode[recvBytes] = '\0';
	recvBytes = APPServer::getInstance()->getTcpServer()->recv(country, sizeof(country));
	sentBytes = APPServer::getInstance()->getTcpServer()->send("ACK", 4);
	country[recvBytes] = '\0';
	recvBytes = APPServer::getInstance()->getTcpServer()->recv(county, sizeof(county));
	sentBytes = APPServer::getInstance()->getTcpServer()->send("ACK", 4);
	county[recvBytes] = '\0';
	recvBytes = APPServer::getInstance()->getTcpServer()->recv(town, sizeof(town));
	sentBytes = APPServer::getInstance()->getTcpServer()->send("ACK", 4);
	town[recvBytes] = '\0';
	recvBytes = APPServer::getInstance()->getTcpServer()->recv(street, sizeof(street));
	sentBytes = APPServer::getInstance()->getTcpServer()->send("ACK", 4);
	street[recvBytes] = '\0';
	recvBytes = APPServer::getInstance()->getTcpServer()->recv(nr, sizeof(nr));
	sentBytes = APPServer::getInstance()->getTcpServer()->send("ACK", 4);
	nr[recvBytes] = '\0';
	recvBytes = APPServer::getInstance()->getTcpServer()->recv(entrance, sizeof(entrance));
	sentBytes = APPServer::getInstance()->getTcpServer()->send("ACK", 4);
	entrance[recvBytes] = '\0';
	recvBytes = APPServer::getInstance()->getTcpServer()->recv(nrAppart, sizeof(nrAppart));
	sentBytes = APPServer::getInstance()->getTcpServer()->send("ACK", 4);
	nrAppart[recvBytes] = '\0';
	fiscalAddress->setPostalCode(postalCode);
	fiscalAddress->setCountry(country);
	fiscalAddress->setCounty(county);
	fiscalAddress->setTown(town);
	fiscalAddress->setStreet(street);
	fiscalAddress->setNr(nr);
	fiscalAddress->setEntrance(entrance);
	fiscalAddress->setNrAppart(nrAppart);
	static_cast<Company*>(this->ClientObj)->setCompanyFiscalAddress(fiscalAddress);
	int fiscalAddressID = APPServer::getInstance()->getBDComm()->insertAddress(postalCode, country, county, town, street, nr, entrance, nrAppart);
	int companyID = APPServer::getInstance()->getBDComm()->insertCompanyInfo(accountID, companyName, fiscalAddressID);
	this->ClientObj->setClientID(companyID);
	static_cast<Company*>(this->ClientObj)->setCompanyProfit(0);
	return this->ClientObj;
}

CompanyBuilder::~CompanyBuilder()
{
	return;
}
