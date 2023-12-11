#include <iostream>
#include "fecha.h"

using namespace std;

int main()
{
   fecha date;
   bool re;

   date.imprimir_la();
   date.imprimir_us();
   date.imprimir_letras();
   re = date.validarFecha();

   cout<<re<<endl;

    return 0;
}
