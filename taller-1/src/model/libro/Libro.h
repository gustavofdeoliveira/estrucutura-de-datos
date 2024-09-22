#ifndef LIBRO_H
#define LIBRO_H

#pragma once
#include <iostream>
#include <string>
#include <MaterialBibliografico.h>

using namespace std;

class Libro : public MaterialBibliografico {
    private:
        string fechaPublicacion;
        string resume;

    public:
        Libro(std::string nombre, std::string isbn, std::string autor, std::string fechaPublicacion, std::string resumen);
        ~Libro();

        void mostrarInformacion() const override;
};


#endif //LIBRO_H
