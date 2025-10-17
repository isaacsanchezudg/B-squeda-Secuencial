// Fig. 19.7: Fig19_07.cpp
// Programa de prueba de OrdenamientoCombinacion.

#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include "OrdenamientoCombinacion.h" // definición de la clase OrdenamientoCombinacion

int main() {

int tam, op;
cout << "Ingrese el tamano del vector: ";
cin >> tam;

OrdenamientoCombinacion orden(tam);

    do {
        cout << "\n===== MENU – METODO DE ORDENAMIENTO RECURSIVO =====\n";
        cout << "1. Ordenamiento creciente\n";
        cout << "2. Ordenamiento decreciente\n";
        cout << "3. Salir\n";
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
        cout << endl;
        break;

    case 2:
        cout << "\nORDENAMIENTO DECRECIENTE\n";
        orden.mostrarElementos();
        cout << "\n\nOrdenando...\n";
        orden.ordenar(op);
        cout << "\nVector ordenado:\n";
        orden.mostrarElementos();
        cout << endl;
        break;

    case 3:
        cout << "\nSaliendo...\n";
        break;

    default:
        cout << "\nOpcion no valida.\n";
        break;
}
 } while (op != 3);

    return 0;
}
