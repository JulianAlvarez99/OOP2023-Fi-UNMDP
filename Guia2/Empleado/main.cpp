#include <iostream>
#include "Empleado.h"

using namespace std;

int main()
{
    empleado e1("Juan","Perez",fecha(1,7,1999),fecha(31,12,1978));
    empleado e2("Pedro","Lopez",fecha(1,7,1999),fecha(25,2,1980));

    e1.imprimir();
    e2.imprimir();
    system("pause");
    return 0;
}
