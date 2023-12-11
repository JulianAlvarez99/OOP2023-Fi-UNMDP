#include "CAdministrativo.h"
#include "CGerenteVentas.h"

int main()
{
    ofstream fout("planillaEmpleados.txt",ios::out);

    CAdministrativo jefe;

    jefe.SetName("Roberto Hidalgo");
    jefe.SetDocument(12516857);
    jefe.SetBirthDate(29,1,1959);
    jefe.SetStatus(Casado);
    jefe.SetEmployed(1,1,1980);
    jefe.SetSalary(95000.00);
    cout<<jefe<<endl;
    fout<<jefe<<endl;

    CVendedor vendedor("Jose Perez", 17871415);
    CFecha hoy;
    float plata;

    vendedor.SetBirthDate(CFecha(17,10,1965));
    vendedor.SetStatus(Soltero);
    vendedor.SetEmployed(2,5,2017);
    vendedor.SetPaymentDate(hoy);
    plata = vendedor.GetPaymentDate() * 2500.65;
    vendedor.SetComision(plata);
    cout<<vendedor<<endl;
    fout<<vendedor<<endl;

    CGerenteVentas gerente("Marcelo Suarez", 23212658, CFecha(25,6,1985));
    gerente.CVendedor::SetStatus(Casado);
    gerente.CVendedor::SetEmployed(25,3,2018);
    gerente.SetPaymentDate(15,9,2019);
    plata = gerente.GetPaymentDate() * 2500.65;
    gerente.SetComision(plata);
    gerente.SetAdmPayment(95000.00);
    plata = gerente.GetComision() + gerente.GetAdmPayment();
    gerente.SetSalary(plata);
    cout<<gerente<<endl;
    fout<<gerente<<endl;

    fout.close();

   /** toda la informacion mostrada en pantalla debe persistirse en un archivo de texto**/

    return 0;
}
