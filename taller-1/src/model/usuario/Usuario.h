#ifndef USUARIO_H
#define USUARIO_H

#include "MaterialBibliografico.h"

using namespace std;


class Usuario {
// Attributes
private:
    string nombre;
    int id;
    MaterialBibliografico *materialesPrestados[5];

public:
    //Constructor
    Usuario(string nombre, int id);

    //Deconstructor
    ~Usuario();

    //Methods
    bool prestarMaterial(MaterialBibliografico *material);

    bool devolverMaterial(MaterialBibliografico *material);

    void mostrarMaterialesPrestados() const;
};


#endif //USUARIO_H
