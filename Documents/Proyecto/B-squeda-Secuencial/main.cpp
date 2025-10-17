// Fig. 19.7: Fig19_07.cpp
// Programa de prueba de OrdenamientoCombinacion con sistema de búsqueda.

#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include <vector>
using std::vector;

#include "OrdenamientoCombinacion.h"
#include "Arreglo.h"
#include "Busqueda.h"


template <class T>
Arreglo<T> vectorToArreglo(const vector<T>& vec) {
    return Arreglo<T>(vec);
}

int main() {
    int tam, op, datoBuscar;
    cout << "Ingrese el tamano del vector: ";
    cin >> tam;

    OrdenamientoCombinacion orden(tam);
    vector<int> datosVector;
    bool vectorOrdenado = false;

    // Crear objetos de búsqueda
    SecuencialDesord<int> busquedaDesord;
    SecuencialOrdenado<int> busquedaOrd;

    do {
        cout << "\n===== MENU – METODO DE ORDENAMIENTO Y BUSQUEDA =====\n";
        cout << "1. Ordenamiento creciente\n";
        cout << "2. Ordenamiento decreciente\n";
        cout << "3. Busqueda SecuencialDesord (vector desordenado)\n";
        cout << "4. Busqueda SecuencialOrdenado (vector ordenado)\n";
        cout << "5. Mostrar vector actual\n";
        cout << "6. Salir\n";
        cout << "Elige tu opcion: ";
        cin >> op;

        switch (op) {
            case 1:
                cout << "\nORDENAMIENTO CRECIENTE\n";
                orden.mostrarElementos();
                cout << "\n\nOrdenando...\n";
                orden.ordenar(op);
                cout << "\nVector ordenado:\n";
                orden.mostrarElementos();
                vectorOrdenado = true;
                cout << endl;
                break;

            case 2:
                cout << "\nORDENAMIENTO DECRECIENTE\n";
                orden.mostrarElementos();
                cout << "\n\nOrdenando...\n";
                orden.ordenar(op);
                cout << "\nVector ordenado:\n";
                orden.mostrarElementos();
                vectorOrdenado = true;
                cout << endl;
                break;

case 3: {
    cout << "\nBUSQUEDA SECUENCIALDESORD (VECTOR DESORDENADO)\n";
    cout << "Vector actual:\n";
    orden.mostrarElementos();

    cout << "\nIngrese el dato a buscar: ";
    cin >> datoBuscar;


    datosVector = orden.getDatos();
    Arreglo<int> arreglo(datosVector);
    int resultado = busquedaDesord.Busca(arreglo, datoBuscar);

    if (resultado != -1) {
        cout << " Dato encontrado en posicion: " << resultado << endl;
    } else {
        cout << " Dato NO encontrado" << endl;
    }
    break;
}

case 4: {
    cout << "\nBUSQUEDA SECUENCIALORDENADO (VECTOR ORDENADO)\n";
    if (!vectorOrdenado) {
        cout << "Primero debe ordenar el vector (opcion 1)\n";
    } else {
        cout << "Vector ordenado:\n";
        orden.mostrarElementos();

        cout << "\nIngrese el dato a buscar: ";
        cin >> datoBuscar;


        datosVector = orden.getDatos();
        Arreglo<int> arreglo(datosVector);
        int resultado = busquedaOrd.Busca(arreglo, datoBuscar);

        if (resultado >= 0) {
            cout << " Dato encontrado en posicion: " << resultado << endl;
        } else {
            cout << " Dato NO encontrado" << endl;
            cout << "Deberia estar en posicion: " << (-resultado - 1) << endl;
        }
    }
    break;
}
            case 5:
                cout << "\nVECTOR ACTUAL\n";
                orden.mostrarElementos();
                if (vectorOrdenado) {
                    cout << " - ORDENADO";
                } else {
                    cout << " - DESORDENADO";
                }
                cout << endl;
                break;

            case 6:
                cout << "\nSaliendo...\n";
                break;

            default:
                cout << "\nOpcion no valida.\n";
                break;
        }
    } while (op != 6);

    return 0;
}
