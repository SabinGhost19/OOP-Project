#include "Address.h"
#include <string.h>
Address::Address()
{
	memset(this->postalCode, 0, 10);
	memset(this->country, 0, 30);
	memset(this->county, 0, 20);
	memset(this->town, 0, 30);
	memset(this->street, 0, 60);
	memset(this->nr, 0, 15);
	memset(this->entrance, 0, 10);
	this->nrAppart = 0;
}

Address::~Address()
{
	memset(this->postalCode, 0, 10);
	memset(this->country, 0, 30);
	memset(this->county, 0, 20);
	memset(this->town, 0, 30);
	memset(this->street, 0, 60);
	memset(this->nr, 0, 15);
	memset(this->entrance, 0, 10);
	this->nrAppart = 0;
}
