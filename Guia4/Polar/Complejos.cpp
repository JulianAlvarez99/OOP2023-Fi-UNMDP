#include "Complejos.h"

complejo::complejo(double re, double imag)
{
    c_real = re;
    c_imag = imag;
}

void complejo::setReal(double re)
{
    c_real = re;
}
void complejo::setImag(double imag)
{
    c_imag = imag;
}
void complejo::setData(void)
{
    cout<<"Valor de parte real: ";
    cin>>c_real;
    cout<<endl;

    cout<<"Valor de parte imaginaria: ";
    cin>>c_imag;
    cout<<endl;
}
double complejo::getReal()
{
    return(c_real);
}
double complejo::getImag()
{
    return(c_imag);
}

complejo complejo::operator+(const complejo &cmp)
{
    complejo sum;

    sum.c_real = c_real + cmp.c_real;
    sum.c_imag = c_imag + cmp.c_imag;

    return sum;
}

complejo complejo::operator-(const complejo &cmp)
{
    complejo dif;
    dif.c_real = c_real - cmp.c_real;
    dif.c_imag = c_imag - cmp.c_imag;

    return(dif);
}

complejo complejo::operator*(const complejo &cmp)
{
    complejo prod;
    prod.c_real = c_real*cmp.c_real - c_imag*cmp.c_imag;
    prod.c_imag = c_real*cmp.c_imag - c_imag*cmp.c_real;

    return(prod);
}

complejo complejo::operator/(const complejo &cmp)
{
    complejo div;
    double deno;

    deno = cmp.c_real*cmp.c_real + cmp.c_imag*cmp.c_imag;
    div.c_real = (c_real*cmp.c_real + c_imag*cmp.c_imag)/deno;
    div.c_imag = (-c_real*cmp.c_imag + c_imag*cmp.c_real)/deno;

    return div;
}

complejo complejo::operator+= (const complejo &cmp)
{
    c_real += cmp.c_real;
    c_imag += cmp.c_imag;

    return(*this);
}

complejo& complejo::operator++()
{
    c_real++;
    c_imag++;

    return(*this);
}

complejo& complejo::operator++(int nan)
{
    complejo &aux = *this;
    ++(*this);
    return(aux);
}

complejo complejo::operator= (const complejo &cmp)
{
    c_real = cmp.c_real;
    c_imag = cmp.c_imag;

    return(*this);
}

bool operator!= (const complejo &cmp1, const complejo &cmp2)
{
    bool result = false;
    if((cmp1.c_real != cmp2.c_real) || (cmp1.c_imag != cmp2.c_imag))
    {
        result = true;
    }
    return(result);
}

bool complejo::operator== (const complejo &cmp)
{
    bool result = true;

    if((c_real != cmp.c_real) || (c_imag != cmp.c_imag))
    {
        result = false;
    }
    return(result);
}

complejo operator+ (double aux, complejo cmp)
{
    complejo sum;
    sum.c_real = aux + cmp.c_real;
    sum.c_imag = cmp.c_imag;

    return(sum);
}

complejo operator+ (complejo cmp, double aux)
{
    complejo sum;
    sum.c_real = cmp.c_real + aux;
    sum.c_imag = cmp.c_imag;

    return(sum);
}
complejo operator- (double aux, complejo cmp)
{
    complejo dif;
    dif.c_real = aux - cmp.c_real;
    dif.c_imag = cmp.c_imag;

    return(dif);
}
complejo operator- (complejo cmp, double aux)
{
    complejo dif;
    dif.c_real = cmp.c_real - aux;
    dif.c_imag = cmp.c_imag;

    return(dif);
}

complejo operator* (double aux, complejo cmp)
{
    complejo prod;
    prod.c_real = aux*cmp.c_real;
    prod.c_imag = aux*cmp.c_imag;

    return(prod);
}
complejo operator* (complejo cmp, double aux)
{
    complejo prod;
    prod.c_real = cmp.c_real*aux;
    prod.c_imag = cmp.c_imag*aux;

    return(prod);
}
complejo operator/ (double aux, complejo cmp)
{
    complejo div;
    double deno;

    deno = cmp.c_real*cmp.c_real + cmp.c_imag*cmp.c_imag;
    div.c_real = (aux*cmp.c_real)/deno;
    div.c_imag = (-aux*cmp.c_imag)/deno;

    return div;
}
complejo operator/ (complejo cmp, double aux)
{
    complejo div;
    div.c_real = cmp.c_real/aux;
    div.c_imag = cmp.c_imag/aux;

    return(div);
}
// Sobrecarga del operador de inserción en el stream de salida
ostream& operator<< (ostream& co, const complejo &cmp)
{
    ios_base::fmtflags fl;
    //int fl;

    co << cmp.c_real;
    fl = co.setf(ios::showpos);
    co << cmp.c_imag << "i";
    co.flags(fl);

    return co;
}
