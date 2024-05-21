#ifndef FACTORYUSER_H
#define FACTORYUSER_H
#include"userClient.h"
#include"userRequest.h"
#include"userCompany.h"

class FactoryUser
{
    UserRequest*new_request=nullptr;
    int rol=0;

public:
    FactoryUser();
    void Initializing();
    void ConstructUser();
    UserCompany*ConstrucCompanytUser(int ID);
    UserClient*ConstrucClienttUser(int ID);
    void setRol(int rol_param);
    int GetRol();

};

#endif // FACTORYUSER_H
