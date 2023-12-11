#include <iostream>
#include "Vehiculo.h"

using namespace std;


int main()
{
    vehiculo v1("Renault","LKI 060","CLIO 2 16v",3,1.2,2012,81840);

    cout<<v1.getMarca()<<"\n"<<endl;
    cout<<v1.getModelo()<<"\n"<<endl;
    cout<<"Patente "<<v1.getPatente()<<"\n"<<endl;
    cout<<"Cilindrada "<<v1.getCilindrada()<<"\n"<<endl;
    cout<<v1.getPuertas()<<" Puertas \n"<<endl;
    cout<<v1.getKm()<<" Km \n"<<endl;
    cout<<"Modelo "<<v1.getLinea()<<"\n"<<endl;


    return 0;
}
