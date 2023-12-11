#ifndef POLINOMIO_H_INCLUDED
#define POLINOMIO_H_INCLUDED

#include <fstream>
#include "Monomio.h"

namespace oop
{
class Polinomio
{
private:
    Monomio *Monomios_;  ///< Sería mejor usar shared_ptr
    int CantMonomios_;

public:
    // Polinomio();
    Polinomio(const int deg = 0, const double coefs[] = nullptr);
    Polinomio(const Polinomio &pol);
    ~Polinomio();

    double operator()(const double val);
    Polinomio &operator=(const Polinomio &pol) = default;
    friend Polinomio operator+(const Polinomio &lhs, const Polinomio &rhs);
    friend std::ofstream &operator<<(std::ofstream &s,
                                     const Polinomio &pol);
    friend std::ifstream &operator>>(std::ifstream &s, Polinomio &pol);
    friend std::ostream &operator<<(std::ostream &s, const Polinomio &pol);
};

Polinomio operator+(const Polinomio &lhs, const Polinomio &rhs);
std::ofstream &operator<<(std::ofstream &s, const Polinomio &pol);
std::ifstream &operator>>(std::ifstream &s, Polinomio &pol);
std::ostream &operator<<(std::ostream &s, const Polinomio &pol);
}

#endif // POLINOMIO_H_INCLUDED
