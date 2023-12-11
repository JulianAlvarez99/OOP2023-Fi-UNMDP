#ifndef CRADIORELOJ_H_INCLUDED
#define CRADIORELOJ_H_INCLUDED
#include "cRadio.h"
#include "cReloj.h"

enum TipoAlarma
{
    Musica,
    Timbre
};

class cRadioReloj: public cRadio, public cReloj
{
private:
    cTime alarma;
    TipoAlarma tipo;
    bool status_alarma;
public:
// todos los métodos necesarios
cRadioReloj(const cTime &reloj, const cTime &alarma = cTime(),
            const TipoAlarma tipo = Timbre, const bool status = false,
            const cRadio &freq = cRadio(100.1,FM,false));
void setPrendido(const bool status_alarma);
void setAlarma(const unsigned int hora = 0,
               const unsigned int minuto = 0,
               const unsigned int segundo = 0);
void incrementarTiempo();
bool verificarAlarma();

};

#endif // CRADIORELOJ_H_INCLUDED
