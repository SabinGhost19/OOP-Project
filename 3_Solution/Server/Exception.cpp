#define _CRT_SECURE_NO_WARNINGS
#include "Exception.h"
#include "ServerLogger.h"
#include <cstring>

Exception::Exception(const char* msgError)
{
	this->msg = new char(strlen(msgError));
	strcpy(this->msg, msgError);

	ServerLogger::getInstance("ExceptionLogger.txt")->loggAction(msg);
}

char* Exception::what()
{
	return this->msg;
}

Exception::~Exception()
{
	delete[] this->msg;
}