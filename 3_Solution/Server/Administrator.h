#pragma once
#include "AClient.h"

class Product;

class Administrator : public AClient
{
protected:

public:
	Administrator() = default;
	virtual void sendInformations() override;
	bool listProduct(Product* productToAdd) override;
	bool deleteProduct() override;
	virtual char* getRole() override;
	~Administrator() = default;
};

