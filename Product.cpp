#include "Product.h"
#include<QWidget>

ProductCategory GetProductCategory(const std::string &category) {
    if (category == "Electronice") {
        return ProductCategory::ELECTRONICS;
    }
    else if (category == "CLOTHING"){
        return ProductCategory::CLOTHING;
    }
    else if (category == "BEAUTY") {
        return ProductCategory::BEAUTY;
    }
    else if (category == "BOOKS") {
         return ProductCategory::BOOKS;
    }
    else if (category == "FOOD") {
        return ProductCategory::FOOD;
    }
    else if (category == "SPORTS") {
        return ProductCategory::SPORTS;
    }
    else {

        return ProductCategory::INVALID;
    }
}


std::string GetCategory(const ProductCategory product) {

    switch (product) {
    case ProductCategory::ELECTRONICS:
        return "Electronice\n";
        break;
    case ProductCategory::CLOTHING:
        return "Îmbrăcăminte\n";
        break;
    case ProductCategory::BOOKS:
        return "Cărți\n";
        break;
    case ProductCategory::BEAUTY:
        return "Cosmetice\n";
        break;
    case ProductCategory::FOOD:
        return "Alimente\n";
        break;
    case ProductCategory::SPORTS:
        return "Articole sportive\n";
        break;
    default:
        //error
        return "-";
    }


}


Product::Product() : price(0.0f) {}


void Product::setImage(QPixmap image_label) {
    this->image_label=image_label;
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

QPixmap Product::getImage() const {
    return this->image_label;
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


