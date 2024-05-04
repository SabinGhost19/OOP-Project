#include "Product.h"

Product::Product()
{
	this->productID = 0;
	this->productName = NULL;
	this->productDescription = NULL;
	this->stockUnits = 0;
	this->price = 0;
	this->images.clear();
	this->reviews.clear();
}

Product::~Product()
{
	this->productID = 0;
	delete[] this->productName;
	delete[] this->productDescription;
	this->stockUnits = 0;
	this->price = 0;
	for (auto iterator : this->images)
		delete iterator;	
	for (auto iterator : this->reviews)
		delete iterator;
}
