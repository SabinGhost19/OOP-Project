#pragma once
#include "ARequest.h"
#include "IClient.h"

class SignInRequest : public ARequest
{
private:
	bool signInResult;
public:
	SignInRequest();
	bool receiveRequest() override;
	bool sendAnswear() override;
	~SignInRequest();
};

