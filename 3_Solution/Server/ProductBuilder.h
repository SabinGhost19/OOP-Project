#pragma once
#include "Product.h"
#include <iostream>
#include <vector>

class ProductBuilder
{
private:
	Product* productObj;
public:
	ProductBuilder();
	Product* buildProductFromRequest();
	std::vector<Product*> buildProductsForCompany(int companyID);
	~ProductBuilder();
};

