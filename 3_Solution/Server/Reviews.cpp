#include "Reviews.h"

Reviews::Reviews()
{
	this->note = 0;
	delete[] this->comment;
}

Reviews::~Reviews()
{
	this->note = 0;
	delete[] this->comment;
}
