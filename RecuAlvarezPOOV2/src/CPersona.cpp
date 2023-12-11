#include "CPersona.h"

CPersona::CPersona(string nombre, unsigned numero, CFecha ddmmaa, TipoEstadocivil_ estado)
{
    this->Name = nombre;
    this->Document = numero;
    this->BirthDate = ddmmaa;
    this->Status = estado;
}

CPersona::~CPersona()
{
    ;
}

void CPersona::SetName(string nombre)
{
    this->Name = nombre;
}
bool CPersona::SetDocument(unsigned doc)             /// retorna TRUE si el formato es correcto
{
    bool result = false;

    if (doc > 1000000)
    {
        this->Document = doc;
        result = true;
    }
    return(result);
}
bool CPersona::SetBirthDate(CFecha date)              /// chequea la validez de la fecha
{
    bool result = false;

    if(date.GetDay()<=31 && date.GetMonth()<=12 && (date.GetYear()>1700 && date.GetYear()<2023))
    {
        this->BirthDate = date;
        result = true;
    }
    return(result);
}
bool CPersona::SetBirthDate(int d, int m, int y)       ///chequea la validez de la fecha
{
    bool result = false;

    if(d<=31 && m<=12 && (y>1700 && y<2023))
    {
        this->BirthDate.SetDay(d);
        this->BirthDate.SetMonth(m);
        this->BirthDate.SetYear(y);
        result = true;
    }
    return(result);
}
void CPersona::SetStatus(TipoEstadocivil_ estado)
{
    this->Status = estado;
}
string CPersona::GetName()
{
    return(Name);
}
unsigned CPersona::GetDocument()
{
    return(Document);
}
CFecha& CPersona::GetBirthDate()
{
    return(BirthDate);
}

TipoEstadocivil_ CPersona::GetStatus()
{
    return(Status);
}
ostream& operator << (ostream& salida, CPersona& per)
{
    const char* strEstadocivil[] = {"Soltero","Casado","Divorciado","Viudo"};
    salida<<left<<"Nombre:"<<per.GetName()<<"\t\t\tDNI:"<<per.GetDocument()<<endl
          <<"Fecha de nacimiento: "<<per.GetBirthDate()<<"\t\tEstado civil: "<<strEstadocivil[per.GetStatus()]<<endl;

    return(salida);
}
