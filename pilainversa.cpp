#include <iostream>
#include <stack>

// --- FUNCIONES PLANTILLA (TEMPLATES) ---

// 1. Función para ordenar la pila (Menor en el tope, Mayor en el fondo)
template <typename T>
void ordenarPila(std::stack<T>& pilaOriginal) {
    std::stack<T> pilaAux;
    while (!pilaOriginal.empty()) {
        T temp = pilaOriginal.top();
        pilaOriginal.pop();

        while (!pilaAux.empty() && pilaAux.top() > temp) {
            pilaOriginal.push(pilaAux.top());
            pilaAux.pop();
        }
        pilaAux.push(temp);
    }
    while (!pilaAux.empty()) {
        pilaOriginal.push(pilaAux.top());
        pilaAux.pop();
    }
}

// 2. NUEVA: Función para invertir el orden de la pila
template <typename T>
void invertirPila(std::stack<T>& pilaOriginal) {
    std::stack<T> pilaAux1;
    std::stack<T> pilaAux2;

    // Paso 1: Pasamos a la primera auxiliar (se invierte el orden)
    while (!pilaOriginal.empty()) {
        pilaAux1.push(pilaOriginal.top());
        pilaOriginal.pop();
    }

    // Paso 2: Pasamos a la segunda auxiliar (vuelve al orden original)
    while (!pilaAux1.empty()) {
        pilaAux2.push(pilaAux1.top());
        pilaAux1.pop();
    }

    // Paso 3: Pasamos de vuelta a la original (se invierte por completo)
    while (!pilaAux2.empty()) {
        pilaOriginal.push(pilaAux2.top());
        pilaAux2.pop();
    }
}

// 3. Función para imprimir la pila sin destruirla
template <typename T>
void imprimirPila(std::stack<T> pila) {
    if (pila.empty()) {
        std::cout << "[ Pila Vacía ]\n";
        return;
    }
    while (!pila.empty()) {
        std::cout << "| " << pila.top() << " |\n";
        pila.pop();
    }
    std::cout << "-----\n";
}

// --- PROGRAMA PRINCIPAL ---
int main() {
    std::stack<int> miPila;
    
    // Llenamos la pila con algunos datos iniciales
    miPila.push(34);
    miPila.push(3);
    miPila.push(99);
    miPila.push(1);
    miPila.push(25);

    int opcion;
    do {
        std::cout << "\n--- ESTADO ACTUAL DE LA PILA ---\n";
        imprimirPila(miPila);

        std::cout << "1. Ordenar pila (Menor arriba, Mayor abajo)\n";
        std::cout << "2. Invertir el orden actual de la pila\n";
        std::cout << "3. Salir\n";
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                ordenarPila(miPila);
                std::cout << "\n¡Pila ordenada con exito!\n";
                break;
            case 2:
                invertirPila(miPila);
                std::cout << "\n¡Pila invertida a peticion del usuario!\n";
                break;
            case 3:
                std::cout << "Saliendo del programa...\n";
                break;
            default:
                std::cout << "Opcion no valida. Intente de nuevo.\n";
        }
    } while (opcion != 3);

    return 0;
}