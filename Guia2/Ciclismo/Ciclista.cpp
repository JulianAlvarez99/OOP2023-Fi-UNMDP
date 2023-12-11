#include "Ciclista.h"

ciclista::ciclista()
{
    nombre = "";
    apellido = "";
}
ciclista::ciclista(string name, string lastname, fecha birth)
{
 nombre = name;
 apellido = lastname;
 fechaNacimiento = birth;
}
string ciclista::getNombre()
{
    return(nombre);
}

string ciclista::getApellido()
{
    return(apellido);
}

void ciclista::imprimir()
{
    cout<<apellido<<" "<<nombre<<"\t"<<fechaNacimiento.fechaEdad()<<"\t";
    tiempoPrueba.muestra_fmt_estandar();
    cout<<"\t\t"<<nroVueltas;
}

void ciclista::PrimeraPrueba()
{
    tiempo Prueba;

    tiempoPrueba = Prueba.tiempo_Prueba();
}
void ciclista::numeroVueltas()
{
    srand(time(NULL)+rand());//Sumo un aleatorio al setear la seed para que no me de siempre el mismo valor aleatorio por pertener a la misma seed
    nroVueltas = rand() % 11 + 25;
}

tiempo ciclista::getTiempoPrueba()
{
return(tiempoPrueba);
}
uint16_t ciclista::getNroVueltas()
{
return(nroVueltas);
}


tiempo tiempoMinimo(tiempo* tabla,uint16_t numClts)
{
    tiempo minimo = tabla[0];
    for(int i=1;i<numClts;i++)
    {
        if(minimo.getMinutos()>tabla[i].getMinutos())
        {
            minimo = tabla[i];
        }
        else if(minimo.getMinutos() == tabla[i].getMinutos())
        {
            if(minimo.getSegundos()>tabla[i].getSegundos())
            {
                minimo = tabla[i];
            }
        }
    }
    return(minimo);
}

void difTiempo(tiempo clts, tiempo minimo)
{
    tiempo dif;
    uint16_t mm,ss;

    mm = clts.getMinutos()-minimo.getMinutos();
    ss = abs(clts.getSegundos()-minimo.getSegundos());

    dif.setDatos(0,mm,ss);
    cout<<"\t\t";
    dif.muestra_fmt_estandar();
}

void difVuelta(uint16_t mejorV, uint16_t vueltaClts)
{
    cout<<"\t\t"<<mejorV-vueltaClts<<endl;
}


tiempo* tablaTiempos(ciclista* clts[], uint16_t numClts)
{
    tiempo* tabla = new tiempo[numClts];
    tiempo minimo;

    for(int i=0; i<numClts;i++)
    {
        tabla[i]=clts[i]->getTiempoPrueba();
    }

    minimo = tiempoMinimo(tabla,numClts);

    for(int j=0; j<numClts; j++)
    {
        if((minimo.getMinutos() == tabla[j].getMinutos()) && (minimo.getSegundos() == tabla[j].getSegundos()))
           {
               cout<<"Ciclista mas rapido de la primera prueba: "<<clts[j]->getApellido()<<", "<<clts[j]->getNombre()<< "\t\tTiempo: ";
               minimo.muestra_fmt_estandar();
               cout<<"\n"<<endl;
           }
    }
    return(tabla);
}

uint16_t mejorVuelta(ciclista* clts[],uint16_t numClts)
{
    uint16_t vuelta = clts[0]->getNroVueltas();
    int i = 0;

    for(int j=1; j<numClts; j++)
    {
        if(vuelta<clts[j]->getNroVueltas())
           {
               vuelta = clts[j]->getNroVueltas();
               i=j;
           }
    }
    cout<<"Ciclista con mas vueltas en la segunda prueba: "<<clts[i]->getApellido();
    cout<<", "<<clts[i]->getNombre()<< "\t\tVueltas: "<<vuelta<<endl;
    cout<<"\n"<<endl;
    return(vuelta);
}



