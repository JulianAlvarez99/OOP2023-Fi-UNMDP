#ifndef CMATRIZ_H
#define CMATRIZ_H
#include <string>
#include <iostream>
#include <fstream>
#include <cstring>
#include "CColor.h"

using namespace std;

class CMatriz
{
protected:
    unsigned int cantidad_filas;
    unsigned int cantidad_columnas;
    color_t * todos_los_valores;

private:

public:
    CMatriz( unsigned int filas = 0, unsigned int columnas = 0,color_t* data = NULL);
    CMatriz(const CMatriz&); /**Constructor por copia**/
    virtual ~CMatriz();

    void cargar(string _nombreArchivo);
    void setFilas(const unsigned int filas);
    void setColumnas(const unsigned int columnas);

    unsigned int getFilas();
    unsigned int getColumnas();
    color_t* getValores();

    /**SOBRECARGA DE OPERADORES**/
    CMatriz& operator+(const CMatriz&);
    CMatriz& operator+(const unsigned int);
    CMatriz& operator+= (const CMatriz&);
    CMatriz& operator= (const CMatriz&);
    friend ostream& operator<< (ostream&, const CMatriz&);
};

#endif // CMATRIZ_H
