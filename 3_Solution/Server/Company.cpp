#include "Company.h"

Company::Company()
{
	this->fiscalAddress = NULL;
	this->listedProducts.clear();
}

Company::~Company()
{
	delete this->fiscalAddress;
	for (auto iterator : this->listedProducts)
		delete iterator;
}
