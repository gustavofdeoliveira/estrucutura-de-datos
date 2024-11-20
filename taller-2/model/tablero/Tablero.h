#ifndef TABLERO_H
#define TABLERO_H

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

const int tres = 3;
const int dos = 2;
const int uno = 1;
const int cero = 0;

class Tablero {
private:
    char tablero[tres][tres];

public:
    Tablero(); // Construtor

    void mostrar() const;

    bool realizarMovimiento(int fila, int columna, char jugador);

    char verificarGanador() const;

    vector<pair<int, int>> obtenerCoordenadasDisponibles() const;

    bool estaLleno() const;
};

#endif // TABLERO_H
