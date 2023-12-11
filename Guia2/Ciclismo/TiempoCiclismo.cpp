#include "TiempoCiclismo.h"

tiempo::tiempo()
{
    //ingresarDatos();
    hora = 0;
    minutos = 0;
    segundos = 0;
}

void tiempo::setHora(uint16_t hh)
{
    hora = hh;
}
void tiempo::setMinutos(uint16_t mm)
{
    minutos = mm;
}
void tiempo::setSegundos(uint16_t ss)
{
    segundos = ss;
}
uint16_t tiempo::getHora()
{
    return(hora);
}
uint16_t tiempo::getMinutos()
{
    return(minutos);
}
uint16_t tiempo::getSegundos()
{
    return(segundos);
}

void tiempo::setDatos(uint16_t hh,uint16_t mm, uint16_t ss)
{
    setHora(hh);
    setMinutos(mm);
    setSegundos(ss);
}

void tiempo::ingresarDatos()
{
    uint16_t hh=0,mm=0,ss=0;

    cout<<"Ingrese el tiempo\n"<<endl;
    cout<<"hora: "<<endl; cin>>hh;
    cout<<"\nminutos: "<<endl; cin>>mm;
    cout<<"\nsegundos: "<<endl; cin>>ss;
    setDatos(hh,mm,ss);
}

void tiempo::muestra_fmt_estandar()
{
    cout<<setw(2)<<setfill('0')<<hora<<":"<<setw(2)<<setfill('0')<<minutos<<":"<<setw(2)<<setfill('0')<<segundos;
}

tiempo tiempo::tiempo_Prueba() /***PREGUNTAR SI SE PUEDE HACER POR REFERENCIA DESDE CICLISTA**/
{
    tiempo Prueba;
    uint16_t mm=0,ss=0;

    srand(time(NULL)+rand());
    mm = rand()% 15 + 40 ;
    ss = rand() % 60;

    Prueba.setDatos(0,mm,ss);
    return(Prueba);
}



