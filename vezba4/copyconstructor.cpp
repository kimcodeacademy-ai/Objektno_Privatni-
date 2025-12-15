#include <iostream>
using namespace std;

class myclass {
    int i;

public:
    myclass(int n);
    ~myclass();
    myclass(const myclass &n);
    void set_i(int n) { i=n; }
    int get_i() { return i; }
};

myclass::myclass(int n) { i = n; cout << "Constructing " << i << "\n"; }
myclass::~myclass() { cout << "Destroying " << i << "\n"; }
myclass::myclass(const myclass &n) {
    i = n.i; cout << "Constructing+copying " << i << "\n"; }

void f(myclass);

int main() {
    myclass x(1);
    f(x);
    cout << "This is i in main: ";
    cout << x.get_i() << endl;
    return 0;
}


void f(myclass ob) {
    ob.set_i(2);
    cout << "This is local i: " <<
    ob.get_i() << endl;
}