#include <iostream>

using namespace std;

struct Nodo {
  int dato;
  Nodo *izquierda;
  Nodo *derecho;

  Nodo(int v) : dato(v), izquierda(nullptr), derecho(nullptr) {
  }
};

// Função para inserir um novo nodo na ABB
Nodo *insertar(Nodo *nodo, int dato) {
  if (nodo == nullptr) {
    return new Nodo(dato);
  }
  if (dato < nodo->dato) {
    nodo->izquierda = insertar(nodo->izquierda, dato);
  } else {
    nodo->derecho = insertar(nodo->derecho, dato);
  }
  return nodo;
}

// Função para buscar um elemento na ABB
Nodo *bucuscarABBrec(Nodo *r, const int x) {
  if (!r) return nullptr;
  if (r->dato == x) {
    return r;
  }
  if (r->dato < x) {
    return bucuscarABBrec(r->derecho, x); // Corrigido para buscar na direita se x > r->dato
  }
  return bucuscarABBrec(r->izquierda, x);
}

// Função para imprimir a árvore em ordem
void imprimirEnOrden(Nodo *nodo) {
  if (nodo != nullptr) {
    imprimirEnOrden(nodo->izquierda);
    cout << nodo->dato << " ";
    imprimirEnOrden(nodo->derecho);
  }
}

int main() {
  int arr[] = {8, 3, 10, 1, 6, 14, 4, 7, 13}; // Exemplo de array
  int n = sizeof(arr) / sizeof(arr[0]);

  Nodo *raiz = nullptr;

  // Inserindo elementos do array na árvore
  for (int i = 0; i < n; i++) {
    raiz = insertar(raiz, arr[i]);
  }

  cout << "Árvore em ordem: ";
  imprimirEnOrden(raiz);
  cout << endl;

  // Exemplo de busca
  const int valor = 6;
  Nodo *resultado = bucuscarABBrec(raiz, valor);
  if (resultado) {
    cout << "Valor " << valor << " encontrado na arvore." << endl;
  } else {
    cout << "Valor " << valor << " não encontrado na arvore." << endl;
  }

  return 0;
}
