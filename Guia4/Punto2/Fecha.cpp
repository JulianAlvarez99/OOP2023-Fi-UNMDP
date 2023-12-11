#include "Fecha.h"

oop::Fecha::Fecha(int d, int m, int a)
{
    Day = d;
    Month = m;
    Year = a;
}

std::ostream &oop::operator<<(std::ostream &s, const oop::Fecha &f)
{
    return (s << f.Year << "-" << f.Month << "-" << f.Day);
}
