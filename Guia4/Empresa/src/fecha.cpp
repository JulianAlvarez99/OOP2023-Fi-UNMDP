#include "fecha.h"

fecha::fecha(const int dia, const int mes , const int anio)
{
    this->day_ = dia;
    this->month_ = mes;
    this->year_ = anio;
}

fecha::~fecha()
{
    //dtor
}

ostream &operator<<(ostream &s, const fecha &f)
{
    return (s << f.day_<< "/" << f.month_<< "/" << f.year_);
}
