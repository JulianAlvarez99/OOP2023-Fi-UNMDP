#include "CMaritimo.h"

CMaritimo::CMaritimo(string patente, string nom, unsigned int col, int pax)
{
    this->SetMatricula(patente);
    this->Nombre = nom;
    this->SetColor(col);
    this->SetPasajeros(pax);
}

CMaritimo::~CMaritimo()
{
    //dtor
}

void CMaritimo::SetNombre(string name)
{
    this->Nombre = name;
}
string CMaritimo::GetNombre()
{
    return(Nombre);
}
int CMaritimo::GetPasajeros()
{
    return Pasajeros;
}
void CMaritimo::SetPasajeros(int pax)
{
    this->Pasajeros = pax;
}

void CMaritimo::vImprimir(ostream& os)
{
    os<<"Matricula: "<<GetMatricula()<<endl
      <<"Nombre: "<<Nombre<<endl
      <<"Cantidad pasajeros: "<<Pasajeros<<endl;

      imprimirColor(os);

}
