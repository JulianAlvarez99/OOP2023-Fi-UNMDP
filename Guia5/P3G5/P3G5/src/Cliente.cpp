#include "Cliente.h"

Cliente::Cliente(const string &name, const unsigned int &num, const Fecha &fecha)
{
    Name_ = name;
    Document_ = num;
    BirthDate_ = fecha;
}

Cliente::Cliente(Cliente& original)
{
    this->Name_ = original.Name_;
    this->Document_ = original.Document_;
    this->BirthDate_ = original.BirthDate_;
}

Cliente::~Cliente() {}

void Cliente::SetName(const string &nom)
{
    Name_ = nom;
}

bool Cliente::SetDocument(const unsigned int &doc)
{
    bool result = false;

    if (Document_ != doc)
    {
        Document_ = doc;
        result = true;
    }

    return result;
}

bool Cliente::SetBirthDate(const Fecha &date)
{
    BirthDate_ = date;
    return true;
}

bool Cliente::SetBirthDate(const int dd, const int mm, const int aa)
{
    bool result = false;
    Fecha fecha(dd, mm, aa);

    if (fecha.Day == dd && fecha.Month == mm && fecha.Year == aa)
    {
        BirthDate_ = fecha;
        result = true;
    }

    return result;
}

string Cliente::GetName() const
{
    return Name_;
}

unsigned int Cliente::GetDocument() const
{
    return Document_;
}

Fecha Cliente::GetBirthDate() const
{
    return BirthDate_;
}

ostream& operator<<(ostream &os, const Cliente &per)
{
    return (os << per.Name_);
}

