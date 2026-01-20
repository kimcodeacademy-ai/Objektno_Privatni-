// Да се дефинира класа Book која ќе претставува една книга. Треба да ги содржи следните полиња:
// title, насловот на книгата (string)
// author, авторот на книгата (string)
// За класата треба да се дефинира параметризиран конструктор и метод print().
// Да се дефинира класа DigitalCopy, која ќе ги претставува дигиталните параметри на книгата. Таа треба да ги содржи следните полиња:
// fileSize, големината на датотеката во MB (double)
// formats, низа од 3 стрингови кои ги претставуваат поддржаните формати (на пример: "PDF", "EPUB", "MOBI")
// За класата треба да се дефинира параметризиран конструктор и метод print(). Во конструкторот треба да се провери:
// fileSize да е поголем од 0 и помал од 1000 MB – во спротивно, да се фрли исклучок од тип InvalidFileSizeException.
// Секој формат да биде "PDF", "EPUB" или "MOBI" – во спротивно, да се фрли исклучок од тип InvalidFormatException.
// Исклучоците треба да се фатат во main() функцијата, каде ќе се читаат податоци за n дигитални книги.


// Input:
// Input	Expected	Got
// 2
// Ne kazhuvam
// Petar Andonovski
// 12.5
// PDF EPUB MOBI
// Vishnova hronika
// Frosina Parmakovska
// 500.0
// MOBI PDF EPUB

// Expected:
// EBook:
// Ne kazhuvam by Petar Andonovski
// File size: 12.5 MB
// Supported formats: PDF EPUB MOBI
// AudioBook:
// Vishnova hronika by Frosina Parmakovska
// File size: 500 MB
// Supported formats: MOBI PDF EPUB

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


class InvalidFileSizeException {
    string message;
public:
    InvalidFileSizeException(string message) {
        this->message = message;
    }
    void print(){
        cout << "InvalidFileSizeException: " << message << endl;
    }
};

class InvalidFormatException {
    string message;
public:
    InvalidFormatException(string message) {
        this->message = message;
    }
    void print(){
        cout << "InvalidFormatException: " << message << endl;
    }
};


class Book {
protected:
    string title;
    string author;
public:
    Book(string t, string a) {
        title = t;
        author = a;
    }

    void print() {
        cout<<"Title: " << title << ", Author: " << author <<endl;
    }

};

class DigitalCopy {
protected:
    double fileSize;
    string formats[3];
public:
    DigitalCopy(double fs, string* f) {
        if (fs <=0 || fs >=1000) {
            throw InvalidFileSizeException("File size must be >0 and <1000 MB");
        }
        fileSize = fs;



        for (int i = 0; i < 3; i++) {
            string fmt = f[i];
            if (fmt != "PDF" && fmt != "EPUB" && fmt != "MOBI") {
                throw InvalidFormatException("Invalid format: " + f[i]);
            }
            formats[i] = f[i];
        }
    }

    void print() {
        cout << "File size: " << fileSize << " MB" << endl;
        cout << "Formats: ";
        for (int i = 0; i < 3; i++) {
            cout << formats[i] << " ";
        }
        cout << endl;
    }
};

class EBook : public Book, public DigitalCopy {
public:
    EBook(string title, string author, double fileSize, string formats[3])
            : Book(title, author), DigitalCopy(fileSize, formats) {}

    void print()   {
        cout << "EBook:" << endl;
        Book::print();
        DigitalCopy::print();
    }
};

class AudioBook : public Book, public DigitalCopy {
public:
    AudioBook(string title, string author, double fileSize, string formats[3])
            : Book(title, author), DigitalCopy(fileSize, formats) {}

    void print()  {
        cout << "AudioBook:" << endl;
        Book::print();
        DigitalCopy::print();
    }
};

int main() {
    int n;
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; ++i) {
        string title, author;
        double fileSize;
        string formats[3];

        getline(cin, title);
        getline(cin, author);
        cin >> fileSize;

        for (int j = 0; j < 3; ++j) {
            cin >> formats[j];
        }
        cin.ignore();

        try {
            if (i % 2 == 0) {
                EBook eb(title, author, fileSize, formats);
                eb.print();
            } else {
                AudioBook ab(title, author, fileSize, formats);
                ab.print();
            }
        }
        catch (InvalidFileSizeException &e) {
            e.print();
        }
        catch (InvalidFormatException &e) {
            e.print();
        }
    }

    return 0;
}