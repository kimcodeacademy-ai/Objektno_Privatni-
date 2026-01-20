#include <iostream>
#include <string>

using namespace std;

class MyException {
public:
    string message;
    MyException(string m) {
        message = m;
    }
};

class DivizionByZero : public MyException {
public:
    DivizionByZero() : MyException("Divizion by zero!") {}
};

class NegativeValue : public MyException {
public:
    NegativeValue() : MyException("Negative value!") {}
};

double divide(double a, double b) {
    if (b==0)
        throw DivizionByZero();
    return a/b;
}

void riskyFunction(int option) {
    try {
        if (option == 1) throw DivizionByZero();
        else if (option == 2) throw NegativeValue();
        else if (option == 3) throw  "Unknown exception!";
    }
    catch (DivizionByZero& e) {
        cout <<"Caught in riskyFunction: "<<e.message<<endl;
        throw;
    }
}

int main() {
    try {
        // cout << "Divide 10/2 = " << divide(10,2) << endl;
        // cout << "Testing divide by zero nowL \n";
        // cout << divide(10,0);

        riskyFunction(1);
        riskyFunction(2);
        riskyFunction(3);
        riskyFunction(4);
    }
    catch (DivizionByZero& e) {
        cout << "Caught in main: " << e.message << endl;
    }
    catch (NegativeValue &e) {
        cout << "Caught in main: " << e.message << endl;
    }
    catch (...) {
        cout << "Caught unknown exteption" << endl;
    }

    return 0;

}