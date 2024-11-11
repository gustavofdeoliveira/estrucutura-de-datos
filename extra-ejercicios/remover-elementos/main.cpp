#include <iostream>
using namespace std;

// Estructura del Nodo
struct Nodo {
    int valor;
    Nodo *siguiente;

    Nodo(int v) : valor(v), siguiente(nullptr) {
    }
};

// Función para ordenar la lista enlazada
void eliminarDuplicados(Nodo *head) {
    if (head == nullptr) {
        cout << "Lista vazia" << endl;
    }
    Nodo *aux = head;

    while (aux != nullptr) {
        Nodo *aux2 = aux;
        while (aux2->siguiente != nullptr) {
            if (aux->valor == aux2->siguiente->valor) {
                Nodo *nodoDuplicado = aux->siguiente;
                aux->siguiente = aux2->siguiente->siguiente;
                delete nodoDuplicado;
            }
            aux2 = aux2->siguiente;
        }
        aux = aux->siguiente;
    }
}

Nodo *buscarElementos(Nodo *head, int valor) {
    if (head == nullptr) {
        cout << "Lista vazia" << endl;
    }
    Nodo *aux = head;
    while (aux != nullptr) {
        if (aux->valor == valor) {
            cout << aux->valor << endl;
            return aux;
        }
    }
}

void ordenaListatos(Nodo *head) {
    if (head == nullptr) {
        cout << "Lista vazia" << endl;
    }

    Nodo *aux = head;

    while (aux != nullptr) {
        while (aux->siguiente != nullptr) {
            if (aux->valor > aux->siguiente->valor) {
                int valor = aux->valor;
                aux->valor = aux->siguiente->valor;
                aux->siguiente->valor = valor;
            }
            aux = aux->siguiente;
        }
        aux = aux->siguiente;
    }
}

void eliminarElemento(Nodo* head, int valor) {
    if (head == nullptr) {
        cout << "Lista vazia" << endl;
    }

    Nodo *aux = head;

    if(aux->valor == valor) {
        Nodo *nodoDuplicado = aux;
        aux = aux->siguiente;
        delete nodoDuplicado;
        return;
    }
    while (aux != nullptr) {

        aux = aux->siguiente;
    }
}
void desordenadarListados(Nodo *head) {
    if (head == nullptr) {
        cout << "Lista vazia" << endl;
    }

    Nodo *actual = head;
    Nodo *anterior = nullptr;
    Nodo *siguiente = nullptr;

    while (actual) {
        if (actual->valor > actual->siguiente->valor) {
            siguiente = actual->siguiente;
            actual->siguiente = anterior;
            actual->siguiente;
        }
    }
}


// Función para crear una lista enlazada a partir de un array
Nodo *crearLista(int arr[], int tamaño) {
    if (tamaño == 0) return nullptr;

    Nodo *head = new Nodo(arr[0]);
    Nodo *actual = head;
    for (int i = 1; i < tamaño; i++) {
        actual->siguiente = new Nodo(arr[i]);
        actual = actual->siguiente;
    }
    return head;
}

// Función para imprimir la lista enlazada
void imprimirLista(Nodo *head) {
    Nodo *actual = head;
    while (actual != nullptr) {
        cout << actual->valor << " ";
        actual = actual->siguiente;
    }
    cout << endl;
}

int main() {
    int arr[] = {1, 1, 3, 3, 2, 4, 4, 7, 6, 10, 8, 9};
    int tamano = sizeof(arr) / sizeof(arr[0]);

    // Crea la lista enlazada a partir del array
    Nodo *head = crearLista(arr, tamano);

    // Imprime la lista original
    cout << "Lista original: ";
    imprimirLista(head);

    // Invierte la lista
    eliminarDuplicados(head);

    // Imprime la lista invertida
    cout << "Lista Output: ";
    imprimirLista(head);

    buscarElementos(head, 1);

    cout << "Lista original: ";
    imprimirLista(head);

    ordenaListatos(head);

    cout << "Lista Output: ";
    imprimirLista(head);

    cout << "Lista original: ";
    imprimirLista(head);

    eliminarElemento(head, 3);

    cout << "Lista Output: ";
    imprimirLista(head);


    return 0;
}
