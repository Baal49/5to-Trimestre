#include <iostream>
#include <stdlib.h> // Mantenido por si usas system() en el futuro

using namespace std;

struct Nodo{
    int dato;
    Nodo *siguiente;
};

void agregarPila(Nodo *&pila, int); 

int main(){
    Nodo *pila = NULL;
    int n1, n2;

    cout << "Agregue un numero al azar" << endl;
    cin >> n1;

    agregarPila(pila, n1);
    
    cout << "Agregue otro numero al azar" << endl;
    cin >> n2;

    agregarPila(pila, n2);

    cout << "Los numeros agregados a la pila son: " << endl;
    
    Nodo *aux = pila;
    while (aux != NULL){
        cout << aux->dato << endl;
        aux = aux->siguiente;
    }
    
    // Alternativa limpia a getch() sin usar conio.h
    cout << "\nPresione Enter para salir...";
    cin.ignore(); // Limpia el buffer del cin anterior
    cin.get();    // Pausa el programa esperando un Enter
    
    return 0;
}

void agregarPila (Nodo *&pila, int n){
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->dato = n;
    nuevo_nodo->siguiente = pila;
    pila = nuevo_nodo;
}