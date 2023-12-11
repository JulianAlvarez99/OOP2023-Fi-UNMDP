#include "ManejadorServicios.h"

ManejadorServicios::ManejadorServicios()
{
    //ctor
}

ManejadorServicios::~ManejadorServicios()
{
    //dtor
}

void ManejadorServicios::AgregarServicio(Servicio* ser)
{
    Trabajos.push_back(ser);
}

Servicio* ManejadorServicios::GetServicio(uint8_t index)
{
    return(Trabajos.at(index));
}

bool cmp_fecha(Servicio* ser_1,Servicio* ser_2)
{
    return(ser_1->GetInicioServicio() < ser_2->GetInicioServicio());
}

bool cmp_nombres(Servicio* ser_1,Servicio* ser_2)
{
    return(ser_1->GetCliente().GetName() > ser_2->GetCliente().GetName());
}

void ManejadorServicios::OrdenarFecha()
{
    sort(Trabajos.begin(),Trabajos.end(),cmp_fecha);
}

void ManejadorServicios::OrdenarNombresDecrecientes()
{
    sort(Trabajos.begin(),Trabajos.end(),cmp_nombres);
}

double ManejadorServicios::facturacionTotal()
{
    double Valor = 0.0;

    for(unsigned int i = 0; i<Trabajos.size(); i++)
    {
        Valor += Trabajos[i]->costoTotal();
    }
    return Valor;
}
double ManejadorServicios::montoSueldos()
{
    double Valor = 0.0;

    for(unsigned int i = 0; i<Trabajos.size(); i++)
    {
        Valor += Trabajos[i]->costoManoObra();
    }
    return Valor;
}

long long unsigned int fileSize(const char* fname)
{
   ifstream file(fname,ios::binary);
   file.seekg(0, ios::end);
   long long unsigned int size = file.tellg();
   file.close();
   return size;
}

void ManejadorServicios::RecuperarServicios_bin(const char* file_name)
{
    std::fstream in;
    in.exceptions ( fstream::badbit );
    try
    {
        in.open(file_name, ios::in|ios::binary);
        unsigned int file_size = fileSize(file_name);
        int CantTrabajos = 0;
        int TipoTrabajo = 0;
        string nombre;
        int dia_in = 0, mes_in = 0, anio_in = 0,
            dia_serv = 0, mes_serv = 0, anio_serv = 0;
        int identificacion = 0;
        float sup = 0.0, precio = 0.0;
        int alarmas = 0;
        int len = 0;

        in.read((char*)&(CantTrabajos),sizeof(CantTrabajos));
        while(in.tellg()<file_size)
        {
            in.read((char*)&(TipoTrabajo),sizeof(TipoTrabajo));

            if (TipoTrabajo == 1962)
            {
                TrabajoPintura* aux = new TrabajoPintura();

                in.read((char*)&len,sizeof(len));
                char* temp = new char[len+1];
                in.read(temp,len);
                temp[len] = '\0';
                nombre = temp;
                delete [] temp;

                aux->GetTrabajador().SetName(nombre);

                in.read((char*)&(dia_in),sizeof(dia_in));
                in.read((char*)&(mes_in),sizeof(mes_in));
                in.read((char*)&(anio_in),sizeof(anio_in));

                aux->GetTrabajador().SetBirthDate(dia_in,mes_in,anio_in);

                in.read((char*)&(identificacion),sizeof(identificacion));

                aux->GetTrabajador().SetDocument(identificacion);

                in.read((char*)&(dia_serv),sizeof(dia_serv));
                in.read((char*)&(mes_serv),sizeof(mes_serv));
                in.read((char*)&(anio_serv),sizeof(anio_serv));

                aux->GetInicioServicio().SetDay(dia_serv);
                aux->GetInicioServicio().SetMonth(mes_serv);
                aux->GetInicioServicio().SetYear(anio_serv);

                in.read((char*)&len,sizeof(len));
                temp = new char[len+1];
                in.read(temp,len);
                temp[len] = '\0';
                nombre = temp;
                delete [] temp;

                aux->GetCliente().SetName(nombre);

                in.read((char*)&(identificacion),sizeof(identificacion));
                aux->GetCliente().SetDocument(identificacion);

                in.read((char*)&(sup),sizeof(sup));
                in.read((char*)&(precio),sizeof(precio));

                aux->SetSuperficie(sup);
                aux->SetPrecioPintura(precio);

                Trabajos.push_back(aux);
            }
            if (TipoTrabajo == 341)
            {
                RevisionAlarma* aux = new RevisionAlarma();

                in.read((char*)&(dia_serv),sizeof(dia_serv));
                in.read((char*)&(mes_serv),sizeof(mes_serv));
                in.read((char*)&(anio_serv),sizeof(anio_serv));

                aux->GetInicioServicio().SetDay(dia_serv);
                aux->GetInicioServicio().SetMonth(mes_serv);
                aux->GetInicioServicio().SetYear(anio_serv);

                in.read((char*)&len,sizeof(len));
                char* temp = new char[len+1];
                in.read(temp,len);
                temp[len] = '\0';
                nombre = temp;
                delete [] temp;

                aux->GetCliente().SetName(nombre);

                in.read((char*)&(identificacion),sizeof(identificacion));
                aux->GetCliente().SetDocument(identificacion);

                in.read((char*)&(alarmas),sizeof(alarmas));
                aux->SetCantAlarmas(alarmas);

                Trabajos.push_back(aux);
            }
            CantTrabajos--;
        }
    }
    catch(const ifstream::failure& e)
    {
        cout << "Excepcion al abrir/leer el archivo\n";
    }
    in.close();
}

void ManejadorServicios::imprimirTrabajos(ostream& os)
{
    vector<Servicio*>::iterator ForIter;
    ForIter = Trabajos.begin();                        // puntero al primer elemento
    os << endl;
    while (ForIter != Trabajos.end() )                 // mientras no sea el ultimo elemento
    {
        (*ForIter)->detalleServicio(os);
        os<<endl;
        ForIter++;              // aumento el iterador
    }
    os << "\n\n";
}
