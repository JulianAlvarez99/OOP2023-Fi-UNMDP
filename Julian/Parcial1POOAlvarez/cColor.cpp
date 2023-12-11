#include "CColor.h"

CColor::CColor(uint32_t col)
{   //color = 0x AA RR GG BB
    color=col;
}

uint8_t CColor::getAlpha()
{
    return ((color & 0xFF000000) >> 24) & 0xFF;
}

uint8_t CColor::getRed()
{
    return ((color & 0x00FF0000) >> 16) & 0xFF;
}

uint8_t CColor::getGreen()
{
    return ((color & 0x0000FF00) >> 8) & 0xFF;
}

uint8_t CColor::getBlue()
{
    return (color & 0x000000FF);
}

uint32_t CColor::getColor()
{
    return color;
}

void CColor::setRed(uint8_t red)
{
    uint32_t col;
    col = (color & 0xFF00FFFF) | (red<<16);
    color = col;
}

void CColor::setGreen(uint8_t green)
{
    uint32_t col;
    col = (color & 0xFFFF00FF) | (green<<8);
    color = col;
}

void CColor::setBlue(uint8_t blue)
{
    uint32_t col;
    col = (color & 0xFFFFFF00) | (blue);
    color = col;
}

void CColor::setAlpha(uint8_t alpha)
{
    uint32_t col;
    col = (color & 0x00FFFFFF) | (alpha<<24);
    color = col;
}

void CColor::setColor(uint32_t val)
{
    color = val;
}

ostream& operator<< (ostream& co, CColor& c)
{
        co << "\ncomponente azul: " << (uint32_t)c.getBlue()
           << "\ncomponente roja: " << (uint32_t)c.getRed()
           << "\ncomponente verde: " << (uint32_t)c.getGreen()
           << "\ncomponente alpha:: " << (uint32_t)c.getAlpha();
    return co;
}
