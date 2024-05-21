#pragma once
class Address
{
private:
	char postalCode[10];
	char country[30];
	char county[20];
	char town[30];
	char street[60];
	char nr[15];
	char entrance[10];
	int nrAppart;
public:
	Address();
	void setPostalCode(char* postalCodeToSet);
	void setCountry(char* countryToSet);
	void setCounty(char* countyToSet);
	void setTown(char* townToSet);
	void setStreet(char* streetToSet);
	void setNr(char* nrToSet);
	void setEntrance(char* entranceToSet);
	void setNrAppart(char* nrAppartToSet);
	char* getPostalCode();
	char* getCountry();
	char* getCounty();
	char* getTown();
	char* getStreet();
	char* getNr();
	char* getEntrance();
	int getNrAppart();
	~Address();
};

