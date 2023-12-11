#include "CuentaCorriente.h"

CuentaCorriente::CuentaCorriente(string _Sucursal, string _IDBanco,Cliente _Client,long _CuentasActual, double _money, double tope)
    :Cuenta(_Sucursal,_IDBanco,_Client,_CuentasActual,_money)
{
        this->_tope = tope;//ctor
}

Cuenta* CuentaCorriente::Clonar()
{
    return (new CuentaCorriente(*this));
}

CuentaCorriente::~CuentaCorriente()
{
    //dtor
}

double CuentaCorriente::extraccion(double _monto)
{
    double extraccion = 0;

    if (_Saldo - _monto >= _tope)
    {
        extraccion = Cuenta::extraccion(_monto);
    }

    return extraccion;
}
