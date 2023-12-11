#include "persona.h"

persona::persona(string nombre, unsigned numero, fecha ddmmaa)
{
    this->Name = nombre;
    this->Document = numero;
    this->BirthDate = ddmmaa;
}

persona::~persona()
{
    ;
}

void persona::SetName(string nombre)
{
    this->Name = nombre;
}
bool persona::SetDocument(unsigned doc)             /// retorna TRUE si el formato es correcto
{
    bool result = false;

    if (doc > 1000000)
    {
        this->Document = doc;
        result = true;
    }
    return(result);
}
bool persona::SetBirthDate(fecha date)              /// chequea la validez de la fecha
{
    bool result = false;

    if(date.Day <= 31 && date.Month <= 12 && (date.Year > 1700 && date.Year < 2023))
    {
        this->BirthDate = date;
        result = true;
    }
    return(result);
}
bool persona::SetBirthDate(int d, int m, int y)       ///chequea la validez de la fecha
{
    bool result = false;

    if(d<=31 && m<=12 && (y>1700 && y<2023))
    {
        this->BirthDate.Day = d;
        this->BirthDate.Month = m;
        this->BirthDate.Year = y;
        result = true;
    }
    return(result);
}

string persona::GetName()
{
    return(Name);
}
unsigned persona::GetDocument()
{
    return(Document);
}
fecha& persona::GetBirthDate()
{
    return(BirthDate);
}

ostream& operator << (ostream& salida, persona* &per)
{
    salida<<left<<"Nombre:"<<per->GetName()<<endl
          <<"DNI:"<<per->GetDocument()<<endl
          <<"Fecha de nacimiento: "<<per->GetBirthDate()<<endl;
    return(salida);
}

fecha::fecha(int d, int m, int a)
{
    this->Day = d;
    this->Month = m;
    this->Year = a;
}

ostream& operator << (ostream& salida, fecha& date)
{
    salida<<date.Day<<"/"<<date.Month<<"/"<<date.Year;
    return salida;
}
