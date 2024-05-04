#pragma once
#include "AClient.h"
#include "Address.h"
#include "Product.h"
#include <vector>
using namespace std;

class Client : public AClient
{
protected:
	Address* deliveryAddress;
	Address* billingAddress;
	vector<Product*> buyingCart;
	vector<Product*> wishList;
public:
	Client();
	~Client();
};

