#ifndef CMATRIZ_H_INCLUDED
#define CMATRIZ_H_INCLUDED
#include "cColor.h"
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

class CMatriz : public CColor
{
protected:
    unsigned int cantidad_filas;
    unsigned int cantidad_columnas;
    unsigned int **todos_los_valores;
private:
public:
    CMatriz( unsigned int filas = 0, unsigned int columnas = 0,unsigned int* data = NULL);
    CMatriz(const CMatriz&); /**Constructor por copia**/
    ~CMatriz();

    void cargar(const char* _nombreArchivo);
    void setFilas(const unsigned int filas);
    void setColumnas(const unsigned int columnas);

    unsigned int getFilas();
    unsigned int getColumnas();

    /**SOBRECARGA DE OPERADORES**/
    CMatriz operator+(const CMatriz&);
    CMatriz operator+(const unsigned int);
    CMatriz operator+= (const CMatriz&);
    CMatriz operator= (const CMatriz&);
    friend ostream& operator<< (ostream&, const CMatriz&);
};

unsigned int** _reservaMatrix(unsigned int, unsigned int);


#endif // CMATRIZ_H_INCLUDED
