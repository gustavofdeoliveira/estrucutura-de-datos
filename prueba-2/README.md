# Prueba 2

## Alumno
- **Nombre:** Gustavo Ferreira de Oliveira
- **RUT:** 400162816

## Descripción del Problema

El problema del caballo de ajedrez consiste en encontrar todos los posibles recorridos
que un caballo puede realizar en un tablero de ajedrez de tamaño NxN, visitando cada
casilla exactamente una vez y volviendo a la posición inicial.


### Reglas del Caballo en el Tablero:
- El caballo puede moverse en 8 direcciones diferentes:
    1. Dos casillas hacia adelante y una hacia la derecha.
    2. Dos casillas hacia adelante y una hacia la izquierda.
    3. Dos casillas hacia atrás y una hacia la derecha.
    4. Dos casillas hacia atrás y una hacia la izquierda.
    5. Una casilla hacia adelante y dos hacia la derecha.
    6. Una casilla hacia adelante y dos hacia la izquierda.
    7. Una casilla hacia atrás y dos hacia la derecha.
    8. Una casilla hacia atrás y dos hacia la izquierda.

### Objetivo:
Encontrar un camino que cubra todas las casillas de un tablero de tamaño `N x N` y regresar a la posición inicial. Si se encuentra una solución, el programa muestra el camino recorrido.


## Estructura del Código

### 1. **Entrada de Datos**
El programa solicita al usuario el tamaño del tablero (N) y la posición inicial del caballo (x, y). El tablero es una matriz cuadrada de tamaño `N x N`, y las coordenadas iniciales indican dónde comenzará el caballo.

```cpp
cin >> tamanoTablero >> coordinarX >> coordinarY;
```

### 2. **Movimientos Posibles**
El vector `movimientosCaballo` contiene los 8 posibles movimientos del caballo en términos de desplazamiento en filas y columnas. El caballo puede moverse en cualquiera de estas direcciones, y el código intenta todas estas opciones para encontrar una solución.

```cpp
const vector<pair<int, int>> movimientosCaballo = {
    {dos, uno}, {uno, dos}, {-uno, dos}, {-dos, uno},
    {-dos, -uno}, {-uno, -dos}, {uno, -dos}, {dos, -uno}
};
```

### 3. **Función `esValida`**
Esta función verifica si la nueva posición del caballo después de un movimiento es válida. La posición es válida si está dentro de los límites del tablero y si la casilla aún no ha sido visitada.

```cpp
bool esValida(int x, int y, int N, vector<vector<bool>> &visitado) {
    return (x >= cero && x < N && y >= cero && y < N && !visitado[x][y]);
}
```

### 4. **Función de DFS (`dfs`)**
La función `dfs` (búsqueda en profundidad) es responsable de explorar todas las posibilidades de movimiento del caballo. Se llama recursivamente para cada nueva posición del caballo, hasta que el caballo haya visitado todas las casillas o hasta que el camino ya no sea posible.

- Si el caballo ha visitado todas las casillas (`i == N * N`), la variable `exito` se marca como `true`, lo que indica que se encontró una solución.
- Si el camino resulta inválido, el caballo retrocede (backtracking), desmarcando la posición.

```cpp
void dfs(int x, int y, int N, int i, vector<vector<int>> &tablero,
         vector<vector<bool>> &visitado, bool &exito, vector<pair<int, int>> &camino) {
    // Marca la posición actual como visitada
    visitado[x][y] = true;
    tablero[x][y] = i; // Marca la posición con el número de la jugada
    camino.push_back({x, y}); // Agrega la posición al camino
    // Explora todos los movimientos posibles
    for (const auto &mov : movimientosCaballo) {
        int nx = x + mov.first;
        int ny = y + mov.second;
        if (esValida(nx, ny, N, visitado)) {
            dfs(nx, ny, N, i + uno, tablero, visitado, exito, camino);
            if (exito) break; // Si encontró la solución, interrumpe
        }
    }
    // Desmarca la posición si no encontró la solución
    if (!exito) {
        tablero[x][y] = cero; // Desmarca la posición
    }
    visitado[x][y] = false;
}
```

### 5. **Salida**
Si se encuentra una solución, el programa imprime la secuencia de movimientos que hizo el caballo para cubrir todas las casillas, regresando a la posición inicial. De lo contrario, informa que no se encontró solución.

```cpp
if (exito) {
    cout << "Output: ";
    for (size_t i = 0; i < camino.size(); i++) {
        cout << "(" << camino[i].first << ", " << camino[i].second << ")";
        if (i < camino.size() - uno) {
            cout << " -> ";
        }
    }
    cout << " -> (" << camino[cero].first << ", " << camino[cero].second << ")" << endl;
} else {
    cout << "¡No hay solución!" << endl;
}
```

## Cómo Usar

1. **Compilar y ejecutar el código**:
    - Para compilar y ejecutar el código en un sistema que tenga el compilador de C++ (como `g++`), siga estos pasos:

### Compilación:
En la terminal o consola, navegue hasta el directorio donde se encuentra el archivo `.cpp` y ejecute el siguiente comando para compilar el código:

```bash
g++ -o main.cpp
```

### Ejecución:
Después de compilar, ejecute el programa con el siguiente comando:

```bash
./main
```

2. **Entrada de Datos**:
    - El programa pedirá al usuario que ingrese el tamaño del tablero y la posición inicial del caballo. Ejemplo de entrada:

   ```
   Ingrese el tamaño del tablero (N) y la posición inicial del caballo (x y):
   Ejemplo: 8 0 0
   Entrada: 8 0 0
   ```

3. **Resultado**:
    - Si el programa encuentra una solución, mostrará la secuencia de movimientos del caballo.
    - Si no hay solución, mostrará el siguiente mensaje:

   ```
   ¡No hay solución!
   ```



