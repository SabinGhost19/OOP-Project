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

    int comment_index=-1;
    int state=0;
    int image_index=0;

    std::vector<std::pair<std::string, std::string>> comments;
    std::vector<QPixmap> image_label_LIST;
    ProductCategory categorie_produs;
    std::string description;
    std::string cantitate;//
    std::string price;
    std::string product_ID;//
    std::string title;
    std::string producer_name;

public:

    Product();

    void setQuantity(std::string quant);
    void setImage( QPixmap image_label);
    void setTitle(const std::string &title);
    void setPrice(std::string price);
    void setDescription(const std::string &description);
    void setComments(std::vector<std::pair<std::string, std::string>>vec_param);
    void setCategory(std::string category_param);
    void setID(std::string id_param);
    void setProducerName(std::string);


    std::vector<QPixmap> getImage() const;
    std::string GetProductID()const;
    std::string getTitle() const;
    std::string getPrice() const;
    //std::string GetId()const;
    std::string getDescription() const;
    std::vector<std::pair<std::string, std::string>> getComments();
    ProductCategory getCategory()const;
    std::string GetQuant()const ;
    int GetState();
    std::string GetProducerName();

    void ModifyState();
    void ResetState();
    void AddMoreImages(std::vector<QPixmap>more);

    QPixmap GetNextImage();

};

#endif // PRODUCT_H
