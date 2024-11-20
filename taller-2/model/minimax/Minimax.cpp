#include "Minimax.h"
#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int Minimax::evaluar(const Tablero& tablero, char jugador) {
    char ganador = tablero.verificarGanador();
    if (ganador == jugador) return 1;
    if (ganador == 'O' && jugador == 'X') return -1;
    return 0;
}

void Minimax::construirArbol(Nodo& nodo, const Tablero& estado, int profundidad) {
    if (profundidad == 0 || estado.verificarGanador() != ' ') return;

    auto coordenadas = estado.obtenerCoordenadasDisponibles();
    for (const auto& coordenada : coordenadas) {
        Tablero nuevoEstado = estado;
        nuevoEstado.realizarMovimiento(coordenada.first, coordenada.second, nodo.jugador);

        Nodo nuevoNodo(coordenadas, nodo.jugador == 'X' ? 'O' : 'X');
        nodo.movimientos.push_back(nuevoNodo);

        construirArbol(nodo.movimientos.back(), nuevoEstado, profundidad - 1);
    }
}

int Minimax::minimax(Nodo& nodo, const Tablero& estado, int profundidad, bool esMaximizador) {
    if (profundidad == 0 || estado.verificarGanador() != ' ') {
        return evaluar(estado, nodo.jugador);
    }

    int mejorPuntuacion = esMaximizador ? numeric_limits<int>::min() : numeric_limits<int>::max();
    auto coordenadas = estado.obtenerCoordenadasDisponibles();

    for (const auto& coordenada : coordenadas) {
        Tablero nuevoEstado = estado;
        nuevoEstado.realizarMovimiento(coordenada.first, coordenada.second, nodo.jugador);

        Nodo nuevoNodo(coordenadas, nodo.jugador == 'X' ? 'O' : 'X');
        int puntuacion = minimax(nuevoNodo, nuevoEstado, profundidad - 1, !esMaximizador);

        if (esMaximizador) {
            mejorPuntuacion = max(mejorPuntuacion, puntuacion);
        } else {
            mejorPuntuacion = min(mejorPuntuacion, puntuacion);
        }
    }

    return mejorPuntuacion;
}

int Minimax::minimaxComPoda(Nodo& nodo, const Tablero& estado, int profundidad, bool esMaximizador, int alfa, int beta) {
    if (profundidad == 0 || estado.verificarGanador() != ' ') {
        return evaluar(estado, nodo.jugador);
    }

    int mejorPuntuacion = esMaximizador ? numeric_limits<int>::min() : numeric_limits<int>::max();
    auto coordenadas = estado.obtenerCoordenadasDisponibles();

    for (const auto& coordenada : coordenadas) {
        Tablero nuevoEstado = estado;
        nuevoEstado.realizarMovimiento(coordenada.first, coordenada.second, nodo.jugador);

        Nodo nuevoNodo(coordenadas, nodo.jugador == 'X' ? 'O' : 'X');
        int puntuacion = minimaxComPoda(nuevoNodo, nuevoEstado, profundidad - 1, !esMaximizador, alfa, beta);

        if (esMaximizador) {
            mejorPuntuacion = max(mejorPuntuacion, puntuacion);
            alfa = max(alfa, mejorPuntuacion);
        } else {
            mejorPuntuacion = min(mejorPuntuacion, puntuacion);
            beta = min(beta, mejorPuntuacion);
        }

        if (beta <= alfa) break;
    }

    return mejorPuntuacion;
}

pair<int, int> Minimax::encontrarMejorMovimientoSinPoda(Tablero& tablero, char jugador) {
    Nodo nodo(tablero.obtenerCoordenadasDisponibles(), jugador);
    int mejorPuntuacion = numeric_limits<int>::min();
    pair<int, int> mejorMovimiento;

    for (const auto& coordenada : nodo.cordenadasDisponibles) {
        Tablero nuevoEstado = tablero;
        nuevoEstado.realizarMovimiento(coordenada.first, coordenada.second, jugador);

        Nodo nuevoNodo(nodo.cordenadasDisponibles, jugador == 'X' ? 'O' : 'X');
        int puntuacion = minimax(nuevoNodo, nuevoEstado, 3, false); // Limite de profundidade 3

        if (puntuacion > mejorPuntuacion) {
            mejorPuntuacion = puntuacion;
            mejorMovimiento = coordenada;
        }
    }

    return mejorMovimiento;
}

pair<int, int> Minimax::encontrarMejorMovimientoComPoda(Tablero& tablero, char jugador) {
    Nodo nodo(tablero.obtenerCoordenadasDisponibles(), jugador);
    int mejorPuntuacion = numeric_limits<int>::min();
    pair<int, int> mejorMovimiento;
    int alfa = numeric_limits<int>::min();
    int beta = numeric_limits<int>::max();

    for (const auto& coordenada : nodo.cordenadasDisponibles) {
        Tablero nuevoEstado = tablero;
        nuevoEstado.realizarMovimiento(coordenada.first, coordenada.second, jugador);

        Nodo nuevoNodo(nodo.cordenadasDisponibles, jugador == 'X' ? 'O' : 'X');
        int puntuacion = minimaxComPoda(nuevoNodo, nuevoEstado, 3, false, alfa, beta);

        if (puntuacion > mejorPuntuacion) {
            mejorPuntuacion = puntuacion;
            mejorMovimiento = coordenada;
        }
    }

    return mejorMovimiento;
}
