#include <iostream>

using namespace std;

enum months { JAN = 1, FEB, MAR, APR, MAY, JUN,
JUL, AUG, SEP, OCT, NOV, DEC };

int main() {
    months month;
    int i;
    const char *monthName[] = { "", "Januari", "Fevruari",
    "Mart", "April", "Maj", "Juni", "Juli", "Avgust",
    "Septemvri", "Oktomvri", "Noemvri", "Dekemvri" };
    for (i = JAN; i <= DEC; i++)
        cout << i << " " << monthName[i] << endl;
    return 0;
}