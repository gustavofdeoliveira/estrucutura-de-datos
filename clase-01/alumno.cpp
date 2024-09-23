#include "alumno.h"

Alumno::Alumno(int edad, string nombre) {  // Definition
    this->edad = edad;
    this->nombre = nombre;
}

string Alumno::getNombre() {
    return this->nombre;
}

int Alumno::getEdad() {
    return this->edad;
}

void Alumno::setNombre(string nombre) {
    this->nombre = nombre;
}

void Alumno::setEdad(int edad) {
    this->edad = edad;
}

Alumno::~Alumno() {
    std::cout << "Se destruye el nodo cono valor" << std::endl;
}

