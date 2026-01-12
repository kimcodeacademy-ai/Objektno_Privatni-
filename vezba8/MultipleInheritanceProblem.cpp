#include <iostream>
using namespace std;

// Abstract base class
class Vehicle {
protected:
    int weight;

public:
    Vehicle(int w) : weight(w) {}

    virtual int getWeight() const = 0;
};

// First derived class
class LandVehicle : public Vehicle {
public:
    LandVehicle(int w) : Vehicle(w) {}

    int getWeight() const override {
        return weight;
    }
};

// Second derived class
class WaterVehicle : public Vehicle {
public:
    WaterVehicle(int w) : Vehicle(w) {}

    int getWeight() const override {
        return weight;
    }
};

// Multiple inheritance (diamond)
class AmphibiousVehicle : public LandVehicle, public WaterVehicle {
public:
    AmphibiousVehicle(int w)
        : LandVehicle(w), WaterVehicle(w) {}  // ⚠ weight passed twice
};

int main() {
    AmphibiousVehicle av(2000);

    // ERROR: ambiguous
    cout << av.WaterVehicle::getWeight() << endl;

    return 0;
}
