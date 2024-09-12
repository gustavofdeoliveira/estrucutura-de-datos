# Control 1

## Bubble Sort

### Pior Caso 
- O pior caso ocorre quando o array está ordenado de forma decrescente.
- Neste caso, o algoritmo precisará percorrer o array inteiro e fazer o máximo número de trocas possíveis, o que implica que cada elemento é comparado com todos os outros.
- A cada iteração do laço externo, uma comparação é feita para cada elemento no laço interno.
- Isso resulta em uma complexidade de tempo de `O(n²)`.

### Melhor Caso

- O melhor caso ocorre quando o array já está ordenado.
- O algoritmo ainda executa os dois laços, mas, se o array estiver ordenado, ele não precisa fazer nenhuma troca.
- Mesmo tendo que percorrer o array inteiro, o algoritmo não faz nenhuma troca, resultando em uma complexidade de tempo de `O(n)`.

## Insertation Sort

### Pior Caso
- O pior caso ocorre quando o array está em ordem decrescente. Neste caso, para cada novo elemento, o laço `while` terá que percorrer toda a parte ordenada (até o início do array) para encontrar o lugar correto de inserção.
- O número de comparações e trocas no pior caso é dado pela soma dos primeiros `n-1` números inteiros.
- A complexidade de tempo do pior caso é `O(n²)`.


### Melhor Caso

- O melhor caso para o Insertion Sort ocorre quando o array já está ordenado.
- Nesse caso, o laço `while` nunca é executado, pois `array[j]` nunca será maior que `key`. O algoritmo simplesmente percorre o array sem fazer trocas.
- Nesse cenário, o algoritmo executa `n-1` comparações, uma vez para cada iteração do laço externo, resultando em uma complexidade de tempo de `O(n)`.


## Selection Sort

## Pior Caso

- O pior caso ocorre quando o array está em qualquer estado (inclusive desordenado), pois o algoritmo sempre faz o mesmo número de comparações.
- Para cada iteração do array (ou seja, para cada posição `i`), o algoritmo precisa fazer uma varredura no restante do array (da posição `i+1` até `n`).
- No primeiro ciclo, são feitas `n-1` comparações, no segundo ciclo são feitas `n-2` comparações, e assim por diante, até que restam apenas 1 comparação.

## Melhor Caso

- O melhor caso também tem complexidade `O(n²)`. Mesmo que o array já esteja ordenado, o algoritmo sempre percorre o restante do array para encontrar o menor elemento, o que significa que ele não pode ser otimizado para parar mais cedo.
- Assim como no pior caso, serão feitas `𝑛(𝑛−1)/2` comparações, independentemente da ordenação inicial do array.

