#include <iostream>
using namespace std;

// Estructura del Nodo
struct Nodo {
    int valor;
    Nodo* siguiente;
    Nodo(int v) : valor(v), siguiente(nullptr) {}
};

// Función para buscar un valor en la lista
Nodo* buscarValor(Nodo* head, int dato) {
    Nodo* actual = head;
    while (actual != nullptr) {
        if(actual->valor == dato) {
            return actual;
        }
        actual = actual->siguiente;
    }
    cout << "Valor nao encontrado" << endl;
    return nullptr;
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
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int tamano = sizeof(arr) / sizeof(arr[0]);

    // Crea la lista enlazada a partir del array
    Nodo* head = crearLista(arr, tamano);

    // Imprime la lista original
    cout << "Lista original: ";
    imprimirLista(head);

    // Invierte la lista
    Nodo* nodo = buscarValor(head, 0);

    cout << "Valor encontrado: " << nodo->valor << endl;

    return 0;
}
