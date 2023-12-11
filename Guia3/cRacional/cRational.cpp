#include "cRational.h"
#include <algorithm>
#include <numeric>

oop::CRacional::CRacional(const int num, const int den)
{
    num_ = num;
    den_ = den != 0 ? den : 1;
    Simplify_();
}

int oop::CRacional::GetNumerator() const
{
    return num_;
}

int oop::CRacional::GetDenominator() const
{
    return den_;
}

void oop::CRacional::SetNumerator(int num)
{
    num_ = num;
    Simplify_();
}

void oop::CRacional::SetDenominator(int den)
{
    if (den != 0)
    {
        den_ = den;
        Simplify_();
    }
}

std::ostream &operator<<(std::ostream &s, const oop::CRacional &r)
{
    return s << r.GetNumerator() << "/" << r.GetDenominator();
}

std::istream &operator>>(std::istream &s, oop::CRacional &r)
{
    int num, den;
    s >> num;
    s >> den;
    r.SetNumerator(num);
    r.SetDenominator(den);
    return s;
}

const oop::CRacional operator+(const oop::CRacional &lhs,
                               const oop::CRacional &rhs)
{
    int num(lhs.GetNumerator() * rhs.GetDenominator() +
            lhs.GetDenominator() * rhs.GetNumerator()),
                               den(lhs.GetDenominator() * rhs.GetDenominator());
    return oop::CRacional(num, den);
}

oop::CRacional oop::CRacional::operator-() const
{
    return oop::CRacional(-GetNumerator(), GetDenominator());
}

const oop::CRacional operator-(const oop::CRacional &lhs,
                               const oop::CRacional &rhs)
{
    return lhs + (-rhs);
}

oop::CRacional &oop::CRacional::operator+=(const CRacional &rhs)
{
    return (*this = *this + rhs);
}

void oop::CRacional::Simplify_()
{
    int gcd(std::__gcd(num_, den_)); //maximo comun denominador

    if (gcd != 1)
    {
        num_ = int(num_ / gcd);
        den_ = int(den_ / gcd);
    }
}

bool oop::CRacional::operator==(const oop::CRacional &rhs) const
{
    /* Funciona porque las fracciones se simplifican con llamados al
     * constructor, a SetNumerator y a SetDenominator */
    return (num_ == rhs.num_ && den_ == rhs.den_);
}

bool oop::CRacional::operator>=(const oop::CRacional &rhs) const
{
    /*
    Para >=

    a/b >= c/d

    a/b - c/d >= 0

    (ad - cb) / bd >= 0

    ad - cb >= 0 && bd > 0 || ad - cb <= 0 && bd < 0

    */
    int a(num_), b(den_), c(rhs.GetNumerator()), d(rhs.GetDenominator()),
        f1(a * d - c * b), f2(b * d);

    return ((f1 >= 0 && f2 > 0) || (f1 <= 0 && f2 < 0));
}

bool oop::CRacional::operator<=(const oop::CRacional &rhs) const
{
    /* <=
    ad - cb <= 0 && bd > 0 || ad - cb >= 0 && bd < 0
    */
    int a(num_), b(den_), c(rhs.GetNumerator()), d(rhs.GetDenominator()),
        f1(a * d - c * b), f2(b * d);

    return ((f1 <= 0 && f2 > 0) || (f1 >= 0 && f2 < 0));
}

bool oop::CRacional::operator>(const oop::CRacional &rhs) const
{
    int a(num_), b(den_), c(rhs.GetNumerator()), d(rhs.GetDenominator()),
        f1(a * d - c * b), f2(b * d);

    return ((f1 > 0 && f2 > 0) || (f1 < 0 && f2 < 0));
}

bool oop::CRacional::operator<(const oop::CRacional &rhs) const
{
    int a(num_), b(den_), c(rhs.GetNumerator()), d(rhs.GetDenominator()),
        f1(a * d - c * b), f2(b * d);

    return ((f1 < 0 && f2 > 0) || (f1 > 0 && f2 < 0));
}

bool oop::CRacional::operator!() const
{
    return num_ != 0;
}

oop::CRacional &oop::CRacional::operator++()
{
    num_ += den_;
    return *this;
}

oop::CRacional oop::CRacional::operator++(int dummy)
{
    oop::CRacional backup(*this);
    num_ += den_;
    return backup;
}

oop::CRacional &oop::CRacional::operator--()
{
    num_ -= den_;
    return *this;
}

oop::CRacional oop::CRacional::operator--(int dummy)
{
    oop::CRacional backup(*this);
    num_ -= den_;
    return backup;
}

const oop::CRacional operator*(const oop::CRacional &lhs,
                               const oop::CRacional &rhs)
{
    /*
    a/b * c/d = ac / bd
    */
    return oop::CRacional(lhs.GetNumerator() * rhs.GetNumerator(),
                          lhs.GetDenominator() * rhs.GetDenominator());
}

oop::CRacional &oop::CRacional::Invert()
{
    std::swap(num_, den_);
    Simplify_();
    return *this;
}

const oop::CRacional operator/(const oop::CRacional &lhs,
                               const oop::CRacional &rhs)
{
    return oop::CRacional(lhs.GetNumerator() * rhs.GetDenominator(),
                          lhs.GetDenominator() * rhs.GetNumerator());
}

oop::CRacional::operator double()
{
    return double(num_) / double(den_);
}

const oop::CRacional operator+(const double &lhs, const oop::CRacional &rhs)
{
    int den = rhs.GetDenominator();
    return oop::CRacional(int(lhs) * den + rhs.GetNumerator(), den);
}
