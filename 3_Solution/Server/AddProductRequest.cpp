#include "AddProductRequest.h"
#include "ProductBuilder.h"
#include "APPServer.h"
#include "Product.h"

bool AddProductRequest::receiveRequest()
{
    ProductBuilder productBuilder;
    Product* productCreated = productBuilder.buildProductFromRequest();
    return true;
}

bool AddProductRequest::sendAnswear()
{
    return false;
}
