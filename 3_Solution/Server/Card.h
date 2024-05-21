#pragma once
class Card
{
private:
	char* cardNumber;
	char* ownerName;
	char* expirationDate;
	int CVC;
public:
	Card();
	void setCardNumber(char* cardNumber);
	void setOwnerName(char* ownerName);
	void setExpirationDate(char* expirationDate);
	void setCVC(int CVC);
	char* getCardNumber();
	char* getOwnerName();
	char* getExpirationDate();
	int getCVC();
	~Card();
};

