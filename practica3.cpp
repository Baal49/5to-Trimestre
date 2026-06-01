#include <iostream>

using namespace std;

struct DNode {
	int dato;
	DNode *prev;
	DNode *next;
};

struct List {
	DNode *head;
	DNode *tail;
	int cnt;
};

void init_list(List &l){ l.head = l.tail = nullptr; l.cnt = 0; } // Inicializa la lista vacía

DNode* create_node(int v){ // Crea un nuevo nodo con el valor dado
	DNode *n = new DNode;
	n->dato = v; n->prev = n->next = nullptr;
	return n;
}

void insert_front(List &l, int v){ // Inserta un nuevo nodo al frente de la lista
	DNode *n = create_node(v);
	n->next = l.head;
	if (l.head) l.head->prev = n;
	l.head = n;
	if (!l.tail) l.tail = n;
	++l.cnt;
}

void insert_back(List &l, int v){ // Inserta un nuevo nodo al final de la lista
	DNode *n = create_node(v);
	n->prev = l.tail;
	if (l.tail) l.tail->next = n;
	l.tail = n;
	if (!l.head) l.head = n;
	++l.cnt;
}

bool insert_at(List &l, int index, int v){ // Inserta un nuevo nodo en la posición dada (0-based)
	if (index < 0 || index > l.cnt) return false;
	if (index == 0){ insert_front(l, v); return true; }
	if (index == l.cnt){ insert_back(l, v); return true; }
	DNode *cur = l.head;
	for (int i=0;i<index;i++) cur = cur->next;
	DNode *n = create_node(v);
	n->prev = cur->prev;
	n->next = cur;
	if (cur->prev) cur->prev->next = n;
	cur->prev = n;
	++l.cnt;
	return true;
}

bool delete_value(List &l, int v){ // Elimina el primer nodo que contenga el valor dado
	DNode *cur = l.head;
	while (cur){
		if (cur->dato == v){
			if (cur->prev) cur->prev->next = cur->next;
			else l.head = cur->next;
			if (cur->next) cur->next->prev = cur->prev;
			else l.tail = cur->prev;
			delete cur;
			--l.cnt;
			return true;
		}
		cur = cur->next;
	}
	return false;
}

bool delete_at(List &l, int index){ // Elimina el nodo en la posición dada (0-based)
	if (index < 0 || index >= l.cnt) return false;
	DNode *cur = l.head;
	for (int i=0;i<index;i++) cur = cur->next;
	if (cur->prev) cur->prev->next = cur->next;
	else l.head = cur->next;
	if (cur->next) cur->next->prev = cur->prev;
	else l.tail = cur->prev;
	delete cur;
	--l.cnt;
	return true;
}

DNode* find(List &l, int v){ // Busca el primer nodo que contenga el valor dado y lo devuelve, o nullptr si no existe
	DNode *cur = l.head;
	while (cur){ if (cur->dato == v) return cur; cur = cur->next; }
	return nullptr;
}

void print_forward(const List &l){ // Imprime la lista de adelante hacia atrás
	cout << "[ ";
	DNode *cur = l.head;
	while (cur){ cout << cur->dato; if (cur->next) cout << ", "; cur = cur->next; }
	cout << " ] (size=" << l.cnt << ")\n";
}

void print_backward(const List &l){ // Imprime la lista de atrás hacia adelante
	cout << "[ ";
	DNode *cur = l.tail;
	while (cur){ cout << cur->dato; if (cur->prev) cout << ", "; cur = cur->prev; }
	cout << " ] (size=" << l.cnt << ")\n";
}

void clear(List &l){ // Elimina todos los nodos de la lista y la deja vacía
	DNode *cur = l.head;
	while (cur){ DNode *t = cur; cur = cur->next; delete t; }
	l.head = l.tail = nullptr; l.cnt = 0;
}

int size(const List &l){ return l.cnt; }

int main(){
	List lista;
	init_list(lista);
	cout << "Demo: lista doble enlazada\n";

	insert_back(lista, 10);
	insert_front(lista, 5);
	insert_back(lista, 15);
	insert_at(lista, 2, 12); // entre 10 y 15
	cout << "Forward: "; print_forward(lista);
	cout << "Backward: "; print_backward(lista);

	cout << "Eliminar valor 5: ";
	cout << (delete_value(lista, 5) ? "OK" : "No existe") << "\n";
	cout << "Eliminar en posicion 1: ";
	cout << (delete_at(lista, 1) ? "OK" : "Indice invalido") << "\n";
	cout << "Después: "; print_forward(lista);

	cout << "\nDemostración completa. Presione Enter para salir...";
	cin.ignore();
	cin.get();
	clear(lista);
	return 0;
}

