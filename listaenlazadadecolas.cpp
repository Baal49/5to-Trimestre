#include <iostream>
using namespace std;
template <typename N>
    class nodo{
        public:
            N dato;
            nodo* Nextnode=nullptr;
        nodo(N d){
            dato=d;
        }
        nodo(){

        }
    };
template <typename l>
class cola{
        public:
            nodo<l>* principio=nullptr;
            nodo<l>*fin;
            int cant=0;
            cola(){
                principio=nullptr;
                fin=nullptr;
            }
            ~cola(){
                while(principio!=nullptr){
                    pop();
                }
            }
            void push(l n){
                nodo<l>* nodoact=new nodo<l>{n};
                if(fin!=nullptr){
                    fin->Nextnode=nodoact;
                }
                fin=nodoact;
                if(principio==nullptr){
                    principio=nodoact;
                }
                cant++;
            }
            l pop(){
                if(principio==nullptr){
                    return 0;
                }
                nodo<l>* nodoact=principio;
                principio=nodoact->Nextnode;
                l d=nodoact->dato;
                delete nodoact;
                if(principio==nullptr){
                    fin=nullptr;
                }
                cant--;
                return d;
            }

};
template <typename O>
class lista{
    public:
        nodo<O>* Head;
        int cant;
        lista() {
        Head = nullptr;
        cant = 0;
    }

    ~lista() {

    }

    void insertar(O dato){
        nodo<O>* newnode=new nodo(dato);
        if(Head==nullptr){
            Head=newnode;
            cant++;
        }
        else{
            nodo<O>* act=Head;
            act=Head;
            while(act->Nextnode!=nullptr){
                act=act->Nextnode;
            }
            act->Nextnode=newnode;
            cant++;
        }
    }
    void mostrar() {
        nodo<O>* actual = Head;
        while (actual != nullptr) {
            cout << actual->dato->pop() << " -> ";
            actual = actual->Nextnode;
        }
        cout << "NULL" << endl;
    }
};
int main(){
lista<cola<int>*>* colas=new lista<cola<int>*>;
cola<int>* colap1=new cola<int>;
cola<int>* colap2=new cola<int>;
cola<int>* colap3=new cola<int>;
cola<int>* colap4=new cola<int>;
cola<int>* colap5=new cola<int>;
colas->insertar(colap1);
colap1->push(10);
colas->insertar(colap2);
colap2->push(20);
colas->insertar(colap3);
colap3->push(30);
colas->insertar(colap4);
colap4->push(40);
colas->insertar(colap5);
colap5->push(50);
colas->mostrar();

}