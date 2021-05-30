#include <iostream>
#include "product.h"
#include "databasemanager.h"
#include "order.h"
#include <fstream>

using namespace std;

void managementPanel()
{
    int zm,id,price;
    string name;
    for(;;)
    {
        system("clear");
        cout<<"\n==========================================";
        cout<<"\n1.Add product to database";
        cout<<"\n2.Delete product from database";
        cout<<"\n3.Show all products";
        cout<<"\n4.Exit";
        cout<<"\nYour choice: ";
        cin>>zm;
        switch(zm)
            {
            case 1:
                {
                        Product pObj;
                        DatabaseManager dbObj;
                        system("clear");
                        cout<<"\n=================================";
                        cout<<"\nAdd product to database ";
                        cout<<"\nProduct ID: ";
                        cin>>id;
                        pObj=dbObj.read(id);
                        if(pObj.getId()==id)
                            {
                                cout<<"Product already exist";
                                managementPanel();
                            }
                        else
                            {
                                cout<<"\nProduct name: ";
                                cin>>name;
                                cout<<"\nProduct price: ";
                                cin>>price;
                                dbObj.read(id);
                                pObj.create(id,name,price);
                                dbObj.save(pObj);
                                break;
                            }
                }
            case 2:
                {
                        DatabaseManager dbObj;
                        Product pObj;
                        system("clear");
                        dbObj.readAllProducts();
                        cout<<"\nProduct ID to delete: ";
                        cin>>id;
                        pObj=dbObj.read(id);
                        if(pObj.getId()!=id)
                            {
                                cout<<"Product doesnt exist!Press any key to go to management panel";
                                getchar();
                                break;
                            }
                        else
                            {
                                dbObj.delProduct(id);
                                cout<<"\nProduct deleted!Press any key to go to management panel";
                                getchar();
                                break;
                            }
                }

            case 3:
                {
                        DatabaseManager dbObj;
                        dbObj.readAllProducts();
                        cout<<"\nPress any button to go to managment panel...";
                        getchar();
                        break;

                }
            case 4:
                {
                        return;
                }
            default:
                {
                        cout<<"Wrong number!";
                        getchar();
                }
            }
    }
}
void submitOrder()
{
    int id,quantity,i,a,total=0;
    char yn='Y';
    Product tab[sizeof(Product)];
    DatabaseManager dbObj;
    Order ordObj;
    Product pObj;
    fstream file;
        do
        {
            system("clear");
            dbObj.readAllProducts();
            cout<<"\n==========================================================";
            cout<<"\nPlease type product ID which you want to buy: ";
            cin>>id;
            pObj=dbObj.read(id);
            file.open("database.dat",ios::in|ios::out);
            while(file.read((char*)&pObj,sizeof(Product))&& i==0)
            {
                if(pObj.getId()==id)
                {
                    system("clear");
                    cout<<"\nProduct ID\t"<<"Product Name\t"<<"Product Price\t";
                    cout<< "\n"<<pObj.getId() << "\t\t" << pObj.getName()<<"\t\t"<<pObj.getPrice();
                    if(pObj.getPrice()>0)
                    {
                        cout << "\nQuantitiy:  ";
                        cin >>quantity;
                        total=total+ordObj.calculateOrder(pObj,quantity);
                        tab[a]=pObj;
                        i=1;
                        break;
                    }
                /*  else
                    {
                        cout<<"\nPlace product on weight";
                        total=total+(pObj.getWeight()*pObj.pricePer100g);
                    } */
                }
            }
            file.close();
            if(i==0)
                {
                    cout<<"\nProduct you search doesnt exist";
                }
            else if(i==1)
                {
                     system("clear");
                     cout<<"\n\n======================YOUR ORDER===========================";
                     cout<<"\nProduct ID\t"<<"Product Name\t"<<"Product Price\t"<<"Quantity";
                     for(int temp=0;temp<=a;temp++)
                         {
                            cout<<"\n"<<tab[temp].getId()<<"\t\t"<<tab[temp].getName()<<"\t\t"<<tab[temp].getPrice();
                         }
                     a=a+1;
                     cout<<"\n==========================================================";
                     cout<<"\nTotal: "<< total;
                }

            cout<<"\nDo you want to continue your order?(Y/N)";
            cin >> yn;
            i=0;
        }while(yn=='y'|| yn=='Y');



}
int main()
{
    int zm;
    for(;;)
    {
        system("clear");
        cout<<"\n==========================================";
        cout<<"\n1.Management Panel";
        cout<<"\n2.Submit your order";
        cout<<"\n3.Exit";
        cout<<"\nYour choice:  ";
        cin >>zm;
            switch(zm)
            {
            case 1:
                        system("clear");
                        managementPanel();
                        break;
            case 2:
                        system("clear");
                        submitOrder();
                        break;
            case 3:
                        return 0;
            default:
                        cout<<"Wrong number!";
                        getchar();
            }
    }
    return 0;
}
