#include "cPantalla.h"

CPantalla::CPantalla(const CMatriz &original):CMatriz(original)
{
}

void CPantalla::ajustarColor(unsigned int _modAlpha)
{
    CColor _colorActual;

    for(unsigned int i=0; i<getFilas(); i++)
    {
        for(unsigned int j=0; j<getColumnas(); j++)
        {
            _colorActual.setColor(todos_los_valores[i][j]);

            if(_colorActual.getAlpha()+_modAlpha>255)
            {
                _colorActual.setAlpha(255);
            }
            else
            {
                _colorActual.setAlpha(_colorActual.getAlpha()+_modAlpha);
            }
             todos_los_valores[i][j] = _colorActual.getColor();
        }
    }
}

void CPantalla::borrarVerde()
{
    CColor _colorActual;

    for(unsigned int i=0; i<getFilas(); i++)
    {
        for(unsigned int j=0; j<getColumnas(); j++)
        {
            _colorActual.setColor(todos_los_valores[i][j]);
            _colorActual.setGreen(0);
             todos_los_valores[i][j] = _colorActual.getColor();
        }
    }
}

void CPantalla::reforzarRojo(float _porcentajeRojo)
{
    CColor _colorActual;

    for(unsigned int i=0; i<getFilas(); i++)
    {
        for(unsigned int j=0; j<getColumnas(); j++)
        {
              _colorActual.setColor(todos_los_valores[i][j]);

            if(_colorActual.getRed()*(1+_porcentajeRojo)>255)
            {
                _colorActual.setRed(255);
            }
            else
            {
                _colorActual.setRed(_colorActual.getRed()*(1+_porcentajeRojo));
            }
             todos_los_valores[i][j] = _colorActual.getColor();
        }
    }
}

unsigned int* CPantalla::getPtr()
{
    unsigned int *_dataArray = new unsigned int[getFilas()*getColumnas()];
    int _Index = 0;

     for(unsigned int i=0; i<getFilas(); i++)
        {
            for(unsigned int j=0; j<getColumnas(); j++)
            {
              _dataArray[_Index++] = todos_los_valores[i][j];
            }
        }
    return (_dataArray);
}
