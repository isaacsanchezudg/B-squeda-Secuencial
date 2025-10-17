
#ifndef BUSQUEDA_H
#define BUSQUEDA_H

#include "Arreglo.h"

/* Clase abstracta que servirá como base para declarar cada una de las
clases derivadas que representan los distintos métodos de búsqueda en
arreglos. */
template <class T>
class Busqueda
{
public:
    virtual int Busca(Arreglo<T>, T) = 0;
};

/* Definición de la clase encargada de realizar la búsqueda secuencial
en un arreglo cuyos elementos están desordenados. Es una clase derivada
de Busqueda y en ella se especifica el método Busca(). */
template <class T>
class SecuencialDesord : public Busqueda<T>
{
public:
    int Busca(Arreglo<T>, T);
};

/* Definición de la clase encargada de realizar la búsqueda secuencial
en un arreglo ordenado. Es una clase derivada de Busqueda y en ella se
especifica el método Busca(). */
template <class T>
class SecuencialOrdenado : public Busqueda<T>
{
public:
    int Busca(Arreglo<T>, T);
};

/* Método que realiza la búsqueda, elemento por elemento, de un dato
dado en un arreglo desordenado. Recibe como parámetros el dato a buscar
y el arreglo en el cual se llevará a cabo la operación. Si lo encuentra
da como resultado la posición, en caso contrario regresa un -1. */
template <class T>
int SecuencialDesord<T>::Busca(Arreglo<T> Arre, T Dato)
{
    int Indice = 0, Posic = -1;
    while (Indice < Arre.RegresaTam() && Dato != Arre.RegresaValor(Indice))
        Indice++;
    if (Indice < Arre.RegresaTam())
        Posic = Indice;
    return Posic;
}

/* Método que realiza la búsqueda de un dato en un arreglo cuyos valores
están ordenados de manera creciente. Esta operación se interrumpe
cuando se encuentra el valor buscado o cuando se compara a éste con un
valor mayor. Recibe como parámetros el dato a buscar y el arreglo en el
cual se llevará a cabo la operación. Si lo encuentra da como resultado
la posición, en caso contrario regresa el negativo de la posición en la
que debería estar, más 1. */
template <class T>
int SecuencialOrdenado<T>::Busca(Arreglo<T> Arre, T Dato)
{
    int Indice = 0, Posic;
    while (Indice < Arre.RegresaTam() && Dato > Arre.RegresaValor(Indice))
        Indice++;
    if (Indice == Arre.RegresaTam() || Dato < Arre.RegresaValor(Indice))
        Posic = -(Indice + 1);
    else
        Posic = Indice;
    return Posic;
}

#endif // BUSQUEDA_H
