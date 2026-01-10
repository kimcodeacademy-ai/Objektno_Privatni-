#include <iostream>
using namespace std;

class Vehicle {
public:
    virtual ~Vehicle() {}  // Enables RTTI
};

class Car : public Vehicle {
public:
    void drive() const {
        cout << "Driving a car" << endl;
    }
};

class Truck : public Vehicle {
public:
    void load() const {
        cout << "Loading the truck" << endl;
    }
};

void processVehicle(Vehicle* v) {
    // Safe runtime type check
    if (Car* c = dynamic_cast<Car*>(v)) {
        c->drive();
    }
    else if (Truck* t = dynamic_cast<Truck*>(v)) {
        t->load();
    }
    else {
        cout << "Unknown vehicle type" << endl;
    }
}

int main() {
    Vehicle* v1 = new Car(); // upcasting
    Vehicle* v2 = new Truck(); // upcasting

    processVehicle(v1);  // Car branch
    processVehicle(v2);  // Truck branch

    delete v1;
    delete v2;

    return 0;
}
