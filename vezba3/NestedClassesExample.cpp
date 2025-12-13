#include <iostream>
using namespace std;

class Outer {

public:
    class Inner {
        int value;
    public:
        void setValue(int v) {
            value = v;
        }
        int getValue() { return value; }
    };

    void process() {
        Inner temp;
        temp.setValue(x);   // x = 10
        innerObj = temp;
    }

    void print()  {
        cout << "Outer x = " << x << endl;
        cout << "Inner value (inside Outer) = " << innerObj.getValue() << endl;
    }

private:
    int x = 10;
    Inner innerObj;
};

int main() {
    Outer::Inner a;
    Outer b;

    a.setValue(5);
    b.process();

    cout << "Inner value (standalone) = " << a.getValue() << endl;
    b.print();

    return 0;
}
