#pragma once
#include "ARequest.h"
class AddCardRequest : public ARequest
{
private:
public:
	AddCardRequest() = default;
	bool receiveRequest() override;
	bool sendAnswear() override;
	~AddCardRequest() = default;
};

