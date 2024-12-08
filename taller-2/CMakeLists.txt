cmake_minimum_required(VERSION 3.29)
project(taller_2)

set(CMAKE_CXX_STANDARD 14)

add_executable(taller_2
        src/main.cpp
        src/model/tablero/Tablero.h
        src/model/tablero/Tablero.cpp
        src/model/minimax/Minimax.h
        src/model/minimax/Minimax.cpp
        src/model/nodo/Nodo.h
)
