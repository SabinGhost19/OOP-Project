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
	~Address();
};

