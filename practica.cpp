#include <iostream>
#include <string>

template <typename T>
struct Node {
    T value;
    Node* next;
    explicit Node(const T& val) : value(val), next(nullptr) {}
};
//La siguiente funcion conecta dos nodos y siempre devuelve el punteor al primer nodo
//Si el primer nodo es null, manda el segundo nodo al inicio de cadena
template <typename T>
Node<T>* connectNodes(Node<T>* first, Node<T>* second) {
    if (first == nullptr) {
        return second;
    }
    Node<T>* current = first;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = second;
    return first; 
}

template <typename T>
void printList(Node<T>* head) {
    Node<T>* current = head;
    while (current != nullptr) {
        std::cout << current->value;
        if (current->next != nullptr) {
            std::cout << " -> ";
        }
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
    Node<int>* nodo1 = new Node<int>(15);
    Node<int>* nodo2 = new Node<int>(22);
    Node<int>* nodo3 = new Node<int>(38);

    Node<int>* head = connectNodes(nodo1, nodo2);
    head = connectNodes(head, nodo3);

    printList(head);

    // Liberar memoria simple
    Node<int>* current = head;
    while (current != nullptr) {
        Node<int>* next = current->next;
        delete current;
        current = next;
    }

    return 0;
}