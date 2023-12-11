#include "Servicio.h"

Servicio::Servicio()
{
    //ctor
}

Servicio::~Servicio()
{
    //dtor
}
CFecha& Servicio::GetInicioServicio()
{
    return(this->InicioServicio);
}
CPersona& Servicio::GetCliente()
{
    return(this->Cliente);
}
CPersona& Servicio::GetTrabajador()
{
    return(this->Trabajador);
}
