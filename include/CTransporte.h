#ifndef CTRANSPORTE_H
#define CTRANSPORTE_H
#include <iostream>

using namespace std;

typedef union
{
    unsigned int value;
    unsigned char bytes[4];

}color_t;


class CTransporte
{
public:
    CTransporte(int pax = 0, string patente = "", float vel = 0.0, unsigned int col = 0);
    virtual ~CTransporte();

    virtual void SetMatricula(string);
    virtual string GetMatricula();

    virtual unsigned int GetColor();
    virtual void SetColor(unsigned int);
    virtual void SetRed(unsigned int);
    virtual void SetGreen(unsigned int);
    virtual void SetBlue(unsigned int);
    virtual void SetAlpha(unsigned int);
    virtual void imprimirColor(ostream& os);

    virtual void vImprimir(ostream& os=cout)=0;

    friend ostream& operator<<(ostream&,CTransporte*&);

protected:

private:
    string Matricula;
    color_t Pintura;
};

#endif // CTRANSPORTE_H
