#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED
#include <iostream>
#include <algorithm>
#include <vector>

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
    void setFecha(uint16_t,uint16_t,uint32_t);
    void setDay(uint16_t);
    void setMonth(uint16_t);
    void setYear(uint32_t);
    void ingresarFecha();
    void imprimir_la();
    void imprimir_us();
    void imprimir_letras();
    string mesLetras();
    string numerosLetras();
    bool validarFecha();
};

#endif // FECHA_H_INCLUDED
