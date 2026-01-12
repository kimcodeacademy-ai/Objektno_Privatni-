// Креирај апстрактна класа CelestialBody (небесно тело) што ќе ја користиме за опишување на планети и џуџести планети. Kласата треба да ги содржи следните информации:
//
// име на телото - (динамички алоцирана низа од знаци)
//  маса во земјини маси - (реален број)
//  оддалеченост од Сонцето во астрономски единици - (реален број)
// Класата треба да ги има следните два виртуелни методи:
//
// calculateGravity - за пресметување на гравитација.
// printInfo - принтање
// Од оваа класа да се изведат класите Planet и DwarfPlanet . Во класата Planet дополнително се чуваат следните информации:
//
//  број на месечини (цел број)
// За секоја џуџеста планета (DwarfPlanet) дополнително се чуваат следните информации:
// дали е во Кајперовиот појас(bool вредност)
// За секоја планета (Planet) потребно е да се обезбеди метод (calculateGravity) за пресметување на гравитацијата на планетата според следново:
//
// Гравитација = маса / (растојание²). Доколку има повеќе од 2 месечини, гравитацијата се зголемува за 10%.
//
// За секоја џуџеста планета (DwarfPlanet) потребно е да се обезбеди метод (calculateGravity) за пресметување на гравитација според следново:
//
// Гравитација = маса / (растојание²).Доколку џуџестата планета не е во Кајперовиот појас тогаш гравитацијата се намалува за 20%.
//
// Функцијата за печатење на податоци за секое небесно тело треба да биде во следниов формат:
//
// За планета (Planet):
//
// [име]-[број на месечини] - gravity impact: [вредност]
// За џуџеста планета (DwarfPlanet):
//
// ***доколку е во Кајперов појас се печати in Kuiper Belt а ако не е out of Kuiper Belt.
//
// [име]-[in/out of Kuiper Belt] - gravity impact: [вредност]
// Да се дефинира глобална функција float mostGravitationalBody(CelestialBody* bodies[], int n) што на влез прима низа од покажувачи кон објекти од класата CelestialBody и нивниот број, а како резултат ја враќа гравитацијата на небесното тело со најголема гравитација.


#include <iostream>
#include <cstring>
using namespace std;

class CelestialBody {
protected:
    char *name;
    float mass;
    float distanceFromSun;

public:
    CelestialBody(char *name, float mass, float distanceFromSun) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        this->mass = mass;
        this->distanceFromSun = distanceFromSun;
    }

    virtual double calculateGravity() = 0;
    virtual void printInfo() = 0;

    virtual ~CelestialBody() {}
};

//За секоја планета (Planet) потребно е да се обезбеди метод (calculateGravity) за пресметување на гравитацијата на планетата според следново:
//
// Гравитација = маса / (растојание²). Доколку има повеќе од 2 месечини, гравитацијата се зголемува за 10%.
//
// За секоја џуџеста планета (DwarfPlanet) потребно е да се обезбеди метод (calculateGravity) за пресметување на гравитација според следново:
//
// Гравитација = маса / (растојание²).Доколку џуџестата планета не е во Кајперовиот појас тогаш гравитацијата се намалува за 20%.

class Planet : public CelestialBody {
    int numberOfMoons;
public:
    Planet(char *name, float mass, float distanceFromSun, int numberOfMoons) :  CelestialBody(name, mass,distanceFromSun){
        this->numberOfMoons = numberOfMoons;
    }

    double calculateGravity() {
        double result = mass / (distanceFromSun * distanceFromSun);
        if (numberOfMoons > 2) {
            result = result*1.1;
        }
        return result;
    }

    void printInfo() {
        cout << name << " - ";
        cout << mass << " - ";
        cout << "gravity impact: " << calculateGravity() << endl;
    }
};

// Функцијата за печатење на податоци за секое небесно тело треба да биде во следниов формат:
//
// За планета (Planet):
//
// [име]-[број на месечини] - gravity impact: [вредност]
// За џуџеста планета (DwarfPlanet):
//
// ***доколку е во Кајперов појас се печати in Kuiper Belt а ако не е out of Kuiper Belt.
//
// [име]-[in/out of Kuiper Belt] - gravity impact: [вредност]
class DwarfPlanet : public CelestialBody {
    bool inKuiperBelt;
public:
    DwarfPlanet(char *name, float mass, float distanceFromSun, bool inKuiperBelt) :  CelestialBody(name, mass,distanceFromSun){
        this->inKuiperBelt = inKuiperBelt;
    }

    double calculateGravity() {
        double result = mass / (distanceFromSun * distanceFromSun);
        if (inKuiperBelt) {
            result = result*0.8;
        }
        return result;
    }

    void printInfo() {
        cout << name << " - ";
        if (inKuiperBelt) {
            cout << "in Kuiper Belt" << " - ";
        }
        else {
            cout << "out of Kuiper Belt" << " - ";
        }
        cout << "gravity impact: " << calculateGravity() << endl;
    }
};

float mostGravitationalBody(CelestialBody* bodies[], int n) {
    double maxGravity = bodies[0]->calculateGravity();

    for (int i = 1; i < n; i++) {
        if (bodies[i]->calculateGravity() > maxGravity) {
            maxGravity = bodies[i]->calculateGravity();
        }
    }
    return  maxGravity;
}


int main() {
    int n;
    cin >> n;

    CelestialBody* bodies[n];

    for (int i = 0; i < n; ++i) {
        char type[30];
        char name[30];
        float mass;
        float distanceFromSun;
        int numberOfMoons;
        bool inKuiperBelt;

        cin >> type;

        //cout << "Enter name: ";
        cin >> name;

        //cout << "Enter mass: ";
        cin >> mass;

        //cout << "Enter distanceFromSun: ";
        cin >> distanceFromSun;

        if (strcmp(type, "Planet") == 0) {
            //cout << "Enter numberOfMoons: ";
            cin >> numberOfMoons;
            bodies[i] = new Planet(name, mass, distanceFromSun, numberOfMoons);
        } else if (strcmp(type, "DwarfPlanet") == 0) {
            cin >> inKuiperBelt;
            bodies[i] = new DwarfPlanet(name, mass, distanceFromSun, inKuiperBelt);
        }
    }



    cout << "Most Gravitational body ";
    double maxGravity = mostGravitationalBody(bodies, n);
    for (int i = 0; i < n; ++i) {
        if (bodies[i]->calculateGravity() == maxGravity) {
            bodies[i]->printInfo();
            break;
        }
    }



    // Deallocate memory
    for (int i = 0; i < n; ++i) {
        delete bodies[i];
    }

    return 0;
}