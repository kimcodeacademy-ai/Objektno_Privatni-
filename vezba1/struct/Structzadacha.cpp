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

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct Proiz {
    string name;
    int cena;
    float kolicina;

    // kaj struktura nemame metodi - klasa
};

// int main(){
//
//     int n;
//     cin>>n;
//
//     // int niza[n];
//     // char niza[n];
//     Proiz arr[n];
//     float total = 0;
//
//     for (int i = 0; i < n; i++) {
//         cin>> arr[i].name >> arr[i].cena >> arr[i].kolicina;
//
//         float rez = arr[i].cena * arr[i].kolicina;
//         total += rez;
//     }
//
//     cout<<"Imame vkupno: "<<n<<" proizvodi"<<endl;
//     // 1. Flips	10.00 x 3.0 = 30.00
//     for (int i = 0; i < n; i++) {
//         float rez = arr[i].cena * arr[i].kolicina;
//
//         //cout<<arr[i].name<<" "<<arr[i].cena<<" "<< arr[i].kolicina<<endl;
//         cout << i+1 << ". "
//         << arr[i].name << "\t"
//         << fixed << setprecision(2) << arr[i].cena
//         << " x "
//         << setprecision(1) << arr[i].kolicina
//         << " = "
//         << setprecision(2) << rez << "\n";
//     }
//
//     cout<<total<<"\n";
//     return 0;
// }