#pragma once
class IClient
{
protected:

public:
	IClient() = default;
	virtual bool signUpAccount() = 0;
	virtual bool logInAccount() = 0;
	virtual bool addProductToCart() = 0;
	virtual bool addProductToFav() = 0;
	virtual bool listProduct() = 0;
	virtual bool deleteProduct() = 0;
	virtual bool addReview() = 0;
	virtual ~IClient() = default;
};

