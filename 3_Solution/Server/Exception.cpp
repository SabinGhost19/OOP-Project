#define _CRT_SECURE_NO_WARNINGS
#include "Exception.h"
#include "ServerLogger.h"
#include <cstring>

Exception::~Exception()
{
	msg = "";
}
