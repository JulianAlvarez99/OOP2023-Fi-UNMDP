#include <iostream>
using namespace std;

void Xhandler(int test)
{
    if(test == 0)
        throw 5;
    if(test == 1)
        throw 'A';
    if(test==2)
        throw 123.45;
    if(test==3)
        throw "Hola";

}

int main()
{
    cout << "Inicio" << endl<< endl;
    Xhandler(0);
    Xhandler(1);
    Xhandler(2);
    try
    {
        Xhandler(3);
    }
    catch(int i)
    {
        cout<<"Capturado un entero: "<< i<< "\n\n";
    }
    catch(char c)
    {
        cout<<"Capturado un caracter: "<< c<< "\n\n";
    }
    catch(double d)
    {
        cout<<"Capturado un double: "<< d<< "\n\n";
    }
    catch(...)
    {
        cout<<"Captura todos los tipos\n\n";
    }


    cout<<"\nFin\n\n";

    return 0;
}
