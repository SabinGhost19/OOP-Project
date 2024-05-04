#pragma once
#include "Reviews.h"
#include <vector>

using namespace std;

class Product
{
private:
	int productID;
	char* productName;
	char* productDescription;
	int stockUnits;
	int price;
	vector<uint8_t*> images;
	vector<Reviews*> reviews;
public:
	Product();
	~Product();
};

