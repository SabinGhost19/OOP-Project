#pragma once
#include <windows.h>
#include <sqltypes.h>
#include <sql.h>
#include <sqlext.h>
#include <vector>
#include "Reviews.h"

#define SQL_RESULT_LEN 240
#define SQL_RETURN_CODE_LEN 1000

using namespace std;

class IClient;
class Product;
class ForumCategory;
class ForumPost;

class BDComm
{
private:
    SQLHANDLE sqlConnHandle;
    SQLHANDLE sqlStmtHandle;
    SQLHANDLE sqlEnvHandle;
    SQLWCHAR retconstring[SQL_RETURN_CODE_LEN];
public:
	BDComm();
    SQLWCHAR* ConvertToWideChar(const char* str);
    void CreateConnection();
    void CloseConnection(); 
    char* verifyAccountLogIn(char* email, char* password);
    vector<char*> getClientInfoByEmailAndPassword(char* email, char* password);
    vector<char*> getCompanyInfoByEmailAndPassword(char* email, char* password);
    int getAccountID(char* email, char* password);
    int getClientID(int AccountID);
    int getCategoryId(char* categoryName);
    void insertAccount(char* email, char* password, char* role);
    int insertClientInfo(int accountID,char* lastName,char* firstName,char* TelephoneNo,char* BirthDate);
    int insertCompanyInfo(int companyIDACC, char* companyName, int fiscalAddressID);
    int insertAddress(char* postalCode, char* country, char* county, char* town, char* street, char* nr, char* entrance, char* nrAppart);
    int insertProduct(int companyID, int categoryID, char* productName, char* productDescription, char* stockUnits, char* price);
    char* getNrOfImages();
    void insertImage(int productID, char* imagePath);
    void setAddressForClient(int idClient, int billingAddress, int deliveryAddress);
    int verifyEmailExistance(char* email);
    vector<Product*> getAllProducts();
    vector<char*> getProductPhotos(int productID);
    void addReview(int clientID, int productID, int rating, char* comment);
    vector<Reviews*> getProductReviews(int productID);
    char* getClientNamesByID(int clientID);
    void buyProduct(int productID, int quantity);
    void addCard(int clientID, char* cardNumber, char* cardOwner, char* expirationDate, int CVC);
    vector<char*> getCardInfoById(int clientID);
    void changeClientPasswd(int clientID, char* newPasswd);
    void addMoneyToAccount(int clientID, float moneyToAdd);
    vector<Product*> getCompanyListedProducts(int companyID);
    void setNewQuantity(int productID, int newQuantity);
    void setNewPrice(int productID, float newPrice);
    vector<ForumCategory*> getAllForumCategories();
    vector<ForumPost*> getAllPostsForCategory(int forumCategoryID);
    void addPost(int forumCategoryID, char* name,char* post);
    ~BDComm();
};

