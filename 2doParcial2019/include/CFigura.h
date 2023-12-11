#ifndef CFIGURA_H_INCLUDED
#define CFIGURA_H_INCLUDED
#include <math.h>
#include <iostream>
#include <fstream>
#include "CColor.h"

using namespace std;

class CFigura
{
    public:
        CFigura(string tipo = "", unsigned int fore_color = 0, unsigned int back_color = 0);
        virtual ~CFigura();
        CColor& colGetForeColor();
        CColor& colGetBackColor();
        void vSetForeColor(CColor);
        void vSetBackColor(CColor);

        string GetTipoFigura();
        float GetAltura();
        float GetBase();

        void SetTipoFigura(string);
        void SetAltura(float);
        void SetBase(float);

        virtual double dCalcArea() = 0;
        friend ostream& operator<< (ostream&, CFigura* &);
        virtual void vImprimir(ostream& os=cout)=0;
        virtual void SetValores(float, float){};
        virtual void SetValores(float){};

        virtual void file_write_txt(ostream&) = 0;
        virtual void file_write_bin(const char*) = 0;

    protected:
        CColor Color_fondo;
        CColor Color_linea;
        string TipoFigura;
        float Base;
        float Altura;
        double Area;
};

#endif // CFIGURA_H_INCLUDED
