#include "CTerrestre.h"

CTerrestre::CTerrestre(float vel , int neum, string mar)
{
    this->Velocidad = vel;
    this->Ruedas = neum;
    this->Marca = mar;
}

CTerrestre::~CTerrestre()
{
    //dtor
}

void CTerrestre::SetRuedas(int neumaticos)
{
    this->Ruedas = neumaticos;
}
void CTerrestre::SetMarca(string firma)
{
    this->Marca = firma;
}
int CTerrestre::GetRuedas()
{
    return Ruedas;
}
string CTerrestre::GetMarca()
{
    return Marca;
}
void CTerrestre::SetVelocidad(float vel)
{
    this->Velocidad = vel;
}
float CTerrestre::GetVelocidad()
{
    return Velocidad;
}

void CTerrestre::vImprimir(ostream& os)
{
    os<<"Matricula: "<< GetMatricula()<<endl
      <<"Marca: "<<Marca<<endl
      <<"Velocidad maxima: "<<Velocidad<<endl
      <<"Cantidad Ruedas: " <<Ruedas<<endl;

      imprimirColor(os);
}

