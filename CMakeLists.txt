cmake_minimum_required(VERSION 3.26)
project(Objektno_Privatni)

set(CMAKE_CXX_STANDARD 20)

add_executable(main_app main.cpp)
add_executable(agol_app vezba1/Agol.cpp)
add_executable(krug_app vezba1/Krug.cpp)
add_executable(film_app vezba1/Film.cpp)
add_executable(struct_app
        vezba1/struct/Structzadacha.cpp
)
