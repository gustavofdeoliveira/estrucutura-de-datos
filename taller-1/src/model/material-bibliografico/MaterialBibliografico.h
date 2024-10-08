#ifndef MATERIALBIBLIOGRAFICO_H
#define MATERIALBIBLIOGRAFICO_H

#pragma once

#include <string>
using namespace std;

class MaterialBibliografico{
  //atributos de la classe
  protected:
    string nombre;
    string isbn;
    string autor;
    bool prestado;
  public:
    //Constructor
    MaterialBibliografico(string nombre, string isbn, string autor);

    //Metodos
    virtual void mostrarInformacion() const = 0;
    bool estaPrestado() const;
    void prestar();
    void devolver();

    //Getters
    string getNombre();
    string getAutor();

    //Setters
    string setNombre(string nombre);
    string setAutor(string autor);

    //Descontructor
    ~MaterialBibliografico();
};
#endif