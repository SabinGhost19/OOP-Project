#pragma once
#include <exception>
#include "ServerLogger.h"
#include <string>

class Exception : public std::exception
{
protected:
	std::string msg;
public:
	Exception(const char* msgError) : msg(msgError) {};
	virtual char const* what() const { return msg.c_str(); };
	~Exception();
};
