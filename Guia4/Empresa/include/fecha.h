#ifndef FECHA_H
#define FECHA_H
#include <iostream>

using namespace std;

class fecha
{
private:
protected:

public:
    int day_;
    int month_;
    int year_;

    fecha(const int d = 1, const int m = 1, const int a = 1970);
    virtual ~fecha();

    friend ostream &operator<<(ostream &s, const fecha &f);

};


#endif // FECHA_H
