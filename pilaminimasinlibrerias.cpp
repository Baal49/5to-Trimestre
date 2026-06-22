#include <iostream>
#include <stdexcept>

using namespace std;

// ==========================================
// 1. TEMPLATE DEL NODO
// ==========================================
template <typename T>
class Nodo {
public:
    T dato;
    Nodo<T>* siguiente;

    Nodo(T valor) {
        dato = valor;
        siguiente = nullptr;
    }
};

// ==========================================
// 2. TEMPLATE DE LA PILA BASE
// ==========================================
template <typename T>
class Pila {
private:
    Nodo<T>* topeNodo;

public:
    Pila() { topeNodo = nullptr; }

    ~Pila() {
        while (!empty()) {
            pop();
        }
    }

    bool empty() { return topeNodo == nullptr; }

    void push(T valor) {
        Nodo<T>* nuevo = new Nodo<T>(valor);
        nuevo->siguiente = topeNodo;
        topeNodo = nuevo;
    }

    void pop() {
        if (!empty()) {
            Nodo<T>* temp = topeNodo;
            topeNodo = topeNodo->siguiente;
            delete temp;
        }
    }

    T top() {
        if (!empty()) {
            return topeNodo->dato;
        }
        throw runtime_error("Error: Pila vacia");
    }
};

// ==========================================
// 3. TEMPLATE DE LA PILA MÍNIMA (MinStack)
// ==========================================
template <typename T>
class PilaMinima {
private:
    // Instanciamos nuestras propias pilas en lugar de std::stack
    Pila<T> pilaPrincipal;
    Pila<T> pilaMinimos;

public:
    void push(T valor) {
        pilaPrincipal.push(valor);
        
        // Comparamos si es el primer elemento o si es menor/igual al mínimo actual
        if (pilaMinimos.empty() || valor <= pilaMinimos.top()) {
            pilaMinimos.push(valor);
        }
    }

    void pop() {
        if (pilaPrincipal.empty()) {
            cout << "Error: No se puede hacer pop, la pila esta vacia." << endl;
            return;
        }

        // Si el valor que se va a eliminar es el mínimo actual, también sale del historial
        if (pilaPrincipal.top() == pilaMinimos.top()) {
            pilaMinimos.pop();
        }
        
        pilaPrincipal.pop();
    }

    T top() {
        if (pilaPrincipal.empty()) {
            throw runtime_error("Error: Pila vacia");
        }
        return pilaPrincipal.top();
    }

    // Retorna el elemento más pequeño en tiempo O(1)
    T getMin() {
        if (pilaMinimos.empty()) {
            throw runtime_error("Error: Pila vacia, no hay minimos");
        }
        return pilaMinimos.top();
    }
};

// ==========================================
// FUNCIÓN MAIN PARA PROBAR
// ==========================================
int main() {
    // Creamos una Pila Mínima específicamente para enteros (int)
    PilaMinima<int> miPilaMinima;

    cout << "Insertando elementos: 5, 8, 3, 7, 3" << endl;
    miPilaMinima.push(5);
    miPilaMinima.push(8);
    miPilaMinima.push(3);
    miPilaMinima.push(7);
    miPilaMinima.push(3); // Probando un mínimo duplicado

    cout << "---------------------------------" << endl;
    cout << "Minimo actual: " << miPilaMinima.getMin() << " (Esperado: 3)" << endl;
    
    cout << "\nHacemos pop... (Se elimina el ultimo 3)" << endl;
    miPilaMinima.pop();
    cout << "Minimo actual: " << miPilaMinima.getMin() << " (Esperado: 3, porque hay otro 3 en la pila)" << endl;

    cout << "\nHacemos pop... (Se elimina el 7)" << endl;
    miPilaMinima.pop();
    cout << "Minimo actual: " << miPilaMinima.getMin() << " (Esperado: 3)" << endl;
    
    cout << "\nHacemos pop... (Se elimina el primer 3)" << endl;
    miPilaMinima.pop();
    cout << "Minimo actual: " << miPilaMinima.getMin() << " (Esperado: 5)" << endl;

    return 0;
}