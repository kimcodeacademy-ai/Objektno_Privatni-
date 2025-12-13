// Да се дефинира класа MobilePhone во која ќе се чуваат податоци за еден мобилен телефон:
// модел (низа од карактери не подолга од 20 карактери)
// број на модел (цел број)
// година на издавање (цел број)
// За класата да се дефинира default конструктор, конструктор со аргументи, copy конструктор, деструктор и доколку има потреба get методи.
// Исто така да се дефинира и фунцкија за печатење на информации за класата која ќе печати во следниот формат „(модел) (број на модел) release year: (година на издавање)“.
// Потоа да се дефинира класа Owner во која се чуваат следните информации:
// име (низа од карактери не подолга од 20 карактери)
// презиме (низа од карактери не подолга од 20 карактери)
// мобилен телефон (објект од класа MobilePhone)
// Да се креира default конструктор, конструктор со аргументи, деструктор и доколку има потреба get методи.
// Исто така да се дефинира и функција за печатење на информации за класата која ќе печати во следниот формат:
// „(име) (презиме) has a mobile phone:
// (информации за мобилен телефон)“
//
// ДА НЕ СЕ МЕНУВА MAIN ФУНКЦИЈАТА!!!


// Input	Result
// 1
// Iphone
// 12
// 2020
// Marko
// Petrov
//
// Result
// Marko Petrov has a mobile phone:
// Iphone 12 release year: 2020


#include <iostream>
#include <cstring>
using namespace std;

class MobilePhone {
    char model[21];
    int modelNumber;
    int releaseYear;

public:
    MobilePhone() {
        strcpy(model, "not specified");
        modelNumber = 0;
        releaseYear = 0;
    }

    MobilePhone(char* m, int num, int year) {
        strncpy(model, m, 20);
        modelNumber = num;
        releaseYear = year;
    }

    ~MobilePhone(){}

    MobilePhone(MobilePhone& other) {
        strcpy(model, other.model);
        modelNumber = other.modelNumber;
        releaseYear = other.releaseYear;
    }

    void print() {
        cout << model << " " << modelNumber << " release year: " << releaseYear << endl;
    }
};

class Owner {
    char name[21];
    char surname[21];
    MobilePhone phone;

public:
    Owner() {
        strcpy(surname, "not specified");
        strcpy(name, "not specified");
    }

    Owner ( char* n, char* s, MobilePhone p) {
        strncpy(name, n, 20);
        strncpy(surname, s, 20);
        phone = p;
    }

    ~Owner(){}

    void print() {
        cout << name << " " << surname << " has a mobile phone: " << endl;
        phone.print();
    }

};
//DO NOT CHANGE THE MAIN FUNCTION
int main() {
    char model[20];
    int modelNumber;
    int year;
    char name[20];
    char surname[20];

    int testCase;

    cin>>testCase;

    cin>>model;
    cin>>modelNumber;
    cin>>year;
    cin>>name;
    cin>>surname;

    if(testCase==1){
        MobilePhone mobilePhone(model,modelNumber,year);

        Owner owner(name,surname,mobilePhone);
        owner.print();
    }
    if(testCase==2){
        MobilePhone mobilePhone(MobilePhone(model,modelNumber,year));

        Owner owner(name,surname,mobilePhone);
        owner.print();
    }

}