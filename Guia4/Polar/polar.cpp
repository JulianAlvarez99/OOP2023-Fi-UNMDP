#include "polar.h"
#include <math.h>

polar::polar()
{
    fModulo = 0.0;
    fFase = 0.0;
}

polar::polar(complejo& comp): complejo(comp)
{
    fModulo = CalModulo(comp);
    fFase = CalFase(comp);
 //   c_real = comp.getReal();
 //   c_imag = comp.getImag();
}

polar::polar(float r, float i, bool modo) : complejo(r, i)
{
    if(modo)
    {
        fModulo = r;
        fFase = i;
        ToRect();
    }
    else
    {
        fModulo = CalModulo(*this);
        fFase = CalFase(*this);
    }
}

float polar::GetModulo()
{
    return fModulo;
}

void polar::SetModulo(float valor)
{
    fModulo = valor;
}

float polar::GetFase()
{
    return fFase;
}

void polar::SetFase(float valor)
{
    fFase = valor;
}

float polar::CalModulo(complejo& valor)
{
    fModulo = sqrt(pow(valor.getReal(), 2) + pow(valor.getImag(), 2));

    return fModulo;
}

float polar::CalFase(complejo& valor)
{
    fFase = atan2(valor.getImag(), valor.getReal()) * 180.0 / 3.1415927;

    return fFase;
}

void polar::ToRect()
{
    c_real = fModulo*cos(fFase*3.1415927/180.0);
    c_imag = fModulo*sin(fFase*3.1415927/180.0);
}

void polar::ToPolar()
{
    fModulo = CalModulo(*this);
    fFase = CalFase(*this);
}

polar polar::operator+ (polar& sumando)
{
    polar aux;
    aux.c_real = c_real + sumando.c_real;
    aux.c_imag = c_imag + sumando.c_imag;
    aux.ToPolar();

    return aux;
}
/*
polar polar::operator+= (polar& sumando)
{
    c_real+= sumando.c_real;
    c_imag+= sumando.c_imag;
    this->ToPolar();

    return (*this);
}
*/
polar operator* (double factor, polar& pol)
{
    polar aux(pol);

    aux.fModulo*= factor;
    aux.ToRect();

    return aux;
}

polar polar::operator*= (double factor)
{
    fModulo*= factor;
    ToRect();

    return (*this);
}

double operator* (polar& pol1, polar& pol2)
{
    return (pol1.fModulo * pol2.fModulo * cos((pol1.fFase - pol2.fFase)*3.1415927/180.0) );
}

ostream& operator<< (ostream& co, const polar &pol)
{

    co << pol.fModulo << "/";
    co << pol.fFase << " grados";

    return co;
}

istream& operator>> (istream& co, const polar &pol)
{
    co >> pol.c_real;
    co >> pol.c_imag;

    return pol;
}

