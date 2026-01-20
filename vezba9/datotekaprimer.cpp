#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main() {
    // ofstream - zapisuvanje
    ofstream outFile;
    outFile.open("vezba9/example.txt",ios::out | ios::trunc);

    if (!outFile.fail()) {
        outFile << "Kimcode Academy\n";
        outFile << "Ucime c++\n";
    }
    else {
        cout << "Unable to open file for writing" << endl;
        return 1;
    }

    // ofstream - app
    ofstream appendFile("vezba9/example.txt", ios::out | ios::app);
    if (appendFile.is_open()) {
        appendFile << "Appended line \n";
        appendFile.close();
    }
    else {
        cout << "Unable to open file for appending" << endl;
        return 1;
    }

    // ifstream
    ifstream inFile;
    inFile.open("vezba9/example.txt", ios::in);
    if (inFile) {
        string line;
        while (getline(inFile, line)) {
            cout << line << endl;
        }
        inFile.close();
    }

    // ifstream - citame znak po znak
    inFile.open("vezba9/example.txt");
    if (!inFile.fail()) {
        char ch;
        while (inFile.get(ch)) {
            cout << ch << endl;
        }
        inFile.close();
    }


    fstream file;
    file.open("vezba9/example.txt", ios::in | ios::out);
    if (file.is_open()) {
        // tellg - ja vrakja momentalnata pozicija na citajne, vrakja -1 kraj
        cout << "Current position: " << file.tellg() << endl;

        // seekg - pocnuva od nekade, ima nekoj offset i cita od tamu
        file.seekg(0, ios::beg);
        string firstLine;
        getline(file, firstLine);
        cout << "First line: " << firstLine << endl;


        // seekp - ni bara nekoj karakter dali postoi
        file.seekp(0, ios::end);
        file << "\n Written using fstream";
        file.close();
    }

}