#ifndef PRODUCT_H
#define PRODUCT_H
#include<iostream>
#include<string.h>
#include<vector>

enum class ProductCategory;

class Product {
private:
    std::string imagePath;
    std::string title;
    float price;
    std::string description;
    std::vector<std::pair<std::string, std::string>> comments;
    int comment_index=-1;
    ProductCategory categorie_produs;
public:

    Product();


    void setImagePath(const std::string &imagePath);
    void setTitle(const std::string &title);
    void setPrice(float price);
    void setDescription(const std::string &description);
    void setComments(std::vector<std::pair<std::string, std::string>>vec_param);
    void setCategory(std::string category_param);


    std::string getImagePath() const;
    std::string getTitle() const;
    float getPrice() const;
    std::string getDescription() const;
    std::pair<std::string, std::string> getComments();
    ProductCategory getCategory()const;

};

#endif // PRODUCT_H
