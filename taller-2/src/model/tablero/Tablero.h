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
    // Matriz que representa el tablero del juego
    char tablero[tres][tres];

public:
    // Constructor
    Tablero();

    // Muestra el estado actual del tablero
    void mostrar() const;

    // Realiza un movimiento en el tablero
    bool realizarMovimiento(int fila, int columna, char jugador);

    // Verifica si hay un ganador en el tablero
    char verificarGanador() const;

    // Obtiene las posiciones disponibles en el tablero
    vector<pair<int, int>> obtenerCoordenadasDisponibles() const;

    // Verifica si el tablero está lleno
    bool estaLleno() const;
};

#endif // TABLERO_H
