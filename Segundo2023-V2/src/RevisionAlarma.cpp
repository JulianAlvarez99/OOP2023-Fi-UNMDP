#include "RevisionAlarma.h"

RevisionAlarma::RevisionAlarma(string nombre, CFecha fecha,int id)
{
 this->Trabajador.SetBirthDate(fecha);
 this->Trabajador.SetName(nombre);
 this->Trabajador.SetDocument(id);
}

RevisionAlarma::~RevisionAlarma()
{
    //dtor
}

int RevisionAlarma::GetCantAlarmas()
{
    return(this->CantAlarmas);
}
void RevisionAlarma::SetCantAlarmas(int alarmas)
{
    this->CantAlarmas = alarmas;
}

double RevisionAlarma::costoMaterial()
{
    return 500.0;
}
double RevisionAlarma::costoManoObra()
{
    double Valor = 0.0;

    Valor = ((this->CantAlarmas)/3.0)*40;
    return Valor;
}
double RevisionAlarma::costoTotal()
{
    return(this->costoManoObra()+this->costoMaterial());
}
void RevisionAlarma::detalleServicio(ostream& os)
{
     os<<"REVISION PERIODICA ALARMAS CONTRA INCENDIOS"<<endl;
     os<<"    Cliente: "<<this->Cliente.GetName()
     <<"\n    Fecha de revision: "<<this->InicioServicio
     <<"\n    Revisor: "<<this->Trabajador.GetName()
     <<"\n    Costo Total: $ "<< this->costoTotal()<<endl;
}
