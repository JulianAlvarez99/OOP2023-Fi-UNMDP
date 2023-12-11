#ifndef VEHICULO_H_INCLUDED
#define VEHICULO_H_INCLUDED
#include <iostream>
#include <cstring>

using namespace std;
/*
typedef struct t_vehiculo
{
    char* marca;
    int puertas;
    long km;
    int cilindrada;
}vehiculo_t;

char* getMarca();
void setMarca(char*);
void setPuertas(int);
int getPuerta();
void setKm(long);
long getKm();
void setCilindrada(int);
int getCilindrada();


vehiculo_t* crearVehiculo();
void destruirVehiculo(vehiculo_t*);
int vehiculo_Acelerar();
int vehiculo_Frenar();
int vehiculo_Prender();
int vehiculo_Apagar();*/

class vehiculo
{
public:
//CONSTRUCTOR
    vehiculo(const char *,const char *,const char *, int, float, int, long);
//DESTRUCTOR
    ~vehiculo();
//METODOS
//setters
    void setMarca(const char*);
    void setPatente(const char*);
    void setModelo(const char*);
    void setPuertas(int);
    void setCilindrada(float);
    void setLinea(int);
    void setKm(long);
//getters
    string getMarca();
    string getPatente();
    string getModelo();
    int getPuertas();
    float getCilindrada();
    int getLinea();
    long getKm();

//Funciones
    int vehiculo_Acelerar(int);
    int vehiculo_Frenar(int);
    int vehiculo_Prender(int);
    int vehiculo_Apagar(int);

    static float valor_patente;

//VARIABLES MIEMBRO
private:
    char *marca, *patente, *modelo;
    int puertas,linea;
    float cilindrada;
    long km;
};


#endif // VEHICULO_H_INCLUDED
