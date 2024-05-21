#pragma once
#include "ARequest.h"
class FirstImageRequest : public ARequest
{
private:

public:
	FirstImageRequest() = default;
	bool receiveRequest() override;
	bool sendAnswear() override;
	~FirstImageRequest() = default;
};

