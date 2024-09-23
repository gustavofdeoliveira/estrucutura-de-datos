#include "Revista.h"
#include <iostream>

using namespace std;

Revista::Revista(string nombre, string isbn, string autor, int numeroEdicion, string mesPublicacion) : MaterialBibliografico(nombre, isbn, autor), numeroEdicion(numeroEdicion), mesPublicacion(mesPublicacion){}
Revista::~Revista(){}

void Revista::mostrarInformacion() const {
    cout << "Revista: " << nombre << "\nAutor: " << autor << "\nISBN: " << isbn
              << "\nNumero de Edicion: " << numeroEdicion << "\nMes de Publicacion: " << mesPublicacion << std::endl;
}
