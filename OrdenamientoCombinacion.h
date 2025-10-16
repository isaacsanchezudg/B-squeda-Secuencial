
#ifndef ORDENAMIENTOCOMBINACION_H
#define ORDENAMIENTOCOMBINACION_H

 // Fig. 19.5: OrdenamientoCombinacion.h
// Clase que crea un vector lleno de enteros aleatorios.
// Proporciona una función para ordenar el vector con el ordenamiento por combinación.

#include <vector>
using std::vector;

// Definición de la clase OrdenamientoCombinacion
class OrdenamientoCombinacion
{
public:
    // El constructor inicializa el vector
    OrdenamientoCombinacion(int);

    // Ordena el vector usando el ordenamiento por combinación
    void ordenar(int op);

    // Muestra los elementos del vector
    void mostrarElementos() const;

private:
    int tamanio;              // Tamaño del vector
    vector<int> datos;        // Vector de valores int

    // Ordena el subvector
    void ordenarSubVector(int, int, int);

    // Combina dos vectores ordenados
    void combinar(int, int, int, int, int);

    // Muestra el subvector
    void mostrarSubVector(int, int) const;
}; // Fin de la clase OrdenamientoCombinacion


#endif // ORDENAMIENTOCOMBINACION_H
