#include<iostream>
#include<vector>
#include<string>
#include<list>

enum class ProductCategory {
    ELECTRONICS,
    CLOTHING,
    BOOKS,
    BEAUTY,
    FOOD,
    SPORTS,
    INVALID
};

ProductCategory GetProductCategory(const std::string &category) {
    if (category == "Electronice\n") {
        return ProductCategory::ELECTRONICS;
    } else if (category == "Îmbrăcăminte\n") {
        return ProductCategory::CLOTHING;
    } else if (category == "Cărți\n") {
        return ProductCategory::BOOKS;
    } else if (category == "Cosmetice\n") {
        return ProductCategory::BEAUTY;
    } else if (category == "Alimente\n") {
        return ProductCategory::FOOD;
    } else if (category == "Articole sportive\n") {
        return ProductCategory::SPORTS;
    } else {

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
