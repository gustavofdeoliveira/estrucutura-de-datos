#include "MaterialBibliografico.h"
#include <iostream>

using namespace std;

//Constructor
MaterialBibliografico::MaterialBibliografico(string nombre, string isbn, string autor) {
    this->nombre = nombre;
    this->isbn = isbn;
    this->autor = autor;
}

//Metodos
bool MaterialBibliografico::estaPrestado() const {
    return this -> prestado;
}

void MaterialBibliografico::prestar() {
    prestado = true;
}

void MaterialBibliografico::devolver() {
    prestado = false;
}

//Getters
string MaterialBibliografico::getNombre() {
    return this->nombre;
}

string MaterialBibliografico::getAutor() {
    return this->autor;
}

//Setters
string MaterialBibliografico::setNombre(string nombre) {
    this ->nombre = nombre;
}

string MaterialBibliografico::setAutor(string autor) {
    this -> autor = autor;
}




