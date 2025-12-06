// Да се дефинира класа Country во која ќе се чуваат информации за:
// name(низа од максимум 100 карактери) име на државата
// capital(низа од максимум 100 карактери) главен град
// area(децимален број) - површина во илјада km2
// population(децимален број) - популација во милиони.
// Сите променливи внатре во класата треба да бидат приватни. Соодветно во рамките на класата да се дефинираат:
// конструктор (без и со параметри)
// деструктор
// set методи
// get методи
// Да се дефинираат следните методи во класата:
// display() која што ќе ги печати информациите за drzava во следниот формат:
// Country: Guyana
// Capital: Georgetown
// Area: 214
// Population: 0.8
// Надвор од класата:
// sortCountries(Country *countries, int n) која што ќе ги сортира државите растечки по нивната површина.
// ДА НЕ СЕ МЕНУВА MAIN ФУНКЦИЈАТА.

// Input	Result
// 5
// Brazil Brasília 8515 213.3
// Chile Santiago 756 19.1
// Cyprus Nicosia 9 1.2
// Gambia Banjul 11 2.3
// Greece Athens 131957 10.7

// Result:
// -->Testing set methods and display()
// Country: Greece
// Capital: Athens
// Area: 131957
// Population: 10.7
//
// -->Testing sortCountries()
// Country: Cyprus
// Capital: Nicosia
// Area: 9
// Population: 1.2
// Country: Gambia
// Capital: Banjul
// Area: 11
// Population: 2.3
// Country: Chile
// Capital: Santiago
// Area: 756
// Population: 19.1
// Country: Brazil
// Capital: Brasília
// Area: 8515
// Population: 213.3
// Country: Greece
// Capital: Athens
// Area: 131957
// Population: 10.7

#include<iostream>
#include<cstring>
using namespace std;
class Country {
    char name[100];
    char capital[100];
    double area;
    double population;

public:
    Country() {};

    Country(char *_name, char *_capital, double _area, double _population) {
        strcpy(name, _name);
        strcpy(capital, _capital);
        area = _area;
        population = _population;
    }

    // setters
    void setArea(double area) {
        this->area = area;
    }
    void setPopulation(double population) {
        this->population = population;
    }
    void setName(char *name) {
        strcpy(this->name, name);
    }
    void setCapital(char *capital) {
        strcpy(this -> capital, capital);
    }

    // getters
    char *get_name() {
        return name;
    }
    char *get_capital() {
        return capital;
    }
    double get_area() {
        return area;
    }
    double get_population() {
        return population;
    }

    // Country: Guyana
    // Capital: Georgetown
    // Area: 214
    // Population: 0.8
    void display() {
        // cout << "Country: " << name << endl;
        // cout << "Capital: " << capital << endl;
        // cout << "Area: " << area << endl;
        // cout << "Population: " << population << endl;

        cout << "Country: " << name
        << "\n" << "Capital: " << capital
        << "\n" << "Area: " << area
        << "\n" << "Population: " << population;
    }

};

void printCountries(Country *countries, int n) {
    for (int i = 0; i < n; i++) {
        countries[i].display();
    }
}

void sortCountries(Country *countries, int n) {

    // Outer loop that corresponds to the number of
    // elements to be sorted
    for (int i = 0; i < n - 1; i++) {

        // Last i elements are already
        // in place
        for (int j = 0; j < n - i - 1; j++) {

            // Comparing adjacent elements
            if (countries[j].get_area() > countries[j + 1].get_area())

                // Swapping if in the wrong order
                    swap(countries[j], countries[j + 1]);
        }
    }

    printCountries(countries, n);
}

// DO NOT CHANGE THE MAIN FUNCTION
int main() {
    int n;
    cin >> n;
    Country countries[100];

    char name[100];
    char capital[100];
    double area;
    double population;

    for (int i = 0; i < n-1; i++)  {
        cin>>name;
        cin >> capital;
        cin >> area;
        cin>>population;

        // testing constructor with arguments
        countries[i] = Country(name, capital, area, population);

    }


    // testing set methods and display for last element
    cin>>name;
    cin >> capital;
    cin >> area;
    cin>>population;
    countries[n-1].setName(name);
    countries[n-1].setCapital(capital);
    countries[n-1].setArea(area);
    countries[n-1].setPopulation(population);

    cout<<"-->Testing set methods and display()"<<endl;
    countries[n-1].display();
    cout<<endl;
    cout << endl;
    cout<<"-->Testing sortCountries()"<<endl;
    sortCountries(countries,n);
    return 0;
}