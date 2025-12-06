// Да се дефинира класа Agol, во која се чуваат информации за:
//
// степени, минути и секунди (int)
// Во класата да се реализираат:
//
// конструктор по потреба
// методи за поставување на вредности на атрибутите на класата (set методи)
// метод за пресметување на вредноста на аголот во секунди
// Да се дефинира и метод за проверување на тоа дали внесениот агол е валиден, односно дали се внесени соодветни вредности
// за атрибутите (во границите кои ги дозволуваат).
//
// For example:
//
// Input	Result
// 15 20 20
// 55220

#include <iostream>
using namespace std;

class Agol {
    // po default private vo C++
    int deg;
    int min;
    int sec;

public:
    // Agol(int deg, int min, int sec)
    //     : deg(deg),
    //       min(min),
    //       sec(sec) {
    // }

    Agol () {

    }
    Agol (int _deg, int _min, int _sec) {
        deg = _deg;
        min = _min;
        sec = _sec;
    }

    // setteri
    void setDeg(int _deg) {
        deg = _deg;
    }

    void setMin(int _min) {
        min = _min;
    }

    void setSec(int _sec) {
        sec = _sec;
    }

    // getteri
    int getDeg() {
        return deg;
    }

    int getMin() {
        return min;
    }

    int to_sekundi() {
        return deg*60*60+min*60+sec;
    }

    //setter od clion
    // explicit Agol(int sec)
    //     : sec(sec) {
    // }
};

int proveri(int deg, int min, int sec) {
    if (deg > 360){
        return 0;
    }
    else if (deg < 0 || min < 0 || sec < 0 || sec >= 60) {
        return 0;
    }
    return 1;
}
int main() {
    // Agol a(30, 20, 10);
    Agol a;
    int deg, min, sec;
    cin >> deg >> min >> sec;

    if (proveri(deg, min, sec)) {
        a.setDeg(deg);
        a.setMin(min);
        a.setSec(sec);
        cout<<a.to_sekundi()<<endl;
    }
    else {
        cout<<"Nevalidni vrednosti za dadeniot agol"<<endl;
    }

    cout<<a.getDeg()<<endl;
    return 0;

    // cout<<a.min<<endl;
    // cout<<a.deg<<endl;
}