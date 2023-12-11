#include <stdio.h>
#include "Empresa.h"

int main()
{
    oop::Empresa empresa = oop::Empresa();
    oop::Empleado e1("Juan Carlos", oop::Empleado::Gerente, 18, 2, 3, true),
        e2("Alberto", oop::Empleado::Temporario, 39, 1, 2, false),
        e3("Francisco", oop::Empleado::PlantaPermanente, 72, 4, 0, true);

    empresa.AddEmpleado(e1);
    empresa.AddEmpleado(e2);
    empresa.AddEmpleado(e3);

    std::cout << empresa << std::endl;

    return 0;
}
