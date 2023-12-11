#ifndef CUENTA_H
#define CUENTA_H
#include <iostream>
#include <iomanip>
#include "Cliente.h"

using namespace std;

class Cuenta
{
public:
    Cuenta(string _Sucursal, string _IDBanco,
           Cliente _Client,long _CuentasActual = 0, double _money = 0.0); /**Tengo que pasar como parametro un objeto tipo Cliente***/
    virtual ~Cuenta();

    void setSaldo(double);
    void setCuenta(long);
    void setCBU(string);
    long getCuenta();
    string getCBU();
    double getSaldo();

    virtual double extraccion(double _Money);
    virtual void deposito(double _Money);
    virtual void printCuenta();
    virtual Cuenta* Clonar();

protected:

    Cliente _Titular;
    long  _NroCuenta;
    string _Cbu;
    double _Saldo;

private:
};

string CBU_Generator(string _Sucursal, string _IDBanco ,long _CuentasActual);

#endif // CUENTA_H
