#include <iostream>
#include <cstring>
using namespace std;

class Niza {
private:

    int * podatoci;
    int golemina;
public:
    Niza(int g = 0) : golemina(g) {
        if (g > 0) podatoci = new int[g]; // alociranje na dinamicka memorija
        else podatoci = nullptr; // nullptr dinamicka memorija
    }

    ~Niza() { delete[] podatoci; }

    Niza& operator=(const Niza& n) {
        if (this != &n) {
            delete[] podatoci;
            
            golemina = n.golemina;
            if (n.podatoci) {
                podatoci = new int[golemina];
                for (int i = 0; i < golemina; i++) 
                    podatoci[i] = n.podatoci[i];
            } else {
                podatoci = nullptr;
            }
        }
        return *this;
    }

    int& operator[](int i) { return podatoci[i]; }

    void postavi(int i, int v) { if (i < golemina) podatoci[i] = v; }
    void pecati() {
        for (int i = 0; i < golemina; i++) cout << podatoci[i] << " ";
        cout << endl;
    }
};

int main() {
    Niza n1(3);
    n1.postavi(0, 10); n1.postavi(1, 20); n1.postavi(2, 30);

    Niza n2;
    n2 = n1;

    n1[0] = 99;
    cout << "N1: "; n1.pecati();
    cout << "N2 (kopija): "; n2.pecati();

    return 0;
}