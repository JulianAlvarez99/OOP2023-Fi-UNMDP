#ifndef CRADIO_H_INCLUDED
#define CRADIO_H_INCLUDED
#include <iostream>
using namespace std;

enum TipoDeBanda
{
    AM,
    FM
};

class cRadio
{
private:
    float frecuencia;
    TipoDeBanda banda;
    bool status_radio;
public:
// todos los métodos necesarios
cRadio(const float freq = 95.5, const TipoDeBanda tipo = FM, const bool status = false);
void setPrendido(const bool status);
void setBanda(const TipoDeBanda tipo);
};

#endif // CRADIO_H_INCLUDED
