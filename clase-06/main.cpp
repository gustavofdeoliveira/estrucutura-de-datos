#include <iostream>

using namespace std;

class Nodo
{
public:
    int dato;
    Nodo *sig;
    Nodo(int dato)
    {
        this->dato = dato;
        sig = nullptr;
    }

    ~Nodo()
    {
        std::cout << "Constructor por defecto" << this->dato << std::endl;
    }
};

void eliminarNodo(Nodo *head, int valor)
{
    if (head == nullptr)
    {
        return;
    }

    Nodo *aux = head;

    while (aux != nullptr)
    {
        if (aux->dato == valor)
        {
            if (aux->sig == nullptr || aux == head)
            {
                delete head;
                return;
            }
            Nodo *aux2 = head;
            while (aux2->sig != aux)
            {
                aux2 = aux2->sig;
            }
            aux2->sig = aux->sig;
            delete aux;
            return;
        }
        aux = aux->sig;
    }
}

int main()
{
    Nodo *n1 = new Nodo(1);
    Nodo *n2 = new Nodo(2);
    Nodo *n3 = new Nodo(3);

    n1->sig = n2;
    n2->sig = n3;

    return 0;
}