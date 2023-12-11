#include "Empleado.h"

oop::Empleado::Empleado() : Persona()
{
    stCategoria = "";
    fechaIngreso = Fecha();
    fSueldo = 0.0;
}

oop::Empleado::Empleado(const std::string &name, const unsigned int doc,
                        const Fecha &fnac, const std::string &categoria,
                        const Fecha &fing, float sueldo)
    : Persona(name, doc, fnac)
{
    stCategoria = categoria;
    fechaIngreso = fing;
    fSueldo = sueldo;
}

oop::Empleado::~Empleado() {}

void oop::Empleado::vSetCategoria(const std::string &carr)
{
    stCategoria = carr;
}

bool oop::Empleado::vSetIngreso(const oop::Fecha &date)
{
    fechaIngreso = date;
    return true;
}

bool oop::Empleado::vSetIngreso(const int dd, const int mm, const int aa)
{
    bool result = false;
    Fecha fecha(dd, mm, aa);

    if (fecha.Day == dd && fecha.Month == mm && fecha.Year == aa)
    {
        fechaIngreso = fecha;
        result = true;
    }

    return result;
}

void oop::Empleado::fSetSueldo(const float prom)
{
    fSueldo = prom;
}

std::string oop::Empleado::stGetCategoria() const
{
    return stCategoria;
}

oop::Fecha oop::Empleado::fechaGetIngreso() const
{
    return fechaIngreso;
}

float oop::Empleado::fGetSueldo() const
{
    return fSueldo;
}

std::ostream &oop::operator<<(std::ostream &os, const oop::Empleado &est)
{
    return (os << "Nombre = " << est.Name_ << "\nDocumento = " << est.Document_
            << "\nFecha nacimiento = " << est.BirthDate_ << "\nCategoria"
            << est.stCategoria << "\nFecha ingreso = " << est.fechaIngreso
            << "\nSueldo = " << est.fSueldo << "\n"
            << std::endl);
}
