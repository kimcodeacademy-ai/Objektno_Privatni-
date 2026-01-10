// Потребно е да дизајнирате програма за систем за хотелски резервации. За таа цел потребно е да изработите класа Room која што ќе ги има следните информации:
//
// број на соба - цел број
// цена за ноќевање - цел број
// За оваа класа потребно е да креирате:
//
// Default конструктор
// Конструктор со параметри
// Copy конструктор
// Оператор =
// Функција која што ја враќа цената за едно ноќевање (getPrice)
// Функција print што ги печати информациите за собата во формат:
// [број на соба] - [цена за ноќевање] euros
// Понатаму, треба да креирате класа StandardRoom. Класата треба да наследува од класата Room и дополнително да ги има следниве информации:
//
// hasBalcony  - bool променлива
// За оваа класа потребно е да креирате:
//
// Default конструктор
// Конструктор со параметри
// Функција што ја враќа цената за едно ноќевање (getPrice) која што се пресметува така што доколку собата има балкон, се одзема 5% од цената што ја добивате од класата Room. Доколку собата нема балкон,цената за едно ноќевање е онаа што ја добивате од класата Room. Пример, доколку цената за ноќевање што ја добивате од класата Room е 60 евра и собата има балкон, тогаш овде функцијата треба да врати 57 евра затоа што 60 - 60 *0.05 = 57.
// Функција print што ги печати информациите за собата во формат:   [број на соба] - [цена за ноќевање] euros.  Доколку има балкон додадете 'has a balcony', доколку нема балкон додадете 'without balcony'.
// Понатаму, треба да креирате класа LuxuryRoom која треба да наследува од класата Room и дополнително да ги има следниве информации:
//
// hasJacuzzi - bool променлива
// За оваа класа потребно е да креирате:
//
// Default конструктор
// Конструктор со параметри
// Функција што ја враќа цената за едно ноќевање (getPrice) која што се пресметува така што доколку собата има џакузи, се додава 20% од цената што ја добивате од класата Room.Доколку собата нема џакузи,цената за едно ноќевање е онаа што ја добивате од класата Room.Пример, доколку цената за ноќевање што ја добивате од класата Room е 60 евра и собата има џакузи, тогаш овде функцијата треба да врати 72 евра затоа што 60 + 60 *0.2 = 72.
// Функција print што ги печати информациите за собата во формат:    [број на соба] - [цена за ноќевање] euros. Доколку има џакузи додадете 'has a jacuzzi', доколку нема додадете 'without jacuzzi'.
//
//
// Input	Result
// 2
// 202 200 0
// 202 - 200 euros without balcony

#include <iostream>
#include <cstring>

using namespace std;

// YOUR CODE STARTS HERE

class Room {
protected:
    int number;
    int price;

public:
    Room() {
        number = 0;
        price = 0;
    }

    Room(int number, int price) {
        this->number = number;
        this->price = price;
    }

    Room(const Room& r) {
        number = r.number;
        price = r.price;
    }

    Room& operator=(const Room& r) {
        if (this != &r) {
            number = r.number;
            price = r.price;
        }
        return *this;
    }

    virtual int getPrice() {
        return price;
    }

    virtual void print() {
        cout << number << " - " << price << " euros " << endl;
    }

};

class StandardRoom : public Room {
    bool hasBalcony;

public:
    StandardRoom() {
        hasBalcony = false;
    }

    StandardRoom(int number, int price, bool hasBalcony) : Room(number, price){
        this->hasBalcony = hasBalcony;
    }

    // Функција што ја враќа цената за едно ноќевање (getPrice) која што се пресметува така што доколку собата има балкон,
    // се одзема 5% од цената што ја добивате од класата Room. Доколку собата нема балкон,цената за едно ноќевање е
    // онаа што ја добивате од класата Room. Пример, доколку цената за ноќевање што ја добивате од класата Room е 60 евра и собата има балкон,
    // тогаш овде функцијата треба да врати 57 евра затоа што 60 - 60 *0.05 = 57.

    int getPrice() {
        if (hasBalcony)
            return price - price*0.05;
        return price;
    }

    void print() {
        Room::print();
        if (hasBalcony)
            cout << "has a balcony";
        else
            cout << "without balcony";
        cout << endl;
    }

};

class LuxuryRoom : public Room {
    bool hasJacuzzi;

public:
    LuxuryRoom() {
        hasJacuzzi = false;
    }

    LuxuryRoom(int number, int price, bool hasJacuzzi) : Room(number, price){
        this->hasJacuzzi = hasJacuzzi;
    }

    // Функција што ја враќа цената за едно ноќевање (getPrice) која што се пресметува така што доколку собата има џакузи
    // , се додава 20% од цената што ја добивате од класата Room.Доколку собата нема џакузи,цената за едно ноќевање е онаа што ја добивате од класата Room.
    // Пример, доколку цената за ноќевање што ја добивате од класата Room е 60 евра и собата има џакузи, тогаш овде функцијата треба да врати 72 евра затоа што 60 + 60 *0.2 = 72.


    int getPrice() {
        if (hasJacuzzi)
            return price + price*0.2;
        return price;
    }

    void print() {
        Room::print();
        if (hasJacuzzi)
            cout << "has a jacuzzi";
        else
            cout << "without jacuzzi";
        cout << endl;
    }

};

// DO NOT CHANGE THE MAIN FUNCTION
int main() {
    int testCase;
    cin >> testCase;

    if (testCase == 1) {
        // Test Room class
        int number, price;
        cin >> number >> price;
        Room r1(number, price);
        Room r2 = r1;  // Copy constructor
        Room r3;
        r3 = r1;       // Assignment operator

        r1.print();
        r2.print();
        r3.print();
    }
    else if (testCase == 2) {
        // Test StandardRoom
        int number, price;
        bool hasBalcony;
        cin >> number >> price >> hasBalcony;

        StandardRoom sr(number, price, hasBalcony);
        sr.print();
    }
    else if (testCase == 3) {
        // Test LuxuryRoom
        int number, price;
        bool hasJacuzzi;
        cin >> number >> price >> hasJacuzzi;

        LuxuryRoom lr(number, price, hasJacuzzi);
        lr.print();
    }


    // 4
    // 4
    // Room 209 90
    // Standard 210 110 0
    // Luxury 211 180 1
    // Room 212 75
    else if (testCase == 4) {
        // Polymorphism test
        int n;
        cin >> n;
        Room* rooms[100];

        for (int i = 0; i < n; ++i) {
            string type;
            cin >> type;

            int number, price;
            cin >> number >> price;

            if (type == "Standard") {
                bool hasBalcony;
                cin >> hasBalcony;
                rooms[i] = new StandardRoom(number, price, hasBalcony); // upcasting
            } else if (type == "Luxury") {
                bool hasJacuzzi;
                cin >> hasJacuzzi;
               rooms[i] = new LuxuryRoom(number, price, hasJacuzzi); // upcasting
            } else {
                rooms[i] = new Room(number, price);
            }
        }

        for (int i = 0; i < n; ++i) {
            rooms[i]->print();
        }

        for (int i = 0; i < n; ++i) {
            delete rooms[i];
        }
    }

    return 0;
}

