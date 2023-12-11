#include "cRadio.h"

cRadio::cRadio(const float freq, const TipoDeBanda tipo, const bool status)
{
    this->frecuencia = freq;
    setBanda(tipo);
    setPrendido(status);
}

void cRadio::setPrendido(const bool status)
{
    this->status_radio = status;
}

void cRadio::setBanda(const TipoDeBanda tipo)
{
    this->banda = tipo;
}
