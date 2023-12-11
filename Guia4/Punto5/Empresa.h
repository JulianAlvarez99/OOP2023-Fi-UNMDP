#ifndef EMPRESA_H_INCLUDED
#define EMPRESA_H_INCLUDED

#include <iostream>
#include <vector>

#include "Empleado.h"

namespace oop
{
class Empresa
{
private:
    std::vector<Empleado> Empleados_;

public:
    /**
     * @brief Devuelve el monto total a pagar a todos los empleados
     * @return Monto total a pagar a todos los empleados
     */
    double MontoTotal(void);

    /**
     * @brief Agrega un nuevo empleado a la empresa
     * @param empl Empleado
     */
    void AddEmpleado(Empleado &empl);

    friend std::ostream &operator<<(std::ostream &s, const Empresa &emp);
};

std::ostream &operator<<(std::ostream &s, const Empresa &emp);
}

#endif // EMPRESA_H_INCLUDED
