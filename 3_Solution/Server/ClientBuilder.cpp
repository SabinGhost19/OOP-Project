#include "ClientBuilder.h"
#include "APPServer.h"
#include <windows.h>
#include "Client.h"
#include <sqltypes.h>
#include <sql.h>
#include <sqlext.h>
#include <vector>

using namespace std;

ClientBuilder::ClientBuilder()
{
	this->ClientObj = new Client;
}

IClient* ClientBuilder::buildClient(char* email, char* password)
{
	this->ClientObj->logInAccount(email, password, (char*)"Client");
	vector<char*> clientInfoArray;
	clientInfoArray = APPServer::getInstance()->getBDComm()->getClientInfoByEmailAndPassword(email, password);
	static_cast<Client*>(this->ClientObj)->setClientID(atoi(clientInfoArray[0]));
	static_cast<Client*>(this->ClientObj)->setLastName(clientInfoArray[1]);
	static_cast<Client*>(this->ClientObj)->setFirstName(clientInfoArray[2]);
	static_cast<Client*>(this->ClientObj)->setTelephoneNo(clientInfoArray[3]);
	static_cast<Client*>(this->ClientObj)->setBirthDate(clientInfoArray[4]);
	static_cast<Client*>(this->ClientObj)->setBalance(atof(clientInfoArray[5]));

	Address* newBillingAddress = new Address;
	newBillingAddress->setPostalCode(clientInfoArray[6]);
	newBillingAddress->setCountry(clientInfoArray[7]);
	newBillingAddress->setCounty(clientInfoArray[8]);
	newBillingAddress->setTown(clientInfoArray[9]);
	newBillingAddress->setStreet(clientInfoArray[10]);
	newBillingAddress->setNr(clientInfoArray[11]);
	newBillingAddress->setEntrance(clientInfoArray[12]);
	newBillingAddress->setNrAppart(clientInfoArray[13]);
	static_cast<Client*>(this->ClientObj)->setBillingAddress(newBillingAddress);


	Address* newDeliveryAddress = new Address;
	newDeliveryAddress->setPostalCode(clientInfoArray[14]);
	newDeliveryAddress->setCountry(clientInfoArray[15]);
	newDeliveryAddress->setCounty(clientInfoArray[16]);
	newDeliveryAddress->setTown(clientInfoArray[17]);
	newDeliveryAddress->setStreet(clientInfoArray[18]);
	newDeliveryAddress->setNr(clientInfoArray[19]);
	newDeliveryAddress->setEntrance(clientInfoArray[20]);
	newDeliveryAddress->setNrAppart(clientInfoArray[21]);
	static_cast<Client*>(this->ClientObj)->setDeliveryAddress(newDeliveryAddress);

	for (auto iterator : clientInfoArray)
		delete[] iterator;
	clientInfoArray.clear();

	//DETERMINA DATE CARD
	Card* newCard = new Card;
	clientInfoArray = APPServer::getInstance()->getBDComm()->getCardInfoById(this->ClientObj->getClintId());
	if (clientInfoArray.size() == 0)
	{
		static_cast<Client*>(this->ClientObj)->setClientCard(nullptr);
		return this->ClientObj;
	}
	newCard->setCardNumber(clientInfoArray[0]);
	newCard->setOwnerName(clientInfoArray[1]);
	newCard->setExpirationDate(clientInfoArray[2]);
	newCard->setCVC(atoi(clientInfoArray[3]));
	static_cast<Client*>(this->ClientObj)->setClientCard(newCard);
	return this->ClientObj;
}

IClient* ClientBuilder::buildClientFromSignUp(char* email, char* password)
{
	int recvBytes = 0, sentBytes = 0;
	this->ClientObj->signUpAccount(email, password, (char*)"Client");
	int accountID = APPServer::getInstance()->getBDComm()->getAccountID(email, password);

	char lastName[50]="", firstName[50] = "", TelephoneNo[11] = "", BirthDate[15] = "";
	recvBytes = APPServer::getInstance()->getTcpServer()->recv(lastName, sizeof(lastName)); 
	sentBytes = APPServer::getInstance()->getTcpServer()->send("ACK", 4);
	lastName[recvBytes] = '\0';
	recvBytes = APPServer::getInstance()->getTcpServer()->recv(firstName, sizeof(firstName)); 
	sentBytes = APPServer::getInstance()->getTcpServer()->send("ACK", 4);
	firstName[recvBytes] = '\0';
	recvBytes = APPServer::getInstance()->getTcpServer()->recv(TelephoneNo, sizeof(TelephoneNo));
	sentBytes = APPServer::getInstance()->getTcpServer()->send("ACK", 4);
	TelephoneNo[recvBytes] = '\0';
	recvBytes = APPServer::getInstance()->getTcpServer()->recv(BirthDate, sizeof(BirthDate)); 
	sentBytes = APPServer::getInstance()->getTcpServer()->send("ACK", 4);
	BirthDate[recvBytes] = '\0';
	int clientID = 0;
	clientID = APPServer::getInstance()->getBDComm()->insertClientInfo(accountID,lastName, firstName, TelephoneNo, BirthDate);
	this->ClientObj->setClientID(clientID);
	static_cast<Client*>(this->ClientObj)->setLastName(lastName);
	static_cast<Client*>(this->ClientObj)->setFirstName(firstName);
	static_cast<Client*>(this->ClientObj)->setTelephoneNo(TelephoneNo);
	static_cast<Client*>(this->ClientObj)->setBirthDate(BirthDate);
	static_cast<Client*>(this->ClientObj)->setBalance(0);


	Address* newBillingAddress = new Address;
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
	newBillingAddress->setPostalCode(postalCode);
	newBillingAddress->setCountry(country);
	newBillingAddress->setCounty(county);
	newBillingAddress->setTown(town);
	newBillingAddress->setStreet(street);
	newBillingAddress->setNr(nr);
	newBillingAddress->setEntrance(entrance);
	newBillingAddress->setNrAppart(nrAppart);
	static_cast<Client*>(this->ClientObj)->setBillingAddress(newBillingAddress);
	int billingAddressId = APPServer::getInstance()->getBDComm()->insertAddress(postalCode, country, county, town, street, nr, entrance, nrAppart);


	Address* newDeliveryAddress = new Address;
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
	newDeliveryAddress->setPostalCode(postalCode);
	newDeliveryAddress->setCountry(country);
	newDeliveryAddress->setCounty(county);
	newDeliveryAddress->setTown(town);
	newDeliveryAddress->setStreet(street);
	newDeliveryAddress->setNr(nr);
	newDeliveryAddress->setEntrance(entrance);
	newDeliveryAddress->setNrAppart(nrAppart);
	static_cast<Client*>(this->ClientObj)->setDeliveryAddress(newDeliveryAddress);
	int deliveryAddressId = APPServer::getInstance()->getBDComm()->insertAddress(postalCode, country, county, town, street, nr, entrance, nrAppart);

	APPServer::getInstance()->getBDComm()->setAddressForClient(clientID, billingAddressId, deliveryAddressId);
	static_cast<Client*>(this->ClientObj)->setClientCard(nullptr);
	return this->ClientObj;
}

ClientBuilder::~ClientBuilder()
{
	return;
}
