#include "TrabajoPintura.h"

TrabajoPintura::TrabajoPintura(double sup, double precio)
{
    this->Superficie = sup;
    this->PrecioPintura = precio;
}

TrabajoPintura::~TrabajoPintura()
{
    //dtor
}
void TrabajoPintura::SetSuperficie(double sup)
{
    this->Superficie = sup;
}
void TrabajoPintura::SetPrecioPintura(double precio)
{
    this->PrecioPintura = precio;
}
double TrabajoPintura::GetSuperficie()
{
    return(this->Superficie);
}
double TrabajoPintura::GetPrecioPintura()
{
    return(this->PrecioPintura);
}

double TrabajoPintura::costoMaterial()
{
    double Valor = 0.0;

    Valor = ((this->Superficie)/7.8) * this->PrecioPintura;
    return Valor;
}
double TrabajoPintura::costoManoObra()
{
    double Valor = 0.0;

    Valor = ((this->Superficie)/10.0) * 9.5;
    return Valor;
}

double TrabajoPintura::costoTotal()
{
    return(this->costoMaterial()+this->costoManoObra());
}
void TrabajoPintura::detalleServicio(ostream& os)
{
    double CostoAdicional = 0.0;
   os<<"TRABAJO DE PINTURA"<<endl;
   os<<"    Cliente: "<<this->Cliente.GetName()
     <<"\n    Fecha de inicio: "<<this->InicioServicio
     <<"\n    Pintor: "<<this->Trabajador.GetName()
     <<"\n    Costo Materiales: $ "<<this->costoMaterial()
     <<"\n    Costo Mano Obra: $ "<<this->costoManoObra();

   if(this->Superficie < 50)
   {
       CostoAdicional = this->costoTotal()*0.15;
       os<<"\n    Costo Adicional: $ "<<CostoAdicional;
   }
   else
   {
     os<<"\n    Costo Adicional: $ "<<CostoAdicional;
   }
   os<<"\n    Costo Total: $ "<< this->costoTotal() + CostoAdicional<<endl;
}
