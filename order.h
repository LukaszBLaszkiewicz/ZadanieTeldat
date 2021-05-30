#include <string>
#include "product.h"
#pragma once
class Order
{
    public:
    int _id;
    char _name[15];
    float _price;
    int _quantity;
    float _total;

    public:
    float calculateOrder(Product product, int quantity);
};
