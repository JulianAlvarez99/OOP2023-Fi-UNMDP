#include "Becario.h"

oop::Becario::Becario() : Estudiante(), Empleado()
{
    sTipo = "";
    iDuracion = 0;
    stLaboratorio = "";
    stDirector = "";
}

oop::Becario::Becario(const std::string &name, const unsigned int doc,
                      const oop::Fecha &fnac, const std::string carr,
                      const oop::Fecha &fing, const int cant, const float prom,
                      const std::string cat, const oop::Fecha &feing,
                      const float su, const std::string tipo, const int dur,
                      const std::string lab, const std::string dir)
    : Persona(name, doc, fnac),
      Estudiante(name, doc, fnac, carr, fing, cant, prom),
      Empleado(name, doc, fnac, cat, feing, su)
{
    sTipo = tipo;
    iDuracion = dur;
    stLaboratorio = lab;
    stDirector = dir;
}

oop::Becario::~Becario() {}

void oop::Becario::vSetTipo(const std::string &carr)
{
    sTipo = carr;
}

void oop::Becario::vSetDuracion(const int cant)
{
    iDuracion = cant;
}

void oop::Becario::vSetLaboratorio(const std::string &lab)
{
    stLaboratorio = lab;
}

std::string oop::Becario::stGetTipo() const
{
    return sTipo;
}

int oop::Becario::iGetDuracion() const
{
    return iDuracion;
}

std::string oop::Becario::stGetLaboratorio() const
{
    return stLaboratorio;
}

std::string oop::Becario::stGetDirector() const
{
    return stDirector;
}

std::ostream &oop::operator<<(std::ostream &s, const oop::Becario &b)
{
    return (s << "Nombre = " << b.Name_ << "\nDocumento = " << b.Document_
            << "\nFecha nacimiento = " << b.BirthDate_
            << "\nCategoria = " << b.stCategoria
            << "\nFecha ingreso (empleado) = " << b.Empleado::fechaIngreso
            << "\nSueldo = " << b.fSueldo << "\nCarrera = " << b.stCarrera
            << "\nFecha ingreso (estudiante) = " << b.Estudiante::fechaIngreso
            << "\nCantidad de materias = " << b.iMaterias << "\nPromedio = "
            << b.fPromedio << "\nTipo de beca = " << b.sTipo
            << "\nDuracion = " << b.iDuracion
            << "\nLugar trabajo = " << b.stLaboratorio
            << "\nNombre director = " << b.stDirector << "\n"
            << std::endl);
}
