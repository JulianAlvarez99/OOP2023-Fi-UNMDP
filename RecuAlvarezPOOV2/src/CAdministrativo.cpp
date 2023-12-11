#include "CAdministrativo.h"

CAdministrativo::CAdministrativo()
{
    this->Salary = 0.0;
}

CAdministrativo::CAdministrativo(CPersona p1,CFecha f1, double sal)
{
    this->Sujeto = p1;
    this->Hired = f1;
    this->Salary = sal;
}

CAdministrativo::~CAdministrativo()
{
    //dtor
}

void CAdministrativo::SetEmployed(int d, int m, int y)
{
    Hired.SetDay(d);
    Hired.SetMonth(m);
    Hired.SetYear(y);
}

CFecha CAdministrativo::GetEmployed()
{
    return(Hired);
}
void CAdministrativo::SetSalary(double monto)
{
    this->Salary = monto;
}

double CAdministrativo::GetSalary()
{
    return(Salary);
}
ostream &operator<<(ostream& salida, CAdministrativo& adm)
{

    salida<<(CPersona&)adm<< "Fecha de contratacion: "<< adm.Hired << "\tSalario: $"<< adm.Salary<<endl;
    return(salida);
}


