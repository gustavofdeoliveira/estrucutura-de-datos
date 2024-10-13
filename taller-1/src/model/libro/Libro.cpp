#include "Libro.h"
#include <iostream>

using namespace std;

//Construct
Libro::Libro(string nombre, string isbn, string autor, string fechaPublicacion, string resumen)
    : MaterialBibliografico(nombre, isbn, autor) {
    this->fechaPublicacion = fechaPublicacion;
    this->resumen = resumen;
}

//Deconstruct
Libro::~Libro() {
    cout << "Destruyendo Libro" << this->nombre << endl;
}

//Methods
void Libro::mostrarInformacion() const {
    cout << "Libro: " << this->nombre << "\nAutor: " << this->autor << "\nISBN: " << this->isbn
            << "\nFecha de Publicacion: " << this->fechaPublicacion << "\nResumen: " << this->resumen
            << "\nPrestado: " << (this->prestado ? "Sí" : "No") << endl;
}
