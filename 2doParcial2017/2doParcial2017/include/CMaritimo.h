#ifndef CMARITIMO_H
#define CMARITIMO_H
#include "CTransporte.h"

class CMaritimo : virtual public CTransporte
{
    public:
        CMaritimo(string patente = "", string nom = "", unsigned int col = 0, int pax = 0);
        virtual ~CMaritimo();

        void SetPasajeros(int);
        void SetNombre(string);

        int GetPasajeros();
        string GetNombre();

        virtual void vImprimir(ostream& os=cout);
    protected:

    private:
        string Nombre;
        int Pasajeros;
};

#endif // CMARITIMO_H
