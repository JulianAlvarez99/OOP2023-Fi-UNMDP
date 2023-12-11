#ifndef CCIRCULO_H_INCLUDED
#define CCIRCULO_H_INCLUDED
#include "CFigura.h"
# define M_PI           3.14159265358979323846

class CCirculo : virtual public CFigura
{
    public:
        CCirculo(string tipo = "Circulo",unsigned int fore_color = 0,unsigned int back_color = 0, float r = 0.0);
        ~CCirculo();
        double dCalcArea();
        void vImprimir(ostream& os=cout);
        void SetValores(float);
        void file_write_txt(ostream&);
        void file_write_bin(const char*);
    protected:
    private:
};


#endif // CCIRCULO_H_INCLUDED
