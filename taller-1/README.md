# Taller 1

## Alumnos
- **Nombre:** Gustavo Ferreira de Oliveira
- **RUT:** 400162816

## Objetivo

El proyecto consiste en crear un sistema que permita a los usuarios de la biblioteca realizar acciones como agregar nuevos libros, buscar libros por título o autor, y gestionar el préstamo de libros.


## Estructura del proyecto

El proyecto está dividido en los siguientes paquetes:

```
📁 taller-1/
│
├── 📁 src/               
│   ├── 📁 model
│   │     ├── 📁 libro
│   │     ├── 📁 material-bibliografico
│   │     ├── 📁 revista
│   │     └── 📁 usuario
|   │ 
│   └── 📄 main.cpp
└── 📄 README.md

```

- **model:** Contiene las clases que representan los objetos del sistema.
- **main.cpp:** Archivo principal del proyecto.
- **README.md:** Archivo con la descripción del proyecto.

## Ejecución

Para ejecutar el proyecto, se debe compilar el archivo `main.cpp` y ejecutar el archivo generado.

1. Compilar el archivo `main.cpp`, ejecutando el siguiente comando en la terminal:

```bash
g++ src/main.cpp -o main
```

2. Ejecutar el archivo generado:

```bash
./main
```

## Consideraciones

- El proyecto permite agregar nuevos libros, buscar libros por título o autor, gestionar el préstamo de libros, agregar usuarios y buscar usuarios, entre otras funcionalidades. Se recomienda revisar el código fuente para conocer todas las funcionalidades disponibles.

### Recomendaciones

1. Agregar un libro:
   - Para agregar un libro, se debe seleccionar la opción `1` en el menú principal y seguir las instrucciones que se muestran en pantalla.

2. Agregar una revista:
   - Para agregar una revista, se debe seleccionar la opción `2` en el menú principal y seguir las instrucciones que se muestran en pantalla.

3. Listar los materiales bibliográficos:
   - Para listar los materiales bibliográficos, se debe seleccionar la opción `3` en el menú principal.

4. Agregar un usuario:
   - Para agregar un usuario, se debe seleccionar la opción `5` en el menú principal y seguir las instrucciones que se muestran en pantalla.

5. Buscar uno Material Bibliográfico:
   - Para buscar un material bibliográfico, se debe seleccionar la opción `4` en el menú principal y seguir las instrucciones que se muestran en pantalla.

6. Emitir un préstamo:
   - Para emitir un préstamo, se debe seleccionar la opción `6` en el menú principal y seguir las instrucciones que se muestran en pantalla.

7. Devolver un préstamo:
   - Para devolver un préstamo, se debe seleccionar la opción `7` en el menú principal y seguir las instrucciones que se muestran en pantalla.


### Vídeo de demostración

Se adjunta un vídeo de demostración del proyecto en funcionamiento.

- [Video demo](https://www.youtube.com/5DZp8yFbUrI)