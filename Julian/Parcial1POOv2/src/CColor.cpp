#include "CColor.h"

CColor::CColor(unsigned col)
{
      color.value = col;
}

ostream& operator<< (ostream& co, CColor& c)
{
        co << "\ncomponente azul: " << /*(c.color.value & 0xFF)*/(unsigned int)c.color.components[0]
           << "\ncomponente roja: " << /*(c.color.value>>16 & 0xFF)*/(unsigned int)c.color.components[2]
           << "\ncomponente verde: " << /*(c.color.value>>8 & 0xFF)*/(unsigned int)c.color.components[1]
           << "\ncomponente alpha: " << /*(c.color.value>>24 & 0xFF)*/(unsigned int)c.color.components[3];
    return co;
}

///AARRGGBB
///CON UNION QUEDA BBGGRRAA
