#define _CRT_SECURE_NO_WARNINGS
#include "Card.h"
#include <string.h>

Card::Card()
{
	this->cardNumber = nullptr;
	this->CVC = 0;
	this->expirationDate = nullptr;
	this->ownerName = nullptr;
}

void Card::setCardNumber(char* cardNumber)
{
	this->cardNumber = new char[strlen(cardNumber) + 1];
	strcpy(this->cardNumber, cardNumber);
}

void Card::setOwnerName(char* ownerName)
{
	this->ownerName = new char[strlen(ownerName) + 1];
	strcpy(this->ownerName, ownerName);
}

void Card::setExpirationDate(char* expirationDate)
{
	this->expirationDate = new char[strlen(expirationDate) + 1];
	strcpy(this->expirationDate, expirationDate);
}

void Card::setCVC(int CVC)
{
	this->CVC = CVC;
}

char* Card::getCardNumber()
{
	return this->cardNumber;
}

char* Card::getOwnerName()
{
	return this->ownerName;
}

char* Card::getExpirationDate()
{
	return this->expirationDate;
}

int Card::getCVC()
{
	return this->CVC;
}

Card::~Card()
{
	delete[] this->cardNumber;
	delete[] this->expirationDate;
	delete[] this->ownerName;
	this->CVC = 0;
}
