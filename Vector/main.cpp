#include <iostream>
#include "cVector.h"
#include "ctime"

using namespace std;
using namespace oop;

string crear(int leng)
{
    char a;
    string b;
    for(int i = 0; i < leng; i++)
    {
        a = 97 + rand() % (122 - 97);
        b += a;
    }
    return b;
}


int main()
{

    vector str;

    str.reserve(5);

    str.push_back("Puto");
    str.push_back(" el");
    str.push_back(" que");
    str.push_back(" lee");
    str.push_back(" dea");

    for(int i = 0; i<(int)str.capacity()-1 ;i++)
    {
       cout<<str[i];
    }
    cout<<endl<<endl;

    while(!str.empty())
    {
     str.pop_back();
    }

    cout<<"El tamanio del vector es: "<<str.size()<<endl;

    str.reserve(10);

    cout<<"El vector puede almacenar: "<<str.capacity()<<" elementos"<<endl;
    for(int i = 0; i<(int)str.capacity() ;i++)
    {
        srand(time(NULL)+rand());

        str.push_back(crear(15));
    }

      for(int i = 0; i<(int)str.capacity()-1 ;i++)
    {
       cout<<str[i]<<endl;
    }
    cout<<endl<<endl;
    cout<< str.full()<<endl;

     while(!str.empty())
    {
     str.pop_back();
    }

    str.clear();
    cout<<str.full()<<endl;
    cout<<"El tamanio del vector es: "<<str.size()<<endl;

    return 0;
}
