// Да се дефинира класа Krug, во која се чуваат информации за:
//
// радиус float
// бројот π const float.
// Во класата да се реализираат:
//
// default конструктор и конструктор со аргументи
// метод за пресметување плоштина
// метод за пресметување периметар
// метод кој кажува дали плоштината и периметарот на даден круг се еднакви
// For example:
//
// Input	Result
// 15
// 94.2
// 706.5
// 0

#include <iostream>
using namespace std;

class Krug {

private:
    float radius;
    float pi = 3.14;

public:

    // konstruktori: specijalni metodi za dodeluvanje vrednost na atributite
    // notacija za konstruktir: imeto na samata klasa (//argumentite)

    // default constructor
    Krug() {}

    // constructor with arguments
    Krug(float _radius) {
        radius = _radius;
    }

    // pi*radius^2
    float plostina() {
        return pi*radius*radius;
    }

    // 2*radius*pi;
    float perimetar() {
        return 2*radius*pi;
    }

    bool isEqual() {
        return plostina() == perimetar();
    }
};

int main() {

    float r;
    cin >> r;

    Krug krug(r);

    cout << "Perimetarot na krugot e: " << krug.perimetar()<<endl;
    cout << "Plostinata na krugot e: " << krug.plostina()<<endl;
    cout << "Dali perimetarot na krugot e ednakov so plostinata na krugot: " << krug.isEqual()<<endl;

    return 0;
}

