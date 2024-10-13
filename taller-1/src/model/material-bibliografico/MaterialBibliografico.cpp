#include "MaterialBibliografico.h"
#include <iostream>

using namespace std;

//Constructor
MaterialBibliografico::MaterialBibliografico(string nombre, string isbn, string autor) {
    this->nombre = nombre;
    this->isbn = isbn;
    this->autor = autor;
    this->prestado = false;
}

//Methods
bool MaterialBibliografico::isPrestado() {
    return this->prestado;
}

void MaterialBibliografico::setPrestado(bool estado) {
    this->prestado = estado;
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
    this->nombre = nombre;
}

string MaterialBibliografico::setAutor(string autor) {
    this->autor = autor;
}




