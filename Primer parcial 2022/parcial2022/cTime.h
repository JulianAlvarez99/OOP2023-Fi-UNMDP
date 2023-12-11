#ifndef CTIME_H_INCLUDED
#define CTIME_H_INCLUDED
#include <iostream>
using namespace std;

class cTime
{
private:
    unsigned int hora;
    unsigned int minuto;
    unsigned int segundo;
public:
// todos los métodos necesarios
    cTime(const unsigned int h = 0,const unsigned int m = 0,const unsigned int s = 0);
    void setTiempo(const unsigned int h, const unsigned int m, const unsigned int s);
    cTime getTiempo() const;
    void incrementarTiempo(const unsigned int m);

    friend ostream& operator<<(ostream &salida, const cTime &t);
};


#endif // CTIME_H_INCLUDED
