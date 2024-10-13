#ifndef MATERIALBIBLIOGRAFICO_H
#define MATERIALBIBLIOGRAFICO_H

#pragma once

#include <string>
using namespace std;

class MaterialBibliografico {
// Attributes
protected:
  string nombre;
  string isbn;
  string autor;
  bool prestado;

public:
  //Construct
  MaterialBibliografico(string nombre, string isbn, string autor);

  //Deconstruct
  virtual ~MaterialBibliografico() {
  };

  //Methods
  virtual void mostrarInformacion() const = 0;

  bool isPrestado();

  void setPrestado(bool estado);


  //Getters
  string getNombre();

  string getAutor();

  //Setters
  string setNombre(string nombre);

  string setAutor(string autor);
};
#endif
