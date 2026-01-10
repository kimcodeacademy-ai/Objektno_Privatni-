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
        vezba2/construcotdestructorexample.cpp
        vezba3/Car.cpp
        vezba3/MobilePhoneOwner.cpp
        vezba4/copyconstructor.cpp
        vezba4/thispointer.cpp
        vezba4/staticexample.cpp
        vezba4/VideoGame.cpp
        vezba4/Mountain.cpp
        vezba5/vekdotr2d.cpp
        vezba5/brojac.cpp
        vezba5/niza.cpp
        vezba5/matrica-lab.cpp
        vezba5/ingredient.cpp
        vezba7/upcasting.cpp
        vezba7/upcastingvsdowncasting.cpp
        vezba7/polymorphismexample.cpp
        vezba7/dynamiccastexample.cpp
        vezba7/hotelroom.cpp
        vezba7/actors.cpp
)
add_executable(krug_app vezba1/Krug.cpp)
add_executable(film_app vezba2/Film.cpp)
add_executable(struct_app
        vezba1/struct/Structzadacha.cpp
)
