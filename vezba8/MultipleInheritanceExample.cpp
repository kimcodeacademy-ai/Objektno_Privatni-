#include <iostream>
using namespace std;

// Abstract class 1
class Device {
public:
    int number;
    virtual void turnOn() = 0;
    virtual ~Device() {}
};

// Abstract class 2
class Connectable {
public:
    int connectNumber;
    virtual void connectToWiFi() = 0;
    virtual ~Connectable() {}
};

// Derived class inheriting from BOTH abstract classes
class SmartPhone : public Device, public Connectable {
public:
    void turnOn() {
        cout << "Smartphone is turned on." << endl;
    }

    void connectToWiFi() {
        cout << "Smartphone connected to WiFi." << endl;
    }
};

int main() {

    // Not allowed – abstract classes
    // Device d;
    // Connectable c;

    // Multiple inheritance + polymorphism
    Device* phone1 = new SmartPhone();
    Connectable* phone2 = new SmartPhone();
    SmartPhone* sp = new SmartPhone();
    // sp->number;
    // sp->connectNumber;

    phone1->turnOn();
    phone2->connectToWiFi();

    delete phone1;
    delete phone2;
    return 0;
}
