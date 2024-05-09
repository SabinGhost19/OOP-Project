#ifndef PRODUCT_H
#define PRODUCT_H
#include<iostream>
#include<string.h>
#include<vector>
#include<QWidget>
#include<QLabel>
#include<QPixmap>


enum class ProductCategory {
    ELECTRONICS,
    CLOTHING,
    BOOKS,
    BEAUTY,
    FOOD,
    SPORTS,
    INVALID,
    ALL
};

class Product {
private:
    QPixmap image_label;
    std::string title;
    float price;
    std::string description;
    std::vector<std::pair<std::string, std::string>> comments;
    int comment_index=-1;
    ProductCategory categorie_produs;
public:

    Product();


    void setImage( QPixmap image_label);
    void setTitle(const std::string &title);
    void setPrice(float price);
    void setDescription(const std::string &description);
    void setComments(std::vector<std::pair<std::string, std::string>>vec_param);
    void setCategory(std::string category_param);


    QPixmap getImage() const;
    std::string getTitle() const;
    float getPrice() const;
    std::string getDescription() const;
    std::pair<std::string, std::string> getComments();
    ProductCategory getCategory()const;

};

#endif // PRODUCT_H
