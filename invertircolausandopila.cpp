#include <iostream>
#include <queue>
#include <stack>

using namespace std;

// Función para invertir los primeros K elementos de la cola
void invertirPrimerosK(queue<int>& cola, int k) {
    // 1. Manejo de casos borde: 
    // Si la cola está vacía, k es inválido o mayor al tamaño de la cola, no hacemos nada.
    if (cola.empty() || k <= 0 || k > cola.size()) {
        return;
    }

    stack<int> pila;

    // Paso 1: Extraer los primeros 'k' elementos de la cola y meterlos en la pila.
    // Esto naturalmente invertirá su orden al sacarlos de la pila más tarde.
    for (int i = 0; i < k; ++i) {
        pila.push(cola.front());
        cola.pop();
    }

    // Paso 2: Extraer los elementos de la pila e insertarlos al final de la cola.
    // Ahora los primeros 'k' elementos están al final de la cola, y están invertidos.
    while (!pila.empty()) {
        cola.push(pila.top());
        pila.pop();
    }

    // Paso 3: Rotar los elementos restantes (los que no queríamos invertir).
    // Los sacamos del frente y los volvemos a meter al final para restaurar el orden general.
    int elementosRestantes = cola.size() - k;
    for (int i = 0; i < elementosRestantes; ++i) {
        cola.push(cola.front());
        cola.pop();
    }
}

// Función auxiliar para imprimir el contenido de la cola sin perderla
void imprimirCola(queue<int> cola) {
    while (!cola.empty()) {
        cout << cola.front() << " ";
        cola.pop();
    }
    cout << endl;
}

int main() {
    queue<int> miCola;
    int k = 4;

    // Llenamos la cola con valores del 10 al 70
    for (int i = 1; i <= 7; ++i) {
        miCola.push(i * 10);
    }

    cout << "Cola original: \n";
    imprimirCola(miCola); // Salida esperada: 10 20 30 40 50 60 70

    invertirPrimerosK(miCola, k);

    cout << "\nCola tras invertir los primeros " << k << " elementos:\n";
    imprimirCola(miCola); // Salida esperada: 40 30 20 10 50 60 70

    return 0;
}