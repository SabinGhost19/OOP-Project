#pragma once
#include "IClient.h"
#include "Account.h"
class AClient : public IClient
{
protected:
	int ClientID;
	Account* clientAccount;
public:
	AClient();
	bool signUpAccount(char* email, char* password, char* functie) override;
	bool logInAccount(char* email, char* password, char* functie) override;
	virtual void sendInformations() = 0;
	void setClientID(int idToSet) override;
	virtual bool buyProduct(int productID, int quantity) override;
	virtual Address* getClientBillingAddress() override;
	virtual Address* getClientDeliveryAddress() override;
	virtual Address* getCompanyFiscalAddress() override;
	virtual Account* getAccount() override;
	virtual char* getName() override;
	virtual int getClintId() override;
	virtual char* getRole() = 0;
	virtual bool listProduct(Product* productToAdd) = 0;
	virtual bool deleteProduct() = 0;
	bool addReview() override;
	virtual ~AClient();
};

