#include "CCirculo.h"

CCirculo::CCirculo(string tipo, unsigned int fore_color,unsigned int back_color, float r)
:CFigura(tipo,fore_color,back_color)
{
    this->Base = r;
}

CCirculo::~CCirculo()
{
    //dtor
}

double CCirculo::dCalcArea()
{
    this->Area = M_PI*pow(Base,2);
    return Area;
}
void CCirculo::vImprimir(ostream& os)
{
    os<<"Soy un circulo de radio = "<< Base<< " y area = "<<dCalcArea()<<"\n"<<endl;
}
void CCirculo::SetValores(float rad)
{
    this->Base = rad;
    cout<<"Estoy en SetValores del circulo"<<endl;
}

void CCirculo::file_write_txt(ostream& os)
{
    os<<TipoFigura<<';'<<Color_linea.GetColor()<<';'<<Color_fondo.GetColor()<<';'<<Base<<endl;
}

void CCirculo::file_write_bin(const char* file_name)
{
    ofstream out;
    out.exceptions ( ofstream::badbit );
    try
    {
        out.open(file_name, ios::app|ios::binary);

        int circulo = 1;
        out.write( (char*)(&circulo), sizeof(circulo));

        out.write((char*)(&(this->colGetForeColor())),sizeof(this->colGetForeColor()));
        out.write((char*)(&(this->colGetBackColor())),sizeof(this->colGetBackColor()));

        float base = this->Base;
        out.write((char*)(&base),sizeof(float));
        float altura = 0.0;
        out.write((char*)(&altura),sizeof(float));
    }

catch(const ofstream::failure& e)
{
    cout << "Excepcion al abrir/escribir el archivo\n";
}
out.close();
}
