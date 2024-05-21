#pragma once
#include "ARequest.h"
class AddMoneyRequest : public ARequest
{
private:

public:
	AddMoneyRequest() = default;
	bool receiveRequest() override;
	bool sendAnswear() override;
	~AddMoneyRequest() = default;
};

