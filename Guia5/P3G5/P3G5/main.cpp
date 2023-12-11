#include <iostream>
#include "Banco.h"
#include "CuentaUniversitaria.h"
#include "CuentaCorriente.h"
#include "CajaAhorro.h"

using namespace std;

int main()
{
    Banco Galicia;
    Galicia.setCuentasActivas(0);

    Cliente cl1("Julian Alvarez", 42282383,Fecha(9,11,1999));
    Cliente cl2("Oriana Sapienza Muller", 44722161,Fecha(20,04,2003));
    Cuenta *ca = new CajaAhorro(Galicia.getNroSucursal(),Galicia.getIDBanco(),cl1,Galicia.getCuentasActivas(),15000,30,7);
    Galicia
    Cuenta *cc = new CuentaCorriente(Galicia.getNroSucursal(),Galicia.getIDBanco(),cl2,Galicia.getCuentasActivas(),20000000,15000);

    system("pause");
    system("cls");

    Galicia.Alta_Cuenta(ca);
    Galicia.Alta_Cuenta(cc);

    ca->printCuenta();
    ca->deposito(41.25);
    ca->extraccion(41.25);

    cc->printCuenta();
    cc->deposito(65545.36);
    cc->extraccion(894.23);


    return (0);
}
