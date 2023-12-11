#ifndef CUENTAUNIVERSITARIA_H
#define CUENTAUNIVERSITARIA_H

#include <Cuenta.h>


class CuentaUniversitaria :  public Cuenta
{
    public:
        CuentaUniversitaria(string _Sucursal, string _IDBanco, Cliente _Client,
                        long _CuentasActual = 0, double _money = 0.0, int _topeDiario = 0, int _ultDia = 0, int _ultMes = 0);
        virtual ~CuentaUniversitaria();
        virtual Cuenta* Clonar();

        virtual double extraccion(double _money);

    protected:

    private:
        void ResetCantExtracciones();
        int _topeDiario;
        int _ultMes;
        int _ultDia;
};

#endif // CUENTAUNIVERSITARIA_H
