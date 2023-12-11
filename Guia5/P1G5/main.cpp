#include <iostream>
#include "AutoDeportivo.h"
#include "Furgoneta.h"
#include "Sedan.h"
#include "Camion.h"

using namespace std;

int main()
{
   // Vehiculo *v1 = new Auto;
    Vehiculo *v2 = new Camion;
    Vehiculo *a1 = new AutoDeportivo;
    Vehiculo *a2 = new Furgoneta;
    Vehiculo *a3 = new Sedan;

    v2->Acelerar();
    a1->Acelerar();
    a2->Acelerar();
    a3->Acelerar();
    v2->Frenar();
    a1->Frenar();
    a2->Frenar();
    a3->Frenar();

    delete v2;
    delete a1;
    delete a2;
    delete a3;

    return 0;
}

