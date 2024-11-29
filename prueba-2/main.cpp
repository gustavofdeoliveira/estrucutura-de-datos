#include <iostream>
#include <vector>
#include <utility>

using namespace std;

const int cero = 0;
const int uno = 1;
const int dos = 2;

// Movimientos posibles del caballo en el tablero
const vector<pair<int, int>> movimientosCaballo = {
    {dos, uno}, {uno, dos}, {-uno, dos}, {-dos, uno},
    {-dos, -uno}, {-uno, -dos}, {uno, -dos}, {dos, -uno}
};

// Función para verificar si una posición es válida en el tablero
bool esValida(int x, int y, int N, vector<vector<bool>> &visitado) {
    return (x >= cero && x < N && y >= cero && y < N && !visitado[x][y]);
}

// DFS para resolver el problema del caballo saltador
void dfs(int x, int y, int N, int i, vector<vector<int>> &tablero,
         vector<vector<bool>> &visitado, bool &exito, vector<pair<int, int>> &camino) {
    // Marca la posición actual como visitada
    visitado[x][y] = true;
    tablero[x][y] = i; // Marca la posición con el número de la jugada
    camino.push_back({x, y}); // Agrega la posición al camino

    // Si todas las posiciones han sido visitadas, el problema está resuelto
    if (i == N * N) {
        exito = true;
    } else {
        // Explora todos los movimientos posibles del caballo
        for (const auto &mov : movimientosCaballo) {
            int nx = x + mov.first;
            int ny = y + mov.second;

            // Si la nueva posición es válida, realiza la llamada recursiva
            if (esValida(nx, ny, N, visitado)) {
                dfs(nx, ny, N, i + uno, tablero, visitado, exito, camino);
                if (exito) break; // Si se encontró una solución, interrumpe
            }
        }
    }

    // Si no
    if (!exito) {
        tablero[x][y] = cero; // Desmarca la posición
    }
    visitado[x][y] = false;
}

int main() {
    // Entrada de datos
    int tamanoTablero, coordinarX, coordinarY;
    cout << "Ingrese el tamaño del tablero (N) y la posición inicial del caballo (x y): " << endl;
    cout << "Ejemplo: 8 0 0" << endl;
    cout << "Entrada: ";
    cin >> tamanoTablero >> coordinarX >> coordinarY;

    // Inicializa el tablero y la matriz de visitados
    bool exito = false;
    vector<vector<int>> tablero(tamanoTablero, vector<int>(tamanoTablero, cero));
    vector<vector<bool>> visitado(tamanoTablero, vector<bool>(tamanoTablero, false));
    vector<pair<int, int>> camino; // Almacena el camino recorrido

    // Ejecuta la función DFS para resolver el problema
    dfs(coordinarX, coordinarY, tamanoTablero, uno, tablero, visitado, exito, camino);

    // Muestra la solución formateada
    if (exito) {
        cout << "Output: ";
        for (size_t i = cero; i < camino.size(); i++) {
            cout << "(" << camino[i].first << ", " << camino[i].second << ")";
            if (i < camino.size() - uno) {
                cout << " -> ";
            }
        }
        cout << " -> (" << camino[cero].first << ", " << camino[cero].second << ")" << endl;
    } else {
        cout << "¡No hay solución!" << endl;
    }

    return cero;
}
