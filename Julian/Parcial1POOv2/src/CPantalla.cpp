#include "CPantalla.h"

CPantalla::CPantalla(const CMatriz &original):CMatriz(original)
{
    //ctor
}

void CPantalla::ajustarColor(unsigned int _modAlpha)
{
    unsigned int total = getFilas()*getColumnas();
    unsigned int alpha = 0;

    for(unsigned int i=0; i<total; i++)
    {
        alpha = this->getValores()[i].components[3];//(this->getValores()[i].value >> 24) & 0xFF;

        if(alpha + _modAlpha > 255)
        {
            this->getValores()[i].components[3] = 0xFF;//this->getValores()[i].value = (this->getValores()[i].value & 0x00FFFFFF) | 0xFF000000;
        }
        else
        {
            alpha += _modAlpha;
            this->getValores()[i].components[3] = alpha;//this->getValores()[i].value = (this->getValores()[i].value&0x00FFFFFF) + (alpha<<24);
        }
    }
}
void CPantalla::borrarVerde()
{
    unsigned int total = getFilas()*getColumnas();
    for(unsigned int i = 0; i<total; i++)
        this->getValores()[i].components[1]=0x00;//this->getValores()[i].value = (this->getValores()[i].value & 0xFFFF00FF);
}

void CPantalla::reforzarRojo(float _porcentajeRojo)
{
    unsigned int total = getFilas()*getColumnas();
    float rojo;

    if (_porcentajeRojo < 0.0f)
    {
        _porcentajeRojo = 0.0f;
    }
    else if (_porcentajeRojo > 100.0f)
    {
        _porcentajeRojo = 100.0f;
    }

    // Calcula el factor de reforzamiento en función del porcentaje
    float factorReforzamiento = 1.0f + _porcentajeRojo;

    for(unsigned int i = 0; i<total; i++)
    {
        rojo = this->getValores()[i].components[2];//(this->getValores()[i].value >> 16) & 0xFF;

        if(rojo*factorReforzamiento > 255)
        {
            this->getValores()[i].components[2] = 0xFF;//this->getValores()[i].value = (this->getValores()[i].value & 0xFF00FFFF) | 0x00FF0000;
        }
        else
        {
            rojo = rojo * factorReforzamiento;
            this->getValores()[i].components[2] = (unsigned int)rojo;//this->getValores()[i].value = (this->getValores()[i].value&0xFF00FFFF) + ((unsigned int)rojo<<16);
        }
    }
}

ostream& operator<< (ostream& co, const CPantalla& pan)
{
    co<<"Estoy en impresion de pantalla"<<endl;
    co<<(CMatriz&)pan;                          //OVERRIDING
    return co;
}
