#include <string>
#pragma once
using namespace std;
class Product
{
    public:
    int _id;
    char _name[15];
    float _price;

    public:

    void create(int id,string name,float price);
    int getId();
    char* getName();
    int getPrice();
};

