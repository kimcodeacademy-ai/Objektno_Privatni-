// Да се дефинира класа Film, во која ќе се чуваат информации за:
//
// име низа од 100 знаци
// режисер низа од 50 знаци
// жанр низа од 50 знаци
// година цел број
// Сите променливи треба да бидат приватни. Соодветно во рамките на класата да се дефинираат:
//
// default конструктор и конструктор со аргументи
// метод за печатење на информациите за филмот
// Дополнително да се реализира надворешна функција:
//
// void pecati_po_godina(Film *f, int n, int godina) која ќе прима аргумент низа од филмови, вкупниот број на филмови и година, а треба да ги отпечати само филмовите кои се направени во дадената година.
// For example:
//
// Input	Result
// 4
// Frankenweenie
// Tim_Burton
// Animation
// 2012
// Lincoln
// Steven_Spielberg
// History
// 2012
// Wall-E
// Andrew_Stanton
// Animation
// 2008
// Avatar
// James_Cameron
// Fantasy
// 2009
// 2008

// Result:
// Ime: Wall-E
// Reziser: Andrew_Stanton
// Zanr: Animation
// Godina: 2008


#include <iostream>
#include <cstring>
using namespace std;

class Movie {
    char name[100];
    char director[100];
    char genre[50];
    int year;

public:
    // default constructor
    Movie(){}
    // generated from clion
    // Movie() = default;

    // constructor with arguments
    Movie(char *_name, char *_director, char *_genre, int _year) {
        strcpy(name, _name);
        strcpy(director, _director);
        strcpy(genre, _genre);
        year = _year;
    }

    // constructor generated from clion
    // explicit Movie(int year)
    //     : year(year) {
    // }


    // Ime: Wall-E
    // Reziser: Andrew_Stanton
    // Zanr: Animation
    // Godina: 2008
    void readMovie() {
        cout<< "Ime: " << name << endl;
        cout<< "Reziser: " << director << endl;
        cout<< "Zanr: " << genre << endl;
        cout<< "Godina: " << year << endl;
    }

    int getYear() {
        return year;
    }

    // getter generated from clion
    // [[nodiscard]] int year1() const {
    //     return year;
    // }
};

void pecati_po_godina(Movie *f, int n, int godina) {
    for (int i = 0; i < n; i++) {
        if (f[i].getYear() == godina) {
            f[i].readMovie();
        }
    }
}

int main() {
    // 4
    // Frankenweenie
    // Tim_Burton
    // Animation
    // 2012

    int n;
    cin >> n;
    Movie movies[n];

    for (int i = 0; i < n; i++) {
        char name[100];
        char director[100];
        char genre[50];
        int year;
        cin >> name >> director >> genre >> year;
        movies[i] = Movie(name, director, genre, year);
    }

    int releaseYear;
    cin >> releaseYear;

    pecati_po_godina(movies, n, releaseYear);
}
