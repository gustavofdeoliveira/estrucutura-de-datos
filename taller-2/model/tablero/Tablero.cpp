#include "Tablero.h"

#include <algorithm>

Tablero::Tablero() {
    for (int i = cero; i < tres; ++i)
        for (int j = cero; j < tres; ++j)
            tablero[i][j] = ' ';
}

void Tablero::mostrar() const {
    for (int i = cero; i < tres; ++i) {
        for (int j = cero; j < tres; ++j) {
            cout << tablero[i][j];
            if (j < dos) cout << "|";
        }
        cout << "\n";
        if (i < dos) cout << "-----\n";
    }
}

bool Tablero::realizarMovimiento(int fila, int columna, char jugador) {
    if (tablero[fila][columna] == ' ') {
        tablero[fila][columna] = jugador;
        return true;
    }
    return false;
}

char Tablero::verificarGanador() const {
    for (int i = cero; i < tres; ++i) {
        if (tablero[i][cero] != ' ' && tablero[i][cero] == tablero[i][uno] && tablero[i][uno] == tablero[i][dos])
            return tablero[i][cero];
        if (tablero[cero][i] != ' ' && tablero[cero][i] == tablero[uno][i] && tablero[uno][i] == tablero[dos][i])
            return tablero[cero][i];
    }
    if (tablero[cero][cero] != ' ' && tablero[cero][cero] == tablero[uno][uno] && tablero[uno][uno] == tablero[dos][dos])
        return tablero[cero][cero];
    if (tablero[cero][dos] != ' ' && tablero[cero][dos] == tablero[uno][uno] && tablero[uno][uno] == tablero[dos][cero])
        return tablero[cero][dos];
    return estaLleno() ? 'E' : ' ';
}

vector<pair<int, int>> Tablero::obtenerCoordenadasDisponibles() const {
    vector<pair<int, int>> disponibles;
    for (int i = cero; i < tres; ++i)
        for (int j = cero; j < tres; ++j)
            if (tablero[i][j] == ' ') disponibles.push_back({i, j});
    return disponibles;
}

bool Tablero::estaLleno() const {
    for (int i = cero; i < tres; ++i)
        for (int j = cero; j < tres; ++j)
            if (tablero[i][j] == ' ') return false;
    return true;
}
