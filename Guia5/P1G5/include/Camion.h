#ifndef CAMION_H
#define CAMION_H

#include <Vehiculo.h>


class Camion : public Vehiculo
{
    public:
        Camion();
        virtual ~Camion();

        virtual void Acelerar();
        virtual void Frenar();

    protected:

    private:
};

#endif // CAMION_H
