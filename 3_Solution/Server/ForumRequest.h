#pragma once
#include "ARequest.h"
class ForumRequest : public ARequest
{
private:

public:
	ForumRequest() = default;
	bool receiveRequest() override;
	bool sendAnswear() override;
	~ForumRequest() = default;
};

