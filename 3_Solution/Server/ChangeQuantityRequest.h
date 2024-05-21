#pragma once
#include "ARequest.h"
class ChangeQuantityRequest : public ARequest
{
private:

public:
	ChangeQuantityRequest();
	bool receiveRequest() override;
	bool sendAnswear() override;
	~ChangeQuantityRequest();
};

