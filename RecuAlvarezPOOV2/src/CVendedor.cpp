#include "CVendedor.h"

CVendedor::CVendedor(string nombre, int doc):CPersona(nombre,doc)
{
    //ctor
}

CVendedor::CVendedor(CPersona p1)
{
    this->Sujeto = p1;
}

CVendedor::~CVendedor()
{
    //dtor
}

void CVendedor::SetPaymentDate(CFecha date)
{
    this->PaymentDay = date;
}

void CVendedor::SetPaymentDate(int dd,int mm,int yy)
{
    PaymentDay.SetDay(dd);
    PaymentDay.SetMonth(mm);
    PaymentDay.SetYear(yy);
}
void CVendedor::SetEmployed(int dd,int mm,int yy)
{
    Hired.SetDay(dd);
    Hired.SetMonth(mm);
    Hired.SetYear(yy);
}
void CVendedor::SetComision(double monto)
{
    this->Comision = monto;
}
unsigned int CVendedor::GetPaymentDate()
{
    return(PaymentDay.GetDay());
}
double CVendedor::GetComision()
{
    return(Comision);
}
CFecha CVendedor::GetEmployed()
{
    return(Hired);
}

ostream &operator<<(ostream &salida,CVendedor &vend)
{
    salida<<(CPersona&)vend<<"Fecha de contratacion: "<< vend.Hired
          <<"\t Dia de pago: "<<vend.PaymentDay.GetDay()<< "\tComision: $"<< vend.Comision<<endl;
    return salida;
}
