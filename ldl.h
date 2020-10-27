#ifndef LDL_H
#define LDL_H
#include <iostream>
#include <stdexcept>

using namespace std;

template <typename T>
class LDL
{
private:
#include "nodoldl.h"
    size_t listSize;
    NodoLDL *listFront;
    NodoLDL *listBack;

public:
    LDL() : listSize(0), listFront(nullptr), listBack(nullptr)
    {}

    LDL(const LDL &other)
    {
        listSize = 0;
        listFront = nullptr;
        listBack = nullptr;

        for(size_t i(0); i < other.size();++i)
            push_back(other[i]);
    }

    LDL &operator = (const LDL &other)
    {
        listSize = 0;
        listFront = nullptr;
        listBack = nullptr;

        for(size_t i(0); i < other.size();++i)
            push_back(other[i]);
        return *this;
    }

    bool empty() const;
    size_t size() const;
    void push_front(const T &elem);
    void push_back(const T &elem);
    const T &front() const;
    const T &back() const;
    void pop_front();
    void pop_back();
    void insert(size_t position, const T &elem);
    void erase(size_t position);
    void clear();
    void remove(const T &value);
    T &operator[](size_t idx) const;
};

template <typename T>
bool LDL<T>::empty() const
{
    return listSize == 0;
}

template <typename T>
size_t LDL<T>::size() const
{
    return listSize;
}

template <typename T>
void LDL<T>::push_front(const T &elem)
{
    if(empty())
    {
        listFront = new NodoLDL(elem);
        listBack = listFront;
    }
    else
    {
        NodoLDL *temp = new NodoLDL(elem, nullptr, listFront);
        listFront -> anterior = temp;
        listFront = temp;
    }
    ++listSize;
}

template <typename T>
void LDL<T>::push_back(const T &elem)
{
    if(empty())
    {
        listFront = new NodoLDL(elem);
        listBack = listFront;
    }
    else
    {
        NodoLDL *temp = new NodoLDL(elem, listBack);
        listBack -> siguiente = temp;
        listBack = temp;
    }
    ++listSize;
}

template <typename T>
const T &LDL<T>::front() const
{
    if(empty())
        throw invalid_argument("Front() on empty list");
    return listFront -> dato;
}

template <typename T>
const T &LDL<T>::back() const
{
    if(empty())
        throw  invalid_argument("Back() on empty list");
    return listBack -> dato;
}

template <typename T>
void LDL<T>::pop_front()
{
    if(empty())
        throw invalid_argument("pop front() on empty list");
    NodoLDL *temp = listFront;
    listFront = listFront -> siguiente;
    delete temp;
    temp = nullptr;
    --listSize;
}

template <typename T>
void LDL<T>::pop_back()
{
    if(empty())
        throw invalid_argument("pop back() on empty list");
    NodoLDL *temp = listFront;
    while(temp != nullptr and temp -> siguiente != listBack)
        temp = temp -> siguiente;
    delete listBack;
    listBack = temp;
    temp -> siguiente = nullptr;
    --listSize;
}


template <typename  T>
void LDL<T>::insert(size_t position, const T &elem)
{
    if(empty())
        throw invalid_argument("Insert() on empty list");
    else if(position > listSize)
        throw invalid_argument("Insert() on non valid position");
    else if (position == 0)
        push_front(elem);
    else if (position == listSize)
        push_back(elem);
    else
    {
        NodoLDL *temp = listFront;
        for(size_t i(0); i < position-1;++i)
            temp = temp -> siguiente;
        NodoLDL *newNodo = new NodoLDL(elem, temp -> siguiente);
        temp -> siguiente = newNodo;
        ++listSize;
    }
}

template <typename T>
void LDL<T>::erase(size_t position)
{
    if(empty())
        throw invalid_argument("Erase() on empty list");
    else if(position >= listSize)
        throw invalid_argument("Erase() on non valid position");
    else if(position == 0)
        pop_front();
    else if(position == listSize-1)
        pop_back();
    else
    {
        NodoLDL *temp = listFront;
        for (size_t i(0); i < position-1;++i)
            temp = temp -> siguiente;
        NodoLDL *eliminar = temp -> siguiente;
        temp -> siguiente = eliminar -> siguiente;
        delete eliminar;
        eliminar = nullptr;
        --listSize;
    }
}

template <typename T>
void LDL<T>::clear()
{
    for(size_t i(0); i < listSize; ++i)
        pop_front();

    listSize = 0;
    listFront = nullptr;
    listBack = nullptr;
}

template <typename T>
void LDL<T>::remove(const T &value)
{
    if(empty())
        throw invalid_argument("Remove() on empty list");
    NodoLDL *temp = listFront;
    T dato;
    size_t i= 0;

    while(temp != nullptr)
    {
        dato = temp -> dato;
        temp = temp -> siguiente;
        if(dato == value)
        {
            erase(i);
            --i;
        }
        ++i;
    }
}

template <typename T>
T &LDL<T>::operator [](size_t idx) const
{
    if(empty())
        throw invalid_argument("[] on empty list");
    else if (idx >= listSize)
        throw invalid_argument("index out of range");
    NodoLDL *temp = listFront;
    for(size_t i(0); i < idx; ++i)
        temp = temp -> siguiente;
    return temp->dato;
}

#endif // LDL_H
