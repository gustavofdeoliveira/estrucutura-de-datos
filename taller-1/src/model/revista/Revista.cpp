#include "Revista.h"
#include <iostream>

using namespace std;

Revista::Revista(string nombre, string isbn, string autor, int numeroEdicion,
                 string mesPublicacion) : MaterialBibliografico(nombre, isbn, autor) {
    this->numeroEdicion = numeroEdicion;
    this->mesPublicacion = mesPublicacion;
}

Revista::~Revista() {
    cout << "Destruyendo Revista" << this->nombre << endl;
}

void Revista::mostrarInformacion() const {
    cout << "Revista: " << this->nombre << "\nISBN: " << this->isbn << "\nAutor: " << this->autor
            << "\nNumero de Edicion: " << this->numeroEdicion << "\nMes de Publicacion: " << this->mesPublicacion
            << "\nPrestado: " << (this->prestado ? "Sí" : "No") << endl;
}
