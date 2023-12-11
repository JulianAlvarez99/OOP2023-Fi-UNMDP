#ifndef CLIENTE_H
#define CLIENTE_H
#include "Fecha.h"

using namespace std;

class Cliente
{
    public:
    Cliente(const string &name = "Pedro",
            const unsigned int &num = 123456789,
            const Fecha &fecha = Fecha());
    Cliente(Cliente&);
    virtual ~Cliente();

    void SetName(const string &nom);
    bool SetDocument(const unsigned int &doc);
    bool SetBirthDate(const Fecha &date);
    bool SetBirthDate(const int dd, const int mm, const int aa);

    string GetName() const;
    unsigned int GetDocument() const;
    Fecha GetBirthDate() const;

    friend ostream &operator<<(ostream &os, const Cliente &per);

protected:
    string Name_;
    unsigned int Document_;
    Fecha BirthDate_;
};

#endif // CLIENTE_H
