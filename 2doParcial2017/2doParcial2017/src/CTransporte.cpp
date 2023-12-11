#include "CTransporte.h"

CTransporte::CTransporte(int pax, string patente, float vel, unsigned int col)
{
    this->Matricula = patente;
    this->Pintura.value = col;
}

CTransporte::~CTransporte()
{
    //dtor
}

void CTransporte::SetMatricula(string patente)
{
    this->Matricula = patente;
}

string CTransporte::GetMatricula()
{
    return Matricula;
}

unsigned CTransporte::GetColor()
{
    return(Pintura.value);
}
void CTransporte::SetColor(unsigned int col)
{
    this->Pintura.value = col;
}
void CTransporte::SetRed(unsigned int red)
{
    this->Pintura.bytes[2] = red;
}
void CTransporte::SetGreen(unsigned int green)
{
    this->Pintura.bytes[1] = green;
}
void CTransporte::SetBlue(unsigned int blue)
{
    this->Pintura.bytes[0] = blue;
}
void CTransporte::SetAlpha(unsigned int alpha)
{
    this->Pintura.bytes[3] = alpha;
}

void CTransporte::imprimirColor(ostream& os)
{
      os<<"Color: "<<hex<<showbase<<uppercase<<Pintura.value
      <<dec<<" (Rojo = "<<(unsigned)Pintura.bytes[2]
      <<" Verde = "<<(unsigned)Pintura.bytes[1]
      <<" Azul = "<<(unsigned)Pintura.bytes[0]
      <<" Alpha = "<<(unsigned)Pintura.bytes[3]<<")"<<endl;
}

ostream& operator<<(ostream& os, CTransporte* &trans)
{
    trans->vImprimir(os);
    return(os);
}
