#ifndef CPERSONA_H
#define CPERSONA_H
#include <iostream>
#include "CFecha.h"
using namespace std;

enum TipoEstadocivil_
{
    Soltero,
    Casado,
    Divorciado,
    Viudo
};

class CPersona
{
public:
    CPersona(string nombre = "Pedro", unsigned numero = 12345678, CFecha ddmmaa = CFecha(),TipoEstadocivil_ estado = Soltero);
    ~CPersona();
    void SetName(string);
    bool SetDocument(unsigned);             // retorna TRUE si el formato es correcto
    bool SetBirthDate(CFecha);              // chequea la validez de la fecha
    bool SetBirthDate(int, int, int);       // chequea la validez de la fecha
    void SetStatus(TipoEstadocivil_);
    string GetName();
    unsigned GetDocument();
    CFecha& GetBirthDate();
    TipoEstadocivil_ GetStatus();
    friend ostream& operator << (ostream&, CPersona&);
private:
protected:
    string Name;
    unsigned Document;
    CFecha BirthDate;
    TipoEstadocivil_ Status;
};


#endif // CPERSONA_H
