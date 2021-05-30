#include "order.h"
#include <fstream>
#include <iostream>
#include <cstring>


using namespace std;


float Order::calculateOrder(Product product, int quantity)
{
    Order oObj;
    oObj._price=product._price;
    oObj._quantity=quantity;
    oObj._total=oObj._total+(oObj._quantity*oObj._price);
    return oObj._total;
 }

