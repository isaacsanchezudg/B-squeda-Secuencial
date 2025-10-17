
// Fig. 19.6: OrdenamientoCombinacion.cpp
// Definición de las funciones miembro de la clase OrdenamientoCombinacion.

#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <cstdlib>  // prototipos para las funciones srand y rand
using std::rand;
using std::srand;

#include <ctime>    // prototipo para la función time
using std::time;

#include "OrdenamientoCombinacion.h" // definición de la clase OrdenamientoCombinacion

// El constructor llena el vector con enteros aleatorios
OrdenamientoCombinacion::OrdenamientoCombinacion(int tamanioVector)
{
    tamanio = (tamanioVector > 0 ? tamanioVector : 10); // valida tamanioVector
    srand(time(0)); // siembra el generador de números aleatorios usando la hora actual

    // llena el vector con valores int aleatorios en el rango de 10 a 99
    for (int i = 0; i < tamanio; i++){
        datos.push_back(10 + rand() % 90);
    }
} // fin del constructor

// Divide el vector, ordena los subvectores y los combina en un vector ordenado
void OrdenamientoCombinacion::ordenar(int op)
{
    ordenarSubVector(0, tamanio - 1, op); // ordena todo el vector en forma recursiva
} // fin de la función ordenar

// Función recursiva para ordenar los subvectores
void OrdenamientoCombinacion::ordenarSubVector(int inferior, int superior, int op)
{
    // prueba el caso base; el tamaño del vector es igual a 1
    if ((superior - inferior) >= 1) // si no es el caso base
    {
        int medio1 = (inferior + superior) / 2; // calcula el elemento medio del vector
        int medio2 = medio1 + 1; // calcula el siguiente elemento más arriba

        // imprime el paso de división
        cout << "division: ";
        mostrarSubVector(inferior, superior);
        cout << endl << " ";
        mostrarSubVector(inferior, medio1);
        cout << endl << " ";
        mostrarSubVector(medio2, superior);
        cout << endl << endl;

        // divide el vector a la mitad; ordena cada mitad (llamadas recursivas)
        ordenarSubVector(inferior, medio1, op); // primera mitad
        ordenarSubVector(medio2, superior, op); // segunda mitad

        // combina dos vectores ordenados después de que regresan las llamadas de división
        combinar(inferior, medio1, medio2, superior, op);
    } // fin de if
} // fin de la función ordenarSubVector

// Combina dos subvectores ordenados en un subvector ordenado
void OrdenamientoCombinacion::combinar(int izquierdo, int medio1, int medio2, int derecho, int op)
{
    int indiceIzq = izquierdo;
    int indiceDer = medio2;
    int indiceCombinado = izquierdo;
    vector<int> combinado(tamanio);

    while (indiceIzq <= medio1 && indiceDer <= derecho)
    {
        if (op == 1) { // Ordenamiento creciente
            if (datos[indiceIzq] <= datos[indiceDer])
                combinado[indiceCombinado++] = datos[indiceIzq++];
            else
                combinado[indiceCombinado++] = datos[indiceDer++];
        }
        else if (op == 2) { // Ordenamiento decreciente
            if (datos[indiceIzq] >= datos[indiceDer])
                combinado[indiceCombinado++] = datos[indiceIzq++];
            else
                combinado[indiceCombinado++] = datos[indiceDer++];
        }
    }

    if (indiceIzq == medio2) {
        while (indiceDer <= derecho)
            combinado[indiceCombinado++] = datos[indiceDer++];
    } else {
        while (indiceIzq <= medio1)
            combinado[indiceCombinado++] = datos[indiceIzq++];
    }

    for (int i = izquierdo; i <= derecho; i++)
        datos[i] = combinado[i];
}

// Muestra los elementos en el vector
void OrdenamientoCombinacion::mostrarElementos() const
{
    mostrarSubVector(0, tamanio - 1);
} // fin de la función mostrarElementos

// Muestra ciertos valores en el vector
void OrdenamientoCombinacion::mostrarSubVector(int inferior, int superior) const
{
    // imprime espacios para alineación
    for (int i = 0; i < inferior; i++)
        cout << " ";

    // imprime los elementos del subvector
    for (int i = inferior; i <= superior; i++)
        cout << " " << datos[i];
} // fin de la función mostrarSubVector
