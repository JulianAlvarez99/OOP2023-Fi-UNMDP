#ifndef REVISIONALARMA_H
#define REVISIONALARMA_H
#include "Servicio.h"

class RevisionAlarma: virtual public Servicio
{
public:
    RevisionAlarma(string nombre = "Revisor Especialista Contraincendios",
                   CFecha fecha = CFecha(02,05,2013), int id=1001);
    virtual ~RevisionAlarma();

    int GetCantAlarmas();
    void SetCantAlarmas(int);

    double costoMaterial();
    double costoManoObra();
    double costoTotal();
    void detalleServicio(ostream& os = cout);

protected:

private:
    int CantAlarmas;
};

#endif // REVISIONALARMA_H
