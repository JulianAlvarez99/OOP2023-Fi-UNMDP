#ifndef TIEMPOCICLISMO_H_INCLUDED
#define TIEMPOCICLISMO_H_INCLUDED
#include <iostream>
#include <iomanip>
#include <time.h>
#include <cstdlib>

using namespace std;

class tiempo
{
    private:
        uint16_t hora;
        uint16_t minutos;
        uint16_t segundos;

    public:
        tiempo();

        void setHora(uint16_t hh);
        void setMinutos(uint16_t mm);
        void setSegundos(uint16_t ss);
        uint16_t getSegundos();
        uint16_t getMinutos();
        uint16_t getHora();
        void setDatos(uint16_t,uint16_t,uint16_t);
        void ingresarDatos();
        void muestra_fmt_estandar();
        void muestra_fmt_universal();
        tiempo tiempo_Prueba();
};

#endif // TIEMPOCICLISMO_H_INCLUDED
