#pragma once
#include "AClient.h"
#include "Address.h"
#include "Product.h"
#include "Card.h"
#include <vector>

using namespace std;

class Client : public AClient
{
protected:
	char lastName[50];
	char firstName[50];
	char telephoneNo[11];
	char BirthDate[15];
	float balance;
	Address* deliveryAddress;
	Address* billingAddress;
	Card* clientCard;
public:
	Client();
	virtual void sendInformations() override;
	bool listProduct(Product* productToAdd) override;
	void setLastName(char* lastNameToSet);
	void setFirstName(char* firstNameToSet);
	void setTelephoneNo(char* telephoneNoToSet);
	void setBirthDate(char* birthDateToSet);
	void setDeliveryAddress(Address* addressToSet);
	void setBillingAddress(Address* addressToSet);
	void setClientCard(Card* cardToSet);
	void setBalance(float balanceToSet);
	bool buyProduct(int productID, int quantity) override;
	Address* getClientDeliveryAddress() override;
	Address* getClientBillingAddress() override;
	Card* getClientCard(Card* card);
	virtual char* getName() override;
	virtual char* getRole() override;
	char* getTelephone();
	char* getBirthDate();
	float getBalance();
	bool deleteProduct() override;
	~Client();
};

