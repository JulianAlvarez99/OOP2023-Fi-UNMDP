#include "Ciclista.h"
#include <iostream>
#include <algorithm>
#define NUMCLTS 9

using namespace std;

int main()
{
    ciclista* clts[NUMCLTS];
    tiempo* tabla;
    tiempo minimo;
    uint16_t mejor_vuelta = 0;

    clts[0] = new ciclista("Julian", "Alvarez", fecha(9,11,1999));
    clts[1] = new ciclista("Camila", "Baldoma", fecha(12,9,2002));
    clts[2] = new ciclista("Coni", "Mana", fecha(23,9,2001));
    clts[3] = new ciclista("Manuel", "Cabrera", fecha(31,12,2001));
    clts[4] = new ciclista("Maxi", "DeLellis", fecha(7,8,2002));
    clts[5] = new ciclista("Jorge", "Turina", fecha(16,1,1999));
    clts[6] = new ciclista("Oriana", "Muller", fecha(20,4,2003));
    clts[7] = new ciclista("Mario", "Mayor", fecha(30,3,2000));
    clts[8] = new ciclista("Fren", "Veron", fecha(17,1,2000));

    for(int i = 0; i<NUMCLTS; i++)
    {
        clts[i]->PrimeraPrueba();
        clts[i]->numeroVueltas();
    }

    tabla=tablaTiempos(clts,NUMCLTS);
    minimo = tiempoMinimo(tabla,NUMCLTS);
    mejor_vuelta = mejorVuelta(clts,NUMCLTS);

    cout<<"Nombre\t\t"<<"Edad\t"<<"Tiempo primera prueba\t"<<"Nro de vueltas\t"<<"Dif del mejor tiempo\t"<<"Dif vueltas segunda prueba"<<endl;
    for(int i = 0; i<NUMCLTS; i++)
    {
        clts[i]->imprimir();
        difTiempo(clts[i]->getTiempoPrueba(),minimo);
        difVuelta(mejor_vuelta,clts[i]->getNroVueltas());
        cout<<endl;
    }

    delete[] tabla;
    return 0;
}
