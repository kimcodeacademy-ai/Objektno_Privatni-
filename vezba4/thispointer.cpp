#include <iostream>
using namespace std;

class X {
    int a;
    double b;
public:
    X(int j, double b) {
        a = j;
        this->b = b;
    }
    void seta(int a) {
        this->a=a;
    }
    void setb(double y) {
        b=y;
    }
    void areTheSame(const X &y) {
        if(&y == this)
            cout << "It is the same object" << endl;
        else if(a==y.a && b==y.b)
            cout << "Objects have same values" << endl;
        else
            cout << "Objects are different" << endl;
    }
};


int main() {
    X A(1,2.3), B(4,5.6);
    X C(A), *p = &A;
    A.areTheSame(B);
    C.areTheSame(A);
    A.areTheSame(*p);
    return 0;
}
