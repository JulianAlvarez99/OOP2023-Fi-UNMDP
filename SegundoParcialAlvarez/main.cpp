#include <iostream>
#include "ManejadorServicios.h"

using namespace std;

int main()
{
    ManejadorServicios ms;
    ms.RecuperarServicios_bin("servicios.bin");

    ms.imprimirTrabajos();

    cout<<"Facturacion total: $ "<<ms.facturacionTotal()
        <<"\n Sueldos total: $ "<<ms.montoSueldos()<<endl;

    ms.OrdenarFecha();
    ms.imprimirTrabajos();

    ofstream of;
    of.exceptions(ofstream::badbit);
    try
    {
    of.open("OrdenFecha.txt");
    ms.imprimirTrabajos(of);
    }
    catch(const ofstream::failure& e)
    {
        cout<<"Excepcion al abrir/escribir el archivo"<<endl;
    }
    of.close();

    ms.OrdenarNombresDecrecientes();
    ms.imprimirTrabajos();

    try
    {
    of.open("OrdenNombre.txt");
    ms.imprimirTrabajos(of);
    }
    catch(const ofstream::failure& e)
    {
        cout<<"Excepcion al abrir/escribir el archivo"<<endl;
    }
    of.close();

    return 0;
}
