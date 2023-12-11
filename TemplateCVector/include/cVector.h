#ifndef CVECTOR_H_INCLUDED
#define CVECTOR_H_INCLUDED
#include <cstddef>
#include <cstdlib>
#include <iostream>

using namespace std;

template <class CV> class cvector;
template <class CV> ostream& operator<< (ostream&, cvector<CV>&);

template <class CV = int>class cvector
{
private:
    CV *elems_;
    static const size_t initial_capacity_ = 2;
    size_t size_;
    size_t capacity_;
    void free_();
    void realloc_(const size_t new_cap);
    void realloc_if_necessary();

public:
    cvector();
    cvector(cvector &orig);
    ~cvector();
    CV &at(const size_t pos);
    CV &operator[](const size_t pos);
    CV* begin();
    CV* end();
    bool empty() const;
    size_t size() const;
    void reserve(const size_t new_cap);
    size_t capacity() const;
    void clear();
    void insert(const size_t pos, const CV &value);
    void erase(const size_t pos);
    void push_back(const CV &value);
    void pop_back();
    void resize(const size_t count);
    bool full() const;
    void sort(void*);
    friend ostream& operator<< <>(ostream&, cvector<CV>&);
};

/**
 * @brief Constructor de clase
 */
template <class CV>cvector<CV>::cvector()
{
    elems_ = new CV[initial_capacity_];
    size_ = 0;
    capacity_ = initial_capacity_;
}

/**
 * @brief Constructor de copia
 * @param orig Referencia al vector original
 */
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



template <class CV> void cvector<CV>::free_()
{
    delete[] elems_;
}

/**
 * @brief Destructor de clase
 */
template <class CV> cvector<CV>::~cvector()
{
    free_();
}

/**
 * @brief Devuelve una referencia al elemento que se encuentra
 * en la ubicacion especificada
 * @param pos Posicion del elemento a devolver
 * @return Referencia al elemento requerido
 */
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

/**
 * @brief Devuelve una referencia al elemento que se encuentra
 * en la ubicacion especificada
 * @param pos Posicion del elemento a devolver
 * @return Referencia al elemento requerido
 */
template <class CV>CV &cvector<CV>::operator[](const size_t pos)
{
    return at(pos);
}

/**
 * @brief Comprueba si el vector no contiene elementos
 * @return true si el vector esta vacio, falso de lo contrario
 */
template <class CV>bool cvector<CV>::empty() const
{
    return (size_ == 0);
}


/**
 * @brief Devuelve el numero de elementos en el vector
 * @return El numero de elementos en el vector
 */
template <class CV>size_t cvector<CV>::size() const
{
    return size_;
}

/**
 * @brief Aumenta la capacidad del vector.
 *
 * Si new_cap es menor que la capacidad actual, no hace nada
 * @param new_cap Nueva capacidad del vector (en numero de
 * elementos)
 */
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

/**
 * @brief Devuelve el numero de elementos que el vector puede
 * alojar actualmente
 * @return Capacidad actual del vector
 */
template <class CV>size_t cvector<CV>::capacity() const
{
    return capacity_;
}

/**
 * @brief Vacia el vector, conservando su capacidad
 */
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
/**
 * @brief Inserta value en pos
 * @param pos Posicion donde insertar
 * @param value Valor a insertar
 */
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


/**
 * @brief Elimina un elemento del vector
 * @param pos Posicion a eliminar
 */
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

/**
 * @brief Agrega un elemento al final del vector
 * @param value Elemento a agregar
 */
template <class CV>void cvector<CV>::push_back(const CV &value)
{
    realloc_if_necessary();

    elems_[size_++] = value;
}

/**
 * @brief Quita el ultimo elemento del vector
 */
template <class CV>void cvector<CV>::pop_back()
{
    if (size_ > 0)
    {
        size_--;
    }
}

/**
 * @brief Cambia el tamano del vector
 *
 * Si el tamano actual es mayor que count, el vector se reduce a
 * count elementos. De lo contrario, se reserva memoria hasta
 * completar count elementos.
 * @param count Nuevo tamano del vector
 */
template <class CV>void cvector<CV>::resize(const size_t count)
{
    if (size_ < count)
    {
        realloc_(count);
    }

    capacity_ = count;
    size_ = std::min(count, size_);
}
/**
 * @brief Comprueba si el vector esta lleno
 * @return true si el vector esta lleno, false de lo contrario
 */
template <class CV>bool cvector<CV>::full() const
{
    return (size_ == capacity_);
}

template <class CV>CV* cvector<CV>::begin()
{
    return elems_;
}
template <class CV>CV* cvector<CV>::end()
{
    return elems_ + size_;
}


template <class CV>void cvector<CV>::sort(void* cmp)
{
    qsort(elems_,size_,sizeof(CV),cmp);
}

#endif // CVECTOR_H_INCLUDED
