#ifndef AUTODEPORTIVO_H
#define AUTODEPORTIVO_H

#include <Auto.h>


class AutoDeportivo : public Auto
{
    public:
        AutoDeportivo();
        virtual ~AutoDeportivo();

        virtual void Acelerar();
        virtual void Frenar();

    protected:

    private:
};

#endif // AUTODEPORTIVO_H
