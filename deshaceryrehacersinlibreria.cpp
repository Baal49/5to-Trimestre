#include <iostream>
#include <string>
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
// 3. SIMULACIÓN: EDITOR DE TEXTO (Undo/Redo)
// ==========================================
class EditorTexto {
private:
    string texto;
    // Instanciamos nuestras propias pilas indicando que guardarán strings
    Pila<string> pilaUndo;
    Pila<string> pilaRedo;

public:
    EditorTexto() {
        texto = ""; 
    }

    void escribir(string nuevaPalabra) {
        // Guardamos el estado en Undo antes de modificar
        pilaUndo.push(texto);
        
        texto += nuevaPalabra;
        
        // Vaciamos la pila Redo usando nuestro método pop()
        while (!pilaRedo.empty()) {
            pilaRedo.pop();
        }
    }

    void deshacer() {
        if (pilaUndo.empty()) {
            cout << "[Aviso] No hay acciones para deshacer." << endl;
            return;
        }

        // El estado actual viaja al futuro (Redo)
        pilaRedo.push(texto);

        // Viajamos al pasado recuperando el tope de Undo
        texto = pilaUndo.top();
        pilaUndo.pop();
    }

    void rehacer() {
        if (pilaRedo.empty()) {
            cout << "[Aviso] No hay acciones para rehacer." << endl;
            return;
        }

        // El estado actual regresa al pasado (Undo)
        pilaUndo.push(texto);

        // Recuperamos el futuro desde el tope de Redo
        texto = pilaRedo.top();
        pilaRedo.pop();
    }

    void imprimirDocumento() {
        cout << "> Documento actual: \"" << texto << "\"" << endl;
    }
};

// ==========================================
// FUNCIÓN MAIN PARA PROBAR
// ==========================================
int main() {
    EditorTexto miEditor;

    cout << "--- Escribiendo en el documento ---" << endl;
    miEditor.escribir("Estructuras ");
    miEditor.escribir("dinamicas ");
    miEditor.escribir("en C++.");
    miEditor.imprimirDocumento(); 
    // Salida esperada: Estructuras dinamicas en C++.

    cout << "\n--- Deshacer (Ctrl+Z) 2 veces ---" << endl;
    miEditor.deshacer();
    miEditor.deshacer();
    miEditor.imprimirDocumento(); 
    // Salida esperada: Estructuras 

    cout << "\n--- Rehacer (Ctrl+Y) 1 vez ---" << endl;
    miEditor.rehacer();
    miEditor.imprimirDocumento(); 
    // Salida esperada: Estructuras dinamicas 

    cout << "\n--- Nuevo cambio (Invalida el rehacer pendiente) ---" << endl;
    miEditor.escribir("son geniales.");
    miEditor.imprimirDocumento(); 
    // Salida esperada: Estructuras dinamicas son geniales.

    cout << "\n--- Intentar Rehacer ---" << endl;
    miEditor.rehacer(); 
    // Salida esperada: [Aviso] No hay acciones para rehacer.

    return 0;
}