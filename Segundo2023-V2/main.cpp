#include <iostream>
#include "ManejadorServicios.h"

/***
    Cambios hechos:
    De ManejadorServicios.cpp la variable TipoTrabajo tenia que ser de tipo uint8_t : Linea 82

    Se cambiaron los valores de las condiciones de los if, que arrastraba del error del item anterior
    por no levantar bien el dato del tipo de trabajador, ya que levantaba un dato int, levantaba mas informacion
    de la que necesitaba : Linea 96  valor 170 y linea 147 valor 85

    De Servicio.cpp solo se agrego referencia (&) a los getters, porque sino nunca actualizaba los datos : Lineas 17, 18 y 19 del .h
    y lineas 12, 16 y 20 del .cpp
**/

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
