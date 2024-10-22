#include <iostream>
#include <stack>

using namespace std;

void ordenarEstacionamento(stack<int>& E) {
  stack<int> aux;

  // Si la pila no está vacía
  while (!E.empty()) {
    //Grabo la cima de la pila
    int temp = E.top();
    //Saco la cima de la pila
    E.pop();
    //Mientras la pila auxiliar no esté vacía y la cima de la pila auxiliar sea mayor que la cima de la pila
    while (!aux.empty() && aux.top() > temp) {
      //Paso la cima de la pila auxiliar a la pila
      E.push(aux.top());
      //Saco la cima de la pila auxiliar
      aux.pop();
    }
    //Paso la cima de la pila a la pila auxiliar
    aux.push(temp);
  }

  //Paso los elementos de la pila auxiliar a la pila
  while (!aux.empty()) {
    // Paso la cima de la pila auxiliar a la pila
    E.push(aux.top());

    //Saco la cima de la pila auxiliar
    aux.pop();
  }
}

int main() {
  stack<int> E;
  E.push(1);
  E.push(2);
  E.push(5);
  E.push(10);

  cout << "Stack antes de ordenar: " << endl;
  stack<int> temp = E;
  while (!temp.empty()) {
    cout << temp.top() << endl;
    temp.pop();
  }

  ordenarEstacionamento(E);

  cout << "Stack despues de ordenar: " << endl;
  while (!E.empty()) {
    cout << E.top() << endl;
    E.pop();
  }

  return 0;
}
