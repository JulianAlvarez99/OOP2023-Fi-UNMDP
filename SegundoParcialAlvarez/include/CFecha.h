#ifndef CFECHA_H
#define CFECHA_H

#include <ostream>
#include <iostream>      // para el cout
#include <fstream>       // para archivos

using namespace std;

class CFecha
{
public:
    CFecha();
    CFecha(unsigned int, unsigned int, unsigned int);
    unsigned int GetDay() const;
    bool SetDay(unsigned int);
    unsigned int GetMonth() const;
    bool SetMonth(unsigned int);
    unsigned int GetYear() const;
    bool SetYear(unsigned int);
    bool operator< (const CFecha) const;
    friend ostream& operator << (ostream&, CFecha&);
protected:
private:
    unsigned int Day;
    unsigned int Month;
    unsigned int Year;
};

#endif // CFECHA_H
