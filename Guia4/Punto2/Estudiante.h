#ifndef ESTUDIANTE_H_INCLUDED
#define ESTUDIANTE_H_INCLUDED

#include <iostream>

#include "Persona.h"

namespace oop
{
class Estudiante : public virtual Persona
{
public:
    Estudiante();
    Estudiante(const std::string &name, unsigned int doc, const Fecha &fnac,
               const std::string &carrera, const Fecha &fing,
               const int cant, const float prom);
    virtual ~Estudiante() override;

    void vSetCarrera(const std::string &carr);
    bool vSetIngreso(const Fecha &date);
    bool vSetIngreso(const int dd, const int mm, const int aa);
    void vSetMaterias(const int cant);
    void vSetPromedio(const float prom);

    std::string stGetCarrera() const;
    Fecha fechaGetIngreso() const;
    int iGetMaterias() const;
    float GetPromedio() const;

    friend std::ostream &operator<<(std::ostream &os,
                                    const Estudiante &est);

protected:
    std::string stCarrera;
    int iMaterias;
    Fecha fechaIngreso;
    float fPromedio;
};

std::ostream &operator<<(std::ostream &os, const oop::Estudiante &est);
}

#endif // ESTUDIANTE_H_INCLUDED
