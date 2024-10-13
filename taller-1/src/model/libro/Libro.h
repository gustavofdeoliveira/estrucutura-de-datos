#ifndef LIBRO_H
#define LIBRO_H

#pragma once
#include "../material-bibliografico/MaterialBibliografico.h"
#include <iostream>

using namespace std;

class Libro : public MaterialBibliografico {
// Attributes
private:
    string fechaPublicacion;
    string resumen;

public:
    //Construct
    Libro(string nombre, string isbn, string autor, string fechaPublicacion, string resumen);

    //Deconstruct
    ~Libro();

    //Methods
    void mostrarInformacion() const override;
};

#endif //LIBRO_H
