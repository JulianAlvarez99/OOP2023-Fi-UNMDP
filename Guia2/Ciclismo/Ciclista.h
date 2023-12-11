#ifndef CICLISTA_H_INCLUDED
#define CICLISTA_H_INCLUDED
#include "FechaClicismo.h"
#include "TiempoCiclismo.h"
#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;

class ciclista
{
    private:
        string nombre;
        string apellido;
        fecha fechaNacimiento;
        tiempo tiempoPrueba;
        uint16_t nroVueltas = 0;

    public:
        ciclista();
        ciclista(string, string, fecha);
        tiempo getTiempoPrueba();
        uint16_t getNroVueltas();
        string getNombre();
        string getApellido();
        void PrimeraPrueba();
        void numeroVueltas();
        void imprimir();
};
tiempo* tablaTiempos(ciclista**,uint16_t);
tiempo tiempoMinimo(tiempo*,uint16_t );
uint16_t mejorVuelta(ciclista**,uint16_t );
void difTiempo(tiempo,tiempo);
void difVuelta(uint16_t, uint16_t);

#endif // CICLISTA_H_INCLUDED
