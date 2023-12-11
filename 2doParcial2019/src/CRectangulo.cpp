#include "CRectangulo.h"

CRectangulo::CRectangulo(string tipo, unsigned int fore_color,unsigned int back_color, float b, float h)
    :CFigura(tipo,fore_color,back_color)
{
    this->Base = b;
    this->Altura = h;
}
CRectangulo::CRectangulo(float b, float h)
{
    this->Altura = h;
    this->Base = b;
    this->TipoFigura = "Rectangulo";
}

CRectangulo::~CRectangulo()
{
    //dtor
}

double CRectangulo::dCalcArea()
{
    this->Area = Base*Altura;
    return Area;
}
void CRectangulo::vImprimir(ostream& os)
{
    os<<left<<"Soy un rectangulo de base = "<<Base<<" altura = "<<Altura<<" y area = "<<dCalcArea()<<"\n"<<endl;
}
void CRectangulo::SetValores(float b, float h)
{
    this->Altura = h;
    this->Base = b;
}

void CRectangulo::file_write_txt(ostream& os)
{
    os<<TipoFigura<<';'<<Color_linea.GetColor()<<';'<<Color_fondo.GetColor()<<';'<<Base<<';'<<Altura<<endl;
}

void CRectangulo::file_write_bin(const char* file_name)
{
    fstream out;
    out.exceptions ( ofstream::badbit );
    try
    {
        out.open(file_name, ios::app|ios::binary);

        int rectangulo = 3;
        out.write( (char*)( &rectangulo ), sizeof( rectangulo ));
        out.write((char*)(&(this->colGetForeColor())),sizeof(this->colGetForeColor()));
        out.write((char*)(&(this->colGetBackColor())),sizeof(this->colGetBackColor()));

        float base = this->Base;
        out.write((char*)&(base),sizeof(base));
        float altura = this->Altura;
        out.write((char*)&(altura),sizeof(altura));
    }

catch(const ofstream::failure& e)
{
    cout << "Excepcion al abrir/escribir el archivo\n";
}
out.close();
}
