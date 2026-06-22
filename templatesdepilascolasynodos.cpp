#include <iostream>
#include <string>

using namespace std;

// ==========================================
// 1. TEMPLATE DEL NODO
// ==========================================
template <typename T>
class Nodo {
public:
    T dato;
    Nodo<T>* siguiente;

    // Constructor del nodo
    Nodo(T valor) {
        dato = valor;
        siguiente = nullptr;
    }
};

// ==========================================
// 2. TEMPLATE DE LA PILA (LIFO)
// ==========================================
template <typename T>
class Pila {
private:
    Nodo<T>* topeNodo;

public:
    Pila() { topeNodo = nullptr; }

    // Destructor para liberar memoria
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
            delete temp; // Liberamos la memoria del nodo
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
// 3. TEMPLATE DE LA COLA (FIFO)
// ==========================================
template <typename T>
class Cola {
private:
    Nodo<T>* frenteNodo;
    Nodo<T>* finalNodo;
    int tamano; // Útil para el ejercicio de rotación

public:
    Cola() {
        frenteNodo = nullptr;
        finalNodo = nullptr;
        tamano = 0;
    }

    ~Cola() {
        while (!empty()) {
            pop();
        }
    }

    bool empty() { return frenteNodo == nullptr; }
    
    int size() { return tamano; }

    void push(T valor) {
        Nodo<T>* nuevo = new Nodo<T>(valor);
        if (empty()) {
            frenteNodo = nuevo;
            finalNodo = nuevo;
        } else {
            finalNodo->siguiente = nuevo;
            finalNodo = nuevo;
        }
        tamano++;
    }

    void pop() {
        if (!empty()) {
            Nodo<T>* temp = frenteNodo;
            frenteNodo = frenteNodo->siguiente;
            
            // Si al sacar el elemento la cola quedó vacía, actualizamos el final
            if (frenteNodo == nullptr) {
                finalNodo = nullptr;
            }
            
            delete temp;
            tamano--;
        }
    }

    T front() {
        if (!empty()) {
            return frenteNodo->dato;
        }
        throw runtime_error("Error: Cola vacia");
    }
};