#pragma once
#include "ARequest.h"
class BuyProductRequest : public ARequest
{
private:
	bool result;
public:
	BuyProductRequest();
	bool receiveRequest() override;
	bool sendAnswear() override;
	~BuyProductRequest();
};

