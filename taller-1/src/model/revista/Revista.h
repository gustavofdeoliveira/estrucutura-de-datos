#ifndef REVISTA_H
#define REVISTA_H

#include "MaterialBibliografico.h"

using namespace std;

class Revista : public MaterialBibliografico {
private:
    int numeroEdicion;
    string mesPublicacion;

public:
    Revista(string nombre, string isbn, string autor, int numeroEdicion, string mesPublicacion);
    ~Revista();

    void mostrarInformacion() const override;


};



#endif //REVISTA_H
