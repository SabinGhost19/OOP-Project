#pragma once
class IRequest
{
private:

public:
	IRequest() = default;
	virtual bool receiveRequest() = 0;
	virtual bool sendAnswear() = 0;
	virtual ~IRequest() = default;
};

