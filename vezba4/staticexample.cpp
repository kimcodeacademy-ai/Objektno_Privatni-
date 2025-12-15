#include <iostream>
using namespace std;

class ST {

public:
    ST(int a, int b) : x(a), y(b) {}
    int xo() const {
        return x+offset;
    }
    int yo() const {
        return y+offset;
    }
    static void setoffset(int a) {
        offset = a;
    }
    static int getoffset() {
        return offset;
    }

private:
    int x,y;
    static int offset;
};

int ST::offset=0; // иако е приватна static променливата смее еднаш да се иницијализира надвор од main ()

int main() {
    ST::setoffset(ST::getoffset()+1);
    ST a(2,3);
    const ST b(4,5);
    cout << b.xo() << ' ' << b.yo() << endl;
    b.setoffset(-1);
    cout << a.xo() << ' ' << a.yo() << endl;
    cout << b.xo() << ' ' << b.yo() << endl;
    return(0);
}