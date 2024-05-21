#pragma once
#include "ARequest.h"
class ChangePasswdRequest : public ARequest
{
private:

public:
	ChangePasswdRequest() = default;
	bool receiveRequest() override;
	bool sendAnswear() override;
	~ChangePasswdRequest() = default;
};

