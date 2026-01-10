#include <iostream>
using namespace std;

class Vehicle {
public:
    int weight;

    Vehicle(int w) : weight(w) {}

    int getWeight() const {
        return weight;
    }
};

class Car : public Vehicle {
public:
    int speed;

    Car(int w, int s) : Vehicle(w), speed(s) {}

    int getSpeed() const {
        return speed;
    }
};

class Truck : public Vehicle {
public:
    int truck_load;

    Truck(int w, int s) : Vehicle(w), truck_load(s) {}

    int getTruckLoad() const {
        return truck_load;
    }
};

int main() {
    Truck truck(1200, 220);

    Vehicle v = truck;
    // Object slicing: only Vehicle part is copied

    cout << v.getWeight() << endl; // OK
    // cout << v.getSpeed();       // ERROR: Vehicle has no getSpeed()

    Vehicle* vp = &truck;
    // Base class pointer pointing to derived object (upcasting)

    cout << vp->getWeight() << endl; // Calls Vehicle::getWeight()

    // Explicit downcasting (dangerous if type is wrong)
    Car* cp = reinterpret_cast<Car*>(vp); // downcasting - avoid when possible
    cout << cp->getSpeed() << endl;  // Works only if vp really points to Car

    return 0;
}
