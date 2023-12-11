#include "CuentaUniversitaria.h"

CuentaUniversitaria::CuentaUniversitaria(string _Sucursal, string _IDBanco, Cliente _Client,long _CuentasActual, double _money, int _tope, int _dia, int _mes)
    :Cuenta(_Sucursal,_IDBanco,_Client,_CuentasActual,_money)
{
   this->_topeDiario = _tope;
   this->_ultDia = _dia;
   this->_ultMes = _mes;
   ResetCantExtracciones();
}

Cuenta* CuentaUniversitaria::Clonar()
{
    return (new CuentaUniversitaria(*this));
}

CuentaUniversitaria::~CuentaUniversitaria()
{
    //dtor
}

void CuentaUniversitaria::ResetCantExtracciones()
{
    time_t currentTime;
    struct tm* timeInfo;
    time(&currentTime);
    timeInfo = localtime(&currentTime);

    int _diaActual = timeInfo->tm_mday;
    int _mesActual = timeInfo->tm_mon;// Obtener el mes actual

    // Comprobar si ha habido un cambio de mes en las últimas 24 horas
    if (_diaActual != _ultDia || _mesActual != _ultMes)
    {
        this->_topeDiario = 100;// Restablecer el atributo con la fecha actual
        this->_ultDia = _diaActual;
        this->_ultMes = _mesActual;// Actualizar el registro del último mes
    }
}

double CuentaUniversitaria::extraccion(double _monto)
{
    double _extraido = 0;

    if (_monto <= _topeDiario)
    {
        _extraido  = Cuenta::extraccion(_monto);
        this->_topeDiario -= _monto;
    }

    return _extraido ;
}
