#ifndef BECARIO_H_INCLUDED
#define BECARIO_H_INCLUDED

#include <iostream>
#include <string>

#include "Empleado.h"
#include "Estudiante.h"

namespace oop
{
class Becario final : public Estudiante, public Empleado
{
public:
    Becario();
    Becario(const std::string &name, const unsigned int doc,
            const Fecha &fnac, const std::string carr, const Fecha &fing,
            const int cant, const float prom, const std::string cat,
            const Fecha &feing, const float su, const std::string tipo,
            const int dur, const std::string lab, const std::string dir);
    virtual ~Becario() final;

    void vSetTipo(const std::string &carr);
    void vSetDuracion(const int cant);
    void vSetLaboratorio(const std::string &lab);

    std::string stGetTipo() const;
    int iGetDuracion() const;
    std::string stGetLaboratorio() const;
    std::string stGetDirector() const;

    friend std::ostream &operator<<(std::ostream &s, const Becario &b);

protected:
    std::string sTipo;
    int iDuracion;
    std::string stLaboratorio;
    std::string stDirector;
};

std::ostream &operator<<(std::ostream &s, const Becario &b);
}

#endif // BECARIO_H_INCLUDED
