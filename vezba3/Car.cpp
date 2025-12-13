// Во оваа задача треба да се внесат и испечатат податоци за автомобили.
//
// За еден автомобил (објект од класата Car) се чуваат следниве податоци:
//
// сопственик (објект од класата Person)
// датум на купување (објект од класата Date)
// цена (float price), предодредена вредност 0
// За класата Car потребно е да се напише метод за печатење print() и метод за добивање на цената getPrice().
//
// Класата Date содржи три цели броеви (int year, month, day) кои претставуваат датум. За неа треба да се напише метод за печатење print(), предодреден (default) конструктор, конструктор со параметри и конструктор за копирање.
// Класата Person содржи име и презиме (низи од максимум 20 знаци, со предодредени вредности not specified), предодреден конструктор, конструктор со параметри и метод за печатење print().
// Методот за печатење кај класата Person изгледа вака: [name] [lastName].
// Методот за печатење кај класата Date изгледа вака: [year].[month].[day].
// Методот за печатење кај класата Car изгледа вака:
// owner.print()
// date.print()
// Price: [price]
// Покрај тоа, потребно е да се напише метод cheaperThan(Car* cars, int numCars, float price) кој ќе ги испечати сите објекти Car од низата cars со големина numCars чија цена е помала од price.
//
// --------------------------
//
//
// Input	Result
// 2
// Petre
// Petreski
// 2018
// 07
// 31
// 410020

//Result:
// Petre Petreski
// 2018.7.31
// Price: 410020

#include <iostream>
#include <cstring>
using namespace std;

class Person {
    char name[21];
    char lastname[21];

public:
    Person() {
        strcpy(name, "not specified");
        strcpy(lastname, "not specified");
    }

    Person(char *n, char *ln) {
        strncpy(name, n, 20);
        strncpy(lastname, ln, 20);
    }

    void print() {
        cout << name << " " << lastname << endl;
    }
};

class Date {
    int year, month, day;
public:
    Date() {
        year = 0;
        month = 0;
        day = 0;
    }
    Date(int y, int m, int d) {
        year = y;
        month = m;
        day = d;
    }

    // copy contructor - passes object from same type as argument
    Date(Date& other) {
        year = other.year;
        month = other.month;
        day = other.day;
    }

    void print() {
        cout << year << "." << month << "." << day << endl;
    }

};

class Car {
    Person owner;
    Date date;
    float price;

public:
    Car() {
        price = 0;
    }
    Car(Person o, Date d, float p = 0) {
        owner = o;
        date = d;
        price = p;

    }
    float getPrice() {
        return price;
    }

    void print() {
        owner.print();
        date.print();
        cout << "Price: " << price << endl;
    }
};

void cheaperThan(Car* cars, int numCars, float price) {
    for (int i = 0; i < numCars; i++) {
        if (cars[i].getPrice() < price) {
            cars[i].print();
        }
    }
}

int main() {
    char name[20];
    char lastName[20];
    int year;
    int month;
    int day;
    float price;

    int testCase;
    cin >> testCase;

    if (testCase == 1) {
        cin >> name;
        cin >> lastName;
        Person lik(name, lastName);

        cin >> year;
        cin >> month;
        cin >> day;
        Date date(year, month, day);

        cin >> price;
        Car car(lik, date,  price);

        car.print();
    }
    else if (testCase == 2) {
        cin >> name;
        cin >> lastName;
        Person lik(name, lastName);

        cin >> year;
        cin >> month;
        cin >> day;
        Date date(Date(year, month, day));

        cin >> price;
        Car car(lik, date,  price);
        car.print();
    }
    else {
        int numCars;
        cin >> numCars;

        Car cars[10];
        for (int i = 0; i < numCars; i++) {
            cin >> name;
            cin >> lastName;
            Person lik(name, lastName);

            cin >> year;
            cin >> month;
            cin >> day;
            Date date(year, month, day);

            cin >> price;
            cars[i] = Car(lik, date,  price);
        }
        float priceLimit;
        cin >> priceLimit;
        cheaperThan(cars, numCars, priceLimit);
    }


    return 0;
}