#ifndef MINIMAX_H
#define MINIMAX_H

#include "../nodo/Nodo.h"
#include "../tablero/Tablero.h"
#include <utility>
#include <iostream>

using namespace std;

class Minimax {
public:
    int evaluar(const Tablero& tablero, char jugador);

    void construirArbol(Nodo& nodo, const Tablero& estado, int profundidad);

    int minimax(Nodo& nodo, const Tablero& estado, int profundidad, bool esMaximizador);
    int minimaxComPoda(Nodo& nodo, const Tablero& estado, int profundidad, bool esMaximizador, int alfa, int beta);

    pair<int, int> encontrarMejorMovimientoSinPoda(Tablero& tablero, char jugador);
    pair<int, int> encontrarMejorMovimientoComPoda(Tablero& tablero, char jugador);
};

#endif // MINIMAX_H
