#include "CFigura.h"

CFigura::CFigura(string tipo, unsigned int fore_color, unsigned int back_color)
{
    this->TipoFigura = tipo;
    this->Color_linea = fore_color;
    this->Color_fondo = back_color;
}

CFigura::~CFigura()
{
    //dtor
}

CColor& CFigura::colGetForeColor()
{
    return(Color_linea);
}
CColor& CFigura::colGetBackColor()
{
    return(Color_fondo);
}
void CFigura::vSetForeColor(CColor linea)
{
    this->Color_linea = linea;
}
void CFigura::vSetBackColor(CColor fondo)
{
    this->Color_fondo = fondo;
}

string CFigura::GetTipoFigura()
{
    return this->TipoFigura;
}
float CFigura::GetAltura()
{
    return this->Altura;
}
float CFigura::GetBase()
{
    return this->Base;
}

void CFigura::SetTipoFigura(string tipo)
{
    this->TipoFigura = tipo;
}
void CFigura::SetAltura(float h)
{
    this->Altura = h;
}
void CFigura::SetBase(float b)
{
    this->Base = b;
}

ostream& operator<< (ostream& co, CFigura* &fig)
{
    fig->vImprimir(co);
    co<<"BackColor:\n"<<fig->Color_fondo<<endl<<endl
      <<"ForeColor:\n"<<fig->Color_linea<<endl<<endl;
    return(co);
}
