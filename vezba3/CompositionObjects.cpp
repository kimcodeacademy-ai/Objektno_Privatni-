#include <iostream>
#include <string>
using namespace std;

class Name {
private:
    string value;

public:
    Name(string v) : value(v) {
        cout << "Constructing Name: " << value << endl;
    }

    ~Name() {
        cout << "#Destructing Name: " << value << endl;
    }

    void show()  {
        cout << value;
    }
};

class Person {
private:
    Name firstName;
    Name lastName;
    int level;

public:
    Person(int lv, string fn,  string ln)
        : firstName(fn), lastName(ln), level(lv) {
        cout << "Constructing Person: ";
        firstName.show(); cout << " ";
        lastName.show(); cout << " ";
        cout << level << endl;
    }

    ~Person() {
        cout << "#Destructing Person: ";
        firstName.show(); cout << " ";
        lastName.show(); cout << " ";
        cout << level << endl;
    }

    void show()  {
        firstName.show(); cout << " ";
        lastName.show(); cout << " ";
        cout << level << endl;
    }
};

int main() {
    Name a("Hello");
    Name b("World");

    Person y(1, "Al", "Capone");

    a.show();
    cout << endl;

    {
        Person x(2, "Tony", "Luciano");
        x.show();
        y.show();
    }

    b.show();
    cout << endl;

    return 0;
}
