#include "Estudiante.h"

oop::Estudiante::Estudiante() : Persona()
{
    stCarrera = "";
    fechaIngreso = Fecha();
    vSetMaterias(0);
    vSetPromedio(0.0);
}

oop::Estudiante::Estudiante(const std::string &name, unsigned int doc,
                            const Fecha &fnac, const std::string &carrera,
                            const Fecha &fing, const int cant, const float prom)
    : Persona(name, doc, fnac)

{
    stCarrera = carrera;
    fechaIngreso = fing;
    vSetMaterias(cant);
    vSetPromedio(prom);
}

oop::Estudiante::~Estudiante() {}

void oop::Estudiante::vSetCarrera(const std::string &carr)
{
    stCarrera = carr;
}

bool oop::Estudiante::vSetIngreso(const Fecha &date)
{
    fechaIngreso = date;
    return true;
}

bool oop::Estudiante::vSetIngreso(const int dd, const int mm, const int aa)
{
    bool result = false;
    Fecha fecha(dd, mm, aa);

    if (fecha.Day == dd && fecha.Month == mm && fecha.Year == aa)
    {
        result = true;
    }

    return result;
}

void oop::Estudiante::vSetMaterias(const int cant)
{
    iMaterias = cant >= 0 ? cant : 0;
}

std::string oop::Estudiante::stGetCarrera() const
{
    return stCarrera;
}

oop::Fecha oop::Estudiante::fechaGetIngreso() const
{
    return fechaIngreso;
}

int oop::Estudiante::iGetMaterias() const
{
    return iMaterias;
}

float oop::Estudiante::GetPromedio() const
{
    return fPromedio;
}

void oop::Estudiante::vSetPromedio(const float prom)
{
    fPromedio = prom >= 0 ? prom : 0;
}

std::ostream &oop::operator<<(std::ostream &os, const oop::Estudiante &est)
{
    return (os << est.Name_ << "\nDocumento = " << est.Document_
            << "\nFecha nacimiento = " << est.BirthDate_ << "\nCarrera = "
            << est.stCarrera << "\nFecha ingreso = " << est.fechaIngreso
            << "\nCantidad de materias aprobadas = " << est.iMaterias
            << "\nPromedio = " << est.fPromedio << "\n"
            << std::endl);
}
