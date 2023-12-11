#ifndef COMPLEJOS_H_INCLUDED
#define COMPLEJOS_H_INCLUDED
#include <iostream>
using namespace std;

class complejo
{
private:
protected:
    double c_real;
    double c_imag;
public:

    complejo(double re=0, double img=0);

    void setReal(double);
    void setImag(double);
    void setData(void);

    double getReal();
    double getImag();

    complejo operator+(const complejo&);
    complejo operator-(const complejo&);
    complejo operator*(const complejo&);
    complejo operator/(const complejo&);

    complejo operator+= (const complejo&);

    complejo& operator++();
    complejo& operator++(int);

    // Sobrecarga del operador de asignación
    complejo operator= (const complejo&);      // retorna una referencia para poder hacer a = b = c

    // Sobrecarga de operadores de comparación

    friend bool operator!= (const complejo&, const complejo&);   // mas amigable al utilizar 2 operandos en la comparacion
    bool operator== (const complejo&);           // sin utilizar el modificador friend
    friend complejo operator+ (double, complejo);
    friend complejo operator+ (complejo, double);
    friend complejo operator- (double, complejo);
    friend complejo operator- (complejo, double);
    friend complejo operator* (double, complejo);
    friend complejo operator* (complejo, double);
    friend complejo operator/ (double, complejo);
    friend complejo operator/ (complejo, double);

    // Sobrecarga del operador de inserción en el stream de salida
    friend ostream& operator<< (ostream&, const complejo&);
};

#endif // COMPLEJOS_H_INCLUDED
