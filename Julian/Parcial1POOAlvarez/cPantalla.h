#ifndef CPANTALLA_H_INCLUDED
#define CPANTALLA_H_INCLUDED
#include "cMatriz.h"
#include <iostream>

class CPantalla : public CMatriz
{
private:
protected:
public:
    CPantalla(const CMatriz &original);

    void ajustarColor(unsigned int _modAlpha);
    void borrarVerde();
    void reforzarRojo(float _porcentajeRojo);
    unsigned int* getPtr();
};

#endif // CPANTALLA_H_INCLUDED
