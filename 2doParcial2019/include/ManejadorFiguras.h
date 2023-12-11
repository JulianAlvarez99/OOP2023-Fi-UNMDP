#ifndef MANEJADORFIGURAS_H_INCLUDED
#define MANEJADORFIGURAS_H_INCLUDED
#include <vector>
#include <cstdint>
#include <ostream>
#include <fstream>
#include <algorithm>
#include "CCirculo.h"
#include "CRectangulo.h"
#include "CTriangulo.h"
#include <sstream>

using namespace std;

class ManejadorFiguras
{
    public:
        ManejadorFiguras();
        virtual ~ManejadorFiguras();
        void CargarFiguras();
        void ImprimirFiguras(ostream& os=cout);
        double TotalArea();
        void AgregarFigura(CFigura*);
        CFigura* Get(uint8_t);
        void Ordenar();
        void GuardarFiguras_txt(const char*);
        void RecuperarFiguras_txt(const char*);

        void GuardarFiguras_bin(const char*);
        void RecuperarFiguras_bin(const char*);
    protected:
    private:
        vector<CFigura*> Figuras;
};

bool cmp(CFigura*,CFigura*);
long long unsigned int fileSize(const char*);

#endif // MANEJADORFIGURAS_H_INCLUDED
