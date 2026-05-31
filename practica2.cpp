#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

struct Nodo{
    int dato;
    Nodo *siguiente;
};

void agregarPila(Nodo *&pila, int); //prototipo de la funcion agregarPila

int main(){
    Nodo *pila = NULL;
    int n1,n2;

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

    getch();
    return 0;

}

void agregarPila (Nodo *&pila, int n){
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->dato = n;
    nuevo_nodo->siguiente = pila;
    pila = nuevo_nodo;

}