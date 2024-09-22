#ifndef MATERIALBIBLIOGRAFICO_H
#define MATERIALBIBLIOGRAFICO_H

#pragma once

#include <string>
using namespace std;

class MaterialBibliografico{
  private:
    string nombre;
    string isbn;
    string autor;
    bool prestado;
  public:
    //Constructor
    MaterialBibliografico(string nombre, string isbn, string autor);

    virtual void mostrarInformacion() const = 0;
    bool estaPrestado() const;
    void prestar();
    void devolver();

    string getNombre();
    string getAutor();
    //Descontructor
    ~MaterialBibliografico();
};
#endif