#include "CColor.h"

CColor::CColor()
{
    //ctor
}

CColor::CColor(unsigned int col)
{
    this->color.value = col;
}

unsigned char CColor::GetRed()
{
    return(color.byte[2]);
}
unsigned char CColor::GetGreen()
{
    return(color.byte[1]);
}
unsigned char CColor::GetBlue()
{
    return(color.byte[0]);
}
unsigned char CColor::GetAlpha()
{
    return(color.byte[3]);
}
unsigned int CColor::GetColor()
{
    return(color.value);
}
void CColor::SetRed(unsigned char red)
{
    this->color.byte[2] = red;
}
void CColor::SetGreen(unsigned char green)
{
    this->color.byte[1] = green;
}
void CColor::SetBlue(unsigned char blue)
{
    this->color.byte[0] = blue;
}
void CColor::SetAlpha(unsigned char alpha)
{
    this->color.byte[3] = alpha;
}
void CColor::SetColor(int col)
{
    this->color.value = col;
}
ostream& operator<< (ostream& os, CColor& col)
{
     os << "componente rojo: " << (unsigned int)col.color.byte[0]
           << "\ncomponente verde: " << (unsigned int)col.color.byte[1]
           << "\ncomponente azul: " <<(unsigned int)col.color.byte[2]
           << "\ncomponente alpha: " << (unsigned int)col.color.byte[3];
    return os;
}
