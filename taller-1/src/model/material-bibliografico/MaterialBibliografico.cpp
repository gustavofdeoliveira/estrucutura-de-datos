#include "MaterialBibliografico.h"
#include <iostream>

using namespace std;

MaterialBibliografico::MaterialBibliografico(string nombre, string isbn, string autor) {
    this->nombre = nombre;
    this->isbn = isbn;
    this->autor = autor;
}

bool MaterialBibliografico::estaPrestado() const {
    return this -> prestado;
}

void MaterialBibliografico::prestar() {
    prestado = true;
}

void MaterialBibliografico::devolver() {
    prestado = false;
}

string MaterialBibliografico::getNombre() {
    return this->nombre;
}

string MaterialBibliografico::getAutor() {
    return this->autor;
}



