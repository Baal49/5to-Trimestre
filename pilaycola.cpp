#include <iostream>
#include <string>
#include <stdexcept>

template <typename T>
struct Node {
    T data;
    Node* next;
    Node(T val) : data(val), next(nullptr) {}
};

template <typename T>
class Pila {
private:
    Node<T>* topNode;
    int size;

public:
    Pila() : topNode(nullptr), size(0) {}

    ~Pila() {
        while (size > 0) {
            pop();
        }
    }

    void push(T data) {
        Node<T>* newNode = new Node<T>(data);
        newNode->next = topNode;
        topNode = newNode;
        size++;
    }

    T pop() {
        if (size == 0) {
            throw std::underflow_error("Error: La pila está vacía.");
        }
        Node<T>* temp = topNode;
        T poppedData = temp->data;
        topNode = topNode->next;
        delete temp;
        size--;
        return poppedData;
    }

    int getSize() {
        return size;
    }
};

//cola
template <typename T>
class Cola {
private:
    Node<T>* frontNode;
    Node<T>* backNode;
    int size;

public:
    Cola() : frontNode(nullptr), backNode(nullptr), size(0) {}

    ~Cola() {
        while (size > 0) {
            pop();
        }
    }

    void push(T data) {
        Node<T>* newNode = new Node<T>(data);
        if (size == 0) {
            frontNode = backNode = newNode;
        } else {
            backNode->next = newNode;
            backNode = newNode;
        }
        size++;
    }

    T pop() {
        if (size == 0) {
            throw std::underflow_error("Error: La cola está vacía.");
        }
        Node<T>* temp = frontNode;
        T poppedData = temp->data;
        frontNode = frontNode->next;
        delete temp;
        size--;
       
        if (size == 0) {
            backNode = nullptr;
        }
        return poppedData;
    }

    int getSize() {
        return size;
    }
};

//prueba 1
int main() {
    std::cout << "prueba, hola" << std::endl;

//pila , busqueda
    std::cout << ">>> [1] Prueba con string<<<" << std::endl;
    Pila<std::string> historialWeb;

    std::cout << "push de taxi (prueba)" << std::endl;
    historialWeb.push("google.com");
    historialWeb.push("github.com");
    historialWeb.push("stackoverflow.com");

    std::cout << "Cantidad de páginas guardadas: " << historialWeb.getSize() << "\n" << std::endl;

    std::cout << "Presionando el botón 'Atrás' (pop):" << std::endl;
    // Debería salir en orden inverso
    while (historialWeb.getSize() > 0) {
        std::cout << " Regresando de: " << historialWeb.pop() << std::endl;
        std::cout << " Páginas restantes en historial: " << historialWeb.getSize() << std::endl;
    }

    // Intento de pop en pila vacía para probar el control de errores
    try {
        std::cout << "\nIntentando hacer pop en una pila vacía..." << std::endl;
        historialWeb.pop();
    } catch (const std::underflow_error& e) {
        std::cout << " Capturado correctamente: " << e.what() << std::endl;
    }


    std::cout << "\n-----------------------------------------\n" << std::endl;


//prueba cola
    std::cout << ">>> [2] Probando la COLA (FIFO) con Integers <<<" << std::endl;
    Cola<int> filaImpresion;

    std::cout << "Enviando IDs de documentos a la cola (push)..." << std::endl;
    std::cout << " -> Enviando Doc #101" << std::endl; filaImpresion.push(101);
    std::cout << " -> Enviando Doc #102" << std::endl; filaImpresion.push(102);
    std::cout << " -> Enviando Doc #103" << std::endl; filaImpresion.push(103);

    std::cout << "Documentos en espera: " << filaImpresion.getSize() << "\n" << std::endl;

    std::cout << "Procesando la cola de impresión (pop):" << std::endl;
    // Deberían salir en el mismo orden e
    while (filaImpresion.getSize() > 0) {
        std::cout << " [Impresora] Procesando e imprimiendo documento ID: " << filaImpresion.pop() << std::endl;
    }

    std::cout << "\nDocumentos restantes en cola: " << filaImpresion.getSize() << std::endl;

    //prueba para cola vacia
    try {
        std::cout << "\nIntentando hacer pop en una cola vacía..." << std::endl;
        filaImpresion.pop();
    } catch (const std::underflow_error& e) {
        std::cout << " Capturado correctamente: " << e.what() << std::endl;
    }

    std::cout << "         Fin de las pruebas" << std::endl;

    return 0;
}