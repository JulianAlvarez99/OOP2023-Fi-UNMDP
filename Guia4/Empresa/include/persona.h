#ifndef PERSONA_H
#define PERSONA_H
#include "Fecha.h"

class persona
{
    public:
        persona();
        persona(string name,fecha nac,string documento,string nrocuil);
        virtual ~persona();

    protected:

    private:
    string nombre_;
    fecha nacimiento_;
    string DNI_;
    string cuil_;
};

#endif // PERSONA_H
