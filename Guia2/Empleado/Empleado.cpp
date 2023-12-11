#include "Empleado.h"
#include <cstdlib>

empleado::empleado(string name, string lastname, fecha hired, fecha birth)
{
 nombre = name;
 apellido = lastname;
 fechaContratacion = hired;
 fechaNacimiento = birth;
}

void empleado::imprimir()
{
    cout<<nombre<<","<<apellido<<endl;
    cout<<"Contratado el: ";
    fechaContratacion.imprimir();
    cout<<"Fecha de nacimiento: ";
    fechaNacimiento.imprimir();
    cout<<endl;
}

