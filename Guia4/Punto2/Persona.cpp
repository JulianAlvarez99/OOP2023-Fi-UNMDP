#include "Persona.h"

oop::Persona::Persona(const std::string &name, const unsigned int &num,
                      const Fecha &fecha)
{
    Name_ = name;
    Document_ = num;
    BirthDate_ = fecha;
}

oop::Persona::~Persona() {}

void oop::Persona::SetName(const std::string &nom)
{
    Name_ = nom;
}

bool oop::Persona::SetDocument(const unsigned int &doc)
{
    bool result = false;

    if (Document_ != doc)
    {
        Document_ = doc;
        result = true;
    }

    return result;
}

bool oop::Persona::SetBirthDate(const Fecha &date)
{
    BirthDate_ = date;
    return true;
}

bool oop::Persona::SetBirthDate(const int dd, const int mm, const int aa)
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

std::string oop::Persona::GetName() const
{
    return Name_;
}

unsigned int oop::Persona::GetDocument() const
{
    return Document_;
}

oop::Fecha oop::Persona::GetBirthDate() const
{
    return BirthDate_;
}

std::ostream &oop::operator<<(std::ostream &os, const oop::Persona &per)
{
    return (os << per.Name_);
}
