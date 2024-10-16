#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "model/libro/Libro.h"
#include "model/revista/Revista.h"
#include "model/usuario/Usuario.h"
#include "model/material-bibliografico/MaterialBibliografico.h"

using namespace std;

// Array estáticos de tamaño limitado
MaterialBibliografico *biblioteca[100];
int totalMaterial = 0;

vector<Usuario *> usuarios;

// Funcione para agregar un libro a la biblioteca
void agregarLibro() {
    if (totalMaterial >= 100) {
        cout << "La biblioteca ha alcanzado su capacidad maxima de materiales." << endl;
        return;
    }

    string nombre, isbn, autor, fechaPublicacion, resumen;
    cout << "Ingrese el nombre del libro: ";
    cin.ignore();
    getline(cin, nombre);
    cout << "Ingrese el ISBN del libro: ";
    getline(cin, isbn);
    cout << "Ingrese el autor del libro: ";
    getline(cin, autor);
    cout << "Ingrese la fecha de publicacion: ";
    getline(cin, fechaPublicacion);
    cout << "Ingrese el resumen del libro: ";
    getline(cin, resumen);

    biblioteca[totalMaterial++] = new Libro(nombre, isbn, autor, fechaPublicacion, resumen);
    cout << "Libro agregado con exito." << endl;
}

// Función para agregar una revista a la biblioteca
void agregarRevista() {
    if (totalMaterial >= 100) {
        cout << "La biblioteca ha alcanzado su capacidad maxima de materiales." << endl;
        return;
    }

    string nombre, isbn, autor, mesPublicacion;
    int numeroEdicion;
    cout << "Ingrese el nombre de la revista: ";
    cin.ignore();
    getline(cin, nombre);
    cout << "Ingrese el ISBN de la revista: ";
    getline(cin, isbn);
    cout << "Ingrese el autor de la revista: ";
    getline(cin, autor);
    cout << "Ingrese el numero de edicion: ";
    cin >> numeroEdicion;
    cin.ignore();
    cout << "Ingrese el mes de publicacion: ";
    getline(cin, mesPublicacion);

    biblioteca[totalMaterial++] = new Revista(nombre, isbn, autor, numeroEdicion, mesPublicacion);
    cout << "Revista agregada con exito." << endl;
}

// Función para listar los materiales de la biblioteca
void listarMateriales() {
    for (int i = 0; i < totalMaterial; ++i) {
        biblioteca[i]->mostrarInformacion();
        cout << "-----------------------" << endl;
    }
}

// Función para buscar un material en la biblioteca
void buscarMaterial() {
    string criterio;
    cout << "Ingrese el titulo o autor a buscar: ";
    cin.ignore();
    getline(cin, criterio);

    for (int i = 0; i < totalMaterial; ++i) {
        if (biblioteca[i]->getNombre().find(criterio) != string::npos ||
            biblioteca[i]->getAutor().find(criterio) != string::npos) {
            biblioteca[i]->mostrarInformacion();
            cout << "-----------------------" << endl;
        }
    }
}

// Función para buscar un usuario por su ID
Usuario *buscarUsuario(int id) {
    for (Usuario *usuario: usuarios) {
        if (usuario->getId() == id) {
            return usuario;
        }
    }
    return nullptr;
}

// Función para agregar un usuario a la biblioteca
void agregarUsuario() {
    string nombre;
    int id;
    cout << "Ingrese el nombre del usuario: ";
    cin.ignore();
    getline(cin, nombre);
    cout << "Ingrese el ID del usuario: ";
    cin >> id;

    if (buscarUsuario(id) != nullptr) {
        cout << "El usuario con ese ID ya existe." << endl;
        return;
    }

    usuarios.push_back(new Usuario(nombre, id));
    cout << "Usuario agregado con éxito." << endl;
}

// Función para prestar un material a un usuario
void prestarMaterial() {
    int idUsuario;
    cout << "Ingrese el ID del usuario que va a prestar un material: ";
    cin >> idUsuario;

    Usuario *usuario = buscarUsuario(idUsuario);
    if (!usuario) {
        cout << "Usuario no encontrado." << endl;
        return;
    }

    string nombreMaterial;
    cout << "Ingrese el nombre del material a prestar: ";
    cin.ignore();
    getline(cin, nombreMaterial);

    for (int i = 0; i < totalMaterial; ++i) {
        if (biblioteca[i]->getNombre() == nombreMaterial) {
            if (usuario->prestarMaterial(biblioteca[i])) {
                cout << "Material prestado con éxito." << endl;
            }
            return;
        }
    }
    cout << "Material no encontrado." << endl;
}

// Función para devolver un material prestado por un usuario
void devolverMaterial() {
    int idUsuario;
    cout << "Ingrese el ID del usuario que va a devolver un material: ";
    cin >> idUsuario;

    Usuario *usuario = buscarUsuario(idUsuario);
    if (!usuario) {
        cout << "Usuario no encontrado." << endl;
        return;
    }

    string nombreMaterial;
    cout << "Ingrese el nombre del material a devolver: ";
    cin.ignore();
    getline(cin, nombreMaterial);

    for (int i = 0; i < totalMaterial; ++i) {
        if (biblioteca[i]->getNombre() == nombreMaterial) {
            usuario->devolverMaterial(biblioteca[i]);
            return;
        }
    }
    cout << "Material no encontrado." << endl;
}

// Función para mostrar el menú de opciones
void mostrarMenu() {
    cout << "\n---- Biblioteca ----\n";
    cout << "1. Agregar Libro\n";
    cout << "2. Agregar Revista\n";
    cout << "3. Listar Materiales\n";
    cout << "4. Buscar Material\n";
    cout << "5. Agregar Usuario\n";
    cout << "6. Prestar Material\n";
    cout << "7. Devolver Material\n";
    cout << "0. Salir\n";
    cout << "Ingrese una opcion: ";
}

int main() {
    int opcion;

    do {
        mostrarMenu();
        cin >> opcion;

        switch (opcion) {
            case 1:
                agregarLibro();
                break;
            case 2:
                agregarRevista();
                break;
            case 3:
                listarMateriales();
                break;
            case 4:
                buscarMaterial();
                break;
            case 5:
                agregarUsuario();
                break;
            case 6:
                prestarMaterial();
                break;
            case 7:
                devolverMaterial();
                break;
            case 0:
                cout << "Saliendo del sistema." << endl;
                break;
            default:
                cout << "Opcion no valida. Intente de nuevo." << endl;
        }
    } while (opcion != 0);

    // Liberar la memoria al final del programa
    for (int i = 0; i < totalMaterial; ++i) {
        delete biblioteca[i];
    }

    for (Usuario *usuario: usuarios) {
        delete usuario;
    }

    return 0;
}
