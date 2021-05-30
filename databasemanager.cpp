#include "databasemanager.h"
#include <iostream>
#include <fstream>
void DatabaseManager::save(Product product)
    {
        Product pObj;
        fstream file;
        file.open(dataBase,ios::in|ios::app|ios::out);
        file.write((char*)&product,sizeof(Product));
        file.close();
    }
Product DatabaseManager::read(int id)
    {
        fstream file;
        Product pObj,ptemp;
        file.open(dataBase,ios::in|ios::app|ios::out);
        while(file.read((char*)&ptemp,sizeof(Product)))
            {
                if(ptemp.getId()==id)
                {
                    pObj=ptemp;
                    break;
                }

            }
        file.close();
        return pObj;
    }
void DatabaseManager::readAllProducts()
    {
        system("clear");
        Product pObj;
        Product tab[sizeof(Product)];
        fstream file;
        int k=0,a=0;
        cout<<"\n==========================================================";
        cout<<"\n=====================PRODUCT LIST=========================";
        cout<<"\nProduct ID\t"<<"Product Name\t"<<"Product Price";
        file.open(dataBase,ios::in);
        while(file.read((char*)&pObj,sizeof(Product)))
            {
                tab[k]=pObj;
                k=k+1;
            }
            for(int i=0;i<k;i++)
              {
                for(int j=0;j<k-1;j++)
                {
                  if(tab[j]._id>tab[j+1]._id)
                  {
                    Product temp;
                    temp=tab[j];
                    tab[j]=tab[j+1];
                    tab[j+1]=temp;
                  }
                }
              }
              for(int i=0;i<k;i++)
              {
                 cout<<"\n"<<tab[i].getId()<<"\t\t"<<tab[i].getName()<<"\t\t"<<tab[i].getPrice();
              }
        getchar();
        file.close();
    }
void DatabaseManager::delProduct(int id)
    {
        fstream file,file2;
        Product pObj;
        file.open("database.dat",ios::in|ios::out);
        file2.open("databaseTemp.dat",ios::out|ios::app);
        file.seekg(0,ios::beg);
        while(file.read((char*)&pObj,sizeof(Product)))
        {
            if(pObj.getId()!=id)
            {
                file2.write((char*)&pObj,sizeof(Product));
            }
        }
        file2.close();
        file.close();
        remove("database.dat");
        rename("databaseTemp.dat","database.dat");
        remove("databaseTemp.dat");
        getchar();
    }

