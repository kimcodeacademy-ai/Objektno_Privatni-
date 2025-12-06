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
    float radius;
    const float pi=3.14;

public:
    Krug() {

    }
    Krug(float _radius) {
        radius = _radius;
    }

    // plostina na krug = pi*radius^2
    float plostina() {
        return pi*radius*radius;
    }
    // perimetar na krug = 2*radius*pi
    float perimetar() {
        return 2*radius*pi;
    }

    bool ednakvi() {
        // float plostina = pi*radius*radius;
        // float perimetar = 2*radius*pi;
        // if (perimetar == plostina)
        //     return true;
        // return false;
        if (plostina() == perimetar()) {
            return true;
        }
        return false;
    }

    void setRadius(float _radius) {
        radius = _radius;
    }

};

int main() {
    float r;
    cin >> r;
    Krug k;
    k.setRadius(r);
    cout << "Perimetarot na krugot e: "<<k.perimetar()<<endl;
    cout << "Plostinata na krugot e: "<<k.plostina()<<endl;
    cout << "Dali perimetarot i plostinata na krugot se ednakvi?  "<<k.ednakvi()<<endl;

    return 0;
}