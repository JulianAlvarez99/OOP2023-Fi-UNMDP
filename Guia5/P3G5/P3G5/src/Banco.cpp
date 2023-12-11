#include "Banco.h"

Banco::Banco()
{
}

Banco::~Banco()
{
    //dtor
}

long Banco::getCuentasActivas()
{
    return(this->_CuentasActivas);
}
long Banco::getNroBajas()
{
    return(this->_NroBajas);
}
string Banco::getDireccion()
{
    return(this->_DireccionSucursal);
}
string Banco::getNroSucursal()
{
    return(this->_NroSucursal);
}
string Banco::getIDBanco()
{
    return(this->_IDBanco);
}
string Banco::getContacto()
{
    return(this->_Contacto);
}

void Banco::setCuentasActivas(long altas)
{
    this->_CuentasActivas = altas;
}
void Banco::setNroBajas(long bajas)
{
    this->_NroBajas = bajas;
}

void Banco::Alta_Cuenta(Cuenta* _New_Cuenta)
{
    if(_sistema.full() != true)
    {
        _sistema.push_back(_New_Cuenta);
    }
    else
    {
        _sistema.reserve(_sistema.capacity() + 1);
        _sistema.push_back(_New_Cuenta);
    }
    this->_CuentasActivas++;
}
void Banco::Baja_Cuenta(long nroCuenta)
{
    _sistema[getCuentasActivas()-1]->setCuenta(_sistema[nroCuenta-1]->getCuenta());
    _sistema[getCuentasActivas()-1]->setCBU(_sistema[nroCuenta-1]->getCBU());

    _sistema.erase(nroCuenta-1);
    this->_NroBajas++;
    this->_CuentasActivas--;
}
