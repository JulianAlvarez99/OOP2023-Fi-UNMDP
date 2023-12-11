#include "CFecha.h"
#include <ctime>

CFecha::CFecha()
{
    time_t t = time(0);   // get time now
    struct tm * now = localtime( & t );
    Day = now->tm_mday;
    Month = (now->tm_mon + 1);
    Year = (now->tm_year + 1900);  // No hace falta validar porque es la fecha actual
}

CFecha::CFecha(unsigned int d, unsigned int m, unsigned int a)
{
    SetYear(a);
    SetMonth(m);
    SetDay(d);
}

unsigned int CFecha::GetDay() const
{
    return Day;
}

bool CFecha::SetDay(unsigned int d)
{
    bool cond = false;
    /*    unsigned int y = GetYear(),
                     m = GetMonth();

        try
        {
            if( ( (m==1)||(m==3)||(m==5)||(m==7)||(m==8)||(m==10)||(m==12) ) && (d > 31) )
            {
                throw("El mes tiene solamente 31 dias, intente nuevamente\nDia: ");
            }
            if( ( (m==4)||(m==6)||(m==9)||(m==11) ) && (d > 30) )
            {
                throw("El mes tiene solamente 30 dias, intente nuevamente\nDia: ");
            }
            if( m==2 )
            {
                if( (y%4) && (d>28) )
                    throw("El mes tiene solamente 28 dias, intente nuevamente\nDia: ");
                if( (!(y%4)) && (d>29) )
                    throw("El mes tiene solamente 29 dias, intente nuevamente\nDia: ");
            }
            if( (y == CFecha().GetYear()) && (m == CFecha().GetMonth()) && (d > CFecha().GetDay()) )
            {
                throw("El dia es mayor que la fecha actual, intente nuevamente\nDia: ");
            }
        }
        catch(const char *codigo)
        {
            cout << codigo;
            cin >> d;
            if(!cond)
            {
                cond = SetDay(d);
                return cond;
            }
        }
    */
    Day = d;
    cond = true;

    return cond;
}

unsigned int CFecha::GetMonth() const
{
    return Month;
}

bool CFecha::SetMonth(unsigned int m)
{
    bool cond = false;

    try
    {
        if(m>12)
        {
            throw("El mes es mayor que 12, intente nuevamente\nMes: ");
        }
        if( (GetYear() == CFecha().GetYear()) && (m > CFecha().GetMonth()) )
        {
            throw("El mes es mayor que el mes actual, intente nuevamente\nMes: ");
        }
    }
    catch(const char *codigo)
    {
        cout << codigo;
        cin >> m;
        if(!cond)
        {
            cond = SetMonth(m);
            return cond;
        }
    }

    Month = m;
    cond = true;

    return cond;
}

unsigned int CFecha::GetYear() const
{
    return Year;
};

bool CFecha::SetYear(unsigned int y)
{
    bool cond = false;

    try
    {
        if(y > CFecha().GetYear())
        {
            throw ("El año es mayor que el actual, intente nuevamente\nAño: ");
        }
        if(y < 1920)
        {
            throw ("El año es muy antiguo, intente nuevamente\nAño: ");
        }
    }
    catch(const char *codigo)
    {
        cout << codigo;
        cin >> y;
        if(!cond)
        {
            cond = SetYear(y);
            return cond;
        }
    }

    Year = y;
    cond = true;

    return cond;
}

ostream& operator << (ostream& co, CFecha& fecha)
{
    co.fill('0');
    co.width(2);
    co <<right<< fecha.GetDay() << '/';
    co.fill('0');
    co.width(2);
    co <<right<< fecha.GetMonth() << '/'
       <<right<< fecha.GetYear();

    return co;
}

bool CFecha::operator< (const CFecha fecha) const
{
    bool cond = false;

    if( this->GetYear() < fecha.GetYear() )
        cond = true;
    else if( GetYear() > fecha.GetYear() )
        cond = false;
    else                                // los años son iguales
        if( GetMonth() < fecha.GetMonth() )
            cond = true;
        else if( GetMonth() > fecha.GetMonth() )
            cond = false;
        else                                // los años y los meses son iguales
            if( GetDay() < fecha.GetDay() )
                cond = true;
            else
                cond = false;

    return cond;
}
