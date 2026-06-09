#include <iostream>
#include <queue>
#include <stack>
#include <string>

// --- FUNCIONES PLANTILLA (TEMPLATES) ---

// 1. Función para invertir una cola usando una pila auxiliar (LIFO)
template <typename T>
void invertirCola(std::queue<T>& colaOriginal) {
    std::stack<T> pilaAux;

    // Paso 1: Pasar todo de la cola a la pila (se invierte el orden)
    while (!colaOriginal.empty()) {
        pilaAux.push(colaOriginal.front());
        colaOriginal.pop();
    }

    // Paso 2: Pasar de la pila a la cola (mantiene el orden invertido)
    while (!pilaAux.empty()) {
        colaOriginal.push(pilaAux.top());
        pilaAux.pop();
    }
}

// 2. Función para fusionar dos colas de manera intercalada
// Se pasan por copia (sin el '&') para no destruir las colas originales de la simulación
template <typename T>
std::queue<T> fusionarColas(std::queue<T> c1, std::queue<T> c2) {
    std::queue<T> colaResultado;

    // Mientras alguna de las dos colas tenga elementos
    while (!c1.empty() || !c2.empty()) {
        if (!c1.empty()) {
            colaResultado.push(c1.front());
            c1.pop();
        }
        if (!c2.empty()) {
            colaResultado.push(c2.front());
            c2.pop();
        }
    }
    return colaResultado;
}

// 3. Función para imprimir la cola sin destruirla
template <typename T>
void imprimirCola(std::queue<T> cola) {
    if (cola.empty()) {
        std::cout << "[ Vacía ]";
        return;
    }
    std::cout << "[ Frente ] -> ";
    while (!cola.empty()) {
        std::cout << cola.front() << " -> ";
        cola.pop();
    }
    std::cout << "[ Final ]";
}

// --- PROGRAMA PRINCIPAL CON MENÚ INTERACTIVO ---
int main() {
    // Trabajaremos con tipos 'int' para el ejemplo, pero gracias al template podría ser 'double' o 'string'
    std::queue<int> cola1;
    std::queue<int> cola2;
    std::queue<int> colaFusionada;

    // Llenado inicial para facilitar las pruebas del usuario
    cola1.push(10); cola1.push(20); cola1.push(30);
    cola2.push(100); cola2.push(200); cola2.push(300); cola2.push(400);

    int opcion;
    do {
        std::cout << "\n=========================================\n";
        std::cout << "          ESTADO DE LAS COLAS\n";
        std::cout << "=========================================\n";
        std::cout << "Cola 1: "; imprimirCola(cola1); std::cout << "\n";
        std::cout << "Cola 2: "; imprimirCola(cola2); std::cout << "\n";
        std::cout << "Cola Fusionada: "; imprimirCola(colaFusionada); std::cout << "\n";
        std::cout << "=========================================\n";
        std::cout << "1. Añadir elemento a la Cola 1\n";
        std::cout << "2. Añadir elemento a la Cola 2\n";
        std::cout << "3. Invertir Cola 1\n";
        std::cout << "4. Invertir Cola 2\n";
        std::cout << "5. Fusionar Cola 1 y Cola 2 (Intercalado)\n";
        std::cout << "6. Vaciar Cola Fusionada\n";
        std::cout << "7. Salir\n";
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1: {
                int valor;
                std::cout << "Ingrese valor entero para Cola 1: ";
                std::cin >> valor;
                cola1.push(valor);
                break;
            }
            case 2: {
                int valor;
                std::cout << "Ingrese valor entero para Cola 2: ";
                std::cin >> valor;
                cola2.push(valor);
                break;
            }
            case 3:
                invertirCola(cola1);
                std::cout << "\n¡Cola 1 invertida!\n";
                break;
            case 4:
                invertirCola(cola2);
                std::cout << "\n¡Cola 2 invertida!\n";
                break;
            case 5:
                colaFusionada = fusionarColas(cola1, cola2);
                std::cout << "\n¡Colas fusionadas con éxito en una nueva estructura!\n";
                break;
            case 6:
                while(!colaFusionada.empty()) colaFusionada.pop();
                std::cout << "\nCola fusionada limpiada.\n";
                break;
            case 7:
                std::cout << "Saliendo del sistema...\n";
                break;
            default:
                std::cout << "Opción inválida. Intente de nuevo.\n";
        }
    } while (opcion != 7);

    return 0;
}