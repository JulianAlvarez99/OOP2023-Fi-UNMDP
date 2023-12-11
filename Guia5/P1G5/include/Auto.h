#ifndef AUTO_H
#define AUTO_H
#include "Vehiculo.h"

class Auto : public virtual Vehiculo
{
    public:
        Auto();
        virtual ~Auto();

        virtual void Acelerar() = 0;
        virtual void Frenar();
    protected:

    private:
};

#endif // AUTO_H
