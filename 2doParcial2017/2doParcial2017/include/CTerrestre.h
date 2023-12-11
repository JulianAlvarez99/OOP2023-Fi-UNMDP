#ifndef CTERRESTRE_H
#define CTERRESTRE_H
#include "CTransporte.h"

class CTerrestre : virtual public CTransporte
{
    public:
        CTerrestre(float vel = 50.0, int neum = 4, string mar = "Renault");
        virtual ~CTerrestre();

        void SetRuedas(int neumaticos);
        void SetMarca(string firma);
        void SetVelocidad(float);

        int GetRuedas();
        string GetMarca();
        float GetVelocidad();

        virtual void vImprimir(ostream& os=cout);

    protected:

    private:
        float Velocidad;
        int Ruedas;
        string Marca;
};

#endif // CTERRESTRE_H
