#ifndef ALUMNO_H
#define ALUMNO_H

#pragma once
#include<iostream>

using namespace std;

class Alumno {
private:
  int edad;
  string nombre;

public:
  //constructor
  Alumno(int edad, string nombre);

  //getters
  string getNombre();
  int getEdad();

  //setters
  void setNombre(string nombre);
  void setEdad(int edad);
  //descontructor
  ~Alumno();

};

#endif // ALUMNO_H
