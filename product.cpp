#include "product.h"
#include <cstring>

using namespace std;

void Product::create(int id,string name,float price)
{
    _id=id;
    strcpy(_name, name.c_str());
    _price=price;
}

int Product::getId()
{
    return _id;
}
char* Product::getName()
{
    return _name;
}
int Product::getPrice()
{
    return _price;
}
/*float Product::getWeight()
{
    Code...
    return weight;
}*/
