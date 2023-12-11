#include "persona.h"

persona::persona()
{
    this->nombre_ = "";
    this->DNI_= "";
    this->cuil_ = "";
}
persona::persona(string name ,fecha nac,string documento ,string nrocuil)
{
    this->nombre_ = name;
    this->nacimiento_ = nac;
    this->DNI_= documento;
    this->cuil_ = nrocuil;
}

persona::~persona()
{
    //dtor
}
