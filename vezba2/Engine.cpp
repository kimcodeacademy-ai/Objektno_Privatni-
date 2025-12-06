// Да се креира структура Engine во која што ќе се чуваат податоци за коњска сила / horsepower (int) и вртежен момент / torque (int).
// Потоа, да се креира структура Car во која што ќе  се чуваат податоци името на производителот (char array) ,
// која година е произведена колата (int) и кој мотор / engine (Engine) која што го користи/
// На почетокот се внесува број N што озналува колку коли ќе се читаат од влез.
// Да се направи функцијата:
// void printCars(...)
// која што ќе ги земе двете коли кои имаат најмала коњска сила, и од нив две, ќе ја испечати колата што има поголем вртежен момент.

// For example:
//
// Input	Result
// 3
// Opel
// 1999
// 577
// 516
// Audi
// 2000
// 591
// 590
// Citroen
// 2020
// 220
// 321
// Manufacturer: Opel
// Horsepower: 577
// Torque: 516

#include <iostream>
#include <cstring>
using namespace std;

struct Engine {
    int horsepower;
    int torque;
};

struct Car {
    char manufacturer[100];
    int year;
    Engine engine;
};

void printcar(Car car) {
    cout << "Manufacturer: " << car.manufacturer << endl;
    cout << "Horsepower: " << car.engine.horsepower << endl;
    cout << "Torque: " << car.engine.torque << endl;
}

void cars_to_print(Car *cars, int n) {
    int first = -1, second = -1; // potrebni za naogjanje na dvata indexa so najmal horsepower

    for (int i = 0; i < n; i++) {
        // cout << cars[i].manufacturer << endl;
        // cout << cars[i].year << endl;
        // cout << cars[i].engine.horsepower<<endl;
        // cout << cars[i].engine.torque<<endl;
        if (first == -1 || cars[i].engine.horsepower < cars[first].engine.horsepower) {
            second = first;
            first = i;
        }
        else if (second == -1 || cars[i].engine.horsepower < cars[second].engine.horsepower) {
            second = i;
        }
    }

    // Manufacturer: Opel
    // Horsepower: 577
    // Torque: 516
    if (cars[first].engine.torque > cars[second].engine.torque) {
        printcar(cars[first]);
    }
    else {
        printcar(cars[second]);
    }
}

int main() {
    int n;
    cin >> n;
    Car cars[n];

    for (int i = 0; i < n; i++) {
        char manufacturer[100];
        int year, horsepower, torque;
        cin >> manufacturer >> year >> horsepower >> torque;

        strcpy(cars[i].manufacturer, manufacturer);
        cars[i].year = year;
        cars[i].engine.horsepower = horsepower;
        cars[i].engine.torque = torque;
    }

    cars_to_print(cars, n);
}
