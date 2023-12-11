#ifndef CPANTALLA_H
#define CPANTALLA_H
#include "CMatriz.h"
#include <iostream>

class CPantalla : public CMatriz
{
public:
    CPantalla(const CMatriz &original);

    void ajustarColor(unsigned int _modAlpha);
    void borrarVerde();
    void reforzarRojo(float _porcentajeRojo);
    friend ostream& operator<< (ostream&, const CPantalla&);

protected:

private:
};

#endif // CPANTALLA_H
