#ifndef LIBRO_H
#define LIBRO_H

#pragma once
#include <MaterialBibliografico.h>
#include <iostream>

using namespace std;

class Libro : public MaterialBibliografico {
    private:
        string fechaPublicacion;
        string resumen;

    public:
        Libro(string nombre, string isbn, string autor, string fechaPublicacion, string resumen);
        ~Libro();

        void mostrarInformacion() const override;
};

#endif //LIBRO_H
