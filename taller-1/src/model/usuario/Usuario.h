#ifndef USUARIO_H
#define USUARIO_H

#include "MaterialBibliografico.h"

using namespace std;


class Usuario {
private:
    string nombre;
    string id;
    MaterialBibliografico* material[5];
    public:
    Usuario(string nombre, string id);
    ~Usuario();

    bool pretarMaterial(MaterialBibliografico* material);
    bool devolverMaterial(MaterialBibliografico* material);
    void mostrarMaterialPrestados() const;
};



#endif //USUARIO_H
