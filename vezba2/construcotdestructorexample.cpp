#include <iostream>
using namespace std;

class myclass {
public:
    int who;
    myclass(int id);
    ~myclass();
}

glob_ob1(1), glob_ob2(2);

// конкретната иницијализација на конструкторот
myclass::myclass(int id) {
    cout << "Inicijalizacija " << id << "\n";
    who = id;
}

// конкретната иницијализација на деструкторот
myclass::~myclass(){
    cout << "Unistuvanje " << who << "\n";
}

int main(){
    myclass local_ob1(3);
    cout << "Ova ne e prvata poraka na ekran.\n";
    myclass local_ob2(4);
    return 0;
    // LIFO
}