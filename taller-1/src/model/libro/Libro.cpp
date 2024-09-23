#include "Libro.h"
#include <iostream>

using namespace std;

Libro::Libro(string nombre, string isbn, string autor, string fechaPublicacion, string resumen)
    : MaterialBibliografico(nombre, isbn, autor), fechaPublicacion(fechaPublicacion), resumen(resumen) {}

Libro::~Libro() {}

void Libro::mostrarInformacion() const {
    cout << "Libro: " << this->nombre << "\nAutor: " << autor << "\nISBN: " << isbn
              << "\nFecha de Publicacion: " << fechaPublicacion << "\nResumen: " << resumen << endl;
}