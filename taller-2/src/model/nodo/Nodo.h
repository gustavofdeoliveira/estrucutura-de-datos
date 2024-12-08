#ifndef NODO_H
#define NODO_H

#include <vector>
#include <utility>
#include <iostream>

using namespace std;

struct Nodo {
    vector<pair<int, int> > cordenadasDisponibles;
    char jugador;
    int puntos;
    vector<Nodo> movimientos;

    Nodo() : jugador(' '), puntos(0) {
    }
    
    Nodo(const vector<pair<int, int> > &coords, char jug)
        : cordenadasDisponibles(coords), jugador(jug), puntos(0) {
    }
};

#endif // NODO_H
