#include "BDComm.h"
#include "ServerLogger.h"
#include "Exception.h"
#include <iostream>

#define SQL_RESULT_LEN 240
#define SQL_RETURN_CODE_LEN 1000

using namespace std;

BDComm::BDComm()
{
    return;
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

bool BDComm::verifyAccountLogIn(char* email, char* password)
{
    
}

const char* BDComm::GetQuery(SQLWCHAR* query, int& len)
{
    if (SQL_SUCCESS != SQLExecDirect(sqlStmtHandle, query, SQL_NTS)) {
        ServerLogger::getInstance("SQLLogger.txt")->loggAction("QUERYING SQL SERVER FAILED");
        throw("QUERYING SQL SERVER FAILED");
    }
    else {
        SQLCHAR sqlVersion[SQL_RESULT_LEN];
        SQLLEN ptrSqlVersion;
        while (SQLFetch(sqlStmtHandle) == SQL_SUCCESS) {
            SQLGetData(sqlStmtHandle, 1, SQL_CHAR, sqlVersion, SQL_RESULT_LEN, &ptrSqlVersion);
            return reinterpret_cast<const char*>(sqlVersion);
        }
    }
}

BDComm::~BDComm()
{
    CloseConnection();
}
