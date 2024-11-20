cmake_minimum_required(VERSION 3.29)
project(taller_2)

set(CMAKE_CXX_STANDARD 14)

add_executable(taller_2
    main.cpp
        model/tablero/Tablero.h
        model/tablero/Tablero.cpp
        model/minimax/Minimax.h
        model/minimax/Minimax.cpp
        model/nodo/Nodo.h
)
