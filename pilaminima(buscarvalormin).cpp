#include <iostream>
#include <stack>

using namespace std;

class PilaMinima {
private:
    stack<int> pilaPrincipal; // Guarda todos los elementos
    stack<int> pilaMinimos;   // Guarda el historial de los mínimos

public:
    // Insertar un elemento
    void push(int valor) {
        pilaPrincipal.push(valor);
        
        // Si la pila de mínimos está vacía, o el nuevo valor es MENOR O IGUAL 
        // al mínimo actual, lo apilamos en la pila de mínimos también.
        // Nota: El "menor o igual" es crucial para manejar valores duplicados.
        if (pilaMinimos.empty() || valor <= pilaMinimos.top()) {
            pilaMinimos.push(valor);
        }
    }

    // Extraer un elemento
    void pop() {
        if (pilaPrincipal.empty()) {
            cout << "Error: La pila esta vacia." << endl;
            return;
        }

        // Si el elemento que estamos a punto de sacar de la pila principal 
        // es exactamente igual al tope de la pila de mínimos, 
        // también debemos sacarlo de la pila de mínimos.
        if (pilaPrincipal.top() == pilaMinimos.top()) {
            pilaMinimos.pop();
        }
        
        pilaPrincipal.pop();
    }

    // Ver el elemento en el tope
    int top() {
        if (pilaPrincipal.empty()) {
            cout << "Error: La pila esta vacia." << endl;
            return -1; // Valor de error genérico
        }
        return pilaPrincipal.top();
    }

    // Obtener el mínimo en tiempo O(1)
    int getMin() {
        if (pilaMinimos.empty()) {
            cout << "Error: La pila esta vacia." << endl;
            return -1;
        }
        return pilaMinimos.top();
    }
};

int main() {
    PilaMinima miPila;

    cout << "Insertando: 5, 8, 3, 7, 3" << endl;
    miPila.push(5);
    miPila.push(8);
    miPila.push(3);
    miPila.push(7);
    miPila.push(3); // Insertamos un mínimo duplicado

    cout << "\nMinimo actual: " << miPila.getMin() << " (Esperado: 3)" << endl;
    
    cout << "\nHacemos pop... (sacamos el ultimo 3)" << endl;
    miPila.pop();
    cout << "Minimo actual: " << miPila.getMin() << " (Esperado: 3, porque aun queda otro 3)" << endl;

    cout << "\nHacemos pop... (sacamos el 7)" << endl;
    miPila.pop();
    
    cout << "\nHacemos pop... (sacamos el primer 3)" << endl;
    miPila.pop();
    cout << "Minimo actual: " << miPila.getMin() << " (Esperado: 5)" << endl;

    return 0;
}