#ifndef CADMINISTRATIVO_H
#define CADMINISTRATIVO_H
#include "CPersona.h"

class CAdministrativo: public CPersona
{
public:
    CAdministrativo();
    CAdministrativo(CPersona, CFecha, double);

    virtual ~CAdministrativo();

    void SetEmployed(int, int, int);
    CFecha GetEmployed();
    double GetSalary();
    void SetSalary(double);
    friend ostream &operator<<(ostream&,CAdministrativo&);

private:

    CPersona Sujeto;
    CFecha Hired;
    double Salary;

protected:

};



#endif // CADMINISTRATIVO_H
