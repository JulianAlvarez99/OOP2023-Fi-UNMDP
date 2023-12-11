#include "cReloj.h"
#include "cTime.h"

cReloj::cReloj(const unsigned int hora,const unsigned int minuto,const unsigned int segundo) //constructor por defecto
{
    setTiempo(hora,minuto,segundo);
    setMarca("");
}

cReloj::cReloj(const cTime &original) // constructor de copia
{
    time = original;
}

void cReloj::setTiempo(const unsigned int hora,const unsigned int minuto,const unsigned int segundo)
{
    this->time = cTime(hora,minuto,segundo);
}

void cReloj::setMarca(const char *nueva_marca)
{
    this->marca = const_cast<char*>(nueva_marca); //Necesito modificar el valor sin cambiar el modificador
}

cTime cReloj::getTiempo() const
{
    return(time.getTiempo());
}
