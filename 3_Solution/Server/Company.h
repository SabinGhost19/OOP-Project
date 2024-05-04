#pragma once
#include "AClient.h"
#include "Address.h"
#include "Product.h"
#include <vector>

using namespace std;

class Company : public AClient
{
private:
	Address* fiscalAddress;
	vector<Product*> listedProducts;
public:
	Company();
	~Company();
};

