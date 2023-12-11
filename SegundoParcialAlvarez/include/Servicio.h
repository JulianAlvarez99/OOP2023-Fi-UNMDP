#ifndef SERVICIO_H
#define SERVICIO_H
#include <iostream>
#include "CPersona.h"

using namespace std;
class Servicio
{
    public:
        Servicio();
        virtual ~Servicio();

        virtual double costoMaterial() = 0;
        virtual double costoManoObra() = 0;
        virtual double costoTotal() = 0;
        virtual void detalleServicio(ostream& os = cout) = 0;
        CFecha GetInicioServicio();
        CPersona GetCliente();
        CPersona GetTrabajador();

    protected:
        CPersona Trabajador;
        CPersona Cliente;
        CFecha InicioServicio;
    private:
};

#endif // SERVICIO_H
