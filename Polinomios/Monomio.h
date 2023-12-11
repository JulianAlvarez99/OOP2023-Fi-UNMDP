#ifndef MONOMIO_H_INCLUDED
#define MONOMIO_H_INCLUDED
#include <iostream>

namespace oop
{
class Monomio
{
private:
    double Coef_;
    double Degree_;

public:
    /**
     * @brief Crea una nueva instancia de un Monomio constante
     */
    Monomio(const double coef = 0);

    /**
     * @brief Crea una nueva instancia de Monomio
     * @param coef Coeficiente
     * @param deg Grado
     */
    Monomio(const double coef, const double deg);

    /**
     * @brief Devuelve el valor del coeficiente
     * @return Double con el coeficiente del monomio
     */
    double GetCoef() const;

    /**
     * @brief Devuelve el grado del monomio
     * @return Double con el grado del monomio
     */
    double GetDegree() const;

    /**
     * @brief Establece el coeficiente del monomio
     * @param coef Coeficiente nuevo
     */
    void SetCoef(const double coef);

    /**
     * @brief Establece el grado del monomio
     * @param deg Grado nuevo
     */
    void SetDegree(const double deg);

    /**
     * @brief Evalúa el monomio
     * @param val Valor en el cual especializar
     * @return coef * (val ^ pow)
     */
    double operator()(const double val);

    Monomio operator-() const;
};

const Monomio operator+(const Monomio &lhs, const Monomio &rhs);
const Monomio operator-(const Monomio &lhs, const Monomio &rhs);
const Monomio operator*(const Monomio &lhs, const Monomio &rhs);
const Monomio operator/(const Monomio &lhs, const Monomio &rhs);

std::ostream &operator<<(std::ostream &s, const Monomio &mon);
}

#endif // MONOMIO_H_INCLUDED
