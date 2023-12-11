#ifndef CPERSONA_H
#define CPERSONA_H
#include <iostream>
#include "CFecha.h"
using namespace std;

enum TipoPersona_
{
    Pintor,
    Electricista,
    Cliente,
};

class CPersona
{
public:
    CPersona(string nombre = "Pedro", unsigned numero = 12345678, CFecha ddmmaa = CFecha(),TipoPersona_ estado = Cliente);
    ~CPersona();
    void SetName(string);
    void SetDocument(unsigned);             // retorna TRUE si el formato es correcto
    bool SetBirthDate(CFecha);              // chequea la validez de la fecha
    bool SetBirthDate(int, int, int);       // chequea la validez de la fecha
    void SetStatus(TipoPersona_);
    string GetName();
    unsigned GetDocument();
    CFecha& GetBirthDate();
    TipoPersona_ GetStatus();
    friend ostream& operator << (ostream&, CPersona&);
private:
protected:
    string Name;
    unsigned Document;
    CFecha BirthDate;
    TipoPersona_ Status;
};


#endif // CPERSONA_H
