#pragma once
#include "Reviews.h"
#include <vector>

using namespace std;

class Product
{
private:
	int productID;
	char* producerName;
	char* productName;
	char* category;
	char* productDescription;
	int stockUnits;
	float price;
	vector<char*> images;
	vector<Reviews*> reviews;
public:
	Product();
	int getProductId();
	char* getProductName();
	char* getCategory();
	char* getProductDescription();
	int getStocUnits();
	float getPrice();
	char* getProducerName();
	vector<Reviews*> getReviews();
	void setProductID(int idToSet);
	void setProductName(char* nameToSet);
	void setCategory(char* categoryToSet);
	void setProductDescription(char* descriptionToSet);
	void setStockUnits(int stockUnitsToSet);
	void setPrice(float priceToSet);
	void setProducerName(char* nameToSet);
	void addImagePath(char* imagePath);
	void setAllImages(vector<char*> imagesPaths);
	void addReview(Reviews* reviewToAdd);
	void addAllReviews(vector<Reviews*> productReviews);
	char* getFirstImage();
	vector<char*> getAllImages();
	~Product();
};

