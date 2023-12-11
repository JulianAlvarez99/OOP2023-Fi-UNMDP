#include "cVector.h"
#include <cmath>
#include <stdexcept>

template <class CV>cvector<CV>::cvector()
{
    elems_ = new CV[initial_capacity_];
    size_ = 0;
    capacity_ = initial_capacity_;
}

template <class CV> void cvector<CV>::free_()
{
    delete[] elems_;
}

template <class CV> cvector<CV>::~cvector()
{
    free_();
}

template <class CV> CV &cvector<CV>::at(const size_t pos)
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

template <class CV>CV &cvector<CV>::operator[](const size_t pos)
{
    return at(pos);
}

template <class CV>bool cvector<CV>::empty() const
{
    return (size_ == 0);
}

template <class CV>size_t cvector<CV>::size() const
{
    return size_;
}

template <class CV>void cvector<CV>::reserve(const size_t new_cap)
{
    if (new_cap > capacity_)
    {
        realloc_(new_cap);
    }
}

template <class CV>void cvector<CV>::realloc_(const size_t new_cap)
{
    /* NOTA: No comprueba que new_cap > capacity_ */

    /* Probablemente seria mas eficiente usar memcpy, para no tener que
    llamar a los constructores de copia de cada elemento */

    /* Reservo memoria */
    CV *temp = new CV[new_cap];

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

template <class CV>size_t cvector<CV>::capacity() const
{
    return capacity_;
}

template <class CV>void cvector<CV>::clear()
{
    free_();
    elems_ = new CV[capacity_];
    size_ = 0;
}

template <class CV>void cvector<CV>::realloc_if_necessary()
{
    if (full())
    {
        realloc_(capacity_ * 2);
    }
}

template <class CV>void cvector<CV>::insert(const size_t pos, const CV &value)
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

template <class CV>bool cvector<CV>::full() const
{
    return (size_ == capacity_);
}

template <class CV>void cvector<CV>::erase(const size_t pos)
{
    if (pos < size_)
    {
        /* Muevo todos los elementos hacia la izquierda */
        for (size_t i = pos; i < size_ - 1; i++)
        {
            elems_[i] = elems_[i + 1];
        }

        /* Elimino el ultimo elemento */
        pop_back();
    }
}

template <class CV>void cvector<CV>::push_back(const CV &value)
{
    realloc_if_necessary();

    elems_[size_++] = value;
}

template <class CV>void cvector<CV>::pop_back()
{
    if (size_ > 0)
    {
        size_--;
    }
}

template <class CV>void cvector<CV>::resize(const size_t count)
{
    if (size_ < count)
    {
        realloc_(count);
    }

    capacity_ = count;
    size_ = std::min(count, size_);
}

template <class CV>cvector<CV>::cvector(cvector &orig)
{
    capacity_ = orig.capacity_;
    size_ = orig.size_;
    elems_ = new CV[capacity_];

    for (size_t i = 0; i < size_; i++)
    {
        elems_[i] = orig.elems_[i];
    }
}
