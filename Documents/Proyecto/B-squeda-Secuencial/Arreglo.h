
#ifndef ARREGLO_H
#define ARREGLO_H

#include <vector>
using namespace std;

template <class T>
class Arreglo
{
private:
    vector<T> datos;

public:
    Arreglo() {}

    Arreglo(int tamano)
    {
        datos.resize(tamano);
    }

    Arreglo(vector<T> vectorDatos) : datos(vectorDatos) {}

    int RegresaTam() const
    {
        return datos.size();
    }

    T RegresaValor(int indice) const
    {
        if (indice >= 0 && indice < datos.size())
            return datos[indice];
        return T();
    }

    void AsignaValor(int indice, T valor)
    {
        if (indice >= 0 && indice < datos.size())
            datos[indice] = valor;
    }

    vector<T> RegresaVector() const
    {
        return datos;
    }
};

#endif // ARREGLO_H|
