#ifndef CRATIONAL_H_INCLUDED
#define CRATIONAL_H_INCLUDED

#include <iostream>

namespace oop
{
class CRacional
{
private:
    int num_;
    int den_;
    void Simplify_();

public:
    explicit CRacional(const int num = 0, const int den = 1);

    int GetNumerator() const;
    int GetDenominator() const;
    void SetNumerator(int num);
    void SetDenominator(int den);
    CRacional &Invert(void);

    CRacional operator-(void) const;

    CRacional &operator+=(const CRacional &rhs);
    bool operator==(const CRacional &rhs) const;
    bool operator>=(const CRacional &rhs) const;
    bool operator<=(const CRacional &rhs) const;
    bool operator>(const CRacional &rhs) const;
    bool operator<(const CRacional &rhs) const;
    bool operator!(void) const;
    CRacional &operator++();
    CRacional operator++(int dummy);
    CRacional &operator--();
    CRacional operator--(int dummy);

    operator double();
};
}

std::ostream &operator<<(std::ostream &s, const oop::CRacional &r);
std::istream &operator>>(std::istream &s, oop::CRacional &r);
const oop::CRacional operator+(const oop::CRacional &lhs,
                               const oop::CRacional &rhs);
const oop::CRacional operator-(const oop::CRacional &lhs,
                               const oop::CRacional &rhs);
const oop::CRacional operator*(const oop::CRacional &lhs,
                               const oop::CRacional &rhs);
const oop::CRacional operator/(const oop::CRacional &lhs,
                               const oop::CRacional &rhs);
const oop::CRacional operator+(const double &lhs, const oop::CRacional &rhs);

#endif // CRATIONAL_H_INCLUDED
