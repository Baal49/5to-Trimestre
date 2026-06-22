#include <iostream>
#include <stack>
#include <string>

using namespace std;

class EditorTexto {
private:
    string texto;
    stack<string> pilaUndo;
    stack<string> pilaRedo;

public:
    EditorTexto() {
        texto = ""; // Iniciamos con un documento en blanco
    }

    // Función para simular que escribimos en el editor
    void escribir(string nuevaPalabra) {
        // 1. Antes de modificar el texto, guardamos el estado actual en Undo
        pilaUndo.push(texto);
        
        // 2. Modificamos el texto
        texto += nuevaPalabra;
        
        // 3. Regla de oro del Undo/Redo: Si escribes algo nuevo, 
        // el "futuro" alternativo se borra. Vaciamos la pila Redo.
        while (!pilaRedo.empty()) {
            pilaRedo.pop();
        }
    }

    // Función para simular Ctrl + Z
    void deshacer() {
        if (pilaUndo.empty()) {
            cout << "[Aviso] No hay acciones para deshacer." << endl;
            return;
        }

        // 1. Guardamos el estado actual en Redo (por si nos arrepentimos de deshacer)
        pilaRedo.push(texto);

        // 2. El texto actual pasa a ser el que estaba en el tope de Undo
        texto = pilaUndo.top();
        pilaUndo.pop();
    }

    // Función para simular Ctrl + Y
    void rehacer() {
        if (pilaRedo.empty()) {
            cout << "[Aviso] No hay acciones para rehacer." << endl;
            return;
        }

        // 1. Guardamos el estado actual en Undo (por si queremos volver a deshacer)
        pilaUndo.push(texto);

        // 2. Recuperamos el texto desde la pila Redo
        texto = pilaRedo.top();
        pilaRedo.pop();
    }

    void imprimirDocumento() {
        cout << "> Documento actual: \"" << texto << "\"" << endl;
    }
};

int main() {
    EditorTexto miEditor;

    cout << "--- Iniciando edicion ---" << endl;
    miEditor.escribir("Hola ");
    miEditor.escribir("Mundo. ");
    miEditor.escribir("Esto es C++.");
    miEditor.imprimirDocumento(); 
    // Salida: Hola Mundo. Esto es C++.

    cout << "\n--- Presionando Ctrl+Z (Deshacer) ---" << endl;
    miEditor.deshacer();
    miEditor.imprimirDocumento(); 
    // Salida: Hola Mundo. 

    cout << "\n--- Presionando Ctrl+Z (Deshacer) de nuevo ---" << endl;
    miEditor.deshacer();
    miEditor.imprimirDocumento(); 
    // Salida: Hola 

    cout << "\n--- Presionando Ctrl+Y (Rehacer) ---" << endl;
    miEditor.rehacer();
    miEditor.imprimirDocumento(); 
    // Salida: Hola Mundo. 

    cout << "\n--- Escribiendo algo nuevo ---" << endl;
    miEditor.escribir("Programacion dinamica.");
    miEditor.imprimirDocumento(); 
    // Salida: Hola Mundo. Programacion dinamica.

    cout << "\n--- Intentando Rehacer tras un cambio nuevo ---" << endl;
    miEditor.rehacer(); 
    // Salida: [Aviso] No hay acciones para rehacer. (Porque se vacio la pila Redo)

    return 0;
}