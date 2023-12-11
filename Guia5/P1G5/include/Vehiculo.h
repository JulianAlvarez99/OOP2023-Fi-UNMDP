#ifndef VEHICULO_H
#define VEHICULO_H
#include <iostream>


using namespace std;
class Vehiculo
{
    public:
        Vehiculo();
        virtual ~Vehiculo();

        virtual void Acelerar() = 0;
        virtual void Frenar() = 0;

    protected:

    private:
};

#endif // VEHICULO_H
