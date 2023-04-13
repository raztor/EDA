cmake_minimum_required(VERSION 3.24)
project(EDA)

set(CMAKE_CXX_STANDARD 14)

add_executable(temp2 "Clases/Clase 3/temp2.c" "Clases/Clase 3/numeros.c")
add_executable(numeros "Clases/Clase 3/numeros.c")
add_executable(saludo "Clases/Clase 4/saludo.cpp")
add_executable(return_numero "Clases/Clase 4/return_numero.cpp")
add_executable(main tareas/tarea-1/src/main.c)