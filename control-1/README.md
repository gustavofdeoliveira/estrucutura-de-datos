# Control 1

## Bubble Sort

### Peor Caso 
- El peor caso ocurre cuando el arreglo está ordenado de forma decreciente.
- En este caso, el algoritmo deberá recorrer todo el arreglo y hacer el máximo número de intercambios posibles, lo que implica que cada elemento se compara con todos los demás.
- En cada iteración del bucle externo, se realiza una comparación para cada elemento en el bucle interno.
- Esto resulta en una complejidad temporal de `O(n²)`.

### Mejor Caso

- El mejor caso ocurre cuando el arreglo ya está ordenado.
- El algoritmo todavía ejecuta los dos bucles, pero si el arreglo está ordenado, no necesita hacer ningún intercambio.
- Aunque recorra todo el arreglo, el algoritmo no realiza ningún intercambio, resultando en una complejidad temporal de `O(n)`.

## Insertion Sort

### Peor Caso
- El peor caso ocurre cuando el arreglo está en orden decreciente. En este caso, para cada nuevo elemento, el bucle `while` tendrá que recorrer toda la parte ordenada (hasta el inicio del arreglo) para encontrar el lugar correcto de inserción.
- El número de comparaciones e intercambios en el peor caso es dado por la suma de los primeros `n-1` números enteros.
- La complejidad temporal del peor caso es `O(n²)`.

### Mejor Caso

- El mejor caso para el Insertion Sort ocurre cuando el arreglo ya está ordenado.
- En este caso, el bucle `while` nunca se ejecuta, ya que `array[j]` nunca será mayor que `key`. El algoritmo simplemente recorre el arreglo sin hacer intercambios.
- En este escenario, el algoritmo realiza `n-1` comparaciones, una por cada iteración del bucle externo, resultando en una complejidad temporal de `O(n)`.

## Selection Sort

### Peor Caso

- El peor caso ocurre cuando el arreglo está en cualquier estado (incluso desordenado), ya que el algoritmo siempre realiza el mismo número de comparaciones.
- Para cada iteración del arreglo (es decir, para cada posición `i`), el algoritmo necesita hacer una revisión en el resto del arreglo (desde la posición `i+1` hasta `n`).
- En el primer ciclo, se hacen `n-1` comparaciones, en el segundo ciclo se hacen `n-2` comparaciones, y así sucesivamente, hasta que solo queda 1 comparación.

### Mejor Caso

- El mejor caso también tiene complejidad `O(n²)`. Incluso si el arreglo ya está ordenado, el algoritmo siempre recorre el resto del arreglo para encontrar el elemento más pequeño, lo que significa que no puede ser optimizado para detenerse antes.
- Al igual que en el peor caso, se harán `𝑛(𝑛−1)/2` comparaciones, independientemente del estado inicial del arreglo.

## Búsqueda Binaria

### Peor Caso

- En el peor caso, el valor buscado no está presente en el arreglo. En cada iteración, la búsqueda binaria reduce a la mitad el tamaño del intervalo de búsqueda. Si el arreglo tiene `n` elementos, el número de veces que podemos dividir el arreglo a la mitad hasta que el intervalo de búsqueda se vacíe es proporcional al logaritmo de n en base 2.
- Por lo tanto, en el peor caso, la complejidad temporal de la búsqueda binaria es `O(log n)`, porque en cada iteración descartamos la mitad del arreglo y el número máximo de divisiones hasta que no queden más elementos es `log_2(n)`.

### Mejor Caso

- En el mejor caso, el elemento buscado está exactamente en el medio del arreglo en el primer intento. En este escenario, encontramos el elemento en la primera comparación, resultando en solo una iteración. Sin embargo, en términos de notación asintótica, aunque el mejor caso se encuentre en la primera comparación, la complejidad sigue siendo `O(log n)`, ya que esto se considera en el crecimiento de la función conforme aumenta el tamaño del arreglo.

## Counting Sort

### Peor Caso
- El **peor caso** para el Counting Sort depende de dos factores:
  - `n`, el número de elementos en el arreglo de entrada.
  - `k`, el valor máximo en el arreglo (`max`).
- La complejidad temporal para cada parte del algoritmo:
  1. **Conteo de elementos**: El primer bucle recorre el arreglo de tamaño `n`, por lo tanto, la complejidad es **O(n)**.
  2. **Acumulación de los conteos**: El segundo bucle recorre el arreglo `count[]` de tamaño `max + 1`, por lo que la complejidad es **O(k)**.
  3. **Construcción del arreglo ordenado**: El tercer bucle también recorre el arreglo de tamaño `n`, con complejidad **O(n)**.
  4. **Copia de vuelta al arreglo original**: Este bucle final también recorre el arreglo de tamaño `n`, con complejidad **O(n)**.

Por lo tanto, el tiempo total de ejecución es la suma de las dos partes dominantes, resultando en una complejidad de **O(n + k)**.

### Mejor Caso
- En el **mejor caso**, el Counting Sort se comporta de la misma manera. Esto se debe a que el algoritmo no realiza optimizaciones basadas en la entrada ya ordenada, como lo hacen otros algoritmos de ordenación.
- Aún necesita recorrer el arreglo de entrada para contar los elementos, acumular los conteos y construir el arreglo final. Por lo tanto, el **mejor caso** también tiene complejidad **O(n + k)**.