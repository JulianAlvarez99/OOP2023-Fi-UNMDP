#ifndef CTRIANGULO_H
#define CTRIANGULO_H
#include "CFigura.h"

class CTriangulo : virtual public CFigura
{
    public:
        CTriangulo(string tipo = "Triangulo",unsigned int fore_color = 0,unsigned int back_color = 0, float b = 0.0, float h = 0.0);
        CTriangulo(float, float);
        virtual ~CTriangulo();
        double dCalcArea();
        void vImprimir(ostream& os=cout);
        void SetValores(float, float);
        void file_write_txt(ostream&);
        void file_write_bin(const char*);
    protected:
    private:

};

#endif // CTRIANGULO_H
