#pragma once
#include "ARequest.h"
class ChangePriceRequest : public ARequest
{
private:

public:
	ChangePriceRequest() = default;
	bool receiveRequest() override;
	bool sendAnswear() override;
	~ChangePriceRequest() = default;
};

