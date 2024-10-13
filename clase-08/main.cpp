#include <iostream>

#include "Nodo.h"

Nodo *buscarNodo(Nodo *head, int dato)
{
    Nodo *aux = head;
    while (aux != nullptr)
    {
        if (aux->getDato() == dato)
        {
            return aux->getSig();
        }
        aux = aux->getSig();
    }

    return 0;
}

Nodo *eliminarNodo(Nodo *head, int dato)
{
    Nodo *aux = buscarNodo(head, dato);
    if (aux == nullptr)
    {
        return head;
    }

    if (head == aux)
    {
        head = head->getSig();
        delete aux;
        return head;
    }

    Nodo *aux2 = head;

    while (aux2->getSig() != aux)
    {
        aux2 = aux2->getSig();
    }

    if (aux->getSig() == nullptr)
    {
        aux2->setSig(nullptr);
        delete (aux);
        return head;
    }

    aux2->setSig(aux->getSig());
    delete (aux);
}

Nodo *insertarNodo(Nodo *head, int dato)
{
    Nodo *nuevo = new Nodo(dato);
    if (head == nullptr)
    {
        return nuevo;
    }
    if (head->getDato() > dato)
    {
        nuevo->setSig(head);
        return nuevo;
    }
    Nodo *aux = head->getSig();
    Nodo *aux2 = head;
    while (aux != nullptr)
    {
        if (aux->getDato() > dato)
        {
            nuevo->setSig(aux);
            aux2->setSig(nuevo);
            return head;
        }
        aux2 = aux;
        aux = aux->getSig();
    }
    aux->setSig(nuevo);
    return head;
}

void imprimirLista(Nodo *head)
{
    Nodo *aux = head;
    while (aux != nullptr)
    {
        std::cout << aux->getDato() << " " << std::endl;
        aux = aux->getSig();
    }
    std::cout << std::endl;
    return;
}

Nodo *ordenarLista(Nodo *head)
{
    if (head == nullptr)
    {
        return head;
    }

    Nodo *newHead = new Nodo(head->getDato());

    Nodo *nuevaLista = eliminarNodo(head, head->getDato());

    if(nuevaLista == nullptr){
        return newHead;
    }

    Nodo *aux = nuevaLista->getSig();

    while (aux != nullptr)
    {
        Nodo *aux2 = insertarNodo(newHead, aux->getDato());
    }
}

int main()
{
    Nodo *nodo1 = new Nodo(5);
    Nodo *nodo2 = new Nodo(10);
    Nodo *nodo3 = new Nodo(15);
    nodo1->setSig(nodo2);
    nodo2->setSig(nodo3);
    imprimirLista(nodo1);
    Nodo *aux = insertarNodo(nodo1, 0);

    imprimirLista(aux);

    aux = eliminarNodo(aux, 10);
    return 0;
}