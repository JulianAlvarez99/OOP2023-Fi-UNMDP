#include <iostream>
#include "cRadioReloj.h"

using namespace std;

cRadioReloj::cRadioReloj(const cTime &reloj, const cTime &alarm, const TipoAlarma type, const bool status,const cRadio &rad)
:cRadio(rad)
{
    this->time = reloj;
    this->alarma = alarm;
    this->tipo = type;
    this->status_alarma = status;
}

void cRadioReloj::setPrendido(const bool status)
{
    this->status_alarma = status;
}
void cRadioReloj::setAlarma(const unsigned int hora, const unsigned int minuto, const unsigned int segundo)
{
    this->alarma = cTime(hora,minuto,segundo);
}
void cRadioReloj::incrementarTiempo()
{
    alarma.incrementarTiempo(15);
}
bool cRadioReloj::verificarAlarma()
{
    return status_alarma;
}
