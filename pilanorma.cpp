#include <iostream>
#include <stack>

// Función plantilla para ordenar la pila
template <typename T>
void ordenarPila(std::stack<T>& pilaOriginal) {
    // Pila auxiliar que mantendrá los elementos ordenados temporalmente
    // de MENOR (fondo) a MAYOR (tope) para que al regresarlos se inviertan.
    std::stack<T> pilaAux;

    while (!pilaOriginal.empty()) {
        // Tomamos el elemento del tope de la pila original
        T temp = pilaOriginal.top();
        pilaOriginal.pop(); // el pop lo que hace es quitar el elemento del tope de la pila original

        // RESTRICCIÓN: Para evitar que un valor mayor quede sobre uno menor
        // en la pila auxiliar, vaciamos los elementos mayores de regreso a la original.
        while (!pilaAux.empty() && pilaAux.top() > temp) {
            pilaOriginal.push(pilaAux.top());
            pilaAux.pop();
        }

        // Ahora es seguro colocar 'temp' en la pila auxiliar
        pilaAux.push(temp);
    }

    // Al terminar, pilaAux tiene el mayor en el tope y el menor en el fondo.
    // Al pasarlos de regreso a pilaOriginal, el orden se invierte:
    // Menor en el TOPE y Mayor en el FONDO.
    while (!pilaAux.empty()) {
        pilaOriginal.push(pilaAux.top());
        pilaAux.pop();
    }
}

// Función auxiliar para imprimir la pila (solo para demostración)
template <typename T>
void imprimirPila(std::stack<T> pila) {
    while (!pila.empty()) {
        std::cout << "| " << pila.top() << " |\n";
        pila.pop();
    }
    std::cout << "-----\n";
}

int main() {
    // Ejemplo con enteros
    std::stack<int> miPilaInt;
    miPilaInt.push(34);
    miPilaInt.push(3);
    miPilaInt.push(99);
    miPilaInt.push(1);
    miPilaInt.push(25);

    std::cout << "Pila original (Tope a Fondo):\n";
    imprimirPila(miPilaInt);

    ordenarPila(miPilaInt);

    std::cout << "\nPila ordenada (Menor en el tope, Mayor en el fondo):\n";
    imprimirPila(miPilaInt);

    // Ejemplo con flotantes (demostrando el uso de templates)
    std::stack<double> miPilaDouble;
    miPilaDouble.push(5.5);
    miPilaDouble.push(1.1);
    miPilaDouble.push(3.3);

    ordenarPila(miPilaDouble);

    return 0;
}