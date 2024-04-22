#pragma once
#include <exception>

class Exception : public std::exception
{
protected:
	char* msg;
public:
	Exception(const char* msgError);
	char* what();
	~Exception();
};
