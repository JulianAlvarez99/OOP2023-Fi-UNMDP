#include "Polinomio.h"
#include <cmath>
#include <cstring>
#include <iostream>

/* oop::Polinomio::Polinomio()
{
    double coefs[] = {0};
    *this = Polinomio(0, coefs);
} */

oop::Polinomio::Polinomio(const int deg, const double coefs[])
{
    bool dynamic_memory{coefs == nullptr};

    /* Sanity check. +1 para tener en cuenta el término constante */
    CantMonomios_ = deg > 0 ? deg + 1 : 1;

    if (dynamic_memory)
    {
        coefs = static_cast<const double *>(calloc(1, sizeof(int)));
    }

    /* Asigno memoria */
    Monomios_ = new Monomio[static_cast<unsigned long long>(CantMonomios_)];

    /* Establezco los coeficientes y el grado de cada monomio */
    for (int i = 0; i < CantMonomios_; i++)
    {
        Monomios_[i].SetCoef(coefs[i]);
        Monomios_[i].SetDegree(CantMonomios_ - i - 1);
    }

    if (dynamic_memory)
    {
        free(const_cast<double *>(coefs));
    }
}

oop::Polinomio::~Polinomio()
{
    /* Libero la memoria asignada al array de monomios */
    delete[] Monomios_;
    std::cout << "~Polinomio" << std::endl;
}

double oop::Polinomio::operator()(const double val)
{
    double result = 0;

    for (int i = 0; i < CantMonomios_; i++)
    {
        result += Monomios_[i](val);
    }

    return result;
}

oop::Polinomio::Polinomio(const Polinomio &pol)
{
    size_t cant = static_cast<size_t>(pol.CantMonomios_);

    Monomios_ = static_cast<Monomio *>(malloc(cant * sizeof(Monomio)));
    memcpy(Monomios_, pol.Monomios_, cant * sizeof(Monomio));
    CantMonomios_ = pol.CantMonomios_;
}

oop::Polinomio oop::operator+(const Polinomio &lhs, const Polinomio &rhs)
{
    if (lhs.CantMonomios_ >= rhs.CantMonomios_)
    {
        Polinomio result(lhs);
        int start = lhs.CantMonomios_ - rhs.CantMonomios_;

        for (int i = start; i < lhs.CantMonomios_; i++)
        {
            result.Monomios_[i] = lhs.Monomios_[i] + rhs.Monomios_[i - start];
        }

        return result;
    }
    else
    {
        return rhs + lhs;
    }
}

std::ofstream &oop::operator<<(std::ofstream &s, const Polinomio &pol)
{
    if (s.is_open())
    {
        /* Escribo la cantidad de monomios primero */
        s.write(reinterpret_cast<const char *>(&pol.CantMonomios_),
                sizeof(int));

        /* Escribo el contenido de la matriz de monomios */
        for (int i = 0; i < pol.CantMonomios_; i++)
        {
            s.write(reinterpret_cast<const char *>(&pol.Monomios_[i]),
                    sizeof(Monomio));
        }
    }

    return s;
}

std::ifstream &oop::operator>>(std::ifstream &s, Polinomio &pol)
{
    if (s.is_open())
    {
        /* Leo la cantidad de monomios */
        s.read(reinterpret_cast<char *>(&pol.CantMonomios_), sizeof(int));

        /* Libero la memoria asignada al array de monomios actual, y
        creo un nuevo array de monomios */
        delete[] pol.Monomios_;
        size_t total_bytes{pol.CantMonomios_ * sizeof(Monomio)};
        pol.Monomios_ = static_cast<Monomio *>(malloc(total_bytes));

        /* Escribo todos los monomios en memoria */
        s.read(reinterpret_cast<char *>(pol.Monomios_), total_bytes);
    }

    return s;
}

std::ostream &oop::operator<<(std::ostream &s, const Polinomio &pol)
{
    for (int i = 0; i < pol.CantMonomios_; i++)
    {
        s << pol.Monomios_[i] << " ";
    }

    return s;
}
