#include "Empresa.h"

#include <cmath>

double oop::Empresa::MontoTotal()
{
    double monto(0);

    for (auto &empl : Empleados_)
    {
        monto += empl.GetPagoTotal();
    }

    return monto;
}

void oop::Empresa::AddEmpleado(Empleado &empl)
{
    Empleados_.push_back(empl);
}

std::ostream &oop::operator<<(std::ostream &s, const Empresa &emp)
{
    double pago_total(0), pago_actual(0);

    for (auto &empl : emp.Empleados_)
    {
        pago_actual = empl.GetPagoTotal();
        s << empl.GetNombre() << ": $" << pago_actual << "\n";
        pago_total += pago_actual;
    }

    s << "\nTotal: $" << pago_total;

    return s;
}
