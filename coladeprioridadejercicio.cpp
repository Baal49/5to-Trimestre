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
// 2. TEMPLATE DE LA COLA BASE (FIFO)
// ==========================================
template <typename T>
class Cola {
private:
    Nodo<T>* frenteNodo;
    Nodo<T>* finalNodo;

public:
    Cola() {
        frenteNodo = nullptr;
        finalNodo = nullptr;
    }

    ~Cola() {
        while (!empty()) {
            pop();
        }
    }

    bool empty() { return frenteNodo == nullptr; }

    void push(T valor) {
        Nodo<T>* nuevo = new Nodo<T>(valor);
        if (empty()) {
            frenteNodo = nuevo;
            finalNodo = nuevo;
        } else {
            finalNodo->siguiente = nuevo;
            finalNodo = nuevo;
        }
    }

    void pop() {
        if (!empty()) {
            Nodo<T>* temp = frenteNodo;
            frenteNodo = frenteNodo->siguiente;
            
            if (frenteNodo == nullptr) {
                finalNodo = nullptr;
            }
            
            delete temp;
        }
    }

    T front() {
        if (!empty()) {
            return frenteNodo->dato;
        }
        throw runtime_error("Error: Cola vacia");
    }
};

// ==========================================
// 3. ESTRUCTURA DE DATOS A ENCOLAR
// ==========================================
struct Proceso {
    string nombre;
    int tiempoRestante;
};

// ==========================================
// 4. SIMULADOR ROUND-ROBIN
// ==========================================
void simularRoundRobin(Cola<Proceso>& procesos) {
    // Definimos el Quantum o fragmento de tiempo asignado por turno
    int T = 60; 
    int tiempoTotal = 0;

    cout << "Iniciando simulador de CPU (Quantum T = " << T << " unidades)" << endl;
    cout << "--------------------------------------------------------" << endl;

    // El procesador trabaja mientras haya procesos en la cola
    while (!procesos.empty()) {
        // Extraemos el proceso al frente de la cola
        Proceso pAct = procesos.front();
        procesos.pop();

        cout << "\nAtendiendo: " << pAct.nombre << " | Tiempo requerido: " << pAct.tiempoRestante;

        // Calculamos la ejecución
        if (pAct.tiempoRestante > T) {
            // El proceso no termina en este turno
            pAct.tiempoRestante -= T;
            tiempoTotal += T;
            
            cout << "\n  -> Se ejecuto por " << T << " unidades. Faltan " << pAct.tiempoRestante << " unidades.";
            cout << "\n  -> Reencolando al final de la fila...";
            
            // Volvemos a encolar el proceso modificado
            procesos.push(pAct); 
            
        } else {
            // El proceso requiere menos o exactamente el tiempo T para terminar
            tiempoTotal += pAct.tiempoRestante;
            cout << "\n  -> Termino su ejecucion con exito en " << pAct.tiempoRestante << " unidades.";
        }
    }
    
    cout << "\n\n--------------------------------------------------------" << endl;
    cout << "Todos los procesos finalizados. Tiempo total de CPU: " << tiempoTotal << endl;
}

// ==========================================
// FUNCIÓN MAIN PARA PROBAR
// ==========================================
int main() {
    // Instanciamos la cola usando nuestra estructura Proceso
    Cola<Proceso> colaProcesos;
    
    // Insertamos procesos de prueba
    colaProcesos.push({"Descargar Archivo", 150});
    colaProcesos.push({"Imprimir Documento", 40});
    colaProcesos.push({"Actualizar Sistema", 200});

    // Llamamos al simulador
    simularRoundRobin(colaProcesos);

    return 0;
}