#include <iostream>
using namespace std;

// Estructura del Nodo
struct Nodo {
    int valor;
    Nodo* siguiente;
    Nodo(int v) : valor(v), siguiente(nullptr) {}
};

// Funcion para invertir la lista enlazada
Nodo* revertirLista(Nodo* head) {
    Nodo* anterior = nullptr;
    Nodo* actual = head;
    while (actual != nullptr) {
        Nodo* siguiente = actual->siguiente;
        actual->siguiente = anterior;
        anterior = actual;
        actual = siguiente;
    }
    return anterior;
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

// Funcion para imprimir la lista enlazada
void imprimirLista(Nodo* head) {
    Nodo* actual = head;
    while (actual != nullptr) {
        cout << actual->valor << " ";
        actual = actual->siguiente;
    }
    cout << endl;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int tamano = sizeof(arr) / sizeof(arr[0]);

    // Crea la lista enlazada a partir del array
    Nodo* head = crearLista(arr, tamano);

    // Imprime la lista original
    cout << "Lista original: ";
    imprimirLista(head);

    // Invierte la lista
    head = revertirLista(head);

    // Imprime la lista invertida
    cout << "Lista invertida: ";
    imprimirLista(head);

    return 0;
}
