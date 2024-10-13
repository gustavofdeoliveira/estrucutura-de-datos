#ifndef REVISTA_H
#define REVISTA_H

#include "../material-bibliografico/MaterialBibliografico.h"

using namespace std;

class Revista : public MaterialBibliografico {
// Attributes
private:
    int numeroEdicion;
    string mesPublicacion;

public:
    //Constructor
    Revista(string nombre, string isbn, string autor, int numeroEdicion, string mesPublicacion);

    //Deconstruct
    ~Revista();

    //Methods
    void mostrarInformacion() const override;
};


#endif //REVISTA_H
