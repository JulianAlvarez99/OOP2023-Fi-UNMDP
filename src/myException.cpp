#include "myException.h"

const char* myException :: what() const throw()
{
   switch(motivo)
   {
       case 1:
           return "El Fichero no existe";
   }
   return "Error inesperado";
}
