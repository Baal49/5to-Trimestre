#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Función para verificar si los símbolos están balanceados
bool estanBalanceados(string expresion) {
    stack<char> pila;

    // Recorremos cada caracter de la expresión
    for (int i = 0; i < expresion.length(); i++) {
        char c = expresion[i];

        // 1. Si es un símbolo de apertura, lo apilamos
        if (c == '(' || c == '{' || c == '[') {
            pila.push(c);
        }
        // 2. Si es un símbolo de cierre, verificamos
        else if (c == ')' || c == '}' || c == ']') {
            
            // Caso borde A: Encontramos un cierre pero no hay nada abierto (pila vacía)
            if (pila.empty()) {
                return false; 
            }

            // Revisamos cuál fue el último símbolo abierto (el tope de la pila)
            char tope = pila.top();

            // Verificamos si el símbolo de cierre coincide con el último de apertura
            if ((c == ')' && tope == '(') ||
                (c == '}' && tope == '{') ||
                (c == ']' && tope == '[')) {
                
                // Hacen pareja correcta, así que sacamos el de apertura de la pila
                pila.pop();
            } else {
                // Caso borde B: Hacen cortocircuito (ej. abriste '[' pero cerraste con ')')
                return false;
            }
        }
    }

    // 3. Al final, si la pila está vacía, todo se cerró correctamente.
    // Si quedó algo en la pila, faltó cerrar algún símbolo (Caso borde C).
    return pila.empty();
}

int main() {
    // Casos de prueba
    string exp1 = "{[()]}";
    string exp2 = "{[(])}";
    string exp3 = "{{[[(())]]}}";
    string exp4 = "(()"; // Falta cerrar uno
    string exp5 = "())"; // Sobra uno de cierre

    cout << "Validando expresiones:" << endl;
    cout << "----------------------" << endl;
    
    cout << exp1 << " -> " << (estanBalanceados(exp1) ? "Balanceado" : "Error de sintaxis") << endl;
    cout << exp2 << " -> " << (estanBalanceados(exp2) ? "Balanceado" : "Error de sintaxis") << endl;
    cout << exp3 << " -> " << (estanBalanceados(exp3) ? "Balanceado" : "Error de sintaxis") << endl;
    cout << exp4 << " -> " << (estanBalanceados(exp4) ? "Balanceado" : "Error de sintaxis") << endl;
    cout << exp5 << " -> " << (estanBalanceados(exp5) ? "Balanceado" : "Error de sintaxis") << endl;

    return 0;
}