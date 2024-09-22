#pragma once
#include "Libro.h"

#include <iostream>

using namespace std;

Libro::Libro(std::string nombre, std::string isbn, std::string autor, std::string fechaPublicacion, std::string resumen)
    : MaterialBibliografico(nombre, isbn, autor), fechaPublicacion(fechaPublicacion), resumen(resumen) {}

Libro::~Libro() {}

void Libro::mostrarInformacion() const {
    std::cout << "Libro: " << nombre << "\nAutor: " << autor << "\nISBN: " << isbn
              << "\nFecha de Publicacion: " << fechaPublicacion << "\nResumen: " << resumen << std::endl;
}