#include "CTriangulo.h"

CTriangulo::CTriangulo(string tipo, unsigned int fore_color,unsigned int back_color, float b, float h)
:CFigura(tipo,fore_color,back_color)
{
    this->Base = b;
    this->Altura = h;
}

CTriangulo::CTriangulo(float b, float h)
{
    this->Altura = h;
    this->Base = b;
    this->TipoFigura = "Triangulo";
}

CTriangulo::~CTriangulo()
{
    //dtor
}

double CTriangulo::dCalcArea()
{
    this->Area = (Base*Altura)/2;
    return Area;
}
void CTriangulo::vImprimir(ostream& os)
{
    os<<left<<"Soy un triangulo de base = "<<Base<<" altura = "<<Altura<<" y area = "<<dCalcArea()<<"\n"<<endl;
}
void CTriangulo::SetValores(float b, float h)
{
    this->Altura = h;
    this->Base = b;
}

void CTriangulo::file_write_txt(ostream& os)
{
   os<<TipoFigura<<';'<<Color_linea.GetColor()<<';'<<Color_fondo.GetColor()<<';'<<Base<<';'<<Altura<<endl;
}

void CTriangulo::file_write_bin(const char* file_name)
{
    ofstream out;
    out.exceptions ( ofstream::badbit );
    try
    {
        out.open(file_name, ios::app|ios::binary);

        int triangulo = 2;
        out.write( (char*)( &triangulo), sizeof(triangulo));

        out.write((char*)(&(this->colGetForeColor())),sizeof(this->colGetForeColor()));
        out.write((char*)(&(this->colGetBackColor())),sizeof(this->colGetBackColor()));

        float base = this->Base;
        out.write((char*)(&base),sizeof(float));
        float altura = this->Altura;
        out.write((char*)(&altura),sizeof(float));
    }

catch(const ofstream::failure& e)
{
    cout << "Excepcion al abrir/escribir el archivo\n";
}
out.close();
}
