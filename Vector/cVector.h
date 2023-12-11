#ifndef CVECTOR_H_INCLUDED
#define CVECTOR_H_INCLUDED

#include <cstddef>
#include <iostream>
#define TYPE_ string

using namespace std;
namespace oop
{
    class vector
    {
    private:
        TYPE_ *elems_;
        static const size_t initial_capacity_ = 2;
        size_t size_;
        size_t capacity_;
        void free_();
        void realloc_(const size_t new_cap);
        void realloc_if_necessary();

    public:
        /**
         * @brief Constructor de clase
         */
        vector();

        /**
         * @brief Constructor de copia
         * @param orig Referencia al vector original
         */
        vector(vector &orig);

        /**
         * @brief Destructor de clase
         */
        ~vector();

        /**
         * @brief Devuelve una referencia al elemento que se encuentra
         * en la ubicacion especificada
         * @param pos Posicion del elemento a devolver
         * @return Referencia al elemento requerido
         */
        TYPE_ &at(const size_t pos);

        /**
         * @brief Devuelve una referencia al elemento que se encuentra
         * en la ubicacion especificada
         * @param pos Posicion del elemento a devolver
         * @return Referencia al elemento requerido
         */
        TYPE_ &operator[](const size_t pos);

        /**
         * @brief Comprueba si el vector no contiene elementos
         * @return true si el vector esta vacio, falso de lo contrario
         */
        bool empty() const;

        /**
         * @brief Devuelve el numero de elementos en el vector
         * @return El numero de elementos en el vector
         */
        size_t size() const;

        /**
         * @brief Aumenta la capacidad del vector.
         *
         * Si new_cap es menor que la capacidad actual, no hace nada
         * @param new_cap Nueva capacidad del vector (en numero de
         * elementos)
         */
        void reserve(const size_t new_cap);

        /**
         * @brief Devuelve el numero de elementos que el vector puede
         * alojar actualmente
         * @return Capacidad actual del vector
         */
        size_t capacity() const;

        /**
         * @brief Vacia el vector, conservando su capacidad
         */
        void clear();

        /**
         * @brief Inserta value en pos
         * @param pos Posicion donde insertar
         * @param value Valor a insertar
         */
        void insert(const size_t pos, const TYPE_ &value);

        /**
         * @brief Elimina un elemento del vector
         * @param pos Posicion a eliminar
         */
        void erase(const size_t pos);

        /**
         * @brief Agrega un elemento al final del vector
         * @param value Elemento a agregar
         */
        void push_back(const TYPE_ &value);

        /**
         * @brief Quita el ultimo elemento del vector
         */
        void pop_back();

        /**
         * @brief Cambia el tamano del vector
         *
         * Si el tamano actual es mayor que count, el vector se reduce a
         * count elementos. De lo contrario, se reserva memoria hasta
         * completar count elementos.
         * @param count Nuevo tamano del vector
         */
        void resize(const size_t count);

        /**
         * @brief Comprueba si el vector esta lleno
         * @return true si el vector esta lleno, false de lo contrario
         */
        bool full() const;
    };
}

#endif // CVECTOR_H_INCLUDED
