#pragma once
#include "IRequest.h"

class IClient;
class Product;
class Address;

class ARequest : public IRequest
{
private:

public:
	ARequest() = default;
	virtual bool receiveRequest() = 0;
	virtual bool sendAnswear() = 0;
	void sendAccountDetails(IClient* client);
	void sendClientAddress(Address* address);
	void sendProductMainInfo(Product* product);
	virtual ~ARequest() = default;
};

