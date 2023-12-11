#include "Vehiculo.h"

/**CONSTRUCTOR**/
vehiculo::vehiculo(const char *brand,const char *plate,const char *model, int doors, float cv, int line, long kilometers)
{
    setMarca(brand);
    setPatente(plate);
    setModelo(model);
    setPuertas(doors);
    setCilindrada(cv);
    setLinea(line);
    setKm(kilometers);
}
/**DESTRUCTOR**/
vehiculo::~vehiculo()
{
    delete [] marca;
    delete [] patente;
    delete [] modelo;
}

/**SETTERS**/
void vehiculo::setMarca(const char* brand)
{
    marca = new char[strlen(brand)+1];
    strcpy(marca,brand);
}
void vehiculo::setPatente(const char* plate)
{
    patente = new char[strlen(plate)+1];
    strcpy(patente,plate);
}
void vehiculo::setModelo(const char* model)
{
    modelo = new char[strlen(model)+1];
    strcpy(modelo,model);
}
void vehiculo::setLinea(int line)
{
    linea = line;
}
void vehiculo::setPuertas(int doors)
{
    puertas = doors;
}
void vehiculo::setKm(long kilometraje)
{
    km = kilometraje;
}
void vehiculo::setCilindrada(float cv)
{
    cilindrada = cv;
}
/**GETTERS**/
string vehiculo::getMarca()
{
    return(marca);
}
string vehiculo::getPatente()
{
    return(patente);
}
string vehiculo::getModelo()
{
    return(modelo);
}
int vehiculo::getPuertas()
{
    return(puertas);
}
int vehiculo::getLinea()
{
    return(linea);
}
long vehiculo::getKm()
{
    return(km);
}
float vehiculo::getCilindrada()
{
    return(cilindrada);
}

int vehiculo_Acelerar(int status)
{
    int result = 0;

    if(status==1)
    {
        cout<<"El vehiculo esta acelerando\n"<<endl;
        result = 1;
    }
    else
    {
        cout<<"El vehiculo esta apagado\n"<<endl;
    }
    return(result);
}
int vehiculo_Frenar(int status)
{
    int result = 0;

    if(status==1)
    {
        cout<<"El vehiculo esta frenado\n"<<endl;
        result = 1;
    }
    else
    {
        cout<<"El vehiculo esta apagado\n"<<endl;
    }
    return(result);
}
int vehiculo_Prender(int status)
{
    if(status == 0)
    {
        status = 1;
        cout<<"El vehiculo se ha encendido\n"<<endl;
    }
    else
        cout<<"El vehiculo ya estaba encedido\n"<<endl;
    return(status);
}
int vehiculo_Apagar(int status)
{
    if(status != 0)
    {
        status = 0;
        cout<<"El vehiculo se ha apagado\n"<<endl;
    }
    else
        cout<<"El vehiculo ya estaba apagado\n"<<endl;

    return(status);
}
