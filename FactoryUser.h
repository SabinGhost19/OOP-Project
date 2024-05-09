#ifndef FACTORYUSER_H
#define FACTORYUSER_H
#include"userClient.h"
#include"userRequest.h"

class FactoryUser
{
    UserRequest*new_request=nullptr;
public:
    FactoryUser();
    UserClient*ConstructClientUser(int ID);
};

#endif // FACTORYUSER_H
