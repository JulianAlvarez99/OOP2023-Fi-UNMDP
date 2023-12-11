#include "CMatriz.h"
#include <iomanip>

CMatriz::CMatriz( unsigned int filas, unsigned int columnas,color_t* data)
{
    this->cantidad_filas = filas;
    this->cantidad_columnas = columnas;
    this->todos_los_valores = data;
}

CMatriz::CMatriz(const CMatriz &original) /**Constructor por copia**/
{
    cantidad_filas = original.cantidad_filas;
    cantidad_columnas = original.cantidad_columnas;
    todos_los_valores = new color_t[cantidad_filas*cantidad_columnas-1];
    memcpy((void*)todos_los_valores,(void*)original.todos_los_valores,sizeof(color_t)*cantidad_filas*cantidad_columnas-1);
}

CMatriz::~CMatriz()
{
    if(todos_los_valores != NULL)
    {
        delete [] this->todos_los_valores;
    }
}

void CMatriz::cargar(string _nombreArchivo)
{
    fstream fentrada(_nombreArchivo.data(), ios::in|ios::binary);

    if (fentrada.is_open())
    {
    fentrada.read((char*)&(this->cantidad_filas), sizeof(unsigned int));
    fentrada.read((char*)&(this->cantidad_columnas), sizeof(unsigned int));

    todos_los_valores = new color_t[cantidad_filas*cantidad_columnas-1];

    fentrada.read((char*)(this->todos_los_valores),sizeof(color_t)*cantidad_columnas*cantidad_filas);

    fentrada.close();
    }
}

void CMatriz::setFilas(const unsigned int filas)
{
    cantidad_filas = filas;
}
void CMatriz::setColumnas(const unsigned int columnas)
{
    cantidad_columnas = columnas;
}

unsigned int CMatriz::getFilas()
{
    return(cantidad_filas);
}

unsigned int CMatriz::getColumnas()
{
    return(cantidad_columnas);
}

color_t* CMatriz::getValores()
{
    return(todos_los_valores);
}

/**SOBRECARGA DE OPERADORES**/
CMatriz& CMatriz::operator+(const CMatriz& _matrizAux)
{
    if(cantidad_filas==_matrizAux.cantidad_filas && cantidad_columnas==_matrizAux.cantidad_columnas)
    {
        unsigned int _arrayLenght = cantidad_filas*cantidad_columnas;

        for(unsigned int i=0; i<_arrayLenght; i++)
        {
            todos_los_valores[i].value = todos_los_valores[i].value + _matrizAux.todos_los_valores[i].value;
        }
    }
    return (*this);
}

CMatriz& CMatriz::operator+(const unsigned int _auxInteger)
{
    unsigned int _arrayLenght = cantidad_filas*cantidad_columnas;

    for(unsigned int i=0; i<_arrayLenght; i++)
    {
        todos_los_valores[i].value += _auxInteger;
    }
    return (*this);
}

CMatriz& CMatriz::operator+= (const CMatriz&_matrizAux)
{
    if(cantidad_filas==_matrizAux.cantidad_filas && cantidad_columnas==_matrizAux.cantidad_columnas)
    {
        unsigned int _arrayLenght = cantidad_filas*cantidad_columnas;

        for(unsigned int i=0; i<_arrayLenght; i++)
        {
            todos_los_valores[i].value += _matrizAux.todos_los_valores[i].value;
        }
    }
    return(*this);
}

CMatriz& CMatriz::operator= (const CMatriz& _matrizAux)
{
    this->setFilas(_matrizAux.cantidad_filas);
    this->setColumnas(_matrizAux.cantidad_columnas);

    if((this->getFilas() == _matrizAux.cantidad_filas) && (this->getColumnas() == _matrizAux.cantidad_columnas))
    {
        unsigned int total=this->getFilas()*this->getColumnas();

        this->todos_los_valores=new color_t[total-1];

        for(unsigned int i=0; i<total; i++)
        {
            this->todos_los_valores[i].value = _matrizAux.todos_los_valores[i].value;
        }
    }
    return(*this);
}

ostream& operator<< (ostream& salida, const CMatriz& matriz)
{
    salida.flags(ios::hex | ios::showbase | ios::uppercase);

    for(unsigned int i=0; i<matriz.cantidad_filas; i++)
    {
        for(unsigned int j=0; j<matriz.cantidad_columnas; j++)
        {
            salida<<"\t"<<left<<setw(10)<<matriz.todos_los_valores[i*matriz.cantidad_columnas+j].value<<setfill(' ');
        }
        salida<<"\n";
    }
    salida.flags(ios::dec);
    return salida;
}
