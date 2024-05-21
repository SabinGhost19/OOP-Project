#pragma once
#include "AClient.h"
#include "Address.h"
#include "Product.h"
#include <vector>

using namespace std;

class Company : public AClient
{
private:
	char companyName[100];
	Address* fiscalAddress;
	vector<Product*> listedProducts;
	double profit;
public:
	Company();
	void setCompanyName(char* name);
	void setCompanyProfit(double newProfit);
	void setFiscalAddress(Address* addressToSet);
	virtual void sendInformations() override;
	bool listProduct(Product* productToAdd) override;
	void addProduct(Product* productToAdd);
	bool deleteProduct() override;
	void setCompanyFiscalAddress(Address* address);
	Address* getCompanyFiscalAddress() override;
	char* getName() override;
	virtual char* getRole() override;
	vector<Product*> getListedProducts();
	double getCompanyProfit();
	~Company();
};

