cmake_minimum_required(VERSION 3.29)
project(clase_01)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(clase_01
    alumno.cpp
    alumno.h
    main.cpp)
