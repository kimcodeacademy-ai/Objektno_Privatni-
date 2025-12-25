// Да се напише класа за матрица. Во класата се чуваат елементите од матрицата од тип float (матрица со максимална димензија [10]x[10])
// и големината на матрицата (број на редици и колони). За оваа класа да се преоптоварат следните оператори:
//
// оператор + за собирање матрица со број
// оператор - за одземање на матрици
// оператор * за множење на матрици
// операторот >> за внесување на елементите на матрицата
// операторот << за печатење на елементите на матрицата
// Во главната функција да се креираат објекти A, B и C со подразбирливиот конструктор на класата Matrica.
// Од стандарден влез да се прочитаат нивните вредности. Да се отпечати вредноста на изразот A-(B*C)+2 на стандарден излез.
//
// Да се претпостави дека секогаш матриците ќе бидат квадратни со ист број на редици и колони.
//
// For example:
//
// Input	Result
// 4
// 4
// 2 3 -1 1
// 0 2 1 1
// 0 2 3 2
// 2 1 -1 1
//
// 4
// 4
// 1 0 -1 1
// 1 2 1 1
// 0 2 0 2
// 2 1 -1 0
//
// 4
// 4
// 2 0 0 0
// 0 2 0 0
// 0 0 1 0
// 0 0 -0 1
//
// Result:
// 2 5 2 2
// 0 0 2 2
// 2 0 5 2
// 0 1 2 3

#include <iostream>
using namespace std;

class Matrica {
    float mat[10][10];
    int n;

public:

    // defualt
    Matrica(int dim = 10) : n(dim) {
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                mat[i][j] = 0;
            }
        }
    }

    // imeto na klasata_operator[*]
   friend Matrica operator+(const Matrica& mat, float broj) {
        Matrica rezultat(mat.n);
        for (int i = 0; i < mat.n; i++) {
            for (int j  = 0; j < mat.n; j++) {
                rezultat.mat[i][j] = mat.mat[i][j] + broj;
            }
        }
        return rezultat;
    }

    Matrica operator-(const Matrica& other) {
        Matrica rezultat(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n;j ++) {
                rezultat.mat[i][j] = this->mat[i][j] - other.mat[i][j];
            }
        }
        return rezultat;
    }

    Matrica operator*(const Matrica& other) {
        Matrica rezultat(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n;j ++) {
                rezultat.mat[i][j] = 0;
                for (int k = 0; k < n; k++) {
                    rezultat.mat[i][j] += this->mat[i][k] * other.mat[k][j];
                }
            }
        }
        return rezultat;
    }

    friend istream& operator>>(istream &in, Matrica& mat) {
        int rows, cols;
        in >> rows >> cols;
        mat.n = rows;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                in >> mat.mat[i][j];
            }
        }
        return in;
    }

    friend ostream& operator<<(ostream &out, Matrica& mat) {
        for (int i = 0; i < mat.n; i++) {
            for (int j = 0; j < mat.n; j++) {
                out << mat.mat[i][j];
                if (j < mat.n - 1) out << " ";
            }
            out << endl;
        }
        return out;
    }

};



int main() {
    Matrica A, B, C;
    // Читање на трите матрици. Влезот треба да е во формат: n [елементи] n [елементи]...
    if (!(cin >> A >> B >> C)) return 0;

    Matrica D = B * C;
    Matrica R = A - D;
    Matrica K = R + 2;

    cout << K;
    return 0;
}