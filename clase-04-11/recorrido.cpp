#include <iostream>

using namespace std;

struct Nodo {
    int dato;
    Nodo *izquierda;
    Nodo *derecho;

    Nodo(int v) : dato(v), izquierda(nullptr), derecho(nullptr) {
    }
};

void recorrido(Nodo *raiz) {
    if (raiz == nullptr) {
        return;
    }
    cout << raiz->dato << endl;
    recorrido(raiz->izquierda);
    recorrido(raiz->derecho);
}
