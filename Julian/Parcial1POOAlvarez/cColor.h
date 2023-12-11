#ifndef CCOLOR_H_INCLUDED
#define CCOLOR_H_INCLUDED
#include <ostream>
#include <cstdint>

using namespace std;

class CColor
{
protected:
    uint32_t color;      // color = 0x AA RR GG BB
private:
public:
    CColor(uint32_t col = 0);
    uint8_t getRed();
    uint8_t getGreen();
    uint8_t getBlue();
    uint8_t getAlpha();
    uint32_t getColor();
    void setRed(uint8_t);
    void setGreen(uint8_t);
    void setBlue(uint8_t);
    void setAlpha(uint8_t);
    void setColor(uint32_t);
    friend ostream& operator<< (ostream&, CColor&);
};


/**
union /// BB GG RR AA  --> ASI SE GUARDA EN CODEBLOCKS
{
    unsigned valor;
    unsigned byte[4]
}
**/

#endif // CCOLOR_H_INCLUDED
