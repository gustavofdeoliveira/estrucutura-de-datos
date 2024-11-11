#include <iostream>
using namespace std;

// Estructura del Nodo
struct Nodo {
    int valor;
    Nodo* siguiente;
    Nodo(int v) : valor(v), siguiente(nullptr) {}
};

// Función para ordenar la lista enlazada
void ordenarLista(Nodo* head) {
    if (!head) return; // Verifica se a lista é vazia

    bool intercambio = false;
    while (!intercambio){
        Nodo* actual = head;
        Nodo* siguiente = actual->siguiente;

        while (siguiente != nullptr) {
            if (actual->valor > siguiente->valor) {
                // Troca os valores dos nós
                int temp = actual->valor;
                actual->valor = siguiente->valor;
                siguiente->valor = temp;
                intercambio = true;
            }
            // Avança os ponteiros para os próximos nós
            actual = siguiente;
            siguiente = siguiente->siguiente;
        }
    }
}

// Función para crear una lista enlazada a partir de un array
Nodo* crearLista(int arr[], int tamaño) {
    if (tamaño == 0) return nullptr;

    Nodo* head = new Nodo(arr[0]);
    Nodo* actual = head;
    for (int i = 1; i < tamaño; i++) {
        actual->siguiente = new Nodo(arr[i]);
        actual = actual->siguiente;
    }
    return head;
}

// Función para imprimir la lista enlazada
void imprimirLista(Nodo* head) {
    Nodo* actual = head;
    while (actual != nullptr) {
        cout << actual->valor << " ";
        actual = actual->siguiente;
    }
    cout << endl;
}

int main() {
    int arr[] = {1, 3, 2, 4, 7, 6, 10, 8, 9};
    int tamano = sizeof(arr) / sizeof(arr[0]);

    // Crea la lista enlazada a partir del array
    Nodo* head = crearLista(arr, tamano);

    // Imprime la lista original
    cout << "Lista original: ";
    imprimirLista(head);

    // Invierte la lista
    ordenarLista(head);

    // Imprime la lista invertida
    cout << "Lista invertida: ";
    imprimirLista(head);

    return 0;
}
