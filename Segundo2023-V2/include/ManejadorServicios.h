#ifndef MANEJADORSERVICIOS_H
#define MANEJADORSERVICIOS_H
#include <vector>
#include <cstdint>
#include <ostream>
#include <fstream>
#include <algorithm>
#include "TrabajoPintura.h"
#include "RevisionAlarma.h"
#include <sstream>

using namespace std;
class ManejadorServicios
{
    public:
        ManejadorServicios();
        virtual ~ManejadorServicios();

        void imprimirTrabajos(ostream& os = cout);
        double facturacionTotal();
        double montoSueldos();
        void AgregarServicio(Servicio*);
        Servicio* GetServicio(uint8_t);
        void OrdenarFecha();
        void OrdenarNombresDecrecientes();
        void RecuperarServicios_bin(const char* file_name);

    protected:

    private:
        vector<Servicio*>Trabajos;
};

bool cmp_fecha(Servicio*,Servicio*);
bool cmp_nombres(Servicio*,Servicio*);
long long unsigned int fileSize(const char*);
#endif // MANEJADORSERVICIOS_H
