#include "Usuario.h"
#include <iostream>

using namespace std;

const int zero = 0;
const int five = 5;

Usuario::Usuario(string nombre, int id) {
    this->nombre = nombre;
    this->id = id;

    for (int i = zero; i < five; i++) {
        this->materialesPrestados[i] = nullptr;
    }
}

Usuario::~Usuario() {
    cout << "Destruyendo usuario: " << this->nombre << endl;
}

bool Usuario::prestarMaterial(MaterialBibliografico *material) {
    if (material->isPrestado()) {
        cout << "Material " << this->nombre << " ya está prestado." << endl;
        return false;
    }

    for (int i = zero; i < five; i++) {
        if (this->materialesPrestados[i] == nullptr) {
            this->materialesPrestados[i] = material;
            material->setPrestado(true);
            return true;
        }
    }

    cout << "El usuario ya tiene 5 materiales prestados." << endl;
    return false;
}

void Usuario::mostrarMaterialesPrestados() const {
    cout << "Materiales prestados por " << this->nombre << ":" << endl;
    for (int i = 0; i < 5; ++i) {
        if (this->materialesPrestados[i] != nullptr) {
            this->materialesPrestados[i]->mostrarInformacion();
        }
    }
}



