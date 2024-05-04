#pragma once
#include "IClient.h"
#include "Account.h"
class AClient : public IClient
{
protected:
	Account* clientAccount;
public:
	bool signUpAccount() override;
	bool logInAccount() override;
	bool addProductToCart() override;
	bool addProductToFav() override;
	virtual bool listProduct() = 0;
	virtual bool deleteProduct() = 0;
	bool addReview() override;
	virtual ~AClient();
};

