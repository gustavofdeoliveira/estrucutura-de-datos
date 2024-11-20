#include <iostream>

using namespace std;

struct Nodo {
  int dato;
  Nodo *izquierda;
  Nodo *derecho;

  Nodo(int v) : dato(v), izquierda(nullptr), derecho(nullptr) {
  }
};

int cantarMayor(Nodo *p, int x) {
  //Se for nulo o valor
  if (!p) {
    //retorno zero
    return 0;
  }
  //Se o valor da dado atual é maior que x
  if (p->dato > x) {
    //Soma 1 (conta o nó atual).
    //Continua a busca recursiva
    //chama primeiro o filho filho esquerdo(p->izquierda)
    ////Se existir, vai retorna 1
    //Posteriormente, busca no filho direito(p->derecho) e se existir, soma 1
    return 1 + cantarMayor(p->izquierda, x) + cantarMayor(p->derecho, x);
  }else {
    //
    return cantarMayor(p->derecho, x);
  }
}

int main() {
  // Construção manual de uma árvore binária
  Nodo *raiz = new Nodo(10);
  raiz->izquierda = new Nodo(5);
  raiz->derecho = new Nodo(15);
  raiz->izquierda->izquierda = new Nodo(3);
  raiz->izquierda->derecho = new Nodo(7);
  raiz->derecho->izquierda = new Nodo(12);
  raiz->derecho->derecho = new Nodo(18);

  int x = 10; // Valor de referência
  int resultado = cantarMayor(raiz, x);

  cout << "Numero de nos com valor maior que " << x << ": " << resultado << endl;

  // Liberar a memória da árvore
  delete raiz->izquierda->izquierda;
  delete raiz->izquierda->derecho;
  delete raiz->derecho->izquierda;
  delete raiz->derecho->derecho;
  delete raiz->izquierda;
  delete raiz->derecho;
  delete raiz;

  return 0;
}
