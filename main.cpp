#include <iostream>
#include <map>
#include <algorithm>
#include "myException.h"
#include "CMaritimo.h"
#include "CTerrestre.h"
#include "persona.h"

template <class K, class V> void vPrintMap(map<K, V> &, ostream&);
template <class K, class V> void vPrintMap(map<K, V> &, string);

template <class K, class V> void vPrintMap(map<K, V> &mapa, ostream& co)
{
    typename map<K, V>::iterator ForIter;

    ForIter = mapa.begin();                       // puntero al primer elemento
    co << endl;
    while (ForIter != mapa.end() )                // mientras no sea el último elemento
    {
        co << ForIter->second << endl;
        ForIter++;                              // aumento el iterador
    }
    co << "\n\n";
}

template <class K, class V> void vPrintMap(map<K, V> &mapa, string nombre)
{
 typename map<K, V>::iterator ForIter;

    ofstream fs(nombre, ios::out);
    if( !fs.good() )
        throw myException(1);                    // se produce un error en el archivo destino

    ForIter = mapa.begin();                       // puntero al primer elemento
    fs << endl;
    while (ForIter != mapa.end() )                // mientras no sea el último elemento
    {
        fs << ForIter->second << endl;
        ForIter++;                              // aumento el iterador
    }
    fs << "\n\n";
    fs.close();
}

using namespace std;

int main()
{
    map<string, CTransporte *> mapMoviles;
    map<int, persona *> mapPersonas;

    CMaritimo *CMBarco = new CMaritimo();
    CMaritimo *CMVelero = new CMaritimo("CZX023", "Esperanza", 0x7000FF, 5);
    CTerrestre *CTAuto = new CTerrestre();

    mapMoviles.insert(pair<string, CTransporte*>(CMVelero->GetMatricula(), CMVelero));
    // declarando las clases derivadas se pueden usar los getters y setters //

    CMBarco->SetPasajeros(500);
    CMBarco->SetMatricula("AUB734");
    CMBarco->SetNombre("Titanic");
    CTAuto->SetMatricula("AA769DB");
    CTAuto->SetVelocidad(197.8);
    CTAuto->SetColor(0x050FF0FF);
    CMBarco->SetColor(CTAuto->GetColor());

    mapMoviles.insert(pair<string, CTransporte*>(CMBarco->GetMatricula(), CMBarco));
    mapMoviles.insert(pair<string, CTransporte*>(CTAuto->GetMatricula(), CTAuto));

    CTerrestre *CTMoto = new CTerrestre();
    CTMoto->SetMatricula("007XYZ");
    CTMoto->SetVelocidad(87.5);
    CTMoto->SetRed(225);
    CTMoto->SetGreen(0);
    CTMoto->SetBlue(105);
    CTMoto->SetRuedas(2);
    CTMoto->SetMarca("Honda");

    mapMoviles.insert(pair<string, CTransporte*>(CTMoto->GetMatricula(), CTMoto));
    vPrintMap(mapMoviles, cout);
    vPrintMap(mapMoviles, "prueba_moviles.txt");

    persona *Roberto = new persona("Roberto", 12516857, fecha(26, 10)),
    *Pedro = new persona(),
    *Pablo = new persona("Pablo", 92736675, fecha(25, 10, 1980));

    mapPersonas.insert(pair<int, persona*>(Roberto->GetDocument(), Roberto));
    mapPersonas.insert(pair<int, persona*>(Pedro->GetDocument(), Pedro));
    mapPersonas.insert(pair<int, persona*>(Pablo->GetDocument(), Pablo));

    vPrintMap(mapPersonas, cout);
    try
    {
        vPrintMap(mapPersonas, "prueba_personas.txt");
    }
    catch(const char*){}
    return 0;
}
