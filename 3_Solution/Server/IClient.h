#pragma once
#include <vector>

using namespace std;

class Address;
class Account;
class Product;

class IClient
{
protected:

public:
	IClient() = default;
	virtual bool signUpAccount(char* email, char* password, char* role) = 0;
	virtual bool logInAccount(char* email, char* password, char* functie) = 0;
	virtual void sendInformations() = 0;
	virtual bool listProduct(Product* productToAdd) = 0;
	virtual bool deleteProduct() = 0;
	virtual bool addReview() = 0;
	virtual bool buyProduct(int productID, int quantity) = 0;
	virtual void setClientID(int idToSet) = 0;
	virtual Address* getClientBillingAddress() = 0;
	virtual Address* getClientDeliveryAddress() = 0;
	virtual Address* getCompanyFiscalAddress() = 0;
	virtual Account* getAccount() = 0;
	virtual int getClintId() = 0;
	virtual char* getName() = 0;
	virtual char* getRole() = 0;
	virtual ~IClient() = default;
};