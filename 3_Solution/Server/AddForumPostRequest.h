#pragma once
#include "ARequest.h"
class AddForumPostRequest : public ARequest
{
private:

public:
	AddForumPostRequest() = default;
	bool receiveRequest() override;
	bool sendAnswear() override;
	~AddForumPostRequest() = default;
};

