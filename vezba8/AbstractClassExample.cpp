#include <iostream>
using namespace std;

class Animal {
public:
    // virtual function
    virtual void makeSound() = 0;

    virtual ~Animal() {}
};

void Animal::makeSound() {
    cout << "Animal::makeSound" << endl;
}

class Dog : public Animal {
public:
    void makeSound(){
        //Animal::makeSound();
        cout << "Dog says: Woof!" << endl;
    }
};

class Cat : public Animal {
public:
    void makeSound() {
        cout << "Cat says: Meow!" << endl;
    }
};

int main() {

    // NOT ALLOWED – Animal is an abstract class
    // Animal a;              // Compilation error
    // Animal* a = new Animal(); // Compilation error

    // ✅ Allowed – using base-class pointer
    Animal* d = new Dog();
    Animal* c = new Cat();

    //d->Animal::makeSound();
    d->makeSound(); // Dog says: Woof!
    c->makeSound(); // Cat says: Meow!

    delete d;
    delete c;
    return 0;
}
