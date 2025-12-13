#include <iostream>
#include <string>
using namespace std;

class Person {

private:
    string name;
    string address;
    string phone;

public:
    Person(string n = "", string a = "-unknown-", string p = "-unknown-");

    void setName(string n);
    void setAddress(string a);
    void setPhone(string p);

    string getName() const;
    string getAddress() const;
    string getPhone() const;
    void show() const;
};

Person::Person(string n, string a, string p)
    : name(n), address(a), phone(p) {}

void Person::setName(string n) { name = n; }
void Person::setAddress(string a) { address = a; }
void Person::setPhone(string p) { phone = p; }

string Person::getName() const { return name; }
string Person::getAddress() const { return address; }
string Person::getPhone() const { return phone; }

void Person::show() const {
    cout << name << " " << address << " " << phone << endl;
}

int main() {
    Person p1("Alice", "Skopje", "12345");
    const Person p2("Bob", "Bitola", "98765");
    Person p3;

    // non-const object → everything allowed
    cout << p1.getName() << endl;   // OK
    p1.setName("Alice2");           // OK
    p1.show();                      // OK

    // const object → ONLY const methods allowed
    // p2.setName("Bob2");          // ERROR
    // p2.setAddress("Ohrid");      //  ERROR

    cout << p2.getName() << endl;   // OK
    p2.show();                      // OK

    p3 = p2;                        // OK (copying is allowed)

    p3.show();


    return 0;
}
