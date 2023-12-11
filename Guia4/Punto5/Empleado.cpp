#include "Empleado.h"

const double oop::Empleado::SalarioPorHora_[] = {30.0, 20.0, 40.0};

const double oop::Empleado::SalarioAntiguedad_[] = {10.0, 0.0, 15.0};

const double oop::Empleado::SalarioFamiliar_ = 20.0;

const double oop::Empleado::MontoPareja_ = 10.0;

oop::Empleado::Empleado(const std::string &nombre, const TipoEmpleado tipo,
                        double horas, int anos, int hijos, bool casado)
{
    Nombre_ = nombre;
    TipoEmpleado_ = tipo;
    HorasTrabajadas_ = horas;
    AnosAntiguedad_ = anos;
    CantHijos_ = hijos;
    Casado_ = casado;
}

std::string oop::Empleado::GetNombre() const
{
    return Nombre_;
}

double oop::Empleado::GetHorasTrabajadas() const
{
    return HorasTrabajadas_;
}

int oop::Empleado::GetTipoEmpleado() const
{
    return TipoEmpleado_;
}

int oop::Empleado::GetAnosAntiguedad() const
{
    return AnosAntiguedad_;
}

int oop::Empleado::GetCantHijos() const
{
    return CantHijos_;
}

bool oop::Empleado::GetCasado() const
{
    return Casado_;
}

double oop::Empleado::GetSalarioPorHora() const
{
    return SalarioPorHora_[TipoEmpleado_];
}

double oop::Empleado::GetSalarioAntiguedad() const
{
    return SalarioAntiguedad_[TipoEmpleado_];
}

double oop::Empleado::GetSalarioFamiliar() const
{
    return SalarioFamiliar_;
}

double oop::Empleado::GetPagoTotal() const
{
    return (HorasTrabajadas_ * SalarioPorHora_[TipoEmpleado_] +
            AnosAntiguedad_ * SalarioAntiguedad_[TipoEmpleado_] +
            CantHijos_ * SalarioFamiliar_ + (Casado_ ? MontoPareja_ : 0));
}

void oop::Empleado::SetNombre(const std::string &nombre)
{
    Nombre_ = nombre;
}

void oop::Empleado::SetHorasTrabajadas(const double horas)
{
    if (horas >= 0)
    {
        HorasTrabajadas_ = horas;
    }
}

void oop::Empleado::SetTipoEmpleado(const TipoEmpleado tipo)
{
    TipoEmpleado_ = tipo;
}

void oop::Empleado::SetAnosAntiguedad(const int anos)
{
    if (anos >= 0)
    {
        AnosAntiguedad_ = anos;
    }
}

void oop::Empleado::SetCantHijos(const int hijos)
{
    if (hijos >= 0)
    {
        CantHijos_ = hijos;
    }
}

void oop::Empleado::SetCasado(const bool casado)
{
    Casado_ = casado;
}

std::ostream &operator<<(std::ostream &s, const oop::Empleado &empl)
{
    return (s << empl.GetNombre() << ": $" << empl.GetPagoTotal());
}
