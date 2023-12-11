#ifndef CAJAAHORRO_H
#define CAJAAHORRO_H
#include <Cuenta.h>


class CajaAhorro :  public Cuenta
{
    public:
        CajaAhorro(string _Sucursal, string _IDBanco, Cliente _Client,
                        long _CuentasActual = 0, double _money = 0.0, int _Extracciones = 0, int _Mes = 0);
        virtual ~CajaAhorro();
        virtual Cuenta* Clonar();

        int getCantExtracciones();
        virtual double extraccion(double _money);

    protected:

    private:
        int _CantExtracciones;
        int _ultMes;
        void ResetCantExtracciones();
};

#endif // CAJAAHORRO_H
