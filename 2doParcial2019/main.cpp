#include "ManejadorFiguras.h"

using namespace std;
///Revisar como levanta archivo binario

int main()
{
    ManejadorFiguras mf;

    //mf.RecuperarFiguras_txt("SalidaPrueba.txt");
    mf.RecuperarFiguras_bin("prueba.bin");
    //mf.CargarFiguras();

    mf.ImprimirFiguras();

    cout << "Area total = " << mf.TotalArea() << endl;

    ofstream of;
    of.exceptions(ofstream::badbit);
    try
    {
    of.open("salida.txt");
    mf.Get(1)->SetValores(2.0); //cambio el valor del radio del circulo.

    mf.Ordenar();

    mf.ImprimirFiguras(of);

    of << "Area total = " << mf.TotalArea() << endl;
    }
    catch(const ofstream::failure& e)
    {
        cout<<"Excepcion al abrir/escribir el archivo"<<endl;
    }
    of.close();

    mf.GuardarFiguras_txt("SalidaPrueba.txt");
    //mf.GuardarFiguras_bin("prueba.bin");

    return 0;
}
