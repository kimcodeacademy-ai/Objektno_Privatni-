// Да се дефинира класа Song во која ќе се чуваат информации за некоја песна, и тоа: наслов на песната (стринг),
// име и презиме на авторот на песната (стринг), изведувач на песната (стринг), времетраење на песната (во секунди, цел број).
// За класата да се дефинираат потребните конструктори, set() и get() методи, оператор за читање >>, како и метод void print(ofstream& out),
// за печатење на информациите за песната во датотека што се предава како аргумент на методот (преку ofstream објектот). (10 п.)

// Да се дефинира класа Festival во која ќе се чуваат информации за некој музички фестивал, и тоа: име на фестивалот (стринг),
// град во којшто се одржува фестивалот (стринг), датум на одржување (стринг; формат: ден/месец/година), како и листа на песни
// пријавени за фестивалот (динамички алоцирана низа од објекти од класата Song, како и цел број n кој ја означува големината на листата).
//
// За класата Festival да се имплементираат:
// Потребните конструктори и деструктор (5 п.)
// Оператор -= за бришење на песна (објект од класата Song) од листата. Од листата се бришат сите песни со идентични податоци
// (исти: наслов, автор, изведувач и времетраење) како песната што е предадена како аргумент на операторот. Пред да се изведе бришење, да се провери дали листата е празна
// (да се спречи обидот за бришење на објект од празна листа, со печатење на соодветна порака: „Trying to delete from an empty list!“). (10 п.)
// Метод void print(ofstream& out), за печатење на информациите за фестивалот во датотека што се предава како аргумент
// на методот (преку ofstream објектот). Овој метод задолжително треба да го повика методот print од класата Song, за печатење на информациите за листата од песни. (5 п.)
// Оператор за читање >> (5 п.)
// Метод Festival notFromAuthor(string author) - кој како аргумент прима име и презиме на автор (еден стринг - author),
// а враќа нов објект од класата Festival кој во листата од песни ги содржи само оние песни чиј автор НЕ е author. (5 п.)
//
// Дополнете ја main функцијата со следните барања:
// Од датотеката vlezna.txt прочитајте ги информациите за фестивалот. Секој податок се наоѓа во засебен ред
// (прво се зададени информациите за самиот фестивал, па бројот на пријавени песни, па на крајот и информациите за секоја песна што е пријавена за фестивалот).
// Информациите се вчитуваат директно во објектот festival.
// Во датотеката izlezna1.txt се печатат сите информации за фестивалот и сите песни.
// Во датотеката izlezna2.txt се печатат информациите само за оние песни чиј автор НЕ е авторот author, вчитан во почетниот код. (10 п.)

// Input:
// Ohridski Trubaduri
// Ohrid
// 30/08/2024
// 2
// Usni na usni
// // Grigor Koprov
// Toshe Proeski
// 215
// Tvoeto pismo moja Biblija
// Damir Imeri
// Andrijana Janevska
// 198
// ----
// Grigor Koprov
//
// Result:
// All the data for the festival:
// Festival: Ohridski Trubaduri - Ohrid, 30/08/2024
// Song title: Usni na usni, Author: Grigor Koprov, Interpreted by: Toshe Proeski, 215 sek.
// Song title: Tvoeto pismo moja Biblija, Author: Damir Imeri, Interpreted by: Andrijana Janevska, 198 sek.
// Songs NOT from the author Grigor Koprov:
// Festival: Ohridski Trubaduri - Ohrid, 30/08/2024
// Song title: Tvoeto pismo moja Biblija, Author: Damir Imeri, Interpreted by: Andrijana Janevska, 198 sek.


#include <iostream>
#include <fstream>

using namespace std;

class Song {
    string title;
    string author;
    string performer;
    int duration;

public:
    Song() {
        title = author = performer = "";
        duration = 0;
    }
    Song(string title, string author, string performer, int duration) {
        this->title = title;
        this->author = author;
        this->performer = performer;
        this->duration = duration;
    }

    friend istream& operator>>(istream& in, Song& s) {
        getline(in, s.title);
        getline(in, s.author);
        getline(in, s.performer);
        in >> s.duration;
        in.ignore();
        return in;
    }

    void print(ofstream &out) {
        out << "Title: " << title
        << ", Author: " << author
        << "Interpreted by: " << performer
        << ", duration: " << duration << endl;
    }

    bool operator==(Song &s) {
        return title == s.title &&
            author == s.author &&
                performer == s.performer &&
                    duration == s.duration;
    }

    string getAuthor() {
        return author;
    }
};


class Festival {
    string name;
    string city;
    string date;
    Song* songs;
    int n;

public:

    Festival(){
        name = city = date = "";
        songs = nullptr;
        n = 0;
    }

    Festival(string name, string city, string date, Song* songs, int n) {
        this->name = name;
        this->city = city;
        this->date = date;
        this->songs = new Song[n];
    }

    ~Festival() {
        delete [] songs;
    }

    // Оператор -= за бришење на песна (објект од класата Song) од листата. Од листата се бришат сите песни со идентични податоци
    // (исти: наслов, автор, изведувач и времетраење) како песната што е предадена како аргумент на операторот. Пред да се изведе бришење, да се провери дали листата е празна
    // (да се спречи обидот за бришење на објект од празна листа, со печатење на соодветна порака: „Trying to delete from an empty list!“). (10 п.)
    // Метод void print(ofstream& out), за печатење на информациите за фестивалот во датотека што се предава како аргумент
    // на методот (преку ofstream објектот). Овој метод задолжително треба да го повика методот print од класата Song, за печатење на информациите за листата од песни. (5 п.)
    // Оператор за читање >> (5 п.)
    // Метод Festival notFromAuthor(string author) - кој како аргумент прима име и презиме на автор (еден стринг - author),
    // а враќа нов објект од класата Festival кој во листата од песни ги содржи само оние песни чиј автор НЕ е author. (5 п.)

    Festival& operator-=(Song& s) {
        if (n == 0) {
            cout << "Trying to delete from an empty list!" << endl;
            return *this;
        }

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (!(songs[i] == s)) {
                cnt++;
            }
        }

        Song* tmp = new Song[cnt];

        int index = 0;
        for (int i = 0; i < n; i++) {
            if (!(songs[i] == s)) {
                tmp[index] = songs[i];
                index++;
            }
        }

        delete [] songs;
        songs = tmp;
        n = cnt;
        return *this;
    }


    void print(ofstream& out) {
        out << "Festival: " << name << " - " << city << ", " << date << endl;
        for (int i = 0; i < n;i++)
            songs[i].print(out);
    }

    friend istream& operator>>(istream &in, Festival& f) {
        getline(in, f.name);
        getline(in, f.city);
        getline(in, f.date);
        in >> f.n;

        f.songs = new Song[f.n];
        for (int i = 0; i < f.n; i++) {
            in >> f.songs[i];
        }

        return in;
    }

    Festival notFromAuthor(string author) {
        Festival f;
        f.name = name;
        f.city = city;
        f.date = date;

        int counter = 0;
        for (int i = 0; i < n; i++)
            if (songs[i].getAuthor() != author)
                counter++;

        f.n = counter;
        f.songs = new Song[counter];

        int index = 0;
        for (int i = 0; i < n; i++) {
            if (songs[i].getAuthor() != author) {
                f.songs[index] = songs[i];
                index++;
            }
        }

        return f;
    }
};
using namespace std;

void wtf() {
    ofstream fout("vlezna.txt");
    string line;
    while (getline(std::cin, line)) {
        if (line == "----"){
            break;
        }
        fout << line << endl;
    }
}

void rff(string path) {
    ifstream fin(path);
    string line;
    while (getline(fin, line)) {
        cout << line << endl;
    }
}


int main() {

    wtf();

    Festival festival;
    //TODO your code here
    //TODO Read the data from the file and store them in `festival`

    ifstream fin("vlezna.txt");
    fin >> festival;
    fin.close();

    //DO NOT MODIFY THE CODE BETWEEN THIS AND THE NEXT COMMENT
    string author;
    getline(cin, author);
    //DO NOT MODIFY THE CODE BETWEEN THIS AND THE PREVIOUS COMMENT

    //TODO Save the results in the files izlezna1.txt and izlezna2.txt after this line

    ofstream fout1("izlezna1.txt");
    festival.print(fout1);
    fout1.close();

    Festival filtered = festival.notFromAuthor(author);
    ofstream fout2("izlezna2.txt");
    festival.print(fout2);
    fout2.close();


    //DO NOT MODIFY THE CODE BELLOW

    cout << "All the data for the festival:" << endl;
    rff("izlezna1.txt");
    cout << "Songs NOT from the author " << author << ": " << endl;
    rff("izlezna2.txt");


    return 0;
}