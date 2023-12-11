#ifndef CRECTANGULO_H_INCLUDED
#define CRECTANGULO_H_INCLUDED
#include "CFigura.h"

class CRectangulo : virtual public CFigura
{
    public:
        CRectangulo(string tipo = "Rectangulo",unsigned int fore_color = 0,unsigned int back_color = 0, float b = 0.0, float h = 0.0);
        CRectangulo(float ,float);
        virtual ~CRectangulo();

        double dCalcArea();
        void vImprimir(ostream& os=cout);
        void SetValores(float, float);
        void file_write_txt(ostream&);
        void file_write_bin(const char*);
    protected:
    private:
};

#endif // CRECTANGULO_H_INCLUDED
