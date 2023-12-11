#ifndef FURGONETA_H
#define FURGONETA_H

#include <Auto.h>


class Furgoneta : public Auto
{
    public:
        Furgoneta();
        virtual ~Furgoneta();

        virtual void Acelerar();
        virtual void Frenar();

    protected:

    private:
};

#endif // FURGONETA_H
