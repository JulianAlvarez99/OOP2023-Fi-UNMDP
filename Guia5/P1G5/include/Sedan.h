#ifndef SEDAN_H
#define SEDAN_H

#include <Auto.h>


class Sedan : public Auto
{
    public:
        Sedan();
        virtual ~Sedan();

        virtual void Acelerar();
        virtual void Frenar();

    protected:

    private:
};

#endif // SEDAN_H
