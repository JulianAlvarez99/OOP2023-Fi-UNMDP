#ifndef CUENTACORRIENTE_H
#define CUENTACORRIENTE_H

#include <Cuenta.h>


class CuentaCorriente : public Cuenta
{
    public:
        CuentaCorriente(string _Sucursal, string _IDBanco, Cliente _Client,
                        long _CuentasActual = 0, double _money = 0.0, double tope = 0.0);
        virtual ~CuentaCorriente();
        virtual Cuenta* Clonar();

        virtual double extraccion(double _money);

    protected:

    private:
        double _tope;

};

#endif // CUENTACORRIENTE_H
