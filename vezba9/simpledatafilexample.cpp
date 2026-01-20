#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string filename = "vezba9/example.txt";
    // -- Write something to the file --
    ofstream outFile(filename, ios::app);
    if (!outFile.is_open()) {
        cout << "Error opening file " << filename << endl;
        return 1;
    }

    cout << "Enter text to write in the file. Type 'END' to finish" << endl;
    string line;
    while (true) {
        getline(cin, line);
        if (line == "END") break;
        outFile << line << endl;
    }

    outFile.close();

    // -- Reading something from the file --
    ifstream inFile(filename);
    if (!inFile.is_open()) {
        cout << "Error opening file " << filename << endl;
        return 1;
    }

    cout << "Sodrzinata na fajlot e slednava: "<<endl;
    while (getline(inFile, line)) {
        cout << line << endl;
    }

    inFile.close();

    return 0;

}