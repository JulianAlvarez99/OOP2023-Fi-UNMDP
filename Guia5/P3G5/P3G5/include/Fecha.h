#ifndef FECHA_H
#define FECHA_H
#include "Fecha.h"
#include <time.h>
#include <iostream>

using namespace std;

class Fecha
{
public:
    int Day;
    int Month;
    int Year;

    Fecha(const int d = 1, const int m = 1, const int a = 1970);
    friend ostream &operator<<(ostream &s, const Fecha &f);
};

void Mostrar_TiempoFecha();




#endif // FECHA_H
