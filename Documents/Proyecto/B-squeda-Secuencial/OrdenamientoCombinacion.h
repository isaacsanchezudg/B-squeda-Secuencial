#ifndef ORDENAMIENTOCOMBINACION_H
#define ORDENAMIENTOCOMBINACION_H

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


    vector<int> getDatos() const {
        return datos; // Retorna una copia del vector de datos
    }

private:
    int tamanio;
    vector<int> datos;


    void ordenarSubVector(int, int, int);

    // Combina dos vectores ordenados
    void combinar(int, int, int, int, int);

    // Muestra el subvector
    void mostrarSubVector(int, int) const;
}; // Fin de la clase OrdenamientoCombinacion

#endif // ORDENAMIENTOCOMBINACION_H
