#include "Monomio.h"
#include <cmath>
#include <iomanip>

oop::Monomio::Monomio(const double coef)
{
    *this = Monomio(coef, 0);
}

oop::Monomio::Monomio(const double coef, const double deg)
{
    Coef_ = coef;
    Degree_ = deg;
}

double oop::Monomio::GetCoef() const
{
    return Coef_;
}

double oop::Monomio::GetDegree() const
{
    return Degree_;
}

void oop::Monomio::SetCoef(const double coef)
{
    Coef_ = coef;
}

void oop::Monomio::SetDegree(const double deg)
{
    Degree_ = deg;
}

double oop::Monomio::operator()(const double val)
{
    return Coef_ * std::pow(val, Degree_);
}

oop::Monomio oop::Monomio::operator-() const
{
    return Monomio(-Coef_, Degree_);
}

const oop::Monomio oop::operator+(const oop::Monomio &lhs,
                                  const oop::Monomio &rhs)
{
    double deg_l = lhs.GetDegree();
    Monomio result;

    if (deg_l == rhs.GetDegree())
    {
        result.SetCoef(lhs.GetCoef() + rhs.GetCoef());
        result.SetDegree(deg_l);
    }

    return result;
}

const oop::Monomio oop::operator-(const Monomio &lhs, const Monomio &rhs)
{
    return lhs + (-rhs);
}

const oop::Monomio oop::operator*(const Monomio &lhs, const Monomio &rhs)
{
    return Monomio(lhs.GetCoef() * rhs.GetCoef(),
                   lhs.GetDegree() + rhs.GetDegree());
}

const oop::Monomio oop::operator/(const Monomio &lhs, const Monomio &rhs)
{
    return Monomio(lhs.GetCoef() / rhs.GetCoef(),
                   lhs.GetDegree() - rhs.GetDegree());
}

std::ostream &oop::operator<<(std::ostream &s, const Monomio &mon)
{
    double coef = mon.GetCoef(), deg = mon.GetDegree();

    if (coef != 0)
    {
        s << (coef > 0 ? "+" : "") << coef;

        if (deg == 1)
        {
            s << "x";
        }
        else if (deg != 0)
        {
            s << "x^" << deg;
        }
    }

    return s;
}
