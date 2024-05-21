#pragma once
#include "ARequest.h"

class SignUpRequest : public ARequest
{
private:
	bool signUpResult;
public:
	SignUpRequest();
	bool receiveRequest() override;
	bool sendAnswear() override;
	~SignUpRequest();
};

