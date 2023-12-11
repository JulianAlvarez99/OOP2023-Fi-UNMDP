#include "cTime.h"

cTime::cTime(const unsigned int h, const unsigned int m, const unsigned int s)
{
    setTiempo(h,m,s);
}

void cTime::setTiempo(const unsigned int h, const unsigned int m, const unsigned int s)
{
    this->hora = h;
    this->minuto = m;
    this->segundo = s;
}
cTime cTime::getTiempo() const
{
    return(cTime(*this));
}

void cTime::incrementarTiempo(const unsigned int m)
{
    setTiempo(this->hora, this->minuto + m, this->segundo);
}

ostream& operator<<(ostream &salida, const cTime &tiempo)
{
    return(salida<<tiempo.hora<<":"<<tiempo.minuto<<":"<<tiempo.segundo<<endl);
}
