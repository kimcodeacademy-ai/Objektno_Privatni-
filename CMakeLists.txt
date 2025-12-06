cmake_minimum_required(VERSION 3.26)
project(Objektno_Privatni)

set(CMAKE_CXX_STANDARD 20)

add_executable(main_app main.cpp)
add_executable(agol_app vezba1/Agol.cpp
        vezba2/Engine.cpp
        vezba2/BasketballPlayer.cpp
        vezba2/Country.cpp
        vezba2/examples.cpp
        vezba2/classexamples.cpp
        vezba2/construcotdestructorexample.cpp)
add_executable(krug_app vezba1/Krug.cpp)
add_executable(film_app vezba2/Film.cpp)
add_executable(struct_app
        vezba1/struct/Structzadacha.cpp
)
