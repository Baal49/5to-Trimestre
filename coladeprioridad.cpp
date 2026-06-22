#include <iostream>
#include <queue>
#include <vector>
#include <string>

// Definimos un struct para empaquetar el dato y su prioridad
template <typename T>
struct Elemento {
    T dato;
    int prioridad;

    // Sobrecargamos el operador '>'
    // Esto es crucial porque std::greater lo usa para ordenar de menor a mayor
    bool operator>(const Elemento& otro) const {
        return prioridad > otro.prioridad;
    }
};

template <typename T>
class ColaPrioridad {
private:
    // Usamos std::greater para que el número menor (0) quede al principio (Min-Heap)
    std::priority_queue<Elemento<T>, std::vector<Elemento<T>>, std::greater<Elemento<T>>> cola;

public:
    // Insertar un elemento con su prioridad (0 a 5)
    void insertar(T dato, int prioridad) {
        if (prioridad < 0 || prioridad > 5) {
            std::cout << "[Error] La prioridad debe estar entre 0 y 5.\n";
            return;
        }
        cola.push({dato, prioridad});
    }

    // Eliminar y retornar el elemento con mayor prioridad (menor número)
    void procesarSiguiente() {
        if (cola.empty()) {
            std::cout << "La cola está vacía. Nada que procesar.\n";
            return;
        }

        Elemento<T> frente = cola.top();
        cola.pop();
       
        std::cout << "Procesando: [" << frente.dato
                  << "] con prioridad: " << frente.prioridad << "\n";
    }

    // Verificar si está vacía
    bool estaVacia() const {
        return cola.empty();
    }
};

int main() {
    // Ejemplo manejando un tipo de dato String
    ColaPrioridad<std::string> centralTareas;

    std::cout << "--- Insertando tareas en desorden ---\n";
    centralTareas.insertar("Hacer respaldo del sistema", 5); // Prioridad baja
    centralTareas.insertar("Actualizar documentación", 4);
    centralTareas.insertar("Responder correos pendientes", 3);
    centralTareas.insertar("Atender ticket de soporte pesado", 2);
    centralTareas.insertar("Reiniciar servidor de pruebas", 1);
    centralTareas.insertar("Corregir bug crítico en producción", 0); // Prioridad máxima
    std::cout << "Procesando elementos por prioridad";
    while (!centralTareas.estaVacia()) {
        centralTareas.procesarSiguiente();
    }

    return 0;
}