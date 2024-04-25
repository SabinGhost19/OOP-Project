#include "Product.h"
#include "Utils.cpp"

Product::Product() : price(0.0f) {}


void Product::setImagePath(const std::string &imagePath) {
    this->imagePath = imagePath;
}

void Product::setTitle(const std::string &title) {
    this->title = title;
}

void Product::setPrice(float price) {
    this->price = price;
}

void Product::setDescription(const std::string &description) {
    this->description = description;
}

void Product::setComments(std::vector<std::pair<std::string, std::string>>vec_param){
    this->comments=std::move(vec_param);
}
void Product::setCategory(std::string category_param){
    this->categorie_produs=GetProductCategory(category_param);
}

std::string Product::getImagePath() const {
    return imagePath;
}

std::string Product::getTitle() const {
    return title;
}

float Product::getPrice() const {
    return price;
}

std::string Product::getDescription() const {
    return description;
}
ProductCategory Product::getCategory() const {
    return categorie_produs;
}
std::pair<std::string, std::string> Product::getComments()  {
    this->comment_index++;
    return comments[this->comment_index];
}

