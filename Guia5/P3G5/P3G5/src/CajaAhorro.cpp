#include "CajaAhorro.h"

CajaAhorro::CajaAhorro(string _Sucursal, string _IDBanco, Cliente _Client,long _CuentasActual, double _money, int _Extracciones, int _Mes)
    :Cuenta(_Sucursal,_IDBanco,_Client,_CuentasActual,_money)
{
    this->_CantExtracciones = _Extracciones;
    this->_ultMes = _Mes;
    ResetCantExtracciones();
}

Cuenta* CajaAhorro::Clonar()
{
    return (new CajaAhorro(*this));
}

CajaAhorro::~CajaAhorro()
{
    //dtor
}

int CajaAhorro::getCantExtracciones()
{
    return(_CantExtracciones);
}

void CajaAhorro::ResetCantExtracciones()
{
    time_t currentTime;
    struct tm* timeInfo;
    time(&currentTime);
    timeInfo = localtime(&currentTime);

    int _mesActual = timeInfo->tm_mon; // Obtener el mes actual

    // Comprobar si ha habido un cambio de mes en las últimas 24 horas
    if (_mesActual != _ultMes)
    {
        this->_CantExtracciones = 30;// Restablecer el atributo con la fecha actual
        this->_ultMes = _mesActual;// Actualizar el registro del último mes
    }
}

double CajaAhorro::extraccion(double _monto)
{
    double _extraido = 0;

    if (this->_Saldo - _monto >= 0)
    {
        _extraido  = Cuenta::extraccion(_monto);
        this->_CantExtracciones++;
    }

    return _extraido ;
}
