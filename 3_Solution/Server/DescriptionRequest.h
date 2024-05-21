#pragma once
#include "ARequest.h"

class DescriptionRequest : public ARequest
{
private:
	char* producerName;
	char* productDescription;
public:
	DescriptionRequest();
	bool receiveRequest() override;
	bool sendAnswear() override;
	~DescriptionRequest();
};

