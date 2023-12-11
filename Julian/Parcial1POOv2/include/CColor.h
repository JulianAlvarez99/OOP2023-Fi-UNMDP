#ifndef CCOLOR_H
#define CCOLOR_H
#include <iostream>

using namespace std;

typedef union
{
    unsigned int value;
    unsigned char components[4];

} color_t;

class CColor
{
public:
    CColor(unsigned col = 0);

    friend ostream& operator<< (ostream& co, CColor& c);

protected:

private:
    color_t color;
};

#endif // CCOLOR_H
