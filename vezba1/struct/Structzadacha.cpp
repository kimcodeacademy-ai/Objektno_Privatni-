// Да се напише програма во која од стандарден влез се вчитува N (бројот на производи),
// а потоа се вчитуваат податоците за N производи (име, цена, количина).
// Програмата треба на стандарден излез да ја отпечати листата на купени производи и вкупната сума која треба да се плати
// во следниот облик (пример):
//
// 1. Flips    10.00 x 3 = 30.00
// 2. CocaCola 75.00 x 2 = 150.00
// 3. ChokoBanana  5.00 x 10 = 50.00
// Total: 230.00


// Input	Result
// 3
// Flips 10 3
// CocaCola 75 2
// ChokoBanana 5 10
// 1. Flips	10.00 x 3.0 = 30.00
// 2. CocaCola	75.00 x 2.0 = 150.00
// 3. ChokoBanana	5.00 x 10.0 = 50.00
// Total: 230.00

#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

struct Proizvod {
    string name;
    int cena;
    float kolicina;
    // strukturte nemat metodi vnatre vo niv
};

int main() {

    int n;
    cin>>n;

    float total = 0.0;

    // for (int i = 0; i < n; i++) {
    //     string name;
    //     int vrednost;
    //     int kolicina;
    //     cin>>name>>vrednost>>kolicina;
    //     total = total + (vrednost*kolicina*1.0);
    //     cout<< i+1 << "." << name << " " << vrednost << " " << kolicina << endl;
    // }

    // podatocen tip _ ime na nizata _ br. el
    Proizvod proizvodi[n];

    for (int i = 0; i < n; i++) {
        // input
       cin >> proizvodi[i].name >> proizvodi[i].cena >> proizvodi[i].kolicina;
        total = total + (proizvodi[i].kolicina * proizvodi[i].cena * 1.0);
    }

    // 1. Flips	10.00 x 3.0 = 30.00
    // 2. CocaCola	75.00 x 2.0 = 150.00
    // 3. ChokoBanana	5.00 x 10.0 = 50.00
    for (int i = 0; i < n; i++) {
        // output
        float rez = proizvodi[i].kolicina * static_cast<float>(proizvodi[i].cena);
        cout << i+1 << ". "
            << proizvodi[i].name << " "
            << proizvodi[i].cena << " x "
        << proizvodi[i].kolicina << " = "
        << setprecision(2) << rez << endl;

    }
    cout<<total;
}
