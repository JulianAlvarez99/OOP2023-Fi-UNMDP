#ifndef BANCO_H
#define BANCO_H
#include <string>
#include "cVector.h"
#include "Cuenta.h"

using namespace std;

class Banco
{
public:
    Banco();
    virtual ~Banco();

    long getCuentasActivas();
    long getNroBajas();
    string getIDBanco();
    string getDireccion();
    string getNroSucursal();
    string getContacto();

    void setCuentasActivas(long);
    void setNroBajas(long);

    void Alta_Cuenta(Cuenta*);
    void Baja_Cuenta(long);

protected:

private:
    long _CuentasActivas;
    long _NroBajas;
    string _DireccionSucursal = "Luro 3067";
    string _NroSucursal = "0502";
    string _IDBanco = "014";
    string _Contacto = "2236998542";
    vector _sistema;
};

#endif // BANCO_H
