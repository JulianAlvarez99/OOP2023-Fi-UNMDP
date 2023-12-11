#ifndef CRELOJ_H_INCLUDED
#define CRELOJ_H_INCLUDED
#include "cTime.h"


class cReloj
{
protected:
    cTime time;
    char *marca;

public:
// todos los métodos necesarios
cReloj(const unsigned int hora = 0,const unsigned int minuto = 0,const unsigned int segundo = 0); //constructor por defecto
cReloj(const cTime &original); //Se crea este constructor de copia para copiar otro reloj
void setTiempo(const unsigned int hora,const unsigned int minuto,const unsigned int segundo);
void setMarca(const char *nueva_marca);
cTime getTiempo() const;
};

#endif // CRELOJ_H_INCLUDED
