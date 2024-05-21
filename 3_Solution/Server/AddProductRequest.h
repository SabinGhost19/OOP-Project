#pragma once
#include "ARequest.h"
class AddProductRequest : public ARequest
{
private:

public:
	AddProductRequest() = default;
	virtual bool receiveRequest() override;
	virtual bool sendAnswear() override;
	~AddProductRequest() = default;
};

