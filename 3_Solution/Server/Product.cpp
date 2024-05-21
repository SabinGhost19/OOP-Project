#define _CRT_SECURE_NO_WARNINGS
#include "Product.h"
#include <string.h>

Product::Product()
{
	this->productID = 0;
	this->productName = NULL;
	this->productDescription = NULL;
	this->stockUnits = 0;
	this->price = 0;
	this->images.clear();
	this->reviews.clear();
}

int Product::getProductId()
{
	return this->productID;
}

char* Product::getProductName()
{
	return this->productName;
}

char* Product::getCategory()
{
	return this->category;
}

char* Product::getProductDescription()
{
	return this->productDescription;
}

int Product::getStocUnits()
{
	return this->stockUnits;
}

float Product::getPrice()
{
	return this->price;
}

char* Product::getProducerName()
{
	return this->producerName;
}

vector<Reviews*> Product::getReviews()
{
	return this->reviews;
}

void Product::setProductID(int idToSet)
{
	this->productID = idToSet;
}

void Product::setProductName(char* nameToSet)
{
	this->productName = new char[strlen(nameToSet)];
	strcpy(this->productName, nameToSet);
}

void Product::setCategory(char* categoryToSet)
{
	this->category = new char[strlen(categoryToSet)];
	strcpy(this->category, categoryToSet);
}

void Product::setProductDescription(char* descriptionToSet)
{
	this->productDescription = new char[strlen(descriptionToSet)];
	strcpy(this->productDescription, descriptionToSet);
}

void Product::setStockUnits(int stockUnitsToSet)
{
	this->stockUnits = stockUnitsToSet;
}

void Product::setPrice(float priceToSet)
{
	this->price = priceToSet;
}

void Product::setProducerName(char* nameToSet)
{
	this->producerName = new char[strlen(nameToSet)];
	strcpy(this->producerName, nameToSet);
}

void Product::addImagePath(char* imagePath)
{
	char* newImagePath = new char[strlen(imagePath)];
	strcpy(newImagePath, imagePath);
	this->images.push_back(newImagePath);
}

void Product::setAllImages(vector<char*> imagesPaths)
{
	this->images = imagesPaths;
}

void Product::addReview(Reviews* reviewToAdd)
{
	this->reviews.push_back(reviewToAdd);
}

void Product::addAllReviews(vector<Reviews*> productReviews)
{
	this->reviews = productReviews;
}

char* Product::getFirstImage()
{
	return this->images[0];
}

vector<char*> Product::getAllImages()
{
	return this->images;
}

Product::~Product()
{
	this->productID = 0;
	delete[] this->productName;
	delete[] this->productDescription;
	this->stockUnits = 0;
	this->price = 0;
	for (auto iterator : this->images)
		delete iterator;	
	for (auto iterator : this->reviews)
		delete iterator;
}
