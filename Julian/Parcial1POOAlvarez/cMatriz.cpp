#include "cMatriz.h"
#include <iomanip>

CMatriz::CMatriz( unsigned int filas, unsigned int columnas,unsigned int* data)
{
    unsigned int _Index = 0;
    cantidad_filas = filas;
    cantidad_columnas = columnas;

    todos_los_valores = _reservaMatrix(cantidad_filas, cantidad_columnas);
    //Copio los datos del puntero data a la matrix
    for(unsigned int i = 0; i < cantidad_filas; i++)
    {
        for(unsigned int j = 0; j < cantidad_columnas; j++)
        {
            todos_los_valores[i][j] = data[_Index++];
        }
    }
}

CMatriz::CMatriz(const CMatriz &original) /**Constructor por copia**/
{
    cantidad_filas = original.cantidad_filas;
    cantidad_columnas = original.cantidad_columnas;

    todos_los_valores = _reservaMatrix(cantidad_filas, cantidad_columnas);

    for(unsigned int i = 0; i < cantidad_filas; i++)
    {
        for(unsigned int j = 0; j < cantidad_columnas; j++)
        {
            todos_los_valores[i][j] = original.todos_los_valores[i][j];
        }
    }
}

CMatriz::~CMatriz()
{
    if(todos_los_valores != NULL)
    {
        // se libera memoria: primero las filas y después el vector de punteros
        for(unsigned int i = 0; i < cantidad_filas; i++)
        {
            delete [] todos_los_valores[i];      // verificar en memoria como se destruyen los valores
        }
        delete [] todos_los_valores;
    }
}

unsigned int** _reservaMatrix(unsigned int filas, unsigned int columnas)
{
    // se reserva memoria para el vector de punteros
    unsigned int** _auxMatrix = new unsigned int*[filas];
    // se reserva memoria para cada fila
    for (unsigned int i = 0; i < filas; i++)
    {
        _auxMatrix[i] = new unsigned int[columnas];
    }
    return _auxMatrix;
}


void CMatriz::cargar(const char* _nombreArchivo)
{
    ifstream fentrada(_nombreArchivo, ios::in|ios::binary);

    if (!fentrada)
    {
        cerr << "Error al abrir el archivo" << endl;
        return;
    }

    fentrada.read((char*)&cantidad_filas, sizeof(unsigned int));
    fentrada.read((char*)&cantidad_columnas, sizeof(unsigned int));

    todos_los_valores = _reservaMatrix(cantidad_filas, cantidad_columnas);

    for(unsigned int i = 0; i<cantidad_filas; i++)
    {
        for(unsigned int j= 0; j<cantidad_columnas; j++)
        {
            fentrada.read((char*)&todos_los_valores[i][j],sizeof(unsigned int));
            setColor(todos_los_valores[i][j]);
        }
    }
    fentrada.close();
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

/**SOBRECARGA DE OPERADORES**/
CMatriz CMatriz::operator+(const CMatriz& _matrizAux)
{
    CMatriz _matriz;
    if(cantidad_filas==_matrizAux.cantidad_filas && cantidad_columnas==_matrizAux.cantidad_columnas)
    {
        for(unsigned int i=0; i<cantidad_filas; i++)
        {
            for(unsigned int j=0; j<cantidad_columnas; j++)
            {
                _matriz.todos_los_valores[i][j] = todos_los_valores[i][j] + _matrizAux.todos_los_valores[i][j];
            }
        }
    }
    return (_matriz);
}

CMatriz CMatriz::operator+(const unsigned int _auxInteger)
{
    for(unsigned int i=0; i<cantidad_filas; i++)
    {
        for(unsigned int j=0; j<cantidad_columnas; j++)
        {
            todos_los_valores[i][j] += _auxInteger;
        }
    }
    return (*this);
}

CMatriz CMatriz::operator+= (const CMatriz&_matrizAux)
{
    for(unsigned int i=0; i<cantidad_filas; i++)
    {
        for(unsigned int j=0; j<cantidad_columnas; j++)
        {
            todos_los_valores[i][j] += _matrizAux.todos_los_valores[i][j];
        }
    }
    return(*this);
}

CMatriz CMatriz::operator= (const CMatriz& _matrizAux)
{
    if(cantidad_filas == _matrizAux.cantidad_filas && cantidad_columnas == _matrizAux.cantidad_columnas)
    {
        cantidad_filas = _matrizAux.cantidad_filas;
        cantidad_columnas = _matrizAux.cantidad_columnas;

        todos_los_valores = _reservaMatrix(cantidad_filas, cantidad_columnas);

        for(unsigned int i=0; i<cantidad_filas; i++)
        {
            for(unsigned int j=0; j<cantidad_columnas; j++)
            {
                todos_los_valores[i][j] = _matrizAux.todos_los_valores[i][j];
            }
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
            salida<<"\t"<<left<<setw(10)<<matriz.todos_los_valores[i][j]<<setfill(' ');
        }
        salida<<"\n";
    }
    salida.flags(ios::dec);
    return salida;
}
