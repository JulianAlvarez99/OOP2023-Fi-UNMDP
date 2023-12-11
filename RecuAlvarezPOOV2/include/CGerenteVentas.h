#ifndef CGERENTEVENTAS_H
#define CGERENTEVENTAS_H
#include "CVendedor.h"
#include "CAdministrativo.h"
class CGerenteVentas: public CAdministrativo, public CVendedor
{
public:
    CGerenteVentas();
    CGerenteVentas(string name, int doc, CFecha birth);
    virtual ~CGerenteVentas();
    void SetAdmPayment(double);
    double GetAdmPayment();
    friend ostream &operator<<(ostream&,CGerenteVentas&);

protected:

private:
    double AdmPayment;
};

#endif // CGERENTEVENTAS_H
