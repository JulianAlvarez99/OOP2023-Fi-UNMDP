#include "FechaClicismo.h"

fecha::fecha()
{
    //ingresarFecha();
    day = 0;
    month = 0;
    year = 0;
}

fecha::fecha(uint16_t dd,uint16_t mm,uint32_t yy)
{
    day = dd;
    month = mm;
    year = yy;
}

void fecha::setFecha(uint16_t dd,uint16_t mm,uint32_t yy)
{
    setDay(dd);
    setMonth(mm);
    setYear(yy);
}
void fecha::setDay(uint16_t dd)
{
    day=dd;
}
void fecha::setMonth(uint16_t mm)
{
    month=mm;
}
void fecha::setYear(uint32_t yy)
{
    year=yy;
}
void fecha::ingresarFecha()
{
    uint16_t dd,mm;
    uint32_t yy;

    cout<<"Ingrese el dia, mes y anio (Despues de cada valor presiona enter)\n"<<endl;
    cin>>dd>>mm>>yy;
    getc(stdin);
    fflush(stdin);
    setFecha(dd,mm,yy);
}
void fecha::imprimir_la()
{
    cout<<day<<"/"<<month<<"/"<<year<<endl;
}
void fecha::imprimir_us()
{
    cout<<month<<"/"<<day<<"/"<<year<<endl;
}


vector<uint32_t> fecha::intToArray(uint32_t number) //Utilizo clase vector y algorithm
{
    vector<uint32_t> cifras;

    while(number>0)
    {
        cifras.push_back(number%10); //inserto al final del vector el resto de number
        number = number/10;          //divido por 10 para quitar el digito insertado
    }

    reverse(cifras.begin(),cifras.end());   // doy vuelta el vector ya que incialmente se almacena al reves
    return(cifras);
}

string fecha::_numeroLetras(vector<uint32_t> num)
{
    const char* digito[] = {"","uno","dos","tres","cuatro","cinco","seis","siete","ocho","nueve"};
    const char* decimos[] = {"diez","once","doce","trece","catorce","quince","dieciseis","diecisiete","dieciocho","diecinueve"};
    const char* vigesimos[] = {"veinte","veintiuno","veintidos","veintitres","veinticuatro","veinticinco","veintiseis","veintisiete","veintiocho","veintinueve"};
    const char* decenas[] = {"NaN","NaN","NaN","treinta","cuarenta","cincuenta","sesenta","setenta","ochenta","noventa"};
    const char* centenas[] = {"","ciento","doscientos","trescientos","cuatrocientos","quinientos","seiscientos","sietecientos","ochocientos","novecientos"};
    const char* miles[] = {"NaN","mil","dos mil"};
    string word;
    uint32_t aux=0;

    if(num.size()==4)
    {
        aux = year;         /**UNA VEZ ALMACENADO EN EL STRING EL MILENIO Y SIGLO, ASIGNO LA DECADA A LAS 2 PRIMERAS POSICIONES DE NUM  **/
        if(num[0]==1)       /**PARA ESTANDARIZAR EL PROGRAMA ENTRE DIA Y AÑO**/
        {
            word = string(miles[num[0]])+ " " + string(centenas[num[1]])+" ";
            num[0]=num[2];
            num[1]=num[3];
        }
        else if (num[0]==2)
        {
            word = string(miles[num[0]])+ " " + string(centenas[num[1]])+" ";
            num[0]=num[2];
            num[1]=num[3];
        }
        else
        {
            cerr<<"Anio no valido\n";
        }
    }
    else
    {
        aux = day;
    }

     if(aux==10 || aux%100==10)
    {
        word+=decimos[0];
    }
    else if(aux==20 || aux%100==20)
    {
        word+=vigesimos[0];
    }
    else
    {
        switch(num[0])
        {
            case 0:
                word+=digito[num[1]];
                break;
            case 1:
                word+=decimos[num[1]];
                break;
            case 2:
                word+=vigesimos[num[1]];
                break;
            default:
                word+=string(decenas[num[0]]) + " y " + string(digito[num[1]]);
                break;
        }
    }
    return(word);
}

string fecha::numerosLetras()
{
    string dia,anio,date;
    vector<uint32_t> dd,yy;

    dd=intToArray(day);     //2 indices
    if(day<10)
    {
        dd.insert(dd.begin(),0); /**ACA CONSIDERO EL CASO CUANDO EL DIA ES MENOR A 10, LA FUNCION DE CONVERSION DE INTEGRER A VECTOR NO ME ALMACENABA EL 0**/
    }
    yy=intToArray(year);    //4 indices

    dia=_numeroLetras(dd);
    anio=_numeroLetras(yy);

    date = dia +" de " + mesLetras() + " de " + anio;

    return(date);
}

string fecha::mesLetras()
{
    const char* meses[] = {"NaN","Enero","Febrero","Marzo","Abril","Mayo","Junio","Julio","Agosto","Septiembre","Octubre","Noviembre","Diciembre"};
    return(meses[month]);
}

void fecha::imprimir_letras()
{
    string date;

    if(day*month*year == 0)
    {
        cerr<<"Fecha invalida\n";
    }
    else
    {
    date = numerosLetras();
    transform(date.begin(), date.end(), date.begin(), ::toupper); // llevo el string a mayusculas
    cout<<date<<"\n"<<endl;
    }
}
void fecha::imprimir()
{
    cout<<day<<" de "<<mesLetras()<<" de "<<year<<endl;

}
bool fecha::validarFecha()
{
    bool result;
    uint16_t check = 0;
    uint16_t max_day = 0;

    if(month>=1 && month<=12 && year>=0)
    {
        check=2;
        switch(month)
        {
        case  1 :
        case  3 :
        case  5 :
        case  7 :
        case  8 :
        case 10 :
        case 12 :
            max_day = 31;
            break;

        case  4 :
        case  6 :
        case  9 :
        case 11 :
            max_day = 30;
            break;

        case  2 :
            if (((year%4 == 0) && (year%100 != 0)) || (year%400 == 0))
                max_day = 29;
            else
                max_day = 28;
        }

        if (day >= 1 && day <= max_day)
            check++;
    }

    if(check == 3)
    {
        result = true;
    }
    else
        result = false;
    return result;
}

uint16_t fecha::fechaEdad() //USO LA LIBRERIA CTIME PARA OBTENER LA FECHA ACTUAL POR SISTEMA
{
    uint16_t edad = 0;
    time_t t = time(nullptr);
    tm* now = localtime(&t);

    edad =(now->tm_year + 1900) - year;
    if(month > now->tm_mon +1)
    {
        edad--;
    }
    else if (month == now->tm_mon +1)
    {
        if(day > now->tm_mday)
        {
            edad--;
        }
    }

    return(edad);
}



