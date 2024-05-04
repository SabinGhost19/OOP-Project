#include "AClient.h"

AClient::~AClient()
{
	delete this->clientAccount;
}
