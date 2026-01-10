#include <iostream>
#include <string>
using namespace std;

// =====================
// Base class
// =====================
class Animal {
protected:
    string name;

public:
    // Default constructor
    Animal() {
        name = "Unknown";
        cout << "Animal default constructor called" << endl;
    }

    // Parameterized constructor
    Animal(string n) {
        name = n;
        cout << "Animal parameterized constructor called" << endl;
    }

    // Destructor
    ~Animal() {
        cout << "Animal destructor called" << endl;
    }

    // Function to be overridden
    void speak() {
        cout << "Animal makes a sound" << endl;
    }
};

// =====================
// Derived class 1
// Does NOT explicitly call base constructor
// =====================
class Dog : public Animal {
public:
    // Constructor
    Dog() {
        // Animal default constructor is called automatically
        cout << "Dog constructor called" << endl;
    }

    // Destructor
    ~Dog() {
        cout << "Dog destructor called" << endl;
    }

    // // Overriding the speak function
    void speak() {
        Animal::speak();
        cout << "Dog barks" << endl;
    }
};

// =====================
// Derived class 2
// Explicitly calls base constructor
// =====================
class Cat : public Animal {
public:
    // Constructor with explicit base constructor call
    Cat(string n) : Animal(n) {
        cout << "Cat constructor called" << endl;
    }

    // Destructor
    ~Cat() {
        cout << "Cat destructor called" << endl;
    }

    // // Overriding the speak function
    void speak() {
        Animal::speak();
        cout << "Cat meows" << endl;
    }
};

// =====================
// MAIN
// =====================
int main() {

    cout << "--- Dog example ---" << endl;
    Dog d;
    d.speak();

    cout << endl;

    cout << "--- Cat example ---" << endl;
    Cat c("Whiskers");
    c.speak();

    cout << endl;
    cout << "--- End of main ---" << endl;

    return 0;
}
