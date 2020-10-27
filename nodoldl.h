#ifndef NODOLDL_H
#define NODOLDL_H


struct NodoLDL
{
    T dato;
    NodoLDL *anterior;
    NodoLDL *siguiente;

    NodoLDL(const T &elem, NodoLDL *ant = nullptr, NodoLDL *sig = nullptr):
        dato(elem),
        anterior(ant),
        siguiente(sig)
    {}
};

#endif // NODOLDL_H
