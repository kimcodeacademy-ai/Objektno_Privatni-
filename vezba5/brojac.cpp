#include <iostream>
using namespace std;

class Brojac {
private:
    int vrednost;
public:
    Brojac(int v = 0) : vrednost(v) {}

    Brojac& operator++() {
        vrednost++;
        return *this;
    }

    // povratna_vrednost operator# (argumenti)
    Brojac operator++(int) {
        Brojac temp(*this);
        vrednost++;
        return temp;
    }

    Brojac operator-() const {
        // minus moze da se preoptovari na 2 nacini
        return Brojac(-vrednost);
    }

    void pecati() const { cout << "Vrednost: " << vrednost << endl; }
};

int main() {
    Brojac b(10);

    cout << "Pocetok";
    b.pecati();
    
    Brojac a = ++b;
    cout << "Po b++ (prefix):" << endl;
    cout << "a: "; a.pecati();
    cout << "b: "; b.pecati();

    Brojac c = b++;
    cout << "Po b++ (postfix):" << endl;
    cout << "c: "; c.pecati();
    cout << "b: "; b.pecati();

    Brojac d = -b;
    cout << "Negativen b: "; d.pecati();

    return 0;
}