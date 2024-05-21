#define _CRT_SECURE_NO_WARNINGS
#include "BDComm.h"
#include "ServerLogger.h"
#include "Exception.h"
#include "Product.h"
#include "ForumCategory.h"
#include "ForumPost.h"
#include <iostream>


#define SQL_RESULT_LEN 240
#define SQL_RETURN_CODE_LEN 1000

using namespace std;

BDComm::BDComm()
{
    this->CreateConnection();
}

SQLWCHAR* BDComm::ConvertToWideChar(const char* str)
{
    int wideLen = MultiByteToWideChar(CP_ACP, 0, str, -1, NULL, 0);
    if (wideLen == 0) {
       
        return nullptr;
    }

    SQLWCHAR* wideStr = new SQLWCHAR[wideLen];
    if (!MultiByteToWideChar(CP_ACP, 0, str, -1, wideStr, wideLen)) {
        delete[] wideStr;
        return nullptr;
    }

    return wideStr;
}

void BDComm::CreateConnection()
{
    sqlConnHandle = NULL;
    sqlStmtHandle = NULL;
    if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &sqlEnvHandle))
        CloseConnection();
    if (SQL_SUCCESS != SQLSetEnvAttr(sqlEnvHandle, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, 0))
        CloseConnection();
    if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_DBC, sqlEnvHandle, &sqlConnHandle))
        CloseConnection();
    ServerLogger::getInstance("SQLLogger.txt")->loggAction("CONNECTING TO SQL SERVER");

    switch (SQLDriverConnect(sqlConnHandle, NULL, (SQLWCHAR*)L"DRIVER={SQL Server};SERVER=localhost, 55061;DATABASE=POOProjBD;Trusted=true;",
        SQL_NTS, retconstring, 1024, NULL, SQL_DRIVER_NOPROMPT)) {
    case SQL_SUCCESS:
        ServerLogger::getInstance("SQLLogger.txt")->loggAction("SUCCESFULLY CONNECTED TO SQL SERVER");
        break;
    case SQL_SUCCESS_WITH_INFO:
        ServerLogger::getInstance("SQLLogger.txt")->loggAction("SUCCESFULLY CONNECTED TO SQL SERVER");
        break;
    case SQL_INVALID_HANDLE:
        ServerLogger::getInstance("SQLLogger.txt")->loggAction("CONNECTION TO SQL SERVER FAILED");
        throw("CONNECTION TO SQL SERVER FAILED");
        break;
    case SQL_ERROR:
        ServerLogger::getInstance("SQLLogger.txt")->loggAction("CONNECTION TO SQL SERVER FAILED");
        throw("CONNECTION TO SQL SERVER FAILED");
        break;
    default:
        break;
    }

    if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle))
        CloseConnection();
}

void BDComm::CloseConnection()
{
    SQLFreeHandle(SQL_HANDLE_STMT, sqlStmtHandle);
    SQLDisconnect(sqlConnHandle);
    SQLFreeHandle(SQL_HANDLE_DBC, sqlConnHandle);
    SQLFreeHandle(SQL_HANDLE_ENV, sqlEnvHandle);
}

char* BDComm::verifyAccountLogIn(char* email, char* password)
{
    SQLRETURN retcode = 0;
    SQLINTEGER retValue = 0;

    if (sqlStmtHandle) {
        SQLFreeStmt(sqlStmtHandle, SQL_CLOSE);
    }

    retcode = SQLPrepare(sqlStmtHandle, (SQLWCHAR*)L"EXEC VerificaContInregistrat ?, ?", SQL_NTS);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception("ERROR WHILE TRYING TO PREPARE THE QUERY FOR DATABASE");

    SQLINTEGER emailLength = strlen(email) + 1;
    SQLINTEGER passwordLength = strlen(password) + 1;

    retcode = SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, emailLength, 0, (SQLPOINTER)email, 0, NULL);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception("ERROR WHILE TRYING TO BIND PARAMETER");
    retcode = SQLBindParameter(sqlStmtHandle, 2, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, passwordLength, 0, (SQLPOINTER)password, 0, NULL);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception ("ERROR WHILE TRYING TO BIND PARAMETER");

    retcode = SQLExecute(sqlStmtHandle);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception ("ERROR WHILE TRYING TO EXECUTE THE QUERY");

    SQLCHAR sqlVersion[SQL_RESULT_LEN] ="";
    SQLLEN ptrSqlVersion = 0;
    retcode = SQLFetch(sqlStmtHandle);
    if (retcode != SQL_SUCCESS && retcode != SQL_SUCCESS_WITH_INFO)
    {
        throw Exception("NO ROLE FOUND FOR THIS CREDENTIALS");
    }
    SQLGetData(sqlStmtHandle, 1, SQL_CHAR, sqlVersion, SQL_RESULT_LEN, &ptrSqlVersion);
    if (ptrSqlVersion == 0)
        return nullptr;
    return reinterpret_cast<char*>(sqlVersion);
}

vector<char*> BDComm::getClientInfoByEmailAndPassword(char* email, char* password)
{
    vector<char*> clientInfoArray;
    SQLRETURN retcode = 0;
    SQLINTEGER retValue = 0;

    if (sqlStmtHandle) {
        SQLFreeStmt(sqlStmtHandle, SQL_CLOSE);
    }

    retcode = SQLPrepare(sqlStmtHandle, (SQLWCHAR*)L"EXEC GetClientByEmailAndPassword ?, ?", SQL_NTS);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception ("ERROR WHILE TRYING TO PREPARE THE QUERY FOR DATABASE");

    SQLINTEGER emailLength = strlen(email) + 1;
    SQLINTEGER passwordLength = strlen(password) + 1;

    retcode = SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, emailLength, 0, (SQLPOINTER)email, 0, NULL);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception ("ERROR WHILE TRYING TO BIND PARAMETER");
    retcode = SQLBindParameter(sqlStmtHandle, 2, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, passwordLength, 0, (SQLPOINTER)password, 0, NULL);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception ("ERROR WHILE TRYING TO BIND PARAMETER");

    retcode = SQLExecute(sqlStmtHandle);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception ("ERROR WHILE TRYING TO EXECUTE THE QUERY");

    SQLCHAR FetchedData[1024];
    SQLLEN lenOfData = 0;
    SQLSMALLINT numCols = 0;
    SQLNumResultCols(sqlStmtHandle, &numCols);
    if (!(SQLFetch(sqlStmtHandle) == SQL_SUCCESS))
        throw Exception ("ERROR WHILE TRYING TO FETCH DATA");
    char* charFetchedData;
    for (int i = 1; i <= numCols; i++)
    {
        SQLGetData(sqlStmtHandle, i, SQL_C_CHAR, FetchedData, sizeof(FetchedData), &lenOfData);
        if (lenOfData == -1)
        {
            charFetchedData = new char[6];
            strcpy(charFetchedData, "NULL");
        }
        else
        {
            charFetchedData = new char[lenOfData+1];
            strcpy(charFetchedData, reinterpret_cast<char*>(FetchedData));
        }
        clientInfoArray.push_back(charFetchedData);
    }
    return clientInfoArray;
}

vector<char*> BDComm::getCompanyInfoByEmailAndPassword(char* email, char* password)
{
    vector<char*> clientInfoArray;
    SQLRETURN retcode = 0;
    SQLINTEGER retValue = 0;

    if (sqlStmtHandle) {
        SQLFreeStmt(sqlStmtHandle, SQL_CLOSE);
    }

    retcode = SQLPrepare(sqlStmtHandle, (SQLWCHAR*)L"EXEC GetProducerInfoByEmailAndPassword ?, ?", SQL_NTS);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception ("ERROR WHILE TRYING TO PREPARE THE QUERY FOR DATABASE");

    SQLINTEGER emailLength = strlen(email) + 1;
    SQLINTEGER passwordLength = strlen(password) + 1;

    retcode = SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, emailLength, 0, (SQLPOINTER)email, 0, NULL);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception ("ERROR WHILE TRYING TO BIND PARAMETER");
    retcode = SQLBindParameter(sqlStmtHandle, 2, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, passwordLength, 0, (SQLPOINTER)password, 0, NULL);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception ("ERROR WHILE TRYING TO BIND PARAMETER");

    retcode = SQLExecute(sqlStmtHandle);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception ("ERROR WHILE TRYING TO EXECUTE THE QUERY");

    SQLCHAR FetchedData[1024];
    SQLLEN lenOfData = 0;
    SQLSMALLINT numCols = 0;
    SQLNumResultCols(sqlStmtHandle, &numCols);
    if (!(SQLFetch(sqlStmtHandle) == SQL_SUCCESS))
        throw Exception ("ERROR WHILE TRYING TO FETCH DATA");
    char* charFetchedData;
    for (int i = 1; i <= numCols; i++)
    {
        SQLGetData(sqlStmtHandle, i, SQL_C_CHAR, FetchedData, sizeof(FetchedData), &lenOfData);
        if (lenOfData == -1)
        {
            charFetchedData = new char[6];
            strcpy(charFetchedData, "NULL");
        }
        else
        {
            charFetchedData = new char[lenOfData + 1];
            strcpy(charFetchedData, reinterpret_cast<char*>(FetchedData));
        }
        clientInfoArray.push_back(charFetchedData);
    }
    return clientInfoArray;
}

int BDComm::getAccountID(char* email, char* password)
{
    SQLRETURN retcode = 0;

    if (sqlStmtHandle) {
        SQLFreeStmt(sqlStmtHandle, SQL_CLOSE);
    }

    retcode = SQLPrepare(sqlStmtHandle, (SQLWCHAR*)L"EXEC GetContIdByEmailAndPassword ?, ?", SQL_NTS);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception ("ERROR WHILE TRYING TO PREPARE THE QUERY FOR DATABASE");

    SQLINTEGER emailLength = strlen(email) + 1;
    SQLINTEGER passwordLength = strlen(password) + 1;

    retcode = SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, emailLength, 0, (SQLPOINTER)email, 0, NULL);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception ("ERROR WHILE TRYING TO BIND PARAMETER");
    retcode = SQLBindParameter(sqlStmtHandle, 2, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, passwordLength, 0, (SQLPOINTER)password, 0, NULL);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception ("ERROR WHILE TRYING TO BIND PARAMETER");

    retcode = SQLExecute(sqlStmtHandle);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception ("ERROR WHILE TRYING TO EXECUTE THE QUERY");

    SQLCHAR fetchedData[50] = "";
    SQLLEN dataLen = 0;
    if (!(SQLFetch(sqlStmtHandle) == SQL_SUCCESS))
        throw Exception ("ERROR WHILE TRYING TO FETCH DATA");
    SQLGetData(sqlStmtHandle, 1, SQL_CHAR, fetchedData, SQL_RESULT_LEN, &dataLen);
    return atoi(reinterpret_cast<char*>(fetchedData));
}

int BDComm::getClientID(int AccountID)
{
    SQLRETURN retcode = 0;

    if (sqlStmtHandle) {
        SQLFreeStmt(sqlStmtHandle, SQL_CLOSE);
    }

    retcode = SQLPrepare(sqlStmtHandle, (SQLWCHAR*)L"EXEC GetClientIDFromContID ?", SQL_NTS);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception ("ERROR WHILE TRYING TO PREPARE THE QUERY FOR DATABASE");

    SQLINTEGER AccountIDSQLINT = AccountID;

    retcode = SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_SLONG, SQL_INTEGER, 0, 0, &AccountIDSQLINT, 0, NULL);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception ("ERROR WHILE TRYING TO BIND PARAMETER");

    SQLINTEGER idClient;
    retcode = SQLExecute(sqlStmtHandle);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception ("ERROR WHILE TRYING TO FETCH DATA");
    if (!(SQLFetch(sqlStmtHandle) == SQL_SUCCESS))
        throw Exception ("ERROR WHILE TRYING TO FETCH DATA");
    SQLGetData(sqlStmtHandle, 1, SQL_C_LONG, &idClient, sizeof(idClient), NULL);
    return idClient;
}

int BDComm::getCategoryId(char* categoryName)
{
    SQLRETURN retcode = 0;

    if (sqlStmtHandle) {
        SQLFreeStmt(sqlStmtHandle, SQL_CLOSE);
    }

    retcode = SQLPrepare(sqlStmtHandle, (SQLWCHAR*)L"EXEC GetCategoryID ?", SQL_NTS);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception ("ERROR WHILE TRYING TO PREPARE THE QUERY FOR DATABASE");

    SQLINTEGER categoryNameLen = strlen(categoryName) + 1;

    retcode = SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, categoryNameLen, 0, (SQLPOINTER)categoryName, 0, NULL);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception ("ERROR WHILE TRYING TO BIND PARAMETER");

    SQLINTEGER idCategory;
    retcode = SQLExecute(sqlStmtHandle);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception ("ERROR WHILE TRYING TO FETCH DATA");
    if (!(SQLFetch(sqlStmtHandle) == SQL_SUCCESS))
        throw Exception ("ERROR WHILE TRYING TO FETCH DATA");
    SQLGetData(sqlStmtHandle, 1, SQL_C_LONG, &idCategory, sizeof(idCategory), NULL);
    return idCategory;
}

void BDComm::insertAccount(char* email, char* password, char* role)
{
    SQLRETURN retcode = 0;

    if (sqlStmtHandle) {
        SQLFreeStmt(sqlStmtHandle, SQL_CLOSE);
    }

    retcode = SQLPrepare(sqlStmtHandle, (SQLWCHAR*)L"EXEC AdaugaCont ?, ?, ?", SQL_NTS);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception ("ERROR WHILE TRYING TO PREPARE THE QUERY FOR DATABASE");

    SQLINTEGER emailLength = strlen(email) + 1;
    SQLINTEGER passwordLength = strlen(password) + 1;
    SQLINTEGER roleLength = strlen(role) + 1;

    retcode = SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, emailLength, 0, (SQLPOINTER)email, 0, NULL);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception ("ERROR WHILE TRYING TO BIND PARAMETER");
    retcode = SQLBindParameter(sqlStmtHandle, 2, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, passwordLength, 0, (SQLPOINTER)password, 0, NULL);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception ("ERROR WHILE TRYING TO BIND PARAMETER");
    retcode = SQLBindParameter(sqlStmtHandle, 3, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, roleLength, 0, (SQLPOINTER)role, 0, NULL);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception ("ERROR WHILE TRYING TO BIND PARAMETER");
    
    retcode = SQLExecute(sqlStmtHandle);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception ("ERROR WHILE TRYING TO EXECUTE THE QUERY");
}

int BDComm::insertClientInfo(int accountID, char* lastName, char* firstName, char* TelephoneNo, char* BirthDate)
{
    SQLRETURN retcode = 0;

    if (sqlStmtHandle) {
        SQLFreeStmt(sqlStmtHandle, SQL_CLOSE);
    }

    retcode = SQLPrepare(sqlStmtHandle, (SQLWCHAR*)L"EXEC AdaugaInfoClient ?, ?, ?, ?, ?, ?", SQL_NTS);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception ("ERROR WHILE TRYING TO PREPARE THE QUERY FOR DATABASE");

    SQLINTEGER lastNamelLength = strlen(lastName) + 1;
    SQLINTEGER firstNameLength = strlen(firstName) + 1;
    SQLINTEGER TelephoneLength = strlen(TelephoneNo) + 1;
    SQLINTEGER birthDateLength = strlen(BirthDate) + 1;

    SQLINTEGER accountIdSQLInt = accountID;
    //SQLINTEGER clientID = 0;
    //SQLLEN clientIDLen = 0;
    SQLCHAR clientID[20] = "";
    SQLLEN clientIDLen = 20;
    retcode = SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_SLONG, SQL_INTEGER, 0, 0, &accountIdSQLInt, 0, NULL);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception ("ERROR WHILE TRYING TO BIND PARAMETER");
    retcode = SQLBindParameter(sqlStmtHandle, 2, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, lastNamelLength, 0, (SQLPOINTER)lastName, 0, NULL);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception ("ERROR WHILE TRYING TO BIND PARAMETER");
    retcode = SQLBindParameter(sqlStmtHandle, 3, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, firstNameLength, 0, (SQLPOINTER)firstName, 0, NULL);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception ("ERROR WHILE TRYING TO BIND PARAMETER");
    retcode = SQLBindParameter(sqlStmtHandle, 4, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, TelephoneLength, 0, (SQLPOINTER)TelephoneNo, 0, NULL);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception ("ERROR WHILE TRYING TO BIND PARAMETER");
    retcode = SQLBindParameter(sqlStmtHandle, 5, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, birthDateLength, 0, (SQLPOINTER)BirthDate, 0, NULL);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception ("ERROR WHILE TRYING TO BIND PARAMETER");
    retcode = SQLBindParameter(sqlStmtHandle, 6, SQL_PARAM_OUTPUT, SQL_C_CHAR, SQL_VARCHAR, 20, 0, (SQLPOINTER)clientID, 20, &clientIDLen);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception ("ERROR WHILE TRYING TO BIND PARAMETER");
    retcode = SQLExecute(sqlStmtHandle);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception ("ERROR WHILE EXECUTING THE QUERY");
    retcode = SQLMoreResults(sqlStmtHandle);
    return atoi(reinterpret_cast<char*>(clientID));
}

int BDComm::insertCompanyInfo(int companyIDACC,char* companyName,int fiscalAddressID)
{
    SQLRETURN retcode = 0;

    if (sqlStmtHandle) {
        SQLFreeStmt(sqlStmtHandle, SQL_CLOSE);
    }

    retcode = SQLPrepare(sqlStmtHandle, (SQLWCHAR*)L"EXEC AdaugaInfoProducator ?, ?, ?, ?", SQL_NTS);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception ("ERROR WHILE TRYING TO PREPARE THE QUERY FOR DATABASE");

    SQLINTEGER companyIDACCSQLINT = companyIDACC;
    SQLINTEGER companyNameLEN = strlen(companyName) + 1;
    SQLINTEGER fiscalAddressIDSQLINT = fiscalAddressID;
    SQLCHAR companyID[20] = "";
    SQLLEN companyIDLen = 20;
    retcode = SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_SLONG, SQL_INTEGER, 0, 0, &companyIDACCSQLINT, 0, NULL);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception ("ERROR WHILE TRYING TO BIND PARAMETER");
    retcode = SQLBindParameter(sqlStmtHandle, 2, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, companyNameLEN, 0, (SQLPOINTER)companyName, 0, NULL);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception ("ERROR WHILE TRYING TO BIND PARAMETER");
    retcode = SQLBindParameter(sqlStmtHandle, 3, SQL_PARAM_INPUT, SQL_C_SLONG, SQL_INTEGER, 0, 0, &fiscalAddressIDSQLINT, 0, NULL);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception ("ERROR WHILE TRYING TO BIND PARAMETER");
    retcode = SQLBindParameter(sqlStmtHandle, 4, SQL_PARAM_OUTPUT, SQL_C_CHAR, SQL_VARCHAR, 20, 0, (SQLPOINTER)companyID, 20, &companyIDLen);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception ("ERROR WHILE TRYING TO BIND PARAMETER");

    retcode = SQLExecute(sqlStmtHandle);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception ("ERROR WHILE TRYING TO EXECUTE THE QUERY");
    retcode = SQLMoreResults(sqlStmtHandle);
    return atoi(reinterpret_cast<char*>(companyID));
}

int BDComm::insertAddress(char* postalCode, char* country, char* county, char* town, char* street, char* nr, char* entrance, char* nrAppart)
{
    SQLRETURN retcode = 0;

    if (sqlStmtHandle) {
        SQLFreeStmt(sqlStmtHandle, SQL_CLOSE);
    }

    retcode = SQLPrepare(sqlStmtHandle, (SQLWCHAR*)L"EXEC AdaugaAdresa ?, ?, ?, ?, ?, ?, ?, ?, ?", SQL_NTS);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception ("ERROR WHILE TRYING TO PREPARE THE QUERY FOR DATABASE");

    SQLINTEGER postalCodeLen = strlen(postalCode) + 1;
    SQLINTEGER countryLen = strlen(country) + 1;
    SQLINTEGER countyLen = strlen(county) + 1;
    SQLINTEGER townLen = strlen(town) + 1;
    SQLINTEGER streetLen = strlen(street) + 1;
    SQLINTEGER nrLen = strlen(nr) + 1;
    SQLINTEGER entranceLen = strlen(entrance) + 1;
    SQLCHAR addressID[20] = "";
    SQLLEN addressIDLen = 20;

    SQLINTEGER nrAppSQLINT = atoi(nrAppart);

    retcode = SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, postalCodeLen, 0, (SQLPOINTER)postalCode, 0, NULL);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception ("ERROR WHILE TRYING TO BIND PARAMETER");
    retcode = SQLBindParameter(sqlStmtHandle, 2, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, countryLen, 0, (SQLPOINTER)country, 0, NULL);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception ("ERROR WHILE TRYING TO BIND PARAMETER");
    retcode = SQLBindParameter(sqlStmtHandle, 3, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, countyLen, 0, (SQLPOINTER)county, 0, NULL);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception ("ERROR WHILE TRYING TO BIND PARAMETER");
    retcode = SQLBindParameter(sqlStmtHandle, 4, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, townLen, 0, (SQLPOINTER)town, 0, NULL);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception ("ERROR WHILE TRYING TO BIND PARAMETER");    
    retcode = SQLBindParameter(sqlStmtHandle, 5, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, streetLen, 0, (SQLPOINTER)street, 0, NULL);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception ("ERROR WHILE TRYING TO BIND PARAMETER");
    retcode = SQLBindParameter(sqlStmtHandle, 6, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, nrLen, 0, (SQLPOINTER)nr, 0, NULL);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception ("ERROR WHILE TRYING TO BIND PARAMETER");
    retcode = SQLBindParameter(sqlStmtHandle, 7, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, entranceLen, 0, (SQLPOINTER)entrance, 0, NULL);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception ("ERROR WHILE TRYING TO BIND PARAMETER");
    retcode = SQLBindParameter(sqlStmtHandle, 8, SQL_PARAM_INPUT, SQL_C_SLONG, SQL_INTEGER, 0, 0, &nrAppSQLINT, 0, NULL);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception ("ERROR WHILE TRYING TO BIND PARAMETER");
    retcode = SQLBindParameter(sqlStmtHandle, 9, SQL_PARAM_OUTPUT, SQL_C_CHAR, SQL_VARCHAR, 20, 0, (SQLPOINTER)addressID, 20, &addressIDLen);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception ("ERROR WHILE TRYING TO BIND PARAMETER");
    retcode = SQLExecute(sqlStmtHandle);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception ("ERROR WHILE TRYING TO EXECUTE THE QUERY");

    retcode = SQLMoreResults(sqlStmtHandle);
    return atoi(reinterpret_cast<char*>(addressID));
}

int BDComm::insertProduct(int companyID, int categoryID, char* productName, char* productDescription, char* stockUnits, char* price)
{
    SQLRETURN retcode = 0;

    if (sqlStmtHandle) {
        SQLFreeStmt(sqlStmtHandle, SQL_CLOSE);
    }

    retcode = SQLPrepare(sqlStmtHandle, (SQLWCHAR*)L"EXEC AdaugaProdus ?, ?, ?, ?, ?, ?, ?", SQL_NTS);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception ("ERROR WHILE TRYING TO PREPARE THE QUERY FOR DATABASE");

    SQLINTEGER companyIDSQLINT = companyID;
    SQLINTEGER categoryIDSQLINT = categoryID;
    SQLINTEGER productNameLEN = strlen(productName) + 1;
    SQLINTEGER productDescriptionLEN = strlen(productDescription) + 1;
    SQLINTEGER stockUnitsLEN = strlen(stockUnits) + 1;
    SQLINTEGER priceLEN = strlen(price) + 1;
    SQLCHAR productID[20] = "";
    SQLLEN productIDLen = 20;
    retcode = SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_SLONG, SQL_INTEGER, 0, 0, &companyIDSQLINT, 0, NULL);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception ("ERROR WHILE TRYING TO BIND PARAMETER");
    retcode = SQLBindParameter(sqlStmtHandle, 2, SQL_PARAM_INPUT, SQL_C_SLONG, SQL_INTEGER, 0, 0, &categoryIDSQLINT, 0, NULL);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception ("ERROR WHILE TRYING TO BIND PARAMETER");
    retcode = SQLBindParameter(sqlStmtHandle, 3, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, productNameLEN, 0, (SQLPOINTER)productName, 0, NULL);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception ("ERROR WHILE TRYING TO BIND PARAMETER");
    retcode = SQLBindParameter(sqlStmtHandle, 4, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, productDescriptionLEN, 0, (SQLPOINTER)productDescription, 0, NULL);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception ("ERROR WHILE TRYING TO BIND PARAMETER");
    retcode = SQLBindParameter(sqlStmtHandle, 5, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, stockUnitsLEN, 0, (SQLPOINTER)stockUnits, 0, NULL);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception ("ERROR WHILE TRYING TO BIND PARAMETER");
    retcode = SQLBindParameter(sqlStmtHandle, 6, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, priceLEN, 0, (SQLPOINTER)price, 0, NULL);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception ("ERROR WHILE TRYING TO BIND PARAMETER");
    retcode = SQLBindParameter(sqlStmtHandle, 7, SQL_PARAM_OUTPUT, SQL_C_CHAR, SQL_VARCHAR, 20, 0, (SQLPOINTER)productID, 20, &productIDLen);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception ("ERROR WHILE TRYING TO BIND PARAMETER");

    retcode = SQLExecute(sqlStmtHandle);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception ("ERROR WHILE TRYING TO EXECUTE THE QUERY");
    retcode = SQLMoreResults(sqlStmtHandle);
    return atoi(reinterpret_cast<char*>(productID));
}

char* BDComm::getNrOfImages()
{
    SQLRETURN retcode = 0;

    if (sqlStmtHandle) {
        SQLFreeStmt(sqlStmtHandle, SQL_CLOSE);
    }

    retcode = SQLPrepare(sqlStmtHandle, (SQLWCHAR*)L"EXEC NumaraInregistrariImaginiProdus", SQL_NTS);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception ("ERROR WHILE TRYING TO PREPARE THE QUERY FOR DATABASE");

    retcode = SQLExecute(sqlStmtHandle);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception ("ERROR WHILE TRYING TO EXECUTE THE QUERY");

    SQLCHAR data[SQL_RESULT_LEN] = "";
    SQLLEN dataLen = 0;
    SQLFetch(sqlStmtHandle);
    SQLGetData(sqlStmtHandle, 1, SQL_CHAR, data, SQL_RESULT_LEN, &dataLen);
    return reinterpret_cast<char*>(data);
}

void BDComm::insertImage(int productID,char* imagePath)
{
    SQLRETURN retcode = 0;

    if (sqlStmtHandle) {
        SQLFreeStmt(sqlStmtHandle, SQL_CLOSE);
    }

    retcode = SQLPrepare(sqlStmtHandle, (SQLWCHAR*)L"EXEC AdaugaImagineProdus ?, ?", SQL_NTS);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception ("ERROR WHILE TRYING TO PREPARE THE QUERY FOR DATABASE");

    SQLINTEGER imagePathLen = strlen(imagePath) + 1;
    SQLINTEGER productIDSQLINT = productID;
    retcode = SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_SLONG, SQL_INTEGER, 0, 0, &productIDSQLINT, 0, NULL);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception ("ERROR WHILE TRYING TO BIND PARAMETER");
    retcode = SQLBindParameter(sqlStmtHandle, 2, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, imagePathLen, 0, (SQLPOINTER)imagePath, 0, NULL);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception ("ERROR WHILE TRYING TO BIND PARAMETER");


    retcode = SQLExecute(sqlStmtHandle);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception ("ERROR WHILE TRYING TO EXECUTE THE QUERY");

}

void BDComm::setAddressForClient(int idClient, int billingAddress, int deliveryAddress)
{
    SQLRETURN retcode = 0;

    if (sqlStmtHandle) {
        SQLFreeStmt(sqlStmtHandle, SQL_CLOSE);
    }

    retcode = SQLPrepare(sqlStmtHandle, (SQLWCHAR*)L"EXEC SeteazaAdreseClient ?, ?, ?", SQL_NTS);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception ("ERROR WHILE TRYING TO PREPARE THE QUERY FOR DATABASE");

    SQLINTEGER idClientSQLINT = idClient;
    SQLINTEGER billingAddressSQLINT = billingAddress;
    SQLINTEGER deliveryAddressSQLINT = deliveryAddress;

    SQLLEN idClientLen = sizeof(idClientSQLINT);
    SQLLEN idBillAddressLen = sizeof(billingAddressSQLINT);
    SQLLEN idDelAddressLen = sizeof(deliveryAddressSQLINT);

    retcode = SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_SLONG, SQL_INTEGER, 0, 0, &idClientSQLINT, 0, &idClientLen);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception ("ERROR WHILE TRYING TO BIND PARAMETER");
    retcode = SQLBindParameter(sqlStmtHandle, 2, SQL_PARAM_INPUT, SQL_C_SLONG, SQL_INTEGER, 0, 0, &deliveryAddressSQLINT, 0, &idBillAddressLen);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception ("ERROR WHILE TRYING TO BIND PARAMETER");
    retcode = SQLBindParameter(sqlStmtHandle, 3, SQL_PARAM_INPUT, SQL_C_SLONG, SQL_INTEGER, 0, 0, &billingAddressSQLINT,0, &idDelAddressLen);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception ("ERROR WHILE TRYING TO BIND PARAMETER");

    retcode = SQLExecute(sqlStmtHandle);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception ("ERROR WHILE TRYING TO EXECUTE THE QUERY");
}

int BDComm::verifyEmailExistance(char* email)
{
    SQLRETURN retcode = 0;
    SQLINTEGER retValue = 0;

    if (sqlStmtHandle) {
        SQLFreeStmt(sqlStmtHandle, SQL_CLOSE);
    }

    retcode = SQLPrepare(sqlStmtHandle, (SQLWCHAR*)L"EXEC VerificaExistentaEmail ?, ?", SQL_NTS);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception ("ERROR WHILE TRYING TO PREPARE THE QUERY FOR DATABASE");

    SQLINTEGER emailLength = strlen(email) + 1;
    SQLCHAR existance[20] = "";
    SQLLEN existanceLEN = 20;

    retcode = SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, emailLength, 0, (SQLPOINTER)email, 0, NULL);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception ("ERROR WHILE TRYING TO BIND PARAMETER");
    retcode = SQLBindParameter(sqlStmtHandle, 2, SQL_PARAM_OUTPUT, SQL_C_CHAR, SQL_VARCHAR, 20, 0, (SQLPOINTER)existance, 20, &existanceLEN);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception ("ERROR WHILE TRYING TO BIND PARAMETER");

    retcode = SQLExecute(sqlStmtHandle);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception ("ERROR WHILE TRYING TO EXECUTE THE QUERY");
    retcode = SQLMoreResults(sqlStmtHandle);
    return atoi(reinterpret_cast<char*>(existance));
}

vector<Product*> BDComm::getAllProducts()
{
    vector<Product*> allProducts;
    SQLRETURN retcode = 0;
    
    if (sqlStmtHandle) {
        SQLFreeStmt(sqlStmtHandle, SQL_CLOSE);
    }

    retcode = SQLPrepare(sqlStmtHandle, (SQLWCHAR*)L"EXEC SelectAllProducts ", SQL_NTS);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception ("ERROR WHILE TRYING TO PREPARE THE QUERY FOR DATABASE");

    retcode = SQLExecute(sqlStmtHandle);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception ("ERROR WHILE TRYING TO EXECUTE THE QUERY");

    SQLCHAR FetchedData[3000];
    SQLLEN lenOfData = 0;
    SQLSMALLINT numCols = 0;

    vector<char*> productInfo;
    SQLNumResultCols(sqlStmtHandle, &numCols);
    char* charFetchedData;
    while (SQLFetch(sqlStmtHandle) == SQL_SUCCESS)
    {
        Product* newProduct = new Product;
        for (int i = 1; i <= numCols; i++)
        {
            SQLGetData(sqlStmtHandle, i, SQL_C_CHAR, FetchedData, sizeof(FetchedData), &lenOfData);
            if (lenOfData == -1)
            {
                charFetchedData = new char[6];
                strcpy(charFetchedData, "NULL");
            }
            else
            {
                charFetchedData = new char[lenOfData + 1];
                strcpy(charFetchedData, reinterpret_cast<char*>(FetchedData));
            }
            productInfo.push_back(charFetchedData);
        }
        newProduct->setProductID(atoi(productInfo[0]));
        newProduct->setProducerName(productInfo[1]);
        newProduct->setCategory(productInfo[2]);
        newProduct->setProductName(productInfo[3]);
        newProduct->setProductDescription(productInfo[4]);
        newProduct->setStockUnits(atoi(productInfo[5]));
        newProduct->setPrice(atof(productInfo[6]));
        for (auto iterator : productInfo)
            delete[] iterator;
        productInfo.clear();
        allProducts.push_back(newProduct);
    }
    return allProducts;
}

vector<char*> BDComm::getProductPhotos(int productID)
{
    SQLRETURN retcode = 0;
    vector<char*> productPhotos;

    if (sqlStmtHandle) {
        SQLFreeStmt(sqlStmtHandle, SQL_CLOSE);
    }

    retcode = SQLPrepare(sqlStmtHandle, (SQLWCHAR*)L"EXEC SelectImaginiProdus ?", SQL_NTS);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception ("ERROR WHILE TRYING TO PREPARE THE QUERY FOR DATABASE");

    SQLINTEGER productIDSQLINT = productID;

    retcode = SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_SLONG, SQL_INTEGER, 0, 0, &productIDSQLINT, 0, NULL);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception ("ERROR WHILE TRYING TO BIND PARAMETER");

    retcode = SQLExecute(sqlStmtHandle);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception ("ERROR WHILE TRYING TO EXECUTE THE QUERY");

    SQLCHAR FetchedData[1024];
    SQLLEN lenOfData = 0;

    char* newPath;
    while (SQLFetch(sqlStmtHandle) == SQL_SUCCESS)
    {
        SQLGetData(sqlStmtHandle, 1, SQL_C_CHAR, FetchedData, sizeof(FetchedData), &lenOfData);
        if (lenOfData == -1)
        {
            newPath = new char[6];
            strcpy(newPath, "NULL");
        }
        else
        {
            newPath = new char[lenOfData + 1];
            strcpy(newPath, reinterpret_cast<char*>(FetchedData));
        }
        productPhotos.push_back(newPath);
    }
    return productPhotos;
}

void BDComm::addReview(int clientID, int productID, int rating, char* comment)
{
    SQLRETURN retcode = 0;

    if (sqlStmtHandle) {
        SQLFreeStmt(sqlStmtHandle, SQL_CLOSE);
    }

    retcode = SQLPrepare(sqlStmtHandle, (SQLWCHAR*)L"EXEC AdaugaRecenzie ?, ?, ?, ?", SQL_NTS);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception ("ERROR WHILE TRYING TO PREPARE THE QUERY FOR DATABASE");

    SQLINTEGER clientIDSQLINT = clientID;
    SQLINTEGER productIDSQLINT = productID;
    SQLINTEGER ratingSQLINT = rating;
    SQLINTEGER commentLEN = strlen(comment) + 1;
    retcode = SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_SLONG, SQL_INTEGER, 0, 0, &clientIDSQLINT, 0, NULL);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception ("ERROR WHILE TRYING TO BIND PARAMETER");
    retcode = SQLBindParameter(sqlStmtHandle, 2, SQL_PARAM_INPUT, SQL_C_SLONG, SQL_INTEGER, 0, 0, &productIDSQLINT, 0, NULL);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception ("ERROR WHILE TRYING TO BIND PARAMETER");
    retcode = SQLBindParameter(sqlStmtHandle, 3, SQL_PARAM_INPUT, SQL_C_SLONG, SQL_INTEGER, 0, 0, &ratingSQLINT, 0, NULL);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception ("ERROR WHILE TRYING TO BIND PARAMETER");
    retcode = SQLBindParameter(sqlStmtHandle, 4, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, commentLEN, 0, (SQLPOINTER)comment, 0, NULL);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception ("ERROR WHILE TRYING TO BIND PARAMETER");

    retcode = SQLExecute(sqlStmtHandle);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception ("ERROR WHILE TRYING TO EXECUTE THE QUERY");
}

vector<Reviews*> BDComm::getProductReviews(int productID)
{
    vector<Reviews*> productReviews;
    SQLRETURN retcode = 0;
    vector<char*> productPhotos;

    if (sqlStmtHandle) {
        SQLFreeStmt(sqlStmtHandle, SQL_CLOSE);
    }

    retcode = SQLPrepare(sqlStmtHandle, (SQLWCHAR*)L"EXEC SelectRecenziiByIDProdus ?", SQL_NTS);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception ("ERROR WHILE TRYING TO PREPARE THE QUERY FOR DATABASE");

    SQLINTEGER productIDSQLINT = productID;

    retcode = SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_SLONG, SQL_INTEGER, 0, 0, &productIDSQLINT, 0, NULL);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception ("ERROR WHILE TRYING TO BIND PARAMETER");

    retcode = SQLExecute(sqlStmtHandle);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception ("ERROR WHILE TRYING TO EXECUTE THE QUERY");

    SQLCHAR FetchedData[1024];
    SQLLEN lenOfData = 0;
    SQLSMALLINT numCols = 0;

    SQLNumResultCols(sqlStmtHandle, &numCols);
    char* charFetchedData;
    vector<char*> reviewInfo;
    while (SQLFetch(sqlStmtHandle) == SQL_SUCCESS)
    {
        Reviews* newReview = new Reviews;
        for (int i = 1; i <= numCols; i++)
        {
            SQLGetData(sqlStmtHandle, i, SQL_C_CHAR, FetchedData, sizeof(FetchedData), &lenOfData);
            if (lenOfData == -1)
            {
                charFetchedData = new char[6];
                strcpy(charFetchedData, "NULL");
            }
            else
            {
                charFetchedData = new char[lenOfData + 1];
                strcpy(charFetchedData, reinterpret_cast<char*>(FetchedData));
            }
            reviewInfo.push_back(charFetchedData);
        }
        newReview->setClientID(atoi(reviewInfo[0]));
        newReview->setRating(atoi(reviewInfo[1]));
        newReview->setComment(reviewInfo[2]);
        for (auto iterator : reviewInfo)
            delete[] iterator;
        reviewInfo.clear();
        productReviews.push_back(newReview);
    }
    return productReviews;
}

char* BDComm::getClientNamesByID(int clientID)
{
    SQLRETURN retcode = 0;
    SQLINTEGER retValue = 0;

    if (sqlStmtHandle) {
        SQLFreeStmt(sqlStmtHandle, SQL_CLOSE);
    }

    retcode = SQLPrepare(sqlStmtHandle, (SQLWCHAR*)L"EXEC GetClientNameByID ?", SQL_NTS);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception ("ERROR WHILE TRYING TO PREPARE THE QUERY FOR DATABASE");

    SQLINTEGER emailLength = clientID;

    retcode = SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_SLONG, SQL_INTEGER, 0, 0, &emailLength, 0, NULL);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception ("ERROR WHILE TRYING TO BIND PARAMETER");

    retcode = SQLExecute(sqlStmtHandle);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception ("ERROR WHILE TRYING TO EXECUTE THE QUERY");

    SQLCHAR sqlVersion[SQL_RESULT_LEN] = "";
    SQLLEN ptrSqlVersion = 0;
    SQLFetch(sqlStmtHandle);
    SQLGetData(sqlStmtHandle, 1, SQL_CHAR, sqlVersion, SQL_RESULT_LEN, &ptrSqlVersion);
    if (ptrSqlVersion == 0)
        return nullptr;
    return reinterpret_cast<char*>(sqlVersion);
}

void BDComm::buyProduct(int productID, int quantity)
{
    SQLRETURN retcode = 0;

    if (sqlStmtHandle) {
        SQLFreeStmt(sqlStmtHandle, SQL_CLOSE);
    }

    retcode = SQLPrepare(sqlStmtHandle, (SQLWCHAR*)L"EXEC CumparaProdus ?, ?", SQL_NTS);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception ("ERROR WHILE TRYING TO PREPARE THE QUERY FOR DATABASE");

    SQLINTEGER productIDSQLINT = productID;
    SQLINTEGER quantitySQLINT = quantity;
    retcode = SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_SLONG, SQL_INTEGER, 0, 0, &productIDSQLINT, 0, NULL);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception ("ERROR WHILE TRYING TO BIND PARAMETER");
    retcode = SQLBindParameter(sqlStmtHandle, 2, SQL_PARAM_INPUT, SQL_C_SLONG, SQL_INTEGER, 0, 0, &quantitySQLINT, 0, NULL);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception ("ERROR WHILE TRYING TO BIND PARAMETER");

    retcode = SQLExecute(sqlStmtHandle);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception ("ERROR WHILE TRYING TO EXECUTE THE QUERY");
}

void BDComm::addCard(int clientID, char* cardNumber, char* cardOwner, char* expirationDate, int CVC)
{
    SQLRETURN retcode = 0;

    if (sqlStmtHandle) {
        SQLFreeStmt(sqlStmtHandle, SQL_CLOSE);
    }

    retcode = SQLPrepare(sqlStmtHandle, (SQLWCHAR*)L"EXEC AdaugaCardClient ?, ?, ?, ?, ?", SQL_NTS);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception ("ERROR WHILE TRYING TO PREPARE THE QUERY FOR DATABASE");

    SQLINTEGER clientIDSQLINT = clientID;
    SQLINTEGER cardNumberLEN = strlen(cardNumber) + 1;
    SQLINTEGER cardOwnerLEN = strlen(cardOwner) + 1;
    SQLINTEGER expirationDateLEN = strlen(expirationDate) + 1;
    SQLINTEGER CVCSQLINT = CVC;
    retcode = SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_SLONG, SQL_INTEGER, 0, 0, &clientIDSQLINT, 0, NULL);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception ("ERROR WHILE TRYING TO BIND PARAMETER");
    retcode = SQLBindParameter(sqlStmtHandle, 2, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, cardNumberLEN, 0, (SQLPOINTER)cardNumber, 0, NULL);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception ("ERROR WHILE TRYING TO BIND PARAMETER");
    retcode = SQLBindParameter(sqlStmtHandle, 3, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, cardOwnerLEN, 0, (SQLPOINTER)cardOwner, 0, NULL);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception ("ERROR WHILE TRYING TO BIND PARAMETER");
    retcode = SQLBindParameter(sqlStmtHandle, 4, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, expirationDateLEN, 0, (SQLPOINTER)expirationDate, 0, NULL);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception ("ERROR WHILE TRYING TO BIND PARAMETER");
    retcode = SQLBindParameter(sqlStmtHandle, 5, SQL_PARAM_INPUT, SQL_C_SLONG, SQL_INTEGER, 0, 0, &CVCSQLINT, 0, NULL);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception ("ERROR WHILE TRYING TO BIND PARAMETER");

    retcode = SQLExecute(sqlStmtHandle);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception ("ERROR WHILE TRYING TO EXECUTE THE QUERY");
}

vector<char*> BDComm::getCardInfoById(int clientID)
{
    vector<char*> cardInfo;
    SQLRETURN retcode = 0;

    if (sqlStmtHandle) {
        SQLFreeStmt(sqlStmtHandle, SQL_CLOSE);
    }

    retcode = SQLPrepare(sqlStmtHandle, (SQLWCHAR*)L"EXEC InformatiiCardClient ?", SQL_NTS);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception ("ERROR WHILE TRYING TO PREPARE THE QUERY FOR DATABASE");

    SQLINTEGER clientIDSQLINT = clientID;

    retcode = SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_SLONG, SQL_INTEGER, 0, 0, &clientIDSQLINT, 0, NULL);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception ("ERROR WHILE TRYING TO BIND PARAMETER");

    retcode = SQLExecute(sqlStmtHandle);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception ("ERROR WHILE TRYING TO EXECUTE THE QUERY");

    SQLCHAR FetchedData[1024];
    SQLLEN lenOfData = 0;
    SQLSMALLINT numCols = 0;

    SQLNumResultCols(sqlStmtHandle, &numCols);
    char* charFetchedData;
    while (SQLFetch(sqlStmtHandle) == SQL_SUCCESS)
    {
        Reviews* newReview = new Reviews;
        for (int i = 1; i <= numCols; i++)
        {
            SQLGetData(sqlStmtHandle, i, SQL_C_CHAR, FetchedData, sizeof(FetchedData), &lenOfData);
            if (lenOfData == -1)
            {
                charFetchedData = new char[6];
                strcpy(charFetchedData, "NULL");
            }
            else
            {
                charFetchedData = new char[lenOfData + 1];
                strcpy(charFetchedData, reinterpret_cast<char*>(FetchedData));
            }
            cardInfo.push_back(charFetchedData);
        }
    }
    return cardInfo;
}

void BDComm::changeClientPasswd(int clientID, char* newPasswd)
{
    SQLRETURN retcode = 0;

    if (sqlStmtHandle) {
        SQLFreeStmt(sqlStmtHandle, SQL_CLOSE);
    }

    retcode = SQLPrepare(sqlStmtHandle, (SQLWCHAR*)L"EXEC SchimbaParolaClient ?, ?", SQL_NTS);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception ("ERROR WHILE TRYING TO PREPARE THE QUERY FOR DATABASE");

    SQLINTEGER clientIDSQLINT = clientID;
    SQLINTEGER newPasswdLEN = strlen(newPasswd)+1;
    retcode = SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_SLONG, SQL_INTEGER, 0, 0, &clientIDSQLINT, 0, NULL);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception ("ERROR WHILE TRYING TO BIND PARAMETER");
    retcode = SQLBindParameter(sqlStmtHandle, 2, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, newPasswdLEN, 0, (SQLPOINTER)newPasswd, 0, NULL);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception ("ERROR WHILE TRYING TO BIND PARAMETER");

    retcode = SQLExecute(sqlStmtHandle);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception ("ERROR WHILE TRYING TO EXECUTE THE QUERY");
}

void BDComm::addMoneyToAccount(int clientID, float moneyToAdd)
{
    SQLRETURN retcode = 0;

    if (sqlStmtHandle) {
        SQLFreeStmt(sqlStmtHandle, SQL_CLOSE);
    }

    retcode = SQLPrepare(sqlStmtHandle, (SQLWCHAR*)L"EXEC AdaugaBaniLaBalanta ?, ?", SQL_NTS);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception ("ERROR WHILE TRYING TO PREPARE THE QUERY FOR DATABASE");

    SQLINTEGER clientIDSQLINT = clientID;
    SQLDOUBLE moneyToAddSQLINT = moneyToAdd;
    retcode = SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_SLONG, SQL_INTEGER, 0, 0, &clientIDSQLINT, 0, NULL);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception ("ERROR WHILE TRYING TO BIND PARAMETER");
    retcode = SQLBindParameter(sqlStmtHandle, 2, SQL_PARAM_INPUT, SQL_C_DOUBLE, SQL_DOUBLE, 0, 0, &moneyToAddSQLINT, 0, NULL);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception ("ERROR WHILE TRYING TO BIND PARAMETER");

    retcode = SQLExecute(sqlStmtHandle);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception ("ERROR WHILE TRYING TO EXECUTE THE QUERY");
}

vector<Product*> BDComm::getCompanyListedProducts(int companyID)
{
    vector<Product*> allProducts;
    SQLRETURN retcode = 0;

    if (sqlStmtHandle) {
        SQLFreeStmt(sqlStmtHandle, SQL_CLOSE);
    }

    retcode = SQLPrepare(sqlStmtHandle, (SQLWCHAR*)L"EXEC SelectListedProducts ? ", SQL_NTS);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception ("ERROR WHILE TRYING TO PREPARE THE QUERY FOR DATABASE");

    SQLINTEGER companyIDSQLINT = companyID;

    retcode = SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_SLONG, SQL_INTEGER, 0, 0, &companyIDSQLINT, 0, NULL);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception ("ERROR WHILE TRYING TO BIND PARAMETER");

    retcode = SQLExecute(sqlStmtHandle);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception ("ERROR WHILE TRYING TO EXECUTE THE QUERY");

    SQLCHAR FetchedData[3000];
    SQLLEN lenOfData = 0;
    SQLSMALLINT numCols = 0;

    vector<char*> productInfo;
    SQLNumResultCols(sqlStmtHandle, &numCols);
    char* charFetchedData;
    while (SQLFetch(sqlStmtHandle) == SQL_SUCCESS)
    {
        Product* newProduct = new Product;
        for (int i = 1; i <= numCols; i++)
        {
            SQLGetData(sqlStmtHandle, i, SQL_C_CHAR, FetchedData, sizeof(FetchedData), &lenOfData);
            if (lenOfData == -1)
            {
                charFetchedData = new char[6];
                strcpy(charFetchedData, "NULL");
            }
            else
            {
                charFetchedData = new char[lenOfData + 1];
                strcpy(charFetchedData, reinterpret_cast<char*>(FetchedData));
            }
            productInfo.push_back(charFetchedData);
        }
        newProduct->setProductID(atoi(productInfo[0]));
        newProduct->setProducerName(productInfo[1]);
        newProduct->setCategory(productInfo[2]);
        newProduct->setProductName(productInfo[3]);
        newProduct->setProductDescription(productInfo[4]);
        newProduct->setStockUnits(atoi(productInfo[5]));
        newProduct->setPrice(atof(productInfo[6]));
        for (auto iterator : productInfo)
            delete[] iterator;
        productInfo.clear();
        allProducts.push_back(newProduct);
    }
    return allProducts;
}

void BDComm::setNewQuantity(int productID, int newQuantity)
{
    SQLRETURN retcode = 0;

    if (sqlStmtHandle) {
        SQLFreeStmt(sqlStmtHandle, SQL_CLOSE);
    }

    retcode = SQLPrepare(sqlStmtHandle, (SQLWCHAR*)L"EXEC UpdateCantitateProdus ?, ?", SQL_NTS);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception("ERROR WHILE TRYING TO PREPARE THE QUERY FOR DATABASE");

    SQLINTEGER productIDSQLINT = productID;
    SQLINTEGER newQuantitySQLINT = newQuantity;
    retcode = SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_SLONG, SQL_INTEGER, 0, 0, &productIDSQLINT, 0, NULL);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception("ERROR WHILE TRYING TO BIND PARAMETER");
    retcode = SQLBindParameter(sqlStmtHandle, 2, SQL_PARAM_INPUT, SQL_C_SLONG, SQL_INTEGER, 0, 0, &newQuantitySQLINT, 0, NULL);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception("ERROR WHILE TRYING TO BIND PARAMETER");

    retcode = SQLExecute(sqlStmtHandle);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception("ERROR WHILE TRYING TO EXECUTE THE QUERY");
}

void BDComm::setNewPrice(int productID, float newPrice)
{
    SQLRETURN retcode = 0;

    if (sqlStmtHandle) {
        SQLFreeStmt(sqlStmtHandle, SQL_CLOSE);
    }

    retcode = SQLPrepare(sqlStmtHandle, (SQLWCHAR*)L"EXEC UpdatePretProdus ?, ?", SQL_NTS);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception("ERROR WHILE TRYING TO PREPARE THE QUERY FOR DATABASE");

    SQLINTEGER productIDSQLINT = productID;
    SQLDOUBLE newPriceSQLDOUBLE = newPrice;
    retcode = SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_SLONG, SQL_INTEGER, 0, 0, &productIDSQLINT, 0, NULL);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception("ERROR WHILE TRYING TO BIND PARAMETER");
    retcode = SQLBindParameter(sqlStmtHandle, 2, SQL_PARAM_INPUT, SQL_C_DOUBLE, SQL_DOUBLE, 0, 0, &newPriceSQLDOUBLE, 0, NULL);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception("ERROR WHILE TRYING TO BIND PARAMETER");

    retcode = SQLExecute(sqlStmtHandle);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception("ERROR WHILE TRYING TO EXECUTE THE QUERY");
}

vector<ForumCategory*> BDComm::getAllForumCategories()
{
    vector<ForumCategory*> allForumCategories;
    SQLRETURN retcode = 0;

    if (sqlStmtHandle) {
        SQLFreeStmt(sqlStmtHandle, SQL_CLOSE);
    }

    retcode = SQLPrepare(sqlStmtHandle, (SQLWCHAR*)L"EXEC SelectAllCategories ", SQL_NTS);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception("ERROR WHILE TRYING TO PREPARE THE QUERY FOR DATABASE");

    retcode = SQLExecute(sqlStmtHandle);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception("ERROR WHILE TRYING TO EXECUTE THE QUERY");

    SQLCHAR FetchedData[3000];
    SQLLEN lenOfData = 0;
    SQLSMALLINT numCols = 0;

    vector<char*> categoryInfo;
    SQLNumResultCols(sqlStmtHandle, &numCols);
    char* charFetchedData;
    while (SQLFetch(sqlStmtHandle) == SQL_SUCCESS)
    {
        ForumCategory* newCategory = new ForumCategory;
        for (int i = 1; i <= numCols; i++)
        {
            SQLGetData(sqlStmtHandle, i, SQL_C_CHAR, FetchedData, sizeof(FetchedData), &lenOfData);
            if (lenOfData == -1)
            {
                charFetchedData = new char[6];
                strcpy(charFetchedData, "NULL");
            }
            else
            {
                charFetchedData = new char[lenOfData + 1];
                strcpy(charFetchedData, reinterpret_cast<char*>(FetchedData));
            }
            categoryInfo.push_back(charFetchedData);
        }
        newCategory->setForumCatID(atoi(categoryInfo[0]));
        newCategory->setForumCatName(categoryInfo[1]);
        newCategory->setForumCatDescription(categoryInfo[2]);
        for (auto iterator : categoryInfo)
            delete[] iterator;
        categoryInfo.clear();
        allForumCategories.push_back(newCategory);
    }
    return allForumCategories;
}

vector<ForumPost*> BDComm::getAllPostsForCategory(int forumCategoryID)
{
    vector<ForumPost*> allPostsForCategory;
    SQLRETURN retcode = 0;

    if (sqlStmtHandle) {
        SQLFreeStmt(sqlStmtHandle, SQL_CLOSE);
    }

    SQLINTEGER catIDSQLINT = forumCategoryID;

    retcode = SQLPrepare(sqlStmtHandle, (SQLWCHAR*)L"EXEC DeterminaDiscutii ?", SQL_NTS);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception("ERROR WHILE TRYING TO PREPARE THE QUERY FOR DATABASE");

    retcode = SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_SLONG, SQL_INTEGER, 0, 0, &catIDSQLINT, 0, NULL);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception("ERROR WHILE TRYING TO BIND PARAMETER");

    retcode = SQLExecute(sqlStmtHandle);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception("ERROR WHILE TRYING TO EXECUTE THE QUERY");

    SQLCHAR FetchedData[3000];
    SQLLEN lenOfData = 0;
    SQLSMALLINT numCols = 0;

    vector<char*> postInfo;
    SQLNumResultCols(sqlStmtHandle, &numCols);
    char* charFetchedData;
    while (SQLFetch(sqlStmtHandle) == SQL_SUCCESS)
    {
        ForumPost* newPost = new ForumPost;
        for (int i = 1; i <= numCols; i++)
        {
            SQLGetData(sqlStmtHandle, i, SQL_C_CHAR, FetchedData, sizeof(FetchedData), &lenOfData);
            if (lenOfData == -1)
            {
                charFetchedData = new char[6];
                strcpy(charFetchedData, "NULL");
            }
            else
            {
                charFetchedData = new char[lenOfData + 1];
                strcpy(charFetchedData, reinterpret_cast<char*>(FetchedData));
            }
            postInfo.push_back(charFetchedData);
        }
        newPost->setUsername(postInfo[0]);
        newPost->setPost(postInfo[1]);
        for (auto iterator : postInfo)
            delete[] iterator;
        postInfo.clear();
        allPostsForCategory.push_back(newPost);
    }
    return allPostsForCategory;
}

void BDComm::addPost(int forumCategoryID, char* name, char* post)
{
    SQLRETURN retcode = 0;

    if (sqlStmtHandle) {
        SQLFreeStmt(sqlStmtHandle, SQL_CLOSE);
    }

    retcode = SQLPrepare(sqlStmtHandle, (SQLWCHAR*)L"EXEC AdaugaPostare ?, ?, ?", SQL_NTS);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception("ERROR WHILE TRYING TO PREPARE THE QUERY FOR DATABASE");

    SQLINTEGER forumCatIDSQLINT = forumCategoryID;
    SQLINTEGER nameLEN = strlen(name) + 1;
    SQLINTEGER postLEN = strlen(post) + 1;
    retcode = SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_SLONG, SQL_INTEGER, 0, 0, &forumCatIDSQLINT, 0, NULL);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception("ERROR WHILE TRYING TO BIND PARAMETER");
    retcode = SQLBindParameter(sqlStmtHandle, 2, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, nameLEN, 0, (SQLPOINTER)name, 0, NULL);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception("ERROR WHILE TRYING TO BIND PARAMETER");
    retcode = SQLBindParameter(sqlStmtHandle, 3, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, postLEN, 0, (SQLPOINTER)post, 0, NULL);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception("ERROR WHILE TRYING TO BIND PARAMETER");

    retcode = SQLExecute(sqlStmtHandle);
    if (SQL_SUCCESS != retcode && SQL_SUCCESS_WITH_INFO != retcode)
        throw Exception("ERROR WHILE TRYING TO EXECUTE THE QUERY");
}

BDComm::~BDComm()
{
    CloseConnection();
}
