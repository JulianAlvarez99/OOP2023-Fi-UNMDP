#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED
#include <iostream>
#include "Fecha.h"

using namespace std;

class empleado
{
    private:
        string nombre;
        string apellido;
        fecha fechaContratacion;
        fecha fechaNacimiento;
    public:
        empleado(string, string, fecha, fecha);
        void imprimir();
};


#endif // EMPLEADO_H_INCLUDED
