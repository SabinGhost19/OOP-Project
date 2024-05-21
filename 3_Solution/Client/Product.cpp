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


Product::Product(){}


void Product::setImage(QPixmap image_label) {

    this->image_label_LIST.push_back(image_label);
}
void Product::setProducerName(std::string prod){
    this->producer_name=prod;
}
void Product::setTitle(const std::string &title) {
    this->title = title;
}

void Product::setPrice(std::string price) {
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

QList<QPixmap> Product::getImage() const {
    return this->image_label_LIST;
}

std::string Product::getTitle() const {
    return title;
}

std::string Product::getPrice() const {
    return price;
}
std::string Product::GetProductID()const{
    return this->product_ID;
}
void  Product::setID(std::string id_param){
    this->product_ID=id_param;
    std::cout<<this->product_ID<<std::endl;//bun
}
void Product::setQuantity(std::string quant){

    this->cantitate=quant;
}
int Product::GetState(){
    return this->state;
}
std::string Product::GetQuant()const {
    return this->cantitate;
}
std::string Product::GetProducerName(){
    return this->producer_name;
}
std::string Product::getDescription() const {
    return description;
}
ProductCategory Product::getCategory() const {
    return categorie_produs;
}
 std::vector<std::pair<std::string, std::string>> Product::getComments()  {

    return this->comments;
}

void Product::ModifyState(){
    this->state=1;
}

void Product::ResetState(){
    this->state=0;
}
QPixmap Product::GetNextImage(){

    if(this->image_index+1>static_cast<int>(this->image_label_LIST.size())){
        this->image_index=0;
    }
    QPixmap pix=this->image_label_LIST[this->image_index];
    this->image_index++;
    return pix;
}
void Product::AddMoreImages(QList<QPixmap>more){

    for(auto pix:more){
        this->image_label_LIST.append(pix);
    }
}



