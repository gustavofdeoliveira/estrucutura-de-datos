#include "./model/tablero/Tablero.h"
#include "./model/minimax/Minimax.h"
#include <iostream>
#include <chrono>

using namespace std;

int main() {
    Tablero tablero;
    Minimax minimax;

    cout << "Bem-vindo ao Jogo da Velha!\n";
    tablero.mostrar();

    char jugadorActual = 'X';

    while (tablero.verificarGanador() == ' ' && !tablero.estaLleno()) {
        int fila, columna;
        if (jugadorActual == 'X') {
            cout << "Sua vez (X)!" << endl;
            cout << "Insira linha (0-2): " << endl;
            cin >> fila;
            cout << "Insira coluna (0-2): " << endl;
            cin >> columna;

            if (!tablero.realizarMovimiento(fila, columna, jugadorActual)) {
                cout << "Movimento inválido. Tente novamente.\n";
                continue;
            }
        } else {
            cout << "Turno da IA (O)...\n";
            auto movimiento = minimax.encontrarMejorMovimientoComPoda(tablero, jugadorActual);
            tablero.realizarMovimiento(movimiento.first, movimiento.second, jugadorActual);
        }

        tablero.mostrar();
        jugadorActual = (jugadorActual == 'X') ? 'O' : 'X';
    }

    char ganador = tablero.verificarGanador();
    if (ganador == 'E')
        cout << "Empate!\n";
    else
        cout << "O vencedor é " << ganador << "!\n";

    return 0;
}
