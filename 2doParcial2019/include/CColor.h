#ifndef CCOLOR_H_INCLUDED
#define CCOLOR_H_INCLUDED
#include <ostream>
using namespace std;

typedef union
{
    unsigned int value;
    unsigned char byte[4];
}color_t;

class CColor
{
    public:
        CColor();
        CColor(unsigned int );
        unsigned char GetRed();
        unsigned char GetGreen();
        unsigned char GetBlue();
        unsigned char GetAlpha();
        unsigned int GetColor();
        void SetRed(unsigned char);
        void SetGreen(unsigned char);
        void SetBlue(unsigned char);
        void SetAlpha(unsigned char);
        void SetColor(int);
        friend ostream& operator<< (ostream&, CColor&);
    private:
        color_t color;
};
//BBGGRRAA
//RRGGBBAA ///TOME ESTA CONVENCION DE COLOR
#endif // CCOLOR_H_INCLUDED
