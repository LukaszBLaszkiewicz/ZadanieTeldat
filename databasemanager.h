#include <string>
#include "product.h"
#pragma once

using namespace std;
class DatabaseManager
{
    const string dataBase="database.dat";
    public:
    void save(Product product);
    Product read(int id);
    void readAllProducts();
    void delProduct(int id);

};
