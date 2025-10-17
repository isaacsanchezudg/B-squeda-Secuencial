
#ifndef BUSQUEDA_H
#define BUSQUEDA_H

#include "Arreglo.h"

/* Clase abstracta que servir� como base para declarar cada una de las
clases derivadas que representan los distintos m�todos de b�squeda en
arreglos. */
template <class T>
class Busqueda
{
public:
    virtual int Busca(Arreglo<T>, T) = 0;
};

/* Definici�n de la clase encargada de realizar la b�squeda secuencial
en un arreglo cuyos elementos est�n desordenados. Es una clase derivada
de Busqueda y en ella se especifica el m�todo Busca(). */
template <class T>
class SecuencialDesord : public Busqueda<T>
{
public:
    int Busca(Arreglo<T>, T);
};

/* Definici�n de la clase encargada de realizar la b�squeda secuencial
en un arreglo ordenado. Es una clase derivada de Busqueda y en ella se
especifica el m�todo Busca(). */
template <class T>
class SecuencialOrdenado : public Busqueda<T>
{
public:
    int Busca(Arreglo<T>, T);
};

/* M�todo que realiza la b�squeda, elemento por elemento, de un dato
dado en un arreglo desordenado. Recibe como par�metros el dato a buscar
y el arreglo en el cual se llevar� a cabo la operaci�n. Si lo encuentra
da como resultado la posici�n, en caso contrario regresa un -1. */
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

/* M�todo que realiza la b�squeda de un dato en un arreglo cuyos valores
est�n ordenados de manera creciente. Esta operaci�n se interrumpe
cuando se encuentra el valor buscado o cuando se compara a �ste con un
valor mayor. Recibe como par�metros el dato a buscar y el arreglo en el
cual se llevar� a cabo la operaci�n. Si lo encuentra da como resultado
la posici�n, en caso contrario regresa el negativo de la posici�n en la
que deber�a estar, m�s 1. */
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
