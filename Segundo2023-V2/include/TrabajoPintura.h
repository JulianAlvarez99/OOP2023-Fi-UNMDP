#ifndef TRABAJOPINTURA_H
#define TRABAJOPINTURA_H
#include "Servicio.h"

class TrabajoPintura : virtual public Servicio
{
public:
    TrabajoPintura(double sup = 0.0, double precio = 0.0);
    virtual ~TrabajoPintura();

    void SetSuperficie(double);
    void SetPrecioPintura(double);
    double GetSuperficie();
    double GetPrecioPintura();

    double costoMaterial();
    double costoManoObra();
    double costoTotal();
    void detalleServicio(ostream& os = cout);
protected:

private:
    double Superficie;
    double PrecioPintura;
};

#endif // TRABAJOPINTURA_H
