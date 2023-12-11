#include "cVector.h"
#include <cmath>
#include <stdexcept>

vector::vector()
{
    elems_ = new TYPE_[initial_capacity_];
    size_ = 0;
    capacity_ = initial_capacity_;
}

vector::vector(vector &orig)
{
    capacity_ = orig.capacity_;
    size_ = orig.size_;
    elems_ = new TYPE_[capacity_];

    for (size_t i = 0; i < size_; i++)
    {
        elems_[i] = orig.elems_[i];
    }
}

void vector::free_()
{
    delete[] elems_;
}

vector::~vector()
{
    free_();
}

TYPE_ &vector::at(const size_t pos)
{
    if (pos < size_)
    {
        return elems_[pos];
    }
    else
    {
        throw std::out_of_range("pos fuera de rango");
    }
}

TYPE_ &vector::operator[](const size_t pos)
{
    return at(pos);
}

bool vector::empty() const
{
    return (size_ == 0);
}

size_t vector::size() const
{
    return size_;
}

void vector::reserve(const size_t new_cap)
{
    if (new_cap > capacity_)
    {
        realloc_(new_cap);
    }
}

void vector::realloc_(const size_t new_cap)
{
    /* NOTA: No comprueba que new_cap > capacity_ */

    /* Probablemente seria mas eficiente usar memcpy, para no tener que
    llamar a los constructores de copia de cada elemento */

    /* Reservo memoria */
    TYPE_ *temp = new TYPE_[new_cap];

    /* Copio todos los elementos del vector al nuevo array */
    for (size_t i = 0; i < size_; i++)
    {
        temp[i] = elems_[i];
    }

    /* Elimino el array viejo, asigno el array temporal elems_ y
    establezco la nueva capacidad del vector */
    free_();
    elems_ = temp;
    capacity_ = new_cap;
}

size_t vector::capacity() const
{
    return capacity_;
}

void vector::clear()
{
    free_();
    elems_ = new TYPE_[capacity_];
    size_ = 0;
}

void vector::realloc_if_necessary()
{
    if (full())
    {
        realloc_(capacity_ * 2);
    }
}

void vector::insert(const size_t pos, TYPE_ &value)
{
    realloc_if_necessary();

    if (pos < size_)
    {
        /* Muevo todos los valores a la derecha */
        for (size_t i = size_; i > pos; i--)
        {
            elems_[i] = elems_[i - 1];
        }

        /* Escribo el valor en la posicion indicada */
        elems_[pos] = value;
        size_++;
    }
    else
    {
        push_back(value);
    }
}

bool vector::full() const
{
    return (size_ == capacity_);
}

/*void vector::erase(const size_t pos)
{
    if (pos < size_)
    {
        // Muevo todos los elementos hacia la izquierda
        for (size_t i = pos; i < size_ - 1; i++)
        {
            elems_[i] = elems_[i + 1];
        }

        // Elimino el ultimo elemento
        pop_back();
    }
}*/

void vector::erase(const size_t pos)
{
    if (pos < size_)
    {
        /* toma el último elemento del arreglo elems_ y lo coloca en la posición pos, luego decrementa el tamaño del vector */
       elems_[pos] = elems_[size_ - 1];

        /* Elimino el ultimo elemento */
        pop_back();
    }
}

void vector::push_back(TYPE_ &value)
{
    realloc_if_necessary();

    elems_[size_++] = value;
}

void vector::pop_back()
{
    if (size_ > 0)
    {
        size_--;
    }
}

void vector::resize(const size_t count)
{
    if (size_ < count)
    {
        realloc_(count);
    }

    capacity_ = count;
    size_ = std::min(count, size_);
}


