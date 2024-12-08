#include "Minimax.h"
#include <vector>
#include <limits>
#include <chrono>
#include <iostream>

using namespace std;
using namespace chrono;

// Evalúa el estado del tablero para un jugador específico.
int Minimax::evaluar(const Tablero& tablero, char jugador) {
    char ganador = tablero.verificarGanador();
    if (ganador == jugador) return 1;
    if (ganador == 'O' && jugador == 'X') return -1;
    return 0;
}

// Construye el árbol de posibilidades con profundidad definida
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

// Implementa el algoritmo minimax sin poda alfa-beta
int Minimax::minimaxSinPoda(Nodo& nodo, const Tablero& estado, int profundidad, bool esMaximizador) {
    if (profundidad == 0 || estado.verificarGanador() != ' ') {
        return evaluar(estado, nodo.jugador);
    }

    int mejorPuntuacion = esMaximizador ? numeric_limits<int>::min() : numeric_limits<int>::max();
    auto coordenadas = estado.obtenerCoordenadasDisponibles();

    for (const auto& coordenada : coordenadas) {
        Tablero nuevoEstado = estado;
        nuevoEstado.realizarMovimiento(coordenada.first, coordenada.second, nodo.jugador);

        Nodo nuevoNodo(coordenadas, nodo.jugador == 'X' ? 'O' : 'X');
        int puntuacion = minimaxSinPoda(nuevoNodo, nuevoEstado, profundidad - 1, !esMaximizador);

        if (esMaximizador) {
            mejorPuntuacion = max(mejorPuntuacion, puntuacion);
        } else {
            mejorPuntuacion = min(mejorPuntuacion, puntuacion);
        }
    }

    return mejorPuntuacion;
}

// Implementa el algoritmo minimax con poda alfa-beta
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

// Encuentra el mejor movimiento sin poda alfa-beta y mide el tiempo de ejecución.
pair<int, int> Minimax::encontrarMejorMovimientoSinPoda(Tablero& tablero, char jugador) {
    Nodo nodo(tablero.obtenerCoordenadasDisponibles(), jugador);
    int mejorPuntuacion = numeric_limits<int>::min();
    pair<int, int> mejorMovimiento;

    auto inicio = high_resolution_clock::now();

    for (const auto& coordenada : nodo.cordenadasDisponibles) {
        Tablero nuevoEstado = tablero;
        nuevoEstado.realizarMovimiento(coordenada.first, coordenada.second, jugador);

        Nodo nuevoNodo(nodo.cordenadasDisponibles, jugador == 'X' ? 'O' : 'X');
        int puntuacion = minimaxSinPoda(nuevoNodo, nuevoEstado, 3, false); // Limite de profundidade 3

        if (puntuacion > mejorPuntuacion) {
            mejorPuntuacion = puntuacion;
            mejorMovimiento = coordenada;
        }
    }

    auto fin = high_resolution_clock::now();
    auto duracion = duration_cast<milliseconds>(fin - inicio);
    cout << "Tiempo de ejecucion (sin poda): " << duracion.count() << " ms\n";
    cout << "<==========================>" << endl;

    return mejorMovimiento;
}

// Encuentra el mejor movimiento con poda alfa-beta y mide el tiempo de ejecución.
pair<int, int> Minimax::encontrarMejorMovimientoComPoda(Tablero& tablero, char jugador) {
    Nodo nodo(tablero.obtenerCoordenadasDisponibles(), jugador);
    int mejorPuntuacion = numeric_limits<int>::min();
    pair<int, int> mejorMovimiento;
    int alfa = numeric_limits<int>::min();
    int beta = numeric_limits<int>::max();

    auto inicio = high_resolution_clock::now();

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

    auto fin = high_resolution_clock::now();
    auto duracion = duration_cast<milliseconds>(fin - inicio);
    cout << "Tiempo de ejecucion (con poda): " << duracion.count() << " ms\n";
    cout << "<==========================>" << endl;

    return mejorMovimiento;
}
