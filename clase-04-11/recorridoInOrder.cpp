#include <iostream>
#include <stack>


using namespace std;

struct Nodo {
  int dato;
  Nodo *izquierda;
  Nodo *derecho;

  Nodo(int v) : dato(v), izquierda(nullptr), derecho(nullptr) {
  }
};

void recorridoInOrder(){
  Stack <Nodo*> s;

  Nodo* p = raiz;

  while(1){}
}
