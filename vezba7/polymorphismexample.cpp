#include <iostream>
using namespace std;

class Vehicle {
public:
    virtual ~Vehicle() {}  // Virtual destructor is mandatory

    virtual int getWeight() const {
        return 1000;
    }

    virtual void printType() const {
        cout << "Vehicle" << endl;
    }
};

class Car : public Vehicle {
public:
    int getWeight() const {
        return 1200;
    }

    void printType() const {
        cout << "Car" << endl;
    }
};

class Truck : public Vehicle {
private:
    int trailerWeight;

public:
    Truck(int trailer) : trailerWeight(trailer) {}

    int getWeight() const{
        return 3000 + trailerWeight;
    }

    void printType() const {
        cout << "Truck" << endl;
    }
};

void printVehicleInfo(const Vehicle& v) {
    // Polymorphic behavior happens here
    v.printType();
    cout << "Weight: " << v.getWeight() << endl;
}

int main() {
    Vehicle v;
    Car c;
    Truck t(7000);

    printVehicleInfo(v);  // Vehicle version
    printVehicleInfo(c);  // Car version
    printVehicleInfo(t);  // Truck version

    return 0;
}
