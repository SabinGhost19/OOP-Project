#include "Client.h"

Client::Client()
{
	deliveryAddress = NULL;
	billingAddress = NULL;
	buyingCart.clear();
	wishList.clear();
}

Client::~Client()
{
	delete deliveryAddress;
	delete billingAddress;
	for (auto iterator : this->buyingCart)
		delete iterator;	
	for (auto iterator : this->wishList)
		delete iterator;

}
