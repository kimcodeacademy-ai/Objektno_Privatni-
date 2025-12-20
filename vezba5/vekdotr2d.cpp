#include <iostream>
using namespace std;

// binarni: +, -, a = b+c
// unarni: a++, a-- = a = a+1, <<, >>

class Vektor2D {
private:
    double x, y;
public:
    Vektor2D(double x = 0, double y = 0) : x(x), y(y) {}

    Vektor2D operator+(const Vektor2D& v) const {
        return Vektor2D(x + v.x, y + v.y);
    }

    bool operator==(const Vektor2D& v) const {
        return (x == v.x && y == v.y);
    }

    friend ostream& operator<<(ostream& os, const Vektor2D& v) {
        os << "[" << v.x << ", " << v.y << "]";
        return os;
    }
};

int main() {
    Vektor2D v1(2, 3), v2(4, 5);
    Vektor2D v3 = v1 + v2;


    cout << "v1: " << v1 << endl;
    cout << "v2: " << v2 << endl;
    cout << "v1 + v2 = " << v3 << endl;

    if (v1 == v2) cout << "Vektorite se isti" << endl;
    else cout << "Vektorite se razlicni" << endl;

    return 0;
}