#ifndef FECHACLICISMO_H_INCLUDED
#define FECHACLICISMO_H_INCLUDED
#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>

using namespace std;

class fecha
{
private:
    uint16_t day;
    uint16_t month;
    uint32_t year;
    vector<uint32_t> intToArray(uint32_t number);
    string _numeroLetras(vector<uint32_t>);

public:
    fecha();
    fecha(uint16_t,uint16_t,uint32_t);
    void setFecha(uint16_t,uint16_t,uint32_t);
    void setDay(uint16_t);
    void setMonth(uint16_t);
    void setYear(uint32_t);
    void ingresarFecha();
    void imprimir_la();
    void imprimir_us();
    void imprimir_letras();
    void imprimir();
    string mesLetras();
    string numerosLetras();
    bool validarFecha();
    uint16_t fechaEdad();
};

#endif // FECHACLICISMO_H_INCLUDED
