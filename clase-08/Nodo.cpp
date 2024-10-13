#include <iostream>

#include "Nodo.h"

Nodo::Nodo(int dato)
{
    this->dato = dato;
    // es uno null porque no se sabe a donde apunta
    this->sig = nullptr;
}

int Nodo::getDato()
{
    return this->dato;
}

void Nodo::setDato(int dato)
{
    this->dato = dato;
}

Nodo *Nodo::getSig()
{
    return this->sig;
}

void Nodo::setSig(Nodo *sig)
{
    this->sig = sig;
}

Nodo::~Nodo()
{
    std::cout << "Nodo eliminado" << std::endl;
}