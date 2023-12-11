#include "CGerenteVentas.h"

CGerenteVentas::CGerenteVentas()
{
    this->AdmPayment = 0;
}

CGerenteVentas::CGerenteVentas(string name, int doc, CFecha birth)
{
    this->CVendedor::SetName(name);
    this->CVendedor::SetDocument(doc);
    this->CVendedor::SetBirthDate(birth);
    this->AdmPayment = 0;
}

CGerenteVentas::~CGerenteVentas()
{
    //dtor
}

void CGerenteVentas::SetAdmPayment(double monto)
{
    this->AdmPayment = monto;
}
double CGerenteVentas::GetAdmPayment()
{
    return(AdmPayment);
}

ostream &operator<<(ostream &salida,CGerenteVentas &gerente)
{
    salida<<(CVendedor&)gerente<<"Pago Administrativo: $"<< gerente.AdmPayment <<"\t\tSalario: $"<< gerente.GetSalary()<<endl;
    return salida;
}
