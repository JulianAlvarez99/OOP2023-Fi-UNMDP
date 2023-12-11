#include "Fecha.h"

Fecha::Fecha(int d, int m, int a)
{
    Day = d;
    Month = m;
    Year = a;
}

ostream& operator<<(ostream &s, const Fecha &f)
{
    s<<f.Day<<"/"<<f.Month<<"/"<<f.Year<<endl;
    return(s);
}

void Mostrar_TiempoFecha()
{
   time_t t = time(nullptr);
   tm* now = localtime(&t);

   cout << "Current Date: " << now->tm_mday << '/' << (now->tm_mon + 1) << '/'
        << (now->tm_year + 1900) << endl;
}
