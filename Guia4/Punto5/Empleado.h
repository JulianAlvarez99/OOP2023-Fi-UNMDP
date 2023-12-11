#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED

#include <iostream>
#include <string>

namespace oop
{
    class Empleado
    {
    private:
        std::string Nombre_;
        double HorasTrabajadas_;
        int TipoEmpleado_;
        int AnosAntiguedad_;
        int CantHijos_;
        bool Casado_;
        static const double SalarioPorHora_[];
        static const double SalarioAntiguedad_[];
        static const double SalarioFamiliar_;
        static const double MontoPareja_;
        Empleado();

    public:
        enum TipoEmpleado
        {
            PlantaPermanente = 0,
            Temporario,
            Gerente
        };

        /**
         * @brief Constructor de clase Empleado
         * @param nombre Nombre del empleado
         * @param tipo Tipo de empleado (planta permanente, temporario o
         * gerente)
         * @param horas Cantidad de horas trabajadas
         * @param anos Cantidad de años de antigüedad
         * @param hijos Cantidad de hijos
         * @param casado Si está casado
         */
        Empleado(const std::string &nombre, const TipoEmpleado tipo,
                 double horas, int anos, int hijos, bool casado);

        /**
         * @brief Devuelve el nombre del empleado
         * @return std::string con el nombre del empleado
         */
        std::string GetNombre() const;

        /**
         * @brief Devuelve las horas trabajadas por el empleado
         * @return Cantidad de horas trabajadas por el empleado
         */
        double GetHorasTrabajadas() const;

        /**
         * @brief Devuelve un entero que identifica al tipo de empleado
         * @return Un entero que identifica al tipo de empleado
         */
        int GetTipoEmpleado() const;

        /**
         * @brief Devuelve los años de antigüedad del empleado
         * @return Años de antigüedad del empleado
         */
        int GetAnosAntiguedad() const;

        /**
         * @brief Devuelve la cantidad de hijos del empleado
         * @return Cantidad de hijos del empleado
         */
        int GetCantHijos() const;

        /**
         * @brief Devuelve true si el empleado está casado
         * @return Boolean indicando si el empleado está casado
         */
        bool GetCasado() const;

        /**
         * @brief Devuelve el salario por hora del empleado
         * @return Salario por hora del empleado
         */
        double GetSalarioPorHora() const;

        /**
         * @brief Devuelve el monto pagado por año de antigüedad
         * @return Monto pagado por año de antigüedad
         */
        double GetSalarioAntiguedad() const;

        /**
         * @brief Devuelve el monto pagado por cada hijo
         * @return Monto pagado por cada hijo
         */
        double GetSalarioFamiliar() const;

        /**
         * @brief Devuelve el monto total a pagar al empleado
         * @return Monto total a pagar al empleado
         */
        double GetPagoTotal() const;

        /**
         * @brief Establece el nombre del empleado
         * @param nombre Nombre nuevo
         */
        void SetNombre(const std::string &nombre);

        /**
         * @brief Establece las horas que el empleado ha trabajado
         * @param horas Horas de trabajo
         */
        void SetHorasTrabajadas(const double horas);

        /**
         * @brief Establece el tipo de empleado
         * @param tipo Un entero que representa al tipo de empleado (ver
         * oop::Empleado::TipoEmpleado)
         */
        void SetTipoEmpleado(const TipoEmpleado tipo);

        /**
         * @brief Establece la antigüedad del empleado
         * @param anos Nueva antigüedad
         */
        void SetAnosAntiguedad(const int anos);

        /**
         * @brief Establece la cantidad de hijos del empleado
         * @param hijos Nueva cantidad de hijos
         */
        void SetCantHijos(const int hijos);

        /**
         * @brief Establece el estado civil del empleado
         * @param casado Nuevo estado civil
         */
        void SetCasado(const bool casado);
    };
}

std::ostream &operator<<(std::ostream &s, const oop::Empleado &empl);

#endif // EMPLEADO_H_INCLUDED
