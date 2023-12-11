#include "Cuenta.h"

Cuenta::Cuenta(string _Sucursal, string _IDBanco ,Cliente _Client,long _CuentasActual, double _Dinero)
{
    this->_Titular = Cliente(_Client);
    this->_NroCuenta = _CuentasActual + 1;
    this->_Cbu = CBU_Generator(_Sucursal,_IDBanco,_NroCuenta);
    this->_Saldo = _Dinero;
}

Cuenta* Cuenta::Clonar()
{
    return (new Cuenta(*this));
}

Cuenta::~Cuenta()
{
    //dtor
}

string CBU_Generator(string _Sucursal, string _IDBanco ,long _NroAccount)
{
    srand(time(NULL));
    int _control1 = rand() % 10;
    srand(time(NULL)+rand());
    int _control2 = rand() % 10;

    string _NroCuentaStr = to_string(_NroAccount);

     while (_NroCuentaStr.length() < 13)
    {
        _NroCuentaStr = "0" + _NroCuentaStr;
    }

    string _strCbu = _IDBanco + _Sucursal + to_string(_control1) + _NroCuentaStr + to_string(_control2);
    return(_strCbu);
}

void Cuenta::setSaldo(double _Money)
{
    this->_Saldo = _Money;
}
void Cuenta::setCuenta(long _Account)
{
    this->_NroCuenta = _Account;
}
void Cuenta::setCBU(string _Cebeu)
{
    this->_Cbu = _Cebeu;
}

double Cuenta::getSaldo()
{
    return(this->_Saldo);
}

long Cuenta::getCuenta()
{
    return(this->_NroCuenta);
}
string Cuenta::getCBU()
{
    return(this->_Cbu);
}

double Cuenta::extraccion(double _monto)
{
    _Saldo -= _monto;
    cout<<"Se realizo la extraccion de $"<< _monto << " de la cuenta nro: "<< this->_NroCuenta<<endl
        <<"Saldo: "<< this->_Saldo <<endl;
    Mostrar_TiempoFecha();
    cout<<endl<<endl;

    return _monto;
}

void Cuenta::deposito(double _monto)
{
    setSaldo(getSaldo()+_monto);
    cout<<"Se realizo el deposito de $"<< _monto << " en la cuenta nro: "<< this->_NroCuenta << endl
        <<"Saldo: "<< this->_Saldo <<endl;
    Mostrar_TiempoFecha();
    cout<<endl<<endl;
}

void Cuenta::printCuenta()
{
    cout<<"======================================================================================================"<<endl;
    cout<<"Nro de Cuenta: "<<getCuenta()
        <<"\t\tTitular: "<<this->_Titular.GetName()
        <<"\t DNI: "<<this->_Titular.GetDocument()<<endl
        <<"CBU: "<<getCBU()<<endl
        <<"Saldo disponible: "<<getSaldo()<<endl;
        cout<<endl<<endl;
}


