#define _CRT_SECURE_NO_WARNINGS
#include "Address.h"
#include <string.h>
#include <string>

Address::Address()
{
	memset(this->postalCode, 0, 10);
	memset(this->country, 0, 30);
	memset(this->county, 0, 20);
	memset(this->town, 0, 30);
	memset(this->street, 0, 60);
	memset(this->nr, 0, 15);
	memset(this->entrance, 0, 10);
	this->nrAppart = 0;
}

void Address::setPostalCode(char* postalCodeToSet)
{
	strcpy(this->postalCode, postalCodeToSet);
}

void Address::setCountry(char* countryToSet)
{
	strcpy(this->country, countryToSet);
}

void Address::setCounty(char* countyToSet)
{
	strcpy(this->county, countyToSet);
}

void Address::setTown(char* townToSet)
{
	strcpy(this->town, townToSet);
}

void Address::setStreet(char* streetToSet)
{
	strcpy(this->street, streetToSet);
}

void Address::setNr(char* nrToSet)
{
	strcpy(this->nr, nrToSet);
}

void Address::setEntrance(char* entranceToSet)
{
	strcpy(this->entrance, entranceToSet);
}

void Address::setNrAppart(char* nrAppartToSet)
{
	this->nrAppart = atoi(nrAppartToSet);
}

char* Address::getPostalCode()
{
	return this->postalCode;
}

char* Address::getCountry()
{
	return this->country;
}

char* Address::getCounty()
{
	return this->county;
}

char* Address::getTown()
{
	return this->town;
}

char* Address::getStreet()
{
	return this->street;
}

char* Address::getNr()
{
	return this->nr;
}

char* Address::getEntrance()
{
	return this->entrance;
}

int Address::getNrAppart()
{
	return this->nrAppart;
}

Address::~Address()
{
	memset(this->postalCode, 0, 10);
	memset(this->country, 0, 30);
	memset(this->county, 0, 20);
	memset(this->town, 0, 30);
	memset(this->street, 0, 60);
	memset(this->nr, 0, 15);
	memset(this->entrance, 0, 10);
	this->nrAppart = 0;
}
