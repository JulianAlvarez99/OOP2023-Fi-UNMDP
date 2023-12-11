#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H
#include <iostream>
#include <fstream>

using namespace std;

class myException : public exception                 // derivo de la clase exception
{
    public:
        myException(int mot) : exception(), motivo(mot) {}
        const char* what() const throw();           // sobrescribo el método what(), que es virtual
    private:
        int motivo;                                 // código del error
    protected:
};


#endif // MYEXCEPTION_H
