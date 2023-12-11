#ifndef CVENDEDOR_H
#define CVENDEDOR_H
#include "CPersona.h"


class CVendedor: public CPersona
{
public:
    CVendedor(string nombre = " ", int doc = 0);
    CVendedor(CPersona p1);
    virtual ~CVendedor();

    void SetPaymentDate(CFecha);
    void SetPaymentDate(int,int,int);
    void SetEmployed(int,int,int);
    void SetComision(double);
    unsigned int GetPaymentDate();
    double GetComision();
    CFecha GetEmployed();
    friend ostream &operator<<(ostream&,CVendedor&);

protected:

private:
    CPersona Sujeto;
    CFecha Hired;
    CFecha PaymentDay;
    double Comision;
};

#endif // CVENDEDOR_H
