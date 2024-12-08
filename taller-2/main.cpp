#include "./model/tablero/Tablero.h"
#include "./model/minimax/Minimax.h"
#include <iostream>

using namespace std;

int main() {
    Tablero tablero;
    Minimax minimax;

    cout << "Bienvenido al Juego del Gato!" << endl;

    // Menu de selección de algoritmo
    int opcion = 0;
    bool mostrarMenu = true;

    do {
        cout << "\nElija el tipo de algoritmo: " << endl;
        cout << "1 - Algoritmo Minimax con Poda" << endl;
        cout << "2 - Algoritmo Minimax sin Poda" << endl;
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Seleccionaste Minimax con Poda." << endl;
                mostrarMenu = false;
                break;
            case 2:
                cout << "Seleccionaste Minimax sin Poda." << endl;
                mostrarMenu = false;
                break;
            default:
                cout << "Opción inválida, por favor intenta nuevamente." << endl;
        }
    } while (mostrarMenu);

    tablero.mostrar();
    char jugadorActual = 'X';

    // Loop principal del juego
    while (tablero.verificarGanador() == ' ' && !tablero.estaLleno()) {
        int fila, columna;
        if (jugadorActual == 'X') {
            cout << "Es tu turno (X)!" << endl;
            cout << "Ingresa la fila (0-2): " << endl;
            cin >> fila;
            cout << "Ingresa la columna (0-2): " << endl;
            cin >> columna;

            if (!tablero.realizarMovimiento(fila, columna, jugadorActual)) {
                cout << "Movimiento inválido. Inténtalo de nuevo.\n";
                continue;
            }
        } else {
            cout << "Turno de la IA (O)...\n";
            auto movimiento = (opcion == 1)
                ? minimax.encontrarMejorMovimientoComPoda(tablero, jugadorActual)
                : minimax.encontrarMejorMovimientoSinPoda(tablero, jugadorActual);

            tablero.realizarMovimiento(movimiento.first, movimiento.second, jugadorActual);
        }

        tablero.mostrar();
        jugadorActual = (jugadorActual == 'X') ? 'O' : 'X';
    }

    char ganador = tablero.verificarGanador();
    if (ganador == 'E')
        cout << "Empate!\n";
    else
        cout << "El ganador es " << ganador << "!\n";

    return 0;
}
